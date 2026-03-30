// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

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
