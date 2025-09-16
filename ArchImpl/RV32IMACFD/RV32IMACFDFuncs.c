/**
 * Generated on Tue, 16 Sep 2025 12:56:33 +0200.
 *
 * This file contains the function implementations for the RV32IMACFD core architecture.
 */

#include "RV32IMACFDFuncs.h"

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
etiss_coverage_count(1, 703);
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
etiss_coverage_count(1, 700);
res = res + 1ULL;
etiss_coverage_count(3, 696, 694, 695);
val = val >> 1ULL;
etiss_coverage_count(3, 699, 697, 698);
} // block
} // conditional
etiss_coverage_count(1, 702);
return res;
etiss_coverage_count(1, 701);
} // block
}

void RV32IMACFD_raise(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 irq, etiss_uint32 mcause)
{
cpu->return_pending = 1;
cpu->exception = 0;
etiss_coverage_count(1, 162);
{ // block
etiss_coverage_count(1, 916);
etiss_uint32 epc = cpu->instructionPointer;
etiss_coverage_count(2, 706, 705);
etiss_uint32 deleg = 0LL;
etiss_coverage_count(1, 708);
etiss_uint32 vector = 0LL;
etiss_coverage_count(1, 709);
etiss_uint32 bit = mcause;
etiss_coverage_count(2, 711, 710);
etiss_int32 irq2 = (mcause & 2147483648ULL) != 0LL;
etiss_coverage_count(6, 727, 726, 723, 713, 724, 725);
etiss_coverage_count(1, 728);
if (irq2) { // conditional
etiss_coverage_count(1, 729);
{ // block
etiss_coverage_count(1, 754);
deleg = ((((RV32IMACFD*)cpu)->PRIV <= 1LL)) ? (*((RV32IMACFD*)cpu)->CSR[771LL]) : (0LL);
etiss_coverage_count(8, 740, 730, 739, 733, 731, 734, 737, 738);
bit = bit & 2147483647ULL;
etiss_coverage_count(2, 753, 741);
} // block
} // conditional
else { // conditional
{ // block
etiss_coverage_count(1, 766);
deleg = ((((RV32IMACFD*)cpu)->PRIV <= 1LL)) ? (*((RV32IMACFD*)cpu)->CSR[770LL]) : (0LL);
etiss_coverage_count(8, 765, 755, 764, 758, 756, 759, 762, 763);
} // block
} // conditional
etiss_coverage_count(1, 767);
if (((RV32IMACFD*)cpu)->PRIV <= 1LL && (deleg >> bit) & 1ULL) { // conditional
etiss_coverage_count(9, 777, 770, 768, 776, 773, 771, 772, 774, 775);
{ // block
etiss_coverage_count(1, 846);
vector = ((*((RV32IMACFD*)cpu)->CSR[261LL] & 1ULL) && irq2) ? (bit * 4ULL) : (0LL);
etiss_coverage_count(13, 792, 778, 791, 786, 783, 781, 782, 784, 785, 789, 787, 788, 790);
cpu->nextPc = (*((RV32IMACFD*)cpu)->CSR[261LL] & -2LL) + vector;
etiss_coverage_count(7, 805, 793, 804, 801, 796, 802, 803);
*((RV32IMACFD*)cpu)->CSR[321LL] = epc;
etiss_coverage_count(3, 810, 808, 809);
*((RV32IMACFD*)cpu)->CSR[322LL] = mcause;
etiss_coverage_count(3, 815, 813, 814);
etiss_uint32 s = RV32IMACFD_csr_read(cpu, system, plugin_pointers, 256LL);
etiss_coverage_count(2, 819, 818);
s = RV32IMACFD_set_field(s, 32LL, RV32IMACFD_get_field(s, 2LL));
etiss_coverage_count(6, 827, 820, 826, 821, 825, 823);
s = RV32IMACFD_set_field(s, 256LL, ((RV32IMACFD*)cpu)->PRIV);
etiss_coverage_count(5, 833, 828, 832, 829, 831);
s = RV32IMACFD_set_field(s, 2LL, 0LL);
etiss_coverage_count(5, 839, 834, 838, 835, 837);
RV32IMACFD_csr_write(cpu, system, plugin_pointers, 256LL, s);
etiss_coverage_count(2, 842, 841);
((RV32IMACFD*)cpu)->PRIV = (1LL) & 0x7ULL;
etiss_coverage_count(2, 845, 843);
} // block
} // conditional
else { // conditional
{ // block
etiss_coverage_count(1, 915);
vector = ((*((RV32IMACFD*)cpu)->CSR[773LL] & 1ULL) && irq2) ? (bit * 4ULL) : (0LL);
etiss_coverage_count(13, 861, 847, 860, 855, 852, 850, 851, 853, 854, 858, 856, 857, 859);
cpu->nextPc = (*((RV32IMACFD*)cpu)->CSR[773LL] & -2LL) + vector;
etiss_coverage_count(7, 874, 862, 873, 870, 865, 871, 872);
*((RV32IMACFD*)cpu)->CSR[833LL] = epc;
etiss_coverage_count(3, 879, 877, 878);
*((RV32IMACFD*)cpu)->CSR[834LL] = mcause;
etiss_coverage_count(3, 884, 882, 883);
etiss_uint32 s = RV32IMACFD_csr_read(cpu, system, plugin_pointers, 768LL);
etiss_coverage_count(2, 888, 887);
s = RV32IMACFD_set_field(s, 128LL, RV32IMACFD_get_field(s, 8LL));
etiss_coverage_count(6, 896, 889, 895, 890, 894, 892);
s = RV32IMACFD_set_field(s, 6144LL, ((RV32IMACFD*)cpu)->PRIV);
etiss_coverage_count(5, 902, 897, 901, 898, 900);
s = RV32IMACFD_set_field(s, 8LL, 0LL);
etiss_coverage_count(5, 908, 903, 907, 904, 906);
RV32IMACFD_csr_write(cpu, system, plugin_pointers, 768LL, s);
etiss_coverage_count(2, 911, 910);
((RV32IMACFD*)cpu)->PRIV = (3LL) & 0x7ULL;
etiss_coverage_count(2, 914, 912);
} // block
} // conditional
} // block
}

void RV32IMACFD_translate_exc_code(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 cause)
{
etiss_coverage_count(1, 163);
{ // block
etiss_coverage_count(1, 973);
etiss_uint32 code = 0LL;
etiss_coverage_count(2, 920, 919);
etiss_coverage_count(1, 921);
if (cause == -2147483648LL) { // conditional
etiss_coverage_count(2, 924, 922);
etiss_coverage_count(1, 943);
return;
} // conditional
 else if (cause == -5LL) { // conditional
etiss_coverage_count(2, 927, 925);
code = 5LL;
etiss_coverage_count(2, 946, 944);
} // conditional
 else if (cause == -14LL) { // conditional
etiss_coverage_count(2, 930, 928);
code = 13LL;
etiss_coverage_count(2, 949, 947);
} // conditional
 else if (cause == -6LL) { // conditional
etiss_coverage_count(2, 933, 931);
code = 7LL;
etiss_coverage_count(2, 952, 950);
} // conditional
 else if (cause == -15LL) { // conditional
etiss_coverage_count(2, 936, 934);
code = 15LL;
etiss_coverage_count(2, 955, 953);
} // conditional
 else if (cause == -7LL) { // conditional
etiss_coverage_count(2, 939, 937);
code = 1LL;
etiss_coverage_count(2, 958, 956);
} // conditional
 else if (cause == -9LL) { // conditional
etiss_coverage_count(2, 942, 940);
{ // block
etiss_coverage_count(1, 966);
code = RV32IMACFD_calc_irq_mcause(cpu, system, plugin_pointers);
etiss_coverage_count(3, 961, 959, 960);
etiss_coverage_count(1, 962);
if (!(code)) { // conditional
etiss_coverage_count(2, 964, 963);
etiss_coverage_count(1, 965);
return;
} // conditional
} // block
} // conditional
else { // conditional
code = 2LL;
etiss_coverage_count(2, 969, 967);
} // conditional
RV32IMACFD_raise(cpu, system, plugin_pointers, 0LL, code);
etiss_coverage_count(3, 972, 970, 971);
} // block
}

etiss_uint32 RV32IMACFD_calc_irq_mcause(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 164);
{ // block
etiss_coverage_count(1, 1154);
etiss_uint32 pending_interrupts = *((RV32IMACFD*)cpu)->CSR[772LL] & *((RV32IMACFD*)cpu)->CSR[836LL];
etiss_coverage_count(4, 982, 981, 977, 980);
etiss_coverage_count(1, 983);
if (!(pending_interrupts)) { // conditional
etiss_coverage_count(2, 985, 984);
etiss_coverage_count(1, 987);
return 0LL;
etiss_coverage_count(1, 986);
} // conditional
etiss_uint32 mie = RV32IMACFD_get_field(*((RV32IMACFD*)cpu)->CSR[768LL], 8LL);
etiss_coverage_count(3, 994, 993, 991);
etiss_uint32 m_enabled = ((RV32IMACFD*)cpu)->PRIV < 3LL || (((RV32IMACFD*)cpu)->PRIV == 3LL && mie);
etiss_coverage_count(9, 1006, 1005, 998, 996, 1003, 1001, 999, 1002, 1004);
etiss_uint32 enabled_interrupts = pending_interrupts & ~(*((RV32IMACFD*)cpu)->CSR[771LL]) & -(m_enabled);
etiss_coverage_count(8, 1017, 1016, 1013, 1008, 1012, 1011, 1015, 1014);
etiss_coverage_count(1, 1018);
if (enabled_interrupts == 0LL) { // conditional
etiss_coverage_count(3, 1021, 1019, 1020);
{ // block
etiss_coverage_count(1, 1053);
etiss_uint32 deleg = *((RV32IMACFD*)cpu)->CSR[771LL];
etiss_coverage_count(2, 1026, 1025);
etiss_uint32 sie = RV32IMACFD_get_field(RV32IMACFD_csr_read(cpu, system, plugin_pointers, 256LL), 2LL);
etiss_coverage_count(3, 1032, 1031, 1029);
etiss_uint32 s_enabled = ((RV32IMACFD*)cpu)->PRIV < 1LL || (((RV32IMACFD*)cpu)->PRIV == 1LL && sie);
etiss_coverage_count(9, 1044, 1043, 1036, 1034, 1041, 1039, 1037, 1040, 1042);
enabled_interrupts = pending_interrupts & deleg & -(s_enabled);
etiss_coverage_count(8, 1052, 1045, 1051, 1048, 1046, 1047, 1050, 1049);
} // block
} // conditional
etiss_coverage_count(1, 1054);
if (enabled_interrupts) { // conditional
etiss_coverage_count(1, 1055);
{ // block
etiss_coverage_count(1, 1151);
etiss_coverage_count(1, 1056);
if (enabled_interrupts >> 12ULL) { // conditional
etiss_coverage_count(2, 1062, 1057);
enabled_interrupts = enabled_interrupts >> 12ULL << 12ULL;
etiss_coverage_count(5, 1105, 1093, 1104, 1099, 1094);
} // conditional
 else if (enabled_interrupts & 2048LL) { // conditional
etiss_coverage_count(2, 1065, 1063);
enabled_interrupts = 2048LL;
etiss_coverage_count(2, 1108, 1106);
} // conditional
 else if (enabled_interrupts & 8LL) { // conditional
etiss_coverage_count(2, 1068, 1066);
enabled_interrupts = 8LL;
etiss_coverage_count(2, 1111, 1109);
} // conditional
 else if (enabled_interrupts & 128LL) { // conditional
etiss_coverage_count(2, 1071, 1069);
enabled_interrupts = 128LL;
etiss_coverage_count(2, 1114, 1112);
} // conditional
 else if (enabled_interrupts & 512LL) { // conditional
etiss_coverage_count(2, 1074, 1072);
enabled_interrupts = 512LL;
etiss_coverage_count(2, 1117, 1115);
} // conditional
 else if (enabled_interrupts & 2LL) { // conditional
etiss_coverage_count(2, 1077, 1075);
enabled_interrupts = 2LL;
etiss_coverage_count(2, 1120, 1118);
} // conditional
 else if (enabled_interrupts & 32LL) { // conditional
etiss_coverage_count(2, 1080, 1078);
enabled_interrupts = 32LL;
etiss_coverage_count(2, 1123, 1121);
} // conditional
 else if (enabled_interrupts & 8192LL) { // conditional
etiss_coverage_count(2, 1083, 1081);
enabled_interrupts = 8192LL;
etiss_coverage_count(2, 1126, 1124);
} // conditional
 else if (enabled_interrupts & 1024LL) { // conditional
etiss_coverage_count(2, 1086, 1084);
enabled_interrupts = 1024LL;
etiss_coverage_count(2, 1129, 1127);
} // conditional
 else if (enabled_interrupts & 4LL) { // conditional
etiss_coverage_count(2, 1089, 1087);
enabled_interrupts = 4LL;
etiss_coverage_count(2, 1132, 1130);
} // conditional
 else if (enabled_interrupts & 64LL) { // conditional
etiss_coverage_count(2, 1092, 1090);
enabled_interrupts = 64LL;
etiss_coverage_count(2, 1135, 1133);
} // conditional
else { // conditional
etiss_coverage_count(1, 1137);
return 0LL;
etiss_coverage_count(1, 1136);
} // conditional
etiss_coverage_count(1, 1150);
return 2147483648ULL | RV32IMACFD_ctz(enabled_interrupts);
etiss_coverage_count(3, 1149, 1148, 1147);
} // block
} // conditional
etiss_coverage_count(1, 1153);
return 0LL;
etiss_coverage_count(1, 1152);
} // block
}

void RV32IMACFD_check_irq(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 165);
{ // block
etiss_coverage_count(1, 1163);
etiss_uint32 irq_mcause = RV32IMACFD_calc_irq_mcause(cpu, system, plugin_pointers);
etiss_coverage_count(2, 1157, 1156);
etiss_coverage_count(1, 1158);
if (irq_mcause) { // conditional
etiss_coverage_count(1, 1159);
RV32IMACFD_raise(cpu, system, plugin_pointers, 1ULL, irq_mcause);
etiss_coverage_count(3, 1162, 1160, 1161);
} // conditional
} // block
}
