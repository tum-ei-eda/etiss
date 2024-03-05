/**
 * Generated on Tue, 05 Mar 2024 21:20:27 +0100.
 *
 * This file contains the function implementations for the RV32IMACFD core architecture.
 */

#include "RV32IMACFDFuncs.h"

etiss_uint8 RV32IMACFD_extension_enabled(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int8 extension)
{
{ // block
etiss_coverage_count(1, 10);
return (*((RV32IMACFD*)cpu)->CSR[769LL] >> (extension - 65ULL)) & 1ULL;
etiss_coverage_count(2, 8, 7);
} // block
}

etiss_uint8 RV32IMACFD_get_rm(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint8 rm)
{
{ // block
etiss_coverage_count(1, 25);
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
etiss_coverage_count(1, 86);
etiss_uint32 mask = 0ULL;
etiss_coverage_count(1, 27);
if (RV32IMACFD_extension_enabled(cpu, system, plugin_pointers, 83ULL)) { // conditional
etiss_coverage_count(1, 28);
{ // block
etiss_coverage_count(1, 82);
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
etiss_coverage_count(1, 100);
etiss_uint32 mask = 6280ULL;
etiss_coverage_count(1, 95);
return mask | RV32IMACFD_sstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(3, 98, 96, 97);
} // block
}

etiss_uint32 RV32IMACFD_csr_read(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr)
{
{ // block
etiss_coverage_count(1, 205);
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
etiss_coverage_count(1, 280);
if (csr == 1LL) { // conditional
etiss_coverage_count(2, 208, 206);
*((RV32IMACFD*)cpu)->CSR[3LL] = (*((RV32IMACFD*)cpu)->CSR[3LL] & 224ULL) | (val & 31ULL);
etiss_coverage_count(3, 238, 226, 237);
} // conditional
 else if (csr == 2LL) { // conditional
etiss_coverage_count(2, 211, 209);
*((RV32IMACFD*)cpu)->CSR[3LL] = ((val & 7ULL) << 5ULL) | (*((RV32IMACFD*)cpu)->CSR[3LL] & 31ULL);
etiss_coverage_count(3, 253, 241, 252);
} // conditional
 else if (csr == 3LL) { // conditional
etiss_coverage_count(2, 214, 212);
*((RV32IMACFD*)cpu)->CSR[3LL] = val & 255ULL;
etiss_coverage_count(3, 259, 256, 258);
} // conditional
 else if (csr == 768LL) { // conditional
etiss_coverage_count(2, 217, 215);
*((RV32IMACFD*)cpu)->CSR[768LL] = val & RV32IMACFD_mstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(3, 266, 262, 265);
} // conditional
 else if (csr == 256LL) { // conditional
etiss_coverage_count(2, 220, 218);
*((RV32IMACFD*)cpu)->CSR[768LL] = val & RV32IMACFD_sstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(3, 273, 269, 272);
} // conditional
 else if (csr != 769LL) { // conditional
etiss_coverage_count(2, 223, 221);
*((RV32IMACFD*)cpu)->CSR[csr] = val;
etiss_coverage_count(3, 278, 276, 277);
} // conditional
} // block
}

etiss_uint64 RV32IMACFD_get_field(etiss_uint64 reg, etiss_uint64 mask)
{
{ // block
etiss_coverage_count(1, 298);
if (!(mask)) { // conditional
etiss_coverage_count(2, 282, 281);
return 0ULL;
} // conditional
return (reg & mask) / (mask & ~((mask << 1ULL)));
etiss_coverage_count(3, 296, 288, 295);
} // block
}

etiss_uint64 RV32IMACFD_set_field(etiss_uint64 reg, etiss_uint64 mask, etiss_uint64 val)
{
{ // block
etiss_coverage_count(1, 320);
return ((reg & ~(mask)) | ((val * (mask & ~((mask << 1ULL)))) & mask));
etiss_coverage_count(3, 317, 303, 316);
} // block
}

etiss_uint8 RV32IMACFD_ctz(etiss_uint64 val)
{
{ // block
etiss_coverage_count(1, 388);
if (!(val)) { // conditional
etiss_coverage_count(2, 322, 321);
return 0ULL;
} // conditional
etiss_uint8 res = 0ULL;
etiss_coverage_count(1, 325);
if ((val << 32ULL) == 0ULL) { // conditional
etiss_coverage_count(2, 329, 328);
{ // block
etiss_coverage_count(1, 334);
res = res + 32ULL;
etiss_coverage_count(2, 331, 330);
val = val >> 32ULL;
etiss_coverage_count(2, 333, 332);
} // block
} // conditional
if ((val << 48ULL) == 0ULL) { // conditional
etiss_coverage_count(2, 339, 338);
{ // block
etiss_coverage_count(1, 344);
res = res + 16ULL;
etiss_coverage_count(2, 341, 340);
val = val >> 16ULL;
etiss_coverage_count(2, 343, 342);
} // block
} // conditional
if ((val << 56ULL) == 0ULL) { // conditional
etiss_coverage_count(2, 349, 348);
{ // block
etiss_coverage_count(1, 354);
res = res + 8ULL;
etiss_coverage_count(2, 351, 350);
val = val >> 8ULL;
etiss_coverage_count(2, 353, 352);
} // block
} // conditional
if ((val << 60ULL) == 0ULL) { // conditional
etiss_coverage_count(2, 359, 358);
{ // block
etiss_coverage_count(1, 364);
res = res + 4ULL;
etiss_coverage_count(2, 361, 360);
val = val >> 4ULL;
etiss_coverage_count(2, 363, 362);
} // block
} // conditional
if ((val << 62ULL) == 0ULL) { // conditional
etiss_coverage_count(2, 369, 368);
{ // block
etiss_coverage_count(1, 374);
res = res + 2ULL;
etiss_coverage_count(2, 371, 370);
val = val >> 2ULL;
etiss_coverage_count(2, 373, 372);
} // block
} // conditional
if ((val << 63ULL) == 0ULL) { // conditional
etiss_coverage_count(2, 379, 378);
{ // block
etiss_coverage_count(1, 384);
res = res + 1ULL;
etiss_coverage_count(2, 381, 380);
val = val >> 1ULL;
etiss_coverage_count(2, 383, 382);
} // block
} // conditional
return res;
etiss_coverage_count(1, 386);
} // block
}

void RV32IMACFD_raise(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 irq, etiss_uint32 mcause)
{
cpu->return_pending = 1;
cpu->exception = 0;
{ // block
etiss_coverage_count(1, 577);
etiss_uint32 epc = cpu->instructionPointer;
etiss_coverage_count(2, 391, 390);
etiss_uint32 deleg = 0ULL;
etiss_coverage_count(1, 393);
etiss_uint32 vector = 0ULL;
etiss_coverage_count(1, 394);
etiss_uint32 bit = mcause;
etiss_coverage_count(2, 396, 395);
etiss_int32 irq2 = (mcause & 2147483648ULL) != 0ULL;
etiss_coverage_count(2, 407, 406);
if (irq2) { // conditional
etiss_coverage_count(1, 408);
{ // block
etiss_coverage_count(1, 428);
deleg = ((((RV32IMACFD*)cpu)->PRIV <= 1LL)) ? (*((RV32IMACFD*)cpu)->CSR[771LL]) : (0ULL);
etiss_coverage_count(3, 418, 409, 417);
bit = bit & 2147483647ULL;
etiss_coverage_count(2, 427, 419);
} // block
} // conditional
else { // conditional
{ // block
etiss_coverage_count(1, 439);
deleg = ((((RV32IMACFD*)cpu)->PRIV <= 1LL)) ? (*((RV32IMACFD*)cpu)->CSR[770LL]) : (0ULL);
etiss_coverage_count(3, 438, 429, 437);
} // block
} // conditional
if (((RV32IMACFD*)cpu)->PRIV <= 1LL && (deleg >> bit) & 1ULL) { // conditional
etiss_coverage_count(3, 449, 443, 448);
{ // block
etiss_coverage_count(1, 512);
vector = ((*((RV32IMACFD*)cpu)->CSR[261LL] & 1ULL) && irq2) ? (bit * 4ULL) : (0ULL);
etiss_coverage_count(3, 461, 450, 460);
cpu->nextPc = (*((RV32IMACFD*)cpu)->CSR[261LL] & -2LL) + vector;
etiss_coverage_count(3, 472, 462, 471);
*((RV32IMACFD*)cpu)->CSR[321LL] = epc;
etiss_coverage_count(3, 477, 475, 476);
*((RV32IMACFD*)cpu)->CSR[322LL] = mcause;
etiss_coverage_count(3, 482, 480, 481);
etiss_uint32 s = RV32IMACFD_csr_read(cpu, system, plugin_pointers, 256LL);
etiss_coverage_count(2, 486, 485);
s = RV32IMACFD_set_field(s, 32LL, RV32IMACFD_get_field(s, 2LL));
etiss_coverage_count(3, 494, 487, 493);
s = RV32IMACFD_set_field(s, 256LL, ((RV32IMACFD*)cpu)->PRIV);
etiss_coverage_count(3, 500, 495, 499);
s = RV32IMACFD_set_field(s, 2LL, 0ULL);
etiss_coverage_count(3, 505, 501, 504);
RV32IMACFD_csr_write(cpu, system, plugin_pointers, 256LL, s);
etiss_coverage_count(1, 508);
((RV32IMACFD*)cpu)->PRIV = (1LL) & 0x7;
etiss_coverage_count(2, 511, 509);
} // block
} // conditional
else { // conditional
{ // block
etiss_coverage_count(1, 575);
vector = ((*((RV32IMACFD*)cpu)->CSR[773LL] & 1ULL) && irq2) ? (bit * 4ULL) : (0ULL);
etiss_coverage_count(3, 524, 513, 523);
cpu->nextPc = (*((RV32IMACFD*)cpu)->CSR[773LL] & -2LL) + vector;
etiss_coverage_count(3, 535, 525, 534);
*((RV32IMACFD*)cpu)->CSR[833LL] = epc;
etiss_coverage_count(3, 540, 538, 539);
*((RV32IMACFD*)cpu)->CSR[834LL] = mcause;
etiss_coverage_count(3, 545, 543, 544);
etiss_uint32 s = RV32IMACFD_csr_read(cpu, system, plugin_pointers, 768LL);
etiss_coverage_count(2, 549, 548);
s = RV32IMACFD_set_field(s, 128LL, RV32IMACFD_get_field(s, 8LL));
etiss_coverage_count(3, 557, 550, 556);
s = RV32IMACFD_set_field(s, 6144LL, ((RV32IMACFD*)cpu)->PRIV);
etiss_coverage_count(3, 563, 558, 562);
s = RV32IMACFD_set_field(s, 8LL, 0ULL);
etiss_coverage_count(3, 568, 564, 567);
RV32IMACFD_csr_write(cpu, system, plugin_pointers, 768LL, s);
etiss_coverage_count(1, 571);
((RV32IMACFD*)cpu)->PRIV = (3LL) & 0x7;
etiss_coverage_count(2, 574, 572);
} // block
} // conditional
} // block
}

void RV32IMACFD_translate_exc_code(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 cause)
{
{ // block
etiss_coverage_count(1, 632);
etiss_uint32 code = 0ULL;
etiss_coverage_count(1, 580);
if (cause == -2147483648LL) { // conditional
etiss_coverage_count(2, 583, 581);
return;
etiss_coverage_count(1, 602);
} // conditional
 else if (cause == -5LL) { // conditional
etiss_coverage_count(2, 586, 584);
code = 5LL;
etiss_coverage_count(2, 605, 603);
} // conditional
 else if (cause == -14LL) { // conditional
etiss_coverage_count(2, 589, 587);
code = 13LL;
etiss_coverage_count(2, 608, 606);
} // conditional
 else if (cause == -6LL) { // conditional
etiss_coverage_count(2, 592, 590);
code = 7LL;
etiss_coverage_count(2, 611, 609);
} // conditional
 else if (cause == -15LL) { // conditional
etiss_coverage_count(2, 595, 593);
code = 15LL;
etiss_coverage_count(2, 614, 612);
} // conditional
 else if (cause == -7LL) { // conditional
etiss_coverage_count(2, 598, 596);
code = 1LL;
etiss_coverage_count(2, 617, 615);
} // conditional
 else if (cause == -9LL) { // conditional
etiss_coverage_count(2, 601, 599);
{ // block
etiss_coverage_count(1, 625);
code = RV32IMACFD_calc_irq_mcause(cpu, system, plugin_pointers);
etiss_coverage_count(3, 620, 618, 619);
if (!(code)) { // conditional
etiss_coverage_count(2, 622, 621);
return;
etiss_coverage_count(1, 623);
} // conditional
} // block
} // conditional
else { // conditional
code = 2LL;
etiss_coverage_count(2, 628, 626);
} // conditional
RV32IMACFD_raise(cpu, system, plugin_pointers, 0ULL, code);
etiss_coverage_count(1, 631);
} // block
}

etiss_uint32 RV32IMACFD_calc_irq_mcause(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
{ // block
etiss_coverage_count(1, 803);
etiss_uint32 pending_interrupts = *((RV32IMACFD*)cpu)->CSR[772LL] & *((RV32IMACFD*)cpu)->CSR[836LL];
etiss_coverage_count(2, 641, 640);
if (!(pending_interrupts)) { // conditional
etiss_coverage_count(2, 643, 642);
return 0ULL;
} // conditional
etiss_uint32 mie = RV32IMACFD_get_field(*((RV32IMACFD*)cpu)->CSR[768LL], 8LL);
etiss_coverage_count(2, 652, 651);
etiss_uint32 m_enabled = ((RV32IMACFD*)cpu)->PRIV < 3LL || (((RV32IMACFD*)cpu)->PRIV == 3LL && mie);
etiss_coverage_count(2, 664, 663);
etiss_uint32 enabled_interrupts = pending_interrupts & ~(*((RV32IMACFD*)cpu)->CSR[771LL]) & -(m_enabled);
etiss_coverage_count(2, 675, 674);
if (enabled_interrupts == 0ULL) { // conditional
etiss_coverage_count(2, 677, 676);
{ // block
etiss_coverage_count(1, 709);
etiss_uint32 deleg = *((RV32IMACFD*)cpu)->CSR[771LL];
etiss_coverage_count(2, 682, 681);
etiss_uint32 sie = RV32IMACFD_get_field(RV32IMACFD_csr_read(cpu, system, plugin_pointers, 256LL), 2LL);
etiss_coverage_count(2, 688, 687);
etiss_uint32 s_enabled = ((RV32IMACFD*)cpu)->PRIV < 1LL || (((RV32IMACFD*)cpu)->PRIV == 1LL && sie);
etiss_coverage_count(2, 700, 699);
enabled_interrupts = pending_interrupts & deleg & -(s_enabled);
etiss_coverage_count(3, 708, 701, 707);
} // block
} // conditional
if (enabled_interrupts) { // conditional
etiss_coverage_count(1, 711);
{ // block
etiss_coverage_count(1, 800);
if (enabled_interrupts >> 12ULL) { // conditional
etiss_coverage_count(2, 716, 712);
enabled_interrupts = enabled_interrupts >> 12ULL << 12ULL;
etiss_coverage_count(3, 757, 747, 756);
} // conditional
 else if (enabled_interrupts & 2048LL) { // conditional
etiss_coverage_count(2, 719, 717);
enabled_interrupts = 2048LL;
etiss_coverage_count(2, 760, 758);
} // conditional
 else if (enabled_interrupts & 8LL) { // conditional
etiss_coverage_count(2, 722, 720);
enabled_interrupts = 8LL;
etiss_coverage_count(2, 763, 761);
} // conditional
 else if (enabled_interrupts & 128LL) { // conditional
etiss_coverage_count(2, 725, 723);
enabled_interrupts = 128LL;
etiss_coverage_count(2, 766, 764);
} // conditional
 else if (enabled_interrupts & 512LL) { // conditional
etiss_coverage_count(2, 728, 726);
enabled_interrupts = 512LL;
etiss_coverage_count(2, 769, 767);
} // conditional
 else if (enabled_interrupts & 2LL) { // conditional
etiss_coverage_count(2, 731, 729);
enabled_interrupts = 2LL;
etiss_coverage_count(2, 772, 770);
} // conditional
 else if (enabled_interrupts & 32LL) { // conditional
etiss_coverage_count(2, 734, 732);
enabled_interrupts = 32LL;
etiss_coverage_count(2, 775, 773);
} // conditional
 else if (enabled_interrupts & 8192LL) { // conditional
etiss_coverage_count(2, 737, 735);
enabled_interrupts = 8192LL;
etiss_coverage_count(2, 778, 776);
} // conditional
 else if (enabled_interrupts & 1024LL) { // conditional
etiss_coverage_count(2, 740, 738);
enabled_interrupts = 1024LL;
etiss_coverage_count(2, 781, 779);
} // conditional
 else if (enabled_interrupts & 4LL) { // conditional
etiss_coverage_count(2, 743, 741);
enabled_interrupts = 4LL;
etiss_coverage_count(2, 784, 782);
} // conditional
 else if (enabled_interrupts & 64LL) { // conditional
etiss_coverage_count(2, 746, 744);
enabled_interrupts = 64LL;
etiss_coverage_count(2, 787, 785);
} // conditional
else { // conditional
return 0ULL;
} // conditional
return 2147483648ULL | RV32IMACFD_ctz(enabled_interrupts);
etiss_coverage_count(2, 798, 797);
} // block
} // conditional
return 0ULL;
} // block
}

void RV32IMACFD_check_irq(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
{ // block
etiss_coverage_count(1, 811);
etiss_uint32 irq_mcause = RV32IMACFD_calc_irq_mcause(cpu, system, plugin_pointers);
etiss_coverage_count(2, 806, 805);
if (irq_mcause) { // conditional
etiss_coverage_count(1, 807);
RV32IMACFD_raise(cpu, system, plugin_pointers, 1ULL, irq_mcause);
etiss_coverage_count(1, 809);
} // conditional
} // block
}
