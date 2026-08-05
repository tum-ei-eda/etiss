# Generated on Wed, 05 Aug 2026 14:25:16 +0200.
#
# This file contains the CMake build info for the RV32IMXCoreV core architecture.

PROJECT(RV32IMXCoreV)
FIND_PACKAGE(ETISS)

SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
SET(CMAKE_INSTALL_RPATH "\$ORIGIN/../../include/jit/etiss/jit")

ADD_LIBRARY(${PROJECT_NAME} SHARED
	RV32IMXCoreVArch.cpp
	RV32IMXCoreVArchLib.cpp
	RV32IMXCoreVArchSpecificImp.cpp
	RV32IMXCoreVFuncs.c
	RV32IMXCoreVInstr.cpp
	RV32IMXCoreV_RV32IInstr.cpp
	RV32IMXCoreV_RV32MInstr.cpp
	RV32IMXCoreV_ZifenceiInstr.cpp
	RV32IMXCoreV_XCoreVSimdInstr.cpp
	RV32IMXCoreV_XCoreVBitmanipInstr.cpp
	RV32IMXCoreV_XCoreVAluInstr.cpp
	RV32IMXCoreV_XCoreVBranchImmediateInstr.cpp
	RV32IMXCoreV_XCoreVMemInstr.cpp
	RV32IMXCoreV_XCoreVMacInstr.cpp
	RV32IMXCoreV_tum_xcorevmacInstr.cpp
	RV32IMXCoreV_tum_csrInstr.cpp
	RV32IMXCoreV_tum_retInstr.cpp
	RV32IMXCoreV_tum_semihostingInstr.cpp
)

IF(ETISS_BINARY_DIR)
	ADD_CUSTOM_COMMAND(
		TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy
			"${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}Funcs.h"
			"${ETISS_BINARY_DIR}/include/jit/Arch/${PROJECT_NAME}"
	)
ENDIF()
INSTALL(FILES "${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}Funcs.h" DESTINATION "include/jit/Arch/${PROJECT_NAME}")

# handle gdbserver xml files
IF(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/xml")
	ADD_CUSTOM_TARGET(copy_${PROJECT_NAME}_xml ALL
		COMMAND ${CMAKE_COMMAND} -E make_directory
			"${CMAKE_CURRENT_LIST_DIR}/xml"
		COMMAND ${CMAKE_COMMAND} -E copy_directory
			"${CMAKE_CURRENT_LIST_DIR}/xml"
			"${ETISS_BINARY_DIR}/xml/${PROJECT_NAME}"
	)
	ADD_DEPENDENCIES(${PROJECT_NAME} copy_${PROJECT_NAME}_xml)
	INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/xml/ DESTINATION xml/${PROJECT_NAME})
ENDIF()

ETISSPluginArch(${PROJECT_NAME})
