/*

        @copyright

        <pre>

        Copyright 2018 Chair of Electronic Design Automation, TUM

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

#include "RV64GCVTimer.h"
#include "Encoding.h"
#include "etiss/CPUArch.h"

static etiss_int32 iread(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint32 length)
{
    RV64GCVTimerSystem *lsys = ((RV64GCVTimerSystem *)handle);
    ETISS_System *sys = lsys->orig;
    return sys->iread(sys->handle, cpu, addr, length);
}

static etiss_int32 iwrite(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length)
{
    RV64GCVTimerSystem *lsys = ((RV64GCVTimerSystem *)handle);
    ETISS_System *sys = lsys->orig;
    return sys->iwrite(sys->handle, cpu, addr, buffer, length);
}

etiss_int32 dread(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length)
{
    RV64GCVTimerSystem *lsys = ((RV64GCVTimerSystem *)handle);
    char *mtime_buf;
    switch (addr & 0xfffffff0)
    {
    case MTIME_ADDR:
        mtime_buf = (char *)(&(lsys->this_->mtime_));
        memcpy(buffer, mtime_buf + (addr & 0x7), length);
        break;
    case MTIMECMP_ADDR:

        break;
    default:

        ETISS_System *sys = lsys->orig;
        return sys->dread(sys->handle, cpu, addr, buffer, length);
    }
    return etiss::RETURNCODE::NOERROR;
}

static etiss_int32 dwrite(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length)
{
    RV64GCVTimerSystem *lsys = ((RV64GCVTimerSystem *)handle);
    switch (addr & 0xfffffff0)
    {
    case MTIME_ADDR:
        break;

    case MTIMECMP_ADDR:
        memcpy(lsys->this_->mtimecmp_buf_ + (addr & 0x7), buffer, length);
        break;

    default:
        ETISS_System *sys = lsys->orig;
        return sys->dwrite(sys->handle, cpu, addr, buffer, length);
    }
    return etiss::RETURNCODE::NOERROR;
}

static etiss_int32 dbg_read(void *handle, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length)
{
    RV64GCVTimerSystem *lsys = ((RV64GCVTimerSystem *)handle);
    char *mtime_buf;
    switch (addr & 0xfffffff0)
    {
    case MTIME_ADDR:
        mtime_buf = (char *)(&(lsys->this_->mtime_));
        memcpy(buffer, mtime_buf + (addr & 0x7), length);
        break;

    case MTIMECMP_ADDR:
        break;

    default:
        ETISS_System *sys = lsys->orig;
        return sys->dbg_read(sys->handle, addr, buffer, length);
    }
    return etiss::RETURNCODE::NOERROR;
}

static etiss_int32 dbg_write(void *handle, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length)
{
    RV64GCVTimerSystem *lsys = ((RV64GCVTimerSystem *)handle);
    switch (addr & 0xfffffff0)
    {
    case MTIME_ADDR:
        break;

    case MTIMECMP_ADDR:
        memcpy(lsys->this_->mtimecmp_buf_ + (addr & 0x7), buffer, length);
        break;

    default:
        ETISS_System *sys = lsys->orig;
        return sys->dbg_write(sys->handle, addr, buffer, length);
    }
    return etiss::RETURNCODE::NOERROR;
}

static void syncTime(void *handle, ETISS_CPU *cpu)
{
    RV64GCVTimerSystem *lsys = ((RV64GCVTimerSystem *)handle);
    ETISS_System *sys = lsys->orig;
    sys->syncTime(sys->handle, cpu);
}

RV64GCVTimer::RV64GCVTimer()
    : mtime_(0)
    , mtimecmp_(0)
    , timer_enabled_(false)
    , mtimecmp_overflow_clear_(false)
    , mtimecmp_overflow_(false)
    , mtime_overflow_(false)
{

    memset(mtimecmp_buf_, 0, 8);
}

etiss::int32 RV64GCVTimer::execute()
{

    etiss::uint64 new_mtime = ((ETISS_CPU *)riscv64cpu)->cpuTime_ps / ((ETISS_CPU *)riscv64cpu)->cpuCycleTime_ps;
    mtime_overflow_ = (new_mtime < mtime_) ? true : false;
    mtime_ = new_mtime;

    if (mtimecmp_buf_[0])
    {

        if (!timer_enabled_)
            timer_enabled_ = true;
        etiss::uint64 new_mtimecmp = *((etiss::uint64 *)mtimecmp_buf_);
        bool mtimecmp_overflow_val = (new_mtimecmp < mtimecmp_) ? true : false;
        if (mtimecmp_overflow_val)
        {
            if (mtimecmp_overflow_clear_)
            {
                mtimecmp_overflow_clear_ = false;
            }
            else
                mtimecmp_overflow_ = mtimecmp_overflow_val;
        }
        mtimecmp_ = new_mtimecmp;
        memset(mtimecmp_buf_, 0, 8);
        std::stringstream ss;
        ss << "Current time: 0x" << std::hex << mtime_ << std::endl;
        ss << "New timecmp value: 0x" << std::hex << mtimecmp_ << std::endl;
        etiss::log(etiss::VERBOSE, ss.str());
    }

    if (!timer_enabled_)
        return etiss::RETURNCODE::NOERROR;

    if (mtimecmp_overflow_ && !mtime_overflow_)
    {
        return etiss::RETURNCODE::NOERROR;
    }
    else if (mtime_ >= mtimecmp_ || (!mtimecmp_overflow_ && mtime_overflow_))
    {
        (riscv64cpu->CSR[CSR_MIP]) |= MIP_MTIP;

        if (mtimecmp_overflow_)
        {
            mtime_overflow_ = false;
            if (mtimecmp_overflow_)
                mtimecmp_overflow_ = false;
            else
                mtimecmp_overflow_clear_ = true;
        }
        return etiss::RETURNCODE::INTERRUPT;
    }
    return etiss::RETURNCODE::NOERROR;
}

ETISS_System *RV64GCVTimer::wrap(ETISS_CPU *cpu, ETISS_System *system)
{

    RV64GCVTimerSystem *ret = new RV64GCVTimerSystem();

    ret->sys.iread = &iread;
    ret->sys.iwrite = &iwrite;
    ret->sys.dread = &dread;
    ret->sys.dwrite = &dwrite;
    ret->sys.dbg_read = &dbg_read;
    ret->sys.dbg_write = &dbg_write;
    ret->sys.syncTime = &syncTime;

    ret->sys.handle = (void *)ret;

    ret->this_ = this;

    ret->orig = system;

    return (ETISS_System *)ret;
}

ETISS_System *RV64GCVTimer::unwrap(ETISS_CPU *cpu, ETISS_System *system)
{

    ETISS_System *ret = ((RV64GCVTimerSystem *)system)->orig;

    delete (RV64GCVTimerSystem *)system;

    return ret;
}
