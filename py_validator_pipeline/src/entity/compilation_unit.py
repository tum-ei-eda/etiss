import re

class CompilationUnit:

    def __init__(self):
        self.march = None
        self.mabi = None
        self.misa_spec = None
        self.indent = 2

    def extract_core_information(self, producer: str) -> None:
        pattern = r'-mabi=([^\s]+)|-march=([^\s]+)|-misa-spec=([^\s]+)'

        core_info = re.findall(pattern, producer)

        for mabi, march, misa_spec in core_info:
            if mabi:
                self.mabi = mabi
            if march:
                self.march = march
            if misa_spec:
                self.misa_spec = misa_spec


    def __str__(self) -> str:
        output = "Extracted DWARF debug infromation:\n"
        output += f"{self.indent*' '}┌ Architecture: {self.march}\n"
        output += f"{self.indent*' '}├ ABI: {self.mabi}\n"
        output += f"{self.indent*' '}└ ISA specification: {self.misa_spec}\n"

        return output