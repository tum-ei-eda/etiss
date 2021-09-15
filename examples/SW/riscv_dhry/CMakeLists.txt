cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
SET(CMAKE_TOOLCHAIN_FILE
    "../riscv/cmake/pulpino_tumeda/toolchain.cmake"
)
project(etiss_examples)
include(../riscv/cmake/PulpinoTarget.cmake)

ADD_DEFINITIONS(-DPULPINO_NO_GPIO)

ADD_DEFINITIONS(-DTIME)
ADD_DEFINITIONS(-DNO_INIT)

ADD_EXECUTABLE_PULPINO(riscv_example dhry_1.c dhry_2.c)
