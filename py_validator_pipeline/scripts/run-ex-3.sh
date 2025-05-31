#!/bin/bash
python3 /home/holaphei/repos/etiss-fork/etiss/py_validator_pipeline/main.py \
	--bin /home/holaphei/repos/etiss_riscv_examples/build/install/bin/ex-3-global-var \
	--ini /home/holaphei/repos/etiss_riscv_examples/build/install/ini/ex-3-global-var.ini \
	--src ex-3-global-var.c \
	--fun main \
	--etiss_path /home/holaphei/repos/etiss-fork/etiss/build/bin \
	--etiss_executable bare_etiss_processor

