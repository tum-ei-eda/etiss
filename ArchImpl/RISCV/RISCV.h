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
// This file was generated on Mon Apr 27 14:33:22 CEST 2020
// If necessary please modify this file according to the instructions
// Contact: eda@tum

#ifndef ETISS_RISCVArch_RISCV_H_
#define ETISS_RISCVArch_RISCV_H_
#include <stdio.h>
#include "etiss/jit/CPU.h"

#ifdef __cplusplus
extern "C" {
#endif
#pragma pack(push, 1) 
struct RISCV {
	ETISS_CPU cpu; // original cpu struct must be defined as the first field of the new structure. this allows to cast X * to ETISS_CPU * and vice vers
	etiss_uint32 ZERO;
	etiss_uint32 RA;
	etiss_uint32 SP;
	etiss_uint32 GP;
	etiss_uint32 TP;
	etiss_uint32 T0;
	etiss_uint32 T1;
	etiss_uint32 T2;
	etiss_uint32 S0;
	etiss_uint32 S1;
	etiss_uint32 A0;
	etiss_uint32 A1;
	etiss_uint32 A2;
	etiss_uint32 A3;
	etiss_uint32 A4;
	etiss_uint32 A5;
	etiss_uint32 A6;
	etiss_uint32 A7;
	etiss_uint32 S2;
	etiss_uint32 S3;
	etiss_uint32 S4;
	etiss_uint32 S5;
	etiss_uint32 S6;
	etiss_uint32 S7;
	etiss_uint32 S8;
	etiss_uint32 S9;
	etiss_uint32 S10;
	etiss_uint32 S11;
	etiss_uint32 T3;
	etiss_uint32 T4;
	etiss_uint32 T5;
	etiss_uint32 T6;
	etiss_uint32 *X[32];
	etiss_uint32 ins_X[32];
	etiss_uint64 F[32];
	etiss_uint32 FCSR;
	etiss_uint32 CSR[4096];
	etiss_uint32 FENCE[4];
	etiss_uint32 RES;
	etiss_uint32 SSTATUS;
	etiss_uint32 *MSTATUS;
	etiss_uint32 ins_MSTATUS;
	etiss_uint32 SIE;
	etiss_uint32 *MIE;
	etiss_uint32 ins_MIE;
	etiss_uint32 SIP;
	etiss_uint32 *MIP;
	etiss_uint32 ins_MIP;
	etiss_uint32 MTVEC;
	etiss_uint32 MEPC;
	etiss_uint32 MCAUSE;
	etiss_uint32 MISA;
	etiss_uint32 MHARTID;
	etiss_uint32 MSCRATCH;
	etiss_uint32 MTVAL;
	etiss_uint32 MEDELEG;
	etiss_uint32 MIDELEG;
	etiss_uint32 PMPADDR0;
	etiss_uint32 PMPCFG0;
	etiss_uint32 MCOUNTEREN;
	etiss_uint32 STVEC;
	etiss_uint32 SEPC;
	etiss_uint32 SCAUSE;
	etiss_uint32 SSCRATCH;
	etiss_uint32 STVAL;
	etiss_uint32 SATP;
	etiss_uint32 SCOUNTEREN;
	etiss_uint32 VSTART;
	etiss_uint32 VXSAT;
	etiss_uint32 VXRM;
	etiss_uint32 VL;
	etiss_uint32 VTYPE;
	etiss_uint32 V[32];
	etiss_uint32 PCCRs[32];
	etiss_uint32 PCER;
	etiss_uint32 PCMR;
	etiss_uint32 HWLP[8];
	etiss_uint32 UHARTID;
	etiss_uint32 PRIVLV;
};

#pragma pack(pop) // undo changes
typedef struct RISCV RISCV; // convenient use of X instead of struct X in generated C code
#ifdef __cplusplus
} // extern "C"
#endif
#endif

