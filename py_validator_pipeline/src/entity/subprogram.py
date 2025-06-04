class Subprogram:

    def __init__(self):
        self.low_pc = None
        self.high_pc = None
        self.name = None
        self.type_description = None
        self.base_type = None
        self.base_type_byte_size = None
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



    def __str__(self) -> str:
        output = ""
        output += f"{self.indent*' '}> Subprogram of interest:\n"
        output += f"{self.indent*' '}  ┌ Name: {self.name}\n"
        output += f"{self.indent*' '}  ├ Type composition: {self.type_description}\n"
        output += f"{self.indent*' '}  ├ Base type: {self.base_type}\n"
        output += f"{self.indent*' '}  ├ Base type byte size: {self.base_type_byte_size}\n"
        output += f"{self.indent*' '}  ├ Low-PC: {self.low_pc}\n"
        output += f"{self.indent*' '}  └ High-PC: {self.high_pc}\n"
        return output



