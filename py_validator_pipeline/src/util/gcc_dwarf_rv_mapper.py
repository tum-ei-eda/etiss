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

    _gcc_dwarf_size_mapper: Dict[str, int] = {
        "char": 1,
        "signed char": 1,
        "unsigned char": 1,
        "short int": 2,
        "short unsigned int": 2,
        "int": 4,
        "unsigned int": 4,
        "long int": 4,
        "long unsigned int": 4,
        "long long int": 8,
        "long long unsigned int": 8,
        "float": 4,
        "double": 8,
        "long double": 16,
        "_Bool": 1,
    }

    def __init__(self) -> None:
        pass

    def get_mapping_for_dwarf_base_type(self, key: str) -> str:
        value = ""
        if self._gcc_dwarf_rv_mapper.get(key):
            value += self._gcc_dwarf_rv_mapper.get(key)
        return value

    def get_byte_size_for_base_type(self, key: str) -> int:
        value = 0
        if self._gcc_dwarf_size_mapper.get(key):
            value += self._gcc_dwarf_size_mapper.get(key)
        return value




