#!/bin/bash
python3 /home/holaphei/repos/etiss-fork/etiss/py_validator_pipeline/main.py \
	--bin /home/holaphei/repos/etiss_riscv_examples/build/install/bin/ex-4-multiple-glob-vars \
	--ini /home/holaphei/repos/etiss_riscv_examples/build/install/ini/ex-4-multiple-glob-vars.ini \
	--src ex-4-multiple-glob-vars.c \
	--fun main \
	--etiss_path /home/holaphei/repos/etiss-fork/etiss/build/bin \
	--etiss_executable bare_etiss_processor
