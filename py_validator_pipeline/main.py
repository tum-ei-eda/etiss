"""
    The purpose of this main file is to handle the exeuction of the pipeline
"""

import os
import subprocess
import json
from argparse import Namespace
from pathlib import Path
import sys
import logging
from typing import Tuple
import argparse

from src.extract_subprogram_vars_and_params import process_file

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
    dwarf_info = process_file(binary=args.bin, source_file=args.src, function=args.fun)


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


    lowpc, highpc = dwarf_info['DW_AT_low_pc'], dwarf_info['DW_AT_high_pc']

    snapshot_matches = ""
    for snapshot in snapshots:
        if lowpc <= snapshot['pc'] < highpc:
            snapshot_matches += f"{indent} | <{snapshot['pc']}>: a0: {snapshot['x'][10]}, a1: {snapshot['x'][11]}, fa0: {snapshot['f'][10]}, fa1: {snapshot['f'][11]}\n"
    if snapshot_matches:
        logger.info(f"Snapshots within the subprogram PC range:\n{snapshot_matches}")
    else:
        logger.info("No matches found from snapshot information within function PC range")


def main():
    init_logger()
    run_pipeline()



if __name__ == "__main__":
    main()