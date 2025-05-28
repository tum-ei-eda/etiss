#!/bin/bash
python3 /home/holaphei/repos/etiss-fork/etiss/py_validator_pipeline/main.py \
	--bin /home/holaphei/repos/etiss_riscv_examples/build/install/bin/test_cases \
	--src edge.c \
	--fun edgeDetect \
	--ini /home/holaphei/repos/etiss_riscv_examples/build/install/ini/test_cases.ini \
	--etiss_path /home/holaphei/repos/etiss-fork/etiss/build/bin \
	--etiss_executable bare_etiss_processor

