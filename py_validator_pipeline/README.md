# ETISS-GTS PIPELINE

ETISS-GTS is a proof-of-concept verification infrastructure for traced based comparison of an Instruction Set under development to a trusted golden reference. The pipeline executes ETISS simulations on two binaries compiled for the golden reference instruction set and the instruction set under development, and compares the execution traces from data writes to global variables and of function return values. 

## Installation 

### Installing ETISS

As the verification pipeline executes two ETISS simulations, it requires a working ETISS installation. To install ETISS, please follow the instructions in the README.md in the root-directory of the ETISS project.

### Installing the verification pipeline
The recommended approach is to first create a virtual environment with 
```bash
python3 -m venv venv
```
Activate the virtual environment:

```bash
source /venv/bin/activate
```

Install dependencies:
```bash
pip install -r requirements.txt
```

## Getting started

The pipeline extracts DWARF debug information from both binaries. The proof-of-concept implementation supports binaries that have been compiled without optimizations with `gcc`.

This bash script template provides a useful starting point for running the verification pipeline. The script assumes that
- the binary is compiled with the same name as the source code file of interest. For instance, in case the source code file of interest is `foo.c`, the binary is named `foo`
- both binaries have identical names (i.e., in the given example both binaries are named `foo`)
- the `.ini` files have the same name as the binary (i.e., in this example the ini file would be `foo.ini` for both binaries)
- the function of interest can be found in the give source code file (i.e., in the example file `foo.c` has function `bar`)

```bash 
#!/bin/bash
VERBOSE_ARG="--verbose"
PROGRAM_NAME="foo"
FUNCTION_OF_INTEREST="bar"
SOURCE_FILE="foo.c"

# Check if first argument is --debug
if [[ "$1" == "--verbose" ]]; then
    VERBOSE_ARG="--verbose"
fi

python3 /home/holaphei/repos/etiss-fork/etiss/py_validator_pipeline/main.py \
    --bin_isuv /home/holaphei/repos/xmnn-isax-flow/etiss_riscv_examples/build/install/bin/$PROGRAM_NAME \
    --ini_isuv /home/holaphei/repos/xmnn-isax-flow/etiss_riscv_examples/build/install/ini/$PROGRAM_NAME.ini \
    --bin_golden_ref /home/holaphei/repos/etiss_riscv_examples/build/install/golden_ref/bin/$PROGRAM_NAME \
    --ini_golden_ref /home/holaphei/repos/etiss_riscv_examples/build/install/golden_ref/ini/$PROGRAM_NAME.ini \
    --src $SOURCE_FILE \
    --fun $FUNCTION_OF_INTEREST \
    --etiss_path /home/holaphei/repos/etiss-fork/etiss/build/bin \
    --etiss_executable bare_etiss_processor \
    $VERBOSE_ARG
```

Explanations:
- `bin_golden_ref`: the golden reference binary to simulate on ETISS.
- `ini_golden_ref`: the .ini - file for ETISS simulation for the golden reference
- `bin_isuv`: the binary under verification to simulate on ETISS
- `ini_isuv`: the .ini - file for ETISS simulation for the binary under verification
- `src`: Source code file from the binary in which the function of interest resides
- `fun`: function of interest
- `etiss_path`: absolute path to etiss executable
- `etiss_executable`: name of the etiss executable binary

Bash-script variables:
- `VERBOSE_ARG`: as a convenience pipeline can be run in verbose mode by adding the argument `--verbose`. In verbose  mode more detailed output is printed to console and to log file.
- `PROGRAM_NAME`: to use this script, the binary name and the ini-file name (excluding extension .ini) must be identical. In the case of the script example, both binary files are named `foo` and both `.ini` files are named `foo.ini`
- `SOURCE_FILE`: defines which source file in the compiled binary is of interest. 
- `FUNCTION_OF_INTEREST`: defines the function to be verified. 

Example usage: 
```bash
./<script-name>
```

Example usage with verbose mode activated:
```bash 
./<script-name> --verbose
```

### Considerations

A typical use-case could be to run the ETISS simulation with two different architectures. There are several approaches of how this can be achieved
- A pause can be inserted into the pipeline before a new architecture is loaded into ETISS
- The script and pipeline can be extended to run ETISS-simulations on different builds of ETISS
- Additionally it can be investigated, if bare-metal ETISS supports specifying the architecture. In this case the two architectures could be given as arguments and passing the arguments to ETISS-simulation could be implemented to the pipeline.

During the proof-of-concept work I personally extended the pipeline to use two different builds of ETISS as this was the quickest (if not the most practical) way forward. 

