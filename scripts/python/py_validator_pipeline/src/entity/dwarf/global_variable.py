import re
from src.entity.dwarf.var_and_param_base import VarAndParamBase

class GlobalVariable(VarAndParamBase):

    def __init__(self) -> None:
        super().__init__()
        self._indent = 2  # override

    def get_location_value(self):
        parsed_loc = None
        if self._location and re.search(r'DW_OP_addr:\s*([0-9a-fA-F]+)', self._location):
            # For now we assume all global variables are in memory
            parsed_loc = re.search(r'DW_OP_addr:\s*([0-9a-fA-F]+)', self._location).group(1)
        return parsed_loc

