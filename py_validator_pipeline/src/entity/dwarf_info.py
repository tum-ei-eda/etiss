import re
import logging
from typing import List, Any

from src.util.singleton_meta import SingletonMeta



class DwarfInfo(metaclass=SingletonMeta):

    logger = logging.getLogger(__name__)

    # keys
    _subprogram_low_pc = None
    _subprogram_high_pc = None
    _global_var_locations = {}
    _formal_param_locations = {}

    def __init__(self):
        pass

    def set_subprogram_low_pc(self, value) -> None:
        if self._subprogram_low_pc:
            self.logger.warning(f"Overwriting value for subprogram low PC")
        self._subprogram_low_pc = value

    def set_subprogram_high_pc(self, value) -> None:
        if self._subprogram_high_pc:
            self.logger.warning(f"Overwriting value for subprogram high PC")
        self._subprogram_high_pc = value

    def set_subprogram_low_and_high_pc(self, lowpc, highpc) -> None:
        self._subprogram_low_pc = lowpc
        if highpc < lowpc:
            self._subprogram_high_pc = lowpc + highpc
        else:
            self._subprogram_high_pc = highpc


    def append_global_var_location(self, name, value) -> None:
        parsed_loc = re.search(r'DW_OP_addr:\s*([0-9a-fA-F]+)', value).group(1)
        if not name in self._global_var_locations:
            self._global_var_locations[name] = parsed_loc

    def append_formal_param_location(self, name, location) -> None:
        parsed_loc = re.search(r"\(DW_OP_fbreg:\s*([-+]?\d+)\)", location).group(1)
        if not name in self._formal_param_locations:
            self._formal_param_locations[name] = int(parsed_loc)


    def get_low_pc(self) -> Any:
        return self._subprogram_low_pc

    def get_high_pc(self) -> Any:
        return self._subprogram_high_pc

    def get_global_var_locations(self) -> Any:
        return self._global_var_locations

    def get_formal_param_locations(self) -> Any:
        return self._formal_param_locations


    def flush(self):
        self._subprogram_low_pc = None
        self._subprogram_high_pc = None
        self._global_var_locations = {}
        self._formal_param_locations = {}