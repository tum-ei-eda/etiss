/**
 * Generated on Thu, 12 May 2022 11:48:08 +0200.
 *
 * This file contains the library interface for the RV32IMACFDPV core architecture.
 */

// define a name for this library. this will be used to avoid name clashes with other libraries. in this example the library is named "X".
// IMPORTANT this name MUST match the library name: e.g. X -> libX.so

#define ETISS_LIBNAME RV32IMACFDPV
#include "etiss/helper/CPUArchLibrary.h" // defines the following functions
#include "RV32IMACFDPVArch.h"
extern "C" {

	ETISS_LIBRARYIF_VERSION_FUNC_IMPL

	ETISS_PLUGIN_EXPORT unsigned RV32IMACFDPV_countCPUArch()
	{
//TODO
		return 1; // number of cpu architectures provided
	}
	ETISS_PLUGIN_EXPORT const char * RV32IMACFDPV_nameCPUArch(unsigned index)
	{
//TODO
		switch (index)
		{
		case 0:
			return "RV32IMACFDPV";
		default:
			return "";
		}
	}
	ETISS_PLUGIN_EXPORT etiss::CPUArch* RV32IMACFDPV_createCPUArch(unsigned index,std::map<std::string,std::string> options)
	{
//TODO
		switch (index)
		{
		case 0:
			return new RV32IMACFDPVArch();
		default:
			return 0;
		}
	}
	ETISS_PLUGIN_EXPORT void RV32IMACFDPV_deleteCPUArch(etiss::CPUArch* arch)
	{
		delete arch;
	}
}
