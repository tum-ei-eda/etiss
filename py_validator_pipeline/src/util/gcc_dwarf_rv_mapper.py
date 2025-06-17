from typing import Dict


class GccDwarfMapper:


    _gcc_dwarf_rv_mapper: Dict[str, str] = {
        "char": "int",
        "signed char": "int",
        "unsigned char": "int",
        "short int": "int",
        "short unsigned int": "int",
        "int": "int",
        "unsigned int": "int",
        "long int": "int",
        "long unsigned int": "int",
        "long long int": "long long",
        "long long unsigned int": "long long",
        "float": "float",
        "double": "double",
        "long double": "long double",
        "_Bool": "int",
        "struct": "struct",
    }

    def __init__(self) -> None:
        pass

    def get_mapping_for_dwarf_base_type(self, key: str) -> str:
        value = ""
        if self._gcc_dwarf_rv_mapper.get(key):
            value += self._gcc_dwarf_rv_mapper.get(key)
        return value




