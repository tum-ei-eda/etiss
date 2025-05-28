#!/bin/bash
python3 /home/holaphei/repos/etiss-fork/etiss/py_validator_pipeline/main.py \
	--bin /home/holaphei/repos/etiss_riscv_examples/build/install/bin/semihosting_cpp \
	--src main.cpp \
	--fun main \
	--ini /home/holaphei/repos/etiss_riscv_examples/build/install/ini/semihosting_cpp.ini \
	--etiss_path /home/holaphei/repos/etiss-fork/etiss/build/bin \
	--etiss_executable bare_etiss_processor

