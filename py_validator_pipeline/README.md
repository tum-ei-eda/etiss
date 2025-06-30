# ETISS-GTS PIPELINE

: add introduction and links to relevant documentation. Is there a need to add a lisence here?   

## Installation 

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

This bash script template provides a useful starting point for running the verification pipeline:

```bash 
#!/bin/bash
DEBUG_ARG=""
PROGRAM_NAME="prog.o"
SOURCE_FILE="main.c"
FUNCTION_OF_INTEREST="main"

# Check if first argument is --debug
if [[ "$1" == "--verbose" ]]; then
    DEBUG_ARG="--debug"
fi

python3 /home/holaphei/repos/etiss-fork/etiss/py_validator_pipeline/main.py \
    --bin_golden_ref /<path_to_golden_ref_binary>/$PROGRAM_NAME \
    --ini_golden_ref /<path_to_golden_ref_ini>/$PROGRAM_NAME.ini \
    --bin_isuv /<path_to_binary_to_verify>/$PROGRAM_NAME \
    --ini_isuv /<path_to_ini_file_of_the_binary_to_verify>/$PROGRAM_NAME.ini \
    --src $SOURCE_FILE.c \
    --fun $FUNCTION_OF_INTEREST \
    --etiss_path /home/holaphei/repos/etiss-fork/etiss/build/bin \
    --etiss_executable bare_etiss_processor \
    $DEBUG_ARG
```

Explanations:
- `bin_golden_ref`: the golden reference binary to simulate on ETISS
- `ini_golden_ref`: the .ini - file for ETISS simulation for the golden reference
- `bin_isuv`: the binary under verification to simulate on ETISS
- `ini_isuv`: the .ini - file for ETISS simulation for the binary under verification
- `src`: Source code file from the binary in which the function of interest resides
- `fun`: function of interest
- `etiss_path`: absolute path to etiss executable
- `etiss_executable`: name of the etiss executable binary

Bash-script variables:
- `DEBUG_ARG`: as a convenience pipeline can be run in debug mode by adding the argument `--debug`. In debug mode more detailed output is printed to console and to log file.
- `PROGRAM_NAME`: if the binary name and the ini-file name (excluding extension .ini) are identical, the program name can be used to quickly set the binary to execute
- `SOURCE_FILE`: defines which source file in the compiled binary is of interest
- `FUNCTION_OF_INTEREST`: defines the function to be verified. 

Example usage: 
```bash
./<script-name> --debug
```



