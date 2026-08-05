/**
 * Generated on Wed, 05 Aug 2026 14:25:16 +0200.
 *
 * This file contains the library interface for the RV32IMXCoreV core architecture.
 */

// define a name for this library. this will be used to avoid name clashes with other libraries. in this example the
// library is named "X". IMPORTANT this name MUST match the library name: e.g. X -> libX.so

#define ETISS_LIBNAME RV32IMXCoreV
#include "etiss/helper/CPUArchLibrary.h" // defines the following functions
#include "RV32IMXCoreVArch.h"
#include <string>
extern "C"
{

    ETISS_LIBRARYIF_VERSION_FUNC_IMPL

    ETISS_PLUGIN_EXPORT unsigned RV32IMXCoreV_countCPUArch()
    {
        // TODO
        return 1; // number of cpu architectures provided
    }
    ETISS_PLUGIN_EXPORT const char *RV32IMXCoreV_nameCPUArch(unsigned index)
    {
        // TODO
        switch (index)
        {
        case 0:
            return "RV32IMXCoreV";
        default:
            return "";
        }
    }
    // clang-format off
    ETISS_PLUGIN_EXPORT etiss::CPUArch *RV32IMXCoreV_createCPUArch(unsigned index, std::map<std::string,std::string> options)
    // clang-format on
    {
        // TODO
        switch (index)
        {
        case 0:
        {
            auto it = options.find("coreno");
            unsigned int coreno = 0;
            if (it != options.end())
                coreno = std::stoul(it->second);
            else
                etiss::log(etiss::WARNING, "no core number provided for core, using 0");

            return new RV32IMXCoreVArch(coreno);
        }
        default:
            return 0;
        }
    }
    ETISS_PLUGIN_EXPORT void RV32IMXCoreV_deleteCPUArch(etiss::CPUArch *arch)
    {
        delete arch;
    }
}
