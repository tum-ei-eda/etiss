/**
 * Generated on Mon, 02 Oct 2023 18:56:15 +0200.
 *
 * This file contains the library interface for the RV64IMACFD core architecture.
 */

// define a name for this library. this will be used to avoid name clashes with other libraries. in this example the library is named "X".
// IMPORTANT this name MUST match the library name: e.g. X -> libX.so

#define ETISS_LIBNAME RV64IMACFD
#include "etiss/helper/CPUArchLibrary.h" // defines the following functions
#include "RV64IMACFDArch.h"
extern "C" {

	ETISS_LIBRARYIF_VERSION_FUNC_IMPL

	ETISS_PLUGIN_EXPORT unsigned RV64IMACFD_countCPUArch()
	{
//TODO
		return 1; // number of cpu architectures provided
	}
	ETISS_PLUGIN_EXPORT const char * RV64IMACFD_nameCPUArch(unsigned index)
	{
//TODO
		switch (index)
		{
		case 0:
			return "RV64IMACFD";
		default:
			return "";
		}
	}
	ETISS_PLUGIN_EXPORT etiss::CPUArch* RV64IMACFD_createCPUArch(unsigned index,std::map<std::string,std::string> options)
	{
//TODO
		switch (index)
		{
		case 0:
			return new RV64IMACFDArch();
		default:
			return 0;
		}
	}
	ETISS_PLUGIN_EXPORT void RV64IMACFD_deleteCPUArch(etiss::CPUArch* arch)
	{
		delete arch;
	}
}
