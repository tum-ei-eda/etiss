import re

class CompileUnit:
    """
        An instance of the data extracted from top DIE
    """

    def __init__(self):
        self.march = None
        self.mabi = None
        self.misa_spec = None
        self.little_endian = False
        self.indent = 2

    def extract_core_information(self, producer: str, little_endian: bool) -> None:
        """
        In the initial test setting we can assume producer to have
        parameters mabi, march and misa-spec.
        """
        pattern = r'-mabi=([^\s]+)|-march=([^\s]+)|-misa-spec=([^\s]+)'

        core_info = re.findall(pattern, producer)

        for mabi, march, misa_spec in core_info:
            if mabi:
                self.mabi = mabi
            if march:
                self.march = march
            if misa_spec:
                self.misa_spec = misa_spec

        self.little_endian = little_endian


    def __str__(self) -> str:
        """
        String representation of CompileUnit
        """
        output = ""
        output += f"{self.indent*' '}┌ Architecture: {self.march}\n"
        output += f"{self.indent*' '}├ ABI: {self.mabi}\n"
        output += f"{self.indent*' '}├ ISA specification: {self.misa_spec}\n"
        output += f"{self.indent*' '}└ Little endian: {self.little_endian}\n"

        return output