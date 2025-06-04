from abc import ABC, abstractmethod

class Variable(ABC):

    def __init__(self) -> None:
        self._name = None
        self._location = None
        self._type_description = None
        self._base_type = None
        self._base_type_byte_size = None
        self._range = 1
        self.indent = 2


    def set_name(self, name):
        self._name = name

    def set_location(self, location):
        self._location = location

    def set_type_description(self, description):
        self._type_description = description

    def set_base_type(self, base_type):
        self._base_type = base_type

    def set_base_type_byte_size(self, byte_size) -> None:
        self._base_type_byte_size = byte_size

    def set_range(self, range: int) -> None:
        # For now we support continuous ranges
        self._range = range

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
        output += f"{self.indent*' '}  └ Range: {self._range}\n"
        return output

"""
A hand-written example from which ASCII-symbols can be copied
    ├─main - call #i
    └┐
     ├─ cswsp <PC>: <a0: 0, a1: 0, fa0: 0, fa1: 0> 
     ├─ cswsp <PC>: <a0: 0, a1: 0, fa0: 0, fa1: 0>
     └┐
      ├─ dwrite <PC>: <data: 00, address: 00>
      ├─ dwrite <PC>: <data: 00, address: 00>
     ┌┘
     ├─ cjr <PC>: <a0: 0, a1: 0, fa0: 0, fa1: 0>
    ┌┘
"""