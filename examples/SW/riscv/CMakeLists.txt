cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
SET(CMAKE_TOOLCHAIN_FILE
    "cmake/pulpino_tumeda/toolchain.cmake"
)
project(etiss_examples)
include(cmake/PulpinoTarget.cmake)

ADD_DEFINITIONS(-DPULPINO_NO_GPIO)

ADD_EXECUTABLE_PULPINO(riscv_example.elf 
							main.c 
							./test_accelerators/qvanilla_acc.c
							./test_accelerators/vanilla_acc.c
					  )
