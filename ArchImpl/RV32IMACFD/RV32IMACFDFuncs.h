/**
 * Generated on Mon, 05 Dec 2022 22:55:33 +0100.
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
static inline etiss_uint64 get_field(etiss_uint64 reg, etiss_uint64 mask)
{
return (reg & mask) / (mask & ~((mask << 1UL)));
}
static inline etiss_uint64 set_field(etiss_uint64 reg, etiss_uint64 mask, etiss_uint64 val)
{
return ((reg & ~(mask)) | ((val * (mask & ~((mask << 1UL)))) & mask));
}

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline void raise(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 irq, etiss_int32 mcause)
{
cpu->return_pending = 1;
etiss_uint32 epc = cpu->instructionPointer;
cpu->nextPc = (*((RV32IMACFD*)cpu)->CSR[773] & -2);
*((RV32IMACFD*)cpu)->CSR[833] = epc;
*((RV32IMACFD*)cpu)->CSR[834] = mcause;
etiss_uint32 s = *((RV32IMACFD*)cpu)->CSR[768];
s = set_field(s, 128, get_field(s, 8));
s = set_field(s, 6144, ((RV32IMACFD*)cpu)->PRIV);
s = set_field(s, 8, 0U);
*((RV32IMACFD*)cpu)->CSR[768] = s;
((RV32IMACFD*)cpu)->PRIV = (3) & 0x7;
}
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline void translate_exc_code(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 cause)
{
etiss_int32 code = 0U;
if (cause == -2147483648) {
return;
}
 else if (cause == -5) {
code = 5;
}
 else if (cause == -14) {
code = 13;
}
 else if (cause == -6) {
code = 7;
}
 else if (cause == -15) {
code = 15;
}
 else if (cause == -7) {
code = 1;
}
else {
code = 2;
}
cpu->exception = 0; raise(cpu, system, plugin_pointers, 0U, code);
}
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 etiss_get_cycles(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 etiss_get_time();
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 etiss_get_instret(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 csr_read(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr)
{
if (csr == 1) {
return *((RV32IMACFD*)cpu)->CSR[3] & 31U;
}
if (csr == 2) {
return (*((RV32IMACFD*)cpu)->CSR[3] >> 5U) & 7U;
}
if (csr == 3072) {
return etiss_get_cycles(cpu, system, plugin_pointers);
}
if (csr == 3200) {
return etiss_get_cycles(cpu, system, plugin_pointers) >> 32U;
}
if (csr == 3073) {
return etiss_get_time();
}
if (csr == 3201) {
return etiss_get_time() >> 32U;
}
if (csr == 3074) {
return etiss_get_instret(cpu, system, plugin_pointers);
}
if (csr == 3202) {
return etiss_get_instret(cpu, system, plugin_pointers) >> 32U;
}
return *((RV32IMACFD*)cpu)->CSR[csr];
}
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline void csr_write(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr, etiss_uint32 val)
{
if (csr == 1) {
*((RV32IMACFD*)cpu)->CSR[3] = (*((RV32IMACFD*)cpu)->CSR[3] & 224U) | (val & 31U);
}
 else if (csr == 2) {
*((RV32IMACFD*)cpu)->CSR[3] = ((val & 7U) << 5U) | (*((RV32IMACFD*)cpu)->CSR[3] & 31U);
}
 else if (csr == 3) {
*((RV32IMACFD*)cpu)->CSR[3] = val & 255U;
}
 else if (csr == 768) {
*((RV32IMACFD*)cpu)->CSR[768] = val & 136U;
}
 else if (csr != 769) {
*((RV32IMACFD*)cpu)->CSR[csr] = val;
}
}
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 etiss_semihost_enabled();
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_int64 etiss_semihost(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 XLEN, etiss_uint64 operation, etiss_uint64 parameter);
#endif
#endif