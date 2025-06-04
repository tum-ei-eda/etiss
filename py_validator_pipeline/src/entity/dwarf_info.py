import re
import logging
from typing import List, Any

from src.entity.compilation_unit import CompilationUnit
from src.entity.subprogram import Subprogram
from src.entity.variable import Variable
from src.entity.formal_parameter import FormalParameter
from src.entity.global_variable import GlobalVariable
from src.entity.local_variable import LocalVariable

class DwarfInfo:
    """
        A collection of data extracted
        from the DWARF debugging information
    """




    def __init__(self):
        self.logger = logging.getLogger(__name__)
        self.logger.info("New DwarfInfo instance initialized")

        self.subprogram = Subprogram()
        self.compilation_unit = CompilationUnit()
        self._binary_name = ""
        self._source_file = ""
        self._global_variables = []
        self._formal_parameters = []
        self._local_variables = []

    def set_source_file(self, source_file):
        self._source_file = source_file

    def set_binary_name(self, binary_name):
        self._binary_name = binary_name

    def set_subprogram_name(self, name) -> None:
        self.subprogram.set_name(name)

    def set_subprogram_low_pc(self, value) -> None:
        self.subprogram.low_pc = value

    def set_subprogram_high_pc(self, value) -> None:
        self.subprogram.high_pc = value

    def set_subprogram_low_and_high_pc(self, lowpc, highpc) -> None:
        # If the attribute has relative location, we add it to low PC
        if highpc < lowpc:
            highpc = lowpc + highpc
        self.subprogram.set_low_and_high_pc(lowpc, highpc)

    def set_subprogram_base_type(self, base_type) -> None:
        self.subprogram.set_base_type(base_type)

    def set_subprogram_base_type_byte_size(self, byte_size) -> None:
        self.subprogram.set_base_type_byte_size(byte_size)

    def set_subprogram_type_description(self, description) -> None:
        self.subprogram.set_type_description(description)

    def add_global_variable(self, global_var: Variable) -> None:
        self._global_variables.append(global_var)

    def add_formal_parameter(self, formal_param: FormalParameter) -> None:
        self._formal_parameters.append(formal_param)

    def add_local_variable(self, var) :
        self._local_variables.append(var)



    def extract_core_information(self, producer: str) -> None:
        self.compilation_unit.extract_core_information(producer)

    def get_low_pc(self) -> Any:
        return self.subprogram.low_pc

    def get_high_pc(self) -> Any:
        return self.subprogram.high_pc

    def get_global_variables(self) -> List[GlobalVariable]:
        return self._global_variables

    def get_formal_parameters(self) -> List[FormalParameter]:
        return self._formal_parameters

    def get_local_variables(self) -> List[LocalVariable]:
        return self._local_variables

    def __str__(self) -> str:
        """
            A string representation of the extracted DWARF info
        """
        output = ""
        output += str(self.compilation_unit)

        if self._global_variables:
            output += "  > Global variables:\n"
            for glob_var in self._global_variables:
                output += str(glob_var)
        output += str(self.subprogram)

        if self._formal_parameters:
            output += "      > Formal parameters:\n"
            for param in self._formal_parameters:
                output += str(param)

        if self._local_variables:
            output += "      > Local variables:\n"
            for var in self._local_variables:
                output += str(var)
        return output

