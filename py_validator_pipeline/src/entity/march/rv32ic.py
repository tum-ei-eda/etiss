from collections import namedtuple
from abc import ABC, abstractmethod
from typing import Any, List, Dict, Tuple, Optional
import logging
import struct
from math import ceil


from src.entity.dwarf.types import StructType, BaseType
from src.entity.march.march_base import MArchBase
from src.entity.verification.struct_reg_data_types import (
    Bitfield, Float, Integer, StructRegDataTypes
)
from src.util.gcc_dwarf_rv_mapper import GccDwarfMapper
from src.exception.pipeline_exceptions import VerificationProcessException

class RV32IC(MArchBase, ABC):
    """
        A base class for
    """

    def __init__(self):
        self.logger = logging.getLogger(__name__)
        self.mapper = GccDwarfMapper()
        # For RV32 this is 8 bytes
        self.max_register_struct_size = 8
        self.xlen = 32
        self.flen = 0

    def fetch_int_return_value(self, entry, reg='a0') -> Any:
        """
            In RV32 int (32-bit) return value is stored in register a0
        """
        rv = None
        cjr = self.fetch_cjr_instruction(entry.epilogue)
        if not cjr:
            self.logger.error("Missing cjr instruction. Aborting.")
        else:
            rv = cjr[reg]
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
        cjr = self.fetch_cjr_instruction(entry.epilogue)

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
        return self.form_struct_return_values(entry)

    def form_struct_return_values(self, entry) -> List[Any]:
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
        reservations = self.compute_struct_values(elements)

        def get_register(idx: int) -> str:
            register = 'a0'
            nonlocal reservations
            if idx > 0:
                for i in range(1, idx + 1):
                    if reservations[i][0] == 0:
                        register = 'a1'
            return register

        cjr = self.fetch_cjr_instruction(entry.epilogue)

        if not cjr:
            self.logger.error("Missing cjr instruction. Aborting.")
        elif not reservations:
            # Case: return value in memory
            addr = cjr['a0']
            entry.get_last_writes_to_mem_range(addr, struct_type_info.byte_size)
        else:
            for idx, elem in enumerate(elements):
                reg = get_register(idx)
                match elem:
                    case Bitfield():
                        rv.append(self.fetch_aligned_int_value(reg_val=cjr[reg], loc=reservations[idx]))
                    case Float():
                        if elem.byte_size == 4:
                            rv.append(self.fetch_float_return_value(entry=entry, reg=reg))
                        if elem.byte_size == 8:
                            rv.append(self.fetch_double_return_value(entry=entry, reg=reg))
                    case Integer():
                        if reservations[idx][0] == 0 and reservations[idx][1] == 31:
                            rv.append(self.fetch_int_return_value(entry=entry, reg=reg))
                        else:
                            rv.append(self.fetch_aligned_int_value(reg_val=cjr[reg], loc=reservations[idx]))
        return rv

    def compute_struct_values(self, elements: List[StructRegDataTypes]) -> Optional[List[Tuple[int, int]]]:
        # Holds the bits storing return values
        reg_reservations: Optional[List[Tuple[int, int] | List[Tuple[int, int]]]] = []
        # Registers a0 and a1 can be used for return values according to
        # integer calling convention
        available_registers = 2
        reg_counter = 0

        def crosses_alignment_boundary(bits: int, alignment_bytes: int) -> bool:
            """
                Verifies whether a bitfield or an int value can fit in the current
                integer register
            """
            crosses_boundary = False
            alignment_bits = alignment_bytes * 8
            bits_available = alignment_bytes * 8
            if reg_reservations:
                bits_available = alignment_bits - reg_reservations[-1][1] % alignment_bits
            if bits > alignment_bits:
                # With padding the bits can exceed the alignment boundary. The assumption
                # here is that the alignment_bytes still cannot cross the boundary.
                crosses_boundary = bool(bits_available - alignment_bits >= 0)
            else:
                # Without padding the bits cannot cross the alignment boundary
                crosses_boundary = bool(bits_available - bits >= 0)
            return crosses_boundary

        def get_aligned_start_bit(alignment_bytes: int, bits_to_reserve: int) -> int:
            """
                The assumption here is that the value crosses alignment boundary.
                Because of this, we want the next possible alignment. It is either
                in the same register, or in the next register, if the register is filled.
            """
            nonlocal reg_counter
            alignment_bits: int = alignment_bytes * 8
            aligned_start_bit: int = 0
            if reg_reservations:
                aligned_start_bit = ceil(reg_reservations[-1][1] / alignment_bits) * alignment_bits
                if aligned_start_bit >= self.xlen or aligned_start_bit + bits_to_reserve >= self.xlen:
                    reg_counter += 1
                    aligned_start_bit = 0
            return aligned_start_bit


        for e in elements:
            if reg_counter >= available_registers:
                break
            match e:
                case Bitfield():
                    start_bit = 0
                    if crosses_alignment_boundary(bits=e.bit_size, alignment_bytes=e.alignment):
                        res_bits = e.bit_size if e.bit_size <= e.alignment * 8 else e.alignment * 8
                        start_bit = get_aligned_start_bit(alignment_bytes=e.alignment, bits_to_reserve=res_bits)
                    else:
                        if reg_reservations:
                            start_bit = reg_reservations[-1][1] + 1
                    reg_reservations.append((start_bit, start_bit + e.bit_size - 1))
                case Float():
                    # Supported types are float (4 bytes) and double (8 bytes)
                    reg_len_bits = self.xlen
                    reg_len_bytes = self.xlen // 8
                    if self.flen:
                        reg_len_bits = self.flen
                        reg_len_bytes = self.flen // 8
                    regs = e.byte_size // reg_len_bytes
                    for i in range(regs):
                        reg_counter += 1
                        reg_reservations.append((0, reg_len_bits - 1))
                case Integer():
                    start_bit = 0
                    if crosses_alignment_boundary(bits=e.byte_size, alignment_bytes=e.byte_size):
                        start_bit = get_aligned_start_bit(e.byte_size, e.byte_size)
                    else:
                        if reg_reservations:
                            start_bit = reg_reservations[-1][1] + 1
                    int_bits = e.byte_size * 8
                    reg_reservations.append((start_bit, start_bit + int_bits - 1))
        if reg_counter >= available_registers:
            reg_reservations = None

        return reg_reservations

    def analyze_struct(self, struct: StructType):
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
                    nested = self.analyze_struct(m)
                    for e in nested:
                        elements.append(e)
                case _:
                    # Unsupported type
                    err = f"Unsupported member in struct: {str(struct)}"
                    self.logger.error(err)
                    raise VerificationProcessException(err)

        return elements

    @staticmethod
    def fetch_aligned_int_value(reg_val, loc: Tuple[int, int]) -> int:
        """Extracts an integer value from a register based on a bit range (inclusive)."""
        low, high = loc
        width = high - low + 1
        mask = (1 << width) - 1
        return (reg_val >> low) & mask

    def _form_64_bit_value_from_regs_a0_and_a1(self, entry) -> Any:
        rv = None
        cjr = self.fetch_cjr_instruction(entry.epilogue)

        if not cjr:
            self.logger.error("Missing cjr instruction. Aborting.")
        else:
            a0 = cjr['a0']
            a1 = cjr['a1']
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