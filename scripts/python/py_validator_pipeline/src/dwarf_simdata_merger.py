"""
    A service module to parse and extract snapshot data
"""

import os
import logging
from logging import DEBUG
from typing import List, Dict, Any

from src.entity.dwarf.dwarf_info import DwarfInfo
from src.entity.simulation.simulation_data_collection import SimulationDataCollection
from src.entity.simulation.simulation_data_entry import SimulationDataEntry
from src.util.trace_parser import parse_trace_file
from src.util.peekable_iter import Peekable

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

    realpath = f"{os.getcwd()}/trace.bin"
    data = parse_trace_file(realpath)
    data_iter = Peekable(data)

    data_collection = SimulationDataCollection()

    while True:
        entry_collection = compile_entries(data_iter, dwarf_info)
        if not entry_collection:  # Reached EOF
            break
        data_collection.add_entry(entry_collection)

    return data_collection


def compile_entries(data_iter, dwarf_info: DwarfInfo) -> List[SimulationDataEntry]:
    """
    Initializes and returns a list of SimulationDataEntry objects populated by
    invoked recursive entry-construction function. Applies Python's passing
    of lists as references simplifying data collecting during recursion.

    Args:
        data_iter (iterator): iterator for data entries
        dwarf_info (DwarfInfo): Extracted DWARF debugging information.

    Returns:
        List[SimulationDataEntry]: The list of constructed simulation entries.
    """
    entries: List[SimulationDataEntry] = []
    construct_entries_recursively(data_iter=data_iter, dwarf_info=dwarf_info, entries=entries)
    return entries



def construct_entries_recursively(data_iter: Peekable, dwarf_info: DwarfInfo, entries: List[SimulationDataEntry], entry: SimulationDataEntry= None) -> None:
    """
    Recursively constructs SimulationDataEntry objects from the ETISS activity log,
    segmenting execution data by function boundaries and enriching entries with
    extracted DWARF debug information.

    This function reads from the activity log line-by-line, identifies relevant
    instructions (e.g., prologue, epilogue, memory writes), and groups them into
    entries that correspond to individual function executions. Recursion is used
    to handle nested or sequential function calls that are detected mid-trace.

    Args:
        data_iter (iterator): iterator for data entries
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

    for e in data_iter:
        match e['type']:
            case 'state_snapshot':
                match e['instruction']:
                    case 'cswsp' | 'sw':
                        """
                        Handles detection of function prologues using 'cswsp' or 'sw' instructions.

                        If the instruction's PC falls within the range of the current entry’s 
                        function, it is appended to the existing prologue.

                        If the PC maps to a different subprogram, for which DWARF debug information
                        has been extracted, a new SimulationDataEntry is created and recursively 
                        constructed from that point onward.
                        """
                        sub_prog = dwarf_info.get_enclosing_subprogram(e['pc'])
                        if sub_prog and (not entry.function_name or sub_prog and entry.function_name == sub_prog.name):
                            if not entry.function_name:
                                entry.function_name = sub_prog.name
                                entry.invoke_chain.append(sub_prog.name)
                            entry.append_prologue_instruction(
                                inst=e['instruction'],
                                pc=e['pc'],
                                sp=e['x'][2],
                                fp=e['x'][8],
                                arg_regs=e['x'][10:18],
                                farg_regs=e['f'][10:18]
                            )
                        elif sub_prog:
                            new_entry = SimulationDataEntry()
                            new_entry.add_dwarf_info(dwarf_info)
                            new_entry.function_name = sub_prog.name
                            new_entry.invoke_chain = entry.invoke_chain + [sub_prog.name]
                            new_entry.append_prologue_instruction(
                                inst=e['instruction'],
                                pc=e['pc'],
                                sp=e['x'][2],
                                fp=e['x'][8],
                                arg_regs=e['x'][10:18],
                                farg_regs=e['f'][10:18]
                            )
                            construct_entries_recursively(data_iter=data_iter, dwarf_info=dwarf_info, entries=entries, entry=new_entry)

                    case 'cjr'  | 'jalr':
                        """
                            As the entry creation is recursive, each entry should end with one or several
                            cjr instructions for subprogram of the entry. In case we fail to parse an entry,
                            we may encounter trailing cjr instruction. In such case we just move forward
                            without appending anything. 
                        """
                        sp_for_cjr = dwarf_info.get_enclosing_subprogram(e['pc'])
                        if sp_for_cjr and sp_for_cjr.name == entry.function_name:

                            if dwarf_info.get_enclosing_subprogram(e['pc']):
                                entry.append_epilogue_instruction(
                                    inst=e['instruction'],
                                    pc=e['pc'],
                                    sp=e['x'][2],
                                    fp=e['x'][8],
                                    rv_regs=e['x'][10:12],
                                    frv_regs=e['f'][10:12]
                                )
                                epilogue_reached = True

                            next_e = data_iter.peek()

                            # Sometimes the trace contains multiple consecutive cjr-instructions with the same PC, but changing SP and data
                            # I assume this may be due to stack unwinding. By peeking for the next iterable
                            while next_entry_is_cjr_for_same_subprogram(e, next_e, dwarf_info):
                                next_e = data_iter.__next__()
                                if dwarf_info.get_enclosing_subprogram(next_e['pc']):
                                    entry.append_epilogue_instruction(
                                        inst=next_e['instruction'],
                                        pc=next_e['pc'],
                                        sp=next_e['x'][2],
                                        fp=next_e['x'][8],
                                        rv_regs=next_e['x'][10:12],
                                        frv_regs=next_e['f'][10:12]
                                    )
                                    next_e = data_iter.peek()


            case 'dwrite':
                entry.append_dwrite_instruction(
                    e['pc'],
                    e['location'],
                    e['data'],
                    e['byte_size']
                )
        if epilogue_reached:
            break

    # If no data was added, we likely reached EOF
    if epilogue_reached and is_valid_entry(entry):
        # logger.debug(f"EXTRACTING VARS AND PARAMS FOR FUNCTION: {entry.function_name}")
        global_vars = dwarf_info.get_global_variables()
        # for glob_var in global_vars:
            # entry.add_global_variable_and_location(glob_var.get_name(), glob_var.get_location_value())

        entry.add_global_variables(global_vars)
        if dwarf_info.get_subprogram_by_name(entry.function_name):
            formal_params = dwarf_info.get_subprogram_by_name(entry.function_name).get_formal_parameters()
            for param in formal_params:
                entry.add_formal_param_locations(param.get_name(), param.get_location_value())
        else:
            subprograms = ''
            for k, v in dwarf_info.subprograms.items():
                subprograms += f"{k}: {v}\n"
            logger.error(f"<with Phil Dunphy voice>: WHAAAAT?! fun name: {entry.function_name}\n {entry} \n Subprograms:\n {subprograms}")

        entries.append(entry)
    elif epilogue_reached:
        logger.warning(f"Encountered invalid entry. Skipping. Function name: {entry.function_name}. String representation:\n {entry}")

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
            output += f"> Subprogram name: {entry.function_name} ({entry.get_invoke_chain()})\n"
            output += str(entry)
        if output:
            logger.debug(f"Following snapshot information extracted:\n\n{output}")
        else:
            logger.warning("No snapshot information extracted")


def next_entry_is_cjr_for_same_subprogram(entry: Dict[str, Any], next_entry: Dict[str, Any], dwarf_info: DwarfInfo) -> bool:
    """
        A simple helper function to verify that two given entries are within the range
        of the same subprogram. Most of the complexity is to ensure that there is no
        function calls for None values.
    """
    entries_have_enclosing_subprograms = False
    entries_have_same_subprogram = False
    next_entry_is_cjr_inst = bool(next_entry) and bool(next_entry.get('instruction')) and next_entry['instruction'] == 'cjr'
    if next_entry_is_cjr_inst:
        entries_have_enclosing_subprograms = bool(
            dwarf_info.get_enclosing_subprogram(entry['pc']) and dwarf_info.get_enclosing_subprogram(next_entry['pc']))
    if entries_have_enclosing_subprograms:
        entries_have_same_subprogram = dwarf_info.get_enclosing_subprogram(entry['pc']).name == dwarf_info.get_enclosing_subprogram(
            next_entry['pc']).name
    return next_entry_is_cjr_inst and entries_have_enclosing_subprograms and entries_have_same_subprogram


def is_valid_entry(entry: SimulationDataEntry) -> bool:
    """
        A valid entry should contain state information for
            - function prologue and
            - function epilogue
        Additionally it should indicate for which
        subprogram the entries are
    """
    has_prologue = bool(len(entry.prologue) > 0)
    has_subprogram_name = bool(entry.function_name != '')
    has_epilogue = bool(len(entry.epilogue) > 0)
    return has_prologue and has_subprogram_name and has_epilogue
