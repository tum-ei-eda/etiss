import logging
from abc import ABC, abstractmethod
from collections import namedtuple
from typing import Any, Tuple

from src.entity.dwarf.types import AbstractType, BaseType, StructType, ConstType, ArrayType, UnionType, StructMember


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
        self.logger = logging.getLogger(__name__)
        self._name: None | str = None
        self._location: Any = None

        self.type_info: None | AbstractType = None
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
        base = self.type_info.get_base()
        total_range = self.type_info.get_range()
        return base.byte_size < total_range

    def is_struct(self) -> bool:
        return isinstance(self.type_info, StructType)

    def get_number_of_elements(self) -> int:
        try:
            base = self.type_info.get_base()
            total_range = self.type_info.get_range()
            return int(total_range / base.byte_size)
        except ZeroDivisionError:
            return 0


    @abstractmethod
    def get_location_value(self):
        """
            This method should be implemented by subclasses.
        """
        pass



    def __str__(self) -> str:

        base = self.type_info.get_base()
        total_range = self.type_info.get_range()

        output = ""
        output += f"{self._indent * ' '}  ┌ Name: {self._name}\n"
        output += f"{self._indent * ' '}  ├ Type composition: {str(self.type_info)}\n"
        match self.type_info:
            case StructType():
                output += f"{self._indent * ' '}  ├ Struct name: {self.type_info.name}\n"
                output += f"{self._indent * ' '}  ├ Struct byte size: {self.type_info.byte_size}\n"
            case UnionType():
                output += f"{self._indent * ' '}  ├ Union byte size: {self.type_info.byte_size}\n"
            case _:
                output += f"{self._indent * ' '}  ├ Base Type: {base.type}\n"
                output += f"{self._indent * ' '}  ├ Base Type/Byte Size: {base.byte_size}\n"
        if total_range != base.byte_size:
            output += f"{self._indent * ' '}  ├ Range: {total_range}\n"
        output += f"{self._indent * ' '}  └ Location: {self._location}\n"
        if isinstance(self.type_info, StructType) or isinstance(self.type_info, UnionType):
            if self.type_info.members:
                output += f"{self._indent * ' '}  > Members:\n"
            for member in self.type_info.members:
                output += f"{self._indent * ' '}    ┌ Member name: {member.name}\n"
                output += f"{self._indent * ' '}    ├ Type composition: {str(member)}\n"
                output += f"{self._indent * ' '}    ├ Range (bytes): {member.member_type.get_range()}\n"
                if isinstance(member, StructMember) and member.bit_size:
                    output += f"{self._indent * ' '}    ├ Bit size: {member.bit_size}\n"
                    output += f"{self._indent * ' '}    └ Bit offset: {member.bit_offset}\n"
        return output
