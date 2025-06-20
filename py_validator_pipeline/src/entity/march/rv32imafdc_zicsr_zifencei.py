import struct
from typing import Any, Literal, List

from src.entity.march.rv32ic import RV32IC
from src.exception.pipeline_exceptions import OutOfRegistersException

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

        arg_regs = {'a0', 'a1'}
        farg_regs = {'fa0', 'fa1'}

        def get_next_int_reg():
            ret = ''
            if 'a0' in arg_regs:
                ret = 'a0'
                arg_regs.remove(ret)
            elif 'a1' in arg_regs:
                ret = 'a1'
                arg_regs.remove(ret)
            return ret

        def get_next_float_reg():
            ret = ''
            if 'fa0' in farg_regs:
                ret = 'fa0'
                farg_regs.remove(ret)
            elif 'fa1' in farg_regs:
                ret = 'fa1'
                farg_regs.remove(ret)
            return ret

        cjr = self.fetch_cjr_instruction(entry.epilogue)

        if not cjr:
            self.logger.error("Missing cjr instruction. Aborting.")
        elif not regs:
            # Case: return value in memory
            self.logger.debug(f"No register values extracted. Is this an empty struct?")
            # rv = [''.join(rv)[::-1]]
        else:
            try:
                for idx, reg in enumerate(regs):
                    if reg.float:

                        reg_val = get_next_float_reg()
                        # self.logger.debug(f"Extracting float: {reg}, size: {reg.get_float_size()}, from reg: {reg_val}")
                        if not reg_val:
                            raise OutOfRegistersException()
                        if reg.get_float_size() == 4:
                            rv.append(self.fetch_float_return_value(entry=entry, reg=reg_val))
                        elif reg.get_float_size() == 8:
                            rv.append(self.fetch_double_return_value(entry=entry, reg=reg_val))
                    else:
                        curr_reg = get_next_int_reg()
                        if not curr_reg:
                            raise OutOfRegistersException()
                        for loc in reg.data:
                            reg_val = cjr[curr_reg]
                            rv.append(self.fetch_aligned_int_value(reg_val=reg_val, loc=loc))
            except OutOfRegistersException as e:
                mem_vals = self.extract_from_memory_addr(entry=entry, addr=cjr['a0'], byte_size=struct_type_info.byte_size)
                rv = self.resolve_struct_memory_values(regs, mem_vals)
                # rv = [''.join(rv)[::-1]]

        return rv

    def from_rv32_words_le_bytes(low_hex: str, high_hex: str) -> float:
        # Convert each 32-bit word from little-endian hex string to bytes
        low_bytes = bytes.fromhex(low_hex)[::-1]
        high_bytes = bytes.fromhex(high_hex)[::-1]
        # Concatenate to get 8-byte double (little endian overall)
        double_bytes = high_bytes + low_bytes  # high comes first in IEEE 754
        return struct.unpack('>d', double_bytes)[0]  # Big-endian for correct IEEE interpretation

    def get_march_name(self) -> str:
        return "rv32imafdc_zicsr_zifencei"

    def get_endianness(self) -> Literal['little', 'big']:
        return 'little'
