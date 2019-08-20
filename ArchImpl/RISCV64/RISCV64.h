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

// This file was generated on Thu Jul 12 13:49:55 CEST 2018
// If necessary please modify this file according to the instructions
// Contact: eda@tum

#ifndef ETISS_RISCV64Arch_RISCV64_H_
#define ETISS_RISCV64Arch_RISCV64_H_
#include "etiss/jit/CPU.h"
#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif
#pragma pack(push, 1)
    struct RISCV64
    {
        ETISS_CPU cpu; // original cpu struct must be defined as the first field of the new structure. this allows to
                       // cast X * to ETISS_CPU * and vice vers
        etiss_uint64 RA;
        etiss_uint64 SP;
        etiss_uint64 GP;
        etiss_uint64 TP;
        etiss_uint64 *R[32];
        etiss_uint64 ins_R[32];
        etiss_uint64 SSTATUS;
        etiss_uint64 *MSTATUS;
        etiss_uint64 ins_MSTATUS;
        etiss_uint64 SIE;
        etiss_uint64 *MIE;
        etiss_uint64 ins_MIE;
        etiss_uint64 SIP;
        etiss_uint64 *MIP;
        etiss_uint64 ins_MIP;
        etiss_uint64 MTVEC;
        etiss_uint64 MEPC;
        etiss_uint64 MCAUSE;
        etiss_uint64 MISA;
        etiss_uint64 MHARTID;
        etiss_uint64 MSCRATCH;
        etiss_uint64 MTVAL;
        etiss_uint64 MEDELEG;
        etiss_uint64 MIDELEG;
        etiss_uint64 PMPADDR0;
        etiss_uint64 PMPCFG0;
        etiss_uint64 MCOUNTEREN;
        etiss_uint64 STVEC;
        etiss_uint64 SEPC;
        etiss_uint64 SCAUSE;
        etiss_uint64 SSCRATCH;
        etiss_uint64 STVAL;
        etiss_uint64 SATP;
        etiss_uint64 SCOUNTEREN;
        etiss_uint64 PCCRs[32];
        etiss_uint64 PCER;
        etiss_uint64 PCMR;
        etiss_uint64 HWLP[8];
        etiss_uint64 UHARTID;
        etiss_uint64 PRIVLV;
    };

#pragma pack(pop)                   // undo changes
    typedef struct RISCV64 RISCV64; // convenient use of X instead of struct X in generated C code

    // Manually added
    extern void ETISS_SIGNAL_MMU(ETISS_CPU *cpu, etiss_uint64 mmu_signal_);

#ifdef __cplusplus
} // extern "C"
#endif
#endif
