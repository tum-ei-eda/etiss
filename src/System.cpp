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

        @date November 5, 2014

        @version 0.1

*/
/**
        @file

        @brief implements etiss/System.h. manly consists of the implementation of std::shared_ptr<ETISS_System>
   etiss::wrap(etiss::System * sys)

        @detail

*/

#include <malloc.h>

#include "etiss/System.h"

static etiss_int32 system_call_iread(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint32 length)
{
    return ((etiss::System *)handle)->iread(cpu, addr, length);
}
static etiss_int32 system_call_iwrite(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer,
                                      etiss_uint32 length)
{
    return ((etiss::System *)handle)->iwrite(cpu, addr, buffer, length);
}

static etiss_int32 system_call_dread(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer,
                                     etiss_uint32 length)
{
    return ((etiss::System *)handle)->dread(cpu, addr, buffer, length);
}
static etiss_int32 system_call_dwrite(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer,
                                      etiss_uint32 length)
{
    return ((etiss::System *)handle)->dwrite(cpu, addr, buffer, length);
}

static etiss_int32 system_call_dbg_read(void *handle, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length)
{
    return ((etiss::System *)handle)->dbg_read(addr, buffer, length);
}

static etiss_int32 system_call_dbg_write(void *handle, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length)
{
    return ((etiss::System *)handle)->dbg_write(addr, buffer, length);
}

static void system_call_syncTime(void *handle, ETISS_CPU *cpu)
{
    ((etiss::System *)handle)->syncTime(cpu);
}

std::shared_ptr<ETISS_System> etiss::wrap(etiss::System *sys)
{
    if (sys == 0)
        return 0;
    ETISS_System *ret = new ETISS_System();

    ret->iread = &system_call_iread;
    ret->iwrite = &system_call_iwrite;

    ret->dread = &system_call_dread;
    ret->dwrite = &system_call_dwrite;

    ret->dbg_read = &system_call_dbg_read;
    ret->dbg_write = &system_call_dbg_write;

    ret->syncTime = &system_call_syncTime;

    ret->handle = (void *)sys;

    return std::shared_ptr<ETISS_System>(ret);
}

#ifdef __cplusplus
extern "C"
{
#endif
    int ETISS_System_isvalid(ETISS_System *sys)
    {
        return sys->iread != 0 && sys->iwrite != 0 && sys->dread != 0 && sys->dwrite != 0 && sys->syncTime != 0;
    }

#ifdef __cplusplus
}
#endif

namespace etiss
{

etiss::int32 SimpleSystem::iread(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint32 len)
{
    // disabled since this read function is only intended for timing purpose
    // if (!read(false,cpu,addr,0,len))
    //	return IBUS_READ_ERROR;

    return 0;
}
etiss::int32 SimpleSystem::iwrite(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len)
{
    if (!write(false, cpu, addr, buf, len))
        return etiss::RETURNCODE::IBUS_WRITE_ERROR;

    return 0;
}
etiss::int32 SimpleSystem::dread(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len)
{
    if (!read(false, cpu, addr, buf, len))
        return etiss::RETURNCODE::DBUS_READ_ERROR;

    return 0;
}
etiss::int32 SimpleSystem::dwrite(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len)
{
    if (!write(false, cpu, addr, buf, len))
        return etiss::RETURNCODE::IBUS_WRITE_ERROR;

    return 0;
}
etiss::int32 SimpleSystem::dbg_read(etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len)
{
    if (!read(true, 0, addr, buf, len))
        return etiss::RETURNCODE::DBUS_READ_ERROR;

    return 0;
}
etiss::int32 SimpleSystem::dbg_write(etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len)
{
    if (!write(true, 0, addr, buf, len))
        return etiss::RETURNCODE::DBUS_WRITE_ERROR;

    return 0;
}
void SimpleSystem::syncTime(ETISS_CPU *cpu)
{
    // NOP
}
etiss::int32 dbg_print(etiss::uint32 reg)
{
    // NOP
    return 0;
}
} // namespace etiss
