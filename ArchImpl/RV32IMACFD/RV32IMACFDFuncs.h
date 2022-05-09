/**
 * Generated on Mon, 09 May 2022 21:14:16 +0200.
 *
 * This file contains the function macros for the RV32IMACFD core architecture.
 */

#ifndef __RV32IMACFD_FUNCS_H
#define __RV32IMACFD_FUNCS_H

#ifndef ETISS_ARCH_STATIC_FN_ONLY
#include "Arch/RV32IMACFD/RV32IMACFD.h"
#include "etiss/jit/CPU.h"
#include "etiss/jit/System.h"
#include "etiss/jit/ReturnCode.h"
#endif



#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline void raise(etiss_int32 irq, etiss_int32 mcause);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline void leave(etiss_int32 priv_lvl);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline void wait(etiss_int32 flag);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fadd_s(etiss_uint32, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fsub_s(etiss_uint32, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fmul_s(etiss_uint32, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fdiv_s(etiss_uint32, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fmadd_s(etiss_uint32, etiss_uint32, etiss_uint32, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fsel_s(etiss_uint32, etiss_uint32, etiss_uint32);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fsqrt_s(etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fcmp_s(etiss_uint32, etiss_uint32, etiss_uint32);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fcvt_s(etiss_uint32, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 fcvt_32_64(etiss_uint32, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fcvt_64_32(etiss_uint64, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 unbox_s(etiss_uint64);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fclass_s(etiss_uint32);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fget_flags();
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 fadd_d(etiss_uint64, etiss_uint64, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 fsub_d(etiss_uint64, etiss_uint64, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 fmul_d(etiss_uint64, etiss_uint64, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 fdiv_d(etiss_uint64, etiss_uint64, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 fmadd_d(etiss_uint64, etiss_uint64, etiss_uint64, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 fsel_d(etiss_uint64, etiss_uint64, etiss_uint32);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 fsqrt_d(etiss_uint64, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 fcmp_d(etiss_uint64, etiss_uint64, etiss_uint32);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 fcvt_d(etiss_uint64, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fconv_d2f(etiss_uint64, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 fconv_f2d(etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 unbox_d(etiss_uint64);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 fclass_d(etiss_uint64);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 csr_read(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr)
{
if (csr == 1U) {
return *((RV32IMACFD*)cpu)->CSR[3U] & 31U;
}
if (csr == 2U) {
return (*((RV32IMACFD*)cpu)->CSR[3U] >> 5U) & 7U;
}
return *((RV32IMACFD*)cpu)->CSR[csr];
}
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline void csr_write(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr, etiss_uint32 val)
{
if (csr == 1U) {
*((RV32IMACFD*)cpu)->CSR[3] = (*((RV32IMACFD*)cpu)->CSR[3U] & 224U) | (val & 31U);
} else {
if (csr == 2U) {
*((RV32IMACFD*)cpu)->CSR[3] = ((val & 7U) << 5U) | (*((RV32IMACFD*)cpu)->CSR[3U] & 31U);
} else {
if (csr == 3U) {
*((RV32IMACFD*)cpu)->CSR[3] = val & 255U;
} else {
*((RV32IMACFD*)cpu)->CSR[csr] = val;
}
}
}
}
#endif
#endif