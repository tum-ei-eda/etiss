#!/bin/bash
python3 /home/holaphei/repos/etiss-fork/etiss/py_validator_pipeline/main.py \
	--bin_golden_ref /home/holaphei/repos/etiss_riscv_examples/build/install/golden_ref/bin/ex-6 \
	--ini_golden_ref /home/holaphei/repos/etiss_riscv_examples/build/install/golden_ref/ini/ex-6.ini \
	--bin_isuv /home/holaphei/repos/etiss_riscv_examples/build/install/isuv/bin/ex-6 \
	--ini_isuv /home/holaphei/repos/etiss_riscv_examples/build/install/isuv/ini/ex-6.ini \
	--src ex-6.c \
	--fun circumference \
	--etiss_path /home/holaphei/repos/etiss-fork/etiss/build/bin \
	--etiss_executable bare_etiss_processor
