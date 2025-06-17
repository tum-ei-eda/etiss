"""
    A service module to parse and extract snapshot data
"""

import os
import json
import logging
from typing import List

from src.entity.dwarf.dwarf_info import DwarfInfo
from src.entity.simulation.simulation_data_collection import SimulationDataCollection
from src.entity.simulation.simulation_data_entry import SimulationDataEntry

logger = logging.getLogger(__name__)
INDENT = '    '

def build_simulation_entries(dwarf_info: DwarfInfo):
    """
    Builds a collection of verifiable simulation data entries by parsing
    the ETISS activity log and integrating DWARF debugging information
    from the simulated binary.

    Each entry corresponds to a function-level execution segment, beginning
    at the function prologue and ending at the epilogue. This method
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
            entry_collection = compile_entries(f, dwarf_info)
            if not entry_collection:  # Reached EOF
                break
            data_collection.add_entry(entry_collection)

    return data_collection


def compile_entries(f, dwarf_info: DwarfInfo) -> List[SimulationDataEntry]:
    """
    Initializes and returns a list of SimulationDataEntry objects populated by
    invoked recursive entry-construction function. Applies Python's passing
    of lists as references simplifying data collecting during recursion.

    Args:
        f (file object): Open file handle for the ETISS activity log.
        dwarf_info (DwarfInfo): Extracted DWARF debugging information.

    Returns:
        List[SimulationDataEntry]: The list of constructed simulation entries.
    """
    entries: List[SimulationDataEntry] = []
    construct_entries_recursively(f, dwarf_info, entries)
    return entries



def construct_entries_recursively(f, dwarf_info: DwarfInfo, entries: List[SimulationDataEntry], entry: SimulationDataEntry= None) -> None:
    """
    Recursively constructs SimulationDataEntry objects from the ETISS activity log,
    segmenting execution data by function boundaries and enriching entries with
    extracted DWARF debug information.

    This function reads from the activity log line-by-line, identifies relevant
    instructions (e.g., prologue, epilogue, memory writes), and groups them into
    entries that correspond to individual function executions. Recursion is used
    to handle nested or sequential function calls that are detected mid-trace.

    Args:
        f (file object): Open file handle for the ETISS activity log.
        dwarf_info (DwarfInfo): Extracted DWARF debugging information used to identify
                                subprograms and enrich entries.
        entries (List[SimulationDataEntry]): A shared list reference that accumulates
                                             all constructed entries.
        entry (SimulationDataEntry, optional): The current entry being constructed.
                                               A new one is created if not provided.

    TODO:
        The PC range check could be made more robuts for c.jr instruction. Consider
        raising an error if condition check fails.
    """

    if not entry:
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
                            """
                            Handles detection of function prologues using 'cswsp' or 'sw' instructions.

                            If the instruction's PC falls within the range of the current entry’s 
                            function, it is appended to the existing prologue.

                            If the PC maps to a different subprogram, for which DWARF debug information
                            has been extracted, a new SimulationDataEntry is created and recursively 
                            constructed from that point onward.
                            """
                            sp = dwarf_info.get_enclosing_subprogram(obj['pc'])
                            if sp and (not entry.function_name or sp and entry.function_name == sp.name):
                                if not entry.function_name:
                                    entry.function_name = sp.name
                                entry.append_prologue_instruction(
                                    obj['instruction'],
                                    obj['pc'],
                                    obj['x'][8],
                                    obj['x'][10:18],
                                    obj['f'][10:18]
                                )
                            elif sp:
                                new_entry = SimulationDataEntry()
                                new_entry.add_dwarf_info(dwarf_info)
                                new_entry.function_name = sp.name
                                new_entry.append_prologue_instruction(
                                    obj['instruction'],
                                    obj['pc'],
                                    obj['x'][8],
                                    obj['x'][10:18],
                                    obj['f'][10:18]
                                )
                                construct_entries_recursively(f, dwarf_info, entries, new_entry)
                        case 'cjr':
                            if dwarf_info.get_enclosing_subprogram(obj['pc']):
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
    if epilogue_reached:
        global_vars = dwarf_info.get_global_variables()
        # for glob_var in global_vars:
            # entry.add_global_variable_and_location(glob_var.get_name(), glob_var.get_location_value())

        entry.add_global_variables(global_vars)
        formal_params = dwarf_info.get_subprogram_by_name(entry.function_name).get_formal_parameters()
        for param in formal_params:
            entry.add_formal_param_locations(param.get_name(), param.get_location_value())

        entries.append(entry)

def log_snapshot_information(entries: SimulationDataCollection, fun_of_interest: str):
    """
    Logs snapshot information for each invocation of the specified function of interest.

    Iterates over a collection of simulation data entries, formats relevant details
    (including function name and contents), and logs the output using the debug level.

    Args:
        entries (SimulationDataCollection): Collection of parsed simulation entries.
        fun_of_interest (str): Name of the function being analyzed in the trace.
    """
    output = ""
    times_invoked = 0
    for sim_data_entry in entries.get_entries():
        times_invoked += 1
        output += f"Function of interest: {fun_of_interest}, invoke #{times_invoked}:\n"
        for idx, entry in enumerate(sim_data_entry):
            output += f"> Subprogram name: {entry.function_name}\n"
            output += str(entry)
        if output:
            logger.debug(f"Following snapshot information extracted:\n\n{output}")
        else:
            logger.warning("No snapshot information extracted")


