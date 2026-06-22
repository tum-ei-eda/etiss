import logging
import subprocess

logger = logging.getLogger(__name__)

def run_etiss_simulation(etiss_path: str, bare_metal_etiss: str, ini_file: str, debug_enabled: bool, fault: bool = False):
    """
    Run a bare-metal ETISS simulation using a specified binary and configuration.

    This function constructs and executes a command-line call to an ETISS-based simulator,
    using the provided binary and `.ini` configuration file. It captures the subprocess
    output and optionally prints it if debugging is enabled.

    Args:
        etiss_path: Path to the ETISS build or installation directory.
        bare_metal_etiss: The name of the bare-metal simulator executable to run.
        ini_file: Path to the `.ini` configuration file used by the simulator.
        debug_enabled: If True, prints the full output of the simulation to stdout.

    Raises:
        Exception: If the subprocess fails to execute successfully, or if the binary
                   is not found. Provides basic diagnostics on failure.
    """


    if fault:
        etiss_path = f"{etiss_path}/{bare_metal_etiss}"
        cmd = [
            etiss_path,
            f"-i{ini_file}",
            "-p", "GTS",
            # An example of providing CPU arhcitecture as an argument
            # "--arch.cpu=RV32IMACFDXCoreVXMNN",
            "--jit.gcc.cleanup", "true"
        ]
    # Golden reference
    # TODO: remove this temporary implementation
    else:
        etiss_path = f"{etiss_path}/{bare_metal_etiss}"
        cmd = [
            etiss_path,
            f"-i{ini_file}",
            "-p", "GTS",
            "--jit.gcc.cleanup", "true"
        ]


    logger.debug(f"Running ETISS simulation. This may take a while. Logging ETISS output: {debug_enabled}")
    logger.info(f"ETISS path: {etiss_path}")
    try:
        result = subprocess.run(cmd, text=True, stderr=subprocess.STDOUT, stdout=subprocess.PIPE, check=True)
        if debug_enabled:
            logger.debug(f"ETISS console output:\n{result.stdout}")
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