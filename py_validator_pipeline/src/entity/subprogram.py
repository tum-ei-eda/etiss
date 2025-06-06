from src.entity.type_construct import TypeConstruct

"""
    A class instance of representing data extracted from subprogram DIE
"""
class Subprogram:

    def __init__(self):
        self.low_pc = None
        self.high_pc = None
        self.name = None
        self.type_description = None
        self.base_type = None
        self.base_type_byte_size = None
        self.range = 0
        self.indent = 2


    def set_low_and_high_pc(self, low_pc, high_pc):
        self.low_pc = low_pc
        self.high_pc = high_pc


    def set_name(self, name):
        self.name = name

    def set_type_description(self, type_description):
        self.type_description = type_description

    def set_base_type(self, base_type):
        self.base_type = base_type

    def set_base_type_byte_size(self, byte_size):
        self.base_type_byte_size = byte_size

    def create_type_information(self, type_construct: TypeConstruct) -> None:
        self.base_type = type_construct.base_type
        self.base_type_byte_size = type_construct.base_type_byte_size
        self.range = type_construct.range
        if type_construct.base_type and type_construct.base_type != 'None':
            self.type_description = type_construct.description
        else:
            self.type_description = 'void'


    def get_base_type(self) -> str:
        return str(self.base_type)


    def __str__(self) -> str:
        output = ""
        output += f"{self.indent*' '}> Subprogram of interest:\n"
        output += f"{self.indent*' '}  ┌ Name: {self.name}\n"
        output += f"{self.indent*' '}  ├ Type composition: {self.type_description}\n"
        output += f"{self.indent*' '}  ├ Base type: {self.base_type}\n"
        output += f"{self.indent*' '}  ├ Base type byte size: {self.base_type_byte_size}\n"
        if self.range and (self.range != self.base_type_byte_size):
            output += f"{self.indent*' '}  ├ Range: {self.range}\n"
        output += f"{self.indent*' '}  ├ Low-PC: {self.low_pc}\n"
        output += f"{self.indent*' '}  └ High-PC: {self.high_pc}\n"
        return output



