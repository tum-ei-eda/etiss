import logging

from src.entity.dwarf.march_manager import MArchManager
from src.entity.dwarf.types import AbstractType, BaseType, StructType, UnionType
from src.entity.simulation.simulation_data_entry import SimulationDataEntry
from src.exception.pipeline_exceptions import VerificationProcessException
from src.util.gcc_dwarf_rv_mapper import GccDwarfMapper


class VerificationStage:
    
    def __init__(self):
        self.logger = logging.getLogger(__name__)
        self.comparison_line_lenght = 90
        self.march_manager = MArchManager()
        # TODO: in future support other compilers
        self.mapper = GccDwarfMapper()
        


    def compare_entries(self, entry_gr: SimulationDataEntry, entry_uv: SimulationDataEntry) -> str:
        """
            A collection of methods that co-verify entries from the golden reference and from
            the instruction set under verification.
        """
        result = ""
        expanded_pipeline = False
        if expanded_pipeline:
            self.logger.info("Debug mode on, comparing function prologue and epilogue")
            result += self.compare_prologues(entry_gr.prologue, entry_uv.prologue)

            result += self.compare_formal_param_values(entry_gr.get_first_writes_to_formal_params(), entry_uv.get_first_writes_to_formal_params())

        result += self.compare_global_variable_values(entry_gr.get_last_writes_to_global_var_locations() ,entry_uv.get_last_writes_to_global_var_locations())

        if expanded_pipeline:
            result += self.compare_epilogues(entry_gr.epilogue, entry_uv.epilogue)

        result += self.compare_return_values(entry_gr, entry_uv)
        return result


    def compare_prologues(self, entry_gr_prologue, entry_uv_prologue) -> str:
        section = "  | Function prologue"
        section += (self.comparison_line_lenght - len(section)) * '.'
        result = ""
        if len(entry_gr_prologue) == 0 and len(entry_uv_prologue) == 0:
            result += section + 'FAIL\n'
            result += f"      no snapshots written to prologue\n"
        elif len(entry_gr_prologue) == len(entry_uv_prologue):
            mismatch = ""
            for idx, entry in enumerate(entry_gr_prologue):
                for key in ['pc', 'a0', 'a1', 'fa0', 'fa1']:
                    if entry[key] != entry_uv_prologue[idx][key]:
                        mismatch += f"        mismatch at index {idx}: {entry[key]} vs {entry_uv_prologue[idx][key]}\n"
            if mismatch:
                result += section + 'FAIL\n'
                result += f'      value mismatch:\n{mismatch}\n'
        else:
            result += section + 'FAIL\n'
            result += "      different number of instructions\n"

        if not result:
            result += section + "OK\n"
        return result


    def compare_formal_param_values(self, entry_gr_formal_params, entry_uv_formal_params) -> str:
        section = "  | Formal parameters"
        section += (self.comparison_line_lenght - len(section)) * '.'
        result = ""
        if len(entry_gr_formal_params) == 0 and len(entry_uv_formal_params) == 0:
            result += section + 'NA\n'
            result += "      No data writes to formal parameter locations\n"
        elif len(entry_gr_formal_params) == len(entry_uv_formal_params):
            for var_name, entry in entry_gr_formal_params.items():
                if entry['data'] != entry_uv_formal_params[var_name]['data']:
                    result += section + 'FAIL\n'
                    result += f"      data mismatch in variable {var_name}: {entry['data']} != {entry_uv_formal_params[var_name]['data']}\n"
        else:
            result += section + 'FAIL\n'
            result += "      number of parameters written to stack do not match\n"
        if not result:
            result += section + 'OK\n'
        return result


    def compare_global_variable_values(self, entry_gr_global_var_values, entry_uv_global_variable_values) -> str:
        section = "  | Global variables"
        section += (self.comparison_line_lenght - len(section)) * '.'
        result = ""

        if len(entry_gr_global_var_values) == 0 and len(entry_uv_global_variable_values) == 0:
            result += section + 'NA\n'
            result += "      no data writes to global variable locations\n"
        elif len(entry_gr_global_var_values) == len(entry_uv_global_variable_values):
            for var_name, entry in entry_gr_global_var_values.items():
                if entry['data'] != entry_uv_global_variable_values[var_name]['data']:
                    result += section + 'FAIL\n'
                    result += f"      data mismatch in variable {var_name}: {entry['data']} != {entry_uv_global_variable_values[var_name]['data']}\n"
        else:
            result += section + 'FAIL\n'
            result += "      number of variables do not match\n"

        if not result:
            result += section + 'OK\n'
        return result


    def compare_epilogues(self, entry_gr_epilogue, entry_uv_epilogue) -> str:
        section = "  | Function epilogue"
        section += (self.comparison_line_lenght - len(section)) * '.'
        result = ""
        if len(entry_gr_epilogue) == 0 and len(entry_uv_epilogue) == 0:
            result += section + 'FAIL\n'
            result += "      no snapshots written to epilogue\n"
        elif len(entry_gr_epilogue) == len(entry_uv_epilogue):
            mismatch = ""
            for idx, entry in enumerate(entry_gr_epilogue):
                for key in ['pc', 'a0', 'a1', 'fa0', 'fa1']:
                    if entry[key] != entry_uv_epilogue[idx][key]:
                        mismatch += f"        mismatch at index {idx}: {entry[key]} vs. {entry_uv_epilogue[idx][key]}\n"
            if mismatch:
                result += section + 'FAIL\n'
                result += f'      value mismatch:\n{mismatch}\n'
        else:
            result += section + 'FAIL\n'
            result += "      different number of instructions\n"

        if not result:
            result += section + 'OK\n'
        return result


    def compare_return_values(self, entry_gr, custom_ise) -> str:
        section = "  | Return value"
        section += (self.comparison_line_lenght - len(section)) * '.'
        result = ""

        if not entry_gr.dwarf_info or not custom_ise.dwarf_info:
            self.logger.error("Dwarf debug information extraction missing. Aborting return value comparison.")
            result += section + 'FAIL\n'
            result += "      Missing extracted DWARF debug information\n"
        fun_return_type = entry_gr.dwarf_info.get_subprogram_by_name(entry_gr.function_name).type_info

        if not result and fun_return_type is None:
            self.logger.debug("Void function has no return value")
            result = section + 'NA\n'
            result += "      Void function has no return value\n"
        elif not result:
            gr_rv = self.fetch_return_value(entry_gr, fun_return_type)
            ci_rv = self.fetch_return_value(custom_ise, fun_return_type)
            if gr_rv is None or ci_rv is None:
                result = section + 'NA\n'
                result += f"      Return value is inconclusive. Return values: {gr_rv} (golden ref), {ci_rv} (other), function return type: {str(fun_return_type)}. See log entries for more information.\n"
            else:
                if gr_rv != ci_rv:
                    result += section + 'FAIL\n'
                    result += f"      mismatch in return value: golden reference: {gr_rv}, custom ISE: {ci_rv}\n"
                else:
                    result += section + 'OK\n'
        return result


    def fetch_return_value(self, entry, sp_return_type: AbstractType):
        m = entry.dwarf_info.compilation_unit.march
        march = self.march_manager.get_march_with_name(m)
        rv = None

        self.logger.debug(
            f"{march.get_march_name()}: subprogram {entry.function_name} has return type {str(sp_return_type)}. Verifying return values based on machine architecture.")

        match sp_return_type:
            case BaseType():
                base_type = self.mapper.get_mapping_for_dwarf_base_type(sp_return_type.base_type)

                match base_type:
                    case 'int':
                        rv = march.fetch_int_return_value(entry)
                    case 'long long':
                        rv = march.fetch_long_long_return_value(entry)
                    case 'float':
                        rv = march.fetch_float_return_value(entry)
                    case 'double':
                        rv = march.fetch_double_return_value(entry)
                    case 'long double':
                        rv = march.fetch_long_double_return_value(entry)
                    case _:
                        err = f"No conversion for DWARF base type {sp_return_type}"
                        self.logger.error(err)
                        raise VerificationProcessException(err)
            case StructType():
                rv = march.fetch_struct_return_value(entry)
            case UnionType():
                rv = march.fetch_union_return_value(entry)

        self.logger.debug(f"{march.get_march_name()}: extracted return value {rv}")
        return rv


