import struct
from typing import Any, Literal, Optional, Tuple, List

from src.entity.march.rv32ic import RV32IC
from src.entity.verification.struct_reg_data_types import Bitfield, Float, Integer, StructRegDataTypes


class RV32IMAFDC_zicsr_zifencei(RV32IC):

    def __init__(self):
        super().__init__()
        self.flen = 64

    def fetch_float_return_value(self, entry, reg='fa0') -> Any:
        """
            In rv32imafdc_zicsr_zifencei, float return value is stored
            in 64-bit fa0 register as NaN-boxed. Extract the lower
            32 bits and convert to float.
        """
        rv = None
        cjr = self.fetch_cjr_instruction(entry.epilogue)
        if not cjr:
            self.logger.error("Missing cjr instruction. Aborting.")
        else:
            nan_boxed_rv = cjr[reg]
            nan_box_mask = 0xFFFFFFFF
            lower_32_bits = nan_boxed_rv & nan_box_mask

            # Convert 32-bit int bits to float using struct
            float_bytes = lower_32_bits.to_bytes(4, self.get_endianness())  # or 'big' depending on your platform
            rv = struct.unpack('<f', float_bytes)[0]
        return rv


    def fetch_double_return_value(self, entry, reg='fa0') -> Any:
        """
            In rv32imafdc_zicsr_zifencei, double return value is stored
            in 64-bit fa0 register.
        """
        rv = None
        cjr = self.fetch_cjr_instruction(entry.epilogue)

        if not cjr:
            self.logger.error("Missing cjr instruction. Aborting.")
        else:
            fa0_val = cjr[reg]
            fa0_bytes = fa0_val.to_bytes(8, self.get_endianness())
            rv = struct.unpack('<d', fa0_bytes)[0]
        return rv

    def fetch_struct_return_value(self, entry) -> List[Any]:
        return self.form_struct_return_values(entry)

    def form_struct_return_values(self, entry) -> List[Any]:
        """
        Extracts and decodes the return value of a function that returns a struct,
        according to the RISC-V ABI rules for struct returns. Customized for
        RV32GC to support 64-bit f-registers.

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

        int_regs = ['a0', 'a1']
        used_regs = []

        def get_register(idx: int) -> str:
            register = 'a0'
            nonlocal reservations
            if idx > 0:
                for i in range(1, idx + 1):
                    if reservations[i][0] == 0:
                        register = 'a1'
            return register

        def get_float_reg() -> str:
            reg = ''
            if 'fa0' not in used_regs:
                reg = 'fa0'
                used_regs.append('fa0')
            elif 'fa1' not in used_regs:
                reg = 'fa1'
                used_regs.append('fa1')
            return reg

        cjr = self.fetch_cjr_instruction(entry.epilogue)

        if not cjr:
            self.logger.error("Missing cjr instruction. Aborting.")
        elif not reservations:
            # Case: return value in memory
            addr = cjr['a0']
            entry.get_last_writes_to_mem_range(addr, struct_type_info.byte_size)
        else:
            for idx, elem in enumerate(elements):
                match elem:
                    case Bitfield():
                        reg = get_register(idx)
                        val = self.fetch_aligned_int_value(reg_val=cjr[reg], loc=reservations[idx])
                        rv.append(val)
                    case Float():
                        if elem.byte_size == 4:
                            reg = get_float_reg()
                            rv.append(self.fetch_float_return_value(entry=entry, reg=reg))
                        if elem.byte_size == 8:
                            reg = get_float_reg()
                            rv.append(self.fetch_double_return_value(entry=entry, reg=reg))
                    case Integer():
                        reg = get_register(idx)
                        if reservations[idx][0] == 0 and reservations[idx][1] == 31:
                            rv.append(self.fetch_int_return_value(entry=entry, reg=reg))
                        else:
                            val = self.fetch_aligned_int_value(reg_val=cjr[reg], loc=reservations[idx])
                            rv.append(val)
        return rv

    def get_march_name(self) -> str:
        return "rv32imafdc_zicsr_zifencei"

    def get_endianness(self) -> Literal['little', 'big']:
        return 'little'
