/**
 * Generated on Thu, 24 Feb 2022 17:15:20 +0100.
 *
 * This file contains the library interface for the RV32IMACFD core architecture.
 */

// define a name for this library. this will be used to avoid name clashes with other libraries. in this example the library is named "X".
// IMPORTANT this name MUST match the library name: e.g. X -> libX.so

#define ETISS_LIBNAME RV32IMACFD
#include "etiss/helper/CPUArchLibrary.h" // defines the following functions
#include "RV32IMACFDArch.h"
extern "C" {

	ETISS_LIBRARYIF_VERSION_FUNC_IMPL

	ETISS_PLUGIN_EXPORT unsigned RV32IMACFD_countCPUArch()
	{
//TODO
		return 1; // number of cpu architectures provided
	}
	ETISS_PLUGIN_EXPORT const char * RV32IMACFD_nameCPUArch(unsigned index)
	{
//TODO
		switch (index)
		{
		case 0:
			return "RV32IMACFD";
		default:
			return "";
		}
	}
	ETISS_PLUGIN_EXPORT etiss::CPUArch* RV32IMACFD_createCPUArch(unsigned index,std::map<std::string,std::string> options)
	{
//TODO
		switch (index)
		{
		case 0:
			return new RV32IMACFDArch();
		default:
			return 0;
		}
	}
	ETISS_PLUGIN_EXPORT void RV32IMACFD_deleteCPUArch(etiss::CPUArch* arch)
	{
		delete arch;
	}
}
