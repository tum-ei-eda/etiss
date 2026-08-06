/**
 * Generated on Thu, 06 Aug 2026 12:56:16 +0200.
 *
 * This file contains the registers for the RV32IMACFDV_zvl128b core architecture.
 */

#ifndef ETISS_RV32IMACFDV_zvl128bArch_RV32IMACFDV_zvl128b_H_
#define ETISS_RV32IMACFDV_zvl128bArch_RV32IMACFDV_zvl128b_H_
#include "etiss/jit/CPU.h"

#ifdef __cplusplus
extern "C"
{
#endif
#pragma pack(push, 1)
    struct RV32IMACFDV_zvl128b
    {
        ETISS_CPU cpu; // original cpu struct must be defined as the first field of the new structure.
                       // This allows to cast X * to ETISS_CPU * and vice versa
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
        etiss_uint8 PRIV;
        etiss_uint32 DPC;
        etiss_uint32 FT0;
        etiss_uint32 FT1;
        etiss_uint32 FT2;
        etiss_uint32 FT3;
        etiss_uint32 FT4;
        etiss_uint32 FT5;
        etiss_uint32 FT6;
        etiss_uint32 FT7;
        etiss_uint32 FS0;
        etiss_uint32 FS1;
        etiss_uint32 FA0;
        etiss_uint32 FA1;
        etiss_uint32 FA2;
        etiss_uint32 FA3;
        etiss_uint32 FA4;
        etiss_uint32 FA5;
        etiss_uint32 FA6;
        etiss_uint32 FA7;
        etiss_uint32 FS2;
        etiss_uint32 FS3;
        etiss_uint32 FS4;
        etiss_uint32 FS5;
        etiss_uint32 FS6;
        etiss_uint32 FS7;
        etiss_uint32 FS8;
        etiss_uint32 FS9;
        etiss_uint32 FS10;
        etiss_uint32 FS11;
        etiss_uint32 FT8;
        etiss_uint32 FT9;
        etiss_uint32 FT10;
        etiss_uint32 FT11;
        etiss_uint32 *F[32];
        etiss_uint32 ins_F[32];
        etiss_uint32 RES_ADDR;
        etiss_uint32 FENCE[8];
        etiss_int8 RES[8];
        etiss_uint32 VSTART_CSR;
        etiss_uint32 VXSAT_CSR;
        etiss_uint32 VXRM_CSR;
        etiss_uint32 VCSR_CSR;
        etiss_uint32 VL_CSR;
        etiss_uint32 VTYPE_CSR;
        etiss_uint32 VLENB_CSR;
        etiss_uint32 FCSR;
        etiss_uint32 FFLAGS;
        etiss_uint32 FRM;
        etiss_uint32 MSTATUS;
        etiss_uint32 MIE;
        etiss_uint32 MIP;
        etiss_uint32 CYCLE;
        etiss_uint32 CYCLEH;
        etiss_uint32 MCYCLE;
        etiss_uint32 MCYCLEH;
        etiss_uint32 TIME;
        etiss_uint32 TIMEH;
        etiss_uint32 INSTRET;
        etiss_uint32 INSTRETH;
        etiss_uint32 MINSTRET;
        etiss_uint32 MINSTRETH;
        etiss_uint32 MVENDORID;
        etiss_uint32 MARCHID;
        etiss_uint32 MIMPID;
        etiss_uint32 MHARTID;
        etiss_uint32 MISA;
        etiss_uint32 MEDELEG;
        etiss_uint32 MIDELEG;
        etiss_uint32 MTVEC;
        etiss_uint32 MCOUNTEREN;
        etiss_uint32 MSCRATCH;
        etiss_uint32 MEPC;
        etiss_uint32 MCAUSE;
        etiss_uint32 MTVAL;
        etiss_uint32 *CSR[4096];
        etiss_uint32 ins_CSR[4096];
        etiss_uint8 V[512];
    };

#pragma pack(pop) // undo changes
    // convenient use of X instead of struct X in generated C code
    typedef struct RV32IMACFDV_zvl128b RV32IMACFDV_zvl128b;
#ifdef __cplusplus
} // extern "C"
#endif
#endif
