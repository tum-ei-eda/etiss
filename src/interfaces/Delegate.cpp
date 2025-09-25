// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

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
