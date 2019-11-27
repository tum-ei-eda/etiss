#!/bin/bash
source ../SETTINGS_AND_VERSIONS.sh

ETISS_HOME="$PREFIX/etiss-${ETISS_VERSION}" 
export CC=`which gcc`
export CXX=`which g++`
BUILDDIR=Release
mkdir -p ${BUILDDIR} 
( cd ${BUILDDIR} ; 
 cmake -DCMAKE_BUILD_TYPE=${BUILDDIR} -DCMAKE_VERBOSE_MAKEFILE=TRUE -DETISS_BUILD_MANUAL_DOC=ON -DETISS_USE_PYTHON=OFF \
  -DCMAKE_INSTALL_PREFIX:PATH="$ETISS_HOME" --graphviz=test.dot -G "CodeBlocks - Unix Makefiles" ..
)
echo 
echo "make -C ${BUILDDIR} target... - to compile selected configuration"
echo
