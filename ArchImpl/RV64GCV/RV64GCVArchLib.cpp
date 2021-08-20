// This file was generated on Mon Jun 22 18:08:07 CEST 2020
// If necessary please modify this file according to the instructions
// Contact: eda@tum

// define a name for this library. this will be used to avoid name clashes with other libraries. in this example the library is named "X".
// IMPORTANT this name MUST match the library name: e.g. X -> libX.so

#define ETISS_LIBNAME RV64GCV
#include "etiss/helper/CPUArchLibrary.h" // defines the following functions
#include "RV64GCVArch.h"
extern "C" {

    ETISS_LIBRARYIF_VERSION_FUNC_IMPL

    ETISS_PLUGIN_EXPORT unsigned RV64GCV_countCPUArch()
    {
//TODO
        return 1; // number of cpu architectures provided
    }
    ETISS_PLUGIN_EXPORT const char * RV64GCV_nameCPUArch(unsigned index)
    {
//TODO
        switch (index)
        {
        case 0:
            return "RV64GCV";
        default:
            return "";
        }
    }
    ETISS_PLUGIN_EXPORT etiss::CPUArch* RV64GCV_createCPUArch(unsigned index,std::map<std::string,std::string> options)
    {
//TODO
        switch (index)
        {
        case 0:
            return new RV64GCVArch();
        default:
            return 0;
        }
    }
    ETISS_PLUGIN_EXPORT void RV64GCV_deleteCPUArch(etiss::CPUArch* arch)
    {
        delete arch;
    }

}

