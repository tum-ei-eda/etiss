import struct
from math import ceil
from typing import Any, Literal, List, Tuple, Optional
from unittest import case

from src.entity.march.rv32ic import RV32IC
from src.entity.verification.struct_reg_data_types import StructRegDataTypes, Bitfield, Float, Integer


class RV32IMAC_zicsr(RV32IC):

    def fetch_float_return_value(self, entry, reg='a0') -> Any:
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
        return self.form_struct_return_values(entry)

    def get_march_name(self):
        return "rv32imac_zicsr"

    def get_endianness(self) -> Literal['little', 'big']:
        return 'little'
