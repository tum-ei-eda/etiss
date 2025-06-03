#!/bin/bash
python3 /home/holaphei/repos/etiss-fork/etiss/py_validator_pipeline/main.py \
	--bin_golden_ref /home/holaphei/repos/etiss_riscv_examples/build/install/golden_ref/bin/semihosting_cpp \
	--ini_golden_ref /home/holaphei/repos/etiss_riscv_examples/build/install/golden_ref/ini/semihosting_cpp.ini \
	--bin_isuv /home/holaphei/repos/etiss_riscv_examples/build/install/isuv/bin/semihosting_cpp \
	--ini_isuv /home/holaphei/repos/etiss_riscv_examples/build/install/isuv/ini/semihosting_cpp.ini \
	--src main.cpp \
	--fun main \
	--etiss_path /home/holaphei/repos/etiss-fork/etiss/build/bin \
	--etiss_executable bare_etiss_processor

