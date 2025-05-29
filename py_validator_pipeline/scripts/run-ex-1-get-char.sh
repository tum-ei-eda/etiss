#!/bin/bash
python3 /home/holaphei/repos/etiss-fork/etiss/py_validator_pipeline/main.py \
	--bin /home/holaphei/repos/etiss_riscv_examples/build/install/bin/ex-1-print-inst \
	--ini /home/holaphei/repos/etiss_riscv_examples/build/install/ini/ex-1-print-inst.ini \
	--src print-inst-ex-1.c \
	--fun get_char \
	--etiss_path /home/holaphei/repos/etiss-fork/etiss/build/bin \
	--etiss_executable bare_etiss_processor

