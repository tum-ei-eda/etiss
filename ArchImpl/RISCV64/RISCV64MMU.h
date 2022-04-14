/*

        @copyright

        <pre>

        Copyright 2018 Chair of Electronic Design Automation, TUM

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

#ifndef ETISS_RISCV64Arch_RISCV64MMU_H_
#define ETISS_RISCV64Arch_RISCV64MMU_H_

#include "Encoding.h"
#include "RISCV64.h"

#include "etiss/mm/MMU.h"
#include "etiss/mm/PTE.h"

using namespace etiss::mm;

int32_t tlb_overlap_handler(int32_t fault, etiss::mm::MMU *mmu, uint64_t vma, etiss::mm::MM_ACCESS access);

class RISCV64MMU : public etiss::mm::MMU
{

  public:
    RISCV64MMU(bool pid_enabled);

    ~RISCV64MMU() {}
  
    void SignalMMU(uint64_t control_reg_val_);

  private:
    int32_t WalkPageTable(uint64_t vma, etiss::mm::MM_ACCESS access);

    int32_t CheckProtection(const PTE &pte, etiss::mm::MM_ACCESS access);

    void UpdatePTEFlags(PTE &pte, etiss::mm::MM_ACCESS access) {}

    bool CheckPrivilegedMode() { return (((RISCV64 *)cpu_)->CSR[3088] == PRV_M) ? false : true; }

    int32_t CheckPageOverlap(const uint64_t vma, uint64_t *const pma_buf, MM_ACCESS access, etiss_uint32 length);
};

#endif
