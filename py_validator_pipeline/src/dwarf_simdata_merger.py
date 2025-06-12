"""
    A service module to parse and extract snapshot data
"""

import os
import json
import logging

from src.entity.dwarf.dwarf_info import DwarfInfo
from src.entity.simulation.simulation_data_collection import SimulationDataCollection
from src.entity.simulation.simulation_data_entry import SimulationDataEntry

logger = logging.getLogger(__name__)
INDENT = '    '

def build_simulation_entries(dwarf_info: DwarfInfo):
    """
    Builds a collection of verifiable simulation data entries by parsing
    the ISS activity log and integrating DWARF debugging information.

    Each entry corresponds to a function-level execution segment, beginning
    at the function prologue and ending at the epilogue. This function
    sequentially processes the log file and uses a helper method to
    construct individual SimulationDataEntry objects by fusing relevant
    simulation and DWARF data.

    Args:
        dwarf_info (DwarfInfo): Parsed DWARF debugging information used
        to enrich simulation entries with symbolic context.

    Returns:
        SimulationDataCollection: A collection of SimulationDataEntry
        objects containing combined simulation and DWARF data.
    """

    logger.debug("Extracting snapshots from activity log")

    current_path = os.getcwd()
    with open(f"{current_path}/snapshot-activity.log", "r") as f:
        data_collection = SimulationDataCollection()

        while True:
            entry = construct_entry(f, dwarf_info)
            if entry is None:  # Reached EOF
                break
            data_collection.add_entry(entry)

    return data_collection


def construct_entry(f, dwarf_info):
    entry = SimulationDataEntry()
    entry.add_dwarf_info(dwarf_info)

    epilogue_reached = False

    for line in f:
        try:
            obj = json.loads(line.strip())

            match obj['type']:
                case 'state_snapshot':
                    match obj['instruction']:
                        case 'cswsp' | 'sw':
                            entry.append_prologue_instruction(
                                obj['instruction'],
                                obj['pc'],
                                obj['x'][8],
                                obj['x'][10:18],
                                obj['f'][10:18]
                            )
                        case 'cjr':
                            entry.append_epilogue_instruction(
                                obj['instruction'],
                                obj['pc'],
                                obj['x'][8],
                                obj['x'][10:12],
                                obj['f'][10:12]
                            )

                            epilogue_reached = True
                case 'dwrite':
                    entry.append_dwrite_instruction(
                        obj['pc'],
                        obj['location'],
                        obj['data'],
                        obj['byte_size']
                    )
            if epilogue_reached:
                break
        except json.JSONDecodeError as e:
            raise Exception(f"Error parsing JSON: {e}")

    # If no data was added, we likely reached EOF
    if not epilogue_reached:
        return None

    global_vars = dwarf_info.get_global_variables()
    # for glob_var in global_vars:
        # entry.add_global_variable_and_location(glob_var.get_name(), glob_var.get_location_value())

    entry.add_global_variables(global_vars)
    formal_params = dwarf_info.get_subprogram_of_interest().get_formal_parameters()
    for param in formal_params:
        entry.add_formal_param_locations(param.get_name(), param.get_location_value())

    return entry

def log_snapshot_information(entries: SimulationDataCollection, fun_name: str):
    output = ""
    fun_call = 0
    for idx, entry in enumerate(entries.get_entries()):
        output += f"Function: {fun_name}, call #{fun_call}\n"
        fun_call += 1
        output += str(entry)
    if output:
        logger.debug(f"Following snapshot information extracted:\n\n{output}")
    else:
        logger.warning("No snapshot information extracted")


