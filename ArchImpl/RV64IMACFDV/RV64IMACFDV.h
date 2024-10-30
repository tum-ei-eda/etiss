/**
 * Generated on Wed, 30 Oct 2024 10:54:30 +0100.
 *
 * This file contains the registers for the RV64IMACFDV core architecture.
 */

#ifndef ETISS_RV64IMACFDVArch_RV64IMACFDV_H_
#define ETISS_RV64IMACFDVArch_RV64IMACFDV_H_
#include <stdio.h>
#include "etiss/jit/CPU.h"

#ifdef __cplusplus
extern "C" {
#endif
#pragma pack(push, 1)
struct RV64IMACFDV {
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
	etiss_uint64 FENCE[8];
	etiss_uint8 RES[8];
	etiss_uint8 PRIV;
	etiss_uint64 DPC;
	etiss_uint64 VSTART_CSR;
	etiss_uint64 VXSAT_CSR;
	etiss_uint64 VXRM_CSR;
	etiss_uint64 VCSR_CSR;
	etiss_uint64 VL_CSR;
	etiss_uint64 VTYPE_CSR;
	etiss_uint64 VLENB_CSR;
	etiss_uint64 FCSR;
	etiss_uint64 FFLAGS;
	etiss_uint64 FRM;
	etiss_uint64 MSTATUS;
	etiss_uint64 MIE;
	etiss_uint64 MIP;
	etiss_uint64 CYCLE;
	etiss_uint64 CYCLEH;
	etiss_uint64 TIME;
	etiss_uint64 TIMEH;
	etiss_uint64 INSTRET;
	etiss_uint64 INSTRETH;
	etiss_uint64 MVENDORID;
	etiss_uint64 MARCHID;
	etiss_uint64 MIMPID;
	etiss_uint64 MHARTID;
	etiss_uint64 MISA;
	etiss_uint64 MEDELEG;
	etiss_uint64 MIDELEG;
	etiss_uint64 MTVEC;
	etiss_uint64 MCOUNTEREN;
	etiss_uint64 MSCRATCH;
	etiss_uint64 MEPC;
	etiss_uint64 MCAUSE;
	etiss_uint64 MTVAL;
	etiss_uint64 *CSR[4096];
	etiss_uint64 ins_CSR[4096];
	etiss_uint8 V[4096];
	etiss_uint64 FT0;
	etiss_uint64 FT1;
	etiss_uint64 FT2;
	etiss_uint64 FT3;
	etiss_uint64 FT4;
	etiss_uint64 FT5;
	etiss_uint64 FT6;
	etiss_uint64 FT7;
	etiss_uint64 FS0;
	etiss_uint64 FS1;
	etiss_uint64 FA0;
	etiss_uint64 FA1;
	etiss_uint64 FA2;
	etiss_uint64 FA3;
	etiss_uint64 FA4;
	etiss_uint64 FA5;
	etiss_uint64 FA6;
	etiss_uint64 FA7;
	etiss_uint64 FS2;
	etiss_uint64 FS3;
	etiss_uint64 FS4;
	etiss_uint64 FS5;
	etiss_uint64 FS6;
	etiss_uint64 FS7;
	etiss_uint64 FS8;
	etiss_uint64 FS9;
	etiss_uint64 FS10;
	etiss_uint64 FS11;
	etiss_uint64 FT8;
	etiss_uint64 FT9;
	etiss_uint64 FT10;
	etiss_uint64 FT11;
	etiss_uint64 *F[32];
	etiss_uint64 ins_F[32];
	etiss_uint64 RES_ADDR;
};

#pragma pack(pop) // undo changes
typedef struct RV64IMACFDV RV64IMACFDV; // convenient use of X instead of struct X in generated C code
#ifdef __cplusplus
} // extern "C"
#endif
#endif
