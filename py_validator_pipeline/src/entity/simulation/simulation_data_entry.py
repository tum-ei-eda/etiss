import logging

from typing import List, Dict, Any
from math import ceil

from src.entity.dwarf.dwarf_info import DwarfInfo
from src.entity.dwarf.formal_parameter import FormalParameter
from src.entity.dwarf.global_variable import GlobalVariable
from src.entity.dwarf.local_variable import LocalVariable
from src.entity.dwarf.march_manager import MArchManager
from src.util.gcc_dwarf_rv_mapper import GccDwarfMapper


class SimulationDataEntry:
    """
        This entity holds the information for one function call.
        The information includes
          - CPU state snapshots from prologue instructions
          - dwrites done during function execution
          - CPU state snapshots from epilogue instructions
        TODO:
            This entry class is already RV32 specific. In future
            entries should be created based on machine architecture.
    """

    def __init__(self):
        self.function_name: str = ""
        self.prologue: List[Dict[str, Any]] = []
        self.epilogue: List[Dict[str, Any]] = []
        self.dwrites: Dict[str, List[Dict[str, Any]]] = {}
        self.formal_param_locations: Dict[str, Any] = {}
        self.global_variable_locations: Dict[str, Any] = {}
        self.global_variables  = []
        self.formal_parameters = []
        self.local_variables = []
        self.frame_pointer = 0
        self.stack_pointer = 0
        self.index = 0
        self.logger = logging.getLogger(__name__)
        self.dwarf_info: None | DwarfInfo = None
        self.march_manager = MArchManager()

        # TODO: in future support other compilers
        self.mapper = GccDwarfMapper()

        self.comparison_line_lenght = 90



    def append_prologue_instruction(self, inst: str, pc, sp, fp, arg_regs: list, farg_regs: list) -> None:
        if self.frame_pointer == 0:
            self.frame_pointer = fp
        if self.stack_pointer == 0:
            self.stack_pointer = sp
        self.prologue.append({
            'idx': self.index,
            'instruction': inst,
            'pc': pc,
            'fp': fp,
            'sp': sp,
            'a0': arg_regs[0],
            'a1': arg_regs[1],
            'a2': arg_regs[2],
            'a3': arg_regs[3],
            'a4': arg_regs[4],
            'a5': arg_regs[5],
            'a6': arg_regs[6],
            'a7': arg_regs[7],
            'fa0': farg_regs[0],
            'fa1': farg_regs[1],
            'fa2': farg_regs[2],
            'fa3': farg_regs[3],
            'fa4': farg_regs[4],
            'fa5': farg_regs[5],
            'fa6': farg_regs[6],
            'fa7': farg_regs[7],
        })

        self.index += 1


    def append_epilogue_instruction(self, inst: str, pc, sp, fp, rv_regs: list, frv_regs) -> None:
        self.epilogue.append({
            'idx': self.index,
            'instruction': inst,
            'pc': pc,
            'sp': sp,
            'fp': fp,
            'a0': rv_regs[0],
            'a1': rv_regs[1],
            'fa0': frv_regs[0],
            'fa1': frv_regs[1],
        })
        self.index += 1

    def append_dwrite_instruction(self, pc, location, data, byte_size) -> None:
        if location not in self.dwrites:
            self.dwrites[location] = []

        self.dwrites[location].append({
            'idx': self.index,
            'pc': pc,
            'data': data,
            'location': location,
            'byte_size': byte_size,
        })
        self.index += 1


    def add_formal_param_locations(self, param_name, param_loc) -> None:
        # For now we assume all formal params are in fbregs
        # TODO: should frame pointer or stack pointer be used here?!
        self.formal_param_locations[param_name] = hex(self.frame_pointer +  param_loc)[2:]

    def add_global_variables(self, glob_vars: List[GlobalVariable]) -> None:
        self.global_variables = glob_vars.copy()

    def add_formal_parameters(self, formal_params: List[FormalParameter]) -> None:
        self.formal_parameters = formal_params.copy()

    def add_local_variables(self, local_vars: List[LocalVariable]) -> None:
        self.local_variables = local_vars.copy()

    def add_dwarf_info(self, dwarf_info: DwarfInfo):
        self.dwarf_info = dwarf_info


    def get_last_writes_to_global_var_locations(self) -> Dict[str, Dict[str, Any]]:
        last_writes = {}
        for var in self.global_variables:
            if var.has_more_than_one_element():
                # Handle array dwrite addresses
                n_of_elements = var.get_number_of_elements()
                byte_size = var.type_info.get_base().byte_size
                print(f"n of elements: {n_of_elements}, byte_size {byte_size}")
                var_name = var.get_name()
                loc = var.get_location_value()
                for idx in range(n_of_elements):
                    if loc in self.dwrites:
                        last_writes[f"{var_name}[{idx}]"] = self.dwrites[loc][-1]
                    loc = hex(int(loc, 16) +  byte_size)[2:]
            else:
                loc = var.get_location_value()
                # Handle variable with single memory location
                if loc in self.dwrites:
                    last_writes[var.get_name()] = self.dwrites[loc][-1]

        return last_writes

    def get_last_writes_to_mem_range(self, mem_start, bytes) -> List[Any]:

        last_writes = []
        addr = hex(mem_start)[2:]
        print(f"addr at start: {addr}")
        # Data writes seem to happen in 4 byte chunks
        xlen_bytes = 4
        n_of_addrs = ceil(bytes // xlen_bytes)
        for idx in range(n_of_addrs):
            try:
                if addr in self.dwrites:
                    last_writes.append(self.dwrites[addr][-1])
                addr = hex(int(addr, 16) + xlen_bytes)[2:]
            except Exception as e:
                print(f"Exception: {e}, addr: {addr}")
        return last_writes




    def get_first_writes_to_formal_params(self):
        first_writes = {}
        for param_name, location in self.formal_param_locations.items():
            if location in self.dwrites:
                first_writes[param_name] = self.dwrites[location][0]
        return first_writes


    def __str__(self) -> str:
        """
            A string representation of simulation data entry
        """
        output = ""
        if self.prologue:
            output += "  > Prologue instructions CPU state snapshots:\n"
            for inst in self.prologue:
                output += f"    | cswsp <{inst['pc']}>: <a0: {inst['a0']}, a1: {inst['a1']}, fa0: {inst['fa0']}, fa1: {inst['fa1']}>\n"
        formal_param_writes = self.get_first_writes_to_formal_params()
        if formal_param_writes:
            output += "  > First data writes to formal params stack addresses after prologue:\n"
            for var_name, first_dwrite in formal_param_writes.items():
                output += f"    | {var_name}:\t<pc: {first_dwrite['pc']}\tdata: {first_dwrite['data']}\taddress: {first_dwrite['location']}>\n"
        else:
            output += f"  > No formal parameters written to stack\n"
        global_var_dwrites = self.get_last_writes_to_global_var_locations()
        if global_var_dwrites:
            output += "  > Final data writes to global variable(s) before epilogue:\n"
            for var_name, last_dwrite in global_var_dwrites.items():
                output += f"    | {var_name}:\t<pc: {last_dwrite['pc']}\tdata: {last_dwrite['data']}\taddress: {last_dwrite['location']}>\n"
        else:
            output += f"  > No data writes to global variables\n"
        if self.epilogue:
            output += "  > Epilogue instructions CPU state snapshots:\n"
            for inst in self.epilogue:
                output += f"    | cjr <{inst['pc']}>: <a0: {inst['a0']}, a1: {inst['a1']}, fa0: {inst['fa0']}, fa1: {inst['fa1']}>\n"
        return output
