from src.entity.march.march_base import MArchBase
from typing import Any

class RV32IMAC_zicsr(MArchBase):

    def fetch_int_return_value(self, entry) -> Any:
        """
            In rv32imac_zicsr int return value is stored in register a0
        """
        rv = None
        self.logger.info(f'Architecture {self.get_march_name()} recognized. Extracting return value from register a0')
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
            In rv32imac_zicsr float return value is stored in register a0
        """
        rv = None

        self.logger.info(f'Architecture {self.get_march_name()} recognized. Extracting return value from register a0')
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


    def fetch_long_return_value(self, entry) -> Any:
        self.logger.error(f"Fetching long return value has not been implemented for {self.get_march_name()}.")
        return None

    def fetch_double_return_value(self, entry) -> Any:
        self.logger.error(f"Fetching double return value has not been implemented for {self.get_march_name()}.")
        return None

    def get_march_name(self):
        return "rv32imac_zicsr"
