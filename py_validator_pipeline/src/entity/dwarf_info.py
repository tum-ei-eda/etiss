import logging
from typing import List, Any

from src.util.singleton_meta import SingletonMeta



class DwarfInfo(metaclass=SingletonMeta):

    _dwarf_info = {}
    logger = logging.getLogger(__name__)

    # keys
    subprogram_low_pc = 'DW_AT_low_pc'
    subprogram_high_pc = 'DW_AT_high_pc'
    global_var_locations = 'global_var_locations'
    formal_param_locations = 'formal_param_locations'

    def __init__(self):
        pass

    def add_subprogram_low_pc(self, value) -> None:
        if self.subprogram_low_pc in self._dwarf_info:
            self.logger.warning(f"Overwriting value for subprogram low PC")
        self._dwarf_info[self.subprogram_low_pc] = value

    def add_subprogram_high_pc(self, value) -> None:
        if self.subprogram_high_pc in self._dwarf_info:
            self.logger.warning(f"Overwriting value for subprogram high PC")
        self._dwarf_info[self.subprogram_high_pc] = value


    def append_global_var_location(self, name, value) -> None:
        if not self.global_var_locations in self._dwarf_info:
            self._dwarf_info[self.global_var_locations] = {}
        if not name in self._dwarf_info[self.global_var_locations]:
            self._dwarf_info[self.global_var_locations][name] = []
        self._dwarf_info[self.global_var_locations][name].append(value)

    def append_formal_param_location(self, name, value) -> None:
        if not self.formal_param_locations in self._dwarf_info:
            self._dwarf_info[self.formal_param_locations] = {}
        if not name in self._dwarf_info[self.formal_param_locations]:
            self._dwarf_info[self.formal_param_locations][name] = []
        self._dwarf_info[self.formal_param_locations][name].append(value)


    def get_low_pc(self) -> Any:
        low_pc = None
        if self.subprogram_low_pc in self._dwarf_info:
            low_pc =  self._dwarf_info[self.subprogram_low_pc]
        return low_pc

    def get_high_pc(self) -> Any:
        high_pc = None
        if self.subprogram_high_pc in self._dwarf_info:
            high_pc =  self._dwarf_info[self.subprogram_high_pc]
        return high_pc

    def get_global_var_locations(self) -> None | List[Any]:
        global_var_locations = None
        if self.global_var_locations in self._dwarf_info:
            global_var_locations = self._dwarf_info[self.global_var_locations]
        return global_var_locations

    def get_formal_param_locations(self) -> None | List[Any]:
        formal_param_locations = None
        if self.formal_param_locations in self._dwarf_info:
            formal_param_locations = self._dwarf_info[self.formal_param_locations]
        return formal_param_locations