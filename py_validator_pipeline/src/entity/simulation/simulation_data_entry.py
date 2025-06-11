import logging

from typing import List, Dict, Any

from src.entity.dwarf.dwarf_info import DwarfInfo
from src.entity.dwarf.formal_parameter import FormalParameter
from src.entity.dwarf.global_variable import GlobalVariable
from src.entity.dwarf.local_variable import LocalVariable
from src.march_manager import MArchManager


class SimulationDataEntry:
    """
        This entity holds the information for one function call.
        The information includes
          - CPU state snapshots from prologue instructions
          - dwrites done during function execution
          - CPU state snapshots from epilogue instructions
    """

    def __init__(self):
        self.prologue = []
        self.epilogue = []
        self.dwrites = {}
        self.formal_param_locations = {}
        self.global_variable_locations = {}
        self.global_variables  = []
        self.formal_parameters = []
        self.local_variables = []
        self.frame_pointer = 0
        self.index = 0
        self.logger = logging.getLogger(__name__)
        self.dwarf_info = None
        self.march_manager = MArchManager()

        self.comparison_line_lenght = 90



    def append_prologue_instruction(self, inst: str, pc, fp, arg_regs: list, farg_regs: list) -> None:
        if self.frame_pointer == 0:
            self.frame_pointer = fp
        self.prologue.append({
            'idx': self.index,
            'instruction': inst,
            'pc': pc,
            'fp': fp,
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


    def append_epilogue_instruction(self, inst: str, pc, fp, rv_regs: list, frv_regs) -> None:
        self.epilogue.append({
            'idx': self.index,
            'instruction': inst,
            'pc': pc,
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

    def add_global_variable_and_location(self, var_name, location):
        # For now we assume all global variables are in memory
        self.global_variable_locations[var_name] = location


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
                byte_size = var.get_base_type_byte_size()
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

    def get_last_write_to_global_variables(self):
        last_writes = {}
        for var_name, location in self.global_variable_locations.items():
            if location in self.dwrites:
                last_writes[var_name] = self.dwrites[location][-1]
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


    def compare_entries(self, other_entry, debug: bool) -> str:
        """
            A collection of methods that co-verify entries from the golden reference and from
            the instruction set under verification.
        """
        result = ""
        if debug:
            self.logger.info("Debug mode on, comparing function prologue and epilogue")
            result += self.compare_prologues(other_entry.prologue)

        result += self.compare_formal_param_values(other_entry.get_first_writes_to_formal_params())

        result += self.compare_global_variable_values(other_entry.get_last_writes_to_global_var_locations())

        if debug:
            result += self.compare_epilogues(other_entry.epilogue)

        result += self.compare_return_values(other_entry)
        return result


    def compare_prologues(self, other_entry_prologue) -> str:
        section = "  | Function prologue"
        section += (self.comparison_line_lenght - len(section)) * '.'
        result = ""
        if len(self.prologue) == 0 and len(other_entry_prologue) == 0:
            result += section + 'FAIL\n'
            result += f"      no snapshots written to prologue\n"
        elif len(self.prologue) == len(other_entry_prologue):
            mismatch = ""
            for idx, entry in enumerate(self.prologue):
                for key in ['pc', 'a0', 'a1', 'fa0', 'fa1']:
                    if entry[key] != other_entry_prologue[idx][key]:
                        mismatch += f"        mismatch at index {idx}: {entry[key]} vs {other_entry_prologue[idx][key]}\n"
            if mismatch:
                result += section + 'FAIL\n'
                result += f'      value mismatch:\n{mismatch}\n'
        else:
            result += section + 'FAIL\n'
            result += "      different number of instructions\n"

        if not result:
            result += "Function prologue ... OK\n"
        return result

    def compare_formal_param_values(self, other_entry_formal_params) -> str:
        section = "  | Formal parameters"
        section += (self.comparison_line_lenght - len(section)) * '.'
        result = ""
        formal_param_values = self.get_first_writes_to_formal_params()
        if len(formal_param_values) == 0 and len(other_entry_formal_params) == 0:
            result += section + 'NA\n'
            result += "      No formal parameters\n"
        elif len(formal_param_values) == len(other_entry_formal_params):
            for var_name, entry in formal_param_values.items():
                if entry['data'] != other_entry_formal_params[var_name]['data']:
                    result += section + 'FAIL\n'
                    result += f"      data mismatch in variable {var_name}: {entry['data']} != {other_entry_formal_params[var_name]['data']}\n"
            else:
                print(f"Golden:\n{formal_param_values}\n, isuv:\n {other_entry_formal_params}")
        else:
            result += section + 'FAIL\n'
            result += "      number of parameters written to stack do not match\n"
        if not result:
            result += section + 'OK\n'
        return result

    def compare_global_variable_values(self, other_entry_global_variable_values) -> str:
        section = "  | Global variables"
        section += (self.comparison_line_lenght - len(section)) * '.'
        result = ""
        global_var_values = self.get_last_writes_to_global_var_locations()
        if len(global_var_values) == 0 and len(other_entry_global_variable_values) == 0:
            result += section + 'NA\n'
            result += "      no global variables\n"
        elif len(global_var_values) == len(other_entry_global_variable_values):
            for var_name, entry in global_var_values.items():
                if entry['data'] != other_entry_global_variable_values[var_name]['data']:
                    result += section + 'FAIL\n'
                    result += f"      data mismatch in variable {var_name}: {entry['data']} != {other_entry_global_variable_values[var_name]['data']}\n"
        else:
            result += section + 'FAIL\n'
            result += "      number of variables do not match\n"

        if not result:
            result += section + 'OK\n'
        return result

    def compare_epilogues(self, other_entry_epilogue) -> str:
        section = "  | Function epilogue"
        section += (self.comparison_line_lenght - len(section)) * '.'
        result = ""
        if len(self.epilogue) == 0 and len(other_entry_epilogue) == 0:
            result += section + 'FAIL\n'
            result += "      no snapshots written to epilogue\n"
        elif len(self.epilogue) == len(other_entry_epilogue):
            mismatch = ""
            for idx, entry in enumerate(self.epilogue):
                for key in ['pc', 'a0', 'a1', 'fa0', 'fa1']:
                    if entry[key] != other_entry_epilogue[idx][key]:
                        mismatch += f"        mismatch at index {idx}: {entry[key]} vs. {other_entry_epilogue[idx][key]}\n"
            if mismatch:
                result += section + 'FAIL\n'
                result += f'      value mismatch:\n{mismatch}\n'
        else:
            result += section + 'FAIL\n'
            result += "      different number of instructions\n"

        if not result:
            result += section + 'OK\n'
        return result


    def compare_return_values(self, custom_ise) -> str:
        section = "  | Return value"
        section += (self.comparison_line_lenght - len(section)) * '.'
        result = ""

        if not self.dwarf_info or not custom_ise.dwarf_info:
            self.logger.error("Dwarf debug information extraction missing. Aborting return value comparison.")
            result += section + 'FAIL\n'
            result += "      Missing extracted DWARF debug information\n"
        fun_return_type = self.dwarf_info.subprogram.get_base_type()

        if not result and fun_return_type == 'None':
            self.logger.info("Void function has no return value")
            result = section + 'NA\n'
            result += "      Void function has no return value\n"
        elif not result:
            gr_rv = self.fetch_return_value(self, fun_return_type)
            ci_rv = self.fetch_return_value(custom_ise, fun_return_type)
            if not gr_rv or not ci_rv:
                result = section + 'NA\n'
                result += f"      Return value is inconclusive. See log entries for more information.\n"
            else:
                if gr_rv != ci_rv:
                    result += section + 'FAIL\n'
                    result += f"      mismatch in return value: golden reference: {gr_rv}, custom ISE: {ci_rv}\n"
                else:
                    result += section + 'OK\n'
        return result

    def fetch_return_value(self, entry, func_return_base_type):
        m = entry.dwarf_info.compilation_unit.march
        march = self.march_manager.get_march_with_name(m)
        rv = None
        match func_return_base_type:
            case 'int':
                self.logger.info(
                    "Subprogram has return type int. Verifying return values based on machine architecture.")
                rv = march.fetch_int_return_value(entry)
            case 'unsigned int':
                self.logger.info(
                    "Subprogram has return type unsigned int. Verifying return values based on machine architecture.")
                rv = march.fetch_unsigned_int_return_value(entry)
            case 'char':
                self.logger.info(
                    "Subprogram has return type char. Verifying return values based on machine architecture.")
                rv = march.fetch_char_return_value(entry)
            case 'float':
                self.logger.info(
                    "Subprogram has return type float. Verifying return values based on machine architecture.")
                rv = march.fetch_float_return_value(entry)
        return rv


    def fetch_int_return_value(self, entry) -> Any:
        m = entry.dwarf_info.compilation_unit.march
        march = self.march_manager.get_march_with_name(m)
        rv = march.fetch_int_return_value(entry)
        return rv

    def fetch_float_return_value(self, entry) -> Any:
        m = entry.dwarf_info.compilation_unit.march
        march = self.march_manager.get_march_with_name(m)
        rv = march.fetch_float_return_value(entry)
        return rv








