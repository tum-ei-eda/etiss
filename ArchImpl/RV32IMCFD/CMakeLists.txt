# Generated on Thu, 24 Feb 2022 16:07:25 +0100.
#
# This file contains the CMake build info for the RV32IMCFD core architecture.

PROJECT(RV32IMCFD)

ADD_LIBRARY(${PROJECT_NAME} SHARED
	RV32IMCFDArch.cpp
	RV32IMCFDArchLib.cpp
	RV32IMCFDArchSpecificImp.cpp
	RV32IMCFDInstr.cpp
	RV32IMCFD_RISCVBaseInstr.cpp
	RV32IMCFD_RV32IInstr.cpp
	RV32IMCFD_RV32ICInstr.cpp
	RV32IMCFD_RV32MInstr.cpp
	RV32IMCFD_ZicsrInstr.cpp
	RV32IMCFD_RV32FInstr.cpp
	RV32IMCFD_RV32FCInstr.cpp
	RV32IMCFD_RV32DInstr.cpp
	RV32IMCFD_RV32DCInstr.cpp
	RV32IMCFD_ZifenceiInstr.cpp
	RV32IMCFD_tum_csrInstr.cpp
	RV32IMCFD_tum_retInstr.cpp
	RV32IMCFD_RV32AInstr.cpp
	RV32IMCFD_tum_rvaInstr.cpp
)

INSTALL(FILES "${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}Funcs.h" DESTINATION "include/jit/Arch/${PROJECT_NAME}")

ETISSPluginArch(${PROJECT_NAME})