

import logging
import subprocess

logger = logging.getLogger(__name__)

def run_etiss_simulation(etiss_path, bare_metal_etiss, ini_file):
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