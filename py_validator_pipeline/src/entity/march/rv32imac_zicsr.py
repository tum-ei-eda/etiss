import struct
from typing import Any, Literal

from src.entity.march.rv32ic import RV32IC


class RV32IMAC_zicsr(RV32IC):

    def fetch_float_return_value(self, entry) -> Any:
        """
            In rv32imac_zicsr, float return value is stored in register a0
            as a 32-bit raw bit pattern. Convert it to Python float.
        """
        rv = None

        self.logger.debug(f'Architecture {self.get_march_name()} recognized. Extracting return value from argument register a0')
        cjr = self.fetch_cjr_instruction(entry.epilogue)

        if not cjr:
            self.logger.error("Missing cjr instruction. Aborting.")
        else:
            raw_val = cjr['a0']
            float_bytes = raw_val.to_bytes(4, self.get_endianness())  # Little-endian for RV32
            rv = struct.unpack('<f', float_bytes)[0]
            self.logger.debug(f"Return value for {self.get_march_name()}: {rv}")
        return rv

    def fetch_double_return_value(self, entry) -> Any:
        """
            In RV32IMAC double return value is stored in registers a0 (lower 32 bits)
            and a1 (upper 32 bits)
        """
        return self._form_64_bit_value_from_regs_a0_and_a1(entry)


    def get_march_name(self):
        return "rv32imac_zicsr"

    def get_endianness(self) -> Literal['little', 'big']:
        return 'little'
