from math import prod
from typing import List


class TypeInfo:
    """
        A convenience class to construct and instance of type information.
        The variables all have type information and additionally the
        chosen subprogram has type information as well.
    """

    def __init__(self):
        self._range_list: List[int] = []
        self._description_list: List[str] = []
        self.base_type: str = None
        self.base_type_byte_size: int = None
        self.range: int = 0
        self.description: str = ""
        # For structs, refactor to subclass structure later
        self.members: List[TypeInfo] = []
        self.struct_name: str = ""
        self.member_name = ""
        self.member_bit_size: int = 0
        self.member_bit_offset: int = 0


    def add_element_to_description_list(self, element: str) -> None:
        self._description_list.append(element)

    def add_element_to_range_list(self, element: int) -> None:
        self._range_list.append(element)


    def create_type_information(self, base_type, base_type_byte_size) -> None:
        # Add base type and byte size for base type
        self.base_type = base_type
        self.base_type_byte_size = base_type_byte_size

        # Update range
        self.range = prod(self._range_list) * base_type_byte_size
        # Generate type description
        if base_type and base_type != 'None':
            self.description = " ".join(self._description_list[::1]) + " " + self.base_type
        else:
            self.description = "void"

    def __str__(self) -> str:
        output = "TypeInfo:\n"
        if self.description:
            output += f"  | Description: {self.description}\n"
            output += f"  | Range: {self.range}\n"
            output += f"  | Base Type: {self.base_type}\n"
            output += f"  | Base Type Byte Size: {self.base_type_byte_size}\n"
            if self.struct_name:
                output += f"  | Struct Name: {self.struct_name}\n"
                output += f"  | Struct members: {self.members}\n"
        else:
            output += f"  | Description: void\n"

        return output