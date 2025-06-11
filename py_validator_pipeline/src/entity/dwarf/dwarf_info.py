import logging
from typing import List, Any

from src.entity.dwarf.compilation_unit import CompileUnit
from src.entity.dwarf.frame_base_info import FrameBaseInfo
from src.entity.dwarf.subprogram import Subprogram
from src.entity.dwarf.type_construct import TypeConstruct
from src.entity.dwarf.formal_parameter import FormalParameter
from src.entity.dwarf.global_variable import GlobalVariable
from src.entity.dwarf.local_variable import LocalVariable

class DwarfInfo:
    """
        A collection of data extracted from the DWARF debugging information
    """

    def __init__(self):
        self.logger = logging.getLogger(__name__)
        self.logger.debug("New DwarfInfo instance initialized")

        self.subprogram = Subprogram()
        self.compilation_unit = CompileUnit()
        self.frame_base_infos = []
        self._binary_name = ""
        self._source_file = ""
        self._function_of_interest = ""
        self._global_variables = []
        self._formal_parameters = []
        self._local_variables = []


    def set_source_file(self, source_file: str):
        self._source_file = source_file

    def set_binary_name(self, binary_name: str):
        self._binary_name = binary_name

    def set_function_of_interest(self, function_of_interest: str):
        self._function_of_interest = function_of_interest

    def set_subprogram_name(self, name: str) -> None:
        self.subprogram.set_name(name)

    def set_subprogram_low_and_high_pc(self, lowpc, highpc) -> None:
        # If the attribute has relative location, we add it to low PC
        if highpc < lowpc:
            highpc = lowpc + highpc
        self.subprogram.set_low_and_high_pc(lowpc, highpc)

    def set_subprogram_type_information(self, type_info: TypeConstruct):
        self.subprogram.create_type_information(type_info)

    def add_frame_base_info(self, frame_base_info: FrameBaseInfo):
        if not self.frame_base_infos:
            self.frame_base_infos.append(frame_base_info)
        elif self.frame_base_infos[-1].get_reg() != frame_base_info.get_reg() or self.frame_base_infos[-1].get_offset() != frame_base_info.get_offset():
            self.frame_base_infos.append(frame_base_info)


    def add_global_variable(self, global_var: GlobalVariable) -> None:
        self._global_variables.append(global_var)

    def add_formal_parameter(self, formal_param: FormalParameter) -> None:
        self._formal_parameters.append(formal_param)

    def add_local_variable(self, var: LocalVariable) -> None:
        self._local_variables.append(var)



    def extract_core_information(self, producer: str, little_endian: bool) -> None:
        self.compilation_unit.extract_core_information(producer, little_endian)

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
        output = "DWARF debug information overview\n"
        output += f"  | Binary: {self._binary_name}\n"
        output += f"  | Source File: {self._source_file}\n"
        output += f"  | Function of interest: {self._function_of_interest}\n"

        output += "Extracted DWARF debug information:\n"

        output += str(self.compilation_unit)

        if self.frame_base_infos:
            output += "  > CFA register values and offsets\n"
            for info in self.frame_base_infos:
                output += f"{str(info)}"

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

