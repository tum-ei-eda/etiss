/**
 * Generated on Fri, 03 Nov 2023 13:22:23 +0100.
 *
 * This file contains the function implementations for the RV64IMACFD core architecture.
 */

#include "RV64IMACFDFuncs.h"

etiss_uint8 RV64IMACFD_extension_enabled(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int8 extension)
{
{ // block
return (*((RV64IMACFD*)cpu)->CSR[769LL] >> (extension - 65ULL)) & 1ULL;
} // block
}

etiss_uint8 RV64IMACFD_get_rm(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint8 rm)
{
{ // block
if (rm == 7ULL) { // conditional
rm = ((((((RV64IMACFD*)cpu)->FCSR) >> (5ULL)) & 7)) & 0x7;
} // conditional
if (rm > 4ULL) { // conditional
RV64IMACFD_raise(cpu, system, plugin_pointers, 0ULL, 2LL);
} // conditional
return rm;
} // block
}

etiss_uint64 RV64IMACFD_sstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
{ // block
etiss_uint64 mask = 0ULL;
if (RV64IMACFD_extension_enabled(cpu, system, plugin_pointers, 83ULL)) { // conditional
{ // block
mask = mask | 5767458ULL;
if (RV64IMACFD_extension_enabled(cpu, system, plugin_pointers, 86ULL)) { // conditional
mask = mask | 1536LL;
} // conditional
if (RV64IMACFD_extension_enabled(cpu, system, plugin_pointers, 70ULL)) { // conditional
mask = mask | 24576LL;
} // conditional
if (RV64IMACFD_extension_enabled(cpu, system, plugin_pointers, 88ULL)) { // conditional
mask = mask | 98304LL;
} // conditional
if ((RV64IMACFD_get_field(*((RV64IMACFD*)cpu)->CSR[384LL], 17293822569102704640ULL))) { // conditional
mask = mask | 262144LL;
} // conditional
} // block
} // conditional
return mask;
} // block
}

etiss_uint64 RV64IMACFD_mstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
{ // block
etiss_uint64 mask = 6280ULL;
return mask | RV64IMACFD_sstatus_mask(cpu, system, plugin_pointers);
} // block
}

etiss_uint64 RV64IMACFD_csr_read(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr)
{
{ // block
if (csr == 1LL) { // conditional
return *((RV64IMACFD*)cpu)->CSR[3LL] & 31ULL;
} // conditional
if (csr == 2LL) { // conditional
return (*((RV64IMACFD*)cpu)->CSR[3LL] >> 5ULL) & 7ULL;
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
return *((RV64IMACFD*)cpu)->CSR[768LL] | 8589934592ULL | 34359738368ULL;
} // conditional
if (csr == 769LL) { // conditional
return (((2ULL) << 62) | ((((*((RV64IMACFD*)cpu)->CSR[769LL]) >> (0ULL)) & 4611686018427387903)));
} // conditional
return *((RV64IMACFD*)cpu)->CSR[csr];
} // block
}

void RV64IMACFD_csr_write(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr, etiss_uint64 val)
{
{ // block
if (csr == 1LL) { // conditional
*((RV64IMACFD*)cpu)->CSR[3LL] = (*((RV64IMACFD*)cpu)->CSR[3LL] & 224ULL) | (val & 31ULL);
} // conditional
 else if (csr == 2LL) { // conditional
*((RV64IMACFD*)cpu)->CSR[3LL] = ((val & 7ULL) << 5ULL) | (*((RV64IMACFD*)cpu)->CSR[3LL] & 31ULL);
} // conditional
 else if (csr == 3LL) { // conditional
*((RV64IMACFD*)cpu)->CSR[3LL] = val & 255ULL;
} // conditional
 else if (csr == 768LL) { // conditional
*((RV64IMACFD*)cpu)->CSR[768LL] = val & RV64IMACFD_mstatus_mask(cpu, system, plugin_pointers);
} // conditional
 else if (csr == 256LL) { // conditional
*((RV64IMACFD*)cpu)->CSR[768LL] = val & RV64IMACFD_sstatus_mask(cpu, system, plugin_pointers);
} // conditional
 else if (csr != 769LL) { // conditional
*((RV64IMACFD*)cpu)->CSR[csr] = val;
} // conditional
} // block
}

etiss_uint64 RV64IMACFD_get_field(etiss_uint64 reg, etiss_uint64 mask)
{
{ // block
return (reg & mask) / (mask & ~((mask << 1ULL)));
} // block
}

etiss_uint64 RV64IMACFD_set_field(etiss_uint64 reg, etiss_uint64 mask, etiss_uint64 val)
{
{ // block
return ((reg & ~(mask)) | ((val * (mask & ~((mask << 1ULL)))) & mask));
} // block
}

etiss_uint8 RV64IMACFD_ctz(etiss_uint64 val)
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

void RV64IMACFD_raise(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 irq, etiss_uint64 mcause)
{
cpu->return_pending = 1;
cpu->exception = 0;
{ // block
etiss_uint64 epc = cpu->instructionPointer;
etiss_uint64 deleg = 0ULL;
etiss_uint64 vector = 0ULL;
etiss_uint64 bit = mcause;
etiss_int32 irq2 = (mcause & 9223372036854775808ULL) != 0ULL;
if (irq2) { // conditional
{ // block
deleg = ((((RV64IMACFD*)cpu)->PRIV <= 1LL)) ? (*((RV64IMACFD*)cpu)->CSR[771LL]) : (0ULL);
bit = bit & 9223372036854775807ULL;
} // block
} // conditional
else { // conditional
{ // block
deleg = ((((RV64IMACFD*)cpu)->PRIV <= 1LL)) ? (*((RV64IMACFD*)cpu)->CSR[770LL]) : (0ULL);
} // block
} // conditional
if (((RV64IMACFD*)cpu)->PRIV <= 1LL && (deleg >> bit) & 1ULL) { // conditional
{ // block
vector = ((*((RV64IMACFD*)cpu)->CSR[261LL] & 1ULL) && irq2) ? (bit * 4ULL) : (0ULL);
cpu->nextPc = (*((RV64IMACFD*)cpu)->CSR[261LL] & -2LL) + vector;
*((RV64IMACFD*)cpu)->CSR[321LL] = epc;
*((RV64IMACFD*)cpu)->CSR[322LL] = mcause;
etiss_uint64 s = RV64IMACFD_csr_read(cpu, system, plugin_pointers, 256LL);
s = RV64IMACFD_set_field(s, 32LL, RV64IMACFD_get_field(s, 2LL));
s = RV64IMACFD_set_field(s, 256LL, ((RV64IMACFD*)cpu)->PRIV);
s = RV64IMACFD_set_field(s, 2LL, 0ULL);
RV64IMACFD_csr_write(cpu, system, plugin_pointers, 256LL, s);
((RV64IMACFD*)cpu)->PRIV = (1LL) & 0x7;
} // block
} // conditional
else { // conditional
{ // block
vector = ((*((RV64IMACFD*)cpu)->CSR[773LL] & 1ULL) && irq2) ? (bit * 4ULL) : (0ULL);
cpu->nextPc = (*((RV64IMACFD*)cpu)->CSR[773LL] & -2LL) + vector;
*((RV64IMACFD*)cpu)->CSR[833LL] = epc;
*((RV64IMACFD*)cpu)->CSR[834LL] = mcause;
etiss_uint64 s = RV64IMACFD_csr_read(cpu, system, plugin_pointers, 768LL);
s = RV64IMACFD_set_field(s, 128LL, RV64IMACFD_get_field(s, 8LL));
s = RV64IMACFD_set_field(s, 6144LL, ((RV64IMACFD*)cpu)->PRIV);
s = RV64IMACFD_set_field(s, 8LL, 0ULL);
RV64IMACFD_csr_write(cpu, system, plugin_pointers, 768LL, s);
((RV64IMACFD*)cpu)->PRIV = (3LL) & 0x7;
} // block
} // conditional
} // block
}

void RV64IMACFD_translate_exc_code(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 cause)
{
{ // block
etiss_uint64 code = 0ULL;
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
code = RV64IMACFD_calc_irq_mcause(cpu, system, plugin_pointers);
if (!(code)) { // conditional
return;
} // conditional
} // block
} // conditional
else { // conditional
code = 2LL;
} // conditional
RV64IMACFD_raise(cpu, system, plugin_pointers, 0ULL, code);
} // block
}

etiss_uint64 RV64IMACFD_calc_irq_mcause(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
{ // block
etiss_uint64 pending_interrupts = *((RV64IMACFD*)cpu)->CSR[772LL] & *((RV64IMACFD*)cpu)->CSR[836LL];
if (!(pending_interrupts)) { // conditional
return 0ULL;
} // conditional
etiss_uint64 mie = RV64IMACFD_get_field(*((RV64IMACFD*)cpu)->CSR[768LL], 8LL);
etiss_uint64 m_enabled = ((RV64IMACFD*)cpu)->PRIV < 3LL || (((RV64IMACFD*)cpu)->PRIV == 3LL && mie);
etiss_uint64 enabled_interrupts = pending_interrupts & ~(*((RV64IMACFD*)cpu)->CSR[771LL]) & -(m_enabled);
if (enabled_interrupts == 0ULL) { // conditional
{ // block
etiss_uint64 deleg = *((RV64IMACFD*)cpu)->CSR[771LL];
etiss_uint64 sie = RV64IMACFD_get_field(RV64IMACFD_csr_read(cpu, system, plugin_pointers, 256LL), 2LL);
etiss_uint64 s_enabled = ((RV64IMACFD*)cpu)->PRIV < 1LL || (((RV64IMACFD*)cpu)->PRIV == 1LL && sie);
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
return 9223372036854775808ULL | RV64IMACFD_ctz(enabled_interrupts);
} // block
} // conditional
return 0ULL;
} // block
}

void RV64IMACFD_check_irq(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
{ // block
etiss_uint64 irq_mcause = RV64IMACFD_calc_irq_mcause(cpu, system, plugin_pointers);
if (irq_mcause) { // conditional
RV64IMACFD_raise(cpu, system, plugin_pointers, 1ULL, irq_mcause);
} // conditional
} // block
}

etiss_int64 RV64IMACFD_mulh(etiss_int64 x, etiss_int64 y)
{
{ // block
etiss_int128 res = (etiss_int128)(x) * (etiss_int128)(y);
return (etiss_int64)((res >> 64ULL));
} // block
}

etiss_int64 RV64IMACFD_mulhsu(etiss_int64 x, etiss_uint64 y)
{
{ // block
etiss_int128 res = (etiss_int128)(x) * (etiss_uint128)(y);
return (etiss_int64)((res >> 64ULL));
} // block
}

etiss_uint64 RV64IMACFD_mulhu(etiss_uint64 x, etiss_uint64 y)
{
{ // block
etiss_uint128 res = (etiss_uint128)(x) * (etiss_uint128)(y);
return (etiss_uint64)((res >> 64ULL));
} // block
}
