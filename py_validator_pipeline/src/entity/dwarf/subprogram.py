from typing import List

from src.entity.dwarf.formal_parameter import FormalParameter
from src.entity.dwarf.frame_base_info import FrameBaseInfo
from src.entity.dwarf.local_variable import LocalVariable
from src.entity.dwarf.type_info import TypeInfo



"""
    A class instance of representing data extracted from subprogram DIE
"""
class Subprogram:

    def __init__(self):
        self.name:  str = ""
        self.low_pc: int = 0
        self.high_pc: int = 0
        self.type_info: None | TypeInfo = None
        self.frame_base_infos: List[FrameBaseInfo] = []
        self._formal_parameters = []
        self._local_variables = []
        self._indent: int = 2

    def add_frame_base_info(self, frame_base_info: FrameBaseInfo) -> None:
        if not self.frame_base_infos:
            self.frame_base_infos.append(frame_base_info)
        elif self.frame_base_infos[-1].get_reg() != frame_base_info.get_reg() or self.frame_base_infos[-1].get_offset() != frame_base_info.get_offset():
            self.frame_base_infos.append(frame_base_info)

    def add_formal_parameter(self, formal_param: FormalParameter) -> None:
        self._formal_parameters.append(formal_param)

    def get_formal_parameters(self) -> List[FormalParameter]:
        return self._formal_parameters

    def has_formal_parameters(self) -> bool:
        return bool(self._formal_parameters)

    def add_local_variable(self, var: LocalVariable) -> None:
        self._local_variables.append(var)

    def get_local_variables(self) -> List[LocalVariable]:
        return self._local_variables

    def has_local_variables(self) -> bool:
        return bool(self._local_variables)

    def __str__(self) -> str:
        output = ""
        output += f"{self._indent * ' '}> Subprogram:\n"
        output += f"{self._indent * ' '}  ┌ Name: {self.name}\n"
        if self.frame_base_infos:
            output += f"{self._indent * ' '}  ├ CFA register values and offsets:\n"
            for info in self.frame_base_infos:
                output += str(info)
        if self.type_info.description:
            output += f"{self._indent * ' '}  ├ Type composition: {self.type_info.description}\n"
            output += f"{self._indent * ' '}  ├ Base type: {self.type_info.base_type}\n"
            output += f"{self._indent * ' '}  ├ Base type byte size: {self.type_info.base_type_byte_size}\n"
        else:
            output += f"{self._indent * ' '}  ├ Type composition: void\n"
        if self.type_info.range and (self.type_info.range != self.type_info.base_type_byte_size):
            output += f"{self._indent * ' '}  ├ Range: {self.type_info.range}\n"
        output += f"{self._indent * ' '}  ├ Low-PC: {self.low_pc}\n"
        output += f"{self._indent * ' '}  └ High-PC: {self.high_pc}\n"
        return output



