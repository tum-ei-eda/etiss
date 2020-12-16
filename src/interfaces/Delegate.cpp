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

        @author Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM

        @version 0.1

*/

#include "etiss/interfaces/Delegate.h"

namespace etiss
{
namespace interfaces
{

Delegate::Delegate(ETISS_System &system, ETISS_CPU &cpu) : system(system), cpu(cpu) {}

void Delegate::syncTime(uint64_t time_ps)
{
#if DEBUG
    if (time_ps < cpu.cpuTime_ps)
    {
        etiss::log(etiss::FATALERROR, "The cpu simulation time went backwards");
    }
#endif

    cpu.cpuTime_ps = time_ps;

    system.syncTime(system.handle, &cpu);
}

etiss::int32 Delegate::read(bool ibus, uint64_t &time_ps, uint64_t addr, uint8_t *buf, unsigned len)
{
    // std::cout << "\nread "<<(ibus?"ibus":"dbus")<<" at address 0x" << std::hex << addr << std::dec << std::endl;

    if (injectedRead)
    {
        bool cont = false;
        bool handleNormal = false;

        etiss::int32 ret = injectedRead(ibus, time_ps, addr, buf, len, cont, handleNormal);

        if (!cont)
            injectedRead = nullptr;

        if (!handleNormal) // injectedRead may signal that read() should handle this call
        {
            if (unlikely(snoopRead))
            {
                snoopRead(true, time_ps, addr, buf, len);
            }
            return ret;
        }
    }

#if DEBUG
    if (time_ps < cpu.cpuTime_ps)
    {
        etiss::log(etiss::FATALERROR, "The cpu simulation time went backwards");
    }
#endif

    cpu.cpuTime_ps = time_ps;
    int32_t code = etiss::RETURNCODE::NOERROR;

    if (ibus)
    {
        code = system.iread(system.handle, &cpu, addr, len); // simulate read

        if ((code == etiss::RETURNCODE::NOERROR) || (code == etiss::RETURNCODE::GDBNOERROR)) // check return code
        {
            code = system.dbg_read(system.handle, addr, buf, len); // read data
        }
    }
    else
    {
        code = system.dread(system.handle, &cpu, addr, buf, len); // read data
    }

    time_ps = cpu.cpuTime_ps;

    if (unlikely(snoopRead))
    {
        snoopRead(false, time_ps, addr, buf, len);
    }

    return code;
}

etiss::int32 Delegate::write(bool ibus, uint64_t &time_ps, uint64_t addr, uint8_t *buf, unsigned len)
{

    if (redirectedWrite)
    {
        bool cont = false;
        bool handleNormal = false;

        etiss::int32 ret = redirectedWrite(ibus, time_ps, addr, buf, len, cont, handleNormal);

        if (!cont)
            redirectedWrite = std::function<bool(bool, uint64_t &, uint64_t, uint8_t *, unsigned, bool &, bool &)>();

        if (!handleNormal) // redirectedWrite may signal that write() should handle this call
            return ret;
    }

#if DEBUG
    if (time_ps < cpu.cpuTime_ps)
    {
        etiss::log(etiss::FATALERROR, "The cpu simulation time went backwards");
    }
#endif

    cpu.cpuTime_ps = time_ps;
    int32_t code = etiss::RETURNCODE::NOERROR;

    if (ibus)
    {
        code = system.iwrite(system.handle, &cpu, addr, buf, len); // read data
    }
    else
    {
        code = system.dwrite(system.handle, &cpu, addr, buf, len); // read data
    }

    time_ps = cpu.cpuTime_ps;

    return code;
}

} // namespace interfaces
} // namespace etiss
