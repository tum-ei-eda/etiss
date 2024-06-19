#define ETISS_LIBNAME RiscvTestsPlugins

#include "etiss/helper/CPUArchLibrary.h"
#include "etiss/helper/JITLibrary.h"
#include "etiss/helper/PluginLibrary.h"

#include "etiss/LibraryInterface.h"

#include "FileLogger.h"


extern "C"
{

    // implement version function
    ETISS_LIBRARYIF_VERSION_FUNC_IMPL

    unsigned RiscvTestsPlugins_countJIT() { return 0; }

    unsigned RiscvTestsPlugins_countCPUArch() { return 0; }

    unsigned RiscvTestsPlugins_countPlugin() { return 1; }

    const char *RiscvTestsPlugins_nameJIT(unsigned index) { return 0; }

    const char *RiscvTestsPlugins_nameCPUArch(unsigned index) { return 0; }

    const char *RiscvTestsPlugins_namePlugin(unsigned index)
    {
        switch (index)
        {
        case 0:
            return "FileLogger";
        }
        return 0;
    }

    etiss::JIT *RiscvTestsPlugins_createJIT(unsigned index, std::map<std::string, std::string> options) { return 0; }

    etiss::CPUArch *RiscvTestsPlugins_createCPUArch(unsigned index, std::map<std::string, std::string> options)
    {
        return 0;
    }

    etiss::Plugin *RiscvTestsPlugins_createPlugin(unsigned index, std::map<std::string, std::string> options)
    {
        switch (index)
        {
        case 0:
        {
            etiss::Configuration cfg;
            cfg.config() = options;
            return new etiss::plugin::FileLogger(
                    cfg.get<uint64_t>("plugin.filelogger.logaddr", 0x80000000),
                    cfg.get<uint64_t>("plugin.filelogger.logmask", 0xF0000000),
                    cfg.get<std::string>("plugin.filelogger.output_path", ""),
                    "",
                    cfg.get<bool>("plugin.filelogger.terminate_on_write", false)
                );
        }
        }
        return 0;
    }

    void RiscvTestsPlugins_deleteJIT(etiss::JIT *o) { delete o; }

    void RiscvTestsPlugins_deleteCPUArch(etiss::CPUArch *o) { delete o; }

    void RiscvTestsPlugins_deletePlugin(etiss::Plugin *o) { delete o; }
}

// not part of the example implementation
unsigned etiss::LibraryInterface::getCurrentLibraryVersion()
{
    return RiscvTestsPlugins_etissversion();
}
