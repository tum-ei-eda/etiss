#!/bin/bash
set -e
source ../SETTINGS_AND_VERSIONS.sh

ETISS_HOME="$PREFIX/etiss-${ETISS_VERSION}" 
export CC=`which gcc`
export CXX=`which g++`
BUILDDIR=Build-${HOST_TC_ID}
mkdir -p ${BUILDDIR} 
if [[ -n "$BOOST_ROOT" ]]
then
    SET_BOOST_ROOT=-DBoost_ROOT="${BOOST_ROOT}"
fi

CMAKE_OPTS=(
   -DCMAKE_BUILD_TYPE=${BUILDDIR} \
	 ${SET_BOOST_ROOT} -DBoost_COMPILER=mgw92 \
	 -DCMAKE_VERBOSE_MAKEFILE=TRUE -DETISS_BUILD_MANUAL_DOC=ON -DETISS_USE_PYTHON=OFF \
	 -DCMAKE_COLOR_MAKEFILE=OFF \
         -DCMAKE_INSTALL_PREFIX:PATH="$ETISS_HOME"
)
( cd ${BUILDDIR} ;
  echo CMAKE_OPTS "${CMAKE_OPTS[@]}" ;\
 cmake "${CMAKE_OPTS[@]}" --graphviz=test.dot -G "$CMAKE_GEN" ..
)
echo 
echo "make -C ${BUILDDIR} target... - to compile selected configuration"
echo
