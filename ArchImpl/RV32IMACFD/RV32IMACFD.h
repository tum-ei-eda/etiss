/**
 * Generated on Tue, 16 Sep 2025 12:56:33 +0200.
 *
 * This file contains the registers for the RV32IMACFD core architecture.
 */

#ifndef ETISS_RV32IMACFDArch_RV32IMACFD_H_
#define ETISS_RV32IMACFDArch_RV32IMACFD_H_
#include <stdio.h>
#include "etiss/jit/CPU.h"

#ifdef __cplusplus
extern "C" {
#endif
#pragma pack(push, 1)
struct RV32IMACFD {
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
	etiss_uint32 FENCE[8];
	etiss_uint8 RES[8];
	etiss_uint8 PRIV;
	etiss_uint32 DPC;
	etiss_uint32 FCSR;
	etiss_uint32 FFLAGS;
	etiss_uint32 FRM;
	etiss_uint32 MSTATUS;
	etiss_uint32 MIE;
	etiss_uint32 MIP;
	etiss_uint32 *CSR[4096];
	etiss_uint32 ins_CSR[4096];
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
	etiss_uint32 RES_ADDR;
};

#pragma pack(pop) // undo changes
typedef struct RV32IMACFD RV32IMACFD; // convenient use of X instead of struct X in generated C code
#ifdef __cplusplus
} // extern "C"
#endif
#endif
