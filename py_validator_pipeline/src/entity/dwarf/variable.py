from abc import ABC, abstractmethod

from src.entity.dwarf.type_construct import TypeConstruct


class Variable(ABC):
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
        self._name = None
        self._location = None
        self._type_description = None
        self._base_type = None
        self._base_type_byte_size = None
        self._range = 1
        self._type_desrciption_as_list = []
        self._range_elements = []
        self.indent = 2


    def set_name(self, name):
        self._name = name

    def set_location(self, location):
        self._location = location

    def set_type_description(self, description):
        self._type_description = description

    def add_element_to_type_definition_list(self, element: str) -> None:
        self._type_desrciption_as_list.append(element)

    def add_element_to_range_list(self, element: int) -> None:
        self._range_elements.append(element)

    def create_type_information(self, type_construct: TypeConstruct) -> None:
        self._base_type = type_construct.base_type
        self._base_type_byte_size = type_construct.base_type_byte_size
        self._range = type_construct.range
        if type_construct.base_type and type_construct.base_type != 'None':
            self._type_description = type_construct.description
        else:
            self._type_description = '<UNDEFINED>'

    def set_base_type(self, base_type):
        self._base_type = base_type

    def set_base_type_byte_size(self, byte_size) -> None:
        self._base_type_byte_size = byte_size

    def set_range(self, var_range: int) -> None:
        # For now we support continuous ranges
        self._range = var_range

    def has_more_than_one_element(self) -> bool:
        result = False
        if self._range and self._base_type_byte_size:
            result = self._range / self._base_type_byte_size != 1
        return result

    def get_number_of_elements(self) -> int:
        result = 0
        if self._range and self._base_type_byte_size:
            result = int(self._range / self._base_type_byte_size)
        return result

    def get_base_type_byte_size(self) -> int:
        return self._base_type_byte_size

    def get_name(self) -> str:
        return self._name

    def get_location(self):
        return self._location

    @abstractmethod
    def get_location_value(self):
        """
            This method should be implemented by subclasses.
        """
        pass


    def __str__(self) -> str:
        output = ""
        output += f"{self.indent*' '}  ┌ Name: {self._name}\n"
        output += f"{self.indent*' '}  ├ Type composition: {self._type_description}\n"
        output += f"{self.indent*' '}  ├ Base Type: {self._base_type}\n"
        output += f"{self.indent*' '}  ├ Base Type/Byte Size: {self._base_type_byte_size}\n"
        if self._range != self._base_type_byte_size:
            output += f"{self.indent*' '}  ├ Range: {self._range}\n"
        output += f"{self.indent*' '}  └ Location: {self._location}\n"
        return output
