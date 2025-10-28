import struct
from typing import Any, Literal, List, Dict

from src.entity.march.rv32 import RV32
from src.exception.pipeline_exceptions import OutOfRegistersException

class RV32IM_zicsr_zifencei(RV32):

    def __init__(self):
        super().__init__()

    def fetch_float_return_value(self, entry, reg='a0') -> Any:
        """
        In rv32imac_zicsr, float return value is stored in register a0
        as a 32-bit raw bit pattern. Convert it to Python float.
        """
        rv = None

        self.logger.debug(f'Architecture {self.get_march_name()} recognized. Extracting return value from argument register a0')
        cjr = self.fetch_epilogue_state(entry.epilogue)

        if not cjr:
            self.logger.error("Missing cjr instruction. Aborting.")
        else:
            raw_val = cjr[reg]
            float_bytes = raw_val.to_bytes(4, self.get_endianness())  # Little-endian for RV32
            rv = struct.unpack('<f', float_bytes)[0]
        return rv

    def fetch_double_return_value(self, entry, reg='') -> Any:
        """
        In RV32IMAC double return value is stored in registers a0 (lower 32 bits)
        and a1 (upper 32 bits)
        """
        return self._form_64_bit_value_from_regs_a0_and_a1(entry)

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

        def get_next_reg():
            ret = ''
            if 'a0' in arg_regs:
                ret = 'a0'
                arg_regs.remove(ret)
            elif 'a1' in arg_regs:
                ret = 'a1'
                arg_regs.remove(ret)
            return ret

        cjr = self.fetch_epilogue_state(entry.epilogue)

        if not cjr:
            self.logger.error("Missing cjr instruction. Aborting.")
        elif not regs:
            # Case: return value in memory
            self.logger.debug(f"No register values extracted. Is this an empty struct?")
        else:
            try:
                for idx, reg in enumerate(regs):
                    if reg.float:
                        if len(arg_regs) == 0:
                            raise OutOfRegistersException()
                        if reg.get_float_size() == 4:
                            curr_reg = get_next_reg()
                            rv.append(self.fetch_float_return_value(entry=entry, reg=curr_reg))
                        elif reg.get_float_size() == 8:
                            if not ('a0' in arg_regs and 'a1' in arg_regs):
                                raise OutOfRegistersException()
                            # self.logger.debug(f"Extracting double value from registers")
                            rv.append(self.fetch_double_return_value(entry=entry))
                            arg_regs.clear()
                    else:
                        curr_reg = get_next_reg()
                        if not curr_reg:
                            raise OutOfRegistersException()
                        for loc in reg.data:
                            reg_val = cjr[curr_reg]
                            rv.append(self.fetch_aligned_int_value(reg_val=reg_val, loc=loc))
            except OutOfRegistersException as e:
                mem_vals = self.extract_from_memory_addr(entry=entry, addr=cjr['a0'], byte_size=struct_type_info.byte_size)
                rv = self.resolve_struct_memory_values(regs, mem_vals)


        return rv

    def fetch_prologue_state(self, prologue: List[Dict[str, Any]]) -> None | Dict[str, Any]:
        cswsp_instr = None
        for i in prologue:
            if i['instruction'] == 'sw':
                cswsp_instr = i
                break

        return cswsp_instr

    def fetch_epilogue_state(self, epilogue: List[Dict[str, Any]]) -> None | Dict[str, Any]:
        cjr_inst = None
        for i in epilogue:
            if i['instruction'] == 'jalr':
                cjr_inst = i
                break

        return cjr_inst

    def get_march_name(self):
        return "rv32im_zicsr_zifencei"

    def get_endianness(self) -> Literal['little', 'big']:
        return 'little'
