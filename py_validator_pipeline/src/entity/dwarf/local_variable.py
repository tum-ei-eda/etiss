import re
from src.entity.dwarf.variable import Variable

class LocalVariable(Variable):

    def __init__(self) -> None:
        super().__init__()
        self.indent = 6  # override

    def get_location_value(self):
        # For now we assume all formal params are in fbregs
        parsed_loc = re.search(r"\(DW_OP_fbreg:\s*([-+]?\d+)\)", self._location).group(1)
        return int(parsed_loc)

