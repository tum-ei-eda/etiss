// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
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

static etiss_int32 gdb_system_call_iread(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint32 length)
{
    auto gdbsys = (ETISS_GDBSystem *)handle;
    etiss_int32 exc = gdbsys->sys_->iread(gdbsys->sys_->handle, cpu, addr, length);
    return gdbsys->server_->postMemAccessCallback(exc);
}
static etiss_int32 gdb_system_call_iwrite(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer,
                                          etiss_uint32 length)
{
    auto gdbsys = (ETISS_GDBSystem *)handle;
    etiss_int32 exc = gdbsys->sys_->iwrite(gdbsys->sys_->handle, cpu, addr, buffer, length);
    return gdbsys->server_->postMemAccessCallback(exc);
}

static etiss_int32 gdb_system_call_dread(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer,
                                         etiss_uint32 length)
{
    auto gdbsys = (ETISS_GDBSystem *)handle;
    gdbsys->server_->preDReadCallback(addr);
    etiss_int32 exc = gdbsys->sys_->dread(gdbsys->sys_->handle, cpu, addr, buffer, length);
    return gdbsys->server_->postMemAccessCallback(exc);
}
static etiss_int32 gdb_system_call_dwrite(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer,
                                          etiss_uint32 length)
{
    auto gdbsys = (ETISS_GDBSystem *)handle;
    gdbsys->server_->preDWriteCallback(addr);
    etiss_int32 exc = gdbsys->sys_->dwrite(gdbsys->sys_->handle, cpu, addr, buffer, length);
    return gdbsys->server_->postMemAccessCallback(exc);
}

static etiss_int32 gdb_system_call_dbg_read(void *handle, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length)
{
    ETISS_GDBSystem *gdbsys = (ETISS_GDBSystem *)handle;
    return gdbsys->sys_->dbg_read(gdbsys->sys_->handle, addr, buffer, length);
}

static etiss_int32 gdb_system_call_dbg_write(void *handle, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length)
{
    ETISS_GDBSystem *gdbsys = (ETISS_GDBSystem *)handle;
    return gdbsys->sys_->dbg_write(gdbsys->sys_->handle, addr, buffer, length);
}

static etiss_int32 gdb_system_call_syncTime(void *handle, ETISS_CPU *cpu)
{
    ETISS_GDBSystem *gdbsys = (ETISS_GDBSystem *)handle;
    return gdbsys->sys_->syncTime(gdbsys->sys_->handle, cpu);
}

ETISS_System *Server::wrap(ETISS_CPU *cpu, ETISS_System *sys)
{
    if (sys == 0)
        return 0;

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
