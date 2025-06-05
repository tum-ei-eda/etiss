from math import prod



class TypeConstruct:
    """
        A convenience class to construct and instance of type information.
        The variables all have type information and additionally the
        chosen subprogram has type information as well.
    """

    def __init__(self):
        self._range_list = []
        self._description_list = []
        self.base_type = None
        self.base_type_byte_size = None
        self.range = 0
        self.description = ""


    def add_element_to_description_list(self, element: str) -> None:
        self._description_list.append(element)

    def add_element_to_range_list(self, element: int) -> None:
        self._range_list.append(element)


    def create_type_information(self, base_type, base_type_byte_size):

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
        output = "TypeConstruct:\n"
        output += f"  | Description: {self.description}\n"
        output += f"  | Range: {self.range}\n"
        output += f"  | Base Type: {self.base_type}\n"
        output += f"  | Base Type Byte Size: {self.base_type_byte_size}\n"

        return output