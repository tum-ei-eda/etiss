#!/bin/bash
python3 extract_subprogram_vars_and_params.py \
	--bin /home/holaphei/repos/etiss_riscv_examples/build/install/bin/ex-2-simplest-program \
	--src ex-2-simplest-program.c \
	--fun main

