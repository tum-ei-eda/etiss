# Generated on Mon, 12 Jan 2026 12:41:11 +0100.
#
# This file contains the CMake build info for the XIsaacCore core architecture.

PROJECT(XIsaacCore)

SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
SET(CMAKE_INSTALL_RPATH "\$ORIGIN/../../include/jit/etiss/jit")

ADD_LIBRARY(${PROJECT_NAME} SHARED
	XIsaacCoreArch.cpp
	XIsaacCoreArchLib.cpp
	XIsaacCoreArchSpecificImp.cpp
	XIsaacCoreFuncs.c
	XIsaacCoreInstr.cpp
	XIsaacCore_RV32IInstr.cpp
	XIsaacCore_RV32ICInstr.cpp
	XIsaacCore_RV32MInstr.cpp
	XIsaacCore_RV32FInstr.cpp
	XIsaacCore_RV32FCInstr.cpp
	XIsaacCore_RV32DInstr.cpp
	XIsaacCore_RV32DCInstr.cpp
	XIsaacCore_ZifenceiInstr.cpp
	XIsaacCore_tum_csrInstr.cpp
	XIsaacCore_tum_retInstr.cpp
	XIsaacCore_RV32AInstr.cpp
	XIsaacCore_tum_rvaInstr.cpp
	XIsaacCore_tum_semihostingInstr.cpp
	XIsaacCore_XIsaacInstr.cpp
)

add_custom_command(
	TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
		"${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}Funcs.h"
		"${ETISS_BINARY_DIR}/include/jit/Arch/${PROJECT_NAME}"
)
INSTALL(FILES "${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}Funcs.h" DESTINATION "include/jit/Arch/${PROJECT_NAME}")

ETISSPluginArch(${PROJECT_NAME})