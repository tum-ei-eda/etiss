/**
 * Generated on Thu, 04 Apr 2024 12:50:47 +0200.
 *
 * This file contains the function implementations for the RV64IMACFD core architecture.
 */

#include "RV64IMACFDFuncs.h"

etiss_uint8 RV64IMACFD_extension_enabled(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int8 extension)
{
etiss_coverage_count(1, 80);
{ // block
etiss_coverage_count(1, 257);
etiss_coverage_count(1, 256);
return (*((RV64IMACFD*)cpu)->CSR[769LL] >> (extension - 65ULL)) & 1ULL;
etiss_coverage_count(9, 255, 252, 247, 250, 248, 249, 251, 253, 254);
} // block
}

etiss_uint8 RV64IMACFD_get_rm(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint8 rm)
{
etiss_coverage_count(1, 87);
{ // block
etiss_coverage_count(1, 277);
etiss_coverage_count(1, 260);
if (rm == 7ULL) { // conditional
etiss_coverage_count(3, 258, 259, 267);
rm = ((((((RV64IMACFD*)cpu)->FCSR) >> (5ULL)) & 7)) & 0x7;
etiss_coverage_count(6, 266, 261, 265, 262, 263, 264);
} // conditional
etiss_coverage_count(1, 270);
if (rm > 4ULL) { // conditional
etiss_coverage_count(3, 268, 269, 274);
RV64IMACFD_raise(cpu, system, plugin_pointers, 0LL, 2LL);
etiss_coverage_count(2, 273, 271);
} // conditional
etiss_coverage_count(1, 276);
return rm;
etiss_coverage_count(1, 275);
} // block
}

etiss_uint64 RV64IMACFD_sstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 149);
{ // block
etiss_coverage_count(1, 350);
etiss_uint64 mask = 0LL;
etiss_coverage_count(2, 280, 279);
etiss_coverage_count(1, 282);
if (RV64IMACFD_extension_enabled(cpu, system, plugin_pointers, 83ULL)) { // conditional
etiss_coverage_count(2, 281, 347);
{ // block
etiss_coverage_count(1, 346);
mask = mask | 5767458ULL;
etiss_coverage_count(2, 298, 283);
etiss_coverage_count(1, 300);
if (RV64IMACFD_extension_enabled(cpu, system, plugin_pointers, 86ULL)) { // conditional
etiss_coverage_count(2, 299, 304);
mask = mask | 1536LL;
etiss_coverage_count(2, 303, 301);
} // conditional
etiss_coverage_count(1, 306);
if (RV64IMACFD_extension_enabled(cpu, system, plugin_pointers, 70ULL)) { // conditional
etiss_coverage_count(2, 305, 310);
mask = mask | 24576LL;
etiss_coverage_count(2, 309, 307);
} // conditional
etiss_coverage_count(1, 312);
if (RV64IMACFD_extension_enabled(cpu, system, plugin_pointers, 88ULL)) { // conditional
etiss_coverage_count(2, 311, 316);
mask = mask | 98304LL;
etiss_coverage_count(2, 315, 313);
} // conditional
if ((RV64IMACFD_get_field(*((RV64IMACFD*)cpu)->CSR[384LL], 17293822569102704640ULL))) { // conditional
etiss_coverage_count(4, 338, 334, 340, 345);
mask = mask | 262144LL;
etiss_coverage_count(2, 344, 342);
} // conditional
} // block
} // conditional
etiss_coverage_count(1, 349);
return mask;
etiss_coverage_count(1, 348);
} // block
}

etiss_uint64 RV64IMACFD_mstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 150);
{ // block
etiss_coverage_count(1, 365);
etiss_uint64 mask = 6280ULL;
etiss_coverage_count(1, 360);
etiss_coverage_count(1, 364);
return mask | RV64IMACFD_sstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(3, 363, 361, 362);
} // block
}

etiss_uint64 RV64IMACFD_csr_read(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr)
{
etiss_coverage_count(1, 151);
{ // block
etiss_coverage_count(1, 483);
etiss_coverage_count(1, 368);
if (csr == 1LL) { // conditional
etiss_coverage_count(2, 366, 375);
etiss_coverage_count(1, 374);
return *((RV64IMACFD*)cpu)->CSR[3LL] & 31ULL;
etiss_coverage_count(3, 373, 371, 372);
} // conditional
etiss_coverage_count(1, 378);
if (csr == 2LL) { // conditional
etiss_coverage_count(2, 376, 388);
etiss_coverage_count(1, 387);
return (*((RV64IMACFD*)cpu)->CSR[3LL] >> 5ULL) & 7ULL;
etiss_coverage_count(6, 386, 383, 381, 382, 384, 385);
} // conditional
etiss_coverage_count(1, 391);
if (csr == 3072LL) { // conditional
etiss_coverage_count(2, 389, 394);
etiss_coverage_count(1, 393);
return etiss_get_cycles(cpu, system, plugin_pointers);
etiss_coverage_count(1, 392);
} // conditional
etiss_coverage_count(1, 397);
if (csr == 3200LL) { // conditional
etiss_coverage_count(2, 395, 402);
etiss_coverage_count(1, 401);
return etiss_get_cycles(cpu, system, plugin_pointers) >> 32ULL;
etiss_coverage_count(3, 400, 398, 399);
} // conditional
etiss_coverage_count(1, 405);
if (csr == 3073LL) { // conditional
etiss_coverage_count(2, 403, 408);
etiss_coverage_count(1, 407);
return etiss_get_time();
etiss_coverage_count(1, 406);
} // conditional
etiss_coverage_count(1, 411);
if (csr == 3201LL) { // conditional
etiss_coverage_count(2, 409, 416);
etiss_coverage_count(1, 415);
return etiss_get_time() >> 32ULL;
etiss_coverage_count(3, 414, 412, 413);
} // conditional
etiss_coverage_count(1, 419);
if (csr == 3074LL) { // conditional
etiss_coverage_count(2, 417, 422);
etiss_coverage_count(1, 421);
return etiss_get_instret(cpu, system, plugin_pointers);
etiss_coverage_count(1, 420);
} // conditional
etiss_coverage_count(1, 425);
if (csr == 3202LL) { // conditional
etiss_coverage_count(2, 423, 430);
etiss_coverage_count(1, 429);
return etiss_get_instret(cpu, system, plugin_pointers) >> 32ULL;
etiss_coverage_count(3, 428, 426, 427);
} // conditional
etiss_coverage_count(1, 437);
if (csr == 768LL || csr == 256LL) { // conditional
etiss_coverage_count(5, 433, 431, 436, 434, 458);
etiss_coverage_count(1, 457);
return *((RV64IMACFD*)cpu)->CSR[768LL] | 8589934592ULL | 34359738368ULL;
etiss_coverage_count(3, 456, 448, 440);
} // conditional
etiss_coverage_count(1, 461);
if (csr == 769LL) { // conditional
etiss_coverage_count(2, 459, 478);
etiss_coverage_count(1, 477);
return (((2ULL) << 62) | ((((*((RV64IMACFD*)cpu)->CSR[769LL]) >> (0LL)) & 4611686018427387903)));
etiss_coverage_count(4, 476, 475, 470, 474);
} // conditional
etiss_coverage_count(1, 482);
return *((RV64IMACFD*)cpu)->CSR[csr];
etiss_coverage_count(2, 481, 480);
} // block
}

void RV64IMACFD_csr_write(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr, etiss_uint64 val)
{
etiss_coverage_count(1, 152);
{ // block
etiss_coverage_count(1, 565);
etiss_coverage_count(1, 486);
if (csr == 1LL) { // conditional
etiss_coverage_count(2, 484, 564);
*((RV64IMACFD*)cpu)->CSR[3LL] = (*((RV64IMACFD*)cpu)->CSR[3LL] & 224ULL) | (val & 31ULL);
etiss_coverage_count(10, 519, 504, 518, 512, 507, 513, 516, 514, 515, 517);
} // conditional
 else if (csr == 2LL) { // conditional
etiss_coverage_count(2, 489, 487);
*((RV64IMACFD*)cpu)->CSR[3LL] = ((val & 7ULL) << 5ULL) | (*((RV64IMACFD*)cpu)->CSR[3LL] & 31ULL);
etiss_coverage_count(14, 537, 522, 536, 528, 525, 523, 524, 526, 527, 529, 534, 532, 533, 535);
} // conditional
 else if (csr == 3LL) { // conditional
etiss_coverage_count(2, 492, 490);
*((RV64IMACFD*)cpu)->CSR[3LL] = val & 255ULL;
etiss_coverage_count(5, 544, 540, 543, 541, 542);
} // conditional
 else if (csr == 768LL) { // conditional
etiss_coverage_count(2, 495, 493);
*((RV64IMACFD*)cpu)->CSR[768LL] = val & RV64IMACFD_mstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(5, 551, 547, 550, 548, 549);
} // conditional
 else if (csr == 256LL) { // conditional
etiss_coverage_count(2, 498, 496);
*((RV64IMACFD*)cpu)->CSR[768LL] = val & RV64IMACFD_sstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(5, 558, 554, 557, 555, 556);
} // conditional
 else if (csr != 769LL) { // conditional
etiss_coverage_count(2, 501, 499);
*((RV64IMACFD*)cpu)->CSR[csr] = val;
etiss_coverage_count(4, 563, 561, 560, 562);
} // conditional
} // block
}

etiss_uint64 RV64IMACFD_get_field(etiss_uint64 reg, etiss_uint64 mask)
{
etiss_coverage_count(1, 159);
{ // block
etiss_coverage_count(1, 585);
etiss_coverage_count(1, 567);
if (!(mask)) { // conditional
etiss_coverage_count(2, 566, 570);
etiss_coverage_count(1, 569);
return 0LL;
etiss_coverage_count(1, 568);
} // conditional
etiss_coverage_count(1, 584);
return (reg & mask) / (mask & ~((mask << 1ULL)));
etiss_coverage_count(13, 583, 573, 571, 572, 574, 581, 575, 580, 578, 576, 577, 579, 582);
} // block
}

etiss_uint64 RV64IMACFD_set_field(etiss_uint64 reg, etiss_uint64 mask, etiss_uint64 val)
{
etiss_coverage_count(1, 160);
{ // block
etiss_coverage_count(1, 608);
etiss_coverage_count(1, 607);
return ((reg & ~(mask)) | ((val * (mask & ~((mask << 1ULL)))) & mask));
etiss_coverage_count(21, 605, 589, 586, 588, 587, 590, 603, 600, 591, 598, 592, 597, 595, 593, 594, 596, 599, 601, 602, 604, 606);
} // block
}

etiss_uint8 RV64IMACFD_ctz(etiss_uint64 val)
{
etiss_coverage_count(1, 161);
{ // block
etiss_coverage_count(1, 703);
etiss_coverage_count(1, 610);
if (!(val)) { // conditional
etiss_coverage_count(2, 609, 613);
etiss_coverage_count(1, 612);
return 0LL;
etiss_coverage_count(1, 611);
} // conditional
etiss_uint8 res = 0LL;
etiss_coverage_count(2, 616, 615);
etiss_coverage_count(1, 622);
if ((val << 32ULL) == 0LL) { // conditional
etiss_coverage_count(6, 619, 617, 618, 620, 621, 630);
{ // block
etiss_coverage_count(1, 629);
res = res + 32ULL;
etiss_coverage_count(3, 625, 623, 624);
val = val >> 32ULL;
etiss_coverage_count(3, 628, 626, 627);
} // block
} // conditional
etiss_coverage_count(1, 636);
if ((val << 48ULL) == 0LL) { // conditional
etiss_coverage_count(6, 633, 631, 632, 634, 635, 644);
{ // block
etiss_coverage_count(1, 643);
res = res + 16ULL;
etiss_coverage_count(3, 639, 637, 638);
val = val >> 16ULL;
etiss_coverage_count(3, 642, 640, 641);
} // block
} // conditional
etiss_coverage_count(1, 650);
if ((val << 56ULL) == 0LL) { // conditional
etiss_coverage_count(6, 647, 645, 646, 648, 649, 658);
{ // block
etiss_coverage_count(1, 657);
res = res + 8ULL;
etiss_coverage_count(3, 653, 651, 652);
val = val >> 8ULL;
etiss_coverage_count(3, 656, 654, 655);
} // block
} // conditional
etiss_coverage_count(1, 664);
if ((val << 60ULL) == 0LL) { // conditional
etiss_coverage_count(6, 661, 659, 660, 662, 663, 672);
{ // block
etiss_coverage_count(1, 671);
res = res + 4ULL;
etiss_coverage_count(3, 667, 665, 666);
val = val >> 4ULL;
etiss_coverage_count(3, 670, 668, 669);
} // block
} // conditional
etiss_coverage_count(1, 678);
if ((val << 62ULL) == 0LL) { // conditional
etiss_coverage_count(6, 675, 673, 674, 676, 677, 686);
{ // block
etiss_coverage_count(1, 685);
res = res + 2ULL;
etiss_coverage_count(3, 681, 679, 680);
val = val >> 2ULL;
etiss_coverage_count(3, 684, 682, 683);
} // block
} // conditional
etiss_coverage_count(1, 692);
if ((val << 63ULL) == 0LL) { // conditional
etiss_coverage_count(6, 689, 687, 688, 690, 691, 700);
{ // block
etiss_coverage_count(1, 699);
res = res + 1ULL;
etiss_coverage_count(3, 695, 693, 694);
val = val >> 1ULL;
etiss_coverage_count(3, 698, 696, 697);
} // block
} // conditional
etiss_coverage_count(1, 702);
return res;
etiss_coverage_count(1, 701);
} // block
}

void RV64IMACFD_raise(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 irq, etiss_uint64 mcause)
{
cpu->return_pending = 1;
cpu->exception = 0;
etiss_coverage_count(1, 162);
{ // block
etiss_coverage_count(1, 916);
etiss_uint64 epc = cpu->instructionPointer;
etiss_coverage_count(2, 706, 705);
etiss_uint64 deleg = 0LL;
etiss_coverage_count(1, 708);
etiss_uint64 vector = 0LL;
etiss_coverage_count(1, 709);
etiss_uint64 bit = mcause;
etiss_coverage_count(2, 711, 710);
etiss_int32 irq2 = (mcause & 9223372036854775808ULL) != 0LL;
etiss_coverage_count(6, 727, 726, 723, 713, 724, 725);
etiss_coverage_count(1, 728);
if (irq2) { // conditional
etiss_coverage_count(1, 766);
{ // block
etiss_coverage_count(1, 753);
deleg = ((((RV64IMACFD*)cpu)->PRIV <= 1LL)) ? (*((RV64IMACFD*)cpu)->CSR[771LL]) : (0LL);
etiss_coverage_count(8, 739, 729, 738, 732, 730, 733, 736, 737);
bit = bit & 9223372036854775807ULL;
etiss_coverage_count(2, 752, 740);
} // block
} // conditional
else { // conditional
{ // block
etiss_coverage_count(1, 765);
deleg = ((((RV64IMACFD*)cpu)->PRIV <= 1LL)) ? (*((RV64IMACFD*)cpu)->CSR[770LL]) : (0LL);
etiss_coverage_count(8, 764, 754, 763, 757, 755, 758, 761, 762);
} // block
} // conditional
etiss_coverage_count(1, 776);
if (((RV64IMACFD*)cpu)->PRIV <= 1LL && (deleg >> bit) & 1ULL) { // conditional
etiss_coverage_count(9, 769, 767, 775, 772, 770, 771, 773, 774, 915);
{ // block
etiss_coverage_count(1, 845);
vector = ((*((RV64IMACFD*)cpu)->CSR[261LL] & 1ULL) && irq2) ? (bit * 4ULL) : (0LL);
etiss_coverage_count(13, 791, 777, 790, 785, 782, 780, 781, 783, 784, 788, 786, 787, 789);
cpu->nextPc = (*((RV64IMACFD*)cpu)->CSR[261LL] & -2LL) + vector;
etiss_coverage_count(7, 804, 792, 803, 800, 795, 801, 802);
*((RV64IMACFD*)cpu)->CSR[321LL] = epc;
etiss_coverage_count(3, 809, 807, 808);
*((RV64IMACFD*)cpu)->CSR[322LL] = mcause;
etiss_coverage_count(3, 814, 812, 813);
etiss_uint64 s = RV64IMACFD_csr_read(cpu, system, plugin_pointers, 256LL);
etiss_coverage_count(2, 818, 817);
s = RV64IMACFD_set_field(s, 32LL, RV64IMACFD_get_field(s, 2LL));
etiss_coverage_count(6, 826, 819, 825, 820, 824, 822);
s = RV64IMACFD_set_field(s, 256LL, ((RV64IMACFD*)cpu)->PRIV);
etiss_coverage_count(5, 832, 827, 831, 828, 830);
s = RV64IMACFD_set_field(s, 2LL, 0LL);
etiss_coverage_count(5, 838, 833, 837, 834, 836);
RV64IMACFD_csr_write(cpu, system, plugin_pointers, 256LL, s);
etiss_coverage_count(2, 841, 840);
((RV64IMACFD*)cpu)->PRIV = (1LL) & 0x7;
etiss_coverage_count(2, 844, 842);
} // block
} // conditional
else { // conditional
{ // block
etiss_coverage_count(1, 914);
vector = ((*((RV64IMACFD*)cpu)->CSR[773LL] & 1ULL) && irq2) ? (bit * 4ULL) : (0LL);
etiss_coverage_count(13, 860, 846, 859, 854, 851, 849, 850, 852, 853, 857, 855, 856, 858);
cpu->nextPc = (*((RV64IMACFD*)cpu)->CSR[773LL] & -2LL) + vector;
etiss_coverage_count(7, 873, 861, 872, 869, 864, 870, 871);
*((RV64IMACFD*)cpu)->CSR[833LL] = epc;
etiss_coverage_count(3, 878, 876, 877);
*((RV64IMACFD*)cpu)->CSR[834LL] = mcause;
etiss_coverage_count(3, 883, 881, 882);
etiss_uint64 s = RV64IMACFD_csr_read(cpu, system, plugin_pointers, 768LL);
etiss_coverage_count(2, 887, 886);
s = RV64IMACFD_set_field(s, 128LL, RV64IMACFD_get_field(s, 8LL));
etiss_coverage_count(6, 895, 888, 894, 889, 893, 891);
s = RV64IMACFD_set_field(s, 6144LL, ((RV64IMACFD*)cpu)->PRIV);
etiss_coverage_count(5, 901, 896, 900, 897, 899);
s = RV64IMACFD_set_field(s, 8LL, 0LL);
etiss_coverage_count(5, 907, 902, 906, 903, 905);
RV64IMACFD_csr_write(cpu, system, plugin_pointers, 768LL, s);
etiss_coverage_count(2, 910, 909);
((RV64IMACFD*)cpu)->PRIV = (3LL) & 0x7;
etiss_coverage_count(2, 913, 911);
} // block
} // conditional
} // block
}

void RV64IMACFD_translate_exc_code(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 cause)
{
etiss_coverage_count(1, 163);
{ // block
etiss_coverage_count(1, 973);
etiss_uint64 code = 0LL;
etiss_coverage_count(2, 920, 919);
etiss_coverage_count(1, 923);
if (cause == -2147483648LL) { // conditional
etiss_coverage_count(2, 921, 969);
etiss_coverage_count(1, 942);
return;
} // conditional
 else if (cause == -5LL) { // conditional
etiss_coverage_count(2, 926, 924);
code = 5LL;
etiss_coverage_count(2, 945, 943);
} // conditional
 else if (cause == -14LL) { // conditional
etiss_coverage_count(2, 929, 927);
code = 13LL;
etiss_coverage_count(2, 948, 946);
} // conditional
 else if (cause == -6LL) { // conditional
etiss_coverage_count(2, 932, 930);
code = 7LL;
etiss_coverage_count(2, 951, 949);
} // conditional
 else if (cause == -15LL) { // conditional
etiss_coverage_count(2, 935, 933);
code = 15LL;
etiss_coverage_count(2, 954, 952);
} // conditional
 else if (cause == -7LL) { // conditional
etiss_coverage_count(2, 938, 936);
code = 1LL;
etiss_coverage_count(2, 957, 955);
} // conditional
 else if (cause == -9LL) { // conditional
etiss_coverage_count(2, 941, 939);
{ // block
etiss_coverage_count(1, 965);
code = RV64IMACFD_calc_irq_mcause(cpu, system, plugin_pointers);
etiss_coverage_count(3, 960, 958, 959);
etiss_coverage_count(1, 962);
if (!(code)) { // conditional
etiss_coverage_count(2, 961, 964);
etiss_coverage_count(1, 963);
return;
} // conditional
} // block
} // conditional
else { // conditional
code = 2LL;
etiss_coverage_count(2, 968, 966);
} // conditional
RV64IMACFD_raise(cpu, system, plugin_pointers, 0LL, code);
etiss_coverage_count(3, 972, 970, 971);
} // block
}

etiss_uint64 RV64IMACFD_calc_irq_mcause(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 164);
{ // block
etiss_coverage_count(1, 1154);
etiss_uint64 pending_interrupts = *((RV64IMACFD*)cpu)->CSR[772LL] & *((RV64IMACFD*)cpu)->CSR[836LL];
etiss_coverage_count(4, 982, 981, 977, 980);
etiss_coverage_count(1, 984);
if (!(pending_interrupts)) { // conditional
etiss_coverage_count(2, 983, 987);
etiss_coverage_count(1, 986);
return 0LL;
etiss_coverage_count(1, 985);
} // conditional
etiss_uint64 mie = RV64IMACFD_get_field(*((RV64IMACFD*)cpu)->CSR[768LL], 8LL);
etiss_coverage_count(3, 994, 993, 991);
etiss_uint64 m_enabled = ((RV64IMACFD*)cpu)->PRIV < 3LL || (((RV64IMACFD*)cpu)->PRIV == 3LL && mie);
etiss_coverage_count(9, 1006, 1005, 998, 996, 1003, 1001, 999, 1002, 1004);
etiss_uint64 enabled_interrupts = pending_interrupts & ~(*((RV64IMACFD*)cpu)->CSR[771LL]) & -(m_enabled);
etiss_coverage_count(8, 1017, 1016, 1013, 1008, 1012, 1011, 1015, 1014);
etiss_coverage_count(1, 1020);
if (enabled_interrupts == 0LL) { // conditional
etiss_coverage_count(3, 1018, 1019, 1053);
{ // block
etiss_coverage_count(1, 1052);
etiss_uint64 deleg = *((RV64IMACFD*)cpu)->CSR[771LL];
etiss_coverage_count(2, 1025, 1024);
etiss_uint64 sie = RV64IMACFD_get_field(RV64IMACFD_csr_read(cpu, system, plugin_pointers, 256LL), 2LL);
etiss_coverage_count(3, 1031, 1030, 1028);
etiss_uint64 s_enabled = ((RV64IMACFD*)cpu)->PRIV < 1LL || (((RV64IMACFD*)cpu)->PRIV == 1LL && sie);
etiss_coverage_count(9, 1043, 1042, 1035, 1033, 1040, 1038, 1036, 1039, 1041);
enabled_interrupts = pending_interrupts & deleg & -(s_enabled);
etiss_coverage_count(8, 1051, 1044, 1050, 1047, 1045, 1046, 1049, 1048);
} // block
} // conditional
etiss_coverage_count(1, 1054);
if (enabled_interrupts) { // conditional
etiss_coverage_count(1, 1151);
{ // block
etiss_coverage_count(1, 1150);
etiss_coverage_count(1, 1060);
if (enabled_interrupts >> 12ULL) { // conditional
etiss_coverage_count(2, 1055, 1136);
enabled_interrupts = enabled_interrupts >> 12ULL << 12ULL;
etiss_coverage_count(5, 1103, 1091, 1102, 1097, 1092);
} // conditional
 else if (enabled_interrupts & 2048LL) { // conditional
etiss_coverage_count(2, 1063, 1061);
enabled_interrupts = 2048LL;
etiss_coverage_count(2, 1106, 1104);
} // conditional
 else if (enabled_interrupts & 8LL) { // conditional
etiss_coverage_count(2, 1066, 1064);
enabled_interrupts = 8LL;
etiss_coverage_count(2, 1109, 1107);
} // conditional
 else if (enabled_interrupts & 128LL) { // conditional
etiss_coverage_count(2, 1069, 1067);
enabled_interrupts = 128LL;
etiss_coverage_count(2, 1112, 1110);
} // conditional
 else if (enabled_interrupts & 512LL) { // conditional
etiss_coverage_count(2, 1072, 1070);
enabled_interrupts = 512LL;
etiss_coverage_count(2, 1115, 1113);
} // conditional
 else if (enabled_interrupts & 2LL) { // conditional
etiss_coverage_count(2, 1075, 1073);
enabled_interrupts = 2LL;
etiss_coverage_count(2, 1118, 1116);
} // conditional
 else if (enabled_interrupts & 32LL) { // conditional
etiss_coverage_count(2, 1078, 1076);
enabled_interrupts = 32LL;
etiss_coverage_count(2, 1121, 1119);
} // conditional
 else if (enabled_interrupts & 8192LL) { // conditional
etiss_coverage_count(2, 1081, 1079);
enabled_interrupts = 8192LL;
etiss_coverage_count(2, 1124, 1122);
} // conditional
 else if (enabled_interrupts & 1024LL) { // conditional
etiss_coverage_count(2, 1084, 1082);
enabled_interrupts = 1024LL;
etiss_coverage_count(2, 1127, 1125);
} // conditional
 else if (enabled_interrupts & 4LL) { // conditional
etiss_coverage_count(2, 1087, 1085);
enabled_interrupts = 4LL;
etiss_coverage_count(2, 1130, 1128);
} // conditional
 else if (enabled_interrupts & 64LL) { // conditional
etiss_coverage_count(2, 1090, 1088);
enabled_interrupts = 64LL;
etiss_coverage_count(2, 1133, 1131);
} // conditional
else { // conditional
etiss_coverage_count(1, 1135);
return 0LL;
etiss_coverage_count(1, 1134);
} // conditional
etiss_coverage_count(1, 1149);
return 9223372036854775808ULL | RV64IMACFD_ctz(enabled_interrupts);
etiss_coverage_count(3, 1148, 1147, 1146);
} // block
} // conditional
etiss_coverage_count(1, 1153);
return 0LL;
etiss_coverage_count(1, 1152);
} // block
}

void RV64IMACFD_check_irq(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 165);
{ // block
etiss_coverage_count(1, 1163);
etiss_uint64 irq_mcause = RV64IMACFD_calc_irq_mcause(cpu, system, plugin_pointers);
etiss_coverage_count(2, 1157, 1156);
etiss_coverage_count(1, 1158);
if (irq_mcause) { // conditional
etiss_coverage_count(1, 1162);
RV64IMACFD_raise(cpu, system, plugin_pointers, 1ULL, irq_mcause);
etiss_coverage_count(3, 1161, 1159, 1160);
} // conditional
} // block
}

etiss_int64 RV64IMACFD_mulh(etiss_int64 x, etiss_int64 y)
{
etiss_coverage_count(1, 237);
{ // block
etiss_coverage_count(1, 6907);
etiss_int128 res = (etiss_int128)(x) * (etiss_int128)(y);
etiss_coverage_count(6, 6899, 6898, 6894, 6892, 6897, 6895);
etiss_coverage_count(1, 6906);
return (etiss_int64)((res >> 64ULL));
etiss_coverage_count(4, 6905, 6902, 6900, 6903);
} // block
}

etiss_int64 RV64IMACFD_mulhsu(etiss_int64 x, etiss_uint64 y)
{
etiss_coverage_count(1, 238);
{ // block
etiss_coverage_count(1, 6924);
etiss_int128 res = (etiss_int128)(x) * (etiss_uint128)(y);
etiss_coverage_count(6, 6916, 6915, 6911, 6909, 6914, 6912);
etiss_coverage_count(1, 6923);
return (etiss_int64)((res >> 64ULL));
etiss_coverage_count(4, 6922, 6919, 6917, 6920);
} // block
}

etiss_uint64 RV64IMACFD_mulhu(etiss_uint64 x, etiss_uint64 y)
{
etiss_coverage_count(1, 239);
{ // block
etiss_coverage_count(1, 6941);
etiss_uint128 res = (etiss_uint128)(x) * (etiss_uint128)(y);
etiss_coverage_count(6, 6933, 6932, 6928, 6926, 6931, 6929);
etiss_coverage_count(1, 6940);
return (etiss_uint64)((res >> 64ULL));
etiss_coverage_count(4, 6939, 6936, 6934, 6937);
} // block
}
