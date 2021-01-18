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

#include "etiss/IntegratedLibrary/MemoryDevice.h"

namespace etiss
{
namespace plugin
{

namespace
{

struct MapperSystem
{

    struct ETISS_System sys;

    MemoryDeviceMapper *this_;

    ETISS_System *orig;

    bool (*fastrule)(uint64_t addr, unsigned len);
};

bool empty_fastrule(uint64_t, unsigned)
{
    return false; // pass through directly
}

etiss_int32 iread_(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint32 length)
{
    MapperSystem *lsys = ((MapperSystem *)handle);
    if (lsys->fastrule(addr, length))
    {
        return lsys->this_->iread(lsys->orig, cpu, addr, length);
    }
    ETISS_System *sys = lsys->orig;
    return sys->iread(sys->handle, cpu, addr, length);
}
etiss_int32 iwrite_(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length)
{
    MapperSystem *lsys = ((MapperSystem *)handle);
    if (lsys->fastrule(addr, length))
    {
        return lsys->this_->iwrite(lsys->orig, cpu, addr, buffer, length);
    }
    ETISS_System *sys = lsys->orig;
    return sys->iwrite(sys->handle, cpu, addr, buffer, length);
}

etiss_int32 dread_(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length)
{
    MapperSystem *lsys = ((MapperSystem *)handle);
    if (lsys->fastrule(addr, length))
    {
        return lsys->this_->dread(lsys->orig, cpu, addr, buffer, length);
    }
    ETISS_System *sys = lsys->orig;
    return sys->dread(sys->handle, cpu, addr, buffer, length);
}
etiss_int32 dwrite_(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length)
{
    MapperSystem *lsys = ((MapperSystem *)handle);
    if (lsys->fastrule(addr, length))
    {
        return lsys->this_->dwrite(lsys->orig, cpu, addr, buffer, length);
    }
    ETISS_System *sys = lsys->orig;
    return sys->dwrite(sys->handle, cpu, addr, buffer, length);
}

etiss_int32 dbg_read_(void *handle, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length)
{
    MapperSystem *lsys = ((MapperSystem *)handle);
    if (lsys->fastrule(addr, length))
    {
        return lsys->this_->dbg_read(lsys->orig, addr, buffer, length);
    }
    ETISS_System *sys = lsys->orig;
    return sys->dbg_read(sys->handle, addr, buffer, length);
}

etiss_int32 dbg_write_(void *handle, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length)
{
    MapperSystem *lsys = ((MapperSystem *)handle);
    if (lsys->fastrule(addr, length))
    {
        return lsys->this_->dbg_write(lsys->orig, addr, buffer, length);
    }
    ETISS_System *sys = lsys->orig;
    return sys->dbg_write(sys->handle, addr, buffer, length);
}

void syncTime_(void *handle, ETISS_CPU *cpu)
{
    MapperSystem *lsys = ((MapperSystem *)handle);
    ETISS_System *sys = lsys->orig;
    sys->syncTime(sys->handle, cpu);
}

} // namespace

MemoryDeviceMapper::MemoryDeviceMapper(std::string name) : name_(name) {}

MemoryDeviceMapper::~MemoryDeviceMapper() {}

ETISS_System *MemoryDeviceMapper::wrap(ETISS_CPU *cpu, ETISS_System *system)
{
    MapperSystem *ret = new MapperSystem();

    ret->sys.iread = &iread_;
    ret->sys.iwrite = &iwrite_;
    ret->sys.dread = &dread_;
    ret->sys.dwrite = &dwrite_;
    ret->sys.dbg_read = &dbg_read_;
    ret->sys.dbg_write = &dbg_write_;
    ret->sys.syncTime = &syncTime_;

    ret->sys.handle = (void *)ret;

    ret->this_ = this;

    ret->orig = system;

    ret->fastrule = &empty_fastrule;

    return (ETISS_System *)ret;
}
ETISS_System *MemoryDeviceMapper::unwrap(ETISS_CPU *cpu, ETISS_System *system)
{
    ETISS_System *ret = ((MapperSystem *)system)->orig;

    delete system;

    return ret;
}

etiss::int32 MemoryDeviceMapper::iread(ETISS_System *sys, ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint32 len)
{
    while (true)
    {
        unsigned nlen = len;
        int index = map(true, true, false, addr, 0, len, nlen);
        if ((index < 0) || (index > (int)devices_.size()) || (devices_[index] == 0))
        {
            int32_t err = sys->iread(sys->handle, cpu, addr, len);
            if (err)
                return err;
        }
        else
        {
            int32_t err = devices_[index]->iread(cpu, addr, nlen);
            if (err)
                return err;
        }
        len = len - nlen;
        if (len == 0)
            return 0;
        addr += nlen;
    }
}
etiss::int32 MemoryDeviceMapper::iwrite(ETISS_System *sys, ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf,
                                        etiss::uint32 len)
{
    while (true)
    {
        unsigned nlen = len;
        int index = map(true, false, false, addr, buf, len, nlen);
        if ((index < 0) || (index > (int)devices_.size()) || (devices_[index] == 0))
        {
            int32_t err = sys->iwrite(sys->handle, cpu, addr, buf, len);
            if (err)
                return err;
        }
        else
        {
            int32_t err = devices_[index]->iwrite(cpu, addr, buf, nlen);
            if (err)
                return err;
        }
        len = len - nlen;
        if (len == 0)
            return 0;
        buf += nlen;
        addr += nlen;
    }
}
etiss::int32 MemoryDeviceMapper::dread(ETISS_System *sys, ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf,
                                       etiss::uint32 len)
{
    while (true)
    {
        unsigned nlen = len;
        int index = map(false, true, false, addr, buf, len, nlen);
        if ((index < 0) || (index > (int)devices_.size()) || (devices_[index] == 0))
        {
            int32_t err = sys->dread(sys->handle, cpu, addr, buf, len);
            if (err)
                return err;
        }
        else
        {
            int32_t err = devices_[index]->dread(cpu, addr, buf, nlen);
            if (err)
                return err;
        }
        len = len - nlen;
        if (len == 0)
            return 0;
        buf += nlen;
        addr += nlen;
    }
}
etiss::int32 MemoryDeviceMapper::dwrite(ETISS_System *sys, ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf,
                                        etiss::uint32 len)
{
    while (true)
    {
        unsigned nlen = len;
        int index = map(false, false, false, addr, buf, len, nlen);
        if ((index < 0) || (index > (int)devices_.size()) || (devices_[index] == 0))
        {
            int32_t err = sys->dwrite(sys->handle, cpu, addr, buf, len);
            if (err)
                return err;
        }
        else
        {
            int32_t err = devices_[index]->dwrite(cpu, addr, buf, nlen);
            if (err)
                return err;
        }
        len = len - nlen;
        if (len == 0)
            return 0;
        buf += nlen;
        addr += nlen;
    }
}
etiss::int32 MemoryDeviceMapper::dbg_read(ETISS_System *sys, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len)
{
    while (true)
    {
        unsigned nlen = len;
        int index = map(false, true, true, addr, buf, len, nlen);
        if ((index < 0) || (index > (int)devices_.size()) || (devices_[index] == 0))
        {
            int32_t err = sys->dbg_read(sys->handle, addr, buf, len);
            if (err)
                return err;
        }
        else
        {
            int32_t err = devices_[index]->dbg_read(addr, buf, nlen);
            if (err)
                return err;
        }
        len = len - nlen;
        if (len == 0)
            return 0;
        buf += nlen;
        addr += nlen;
    }
}
etiss::int32 MemoryDeviceMapper::dbg_write(ETISS_System *sys, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len)
{
    while (true)
    {
        unsigned nlen = len;
        int index = map(false, true, true, addr, buf, len, nlen);
        if ((index < 0) || (index > (int)devices_.size()) || (devices_[index] == 0))
        {
            int32_t err = sys->dbg_write(sys->handle, addr, buf, len);
            if (err)
                return err;
        }
        else
        {
            int32_t err = devices_[index]->dbg_write(addr, buf, nlen);
            if (err)
                return err;
        }
        len = len - nlen;
        if (len == 0)
            return 0;
        buf += nlen;
        addr += nlen;
    }
}

int MemoryDeviceMapper::map(bool ibus, bool read, bool dbg, uint64_t addr, uint8_t *buf, unsigned len, unsigned &newlen)
{
    for (unsigned i = 0; i < mountPoints_.size(); i++)
    {
        std::pair<uint64_t, uint64_t> &mp = mountPoints_[i];
        if ((addr & mp.first) == mp.second)
            return (int)i;
    }
    return -1;
}

bool MemoryDeviceMapper::mount(etiss::System *sys, uint64_t mask, uint64_t addr)
{
    if (sys == 0)
        return false;

    devices_.push_back(sys);
    mountPoints_.push_back(std::make_pair(mask, addr));

    return true;
}

} // namespace plugin
} // namespace etiss
