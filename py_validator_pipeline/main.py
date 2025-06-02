"""
    The purpose of this main file is to handle the exeuction of the pipeline
"""

import os
import subprocess
import re
import json
from argparse import Namespace
from pathlib import Path
import sys
import logging
from typing import Tuple
import argparse

from src.extract_subprogram_vars_and_params import process_file
from src.entity.dwarf_info import DwarfInfo

# Global logger
logger = logging.getLogger(__name__)

# Argument parser guides user in providing the required arguments
parser = argparse.ArgumentParser()
parser.add_argument("-b", "--bin", help="absolute path of the binary file", required=True)
parser.add_argument("-i", "--ini", help="absolute path of the ini file", required=True)
parser.add_argument("-s", "--src", help="name of source code file, e.g. hello.c", required=True)
parser.add_argument("-f", "--fun", help="name of the function, e.g. foo", required=True)
parser.add_argument("-e", "--etiss_path", help="absolute path of bare metal ETISS", required=True)
parser.add_argument("-x", "--etiss_executable", help="name of bare metal ETISS", required=True)

args = parser.parse_args()

def init_logger() -> None:
    # Clear existing handlers (if running multiple times, like in Jupyter or REPL)
    root_logger = logging.getLogger()  # root logger

    # Set logging level for all loggers
    root_logger.setLevel(logging.INFO)
    root_logger.handlers.clear()

    # File handler
    file_handler = logging.FileHandler('pyelftools_test.log')
    file_handler.setLevel(logging.DEBUG)

    # Console handler
    console_handler = logging.StreamHandler()
    console_handler.setLevel(logging.INFO)

    # Formatter
    formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
    file_handler.setFormatter(formatter)
    console_handler.setFormatter(formatter)

    # Add handlers to the logger
    root_logger.addHandler(file_handler)
    root_logger.addHandler(console_handler)


def run_pipeline():
    """
        Runs the execution pipeline
    """

    indent = '     '

    # Extract DWARF-information from given binary
    logger.info("Starting pipeline execution")
    logger.info("Extracting DWARF debug information:")
    process_file(binary=args.bin, source_file=args.src, function=args.fun)

    # Get the singleton instance of DWARF information entity
    dwarf_info = DwarfInfo()

    # The low and high PCs for the subprogram of interest are stored in the
    # dwarf_info dictionary
    lowpc = dwarf_info.get_low_pc()
    highpc = dwarf_info.get_high_pc()

    with open("pcs.tmp", "w", encoding="utf-8") as f:
        f.write(f"{lowpc};{highpc}")

    # Run ETISS to produce activity log
    etiss_path = args.etiss_path
    bare_metal_etiss = args.etiss_executable
    ini_file = args.ini
    cmd = [
        f"{etiss_path}/{bare_metal_etiss}",
        f"-i{ini_file}",
        "-p", "InstructionTracer",
        "--jit.gcc.cleanup", "true"
    ]

    logger.info("Running ETISS simulation. This may take a while")
    try:
        result = subprocess.run(cmd, text=True, check=True)
    except subprocess.CalledProcessError as e:
        print("Command failed with non-zero exit code.")
        print("Return code:", e.returncode)
        print("STDOUT:\n", e.stdout)
        print("STDERR:\n", e.stderr)
        raise Exception("Command failed with non-zero exit code.")
    except FileNotFoundError:
        print("Executable not found. Please check the path.")
        raise Exception("Command failed with non-zero exit code.")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")
        raise Exception("Command failed with non-zero exit code.")

    # Remove the temporary file with low and high PC, if it exists
    if os.path.exists("pcs.tmp"):
        os.remove("pcs.tmp")



    # extract snapshots from the activity log
    logger.info("Extracting snapshots from activity log")
    snapshots = []
    current_path = os.getcwd()
    with open(f"{current_path}/snapshot-activity.log", "r") as f:
        for line_number, line in enumerate(f, start=1):
            line = line.strip()
            if not line:
                continue  # skip empty lines
            try:
                obj = json.loads(line)
                snapshots.append(obj)
            except json.JSONDecodeError as e:
                print(f"Error parsing JSON on line {line_number}: {e}")



    state_snapshots = ""
    idx_counter = 0
    dwrites = {}
    idx_ranges = []
    for snapshot in snapshots:
        match snapshot['type']:
            case 'state_snapshot':
                if lowpc <= snapshot['pc'] < highpc:
                    idx_ranges.append(idx_counter)
                    state_snapshots += f"{indent} | idx:{idx_counter} {snapshot['instruction']}@<{snapshot['pc']}>: a0: {snapshot['x'][10]}, a1: {snapshot['x'][11]}, fa0: {snapshot['f'][10]}, fa1: {snapshot['f'][11]}\n"
            case 'dwrite':
                if snapshot['location'] not in dwrites:
                    dwrites[snapshot['location']] = []
                entry = (idx_counter, snapshot['data'])
                dwrites[snapshot['location']].append(entry)
                pass
            case _:
                pass
        idx_counter += 1


    # output state snapshots from within given subprogram range if they exist
    if state_snapshots:
        logger.info(f"Snapshots within the subprogram PC range:\n{state_snapshots}")
    else:
        logger.warning("No matches found from snapshot information within function PC range")

    logger.info(f"Global variable locations: {dwarf_info.get_global_var_locations()}")
    logger.info(f"Formal parameter locations: {dwarf_info.get_formal_param_locations()}")

    # log data writes to global variables from dict dwrites
    if dwrites:
        global_var_locations = dwarf_info.get_global_var_locations()
        global_var_entry = ""
        if global_var_locations:
            for glob_name in global_var_locations:
                for loc in global_var_locations[glob_name]:
                    parsed_loc = re.search(r'DW_OP_addr:\s*([0-9a-fA-F]+)', loc).group(1)
                    if parsed_loc in dwrites:
                        matching_entries = []
                        for entry in dwrites[parsed_loc]:
                            if is_within_idx_range(idx_ranges, entry[0]):
                                matching_entries.append(entry)
                        global_var_entry += f"{indent} | {glob_name}: {matching_entries}\n"
        if global_var_entry:
            logger.info(f"Data writes to global variable addresses within index range:\n{global_var_entry}")
        else:
            mem_writes_to_global_vars = ""
            for glob_name in global_var_locations:
                for loc in global_var_locations[glob_name]:
                    parsed_loc = re.search(r'DW_OP_addr:\s*([0-9a-fA-F]+)', loc).group(1)
                    if parsed_loc in dwrites:
                        for entry in dwrites[parsed_loc]:
                            matching_entries.append(entry)
                        mem_writes_to_global_vars += f"{indent} | {glob_name}: {matching_entries}\n"
            logger.info(f"No data writes to global variable addresses within index ranges:{idx_ranges}\n{indent}| Memory writes to global variables: {mem_writes_to_global_vars}")
    else:
        logger.warning("No data writes found")


def is_within_idx_range(idx_ranges, idx):
    for i in range(0, len(idx_ranges), 2):
        start = idx_ranges[i]
        end = idx_ranges[i + 1]
        if start <= idx <= end:
            return True
    return False


def main():
    init_logger()
    run_pipeline()



if __name__ == "__main__":
    main()