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

        @brief implements a ETISS_System wrapper to enable breakpoints

        @detail

*/
#include <stdlib.h>

#include "etiss/IntegratedLibrary/gdb/GDBServer.h"

using namespace etiss::plugin::gdb;

struct ETISS_GDBSystem
{

    struct ETISS_System system;

    ETISS_System *sys_;

    etiss::plugin::gdb::Server *server_;
};

typedef struct ETISS_GDBSystem ETISS_GDBSystem;

etiss_int32 gdb_system_call_iread(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint32 length)
{
    ETISS_GDBSystem *gdbsys = ((ETISS_GDBSystem *)handle);
    ETISS_System *sys = gdbsys->sys_;
    etiss::int32 exception = gdbsys->server_->preMemoryAccessCallback(addr, length, false, true);
    if (unlikely(exception != 0))
    {
        return exception;
    }
    return sys->iread(sys->handle, cpu, addr, length);
}
etiss_int32 gdb_system_call_iwrite(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer,
                                   etiss_uint32 length)
{
    ETISS_GDBSystem *gdbsys = ((ETISS_GDBSystem *)handle);
    ETISS_System *sys = gdbsys->sys_;
    etiss::int32 exception = gdbsys->server_->preMemoryAccessCallback(addr, length, false, false);
    if (unlikely(exception != 0))
    {
        return exception;
    }
    return sys->iwrite(sys->handle, cpu, addr, buffer, length);
}

etiss_int32 gdb_system_call_dread(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer,
                                  etiss_uint32 length)
{
    ETISS_GDBSystem *gdbsys = ((ETISS_GDBSystem *)handle);
    ETISS_System *sys = gdbsys->sys_;
    etiss::int32 exception = gdbsys->server_->preMemoryAccessCallback(addr, length, true, true);
    if (unlikely(exception != 0))
    {
        return exception;
    }
    return sys->dread(sys->handle, cpu, addr, buffer, length);
}
etiss_int32 gdb_system_call_dwrite(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer,
                                   etiss_uint32 length)
{
    ETISS_GDBSystem *gdbsys = ((ETISS_GDBSystem *)handle);
    ETISS_System *sys = gdbsys->sys_;
    etiss::int32 exception = gdbsys->server_->preMemoryAccessCallback(addr, length, true, false);
    if (unlikely(exception != 0))
    {
        return exception;
    }
    return sys->dwrite(sys->handle, cpu, addr, buffer, length);
}

etiss_int32 gdb_system_call_dbg_read(void *handle, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length)
{
    ETISS_GDBSystem *gdbsys = ((ETISS_GDBSystem *)handle);
    ETISS_System *sys = gdbsys->sys_;
    return sys->dbg_read(sys->handle, addr, buffer, length);
}

etiss_int32 gdb_system_call_dbg_write(void *handle, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length)
{
    ETISS_GDBSystem *gdbsys = ((ETISS_GDBSystem *)handle);
    ETISS_System *sys = gdbsys->sys_;
    return sys->dbg_write(sys->handle, addr, buffer, length);
}

void gdb_system_call_syncTime(void *handle, ETISS_CPU *cpu)
{
    ETISS_GDBSystem *gdbsys = ((ETISS_GDBSystem *)handle);
    ETISS_System *sys = gdbsys->sys_;
    sys->syncTime(sys->handle, cpu);
}

ETISS_System *Server::wrap(ETISS_CPU *cpu, ETISS_System *sys)
{

    if (sys == 0)
        return 0;

    // return sys;

    ETISS_GDBSystem *ret = new ETISS_GDBSystem();

    ETISS_System *retsys = (ETISS_System *)ret;

    retsys->iread = gdb_system_call_iread;
    retsys->iwrite = gdb_system_call_iwrite;

    retsys->dread = gdb_system_call_dread;
    retsys->dwrite = gdb_system_call_dwrite;

    retsys->dbg_read = gdb_system_call_dbg_read;
    retsys->dbg_write = gdb_system_call_dbg_write;

    retsys->syncTime = gdb_system_call_syncTime;

    retsys->handle = (void *)ret;

    ret->server_ = this;

    ret->sys_ = sys;
    unwrappedSys_ = sys;

    return (ETISS_System *)ret;
}

ETISS_System *Server::unwrap(ETISS_CPU *cpu, ETISS_System *system)
{
    ETISS_GDBSystem *ret = (ETISS_GDBSystem *)system;
    system = ret->sys_;
    delete ret;
    return system;
}
