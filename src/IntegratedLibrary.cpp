/**

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

        This file is part of ETISS tool, see <https://github.com/tum-ei-eda/etiss>.

        The initial version of this software has been created with the funding support by the German Federal
        Ministry of Education and Research (BMBF) in the project EffektiV under grant 01IS13022.

        Redistribution and use in source and binary forms, with or without modification, are permitted
        provided that the following conditions are met:

        1. Redistributions of source code must retain the above copyright notice, this list of conditions and
        the following disclaimer.

        2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions
        and the following disclaimer in the documentation and/or other materials provided with the distribution.

        3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse
        or promote products derived from this software without specific prior written permission.

        THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
        WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
        PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
        DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
        PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
        HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
        NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
        POSSIBILITY OF SUCH DAMAGE.

        </pre>

        @author Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM

        @date July 29, 2014

        @version 0.1

*/
/**
        @file

        @brief example implementation of a dynamic library interface that is used to provide access to integrated
   plugins. Other dynamic libraries should be implemented like this

        @detail

*/

#define ETISS_LIBNAME ETISSINCLUDED

#include "etiss/helper/CPUArchLibrary.h"
#include "etiss/helper/JITLibrary.h"
#include "etiss/helper/PluginLibrary.h"

#include "etiss/LibraryInterface.h"

#include "etiss/IntegratedLibrary/Logger.h"
#include "etiss/IntegratedLibrary/PrintInstruction.h"
#include "etiss/IntegratedLibrary/errorInjection/Plugin.h"
#include "etiss/IntegratedLibrary/gdb/GDBServer.h"

extern "C"
{

    // implement version function
    ETISS_LIBRARYIF_VERSION_FUNC_IMPL

    unsigned ETISSINCLUDED_countJIT() { return 0; }

    unsigned ETISSINCLUDED_countCPUArch() { return 0; }

    unsigned ETISSINCLUDED_countPlugin() { return 4; }

    const char *ETISSINCLUDED_nameJIT(unsigned index) { return 0; }

    const char *ETISSINCLUDED_nameCPUArch(unsigned index) { return 0; }

    const char *ETISSINCLUDED_namePlugin(unsigned index)
    {
        switch (index)
        {
        case 0:
            return "BlockAccurateHandler";
        case 1:
            return "gdbserver";
        case 2:
            return "PrintInstruction";
        case 3:
            return "Logger";
        }
        return 0;
    }

    etiss::JIT *ETISSINCLUDED_createJIT(unsigned index, std::map<std::string, std::string> options) { return 0; }

    etiss::CPUArch *ETISSINCLUDED_createCPUArch(unsigned index, std::map<std::string, std::string> options)
    {
        return 0;
    }

    etiss::Plugin *ETISSINCLUDED_createPlugin(unsigned index, std::map<std::string, std::string> options)
    {
        switch (index)
        {
        case 0:
        {
            /// expected option format: -rREGISTERNAME -> FILEPATH (e.g. -rR4 -> /home/you/registerErrors.txt)
            etiss::plugin::errorInjection::BlockAccurateHandler *ret =
                new etiss::plugin::errorInjection::BlockAccurateHandler();
            for (auto iter = options.begin(); iter != options.end(); iter++)
            {
                if (iter->first.length() > 2 && iter->first[0] == '-' && iter->first[1] == 'r')
                {
                    std::string regname = iter->first.substr(2);
                    ret->parseFile(iter->second, regname);
                }
                else
                {
                    etiss::log(etiss::WARNING,
                               std::string("IntegratedLibrary: failed to parse option for BlockAccurateHandler: ") +
                                   iter->first + "->" + iter->second);
                }
            }
            return ret;
        }
        case 1:
            return etiss::plugin::gdb::Server::createTCPServer(options);
        case 2:
            return new etiss::plugin::PrintInstruction();
        case 3:
            etiss::Configuration cfg;
            cfg.config() = options;
            return new etiss::plugin::Logger(cfg.get<uint64_t>("plugin.logger.logaddr", 0x80000000),
                                             cfg.get<uint64_t>("plugin.logger.logmask", 0xF0000000));
        }
        return 0;
    }

    void ETISSINCLUDED_deleteJIT(etiss::JIT *o) { delete o; }

    void ETISSINCLUDED_deleteCPUArch(etiss::CPUArch *o) { delete o; }

    void ETISSINCLUDED_deletePlugin(etiss::Plugin *o) { delete o; }
}

// not part of the example implementation
unsigned etiss::LibraryInterface::getCurrentLibraryVersion()
{
    return ETISSINCLUDED_etissversion();
}
