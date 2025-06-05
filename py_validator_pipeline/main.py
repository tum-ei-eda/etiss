"""
    The purpose of the main file is to handle the pipeline execution.
    All other code should be placed in other modules.
"""

import os
import logging

from src.dwarf_info_extractor import DwarfInfoExtractor
from src.etiss_simulation import run_etiss_simulation
from src.snapshot_handler import (
    parse_and_extract_snapshots,
    log_snapshot_information
)
from src.snapshot_handler import log_snapshot_information

from src.util.logger import init_logger
from src.util.arg_parser import parse_args
from src.util.logo import print_logo

from src.exception.pipeline_exceptions import (
    DWARFExtractionException,
    ActivityLogParserException,
    ETISSSimulationException,
    SnapshotLoggerException,
    VerificationProcessException)

# Global logger
logger = logging.getLogger(__name__)
# parse arguments
args = parse_args()

INDENT = '    '

def run_pipeline(bin_file, ini_file):
    """
        Runs the execution pipeline
    """
    # Get the singleton instance of DWARF information entity

    binary_information = f"{INDENT}| binary: {bin_file}\n{INDENT}| source: {args.src}\n{INDENT}| fuction: {args.fun}"



    try:
        # DWARF EXTRACTION
        logger.info(f"Extracting DWARF debug information:\n{binary_information}")
        # Extract DWARF-information from given binary
        dwarf_info_extractor = DwarfInfoExtractor(binary=bin_file, source_file=args.src, function=args.fun, debug=args.debug)
        dwarf_info_extractor.extract_dwarf_info()



    except Exception as e:
        logger.error(f"An exception while extracting DWARF debug information:\n{e}")
        raise DWARFExtractionException(e)

    dwarf_info = dwarf_info_extractor.get_dwarf_info()
    logger.info(f"{str(dwarf_info)}")


    try:
        # ETISS SIMULATION
        # Get the low and high PCs for the subprogram of interest
        lowpc = dwarf_info.get_low_pc()
        highpc = dwarf_info.get_high_pc()

        # TODO: find a more sensible approach for this
        # Currently low and high pc are stored in a file
        with open("pcs.tmp", "w", encoding="utf-8") as f:
            f.write(f"{lowpc};{highpc}")

        etiss_path = args.etiss_path
        bare_metal_etiss = args.etiss_executable

        logger.info("Running ETISS simulation as subprocess")

        # Run ETISS with Golden Reference binary to produce activity log
        run_etiss_simulation(etiss_path, bare_metal_etiss, ini_file)

        # Remove the temporary file with low and high PC, if it exists
        if os.path.exists("pcs.tmp"):
            os.remove("pcs.tmp")
    except Exception as e:
        logger.error(f"An exception occured during ETISS simulation:\n{e}")
        raise ETISSSimulationException(e)

    try:
        # ACTIVITY LOG EXTRACTION
        logger.info("Extracting entries from Activity log")
        entries = parse_and_extract_snapshots(dwarf_info)
    except Exception as e:
        logger.error(f"An exception occured while parsing infromation from ActivityLog:\n{e}")
        raise ActivityLogParserException(e)

    try:
        # LOG SNAPSHOT INFORMATION
        logger.info(f"Writing snapshot information to log")
        log_snapshot_information(entries, args.fun)
    except Exception as e:
        logger.error(f"An exception occured while logging snapshot results:\n{e}")
        raise SnapshotLoggerException(e)

    return entries


def verify_entries(golden_ref, custom_is):
    try:
        golden_ref_entries = golden_ref.get_entries()
        custom_is_entries = custom_is.get_entries()

        output = ""

        if len(golden_ref_entries) == len(custom_is_entries):
            for idx, golden_ref_entry in enumerate(golden_ref_entries):
                output += f"> Function call {idx + 1}\n"
                output += golden_ref_entry.compare_entries(custom_is_entries[idx], debug=args.debug)

        else:
            output += "Number of function call entries in golden reference and custom is do not match. Aborting"

        logging.info(f"Verification results:\n{output}")
    except VerificationProcessException as e:
        logger.error(f"An exception occured while verifying entries:\n{e}")
        raise Exception(e)


def main():
    init_logger(debug=args.debug)
    logger.info(f"=== VERIFICATION PIPELINE START ===\n{print_logo()}")
    try:
        # Run pipeline with golden reference
        logger.info("=== GOLDEN REFERENCE BEGIN ===")
        golden_ref_entries = run_pipeline(args.bin_golden_ref, args.ini_golden_ref)
        logger.info("=== GOLDEN REFERENCE END ===")

        logger.info("=== BINARY UNDER VERIFICATION BEGIN ===")
        verifiable_entries = run_pipeline(args.bin_isuv, args.ini_isuv)
        logger.info("=== BINARY UNDER VERIFICATION END ===")

        logger.info("=== VERIFICATION BEGIN ===")
        verify_entries(golden_ref_entries, verifiable_entries)

        logger.info("=== VERIFICATION END ===")
    except Exception as ex:
        logger.error("An unexpected error occurred: {}".format(ex))
        logger.info("=== PROCESS TERMINATED ===")

    logger.info("=== END ===")



if __name__ == "__main__":
    main()
