import re
from src.entity.dwarf.variable import Variable

class GlobalVariable(Variable):

    def __init__(self) -> None:
        super().__init__()
        self.indent = 2  # override

    def get_location_value(self):
        # For now we assume all global variables are in memory
        parsed_loc = re.search(r'DW_OP_addr:\s*([0-9a-fA-F]+)', self._location).group(1)
        return parsed_loc

