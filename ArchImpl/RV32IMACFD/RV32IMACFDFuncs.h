/**
 * Generated on Mon, 02 Oct 2023 18:56:15 +0200.
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



extern void leave(etiss_int32 priv_lvl);

extern void wait(etiss_int32 flag);

static inline etiss_uint8 extension_enabled(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int8 extension);

extern etiss_uint32 fadd_s(etiss_uint32, etiss_uint32, etiss_uint8);

extern etiss_uint32 fsub_s(etiss_uint32, etiss_uint32, etiss_uint8);

extern etiss_uint32 fmul_s(etiss_uint32, etiss_uint32, etiss_uint8);

extern etiss_uint32 fdiv_s(etiss_uint32, etiss_uint32, etiss_uint8);

extern etiss_uint32 fmadd_s(etiss_uint32, etiss_uint32, etiss_uint32, etiss_uint32, etiss_uint8);

extern etiss_uint32 fsel_s(etiss_uint32, etiss_uint32, etiss_uint32);

extern etiss_uint32 fsqrt_s(etiss_uint32, etiss_uint8);

extern etiss_uint32 fcmp_s(etiss_uint32, etiss_uint32, etiss_uint32);

extern etiss_uint32 fcvt_s(etiss_uint32, etiss_uint32, etiss_uint8);

extern etiss_uint64 fcvt_32_64(etiss_uint32, etiss_uint32, etiss_uint8);

extern etiss_uint32 fcvt_64_32(etiss_uint64, etiss_uint32, etiss_uint8);

extern etiss_uint32 unbox_s(etiss_uint64);

extern etiss_uint32 fclass_s(etiss_uint32);

extern etiss_uint32 fget_flags();

static inline etiss_uint8 get_rm(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint8 rm);

extern etiss_uint64 fadd_d(etiss_uint64, etiss_uint64, etiss_uint8);

extern etiss_uint64 fsub_d(etiss_uint64, etiss_uint64, etiss_uint8);

extern etiss_uint64 fmul_d(etiss_uint64, etiss_uint64, etiss_uint8);

extern etiss_uint64 fdiv_d(etiss_uint64, etiss_uint64, etiss_uint8);

extern etiss_uint64 fmadd_d(etiss_uint64, etiss_uint64, etiss_uint64, etiss_uint32, etiss_uint8);

extern etiss_uint64 fsel_d(etiss_uint64, etiss_uint64, etiss_uint32);

extern etiss_uint64 fsqrt_d(etiss_uint64, etiss_uint8);

extern etiss_uint64 fcmp_d(etiss_uint64, etiss_uint64, etiss_uint32);

extern etiss_uint64 fcvt_d(etiss_uint64, etiss_uint32, etiss_uint8);

extern etiss_uint32 fconv_d2f(etiss_uint64, etiss_uint8);

extern etiss_uint64 fconv_f2d(etiss_uint32, etiss_uint8);

extern etiss_uint64 unbox_d(etiss_uint64);

extern etiss_uint64 fclass_d(etiss_uint64);

extern etiss_uint64 etiss_get_cycles(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

extern etiss_uint64 etiss_get_time();

extern etiss_uint64 etiss_get_instret(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

static inline etiss_uint32 sstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

static inline etiss_uint32 mstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

static inline etiss_uint32 csr_read(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr);

static inline void csr_write(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr, etiss_uint32 val);

static inline etiss_uint64 get_field(etiss_uint64 reg, etiss_uint64 mask);

static inline etiss_uint64 set_field(etiss_uint64 reg, etiss_uint64 mask, etiss_uint64 val);

static inline etiss_uint8 ctz(etiss_uint64 val);

static inline void raise(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 irq, etiss_uint32 mcause);

static inline void translate_exc_code(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 cause);

static inline etiss_uint32 calc_irq_mcause(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

static inline void check_irq(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

extern etiss_uint8 etiss_semihost_enabled();

extern etiss_int64 etiss_semihost(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 XLEN, etiss_uint64 operation, etiss_uint64 parameter);

static inline etiss_uint8 extension_enabled(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int8 extension)
{
{ // block
return (*((RV32IMACFD*)cpu)->CSR[769LL] >> (extension - 65ULL)) & 1ULL;
} // block
}

static inline etiss_uint8 get_rm(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint8 rm)
{
{ // block
if (rm == 7ULL) { // conditional
rm = ((((((RV32IMACFD*)cpu)->FCSR) >> (5ULL)) & 7)) & 0x7;
} // conditional
if (rm > 4ULL) { // conditional
raise(cpu, system, plugin_pointers, 0ULL, 2LL);
} // conditional
return rm;
} // block
}

static inline etiss_uint32 sstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
{ // block
etiss_uint32 mask = 0ULL;
if (extension_enabled(cpu, system, plugin_pointers, 83ULL)) { // conditional
{ // block
mask = mask | 5767458ULL;
if (extension_enabled(cpu, system, plugin_pointers, 86ULL)) { // conditional
mask = mask | 1536LL;
} // conditional
if (extension_enabled(cpu, system, plugin_pointers, 70ULL)) { // conditional
mask = mask | 24576LL;
} // conditional
if (extension_enabled(cpu, system, plugin_pointers, 88ULL)) { // conditional
mask = mask | 98304LL;
} // conditional
if ((get_field(*((RV32IMACFD*)cpu)->CSR[384LL], 2147483648ULL))) { // conditional
mask = mask | 262144LL;
} // conditional
} // block
} // conditional
return mask;
} // block
}

static inline etiss_uint32 mstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
{ // block
etiss_uint32 mask = 6280ULL;
return mask | sstatus_mask(cpu, system, plugin_pointers);
} // block
}

static inline etiss_uint32 csr_read(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr)
{
{ // block
if (csr == 1LL) { // conditional
return *((RV32IMACFD*)cpu)->CSR[3LL] & 31ULL;
} // conditional
if (csr == 2LL) { // conditional
return (*((RV32IMACFD*)cpu)->CSR[3LL] >> 5ULL) & 7ULL;
} // conditional
if (csr == 3072LL) { // conditional
return etiss_get_cycles(cpu, system, plugin_pointers);
} // conditional
if (csr == 3200LL) { // conditional
return etiss_get_cycles(cpu, system, plugin_pointers) >> 32ULL;
} // conditional
if (csr == 3073LL) { // conditional
return etiss_get_time();
} // conditional
if (csr == 3201LL) { // conditional
return etiss_get_time() >> 32ULL;
} // conditional
if (csr == 3074LL) { // conditional
return etiss_get_instret(cpu, system, plugin_pointers);
} // conditional
if (csr == 3202LL) { // conditional
return etiss_get_instret(cpu, system, plugin_pointers) >> 32ULL;
} // conditional
if (csr == 768LL || csr == 256LL) { // conditional
return *((RV32IMACFD*)cpu)->CSR[768LL] | 8589934592ULL | 34359738368ULL;
} // conditional
if (csr == 769LL) { // conditional
return (((1ULL) << 30) | ((((*((RV32IMACFD*)cpu)->CSR[769LL]) >> (0ULL)) & 1073741823)));
} // conditional
return *((RV32IMACFD*)cpu)->CSR[csr];
} // block
}

static inline void csr_write(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr, etiss_uint32 val)
{
{ // block
if (csr == 1LL) { // conditional
*((RV32IMACFD*)cpu)->CSR[3LL] = (*((RV32IMACFD*)cpu)->CSR[3LL] & 224ULL) | (val & 31ULL);
} // conditional
 else if (csr == 2LL) { // conditional
*((RV32IMACFD*)cpu)->CSR[3LL] = ((val & 7ULL) << 5ULL) | (*((RV32IMACFD*)cpu)->CSR[3LL] & 31ULL);
} // conditional
 else if (csr == 3LL) { // conditional
*((RV32IMACFD*)cpu)->CSR[3LL] = val & 255ULL;
} // conditional
 else if (csr == 768LL) { // conditional
*((RV32IMACFD*)cpu)->CSR[768LL] = val & mstatus_mask(cpu, system, plugin_pointers);
} // conditional
 else if (csr == 256LL) { // conditional
*((RV32IMACFD*)cpu)->CSR[768LL] = val & sstatus_mask(cpu, system, plugin_pointers);
} // conditional
 else if (csr != 769LL) { // conditional
*((RV32IMACFD*)cpu)->CSR[csr] = val;
} // conditional
} // block
}

static inline etiss_uint64 get_field(etiss_uint64 reg, etiss_uint64 mask)
{
{ // block
return (reg & mask) / (mask & ~((mask << 1ULL)));
} // block
}

static inline etiss_uint64 set_field(etiss_uint64 reg, etiss_uint64 mask, etiss_uint64 val)
{
{ // block
return ((reg & ~(mask)) | ((val * (mask & ~((mask << 1ULL)))) & mask));
} // block
}

static inline etiss_uint8 ctz(etiss_uint64 val)
{
{ // block
if (!(val)) { // conditional
return 0ULL;
} // conditional
etiss_uint8 res = 0ULL;
if ((val << 32ULL) == 0ULL) { // conditional
{ // block
res = res + 32ULL;
val = val >> 32ULL;
} // block
} // conditional
if ((val << 48ULL) == 0ULL) { // conditional
{ // block
res = res + 16ULL;
val = val >> 16ULL;
} // block
} // conditional
if ((val << 56ULL) == 0ULL) { // conditional
{ // block
res = res + 8ULL;
val = val >> 8ULL;
} // block
} // conditional
if ((val << 60ULL) == 0ULL) { // conditional
{ // block
res = res + 4ULL;
val = val >> 4ULL;
} // block
} // conditional
if ((val << 62ULL) == 0ULL) { // conditional
{ // block
res = res + 2ULL;
val = val >> 2ULL;
} // block
} // conditional
if ((val << 63ULL) == 0ULL) { // conditional
{ // block
res = res + 1ULL;
val = val >> 1ULL;
} // block
} // conditional
return res;
} // block
}

static inline void raise(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 irq, etiss_uint32 mcause)
{
cpu->return_pending = 1;
cpu->exception = 0;
{ // block
etiss_uint32 epc = cpu->instructionPointer;
etiss_uint32 deleg = 0ULL;
etiss_uint32 vector = 0ULL;
etiss_uint32 bit = mcause;
etiss_int32 irq2 = (mcause & 2147483648ULL) != 0ULL;
if (irq2) { // conditional
{ // block
deleg = ((((RV32IMACFD*)cpu)->PRIV <= 1LL)) ? (*((RV32IMACFD*)cpu)->CSR[771LL]) : (0ULL);
bit = bit & 2147483647ULL;
} // block
} // conditional
else { // conditional
{ // block
deleg = ((((RV32IMACFD*)cpu)->PRIV <= 1LL)) ? (*((RV32IMACFD*)cpu)->CSR[770LL]) : (0ULL);
} // block
} // conditional
if (((RV32IMACFD*)cpu)->PRIV <= 1LL && (deleg >> bit) & 1ULL) { // conditional
{ // block
vector = ((*((RV32IMACFD*)cpu)->CSR[261LL] & 1ULL) && irq2) ? (bit * 4ULL) : (0ULL);
cpu->nextPc = (*((RV32IMACFD*)cpu)->CSR[261LL] & -2LL) + vector;
*((RV32IMACFD*)cpu)->CSR[321LL] = epc;
*((RV32IMACFD*)cpu)->CSR[322LL] = mcause;
etiss_uint32 s = csr_read(cpu, system, plugin_pointers, 256LL);
s = set_field(s, 32LL, get_field(s, 2LL));
s = set_field(s, 256LL, ((RV32IMACFD*)cpu)->PRIV);
s = set_field(s, 2LL, 0ULL);
csr_write(cpu, system, plugin_pointers, 256LL, s);
((RV32IMACFD*)cpu)->PRIV = (1LL) & 0x7;
} // block
} // conditional
else { // conditional
{ // block
vector = ((*((RV32IMACFD*)cpu)->CSR[773LL] & 1ULL) && irq2) ? (bit * 4ULL) : (0ULL);
cpu->nextPc = (*((RV32IMACFD*)cpu)->CSR[773LL] & -2LL) + vector;
*((RV32IMACFD*)cpu)->CSR[833LL] = epc;
*((RV32IMACFD*)cpu)->CSR[834LL] = mcause;
etiss_uint32 s = csr_read(cpu, system, plugin_pointers, 768LL);
s = set_field(s, 128LL, get_field(s, 8LL));
s = set_field(s, 6144LL, ((RV32IMACFD*)cpu)->PRIV);
s = set_field(s, 8LL, 0ULL);
csr_write(cpu, system, plugin_pointers, 768LL, s);
((RV32IMACFD*)cpu)->PRIV = (3LL) & 0x7;
} // block
} // conditional
} // block
}

static inline void translate_exc_code(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 cause)
{
{ // block
etiss_uint32 code = 0ULL;
if (cause == -2147483648LL) { // conditional
return;
} // conditional
 else if (cause == -5LL) { // conditional
code = 5LL;
} // conditional
 else if (cause == -14LL) { // conditional
code = 13LL;
} // conditional
 else if (cause == -6LL) { // conditional
code = 7LL;
} // conditional
 else if (cause == -15LL) { // conditional
code = 15LL;
} // conditional
 else if (cause == -7LL) { // conditional
code = 1LL;
} // conditional
 else if (cause == -9LL) { // conditional
{ // block
code = calc_irq_mcause(cpu, system, plugin_pointers);
if (!(code)) { // conditional
return;
} // conditional
} // block
} // conditional
else { // conditional
code = 2LL;
} // conditional
raise(cpu, system, plugin_pointers, 0ULL, code);
} // block
}

static inline etiss_uint32 calc_irq_mcause(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
{ // block
etiss_uint32 pending_interrupts = *((RV32IMACFD*)cpu)->CSR[772LL] & *((RV32IMACFD*)cpu)->CSR[836LL];
if (!(pending_interrupts)) { // conditional
return 0ULL;
} // conditional
etiss_uint32 mie = get_field(*((RV32IMACFD*)cpu)->CSR[768LL], 8LL);
etiss_uint32 m_enabled = ((RV32IMACFD*)cpu)->PRIV < 3LL || (((RV32IMACFD*)cpu)->PRIV == 3LL && mie);
etiss_uint32 enabled_interrupts = pending_interrupts & ~(*((RV32IMACFD*)cpu)->CSR[771LL]) & -(m_enabled);
if (enabled_interrupts == 0ULL) { // conditional
{ // block
etiss_uint32 deleg = *((RV32IMACFD*)cpu)->CSR[771LL];
etiss_uint32 sie = get_field(csr_read(cpu, system, plugin_pointers, 256LL), 2LL);
etiss_uint32 s_enabled = ((RV32IMACFD*)cpu)->PRIV < 1LL || (((RV32IMACFD*)cpu)->PRIV == 1LL && sie);
enabled_interrupts = pending_interrupts & deleg & -(s_enabled);
} // block
} // conditional
if (enabled_interrupts) { // conditional
{ // block
if (enabled_interrupts >> 12ULL) { // conditional
enabled_interrupts = enabled_interrupts >> 12ULL << 12ULL;
} // conditional
 else if (enabled_interrupts & 2048LL) { // conditional
enabled_interrupts = 2048LL;
} // conditional
 else if (enabled_interrupts & 8LL) { // conditional
enabled_interrupts = 8LL;
} // conditional
 else if (enabled_interrupts & 128LL) { // conditional
enabled_interrupts = 128LL;
} // conditional
 else if (enabled_interrupts & 512LL) { // conditional
enabled_interrupts = 512LL;
} // conditional
 else if (enabled_interrupts & 2LL) { // conditional
enabled_interrupts = 2LL;
} // conditional
 else if (enabled_interrupts & 32LL) { // conditional
enabled_interrupts = 32LL;
} // conditional
 else if (enabled_interrupts & 8192LL) { // conditional
enabled_interrupts = 8192LL;
} // conditional
 else if (enabled_interrupts & 1024LL) { // conditional
enabled_interrupts = 1024LL;
} // conditional
 else if (enabled_interrupts & 4LL) { // conditional
enabled_interrupts = 4LL;
} // conditional
 else if (enabled_interrupts & 64LL) { // conditional
enabled_interrupts = 64LL;
} // conditional
else { // conditional
return 0ULL;
} // conditional
return 2147483648ULL | ctz(enabled_interrupts);
} // block
} // conditional
return 0ULL;
} // block
}

static inline void check_irq(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
{ // block
etiss_uint32 irq_mcause = calc_irq_mcause(cpu, system, plugin_pointers);
if (irq_mcause) { // conditional
raise(cpu, system, plugin_pointers, 1ULL, irq_mcause);
} // conditional
} // block
}
#endif