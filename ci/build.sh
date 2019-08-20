#!/usr/bin/bash

# A simple script to build and install ETISS in ./build_dir

mkdir build_dir
cd build_dir
cmake -DCMAKE_BUILD_TYPE=Debug -DETISS_BUILD_MANUAL_DOC=ON \
        -DETISS_USE_PYTHON=OFF -DCMAKE_INSTALL_PREFIX:PATH=`pwd`/installed \
        --graphviz=test.dot -G "CodeBlocks - Unix Makefiles" ../
make
make install
cd installed/examples/SW/riscv
svn checkout https://github.com/pulp-platform/pulpino/trunk/sw/libs/sys_lib
svn checkout https://github.com/pulp-platform/pulpino/trunk/sw/libs/string_lib
svn checkout https://github.com/cliffordwolf/picorv32/trunk/tests instr_tests
cd ../../bare_etiss_processor
chmod +x run.sh
cd ../../..
