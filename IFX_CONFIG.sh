#!/bin/bash
set -e
source `dirname "$0"`/../SETTINGS_AND_VERSIONS.sh


ETISS_HOME="$PREFIX/etiss-${ETISS_VERSION}" 
INSTALL_HOME="${ETISS_HOME}"

while [[ "$1" != "" && "$1" != "--" ]]
do
    case "$1" in
    "--help"|"-?") 
        echo "`basename $0`: --install <install_path> "
        exit 1
        ;;
    "--install"|"-I")
        INSTALL_HOME="$2"
        shift
        ;;
    "*")
        break
        ;;
    esac
    shift
done

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
         -DCMAKE_INSTALL_PREFIX:PATH="$INSTALL_HOME"
)

echo CMAKE_OPTS "${CMAKE_OPTS[@]}" ;
cmake -B  "${BUILDDIR}" -S . "${CMAKE_OPTS[@]}" --graphviz=test.dot -G "$CMAKE_GEN" 

echo 
echo "cmake --build ${BUILDDIR} ... - to compile selected configuration"
echo
