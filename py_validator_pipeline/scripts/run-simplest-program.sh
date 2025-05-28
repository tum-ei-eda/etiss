#!/bin/bash
python3 main.py \
	--bin /home/holaphei/repos/etiss_riscv_examples/build/install/bin/ex-2-simplest-program \
	--ini /home/holaphei/repos/etiss_riscv_examples/build/install/ini/ex-2-simplest-program.ini \
	--src ex-2-simplest-program.c \
	--fun main \
	--etiss_path /home/holaphei/repos/etiss-fork/etiss/build/bin \
	--etiss_executable bare_etiss_processor

