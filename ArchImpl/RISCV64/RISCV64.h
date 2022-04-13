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
// This file was generated on Fri Jun 05 09:11:00 CEST 2020
// If necessary please modify this file according to the instructions
// Contact: eda@tum

#ifndef ETISS_RISCV64Arch_RISCV64_H_
#define ETISS_RISCV64Arch_RISCV64_H_
#include <stdio.h>
#include "etiss/jit/CPU.h"
#include "etiss/jit/System.h"

#ifdef __cplusplus
extern "C" {
#endif
#pragma pack(push, 1)
struct RISCV64 {
	ETISS_CPU cpu; // original cpu struct must be defined as the first field of the new structure. this allows to cast X * to ETISS_CPU * and vice vers
	etiss_uint64 ZERO;
	etiss_uint64 RA;
	etiss_uint64 SP;
	etiss_uint64 GP;
	etiss_uint64 TP;
	etiss_uint64 T0;
	etiss_uint64 T1;
	etiss_uint64 T2;
	etiss_uint64 S0;
	etiss_uint64 S1;
	etiss_uint64 A0;
	etiss_uint64 A1;
	etiss_uint64 A2;
	etiss_uint64 A3;
	etiss_uint64 A4;
	etiss_uint64 A5;
	etiss_uint64 A6;
	etiss_uint64 A7;
	etiss_uint64 S2;
	etiss_uint64 S3;
	etiss_uint64 S4;
	etiss_uint64 S5;
	etiss_uint64 S6;
	etiss_uint64 S7;
	etiss_uint64 S8;
	etiss_uint64 S9;
	etiss_uint64 S10;
	etiss_uint64 S11;
	etiss_uint64 T3;
	etiss_uint64 T4;
	etiss_uint64 T5;
	etiss_uint64 T6;
	etiss_uint64 *X[32];
	etiss_uint64 ins_X[32];
	etiss_uint64 F[32];
	etiss_uint32 FCSR;
	etiss_uint64 CSR[4096];
	etiss_uint64 FENCE[4];
	etiss_uint64 RES;
};

#pragma pack(pop) // undo changes
typedef struct RISCV64 RISCV64; // convenient use of X instead of struct X in generated C code

// manually added
extern int32_t ETISS_SIGNAL_MMU(ETISS_CPU *cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint64 mmu_signal_);
extern int32_t ETISS_TLB_FLUSH(ETISS_CPU *cpu, ETISS_System * const system, void * const * const plugin_pointers);

#ifdef __cplusplus
} // extern "C"
#endif
#endif

