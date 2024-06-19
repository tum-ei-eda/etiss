/*

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

        @author Chair of Electronic Design Automation, TUM

        @version 0.1

*/

#include "etiss/IntegratedLibrary/Logger.h"
#include <cstring>
#include <iomanip>

namespace etiss
{

namespace plugin
{

etiss_int32 log(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buf, etiss_uint32 len)
{
    auto customH = (Logger::CustomHandle *)handle;
    if ((addr & customH->mask) != customH->addr)
    {
        return customH->origSys->dwrite(customH->origSys->handle, cpu, addr, buf, len);
    }

    if (len <= 0)
        return 0;

    if (buf == 0)
        return 0;

    if (len == 1)
        std::cout << (char)buf[0];
    else
    {
        // print as different types
        int iout = 0;
        int fbuf = 0;
        std::cout << " <char>  ";
        for (unsigned i = 0; i < len; i++)
        {
            iout |= buf[i] << (len - i - 1) * 8;
            fbuf |= buf[i] << (len - i - 1) * 8;
            bool isChar = (buf[i] > 32 && buf[i] < 127);
            if (buf[i] == '\n')
                std::cout << "\\n";
            else
                std::cout << (isChar ? std::string("\033[1;31m") : std::string("")) << std::setw(2) << (char)buf[i]
                          << (isChar ? std::string("\033[0m") : std::string(""));
        }
        float *fout = reinterpret_cast<float *>(&fbuf);

        std::cout << std::setfill('0') << std::hex << " | <hex>  0x" << std::setw(8) << iout << std::dec
                  << std::setfill(' ');
        std::cout << " | <int>  " << std::setw(10) << iout;
        std::cout << " | <float>  " << *fout;
        std::cout << std::endl;
    }

    std::flush(std::cout);

    return 0;
}

Logger::Logger(uint64_t addr_value, uint64_t addr_mask)
{
    customHandle_.addr = addr_value & addr_mask;
    customHandle_.mask = addr_mask;
    if (customHandle_.addr == 0 && customHandle_.mask == 0)
    {
        etiss::log(etiss::WARNING, "Logger instantiated with mask and address set to 0. this will redirect all "
                                   "read/writes exclusively to this logger instance.");
    }
}

ETISS_System Logger::getWrapInfo(ETISS_System *origSystem)
{
    customHandle_.origSys = origSystem;

    ETISS_System wrapInfo = {};
    wrapInfo.handle = &customHandle_;
    wrapInfo.dwrite = &log;
    return wrapInfo;
}

} // namespace plugin

} // namespace etiss
