import re
from src.entity.dwarf.var_and_param_base import VarAndParamBase

class LocalVariable(VarAndParamBase):

    def __init__(self) -> None:
        super().__init__()
        self._indent = 6  # override

    def get_location_value(self):
        # For now we assume all formal params are in fbregs
        parsed_loc = re.search(r"\(DW_OP_fbreg:\s*([-+]?\d+)\)", self._location).group(1)
        return int(parsed_loc)

