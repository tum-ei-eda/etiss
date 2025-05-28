#!/bin/bash
python3 extract_subprogram_vars_and_params.py \
	--bin /home/holaphei/repos/etiss_riscv_examples/build/install/bin/test_cases \
	--src edge.c \
	--fun edgeDetect

