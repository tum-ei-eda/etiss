from collections import namedtuple
from abc import ABC
from typing import Any, List, Dict, Tuple, Optional, Union
import logging
import struct

from src.entity.dwarf.types import StructType, BaseType, UnionType
from src.entity.march.march_base import MArchBase
from src.entity.verification.rv32_return_register_layout import RV32ReturnRegisterLayout
from src.entity.verification.struct_reg_data_types import (
    Bitfield, Float, Integer, StructRegDataTypes
)
from src.util.gcc_dwarf_rv_mapper import GccDwarfMapperForRV32
from src.exception.pipeline_exceptions import VerificationProcessException

class RV32(MArchBase, ABC):
    """
    A base class for supported RV32IC architecture with
    possible extensions
    """

    def __init__(self):
        super().__init__()
        self.logger = logging.getLogger(__name__)
        self.mapper = GccDwarfMapperForRV32()
        # For RV32 this is 8 bytes
        self.max_register_struct_size = 8
        self.xlen = 32
        self.flen = 0

    def fetch_int_return_value(self, entry, reg='a0') -> Any:
        """
        In RV32 int (32-bit) return value is stored in register a0
        """
        rv = None
        epilogue_inst = self.fetch_epilogue_state(entry.epilogue)
        if not epilogue_inst:
            self.logger.error("Missing epilogue instruction. Aborting.")
        else:
            rv = epilogue_inst[reg]
        return rv

    def fetch_long_long_return_value(self, entry) -> Any:
        """
        In RV32IMAC long long return value is stored in registers
        a0 (lower 32 bits) and a1 (upper 32 bits)
        """
        return self._form_64_bit_value_from_regs_a0_and_a1(entry)

    def fetch_long_double_return_value(self, entry) -> Any:
        """
            From RISC-V specification: Floating-point values
            are returned in floating-point registers only
            if they are primitives or members of a struct
            consisting of only on or two floating-point
            values. Other return values that fit into
            two pointer-words are returned in a0 and a1.
            Larger return values are passed entirely in
            memory.

            Conclusion: long double is always passed
            in memory.
        """
        rv = None
        cjr = self.fetch_epilogue_state(entry.epilogue)

        if not cjr:
            self.logger.error("Missing cjr instruction. Aborting.")
            return None

        base_addr = cjr['a0']
        data_words = []

        try:
            for i in range(4):
                addr = format(base_addr + i * 4, 'x')  # Lowercase hex without 0x
                if addr not in entry.dwrites or not entry.dwrites[addr]:
                    raise KeyError(f"Missing or empty dwrites at address {addr}")
                data_hex = entry.dwrites[addr][-1]['data']
                data_words.append(int(data_hex, 16))

            # Combine into a 128-bit value (little-endian: lowest word first)
            combined_val = (data_words[0]
                            | (data_words[1] << 32)
                            | (data_words[2] << 64)
                            | (data_words[3] << 96))

            combined_bytes = combined_val.to_bytes(16, byteorder='little')

            # Note: Python's `struct.unpack('<d', ...)` is for 64-bit floats only.
            # For 128-bit float, you'd need a custom solution, or convert to something readable:
            # rv = combined_bytes  # Return raw bytes for now, or decode externally
            rv = int.from_bytes(combined_bytes, 'little')


        except Exception as e:
            self.logger.error(f"Error reading long double: {e}")

        return rv

    def fetch_struct_return_value(self, entry) -> List[Any]:
        """
        Extracts and decodes the return value of a function that returns a struct,
        according to the RISC-V ABI rules for struct returns.

        This method uses an analyzer method from the base class to analyze the structure's
        layout and then determines how it is returned (in registers or memory),
        and decodes the returned values from the appropriate registers (`a0`, `a1`) based
        on computed bitfield positions.

        Handles:
        - Integer fields (aligned and packed/bitfields)
        - Floating-point fields (delegated to fetch_float_return_value)
        - Composite bitfield returns from multiple subfields

        Args:
            entry: An object representing a function's return context, including DWARF info
                   and the epilogue instruction containing return register values.
            reg_prefix: floating point registers have 'f' prefix

        Returns:
            A list of Python values decoded from the return registers, in struct field order.
            Returns an empty list if the struct is returned in memory (not in registers).
        """
        rv = []
        struct_type_info = entry.dwarf_info.get_subprogram_by_name(entry.function_name).type_info

        elements = self.analyze_struct(struct_type_info)
        regs = self.compute_struct_values(elements)

        float_reg_idx = 0
        int_reg_idx = 0

        def get_register(is_float: bool = False) -> str:
            """
            Allocates the next available register for the return value.

            Priority:
            - If float and floating-point registers are available, use them.
            - Otherwise, use the next available integer register.

            Returns:
                A string representing the chosen register name (e.g., 'a0', 'a1', 'fa0', 'fa1').
            """
            nonlocal float_reg_idx, int_reg_idx

            int_regs = ['a0', 'a1']
            float_regs = ['fa0', 'fa1']
            reg_value = ''

            if is_float:
                if self.flen and float_reg_idx < len(float_regs):
                    reg_value = float_regs[float_reg_idx]
                    float_reg_idx += 1
                elif not self.flen and int_reg_idx < len(int_regs):
                    reg_value = int_regs[int_reg_idx]
                    int_reg_idx += 1
            elif int_reg_idx < len(int_regs):
                reg_value = int_regs[int_reg_idx]
                int_reg_idx += 1

            return reg_value


        epilogue_inst = self.fetch_epilogue_state(entry.epilogue)

        if not epilogue_inst:
            self.logger.error("Missing epilogue instruction. Aborting.")
        elif not regs:
            # Case: return value in memory
            addr = epilogue_inst['a0']
            entry.get_last_writes_to_mem_range(addr, struct_type_info.byte_size)
        else:

            for idx, reg in enumerate(regs):
                if reg.float:
                    reg_val = get_register(is_float=True)
                    if reg.get_float_size() == 4:
                        rv.append(self.fetch_float_return_value(entry=entry, reg=reg_val))
                    elif reg.get_float_size() == 8:
                        rv.append(self.fetch_double_return_value(entry=entry, reg=reg_val))
        return rv

    def compute_struct_values(self, elements: List[StructRegDataTypes]) -> Optional[List[RV32ReturnRegisterLayout]]:

        regs: List[RV32ReturnRegisterLayout] = []
        active_reg: Optional[RV32ReturnRegisterLayout] = RV32ReturnRegisterLayout(xlen=self.xlen)

        for e in elements:
            if not active_reg:
                active_reg = RV32ReturnRegisterLayout(xlen=self.xlen)
            match e:
                case Bitfield():
                    if not active_reg.has_room_for_bitfield(bits_to_reserve=e.bit_size, alignment_bytes=e.alignment):
                        regs.append(active_reg)
                        active_reg = RV32ReturnRegisterLayout(xlen=self.xlen)
                    active_reg.add_bitfield(e)
                case Float():
                    if not active_reg.is_empty():
                        regs.append(active_reg)
                    float_reg = RV32ReturnRegisterLayout(xlen=self.xlen, float=True)
                    float_reg.add_float(e)
                    regs.append(float_reg)
                    active_reg = None
                case Integer():
                    if not active_reg.has_room_for_int(e.byte_size):
                        regs.append(active_reg)
                        active_reg = RV32ReturnRegisterLayout(xlen=self.xlen)
                    active_reg.add_int(e)

        if active_reg and not active_reg.is_empty():
            regs.append(active_reg)
        self.logger.debug(f"Registers required for return values: {', '.join([str(r) for r in regs])}")
        return regs

    def analyze_struct(self, struct: StructType) -> List[Union[Integer, Float, Bitfield]]:
        """
            Analyzes the given struct and returns a flat list of its relevant elements.

            The method processes each member of the struct and collects values of interest:
            - Integer values
            - Floating-point values (float and double)
            - Bitfields

            Nested structs are handled recursively and flattened into the result list.
            Unsupported member types raise a VerificationProcessException.

            Args:
                struct (StructType): The structure to analyze.

            Returns:
                List[Union[Integer, Float, Bitfield]]: A flat list of analyzed struct elements.
        """
        elements = []
        for m in struct.members:
            match m.member_type:
                case BaseType():
                    base = m.get_base()
                    base_type = self.mapper.get_mapping_for_dwarf_base_type(base.type)
                    is_bitfield = bool(m.bit_size)

                    if is_bitfield:
                        # For bitfields, track only bit size and alignment
                        bit_size = m.bit_size
                        alignment = self.mapper.get_byte_size_for_base_type(base.type)
                        elements.append(Bitfield(bit_size=bit_size, alignment=alignment))
                    elif base_type in ['float', 'double']:
                        elements.append(Float(byte_size=base.byte_size))
                    else:
                        elements.append(Integer(byte_size=base.byte_size))
                case StructType():
                    # Handle nested structs recursively
                    nested = self.analyze_struct(m.member_type)
                    for e in nested:
                        elements.append(e)
                case _:
                    # Unsupported type
                    err = f"Unsupported member in struct: {str(struct)}"
                    self.logger.error(err)
                    raise VerificationProcessException(err)

        return elements

    def extract_from_memory_addr(self, entry, addr, byte_size):
        self.logger.debug(
            f"Return values do not fit in the argument registers of this architecture. Extracting {byte_size} bytes starting from address {hex(addr)}")
        return entry.get_last_writes_to_mem_range(addr, byte_size)

    def resolve_struct_memory_values(self, regs: List[RV32ReturnRegisterLayout], mem_vals: List[str]) -> List[Any]:
        resolved_values = []
        rv_bytes = ''.join(mem_vals)  # Flat hex string, 2 chars per byte
        idx = 0

        for r in regs:
            # Get size in bytes, then convert to number of hex characters (2 chars per byte)
            byte_len = self.xlen // 8
            if r.float:
                byte_len = r.get_float_size()

            hex_len = byte_len * 2
            val_bytes = rv_bytes[idx: idx + hex_len]

            # Reverse bytes for little endian
            reversed_bytes = ''.join(
                [val_bytes[i: i + 2] for i in range(0, hex_len, 2)]
            )

            if r.float:
                if byte_len == 4:
                    value = struct.unpack('<f', bytes.fromhex(reversed_bytes))[0]
                elif byte_len == 8:
                    value = struct.unpack('<d', bytes.fromhex(reversed_bytes))[0]
                else:
                    raise ValueError("Unsupported float size")
            else:
                value = int.from_bytes(bytes.fromhex(reversed_bytes), byteorder='little')

            resolved_values.append(value)
            idx += hex_len

        return resolved_values


    def fetch_union_return_value(self, entry) -> Any:
        union: UnionType = entry.dwarf_info.get_subprogram_by_name(entry.function_name).type_info
        byte_size = union.byte_size
        rv = None
        epilogue_inst = self.fetch_epilogue_state(entry.epilogue)
        if not epilogue_inst:
            self.logger.error("Missing epilogue instruction. Aborting.")
        elif byte_size <= 4:
            rv = self.fetch_int_return_value(entry)
        elif byte_size <= 8:
            rv = self._form_64_bit_value_from_regs_a0_and_a1(entry)
        else:
            rv = self.extract_from_memory_addr(entry=entry, addr=epilogue_inst['a0'], byte_size=byte_size)
        return rv


    @staticmethod
    def fetch_aligned_int_value(reg_val: int, loc: Tuple[int, int]) -> int:
        """Extracts an integer value from a register based on a bit range (inclusive)."""
        low, high = loc
        width = high - low + 1
        mask = (1 << width) - 1
        return (reg_val >> low) & mask

    def _form_64_bit_value_from_regs_a0_and_a1(self, entry) -> Any:
        rv = None
        epilogue_inst = self.fetch_epilogue_state(entry.epilogue)

        if not epilogue_inst:
            self.logger.error("Missing epilogue instruction instruction. Aborting.")
        else:
            a0 = epilogue_inst['a0']
            a1 = epilogue_inst['a1']
            combined_val = (a1 << 32) | a0
            combined_bytes = combined_val.to_bytes(8, 'little')
            rv = struct.unpack('<d', combined_bytes)[0]
        return rv

    """
        These static methods fetch specific instructions from CPU state prologue and
        epilogue information
    """
    @staticmethod
    def fetch_cswsp_instruction(prologue: List[Dict[str, Any]]) -> None | Dict[str, Any]:
        cswsp_instr = None
        for i in prologue:
            if i['instruction'] == 'cswsp':
                cswsp_instr = i
                break

        return cswsp_instr

    @staticmethod
    def fetch_cjr_instruction(epilogue: List[Dict[str, Any]]) -> None | Dict[str, Any]:
        cjr_inst = None
        for i in epilogue:
            if i['instruction'] == 'cjr':
                cjr_inst = i
                break

        return cjr_inst