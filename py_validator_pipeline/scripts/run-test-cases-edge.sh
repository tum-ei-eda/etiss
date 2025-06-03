#!/bin/bash
python3 /home/holaphei/repos/etiss-fork/etiss/py_validator_pipeline/main.py \
	--bin_golden_ref /home/holaphei/repos/etiss_riscv_examples/build/install/golden_ref/bin/test_cases \
	--ini_golden_ref /home/holaphei/repos/etiss_riscv_examples/build/install/golden_ref/ini/test_cases.ini \
	--bin_isuv /home/holaphei/repos/etiss_riscv_examples/build/install/isuv/bin/test_cases \
	--ini_isuv /home/holaphei/repos/etiss_riscv_examples/build/install/isuv/ini/test_cases.ini \
	--src edge.c \
	--fun edgeDetect \
	--etiss_path /home/holaphei/repos/etiss-fork/etiss/build/bin \
	--etiss_executable bare_etiss_processor

