import logging
from collections import defaultdict
from typing import List, Dict, Any

from src.entity.dwarf.march_manager import MArchManager
from src.entity.dwarf.types import AbstractType, BaseType, StructType, UnionType
from src.entity.simulation.simulation_data_entry import SimulationDataEntry
from src.exception.pipeline_exceptions import VerificationProcessException
from src.util.gcc_dwarf_rv_mapper import GccDwarfMapperForRV32


class VerificationStage:
    
    def __init__(self):
        self.logger = logging.getLogger(__name__)
        self.comparison_line_lenght = 90
        self.march_manager = MArchManager()
        # TODO: in future support other compilers
        self.mapper = GccDwarfMapperForRV32()
        


    def compare_entries(self, entry_gr: SimulationDataEntry, entry_uv: SimulationDataEntry) -> str:
        """
        Compare simulation data entries from a golden reference and a unit under verification.

        This method co-verifies two `SimulationDataEntry` instances by comparing selected
        parts of their execution state, such as:
            - Global variable writes
            - Return values
            - (Optional) Function prologues, formal parameters, and epilogues

        The `expanded_pipeline` flag can be toggled to enable deeper comparisons like
        prologue/epilogue and first writes to formal parameters.

        Args:
            entry_gr: Simulation entry from the golden reference.
            entry_uv: Simulation entry from the implementation under verification.

        Returns:
            A string containing the comparison report.
        """
        result = ""
        expanded_pipeline = False
        if expanded_pipeline:
            self.logger.info("Debug mode on, comparing function prologue and epilogue")
            result += self._compare_prologues(entry_gr.prologue, entry_uv.prologue)

            result += self._compare_formal_param_values(entry_gr.get_first_writes_to_formal_params(), entry_uv.get_first_writes_to_formal_params())

        result += self._compare_global_variable_values(entry_gr.get_last_writes_to_global_var_locations(), entry_uv.get_last_writes_to_global_var_locations())

        if expanded_pipeline:
            result += self.compare_epilogues(entry_gr.epilogue, entry_uv.epilogue)

        result += self.compare_return_values(entry_gr, entry_uv)
        return result


    def _compare_prologues(self, entry_gr_prologue: List[Dict[str, Any]], entry_uv_prologue: List[Dict[str, Any]]) -> str:
        """
        Compare the function prologues from the golden reference and the unit under verification.

        This method checks whether:
            - Both prologue traces are empty (which is treated as a failure).
            - The traces are the same length.
            - The values of key fields (e.g., 'pc', 'a0', 'a1', 'fa0', 'fa1') match at each step.

        Differences are reported with detailed mismatch information. If all checks pass, the
        result indicates success.

        Args:
            entry_gr_prologue: A list of snapshots (dictionaries) representing the prologue from the golden reference.
            entry_uv_prologue: A list of snapshots (dictionaries) representing the prologue from the unit under verification.

        Returns:
            A formatted string summarizing the comparison results. This includes either
            'OK' or 'FAIL' and relevant mismatch details if present.

        TODO:
            This feature was implemented for the proof of concept, but it's unclear whether comparing
            function prologues adds meaningful value for verification. Instruction sequences may differ
            across architectures, making direct comparison potentially unreliable or misleading.
        """
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


    def _compare_formal_param_values(self, entry_gr_formal_params: Dict[str, Dict[str, Any]],
                                     entry_uv_formal_params: Dict[str, Dict[str, Any]]) -> str:
        """
        Compare the formal parameter values between two entries and generate a formatted comparison report.

        Args:
            entry_gr_formal_params (Dict[str, Dict[str, Any]]):
                A dictionary mapping formal parameter names to their data for the first entry.
            entry_uv_formal_params (Dict[str, Dict[str, Any]]):
                A dictionary mapping formal parameter names to their data for the second entry.

        Returns:
            str: A multiline string report indicating whether the formal parameters match ('OK'),
                 have mismatches ('FAIL'), or are not applicable ('NA'). The report includes
                 detailed mismatch information if any differences are found.
        TODO:
            Initially, the goal was to verify formal parameter values immediately after the prologue,
            but the practical benefit of this check remains unclear. Although this feature is implemented,
            it is currently unused. Consider revisiting its purpose and utility. Additionally, ensure that
            entry normalization, similar to what is done for global variables, is applied here as needed
            to maintain consistency and accuracy.
        """
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


    def _compare_global_variable_values(self, entry_gr_global_var_values: Dict[str, Dict[str, Any]],
                                        entry_uv_global_variable_values: Dict[str, Dict[str, Any]]) -> str:
        """
        Compare global variable values between two entries and produce a detailed comparison report.

        Args:
            entry_gr_global_var_values (Dict[str, Dict[str, Any]]):
                A dictionary mapping global variable names to their associated data for the first entry (golden reference).
            entry_uv_global_variable_values (Dict[str, Dict[str, Any]]):
                A dictionary mapping global variable names to their associated data for the second entry (under verification).

        Returns:
            str: A formatted multiline string indicating the comparison result:
                 - 'OK' if all global variable values match.
                 - 'FAIL' if there are mismatches or discrepancies, with detailed information about which variables differ.
                 - 'NA' if no global variable data writes are present in either entry.

        Notes:
            - If the number of global variables differs between entries, the method attempts to
              normalize and match variable data before reporting mismatches.
            - Normalization is used to handle cases where the number or order of writes differs.
        """
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
            # Try to match values when different number of writes
            golden_ref_data = self.normalize_variable_data(entry_gr_global_var_values)
            isuv_data = self.normalize_variable_data(entry_uv_global_variable_values)
            for name, value in golden_ref_data.items():
                if name not in isuv_data:
                    result += f"      variable {name} was written to in golden reference trace, but no data write found in other trace.\n"
                if value != isuv_data[name]:
                    result += f"      data mismatch in variable {name}: golden_ref={value} != isuv={isuv_data[name]}\n"
        if not result:
            result += section + 'OK\n'
        return result

    @staticmethod
    def normalize_variable_data(var_entries: Dict[str, Dict[str, Any]]) -> Dict[str, bytes]:
        """
        Normalize fragmented variable data entries into contiguous byte sequences.

        This method takes a dictionary of variable data fragments — each keyed by a
        unique name and index (e.g., "var:0", "var:1") — and assembles them into a
        single contiguous bytes object per variable name.

        Each entry contains:
            - 'location': A hexadecimal address indicating the write location.
            - 'data': A hex string representing the written data.

        Since the number and size of writes may vary across architectures, this method
        assumes that the overall content for a given variable should be identical once
        reassembled.

        Args:
            var_entries: A dictionary where keys are in the form "name:index", and values
                         contain 'location' and 'data' fields.

        Returns:
            A dictionary mapping variable names to their fully reconstructed bytes content,
            sorted by address.
        """
        normalized = defaultdict(list)
        result: Dict[str, bytes] = {}

        for key, value in var_entries.items():
            name, idx = key.split(':')
            address = int(value['location'], 16)
            data = bytes.fromhex(value['data'].zfill(len(value['data']) + len(value['data']) % 2))
            normalized[name].append((address, data))

        for name in normalized:
            normalized[name].sort(key=lambda x: x[0])
            result[name] = b''.join(chunk for _, chunk in normalized[name])

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


    def compare_return_values(self, entry_gr: SimulationDataEntry, custom_ise: SimulationDataEntry) -> str:
        """
        Compare the return values of two simulation data entries and generate a formatted report.

        Args:
            entry_gr (SimulationDataEntry): The golden reference simulation data entry.
            custom_ise (SimulationDataEntry): The other simulation data entry to compare against the golden reference.

        Returns:
            str: A multiline string report indicating the result of the return value comparison:
                 - 'OK' if return values match.
                 - 'FAIL' if there is a mismatch or missing debug information.
                 - 'NA' if the function is void or return values are inconclusive.

        Behavior:
            - Logs an error and fails if DWARF debug information is missing in either entry.
            - Detects void functions and marks the return value comparison as not applicable.
            - Fetches and compares the return values based on the function's return type.
            - Provides detailed mismatch information when return values differ.
            - Returns 'NA' if return values cannot be determined.
        """
        section: str = "  | Return value"
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


    def fetch_return_value(self, entry, sp_return_type: AbstractType) -> Any:
        """
        Extract the return value from a simulation data entry based on the function's return type and target machine architecture.

        Args:
            entry (SimulationDataEntry): The simulation data entry containing the function execution details and DWARF debug information.
            sp_return_type (AbstractType): The DWARF type information representing the function's return type.

        Returns:
            Any: The extracted return value, whose type depends on the function's return type and the target architecture.

        Raises:
            VerificationProcessException: If the DWARF base type is not supported for conversion.

        Behavior:
            - Determines the target machine architecture from the entry's compilation unit.
            - Logs debug information about the return type and architecture.
            - Uses the architecture-specific methods to fetch the return value depending on the DWARF return type:
              - Handles base types such as int, long long, float, double, and long double.
              - Supports structured types including structs and unions.
            - Debug-logs the extracted return value before returning.
        """
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


