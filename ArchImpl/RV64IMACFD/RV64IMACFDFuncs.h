/**
 * Generated on Tue, 07 Feb 2023 18:20:18 +0100.
 *
 * This file contains the function macros for the RV64IMACFD core architecture.
 */

#ifndef __RV64IMACFD_FUNCS_H
#define __RV64IMACFD_FUNCS_H

#ifndef ETISS_ARCH_STATIC_FN_ONLY
#include "Arch/RV64IMACFD/RV64IMACFD.h"
#include "etiss/jit/CPU.h"
#include "etiss/jit/System.h"
#include "etiss/jit/ReturnCode.h"
#endif



#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern void leave(etiss_int32 priv_lvl);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern void wait(etiss_int32 flag);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 extension_enabled(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int8 extension)
{
return (*((RV64IMACFD*)cpu)->CSR[769] >> (extension - 65U)) & 1U;
}
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint32 fadd_s(etiss_uint32, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint32 fsub_s(etiss_uint32, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint32 fmul_s(etiss_uint32, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint32 fdiv_s(etiss_uint32, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint32 fmadd_s(etiss_uint32, etiss_uint32, etiss_uint32, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint32 fsel_s(etiss_uint32, etiss_uint32, etiss_uint32);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint32 fsqrt_s(etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint32 fcmp_s(etiss_uint32, etiss_uint32, etiss_uint32);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint32 fcvt_s(etiss_uint32, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint64 fcvt_32_64(etiss_uint32, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint32 fcvt_64_32(etiss_uint64, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint32 unbox_s(etiss_uint64);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint32 fclass_s(etiss_uint32);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint32 fget_flags();
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint64 fadd_d(etiss_uint64, etiss_uint64, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint64 fsub_d(etiss_uint64, etiss_uint64, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint64 fmul_d(etiss_uint64, etiss_uint64, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint64 fdiv_d(etiss_uint64, etiss_uint64, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint64 fmadd_d(etiss_uint64, etiss_uint64, etiss_uint64, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint64 fsel_d(etiss_uint64, etiss_uint64, etiss_uint32);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint64 fsqrt_d(etiss_uint64, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint64 fcmp_d(etiss_uint64, etiss_uint64, etiss_uint32);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint64 fcvt_d(etiss_uint64, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint32 fconv_d2f(etiss_uint64, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint64 fconv_f2d(etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint64 unbox_d(etiss_uint64);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint64 fclass_d(etiss_uint64);
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
etiss_uint64 epc = cpu->instructionPointer;
if (((RV64IMACFD*)cpu)->PRIV <= 1 && (*((RV64IMACFD*)cpu)->CSR[770] >> mcause) & 1U) {
cpu->nextPc = (*((RV64IMACFD*)cpu)->CSR[261] & -2L);
*((RV64IMACFD*)cpu)->CSR[321] = epc;
*((RV64IMACFD*)cpu)->CSR[322] = mcause;
etiss_uint64 s = *((RV64IMACFD*)cpu)->CSR[256];
s = set_field(s, 32, get_field(s, 2));
s = set_field(s, 256, ((RV64IMACFD*)cpu)->PRIV);
s = set_field(s, 2, 0U);
*((RV64IMACFD*)cpu)->CSR[256] = s;
((RV64IMACFD*)cpu)->PRIV = (1) & 0x7;
}
else {
cpu->nextPc = (*((RV64IMACFD*)cpu)->CSR[773] & -2L);
*((RV64IMACFD*)cpu)->CSR[833] = epc;
*((RV64IMACFD*)cpu)->CSR[834] = mcause;
etiss_uint64 s = *((RV64IMACFD*)cpu)->CSR[768];
s = set_field(s, 128, get_field(s, 8));
s = set_field(s, 6144, ((RV64IMACFD*)cpu)->PRIV);
s = set_field(s, 8, 0U);
*((RV64IMACFD*)cpu)->CSR[768] = s;
((RV64IMACFD*)cpu)->PRIV = (3) & 0x7;
}
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
extern etiss_uint64 etiss_get_cycles(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint64 etiss_get_time();
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint64 etiss_get_instret(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 sstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_uint64 mask = 0U;
if (extension_enabled(cpu, system, plugin_pointers, 83U)) {
mask = mask | 5767458UL;
if (extension_enabled(cpu, system, plugin_pointers, 86U)) {
mask = mask | 1536L;
}
if (extension_enabled(cpu, system, plugin_pointers, 70U)) {
mask = mask | 24576L;
}
if (extension_enabled(cpu, system, plugin_pointers, 88U)) {
mask = mask | 98304L;
}
if (0U && get_field(*((RV64IMACFD*)cpu)->CSR[384], 2147483648U) || 1U && get_field(*((RV64IMACFD*)cpu)->CSR[384], 17293822569102704640UL)) {
mask = mask | 262144L;
}
}
return mask;
}
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 mstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_uint64 mask = 6280U;
return mask | sstatus_mask(cpu, system, plugin_pointers);
}
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 csr_read(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr)
{
if (csr == 1) {
return *((RV64IMACFD*)cpu)->CSR[3] & 31UL;
}
if (csr == 2) {
return (*((RV64IMACFD*)cpu)->CSR[3] >> 5UL) & 7U;
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
if (csr == 768 || csr == 256) {
return *((RV64IMACFD*)cpu)->CSR[768] | 8589934592UL | 34359738368UL;
}
if (csr == 769) {
return (((2U) << 62) | ((((*((RV64IMACFD*)cpu)->CSR[769]) >> (0U)) & 4611686018427387903)));
}
return *((RV64IMACFD*)cpu)->CSR[csr];
}
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline void csr_write(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr, etiss_uint64 val)
{
if (csr == 1) {
*((RV64IMACFD*)cpu)->CSR[3] = (*((RV64IMACFD*)cpu)->CSR[3] & 224UL) | (val & 31UL);
}
 else if (csr == 2) {
*((RV64IMACFD*)cpu)->CSR[3] = ((val & 7UL) << 5U) | (*((RV64IMACFD*)cpu)->CSR[3] & 31UL);
}
 else if (csr == 3) {
*((RV64IMACFD*)cpu)->CSR[3] = val & 255UL;
}
 else if (csr == 768) {
*((RV64IMACFD*)cpu)->CSR[768] = val & mstatus_mask(cpu, system, plugin_pointers);
}
 else if (csr == 256) {
*((RV64IMACFD*)cpu)->CSR[768] = val & sstatus_mask(cpu, system, plugin_pointers);
}
 else if (csr != 769) {
*((RV64IMACFD*)cpu)->CSR[csr] = val;
}
}
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_uint8 etiss_semihost_enabled();
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
extern etiss_int64 etiss_semihost(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 XLEN, etiss_uint64 operation, etiss_uint64 parameter);
#endif
#endif
