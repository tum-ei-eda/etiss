import struct
from typing import Any, Literal

from src.entity.march.rv32ic import RV32IC


class RV32IMAFDC_zicsr_zifencei(RV32IC):

    def fetch_float_return_value(self, entry) -> Any:
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
            nan_boxed_rv = cjr['fa0']
            nan_box_mask = 0xFFFFFFFF
            lower_32_bits = nan_boxed_rv & nan_box_mask

            # Convert 32-bit int bits to float using struct
            float_bytes = lower_32_bits.to_bytes(4, self.get_endianness())  # or 'big' depending on your platform
            rv = struct.unpack('<f', float_bytes)[0]
        return rv


    def fetch_double_return_value(self, entry) -> Any:
        """
            In rv32imafdc_zicsr_zifencei, double return value is stored
            in 64-bit fa0 register.
        """
        rv = None
        cjr = self.fetch_cjr_instruction(entry.epilogue)

        if not cjr:
            self.logger.error("Missing cjr instruction. Aborting.")
        else:
            fa0_val = cjr['fa0']
            fa0_bytes = fa0_val.to_bytes(8, self.get_endianness())
            rv = struct.unpack('<d', fa0_bytes)[0]
        return rv



    def get_march_name(self) -> str:
        return "rv32imafdc_zicsr_zifencei"

    def get_endianness(self) -> Literal['little', 'big']:
        return 'little'
