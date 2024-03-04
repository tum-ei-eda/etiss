/**
 * Generated on Mon, 04 Mar 2024 18:55:53 +0100.
 *
 * This file contains the function implementations for the RV32IMACFD core architecture.
 */

#include "RV32IMACFDFuncs.h"

etiss_uint8 RV32IMACFD_extension_enabled(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int8 extension)
{
{ // block
return (*((RV32IMACFD*)cpu)->CSR[769LL] >> (extension - 65ULL)) & 1ULL;
etiss_coverage_count(2, 8, 7);
} // block
}

etiss_uint8 RV32IMACFD_get_rm(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint8 rm)
{
{ // block
if (rm == 7ULL) { // conditional
etiss_coverage_count(2, 12, 11);
rm = ((((((RV32IMACFD*)cpu)->FCSR) >> (5ULL)) & 7)) & 0x7;
etiss_coverage_count(3, 16, 13, 15);
} // conditional
if (rm > 4ULL) { // conditional
etiss_coverage_count(2, 19, 18);
RV32IMACFD_raise(cpu, system, plugin_pointers, 0ULL, 2LL);
etiss_coverage_count(1, 21);
} // conditional
return rm;
etiss_coverage_count(1, 23);
} // block
}

etiss_uint32 RV32IMACFD_sstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
{ // block
etiss_uint32 mask = 0ULL;
etiss_coverage_count(1, 27);
if (RV32IMACFD_extension_enabled(cpu, system, plugin_pointers, 83ULL)) { // conditional
etiss_coverage_count(1, 28);
{ // block
mask = mask | 5767458ULL;
etiss_coverage_count(2, 43, 29);
if (RV32IMACFD_extension_enabled(cpu, system, plugin_pointers, 86ULL)) { // conditional
etiss_coverage_count(1, 44);
mask = mask | 1536LL;
etiss_coverage_count(2, 47, 45);
} // conditional
if (RV32IMACFD_extension_enabled(cpu, system, plugin_pointers, 70ULL)) { // conditional
etiss_coverage_count(1, 49);
mask = mask | 24576LL;
etiss_coverage_count(2, 52, 50);
} // conditional
if (RV32IMACFD_extension_enabled(cpu, system, plugin_pointers, 88ULL)) { // conditional
etiss_coverage_count(1, 54);
mask = mask | 98304LL;
etiss_coverage_count(2, 57, 55);
} // conditional
if ((RV32IMACFD_get_field(*((RV32IMACFD*)cpu)->CSR[384LL], 2147483648ULL))) { // conditional
etiss_coverage_count(1, 65);
mask = mask | 262144LL;
etiss_coverage_count(2, 80, 78);
} // conditional
} // block
} // conditional
return mask;
etiss_coverage_count(1, 84);
} // block
}

etiss_uint32 RV32IMACFD_mstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
{ // block
etiss_uint32 mask = 6280ULL;
etiss_coverage_count(1, 95);
return mask | RV32IMACFD_sstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(3, 98, 96, 97);
} // block
}

etiss_uint32 RV32IMACFD_csr_read(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr)
{
{ // block
if (csr == 1LL) { // conditional
etiss_coverage_count(2, 103, 101);
return *((RV32IMACFD*)cpu)->CSR[3LL] & 31ULL;
etiss_coverage_count(2, 107, 106);
} // conditional
if (csr == 2LL) { // conditional
etiss_coverage_count(2, 112, 110);
return (*((RV32IMACFD*)cpu)->CSR[3LL] >> 5ULL) & 7ULL;
etiss_coverage_count(2, 118, 117);
} // conditional
if (csr == 3072LL) { // conditional
etiss_coverage_count(2, 123, 121);
return etiss_get_cycles(cpu, system, plugin_pointers);
etiss_coverage_count(1, 124);
} // conditional
if (csr == 3200LL) { // conditional
etiss_coverage_count(2, 129, 127);
return etiss_get_cycles(cpu, system, plugin_pointers) >> 32ULL;
etiss_coverage_count(2, 131, 130);
} // conditional
if (csr == 3073LL) { // conditional
etiss_coverage_count(2, 136, 134);
return etiss_get_time();
etiss_coverage_count(1, 137);
} // conditional
if (csr == 3201LL) { // conditional
etiss_coverage_count(2, 142, 140);
return etiss_get_time() >> 32ULL;
etiss_coverage_count(2, 144, 143);
} // conditional
if (csr == 3074LL) { // conditional
etiss_coverage_count(2, 149, 147);
return etiss_get_instret(cpu, system, plugin_pointers);
etiss_coverage_count(1, 150);
} // conditional
if (csr == 3202LL) { // conditional
etiss_coverage_count(2, 155, 153);
return etiss_get_instret(cpu, system, plugin_pointers) >> 32ULL;
etiss_coverage_count(2, 157, 156);
} // conditional
if (csr == 768LL || csr == 256LL) { // conditional
etiss_coverage_count(3, 166, 162, 165);
return *((RV32IMACFD*)cpu)->CSR[768LL] | 8589934592ULL | 34359738368ULL;
etiss_coverage_count(2, 183, 176);
} // conditional
if (csr == 769LL) { // conditional
etiss_coverage_count(2, 188, 186);
return (((1ULL) << 30) | ((((*((RV32IMACFD*)cpu)->CSR[769LL]) >> (0ULL)) & 1073741823)));
etiss_coverage_count(2, 198, 197);
} // conditional
return *((RV32IMACFD*)cpu)->CSR[csr];
etiss_coverage_count(2, 203, 202);
} // block
}

void RV32IMACFD_csr_write(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr, etiss_uint32 val)
{
{ // block
if (csr == 3860LL) { // conditional
etiss_coverage_count(2, 208, 206);
return;
etiss_coverage_count(1, 209);
} // conditional
if (csr == 1LL) { // conditional
etiss_coverage_count(2, 213, 211);
*((RV32IMACFD*)cpu)->CSR[3LL] = (*((RV32IMACFD*)cpu)->CSR[3LL] & 224ULL) | (val & 31ULL);
etiss_coverage_count(3, 243, 231, 242);
} // conditional
 else if (csr == 2LL) { // conditional
etiss_coverage_count(2, 216, 214);
*((RV32IMACFD*)cpu)->CSR[3LL] = ((val & 7ULL) << 5ULL) | (*((RV32IMACFD*)cpu)->CSR[3LL] & 31ULL);
etiss_coverage_count(3, 258, 246, 257);
} // conditional
 else if (csr == 3LL) { // conditional
etiss_coverage_count(2, 219, 217);
*((RV32IMACFD*)cpu)->CSR[3LL] = val & 255ULL;
etiss_coverage_count(3, 264, 261, 263);
} // conditional
 else if (csr == 768LL) { // conditional
etiss_coverage_count(2, 222, 220);
*((RV32IMACFD*)cpu)->CSR[768LL] = val & RV32IMACFD_mstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(3, 271, 267, 270);
} // conditional
 else if (csr == 256LL) { // conditional
etiss_coverage_count(2, 225, 223);
*((RV32IMACFD*)cpu)->CSR[768LL] = val & RV32IMACFD_sstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(3, 278, 274, 277);
} // conditional
 else if (csr != 769LL) { // conditional
etiss_coverage_count(2, 228, 226);
*((RV32IMACFD*)cpu)->CSR[csr] = val;
etiss_coverage_count(3, 283, 281, 282);
} // conditional
if (csr == 384LL) { // conditional
etiss_coverage_count(2, 287, 285);
ETISS_SIGNAL_MMU(cpu, system, plugin_pointers, val);
etiss_coverage_count(1, 289);
} // conditional
} // block
}

etiss_uint64 RV32IMACFD_get_field(etiss_uint64 reg, etiss_uint64 mask)
{
{ // block
if (!(mask)) { // conditional
etiss_coverage_count(2, 293, 292);
return 0ULL;
} // conditional
return (reg & mask) / (mask & ~((mask << 1ULL)));
etiss_coverage_count(3, 307, 299, 306);
} // block
}

etiss_uint64 RV32IMACFD_set_field(etiss_uint64 reg, etiss_uint64 mask, etiss_uint64 val)
{
{ // block
return ((reg & ~(mask)) | ((val * (mask & ~((mask << 1ULL)))) & mask));
etiss_coverage_count(3, 328, 314, 327);
} // block
}

etiss_uint8 RV32IMACFD_ctz(etiss_uint64 val)
{
{ // block
if (!(val)) { // conditional
etiss_coverage_count(2, 333, 332);
return 0ULL;
} // conditional
etiss_uint8 res = 0ULL;
etiss_coverage_count(1, 336);
if ((val << 32ULL) == 0ULL) { // conditional
etiss_coverage_count(2, 340, 339);
{ // block
res = res + 32ULL;
etiss_coverage_count(2, 342, 341);
val = val >> 32ULL;
etiss_coverage_count(2, 344, 343);
} // block
} // conditional
if ((val << 48ULL) == 0ULL) { // conditional
etiss_coverage_count(2, 350, 349);
{ // block
res = res + 16ULL;
etiss_coverage_count(2, 352, 351);
val = val >> 16ULL;
etiss_coverage_count(2, 354, 353);
} // block
} // conditional
if ((val << 56ULL) == 0ULL) { // conditional
etiss_coverage_count(2, 360, 359);
{ // block
res = res + 8ULL;
etiss_coverage_count(2, 362, 361);
val = val >> 8ULL;
etiss_coverage_count(2, 364, 363);
} // block
} // conditional
if ((val << 60ULL) == 0ULL) { // conditional
etiss_coverage_count(2, 370, 369);
{ // block
res = res + 4ULL;
etiss_coverage_count(2, 372, 371);
val = val >> 4ULL;
etiss_coverage_count(2, 374, 373);
} // block
} // conditional
if ((val << 62ULL) == 0ULL) { // conditional
etiss_coverage_count(2, 380, 379);
{ // block
res = res + 2ULL;
etiss_coverage_count(2, 382, 381);
val = val >> 2ULL;
etiss_coverage_count(2, 384, 383);
} // block
} // conditional
if ((val << 63ULL) == 0ULL) { // conditional
etiss_coverage_count(2, 390, 389);
{ // block
res = res + 1ULL;
etiss_coverage_count(2, 392, 391);
val = val >> 1ULL;
etiss_coverage_count(2, 394, 393);
} // block
} // conditional
return res;
etiss_coverage_count(1, 397);
} // block
}

void RV32IMACFD_raise(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 irq, etiss_uint32 mcause)
{
cpu->return_pending = 1;
cpu->exception = 0;
{ // block
etiss_uint32 epc = cpu->instructionPointer;
etiss_coverage_count(2, 402, 401);
etiss_uint32 deleg = 0ULL;
etiss_coverage_count(1, 404);
etiss_uint32 vector = 0ULL;
etiss_coverage_count(1, 405);
etiss_uint32 bit = mcause;
etiss_coverage_count(2, 407, 406);
etiss_int32 irq2 = (mcause & 2147483648ULL) != 0ULL;
etiss_coverage_count(2, 418, 417);
if (irq2) { // conditional
etiss_coverage_count(1, 419);
{ // block
deleg = ((((RV32IMACFD*)cpu)->PRIV <= 1LL)) ? (*((RV32IMACFD*)cpu)->CSR[771LL]) : (0ULL);
etiss_coverage_count(3, 429, 420, 428);
bit = bit & 2147483647ULL;
etiss_coverage_count(2, 438, 430);
} // block
} // conditional
else { // conditional
{ // block
deleg = ((((RV32IMACFD*)cpu)->PRIV <= 1LL)) ? (*((RV32IMACFD*)cpu)->CSR[770LL]) : (0ULL);
etiss_coverage_count(3, 449, 440, 448);
} // block
} // conditional
if (((RV32IMACFD*)cpu)->PRIV <= 1LL && (deleg >> bit) & 1ULL) { // conditional
etiss_coverage_count(3, 460, 454, 459);
{ // block
vector = ((*((RV32IMACFD*)cpu)->CSR[261LL] & 1ULL) && irq2) ? (bit * 4ULL) : (0ULL);
etiss_coverage_count(3, 472, 461, 471);
cpu->nextPc = (*((RV32IMACFD*)cpu)->CSR[261LL] & -2LL) + vector;
etiss_coverage_count(3, 483, 473, 482);
*((RV32IMACFD*)cpu)->CSR[321LL] = epc;
etiss_coverage_count(3, 488, 486, 487);
*((RV32IMACFD*)cpu)->CSR[322LL] = mcause;
etiss_coverage_count(3, 493, 491, 492);
etiss_uint32 s = RV32IMACFD_csr_read(cpu, system, plugin_pointers, 256LL);
etiss_coverage_count(2, 497, 496);
s = RV32IMACFD_set_field(s, 32LL, RV32IMACFD_get_field(s, 2LL));
etiss_coverage_count(3, 505, 498, 504);
s = RV32IMACFD_set_field(s, 256LL, ((RV32IMACFD*)cpu)->PRIV);
etiss_coverage_count(3, 511, 506, 510);
s = RV32IMACFD_set_field(s, 2LL, 0ULL);
etiss_coverage_count(3, 516, 512, 515);
RV32IMACFD_csr_write(cpu, system, plugin_pointers, 256LL, s);
etiss_coverage_count(1, 519);
((RV32IMACFD*)cpu)->PRIV = (1LL) & 0x7;
etiss_coverage_count(2, 522, 520);
} // block
} // conditional
else { // conditional
{ // block
vector = ((*((RV32IMACFD*)cpu)->CSR[773LL] & 1ULL) && irq2) ? (bit * 4ULL) : (0ULL);
etiss_coverage_count(3, 535, 524, 534);
cpu->nextPc = (*((RV32IMACFD*)cpu)->CSR[773LL] & -2LL) + vector;
etiss_coverage_count(3, 546, 536, 545);
*((RV32IMACFD*)cpu)->CSR[833LL] = epc;
etiss_coverage_count(3, 551, 549, 550);
*((RV32IMACFD*)cpu)->CSR[834LL] = mcause;
etiss_coverage_count(3, 556, 554, 555);
etiss_uint32 s = RV32IMACFD_csr_read(cpu, system, plugin_pointers, 768LL);
etiss_coverage_count(2, 560, 559);
s = RV32IMACFD_set_field(s, 128LL, RV32IMACFD_get_field(s, 8LL));
etiss_coverage_count(3, 568, 561, 567);
s = RV32IMACFD_set_field(s, 6144LL, ((RV32IMACFD*)cpu)->PRIV);
etiss_coverage_count(3, 574, 569, 573);
s = RV32IMACFD_set_field(s, 8LL, 0ULL);
etiss_coverage_count(3, 579, 575, 578);
RV32IMACFD_csr_write(cpu, system, plugin_pointers, 768LL, s);
etiss_coverage_count(1, 582);
((RV32IMACFD*)cpu)->PRIV = (3LL) & 0x7;
etiss_coverage_count(2, 585, 583);
} // block
} // conditional
} // block
}

void RV32IMACFD_translate_exc_code(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 cause)
{
{ // block
etiss_uint32 code = 0ULL;
etiss_coverage_count(1, 591);
if (cause == -2147483648LL) { // conditional
etiss_coverage_count(2, 594, 592);
return;
etiss_coverage_count(1, 616);
} // conditional
 else if (cause == -5LL) { // conditional
etiss_coverage_count(2, 597, 595);
code = 5LL;
etiss_coverage_count(2, 619, 617);
} // conditional
 else if (cause == -13LL) { // conditional
etiss_coverage_count(2, 600, 598);
code = 12LL;
etiss_coverage_count(2, 622, 620);
} // conditional
 else if (cause == -14LL) { // conditional
etiss_coverage_count(2, 603, 601);
code = 13LL;
etiss_coverage_count(2, 625, 623);
} // conditional
 else if (cause == -6LL) { // conditional
etiss_coverage_count(2, 606, 604);
code = 7LL;
etiss_coverage_count(2, 628, 626);
} // conditional
 else if (cause == -15LL) { // conditional
etiss_coverage_count(2, 609, 607);
code = 15LL;
etiss_coverage_count(2, 631, 629);
} // conditional
 else if (cause == -7LL) { // conditional
etiss_coverage_count(2, 612, 610);
code = 1LL;
etiss_coverage_count(2, 634, 632);
} // conditional
 else if (cause == -9LL) { // conditional
etiss_coverage_count(2, 615, 613);
{ // block
code = RV32IMACFD_calc_irq_mcause(cpu, system, plugin_pointers);
etiss_coverage_count(3, 637, 635, 636);
if (!(code)) { // conditional
etiss_coverage_count(2, 639, 638);
return;
etiss_coverage_count(1, 640);
} // conditional
} // block
} // conditional
else { // conditional
code = 2LL;
etiss_coverage_count(2, 645, 643);
} // conditional
RV32IMACFD_raise(cpu, system, plugin_pointers, 0ULL, code);
etiss_coverage_count(1, 648);
} // block
}

etiss_uint32 RV32IMACFD_calc_irq_mcause(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
{ // block
etiss_uint32 pending_interrupts = *((RV32IMACFD*)cpu)->CSR[772LL] & *((RV32IMACFD*)cpu)->CSR[836LL];
etiss_coverage_count(2, 658, 657);
if (!(pending_interrupts)) { // conditional
etiss_coverage_count(2, 660, 659);
return 0ULL;
} // conditional
etiss_uint32 mie = RV32IMACFD_get_field(*((RV32IMACFD*)cpu)->CSR[768LL], 8LL);
etiss_coverage_count(2, 669, 668);
etiss_uint32 m_enabled = ((RV32IMACFD*)cpu)->PRIV < 3LL || (((RV32IMACFD*)cpu)->PRIV == 3LL && mie);
etiss_coverage_count(2, 681, 680);
etiss_uint32 enabled_interrupts = pending_interrupts & ~(*((RV32IMACFD*)cpu)->CSR[771LL]) & -(m_enabled);
etiss_coverage_count(2, 692, 691);
if (enabled_interrupts == 0ULL) { // conditional
etiss_coverage_count(2, 694, 693);
{ // block
etiss_uint32 deleg = *((RV32IMACFD*)cpu)->CSR[771LL];
etiss_coverage_count(2, 699, 698);
etiss_uint32 sie = RV32IMACFD_get_field(RV32IMACFD_csr_read(cpu, system, plugin_pointers, 256LL), 2LL);
etiss_coverage_count(2, 705, 704);
etiss_uint32 s_enabled = ((RV32IMACFD*)cpu)->PRIV < 1LL || (((RV32IMACFD*)cpu)->PRIV == 1LL && sie);
etiss_coverage_count(2, 717, 716);
enabled_interrupts = pending_interrupts & deleg & -(s_enabled);
etiss_coverage_count(3, 725, 718, 724);
} // block
} // conditional
if (enabled_interrupts) { // conditional
etiss_coverage_count(1, 728);
{ // block
if (enabled_interrupts >> 12ULL) { // conditional
etiss_coverage_count(2, 733, 729);
enabled_interrupts = enabled_interrupts >> 12ULL << 12ULL;
etiss_coverage_count(3, 774, 764, 773);
} // conditional
 else if (enabled_interrupts & 2048LL) { // conditional
etiss_coverage_count(2, 736, 734);
enabled_interrupts = 2048LL;
etiss_coverage_count(2, 777, 775);
} // conditional
 else if (enabled_interrupts & 8LL) { // conditional
etiss_coverage_count(2, 739, 737);
enabled_interrupts = 8LL;
etiss_coverage_count(2, 780, 778);
} // conditional
 else if (enabled_interrupts & 128LL) { // conditional
etiss_coverage_count(2, 742, 740);
enabled_interrupts = 128LL;
etiss_coverage_count(2, 783, 781);
} // conditional
 else if (enabled_interrupts & 512LL) { // conditional
etiss_coverage_count(2, 745, 743);
enabled_interrupts = 512LL;
etiss_coverage_count(2, 786, 784);
} // conditional
 else if (enabled_interrupts & 2LL) { // conditional
etiss_coverage_count(2, 748, 746);
enabled_interrupts = 2LL;
etiss_coverage_count(2, 789, 787);
} // conditional
 else if (enabled_interrupts & 32LL) { // conditional
etiss_coverage_count(2, 751, 749);
enabled_interrupts = 32LL;
etiss_coverage_count(2, 792, 790);
} // conditional
 else if (enabled_interrupts & 8192LL) { // conditional
etiss_coverage_count(2, 754, 752);
enabled_interrupts = 8192LL;
etiss_coverage_count(2, 795, 793);
} // conditional
 else if (enabled_interrupts & 1024LL) { // conditional
etiss_coverage_count(2, 757, 755);
enabled_interrupts = 1024LL;
etiss_coverage_count(2, 798, 796);
} // conditional
 else if (enabled_interrupts & 4LL) { // conditional
etiss_coverage_count(2, 760, 758);
enabled_interrupts = 4LL;
etiss_coverage_count(2, 801, 799);
} // conditional
 else if (enabled_interrupts & 64LL) { // conditional
etiss_coverage_count(2, 763, 761);
enabled_interrupts = 64LL;
etiss_coverage_count(2, 804, 802);
} // conditional
else { // conditional
return 0ULL;
} // conditional
return 2147483648ULL | RV32IMACFD_ctz(enabled_interrupts);
etiss_coverage_count(2, 815, 814);
} // block
} // conditional
return 0ULL;
} // block
}

void RV32IMACFD_check_irq(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
{ // block
etiss_uint32 irq_mcause = RV32IMACFD_calc_irq_mcause(cpu, system, plugin_pointers);
etiss_coverage_count(2, 823, 822);
if (irq_mcause) { // conditional
etiss_coverage_count(1, 824);
RV32IMACFD_raise(cpu, system, plugin_pointers, 1ULL, irq_mcause);
etiss_coverage_count(1, 826);
} // conditional
} // block
}
