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

        @brief cpu data structure for an or1k processor

        @detail

*/
#ifndef ETISS_OR1KArch_OR1K_H_
#define ETISS_OR1KArch_OR1K_H_
#include "etiss/jit/CPU.h"
#include "etiss/pluginexport.h"

#ifdef __cplusplus
extern "C"
{
#endif

    const static etiss_uint32 OR1K_RESETEXCEPTION = 0x01000000;
    const static etiss_uint32 OR1K_BUSEXCEPTION = 0x02000000;
    const static etiss_uint32 OR1K_DATAPAGEFAULTEXCEPTION = 0x03000000;
    const static etiss_uint32 OR1K_INSTRUCTIONPAGEFAULTEXCEPTION = 0x04000000;
    const static etiss_uint32 OR1K_TICKTIMEREXCEPTION = 0x05000000;
    const static etiss_uint32 OR1K_ALIGNMENTEXCEPTION = 0x06000000;
    const static etiss_uint32 OR1K_ILLEGALINSTRUCTIONEXCEPTION = 0x07000000;
    const static etiss_uint32 OR1K_EXTERNALINTERRUPTEXCEPTION = 0x08000000;
    const static etiss_uint32 OR1K_DTLBMISSEXCEPTION = 0x09000000;
    const static etiss_uint32 OR1K_ITLBMISSEXCEPTION = 0x0A000000;
    const static etiss_uint32 OR1K_RANGEEXCEPTION = 0x0B000000;
    const static etiss_uint32 OR1K_SYSTEMCALLEXCEPTION = 0x0C000000;
    const static etiss_uint32 OR1K_FLOATINGPOINTEXCEPTION = 0x0D000000;
    const static etiss_uint32 OR1K_TRAPEXCEPTION = 0x0E000000;

#pragma pack(push, 1)
    struct OR1K
    {

        ETISS_CPU cpu;

        etiss_uint64 instructionPointer_delayed;

        // current general purpose register (use for shadowing)
        etiss_uint32 *R;

        // main general purpose registers
        etiss_uint32 GPR[17][32];

        // special purpose register
        etiss_uint32 SPR[1 << 5][1 << 11];

        etiss_uint32 *VR;       // SPR[0][0]
        etiss_uint32 *UPR;      // SPR[0][1]
        etiss_uint32 *CPUCFGR;  // SPR[0][2]
        etiss_uint32 *DMMUCFGR; // SPR[0][3]
        etiss_uint32 *IMMUCFGR; // SPR[0][4]
        etiss_uint32 *DCCFGR;   // SPR[0][5]
        etiss_uint32 *ICCFGR;   // SPR[0][6]
        etiss_uint32 *DCFGR;    // SPR[0][7]
        etiss_uint32 *PCCFGR;   // SPR[0][8]
        etiss_uint32 *VR2;      // SPR[0][9]
        etiss_uint32 *AVR;      // SPR[0][10]
        etiss_uint32 *EVBAR;    // SPR[0][11]
        etiss_uint32 *AECR;     // SPR[0][12]
        etiss_uint32 *AESR;     // SPR[0][13]

        etiss_uint32 *NPC; // SPR[0][16]
        etiss_uint32 *SR;  // SPR[0][17]
        etiss_uint32 *PPC; // SPR[0][18]

        etiss_uint32 *FPCSR; // SPR[0][20]
        etiss_uint32 *ISR_8; // SPR[0][21]

        etiss_uint32 *EPCR_16; // SPR[0][32]

        etiss_uint32 *EEAR_16; // SPR[0][48]

        etiss_uint32 *ESR_16; // SPR[0][64]

        etiss_uint32 *GPR_512; // SPR[0][1024]

        etiss_uint32 *MACLO; // SPR[5][1]
        etiss_uint32 *MACHI; // SPR[5][2]

        etiss_uint32 *TTMR; // SPR[10][0]
        etiss_uint32 *TTCR; // SPR[10][1]

        etiss_uint32 *FPMADDHI; // SPR[11][0] //! index officially not defined as 0
        etiss_uint32 *FPMADDLO; // SPR[11][1] //! index officially not defined as 1

        // pc register
        etiss_uint64 *PC;

        etiss_uint32 exceptionDepth;
    };
#pragma pack(pop)

    typedef struct OR1K OR1K;

    extern ETISS_PLUGIN_EXPORT etiss_uint32 OR1KArch_mfspr(OR1K *cpu, etiss_uint32 id);
    extern ETISS_PLUGIN_EXPORT void OR1KArch_mtspr(OR1K *cpu, etiss_uint32 id, etiss_uint32 value);
    extern ETISS_PLUGIN_EXPORT etiss_uint32 OR1K_reset_stopwatch(ETISS_CPU *cpu);

    extern ETISS_PLUGIN_EXPORT etiss_int32 OR1KArch_mul32(OR1K *cpu, etiss_uint8 rDindex, etiss_uint32 ra,
                                                          etiss_uint32 rb);

    extern ETISS_PLUGIN_EXPORT void OR1KArch_apply_fpu_flags(OR1K *cpu, unsigned flags);

    extern ETISS_PLUGIN_EXPORT void OR1K_printchar(char c);
    extern ETISS_PLUGIN_EXPORT void OR1K_report(uint32_t c);
    extern ETISS_PLUGIN_EXPORT void OR1K_print(char *c);
    extern ETISS_PLUGIN_EXPORT void OR1K_printtime(ETISS_CPU *);

    const static etiss_uint32 OR1K_SR_SM = 1 << 0;
    const static etiss_uint32 OR1K_SR_TEE = 1 << 1;
    const static etiss_uint32 OR1K_SR_IEE = 1 << 2;
    const static etiss_uint32 OR1K_SR_DCE = 1 << 3;
    const static etiss_uint32 OR1K_SR_ICE = 1 << 4;
    const static etiss_uint32 OR1K_SR_DME = 1 << 5;
    const static etiss_uint32 OR1K_SR_IME = 1 << 6;
    const static etiss_uint32 OR1K_SR_LEE = 1 << 7;
    const static etiss_uint32 OR1K_SR_CE = 1 << 8;
    const static etiss_uint32 OR1K_SR_F = 1 << 9;
    const static etiss_uint32 OR1K_SR_CY = 1 << 10;
    const static etiss_uint32 OR1K_SR_OV = 1 << 11;
    const static etiss_uint32 OR1K_SR_OVE = 1 << 12;
    const static etiss_uint32 OR1K_SR_DSX = 1 << 13;
    const static etiss_uint32 OR1K_SR_EPH = 1 << 14;
    const static etiss_uint32 OR1K_SR_FO = 1 << 15;

    const static etiss_uint32 OR1K_CPUCFGR_NSGF = 1 << 0 | 1 << 1 | 1 << 2 | 1 << 3;
    const static etiss_uint32 OR1K_CPUCFGR_CGF = 1 << 4;
    const static etiss_uint32 OR1K_CPUCFGR_OB32S = 1 << 5;
    const static etiss_uint32 OR1K_CPUCFGR_OB64S = 1 << 6;
    const static etiss_uint32 OR1K_CPUCFGR_OF32S = 1 << 7;
    const static etiss_uint32 OR1K_CPUCFGR_OF64S = 1 << 8;
    const static etiss_uint32 OR1K_CPUCFGR_OV64S = 1 << 9;
    const static etiss_uint32 OR1K_CPUCFGR_ND = 1 << 10;
    const static etiss_uint32 OR1K_CPUCFGR_AVPR = 1 << 11;
    const static etiss_uint32 OR1K_CPUCFGR_EVBARP = 1 << 12;
    const static etiss_uint32 OR1K_CPUCFGR_ISRP = 1 << 13;
    const static etiss_uint32 OR1K_CPUCFGR_AECSRP = 1 << 14;

    const static etiss_uint32 OR1K_AECR_CYADDE = 1 << 0;
    const static etiss_uint32 OR1K_AECR_OVADDE = 1 << 1;
    const static etiss_uint32 OR1K_AECR_CYMULE = 1 << 2;
    const static etiss_uint32 OR1K_AECR_OVMULE = 1 << 3;
    const static etiss_uint32 OR1K_AECR_DBZE = 1 << 4;
    const static etiss_uint32 OR1K_AECR_CYMACADDE = 1 << 5;
    const static etiss_uint32 OR1K_AECR_OVMACADDE = 1 << 6;

    const static etiss_uint32 OR1K_FPCSR_FPEE = 1 << 0;
    const static etiss_uint32 OR1K_FPCSR_RM_0 = 1 << 1;
    const static etiss_uint32 OR1K_FPCSR_RM_1 = 1 << 2;
    const static etiss_uint32 OR1K_FPCSR_OVF = 1 << 3;
    const static etiss_uint32 OR1K_FPCSR_UNF = 1 << 4;
    const static etiss_uint32 OR1K_FPCSR_SNF = 1 << 5;
    const static etiss_uint32 OR1K_FPCSR_QNF = 1 << 6;
    const static etiss_uint32 OR1K_FPCSR_ZF = 1 << 7;
    const static etiss_uint32 OR1K_FPCSR_IXF = 1 << 8;
    const static etiss_uint32 OR1K_FPCSR_IVF = 1 << 9;
    const static etiss_uint32 OR1K_FPCSR_INF = 1 << 10;
    const static etiss_uint32 OR1K_FPCSR_DZF = 1 << 11;

#ifdef __cplusplus
}
#endif

#endif
