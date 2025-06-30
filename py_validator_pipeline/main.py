"""
    The purpose of the main file is to handle the pipeline execution.
    All other code should be placed in other modules.
"""

import os
import time
import logging

from src.entity.dwarf.march_manager import MArchManager
from src.dwarf_info_extractor import DwarfInfoExtractor
from src.etiss_simulation import run_etiss_simulation
from src.dwarf_simdata_merger import (
    build_simulation_entries,
    log_snapshot_information
)

from src.entity.dwarf.dwarf_info import DwarfInfo
from src.entity.simulation.simulation_data_collection import SimulationDataCollection


from src.util.logger import init_logger
from src.util.arg_parser import parse_args
from src.util.logo import (
    print_logo,
    print_end,
    print_centered_line,
    print_section_title)

from src.exception.pipeline_exceptions import (
    DWARFExtractionException,
    ActivityLogParserException,
    ETISSSimulationException,
    SnapshotLoggerException,
    VerificationProcessException)
from src.verification_stage import VerificationStage

# Global logger
logger = logging.getLogger(__name__)
# parse arguments
args = parse_args()

# TODO: This could be a local singleton as well
march_manager = MArchManager()

INDENT = '    '

def run_pipeline():
    """
        Runs the execution pipeline
    """

    try:
        case_gr = "golden_reference"
        case_isuv = "instruction set under verification"

        logger.info(print_section_title("=== EXTRACTING DWARF DEBUG INFORMATION ==="))
        dwarf_time = time.perf_counter()
        golden_ref_dwarf_info = extract_dwarf_information(args.bin_golden_ref, case_gr)
        isuv_dwarf_info = extract_dwarf_information(args.bin_isuv, case_isuv)

        case_gr += f" ({golden_ref_dwarf_info.compilation_unit.march})"
        case_isuv += f" ({isuv_dwarf_info.compilation_unit.march})"

        logger.debug(f"DWARF debug information for the {case_gr}\n{str(golden_ref_dwarf_info)}")
        logger.debug(f"DWARF debug information for the {case_isuv}\n{str(isuv_dwarf_info)}")

        logger.info(f"DWARF debug data extracted. Total time: {time.perf_counter() - dwarf_time:.4f} seconds.")

        logger.info(print_section_title("=== RUNNING ETISS SIMULATION AND EXTRACTING ACTIVITY LOG ENTRIES ==="))
        etiss_time = time.perf_counter()
        golden_ref_entries = run_etiss_simulation_and_collect_activity_log(golden_ref_dwarf_info, args.ini_golden_ref, case_gr)
        # print("####                PAUSING FOR FAULT INJECTION - PRESS ENTER TO CONTINUE          ####")
        # input('')
        isuv_entries = run_etiss_simulation_and_collect_activity_log(isuv_dwarf_info, args.ini_isuv, case_isuv)

        logger.info(f"ETISS simulations run and activity log entries extracted. Total time: {time.perf_counter() - etiss_time:.4f} seconds.")

        logger.info(print_section_title("=== LOGGING EXTRACTED SNAPSHOT ENTRIES ==="))
        logging_time = time.perf_counter()
        log_snapshot_entries(golden_ref_entries, case_gr)

        log_snapshot_entries(isuv_entries, case_isuv)
        logger.info(f"Snapshots logged. Total time: {time.perf_counter() - logging_time:.4f} seconds.")

        logger.info(print_section_title("=== VERIFYING EXTRACTED SNAPSHOT ENTRIES ==="))
        verification_time = time.perf_counter()
        verify_entries(golden_ref_entries, isuv_entries)
        logger.info(f"Verification finished. Total time: {time.perf_counter() - verification_time:.4f} seconds.")

    except Exception as e:
        logger.error(f"Exception occurred: {e}")
        raise Exception(e)

def extract_dwarf_information(bin_file: str, case: str) -> DwarfInfo:
    try:
        # Extract DWARF-information from given binary
        binary_information = f"{INDENT}| binary: {bin_file}\n{INDENT}| source: {args.src}\n{INDENT}| fuction: {args.fun}"
        logger.info(f"Extracting DWARF debug information for case {case} from binary:\n{binary_information}")
        dwarf_info_extractor = DwarfInfoExtractor(source_file=args.src, function_of_interest=args.fun)
        dwarf_info = dwarf_info_extractor.extract_dwarf_info(binary=bin_file)
        if not march_manager.march_is_supported(dwarf_info.compilation_unit.march):
            logger.error(f"Machine architecture is not supported. Aborting. Machine architecture: {dwarf_info.compilation_unit.march}")
            raise Exception("Unsupported machine architecture! Aborting.")
        logger.debug(f"Machine architecture verified. This verification pipeline supports {dwarf_info.compilation_unit.march}.")
        return dwarf_info

    except Exception as e:
        logger.error(f"An exception occured while extracting DWARF debug information:{e}")
        raise DWARFExtractionException(e)



def run_etiss_simulation_and_collect_activity_log(dwarf_info: DwarfInfo, ini_file: str, case: str) -> SimulationDataCollection:
    try:
        # ETISS SIMULATION
        logger.info(f"Running ETISS simulation as subprocess for {case}")
        # Get the low and high PCs for the subprogram of interest
        lowpc = dwarf_info.get_subprogram_of_interest().low_pc
        highpc = dwarf_info.get_subprogram_of_interest().high_pc

        # TODO: find a more sensible approach for this
        # Currently low and high pc are stored in a file
        with open("pcs.tmp", "w", encoding="utf-8") as f:
            f.write(f"{lowpc};{highpc}")

        etiss_path = args.etiss_path
        bare_metal_etiss = args.etiss_executable

        # Run ETISS with Golden Reference binary to produce activity log
        run_etiss_simulation(etiss_path, bare_metal_etiss, ini_file, args.debug)

        # Remove the temporary file with low and high PC, if it exists
        if os.path.exists("pcs.tmp"):
            os.remove("pcs.tmp")
    except Exception as e:
        logger.error(f"An exception occured during ETISS simulation: {e}")
        raise ETISSSimulationException(e)

    try:
        # ACTIVITY LOG EXTRACTION
        logger.info("Extracting entries from Activity log")
        entries = build_simulation_entries(dwarf_info)
    except Exception as e:
        logger.error(f"An exception occured while parsing infromation from ActivityLog: {e}")
        raise ActivityLogParserException(e)

    return entries

def log_snapshot_entries(entries: SimulationDataCollection, case: str) -> None:
    try:
        # LOG SNAPSHOT INFORMATION
        logger.info(f"Writing snapshot information to log for {case}")
        log_snapshot_information(entries, args.fun)
    except Exception as e:
        logger.error(f"An exception occured while logging snapshot for {case} results: {e}")
        raise SnapshotLoggerException(e)

def verify_entries(golden_ref, custom_is):
    try:
        functions_verified = 0
        verifier =  VerificationStage()
        golden_ref_entry_collection = golden_ref.get_entries()
        custom_is_entry_collection = custom_is.get_entries()

        output = ""

        if len(golden_ref_entry_collection) == len(custom_is_entry_collection):
            for idx_0, golden_ref_fun_call_entries in enumerate(golden_ref_entry_collection):
                if len(custom_is_entry_collection[idx_0]) == len(golden_ref_fun_call_entries):
                    output += f"Subprogram of interest: {args.fun}, invoke #{idx_0 + 1}\n"
                    for idx_1, golden_ref_entry in enumerate(golden_ref_fun_call_entries):
                        output += f"> Function: {golden_ref_entry.function_name}\n"
                        # output += golden_ref_entry.compare_entries(custom_is_entry_collection[idx_0][idx_1], debug=args.debug)
                        output += verifier.compare_entries(golden_ref_entry, custom_is_entry_collection[idx_0][idx_1])
                        functions_verified += 1
                else:
                    err = "Number of function call entries in golden reference and custom IS data do not match. Aborting"
                    output += err
                    raise VerificationProcessException(err)

        else:
            err = "Number of function call entries in golden reference and custom IS data do not match. Aborting"
            output += err
            raise VerificationProcessException(err)

        logger.info(f"Verification results:\n{output}")
        logger.info(f"Total number of functions verified: {functions_verified}")
    except VerificationProcessException as e:
        logger.error(f"An exception occured while verifying entries: {e}")
        raise Exception(e)


def main():
    time_begin = time.perf_counter()
    init_logger(debug=args.debug)
    try:
        # Run pipeline with golden reference
        description = print_centered_line("the instruction set extension verification pipeline for ETISS simulation.")
        description += print_centered_line("Please see README.md for more information.")
        logger.info(f"Welcome to the\n{print_logo()}\n{description}")

        run_pipeline()

        total_time = time.perf_counter() - time_begin
        logger.info(f"Process finished successfully in {total_time:.4f} seconds.")

        logger.info(f"Finished.\n{print_logo()}\n{print_end()}")


    except Exception as ex:
        logger.error("An unexpected error occurred: {}".format(ex))
        logger.info("=== PROCESS TERMINATED ===")

        total_time = time.perf_counter() - time_begin
        logger.info(f"Process terminated after {total_time:.4f} seconds.")

        logger.info(f"Aborted due to exception. See logs for more information.\n{print_logo()}\n{print_end()}")





if __name__ == "__main__":
    main()
