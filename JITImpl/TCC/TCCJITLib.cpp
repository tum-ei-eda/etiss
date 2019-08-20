/*

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

        This file is part of ETISS tool, see <https://gitlab.lrz.de/de-tum-ei-eda-open/etiss>.

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

        @author Chair of Electronic Design Automation, TUM

        @version 0.1

*/

// define a name for this library. this will be used to avoid name clashes with other libraries. in this example the
// library is named "X". IMPORTANT this name MUST match the library name: e.g. X -> libX.so

#define ETISS_LIBNAME TCCJIT

#include "etiss/helper/JITLibrary.h" // defines the following functions

#include "TCCJIT.h"

extern "C"
{

    ETISS_PLUGIN_EXPORT const char *TCCJIT_versionInfo() { return "0.9.26for0.4"; }

    ETISS_LIBRARYIF_VERSION_FUNC_IMPL

    ETISS_PLUGIN_EXPORT unsigned TCCJIT_countJIT()
    {
        // TODO
        return 1; // number of cpu architectures provided
    }
    ETISS_PLUGIN_EXPORT const char *TCCJIT_nameJIT(unsigned index)
    {
        // TODO
        switch (index)
        {
        case 0:
            return "TCCJIT";
        default:
            return "";
        }
    }
    ETISS_PLUGIN_EXPORT etiss::JIT *TCCJIT_createJIT(unsigned index, std::map<std::string, std::string> options)
    {
        // TODO
        switch (index)
        {
        case 0:
            // parse arguments?
            return new TCCJIT();
        default:
            return 0;
        }
    }
    ETISS_PLUGIN_EXPORT void TCCJIT_deleteJIT(etiss::JIT *arch) { delete arch; }
}
