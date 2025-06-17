from abc import ABC, abstractmethod
from typing import Any

from src.entity.dwarf.type_info import TypeInfo


class VarAndParamBase(ABC):
    """
        Parent class for all variables:
          - global variables
          - formal parameters
          - local variables
        Classes that inherit this parent class MUST implement
        method get_location_value, as that is specific to
        different variables.
    """

    def __init__(self) -> None:
        self._name: None | str = None
        self._location: Any = None

        self.type_info: None | TypeInfo = None
        self._indent: int = 2

    def set_name(self, name) -> None:
        self._name = name

    def get_name(self) -> str:
        return self._name

    def set_location(self, location) -> None:
        self._location = location

    def get_location(self):
        return self._location

    def set_type_info(self, type_info) -> None:
        self.type_info = type_info

    def has_more_than_one_element(self) -> bool:
        result = False
        if self.type_info.range and self.type_info.base_type_byte_size:
            result = self.type_info.range / self.type_info.base_type_byte_size != 1
        return result

    def get_number_of_elements(self) -> int:
        result = 0
        if self.type_info.range and self.type_info.base_type_byte_size:
            result = int(self.type_info.range / self.type_info.base_type_byte_size)
        return result

    @abstractmethod
    def get_location_value(self):
        """
            This method should be implemented by subclasses.
        """
        pass


    def __str__(self) -> str:
        output = ""
        output += f"{self._indent * ' '}  ┌ Name: {self._name}\n"
        output += f"{self._indent * ' '}  ├ Type composition: {self.type_info.description}\n"
        output += f"{self._indent * ' '}  ├ Base Type: {self.type_info.base_type}\n"
        output += f"{self._indent * ' '}  ├ Base Type/Byte Size: {self.type_info.base_type_byte_size}\n"
        output += f"{self._indent * ' '}  └ Location: {self._location}\n"
        if self.type_info.range != self.type_info.base_type_byte_size:
            output += f"{self._indent * ' '}  ├ Range: {self.type_info.range}\n"
        if self.type_info.struct_name:
            output += f"{self._indent * ' '}  ├ Struct name: {self.type_info.struct_name}\n"
            if self.type_info.members:
                output += f"{self._indent * ' '}  > Members:\n"
            for member in self.type_info.members:
                output += f"{self._indent * ' '}    ┌ Member name: {member.member_name}\n"
                output += f"{self._indent * ' '}    ├ Type composition: {member.description}\n"
                output += f"{self._indent * ' '}    ├ Base Type: {member.base_type}\n"
                output += f"{self._indent * ' '}    ├ Base Type/Byte Size: {member.base_type_byte_size}\n"
                if member.member_bit_size:
                    output += f"{self._indent * ' '}    ├ Bit size: {member.member_bit_size}\n"
                    output += f"{self._indent * ' '}    └ Bit offset: {member.member_bit_offset}\n"
        return output
