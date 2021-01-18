/**

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

        @author Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM

        @date July 29, 2014

        @version 0.1

*/
/**
        @file

        @brief implements etiss/ReturnCode.h

        @detail

*/
// special define to generate registration functionality of error codes for the
// maps provided in this file
#define ETISS_RETURNCODE_REGISTRATION_BODY
#include "etiss/jit/ReturnCode.h"

std::map<etiss::int32, const char *> &etiss::RETURNCODE::getErrorMessages()
{
    static std::map<etiss::int32, const char *> map;
    return map;
}

std::map<etiss::int32, const char *> &etiss::RETURNCODE::getErrorNames()
{
    static std::map<etiss::int32, const char *> map;
    return map;
}

int32_t etiss::RETURNCODE::setTemporary(const std::string &msg)
{
    static std::mutex mu;
    static std::string msgs[ETISS_RETURNCODE_TEMPORARY_COUNT];
    static int32_t pos = 0;
    std::lock_guard<std::mutex> lock(mu);
    int32_t ret = pos;
    pos = (pos + 1) % ETISS_RETURNCODE_TEMPORARY_COUNT;
    msgs[ret] = msg;
    return ret;
}

int32_t etiss_returncode_setTemporary(const char *msg)
{
    return etiss::RETURNCODE::setTemporary(std::string(msg));
}
