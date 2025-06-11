from src.entity.march.march_base import MArchBase
from typing import Any


class RV32IMAFDC_zicsr_zifencei(MArchBase):

    def fetch_int_return_value(self, entry) -> Any:
        """
            In rv32imafdc_zicsr_zifencei int return value is stored in register a0
        """
        rv = None
        self.logger.info(f'Architecture {self.get_march_name()} recognized. Extracting integer return value from a0')
        cswsp = self.fetch_cswsp_instruction(entry.prologue)
        cjr = self.fetch_cjr_instruction(entry.epilogue)
        if not cswsp:
            self.logger.error("Missing cswsp instruction. Aborting.")
        elif not cjr:
            self.logger.error("Missing cjr instruction. Aborting.")
        else:
            if cswsp['a0'] == cjr['a0']:
                self.logger.info(
                    f'{self.get_march_name()}: a0 has equal value in prologue and epilogue. Value is inconclusive. Aborting.')
            else:
                rv = cjr['a0']
        return rv

    def fetch_unsigned_int_return_value(self, entry) -> Any:
        self.logger.error(f"Fetching unsigned int return value has not been implemented for {self.get_march_name()}.")
        return None

    def fetch_char_return_value(self, entry) -> Any:
        self.logger.error(f"Fetching char return value has not been implemented for {self.get_march_name()}.")
        return None

    def fetch_float_return_value(self, entry) -> Any:
        """
            In rv32imafdc_zicsr_zifencei float return value is stored in register
            64-bit fa0 register as masked value
        """
        rv = None
        self.logger.info(
            f'Architecture {self.get_march_name()} recognized. Extracting and unmasking 32-bit float return value from 64-bit reg fa0')
        cswsp = self.fetch_cswsp_instruction(entry.prologue)
        cjr = self.fetch_cjr_instruction(entry.epilogue)

        if not cswsp:
            self.logger.error("Missing cswsp instruction. Aborting.")
        elif not cjr:
            self.logger.error("Missing cjr instruction. Aborting.")
        else:
            if cswsp['fa0'] == cjr['fa0']:
                self.logger.info(
                    f'{self.get_march_name()}: fa0 has equal value in prologue and epilogue. Value is inconclusive. Aborting.')
            else:
                nan_boxed_rv = cjr['fa0']
                nan_box_mask = 0xFFFFFFFF
                # Bitwise AND removes the upper 32-bit Nan-box
                rv = nan_boxed_rv & nan_box_mask
        return rv

    def fetch_long_return_value(self, entry) -> Any:
        self.logger.error(f"Fetching long return value has not been implemented for {self.get_march_name()}.")
        return None

    def fetch_double_return_value(self, entry) -> Any:
        self.logger.error(f"Fetching double return value has not been implemented for {self.get_march_name()}.")
        return None

    def get_march_name(self):
        return "rv32imafdc_zicsr_zifencei"
