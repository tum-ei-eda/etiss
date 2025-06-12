import logging
from typing import List, Dict, Any

from src.entity.dwarf.compilation_unit import CompileUnit
from src.entity.dwarf.frame_base_info import FrameBaseInfo
from src.entity.dwarf.subprogram import Subprogram
from src.entity.dwarf.global_variable import GlobalVariable


from src.exception.pipeline_exceptions import DWARFExtractionException

class DwarfInfo:
    """
        A collection of data extracted from the DWARF debugging information
    """
    def __init__(self) -> None:
        self.logger = logging.getLogger(__name__)
        self.logger.debug("New DwarfInfo instance initialized")

        self._binary_name: str = ""
        self._source_file: str = ""
        self._function_of_interest: str = ""

        self.compilation_unit: CompileUnit = CompileUnit()
        self.subprograms: Dict[str, Subprogram] = {}
        self._global_variables: List[GlobalVariable] = []


    def set_source_file(self, source_file: str) -> None:
        self._source_file = source_file

    def set_binary_name(self, binary_name: str) -> None:
        self._binary_name = binary_name

    def set_function_of_interest(self, function_of_interest: str) -> None:
        self._function_of_interest = function_of_interest

    def has_subprogram_with_pc_as_low_pc(self, pc: int) -> bool:
        subprogram_found: bool = False
        for s in self.subprograms.values():
            if pc == s.low_pc:
                subprogram_found = True
                break
        return subprogram_found

    def get_subprogram_with_pc_as_low_pc(self, pc: int) -> None | Subprogram:
        subprogram: None | Subprogram = None
        for s in self.subprograms.values():
            if pc == s.low_pc:
                subprogram = s
                break
        return subprogram

    def get_subprogram_by_name(self, name: str) -> None | Subprogram:
        return self.subprograms.get(name)

    def get_subprogram_of_interest(self) -> Subprogram:
        if not self.subprograms.get(self._function_of_interest):
            error_msg = "Subprogram of interest not found during DWARF extraction. Is the name of the subprogram correct?"
            self.logger.error(error_msg)
            raise DWARFExtractionException(error_msg)
        return self.subprograms.get(self._function_of_interest)

    def add_subprogram(self, subprogram: Subprogram) -> None:
        self.subprograms[subprogram.name] = subprogram

    def add_frame_base_info(self, frame_base_info: FrameBaseInfo, pc: int) -> None:
        subprogram = self.get_subprogram_with_pc_as_low_pc(pc)
        subprogram.add_frame_base_info(frame_base_info)

    def add_global_variable(self, global_var: GlobalVariable) -> None:
        self._global_variables.append(global_var)

    def extract_core_information(self, producer: str, little_endian: bool) -> None:
        self.compilation_unit.extract_core_information(producer, little_endian)

    def get_global_variables(self) -> List[GlobalVariable]:
        return self._global_variables

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

        if self._global_variables:
            output += "  > Global variables:\n"
            for glob_var in self._global_variables:
                output += str(glob_var)

        for sp in self.subprograms.values():
            output += str(sp)

            if sp.has_formal_parameters():
                output += "      > Formal parameters:\n"
                for param in sp.get_formal_parameters():
                    output += str(param)

            if sp.has_local_variables():
                output += "      > Local variables:\n"
                for var in sp.get_local_variables():
                    output += str(var)
        return output

