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

        @author Aote Jin <aote.jin@tum.de>, Chair of Electronic Design Automation, TUM

        @date June 24, 2018

        @version 0.1

*/
/**
        @file

        @brief Wrapper class to wrap aroud data MMU


*/

#include "etiss/mm/DMMUWrapper.h"

namespace etiss
{
namespace mm
{

static etiss_int32 iread(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint32 length)
{

    int32_t exception;
    DMMUWrapperSystem *msys = ((DMMUWrapperSystem *)handle);
    std::shared_ptr<MMU> mmu = ((DMMUWrapper *)msys->this_)->mmu_;

    // vma to pma translation
    uint64_t pma = 0;
    if (unlikely(exception = mmu->Translate(addr, &pma, MM_ACCESS::R_ACCESS)))
        return exception;
    std::stringstream msg;
    msg << "Virtual memory: 0x" << std::hex << addr << " is translated into physical address 0x:" << std::hex << pma
        << std::endl;
    etiss::log(etiss::VERBOSE, msg.str());
    ETISS_System *sys = msys->orig;
    return sys->iread(sys->handle, cpu, pma, length);
}

static etiss_int32 iwrite(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length)
{

    int32_t exception;
    DMMUWrapperSystem *msys = ((DMMUWrapperSystem *)handle);
    std::shared_ptr<MMU> mmu = ((DMMUWrapper *)msys->this_)->mmu_;

    // vma to pma translation
    uint64_t pma = 0;
    if (unlikely(exception = mmu->Translate(addr, &pma, MM_ACCESS::W_ACCESS)))
        return exception;
    std::stringstream msg;
    msg << "Virtual memory: 0x" << std::hex << addr << " is translated into physical address 0x:" << std::hex << pma
        << std::endl;
    etiss::log(etiss::VERBOSE, msg.str());
    ETISS_System *sys = msys->orig;
    return sys->iwrite(sys->handle, cpu, pma, buffer, length);
}

static etiss_int32 dread(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length)
{

    int32_t exception;
    DMMUWrapperSystem *msys = ((DMMUWrapperSystem *)handle);
    std::shared_ptr<MMU> mmu = ((DMMUWrapper *)msys->this_)->mmu_;

    // vma to pma translation
    uint64_t pma = 0;
    if (unlikely(exception = mmu->Translate(addr, &pma, MM_ACCESS::R_ACCESS)))
        return exception;
    std::stringstream msg;

    ETISS_System *sys = msys->orig;
    return sys->dread(sys->handle, cpu, pma, buffer, length);
}

static etiss_int32 dwrite(void *handle, ETISS_CPU *cpu, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length)
{

    int32_t exception;
    DMMUWrapperSystem *msys = ((DMMUWrapperSystem *)handle);
    std::shared_ptr<MMU> mmu = ((DMMUWrapper *)msys->this_)->mmu_;

    // vma to pma translation
    uint64_t pma = 0;
    if (unlikely(exception = mmu->Translate(addr, &pma, MM_ACCESS::W_ACCESS)))
        return exception;
    std::stringstream msg;

    ETISS_System *sys = msys->orig;
    return sys->dwrite(sys->handle, cpu, pma, buffer, length);
}

static etiss_int32 dbg_read(void *handle, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length)
{

    int32_t exception;
    DMMUWrapperSystem *msys = ((DMMUWrapperSystem *)handle);
    std::shared_ptr<MMU> mmu = ((DMMUWrapper *)msys->this_)->mmu_;

    // vma to pma translation
    uint64_t pma = 0;
    if (unlikely(exception = mmu->Translate(addr, &pma, MM_ACCESS::X_ACCESS)))
        return etiss::RETURNCODE::PAGEFAULT;

    ETISS_System *sys = msys->orig;
    return sys->dbg_read(sys->handle, pma, buffer, length);
}

static etiss_int32 dbg_write(void *handle, etiss_uint64 addr, etiss_uint8 *buffer, etiss_uint32 length)
{

    int32_t exception;
    DMMUWrapperSystem *msys = ((DMMUWrapperSystem *)handle);
    std::shared_ptr<MMU> mmu = ((DMMUWrapper *)msys->this_)->mmu_;

    // vma to pma translation
    uint64_t pma = 0;
    if (unlikely(exception = mmu->Translate(addr, &pma, MM_ACCESS::W_ACCESS)))
        return exception;
    std::stringstream msg;
    msg << "Virtual memory: 0x" << std::hex << addr << " is translated into physical address 0x:" << std::hex << pma
        << std::endl;
    etiss::log(etiss::VERBOSE, msg.str());
    ETISS_System *sys = msys->orig;
    return sys->dbg_write(sys->handle, pma, buffer, length);
}

static void syncTime(void *handle, ETISS_CPU *cpu)
{
    DMMUWrapperSystem *msys = ((DMMUWrapperSystem *)handle);
    ETISS_System *sys = msys->orig;
    sys->syncTime(sys->handle, cpu);
}

DMMUWrapper::DMMUWrapper(std::shared_ptr<MMU> mmu) : mmu_(mmu) {}

/**
        @brief SystemWrapperPlugin interface to wrap around original ETISS_System
*/
ETISS_System *DMMUWrapper::wrap(ETISS_CPU *cpu, ETISS_System *system)
{

    mmu_->Init(cpu, system);

    DMMUWrapperSystem *ret = new DMMUWrapperSystem();

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

/**
        @brief SystemWrapperPlugin interface to unwrap original ETISS_System
*/
ETISS_System *DMMUWrapper::unwrap(ETISS_CPU *cpu, ETISS_System *system)
{
    ETISS_System *ret = ((DMMUWrapperSystem *)system)->orig;
    delete system;
    return ret;
}

std::string DMMUWrapper::_getPluginName() const
{
    return mmu_->GetName() + std::string(" Wrapper");
}

} // namespace mm
} // namespace etiss
