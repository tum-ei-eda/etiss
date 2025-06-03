#!/bin/bash
python3 /home/holaphei/repos/etiss-fork/etiss/py_validator_pipeline/main.py \
	--bin_golden_ref /home/holaphei/repos/etiss_riscv_examples/build/install/golden_ref/bin/ex-2-simplest-program \
	--ini_golden_ref /home/holaphei/repos/etiss_riscv_examples/build/install/golden_ref/ini/ex-2-simplest-program.ini \
	--bin_isuv /home/holaphei/repos/etiss_riscv_examples/build/install/isuv/bin/ex-2-simplest-program \
	--ini_isuv /home/holaphei/repos/etiss_riscv_examples/build/install/isuv/ini/ex-2-simplest-program.ini \
	--src ex-2-simplest-program.c \
	--fun main \
	--etiss_path /home/holaphei/repos/etiss-fork/etiss/build/bin \
	--etiss_executable bare_etiss_processor

