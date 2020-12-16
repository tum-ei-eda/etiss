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

#include "etiss/FastMemory.h"
#include "etiss/jit/ReturnCode.h"
#include <cstring>

static etiss_int32 system_call_iread(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint32 length)
{
    return 0;
}
static etiss_int32 system_call_iwrite(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer,
                                      etiss_uint32 length)
{
    return etiss::RETURNCODE::IBUS_WRITE_ERROR;
}

static etiss_int32 system_call_dread(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer,
                                     etiss_uint32 length)
{
    memcpy(buffer, ((uint8_t *)handle) + (size_t)addr, length);
    return 0;
}
static etiss_int32 system_call_dwrite(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer,
                                      etiss_uint32 length)
{
    memcpy(((uint8_t *)handle) + (size_t)addr, buffer, length);
    return 0;
}

static etiss_int32 system_call_dbg_read(void *handle, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length)
{
    memcpy(buffer, ((uint8_t *)handle) + (size_t)addr, length);
    return 0;
}

static etiss_int32 system_call_dbg_write(void *handle, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length)
{
    memcpy(((uint8_t *)handle) + (size_t)addr, buffer, length);
    return 0;
}

static void system_call_syncTime(void *handle, ETISS_CPU *cpu) {}

std::shared_ptr<ETISS_System> etiss::createFastMemory(size_t size)
{
    auto ret = std::make_shared<ETISS_System>();

    ret->iread = &system_call_iread;
    ret->iwrite = &system_call_iwrite;

    ret->dread = &system_call_dread;
    ret->dwrite = &system_call_dwrite;

    ret->dbg_read = &system_call_dbg_read;
    ret->dbg_write = &system_call_dbg_write;

    ret->syncTime = &system_call_syncTime;

    ret->handle = new uint8_t[size];

    return ret;
}
