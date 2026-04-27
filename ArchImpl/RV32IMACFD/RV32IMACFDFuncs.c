/**
 * Generated on Mon, 27 Apr 2026 10:48:14 +0000.
 *
 * This file contains the function implementations for the RV32IMACFD core architecture.
 */

#include "RV32IMACFDFuncs.h"
// clang-format off

etiss_uint8 RV32IMACFD_extension_enabled(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int8 extension)
{
etiss_coverage_count(1, 80);
{ // block
etiss_coverage_count(1, 257);
etiss_coverage_count(1, 256);
return (*((RV32IMACFD*)cpu)->CSR[769LL] >> (extension - 65ULL)) & 1ULL;
etiss_coverage_count(9, 255, 252, 247, 250, 248, 249, 251, 253, 254);
} // block
}

etiss_uint8 RV32IMACFD_get_rm(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint8 rm)
{
etiss_coverage_count(1, 87);
{ // block
etiss_coverage_count(1, 277);
etiss_coverage_count(1, 258);
if (rm == 7ULL) { // conditional
etiss_coverage_count(3, 261, 259, 260);
rm = ((((((RV32IMACFD*)cpu)->FCSR) >> (5ULL)) & 0x7ULL)) & 0x7ULL;
etiss_coverage_count(6, 267, 262, 266, 263, 264, 265);
} // conditional
etiss_coverage_count(1, 268);
if (rm > 4ULL) { // conditional
etiss_coverage_count(3, 271, 269, 270);
RV32IMACFD_raise(cpu, system, plugin_pointers, 0LL, 2LL);
etiss_coverage_count(2, 274, 272);
} // conditional
etiss_coverage_count(1, 276);
return rm;
etiss_coverage_count(1, 275);
} // block
}

etiss_uint32 RV32IMACFD_sstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 149);
{ // block
etiss_coverage_count(1, 350);
etiss_uint32 mask = 0LL;
etiss_coverage_count(2, 280, 279);
etiss_coverage_count(1, 281);
if (RV32IMACFD_extension_enabled(cpu, system, plugin_pointers, 83ULL)) { // conditional
etiss_coverage_count(2, 283, 282);
{ // block
etiss_coverage_count(1, 347);
mask = mask | 5767458ULL;
etiss_coverage_count(2, 299, 284);
etiss_coverage_count(1, 300);
if (RV32IMACFD_extension_enabled(cpu, system, plugin_pointers, 86ULL)) { // conditional
etiss_coverage_count(2, 302, 301);
mask = mask | 1536LL;
etiss_coverage_count(2, 305, 303);
} // conditional
etiss_coverage_count(1, 306);
if (RV32IMACFD_extension_enabled(cpu, system, plugin_pointers, 70ULL)) { // conditional
etiss_coverage_count(2, 308, 307);
mask = mask | 24576LL;
etiss_coverage_count(2, 311, 309);
} // conditional
etiss_coverage_count(1, 312);
if (RV32IMACFD_extension_enabled(cpu, system, plugin_pointers, 88ULL)) { // conditional
etiss_coverage_count(2, 314, 313);
mask = mask | 98304LL;
etiss_coverage_count(2, 317, 315);
} // conditional
etiss_coverage_count(1, 318);
if ((RV32IMACFD_get_field(*((RV32IMACFD*)cpu)->CSR[384LL], 2147483648ULL))) { // conditional
etiss_coverage_count(3, 328, 324, 330);
mask = mask | 262144LL;
etiss_coverage_count(2, 346, 344);
} // conditional
} // block
} // conditional
etiss_coverage_count(1, 349);
return mask;
etiss_coverage_count(1, 348);
} // block
}

etiss_uint32 RV32IMACFD_mstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 150);
{ // block
etiss_coverage_count(1, 365);
etiss_uint32 mask = 6280ULL;
etiss_coverage_count(1, 360);
etiss_coverage_count(1, 364);
return mask | RV32IMACFD_sstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(3, 363, 361, 362);
} // block
}

etiss_uint32 RV32IMACFD_csr_read(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr)
{
etiss_coverage_count(1, 151);
{ // block
etiss_coverage_count(1, 483);
etiss_coverage_count(1, 366);
if (csr == 1LL) { // conditional
etiss_coverage_count(2, 369, 367);
etiss_coverage_count(1, 375);
return *((RV32IMACFD*)cpu)->CSR[3LL] & 31ULL;
etiss_coverage_count(3, 374, 372, 373);
} // conditional
etiss_coverage_count(1, 376);
if (csr == 2LL) { // conditional
etiss_coverage_count(2, 379, 377);
etiss_coverage_count(1, 388);
return (*((RV32IMACFD*)cpu)->CSR[3LL] >> 5ULL) & 7ULL;
etiss_coverage_count(6, 387, 384, 382, 383, 385, 386);
} // conditional
etiss_coverage_count(1, 389);
if (csr == 3072LL) { // conditional
etiss_coverage_count(2, 392, 390);
etiss_coverage_count(1, 394);
return etiss_get_cycles(cpu, system, plugin_pointers);
etiss_coverage_count(1, 393);
} // conditional
etiss_coverage_count(1, 395);
if (csr == 3200LL) { // conditional
etiss_coverage_count(2, 398, 396);
etiss_coverage_count(1, 402);
return etiss_get_cycles(cpu, system, plugin_pointers) >> 32ULL;
etiss_coverage_count(3, 401, 399, 400);
} // conditional
etiss_coverage_count(1, 403);
if (csr == 3073LL) { // conditional
etiss_coverage_count(2, 406, 404);
etiss_coverage_count(1, 408);
return etiss_get_time();
etiss_coverage_count(1, 407);
} // conditional
etiss_coverage_count(1, 409);
if (csr == 3201LL) { // conditional
etiss_coverage_count(2, 412, 410);
etiss_coverage_count(1, 416);
return etiss_get_time() >> 32ULL;
etiss_coverage_count(3, 415, 413, 414);
} // conditional
etiss_coverage_count(1, 417);
if (csr == 3074LL) { // conditional
etiss_coverage_count(2, 420, 418);
etiss_coverage_count(1, 422);
return etiss_get_instret(cpu, system, plugin_pointers);
etiss_coverage_count(1, 421);
} // conditional
etiss_coverage_count(1, 423);
if (csr == 3202LL) { // conditional
etiss_coverage_count(2, 426, 424);
etiss_coverage_count(1, 430);
return etiss_get_instret(cpu, system, plugin_pointers) >> 32ULL;
etiss_coverage_count(3, 429, 427, 428);
} // conditional
etiss_coverage_count(1, 431);
if (csr == 768LL || csr == 256LL) { // conditional
etiss_coverage_count(5, 438, 434, 432, 437, 435);
etiss_coverage_count(1, 458);
return *((RV32IMACFD*)cpu)->CSR[768LL] | 8589934592ULL | 34359738368ULL;
etiss_coverage_count(3, 457, 449, 441);
} // conditional
etiss_coverage_count(1, 459);
if (csr == 769LL) { // conditional
etiss_coverage_count(2, 462, 460);
etiss_coverage_count(1, 478);
return (((1ULL) << 30) | (((*((RV32IMACFD*)cpu)->CSR[769LL]) & 0x3fffffffULL)));
etiss_coverage_count(4, 477, 476, 471, 475);
} // conditional
etiss_coverage_count(1, 482);
return *((RV32IMACFD*)cpu)->CSR[csr];
etiss_coverage_count(2, 481, 480);
} // block
}

void RV32IMACFD_csr_write(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr, etiss_uint32 val)
{
etiss_coverage_count(1, 152);
{ // block
etiss_coverage_count(1, 565);
etiss_coverage_count(1, 484);
if (csr == 1LL) { // conditional
etiss_coverage_count(2, 487, 485);
*((RV32IMACFD*)cpu)->CSR[3LL] = (*((RV32IMACFD*)cpu)->CSR[3LL] & 224ULL) | (val & 31ULL);
etiss_coverage_count(10, 520, 505, 519, 513, 508, 514, 517, 515, 516, 518);
} // conditional
 else if (csr == 2LL) { // conditional
etiss_coverage_count(2, 490, 488);
*((RV32IMACFD*)cpu)->CSR[3LL] = ((val & 7ULL) << 5ULL) | (*((RV32IMACFD*)cpu)->CSR[3LL] & 31ULL);
etiss_coverage_count(14, 538, 523, 537, 529, 526, 524, 525, 527, 528, 530, 535, 533, 534, 536);
} // conditional
 else if (csr == 3LL) { // conditional
etiss_coverage_count(2, 493, 491);
*((RV32IMACFD*)cpu)->CSR[3LL] = val & 255ULL;
etiss_coverage_count(5, 545, 541, 544, 542, 543);
} // conditional
 else if (csr == 768LL) { // conditional
etiss_coverage_count(2, 496, 494);
*((RV32IMACFD*)cpu)->CSR[768LL] = val & RV32IMACFD_mstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(5, 552, 548, 551, 549, 550);
} // conditional
 else if (csr == 256LL) { // conditional
etiss_coverage_count(2, 499, 497);
*((RV32IMACFD*)cpu)->CSR[768LL] = val & RV32IMACFD_sstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(5, 559, 555, 558, 556, 557);
} // conditional
 else if (csr != 769LL) { // conditional
etiss_coverage_count(2, 502, 500);
*((RV32IMACFD*)cpu)->CSR[csr] = val;
etiss_coverage_count(4, 564, 562, 561, 563);
} // conditional
} // block
}

etiss_uint64 RV32IMACFD_get_field(etiss_uint64 reg, etiss_uint64 mask)
{
etiss_coverage_count(1, 159);
{ // block
etiss_coverage_count(1, 585);
etiss_coverage_count(1, 566);
if (!(mask)) { // conditional
etiss_coverage_count(2, 568, 567);
etiss_coverage_count(1, 570);
return 0LL;
etiss_coverage_count(1, 569);
} // conditional
etiss_coverage_count(1, 584);
return (reg & mask) / (mask & ~((mask << 1ULL)));
etiss_coverage_count(13, 583, 573, 571, 572, 574, 581, 575, 580, 578, 576, 577, 579, 582);
} // block
}

etiss_uint64 RV32IMACFD_set_field(etiss_uint64 reg, etiss_uint64 mask, etiss_uint64 val)
{
etiss_coverage_count(1, 160);
{ // block
etiss_coverage_count(1, 608);
etiss_coverage_count(1, 607);
return ((reg & ~(mask)) | ((val * (mask & ~((mask << 1ULL)))) & mask));
etiss_coverage_count(21, 605, 589, 586, 588, 587, 590, 603, 600, 591, 598, 592, 597, 595, 593, 594, 596, 599, 601, 602, 604, 606);
} // block
}

etiss_uint8 RV32IMACFD_ctz(etiss_uint64 val)
{
etiss_coverage_count(1, 161);
{ // block
etiss_coverage_count(1, 700);
etiss_coverage_count(1, 609);
if (!(val)) { // conditional
etiss_coverage_count(2, 611, 610);
etiss_coverage_count(1, 613);
return 0LL;
etiss_coverage_count(1, 612);
} // conditional
etiss_uint8 res = 0LL;
etiss_coverage_count(2, 616, 615);
etiss_coverage_count(1, 617);
if ((val << 32ULL) == 0LL) { // conditional
etiss_coverage_count(6, 623, 620, 618, 619, 621, 622);
{ // block
etiss_coverage_count(1, 630);
res = res + 32ULL;
etiss_coverage_count(3, 626, 624, 625);
val = val >> 32ULL;
etiss_coverage_count(3, 629, 627, 628);
} // block
} // conditional
etiss_coverage_count(1, 631);
if ((val << 48ULL) == 0LL) { // conditional
etiss_coverage_count(6, 637, 634, 632, 633, 635, 636);
{ // block
etiss_coverage_count(1, 644);
res = res + 16ULL;
etiss_coverage_count(3, 640, 638, 639);
val = val >> 16ULL;
etiss_coverage_count(3, 643, 641, 642);
} // block
} // conditional
etiss_coverage_count(1, 645);
if ((val << 56ULL) == 0LL) { // conditional
etiss_coverage_count(6, 651, 648, 646, 647, 649, 650);
{ // block
etiss_coverage_count(1, 658);
res = res + 8ULL;
etiss_coverage_count(3, 654, 652, 653);
val = val >> 8ULL;
etiss_coverage_count(3, 657, 655, 656);
} // block
} // conditional
etiss_coverage_count(1, 659);
if ((val << 60ULL) == 0LL) { // conditional
etiss_coverage_count(6, 665, 662, 660, 661, 663, 664);
{ // block
etiss_coverage_count(1, 672);
res = res + 4ULL;
etiss_coverage_count(3, 668, 666, 667);
val = val >> 4ULL;
etiss_coverage_count(3, 671, 669, 670);
} // block
} // conditional
etiss_coverage_count(1, 673);
if ((val << 62ULL) == 0LL) { // conditional
etiss_coverage_count(6, 679, 676, 674, 675, 677, 678);
{ // block
etiss_coverage_count(1, 686);
res = res + 2ULL;
etiss_coverage_count(3, 682, 680, 681);
val = val >> 2ULL;
etiss_coverage_count(3, 685, 683, 684);
} // block
} // conditional
etiss_coverage_count(1, 687);
if ((val << 63ULL) == 0LL) { // conditional
etiss_coverage_count(6, 693, 690, 688, 689, 691, 692);
{ // block
etiss_coverage_count(1, 697);
res = res + 1ULL;
etiss_coverage_count(3, 696, 694, 695);
} // block
} // conditional
etiss_coverage_count(1, 699);
return res;
etiss_coverage_count(1, 698);
} // block
}

void RV32IMACFD_raise(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 irq, etiss_uint32 mcause)
{
cpu->return_pending = 1;
cpu->exception = 0;
etiss_coverage_count(1, 162);
{ // block
etiss_coverage_count(1, 929);
etiss_uint32 epc = cpu->instructionPointer;
etiss_coverage_count(2, 703, 702);
etiss_uint32 deleg = 0LL;
etiss_coverage_count(1, 705);
etiss_uint32 vector = 0LL;
etiss_coverage_count(1, 706);
etiss_uint32 bit = mcause;
etiss_coverage_count(2, 708, 707);
etiss_int32 irq2 = (mcause & 2147483648ULL) != 0LL;
etiss_coverage_count(6, 724, 723, 720, 710, 721, 722);
etiss_coverage_count(1, 725);
if (irq2) { // conditional
etiss_coverage_count(1, 726);
{ // block
etiss_coverage_count(1, 751);
deleg = ((((RV32IMACFD*)cpu)->PRIV <= 1LL)) ? (*((RV32IMACFD*)cpu)->CSR[771LL]) : (0LL);
etiss_coverage_count(8, 737, 727, 736, 730, 728, 731, 734, 735);
bit = bit & 2147483647ULL;
etiss_coverage_count(2, 750, 738);
} // block
} // conditional
else { // conditional
{ // block
etiss_coverage_count(1, 763);
deleg = ((((RV32IMACFD*)cpu)->PRIV <= 1LL)) ? (*((RV32IMACFD*)cpu)->CSR[770LL]) : (0LL);
etiss_coverage_count(8, 762, 752, 761, 755, 753, 756, 759, 760);
} // block
} // conditional
etiss_coverage_count(1, 764);
if (((RV32IMACFD*)cpu)->PRIV <= 1LL && (deleg >> bit) & 1ULL) { // conditional
etiss_coverage_count(9, 774, 767, 765, 773, 770, 768, 769, 771, 772);
{ // block
etiss_coverage_count(1, 851);
vector = ((*((RV32IMACFD*)cpu)->CSR[261LL] & 1ULL) && irq2) ? (bit * 4ULL) : (0LL);
etiss_coverage_count(13, 789, 775, 788, 783, 780, 778, 779, 781, 782, 786, 784, 785, 787);
cpu->nextPc = (*((RV32IMACFD*)cpu)->CSR[261LL] & -2LL) + vector;
etiss_coverage_count(7, 802, 790, 801, 798, 793, 799, 800);
*((RV32IMACFD*)cpu)->CSR[321LL] = epc;
etiss_coverage_count(3, 807, 805, 806);
*((RV32IMACFD*)cpu)->CSR[322LL] = mcause;
etiss_coverage_count(3, 812, 810, 811);
etiss_uint32 s = RV32IMACFD_csr_read(cpu, system, plugin_pointers, 256LL);
etiss_coverage_count(2, 816, 815);
s = (etiss_uint32)(RV32IMACFD_set_field(s, 32LL, RV32IMACFD_get_field(s, 2LL)));
etiss_coverage_count(7, 826, 817, 825, 823, 818, 822, 820);
s = (etiss_uint32)(RV32IMACFD_set_field(s, 256LL, ((RV32IMACFD*)cpu)->PRIV));
etiss_coverage_count(6, 834, 827, 833, 831, 828, 830);
s = (etiss_uint32)(RV32IMACFD_set_field(s, 2LL, 0LL));
etiss_coverage_count(6, 842, 835, 841, 839, 836, 838);
RV32IMACFD_csr_write(cpu, system, plugin_pointers, 256LL, s);
etiss_coverage_count(2, 845, 844);
((RV32IMACFD*)cpu)->PRIV = (1ULL) & 0x7ULL;
etiss_coverage_count(2, 850, 846);
} // block
} // conditional
else { // conditional
{ // block
etiss_coverage_count(1, 928);
vector = ((*((RV32IMACFD*)cpu)->CSR[773LL] & 1ULL) && irq2) ? (bit * 4ULL) : (0LL);
etiss_coverage_count(13, 866, 852, 865, 860, 857, 855, 856, 858, 859, 863, 861, 862, 864);
cpu->nextPc = (*((RV32IMACFD*)cpu)->CSR[773LL] & -2LL) + vector;
etiss_coverage_count(7, 879, 867, 878, 875, 870, 876, 877);
*((RV32IMACFD*)cpu)->CSR[833LL] = epc;
etiss_coverage_count(3, 884, 882, 883);
*((RV32IMACFD*)cpu)->CSR[834LL] = mcause;
etiss_coverage_count(3, 889, 887, 888);
etiss_uint32 s = RV32IMACFD_csr_read(cpu, system, plugin_pointers, 768LL);
etiss_coverage_count(2, 893, 892);
s = (etiss_uint32)(RV32IMACFD_set_field(s, 128LL, RV32IMACFD_get_field(s, 8LL)));
etiss_coverage_count(7, 903, 894, 902, 900, 895, 899, 897);
s = (etiss_uint32)(RV32IMACFD_set_field(s, 6144LL, ((RV32IMACFD*)cpu)->PRIV));
etiss_coverage_count(6, 911, 904, 910, 908, 905, 907);
s = (etiss_uint32)(RV32IMACFD_set_field(s, 8LL, 0LL));
etiss_coverage_count(6, 919, 912, 918, 916, 913, 915);
RV32IMACFD_csr_write(cpu, system, plugin_pointers, 768LL, s);
etiss_coverage_count(2, 922, 921);
((RV32IMACFD*)cpu)->PRIV = (3ULL) & 0x7ULL;
etiss_coverage_count(2, 927, 923);
} // block
} // conditional
} // block
}

void RV32IMACFD_translate_exc_code(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 cause)
{
etiss_coverage_count(1, 163);
{ // block
etiss_coverage_count(1, 986);
etiss_uint32 code = 0LL;
etiss_coverage_count(2, 933, 932);
etiss_coverage_count(1, 934);
if (cause == -2147483648LL) { // conditional
etiss_coverage_count(2, 937, 935);
etiss_coverage_count(1, 956);
return;
} // conditional
 else if (cause == -5LL) { // conditional
etiss_coverage_count(2, 940, 938);
code = 5LL;
etiss_coverage_count(2, 959, 957);
} // conditional
 else if (cause == -14LL) { // conditional
etiss_coverage_count(2, 943, 941);
code = 13LL;
etiss_coverage_count(2, 962, 960);
} // conditional
 else if (cause == -6LL) { // conditional
etiss_coverage_count(2, 946, 944);
code = 7LL;
etiss_coverage_count(2, 965, 963);
} // conditional
 else if (cause == -15LL) { // conditional
etiss_coverage_count(2, 949, 947);
code = 15LL;
etiss_coverage_count(2, 968, 966);
} // conditional
 else if (cause == -7LL) { // conditional
etiss_coverage_count(2, 952, 950);
code = 1LL;
etiss_coverage_count(2, 971, 969);
} // conditional
 else if (cause == -9LL) { // conditional
etiss_coverage_count(2, 955, 953);
{ // block
etiss_coverage_count(1, 979);
code = RV32IMACFD_calc_irq_mcause(cpu, system, plugin_pointers);
etiss_coverage_count(3, 974, 972, 973);
etiss_coverage_count(1, 975);
if (!(code)) { // conditional
etiss_coverage_count(2, 977, 976);
etiss_coverage_count(1, 978);
return;
} // conditional
} // block
} // conditional
else { // conditional
code = 2LL;
etiss_coverage_count(2, 982, 980);
} // conditional
RV32IMACFD_raise(cpu, system, plugin_pointers, 0LL, code);
etiss_coverage_count(3, 985, 983, 984);
} // block
}

etiss_uint32 RV32IMACFD_calc_irq_mcause(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 164);
{ // block
etiss_coverage_count(1, 1171);
etiss_uint32 pending_interrupts = *((RV32IMACFD*)cpu)->CSR[772LL] & *((RV32IMACFD*)cpu)->CSR[836LL];
etiss_coverage_count(4, 995, 994, 990, 993);
etiss_coverage_count(1, 996);
if (!(pending_interrupts)) { // conditional
etiss_coverage_count(2, 998, 997);
etiss_coverage_count(1, 1000);
return 0LL;
etiss_coverage_count(1, 999);
} // conditional
etiss_uint32 mie = (etiss_uint32)(RV32IMACFD_get_field(*((RV32IMACFD*)cpu)->CSR[768LL], 8LL));
etiss_coverage_count(4, 1009, 1008, 1006, 1004);
etiss_uint32 m_enabled = ((RV32IMACFD*)cpu)->PRIV < 3LL || (((RV32IMACFD*)cpu)->PRIV == 3LL && mie);
etiss_coverage_count(9, 1021, 1020, 1013, 1011, 1018, 1016, 1014, 1017, 1019);
etiss_uint32 enabled_interrupts = pending_interrupts & ~(*((RV32IMACFD*)cpu)->CSR[771LL]) & -(m_enabled);
etiss_coverage_count(8, 1032, 1031, 1028, 1023, 1027, 1026, 1030, 1029);
etiss_coverage_count(1, 1033);
if (enabled_interrupts == 0LL) { // conditional
etiss_coverage_count(3, 1036, 1034, 1035);
{ // block
etiss_coverage_count(1, 1070);
etiss_uint32 deleg = *((RV32IMACFD*)cpu)->CSR[771LL];
etiss_coverage_count(2, 1041, 1040);
etiss_uint32 sie = (etiss_uint32)(RV32IMACFD_get_field(RV32IMACFD_csr_read(cpu, system, plugin_pointers, 256LL), 2LL));
etiss_coverage_count(4, 1049, 1048, 1046, 1044);
etiss_uint32 s_enabled = ((RV32IMACFD*)cpu)->PRIV < 1LL || (((RV32IMACFD*)cpu)->PRIV == 1LL && sie);
etiss_coverage_count(9, 1061, 1060, 1053, 1051, 1058, 1056, 1054, 1057, 1059);
enabled_interrupts = pending_interrupts & deleg & -(s_enabled);
etiss_coverage_count(8, 1069, 1062, 1068, 1065, 1063, 1064, 1067, 1066);
} // block
} // conditional
etiss_coverage_count(1, 1071);
if (enabled_interrupts) { // conditional
etiss_coverage_count(1, 1072);
{ // block
etiss_coverage_count(1, 1168);
etiss_coverage_count(1, 1073);
if (enabled_interrupts >> 12ULL) { // conditional
etiss_coverage_count(2, 1079, 1074);
enabled_interrupts = enabled_interrupts >> 12ULL << 12ULL;
etiss_coverage_count(5, 1122, 1110, 1121, 1116, 1111);
} // conditional
 else if (enabled_interrupts & 2048LL) { // conditional
etiss_coverage_count(2, 1082, 1080);
enabled_interrupts = 2048LL;
etiss_coverage_count(2, 1125, 1123);
} // conditional
 else if (enabled_interrupts & 8LL) { // conditional
etiss_coverage_count(2, 1085, 1083);
enabled_interrupts = 8LL;
etiss_coverage_count(2, 1128, 1126);
} // conditional
 else if (enabled_interrupts & 128LL) { // conditional
etiss_coverage_count(2, 1088, 1086);
enabled_interrupts = 128LL;
etiss_coverage_count(2, 1131, 1129);
} // conditional
 else if (enabled_interrupts & 512LL) { // conditional
etiss_coverage_count(2, 1091, 1089);
enabled_interrupts = 512LL;
etiss_coverage_count(2, 1134, 1132);
} // conditional
 else if (enabled_interrupts & 2LL) { // conditional
etiss_coverage_count(2, 1094, 1092);
enabled_interrupts = 2LL;
etiss_coverage_count(2, 1137, 1135);
} // conditional
 else if (enabled_interrupts & 32LL) { // conditional
etiss_coverage_count(2, 1097, 1095);
enabled_interrupts = 32LL;
etiss_coverage_count(2, 1140, 1138);
} // conditional
 else if (enabled_interrupts & 8192LL) { // conditional
etiss_coverage_count(2, 1100, 1098);
enabled_interrupts = 8192LL;
etiss_coverage_count(2, 1143, 1141);
} // conditional
 else if (enabled_interrupts & 1024LL) { // conditional
etiss_coverage_count(2, 1103, 1101);
enabled_interrupts = 1024LL;
etiss_coverage_count(2, 1146, 1144);
} // conditional
 else if (enabled_interrupts & 4LL) { // conditional
etiss_coverage_count(2, 1106, 1104);
enabled_interrupts = 4LL;
etiss_coverage_count(2, 1149, 1147);
} // conditional
 else if (enabled_interrupts & 64LL) { // conditional
etiss_coverage_count(2, 1109, 1107);
enabled_interrupts = 64LL;
etiss_coverage_count(2, 1152, 1150);
} // conditional
else { // conditional
etiss_coverage_count(1, 1154);
return 0LL;
etiss_coverage_count(1, 1153);
} // conditional
etiss_coverage_count(1, 1167);
return 2147483648ULL | RV32IMACFD_ctz(enabled_interrupts);
etiss_coverage_count(3, 1166, 1165, 1164);
} // block
} // conditional
etiss_coverage_count(1, 1170);
return 0LL;
etiss_coverage_count(1, 1169);
} // block
}

void RV32IMACFD_check_irq(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 165);
{ // block
etiss_coverage_count(1, 1180);
etiss_uint32 irq_mcause = RV32IMACFD_calc_irq_mcause(cpu, system, plugin_pointers);
etiss_coverage_count(2, 1174, 1173);
etiss_coverage_count(1, 1175);
if (irq_mcause) { // conditional
etiss_coverage_count(1, 1176);
RV32IMACFD_raise(cpu, system, plugin_pointers, 1ULL, irq_mcause);
etiss_coverage_count(3, 1179, 1177, 1178);
} // conditional
} // block
}
// clang-format on
