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

        @date July 28, 2014

        @version 0.1

*/
/**
        @file

        @brief contains general definitions needed for library function definitions. Doesn't need to be included by
   user.

        @see PluginLibrary.h
        @see JITLibrary.h
        @see CPUArchLibrary.h

        @detail




*/
#ifndef ETISS_INCLUDE_HELPER_MISC_H_
#define ETISS_INCLUDE_HELPER_MISC_H_

#include "etiss/pluginexport.h"
#include <map>
#include <string>

#include "etiss/config.h"

#define etiss_helper_merge_l2(X1, X2) X1##X2
#define etiss_helper_merge(X1, X2) etiss_helper_merge_l2(X1, X2)

extern "C"
{

    /**
             must be implemented like this:

                    #include "helper/Misc.h"
                    ETISS_LIBRARYIF_VERSION_FUNC_IMPL

    */
    ETISS_PLUGIN_EXPORT unsigned etiss_helper_merge(ETISS_LIBNAME, _etissversion)();
}

#define ETISS_LIBRARYIF_VERSION_FUNC_IMPL                                           \
    ETISS_PLUGIN_EXPORT unsigned etiss_helper_merge(ETISS_LIBNAME, _etissversion)() \
    {                                                                               \
        return (ETISS_VERSION_MAJOR << 16) + (ETISS_VERSION_MINOR);                 \
    }

#endif
