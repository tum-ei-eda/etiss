/**
 * Generated on Mon, 26 Oct 2026 08:39:20 +0000.
 *
 * This file contains the function implementations for the RV64IMACFD core architecture.
 */

#include "RV64IMACFDFuncs.h"
// clang-format off

etiss_uint8 RV64IMACFD_extension_enabled(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int8 extension)
{
etiss_coverage_count(1, 80);
{ // block
etiss_coverage_count(1, 260);
etiss_coverage_count(1, 259);
return (etiss_uint8)(((*((RV64IMACFD*)cpu)->CSR[769ULL] >> (extension - 65ULL)) & 1ULL));
etiss_coverage_count(11, 258, 255, 252, 247, 250, 248, 249, 251, 253, 254, 256);
} // block
}

etiss_uint8 RV64IMACFD_get_rm(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint8 rm)
{
etiss_coverage_count(1, 87);
{ // block
etiss_coverage_count(1, 280);
etiss_coverage_count(1, 261);
if (rm == 7ULL) { // conditional
etiss_coverage_count(3, 264, 262, 263);
rm = ((((((RV64IMACFD*)cpu)->FCSR) >> (5ULL)) & 0x7ULL)) & 0x7ULL;
etiss_coverage_count(6, 270, 265, 269, 266, 267, 268);
} // conditional
etiss_coverage_count(1, 271);
if (rm > 4ULL) { // conditional
etiss_coverage_count(3, 274, 272, 273);
RV64IMACFD_raise(cpu, system, plugin_pointers, 0LL, 2ULL);
etiss_coverage_count(2, 277, 275);
} // conditional
etiss_coverage_count(1, 279);
return rm;
etiss_coverage_count(1, 278);
} // block
}

etiss_uint64 RV64IMACFD_get_field(etiss_uint64 reg, etiss_uint64 mask)
{
etiss_coverage_count(1, 149);
{ // block
etiss_coverage_count(1, 300);
etiss_coverage_count(1, 281);
if (!(mask)) { // conditional
etiss_coverage_count(2, 283, 282);
etiss_coverage_count(1, 285);
return 0LL;
etiss_coverage_count(1, 284);
} // conditional
etiss_coverage_count(1, 299);
return (reg & mask) / (mask & ~((mask << 1ULL)));
etiss_coverage_count(13, 298, 288, 286, 287, 289, 296, 290, 295, 293, 291, 292, 294, 297);
} // block
}

etiss_uint64 RV64IMACFD_set_field(etiss_uint64 reg, etiss_uint64 mask, etiss_uint64 val)
{
etiss_coverage_count(1, 150);
{ // block
etiss_coverage_count(1, 325);
etiss_coverage_count(1, 324);
return (etiss_uint64)(((reg & ~(mask)) | ((((etiss_uint128)(val) * (etiss_uint128)((mask & ~((mask << 1ULL)))))) & mask)));
etiss_coverage_count(22, 323, 320, 304, 301, 303, 302, 305, 318, 315, 306, 313, 307, 312, 310, 308, 309, 311, 314, 316, 317, 319, 321);
} // block
}

etiss_uint64 RV64IMACFD_sstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 151);
{ // block
etiss_coverage_count(1, 398);
etiss_uint64 mask = 0LL;
etiss_coverage_count(2, 328, 327);
etiss_coverage_count(1, 329);
if (RV64IMACFD_extension_enabled(cpu, system, plugin_pointers, 83ULL)) { // conditional
etiss_coverage_count(2, 331, 330);
{ // block
etiss_coverage_count(1, 395);
mask = mask | 5767458LL;
etiss_coverage_count(2, 347, 332);
etiss_coverage_count(1, 348);
if (RV64IMACFD_extension_enabled(cpu, system, plugin_pointers, 86ULL)) { // conditional
etiss_coverage_count(2, 350, 349);
mask = mask | 1536ULL;
etiss_coverage_count(2, 353, 351);
} // conditional
etiss_coverage_count(1, 354);
if (RV64IMACFD_extension_enabled(cpu, system, plugin_pointers, 70ULL)) { // conditional
etiss_coverage_count(2, 356, 355);
mask = mask | 24576ULL;
etiss_coverage_count(2, 359, 357);
} // conditional
etiss_coverage_count(1, 360);
if (RV64IMACFD_extension_enabled(cpu, system, plugin_pointers, 88ULL)) { // conditional
etiss_coverage_count(2, 362, 361);
mask = mask | 98304ULL;
etiss_coverage_count(2, 365, 363);
} // conditional
etiss_coverage_count(1, 366);
if ((RV64IMACFD_get_field(*((RV64IMACFD*)cpu)->CSR[384ULL], 17293822569102704640ULL))) { // conditional
etiss_coverage_count(3, 388, 384, 390);
mask = mask | 262144ULL;
etiss_coverage_count(2, 394, 392);
} // conditional
} // block
} // conditional
etiss_coverage_count(1, 397);
return mask;
etiss_coverage_count(1, 396);
} // block
}

etiss_uint64 RV64IMACFD_mstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 152);
{ // block
etiss_coverage_count(1, 413);
etiss_uint64 mask = 6280LL;
etiss_coverage_count(1, 408);
etiss_coverage_count(1, 412);
return mask | RV64IMACFD_sstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(3, 411, 409, 410);
} // block
}

etiss_uint64 RV64IMACFD_csr_read(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr)
{
etiss_coverage_count(1, 153);
{ // block
etiss_coverage_count(1, 549);
etiss_coverage_count(1, 414);
if (csr == 1ULL) { // conditional
etiss_coverage_count(2, 417, 415);
etiss_coverage_count(1, 423);
return *((RV64IMACFD*)cpu)->CSR[3ULL] & 31ULL;
etiss_coverage_count(3, 422, 420, 421);
} // conditional
etiss_coverage_count(1, 424);
if (csr == 2ULL) { // conditional
etiss_coverage_count(2, 427, 425);
etiss_coverage_count(1, 436);
return (*((RV64IMACFD*)cpu)->CSR[3ULL] >> 5ULL) & 7ULL;
etiss_coverage_count(6, 435, 432, 430, 431, 433, 434);
} // conditional
etiss_coverage_count(1, 437);
if (csr == 3072ULL) { // conditional
etiss_coverage_count(2, 440, 438);
etiss_coverage_count(1, 444);
return (etiss_uint64)(etiss_get_cycles(cpu, system, plugin_pointers));
etiss_coverage_count(2, 443, 441);
} // conditional
etiss_coverage_count(1, 445);
if (csr == 3200ULL) { // conditional
etiss_coverage_count(2, 448, 446);
etiss_coverage_count(1, 455);
return (etiss_uint64)((etiss_get_cycles(cpu, system, plugin_pointers) >> 32ULL));
etiss_coverage_count(5, 454, 451, 449, 450, 452);
} // conditional
etiss_coverage_count(1, 456);
if (csr == 3073ULL) { // conditional
etiss_coverage_count(2, 459, 457);
etiss_coverage_count(1, 463);
return (etiss_uint64)(etiss_get_time());
etiss_coverage_count(2, 462, 460);
} // conditional
etiss_coverage_count(1, 464);
if (csr == 3201ULL) { // conditional
etiss_coverage_count(2, 467, 465);
etiss_coverage_count(1, 474);
return (etiss_uint64)((etiss_get_time() >> 32ULL));
etiss_coverage_count(5, 473, 470, 468, 469, 471);
} // conditional
etiss_coverage_count(1, 475);
if (csr == 3074ULL) { // conditional
etiss_coverage_count(2, 478, 476);
etiss_coverage_count(1, 482);
return (etiss_uint64)(etiss_get_instret(cpu, system, plugin_pointers));
etiss_coverage_count(2, 481, 479);
} // conditional
etiss_coverage_count(1, 483);
if (csr == 3202ULL) { // conditional
etiss_coverage_count(2, 486, 484);
etiss_coverage_count(1, 493);
return (etiss_uint64)((etiss_get_instret(cpu, system, plugin_pointers) >> 32ULL));
etiss_coverage_count(5, 492, 489, 487, 488, 490);
} // conditional
etiss_coverage_count(1, 494);
if (csr == 768ULL || csr == 256ULL) { // conditional
etiss_coverage_count(5, 501, 497, 495, 500, 498);
etiss_coverage_count(1, 524);
return (etiss_uint64)((*((RV64IMACFD*)cpu)->CSR[768ULL] | 8589934592ULL | 34359738368ULL));
etiss_coverage_count(5, 523, 520, 512, 504, 521);
} // conditional
etiss_coverage_count(1, 525);
if (csr == 769ULL) { // conditional
etiss_coverage_count(2, 528, 526);
etiss_coverage_count(1, 544);
return (((2ULL) << 62) | (((*((RV64IMACFD*)cpu)->CSR[769ULL]) & 0x3fffffffffffffffULL)));
etiss_coverage_count(4, 543, 542, 537, 541);
} // conditional
etiss_coverage_count(1, 548);
return *((RV64IMACFD*)cpu)->CSR[csr];
etiss_coverage_count(2, 547, 546);
} // block
}

void RV64IMACFD_csr_write(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr, etiss_uint64 val)
{
etiss_coverage_count(1, 154);
{ // block
etiss_coverage_count(1, 631);
etiss_coverage_count(1, 550);
if (csr == 1ULL) { // conditional
etiss_coverage_count(2, 553, 551);
*((RV64IMACFD*)cpu)->CSR[3ULL] = (*((RV64IMACFD*)cpu)->CSR[3ULL] & 224ULL) | (val & 31ULL);
etiss_coverage_count(10, 586, 571, 585, 579, 574, 580, 583, 581, 582, 584);
} // conditional
 else if (csr == 2ULL) { // conditional
etiss_coverage_count(2, 556, 554);
*((RV64IMACFD*)cpu)->CSR[3ULL] = ((val & 7ULL) << 5ULL) | (*((RV64IMACFD*)cpu)->CSR[3ULL] & 31ULL);
etiss_coverage_count(14, 604, 589, 603, 595, 592, 590, 591, 593, 594, 596, 601, 599, 600, 602);
} // conditional
 else if (csr == 3ULL) { // conditional
etiss_coverage_count(2, 559, 557);
*((RV64IMACFD*)cpu)->CSR[3ULL] = val & 255ULL;
etiss_coverage_count(5, 611, 607, 610, 608, 609);
} // conditional
 else if (csr == 768ULL) { // conditional
etiss_coverage_count(2, 562, 560);
*((RV64IMACFD*)cpu)->CSR[768ULL] = val & RV64IMACFD_mstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(5, 618, 614, 617, 615, 616);
} // conditional
 else if (csr == 256ULL) { // conditional
etiss_coverage_count(2, 565, 563);
*((RV64IMACFD*)cpu)->CSR[768ULL] = val & RV64IMACFD_sstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(5, 625, 621, 624, 622, 623);
} // conditional
 else if (csr != 769ULL) { // conditional
etiss_coverage_count(2, 568, 566);
*((RV64IMACFD*)cpu)->CSR[csr] = val;
etiss_coverage_count(4, 630, 628, 627, 629);
} // conditional
} // block
}

etiss_uint8 RV64IMACFD_ctz(etiss_uint64 val)
{
etiss_coverage_count(1, 161);
{ // block
etiss_coverage_count(1, 723);
etiss_coverage_count(1, 632);
if (!(val)) { // conditional
etiss_coverage_count(2, 634, 633);
etiss_coverage_count(1, 636);
return 0LL;
etiss_coverage_count(1, 635);
} // conditional
etiss_uint8 res = 0LL;
etiss_coverage_count(2, 639, 638);
etiss_coverage_count(1, 640);
if ((val << 32ULL) == 0LL) { // conditional
etiss_coverage_count(6, 646, 643, 641, 642, 644, 645);
{ // block
etiss_coverage_count(1, 653);
res = res + 32ULL;
etiss_coverage_count(3, 649, 647, 648);
val = val >> 32ULL;
etiss_coverage_count(3, 652, 650, 651);
} // block
} // conditional
etiss_coverage_count(1, 654);
if ((val << 48ULL) == 0LL) { // conditional
etiss_coverage_count(6, 660, 657, 655, 656, 658, 659);
{ // block
etiss_coverage_count(1, 667);
res = res + 16ULL;
etiss_coverage_count(3, 663, 661, 662);
val = val >> 16ULL;
etiss_coverage_count(3, 666, 664, 665);
} // block
} // conditional
etiss_coverage_count(1, 668);
if ((val << 56ULL) == 0LL) { // conditional
etiss_coverage_count(6, 674, 671, 669, 670, 672, 673);
{ // block
etiss_coverage_count(1, 681);
res = res + 8ULL;
etiss_coverage_count(3, 677, 675, 676);
val = val >> 8ULL;
etiss_coverage_count(3, 680, 678, 679);
} // block
} // conditional
etiss_coverage_count(1, 682);
if ((val << 60ULL) == 0LL) { // conditional
etiss_coverage_count(6, 688, 685, 683, 684, 686, 687);
{ // block
etiss_coverage_count(1, 695);
res = res + 4ULL;
etiss_coverage_count(3, 691, 689, 690);
val = val >> 4ULL;
etiss_coverage_count(3, 694, 692, 693);
} // block
} // conditional
etiss_coverage_count(1, 696);
if ((val << 62ULL) == 0LL) { // conditional
etiss_coverage_count(6, 702, 699, 697, 698, 700, 701);
{ // block
etiss_coverage_count(1, 709);
res = res + 2ULL;
etiss_coverage_count(3, 705, 703, 704);
val = val >> 2ULL;
etiss_coverage_count(3, 708, 706, 707);
} // block
} // conditional
etiss_coverage_count(1, 710);
if ((val << 63ULL) == 0LL) { // conditional
etiss_coverage_count(6, 716, 713, 711, 712, 714, 715);
{ // block
etiss_coverage_count(1, 720);
res = res + 1ULL;
etiss_coverage_count(3, 719, 717, 718);
} // block
} // conditional
etiss_coverage_count(1, 722);
return res;
etiss_coverage_count(1, 721);
} // block
}

void RV64IMACFD_raise(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 irq, etiss_uint64 mcause)
{
cpu->return_pending = 1;
cpu->exception = 0;
etiss_coverage_count(1, 162);
{ // block
etiss_coverage_count(1, 973);
etiss_uint64 epc = cpu->instructionPointer;
etiss_coverage_count(2, 726, 725);
etiss_int64 deleg = 0LL;
etiss_coverage_count(1, 728);
etiss_int64 vector = 0LL;
etiss_coverage_count(1, 729);
etiss_int64 bit = mcause;
etiss_coverage_count(2, 731, 730);
etiss_int32 irq2 = (mcause & 9223372036854775808ULL) != 0LL;
etiss_coverage_count(6, 747, 746, 743, 733, 744, 745);
etiss_coverage_count(1, 748);
if (irq2) { // conditional
etiss_coverage_count(1, 749);
{ // block
etiss_coverage_count(1, 780);
deleg = (etiss_uint64)((((((RV64IMACFD*)cpu)->PRIV <= 1ULL)) ? (*((RV64IMACFD*)cpu)->CSR[771ULL]) : (0LL)));
etiss_coverage_count(10, 763, 750, 762, 759, 753, 751, 754, 757, 758, 760);
bit = bit & 9223372036854775807ULL;
etiss_coverage_count(2, 779, 764);
} // block
} // conditional
else { // conditional
{ // block
etiss_coverage_count(1, 795);
deleg = (etiss_uint64)((((((RV64IMACFD*)cpu)->PRIV <= 1ULL)) ? (*((RV64IMACFD*)cpu)->CSR[770ULL]) : (0LL)));
etiss_coverage_count(10, 794, 781, 793, 790, 784, 782, 785, 788, 789, 791);
} // block
} // conditional
etiss_coverage_count(1, 796);
if (((RV64IMACFD*)cpu)->PRIV <= 1ULL && (deleg >> bit) & 1ULL) { // conditional
etiss_coverage_count(9, 806, 799, 797, 805, 802, 800, 801, 803, 804);
{ // block
etiss_coverage_count(1, 889);
vector = (etiss_uint64)((((*((RV64IMACFD*)cpu)->CSR[261ULL] & 1ULL) && irq2) ? (((etiss_int128)(bit) * (etiss_int128)(4ULL))) : (0LL)));
etiss_coverage_count(15, 824, 807, 823, 820, 815, 812, 810, 811, 813, 814, 818, 816, 817, 819, 821);
cpu->nextPc = (etiss_uint64)(((*((RV64IMACFD*)cpu)->CSR[261ULL] & -2LL) + vector));
etiss_coverage_count(9, 840, 825, 839, 836, 833, 828, 834, 835, 837);
*((RV64IMACFD*)cpu)->CSR[321ULL] = epc;
etiss_coverage_count(3, 845, 843, 844);
*((RV64IMACFD*)cpu)->CSR[322ULL] = mcause;
etiss_coverage_count(3, 850, 848, 849);
etiss_uint64 s = RV64IMACFD_csr_read(cpu, system, plugin_pointers, 256ULL);
etiss_coverage_count(2, 854, 853);
s = (etiss_uint64)(RV64IMACFD_set_field(s, 32ULL, RV64IMACFD_get_field(s, 2ULL)));
etiss_coverage_count(7, 864, 855, 863, 861, 856, 860, 858);
s = (etiss_uint64)(RV64IMACFD_set_field(s, 256ULL, ((RV64IMACFD*)cpu)->PRIV));
etiss_coverage_count(6, 872, 865, 871, 869, 866, 868);
s = (etiss_uint64)(RV64IMACFD_set_field(s, 2ULL, 0LL));
etiss_coverage_count(6, 880, 873, 879, 877, 874, 876);
RV64IMACFD_csr_write(cpu, system, plugin_pointers, 256ULL, s);
etiss_coverage_count(2, 883, 882);
((RV64IMACFD*)cpu)->PRIV = (1ULL) & 0x7ULL;
etiss_coverage_count(2, 888, 884);
} // block
} // conditional
else { // conditional
{ // block
etiss_coverage_count(1, 972);
vector = (etiss_uint64)((((*((RV64IMACFD*)cpu)->CSR[773ULL] & 1ULL) && irq2) ? (((etiss_int128)(bit) * (etiss_int128)(4ULL))) : (0LL)));
etiss_coverage_count(15, 907, 890, 906, 903, 898, 895, 893, 894, 896, 897, 901, 899, 900, 902, 904);
cpu->nextPc = (etiss_uint64)(((*((RV64IMACFD*)cpu)->CSR[773ULL] & -2LL) + vector));
etiss_coverage_count(9, 923, 908, 922, 919, 916, 911, 917, 918, 920);
*((RV64IMACFD*)cpu)->CSR[833ULL] = epc;
etiss_coverage_count(3, 928, 926, 927);
*((RV64IMACFD*)cpu)->CSR[834ULL] = mcause;
etiss_coverage_count(3, 933, 931, 932);
etiss_uint64 s = RV64IMACFD_csr_read(cpu, system, plugin_pointers, 768ULL);
etiss_coverage_count(2, 937, 936);
s = (etiss_uint64)(RV64IMACFD_set_field(s, 128ULL, RV64IMACFD_get_field(s, 8ULL)));
etiss_coverage_count(7, 947, 938, 946, 944, 939, 943, 941);
s = (etiss_uint64)(RV64IMACFD_set_field(s, 6144ULL, ((RV64IMACFD*)cpu)->PRIV));
etiss_coverage_count(6, 955, 948, 954, 952, 949, 951);
s = (etiss_uint64)(RV64IMACFD_set_field(s, 8ULL, 0LL));
etiss_coverage_count(6, 963, 956, 962, 960, 957, 959);
RV64IMACFD_csr_write(cpu, system, plugin_pointers, 768ULL, s);
etiss_coverage_count(2, 966, 965);
((RV64IMACFD*)cpu)->PRIV = (3ULL) & 0x7ULL;
etiss_coverage_count(2, 971, 967);
} // block
} // conditional
} // block
}

void RV64IMACFD_translate_exc_code(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 cause)
{
etiss_coverage_count(1, 163);
{ // block
etiss_coverage_count(1, 1030);
etiss_uint64 code = 0LL;
etiss_coverage_count(2, 977, 976);
etiss_coverage_count(1, 978);
if (cause == -2147483648LL) { // conditional
etiss_coverage_count(2, 981, 979);
etiss_coverage_count(1, 1000);
return;
} // conditional
 else if (cause == -5LL) { // conditional
etiss_coverage_count(2, 984, 982);
code = 5ULL;
etiss_coverage_count(2, 1003, 1001);
} // conditional
 else if (cause == -14LL) { // conditional
etiss_coverage_count(2, 987, 985);
code = 13ULL;
etiss_coverage_count(2, 1006, 1004);
} // conditional
 else if (cause == -6LL) { // conditional
etiss_coverage_count(2, 990, 988);
code = 7ULL;
etiss_coverage_count(2, 1009, 1007);
} // conditional
 else if (cause == -15LL) { // conditional
etiss_coverage_count(2, 993, 991);
code = 15ULL;
etiss_coverage_count(2, 1012, 1010);
} // conditional
 else if (cause == -7LL) { // conditional
etiss_coverage_count(2, 996, 994);
code = 1ULL;
etiss_coverage_count(2, 1015, 1013);
} // conditional
 else if (cause == -9LL) { // conditional
etiss_coverage_count(2, 999, 997);
{ // block
etiss_coverage_count(1, 1023);
code = RV64IMACFD_calc_irq_mcause(cpu, system, plugin_pointers);
etiss_coverage_count(3, 1018, 1016, 1017);
etiss_coverage_count(1, 1019);
if (!(code)) { // conditional
etiss_coverage_count(2, 1021, 1020);
etiss_coverage_count(1, 1022);
return;
} // conditional
} // block
} // conditional
else { // conditional
code = 2ULL;
etiss_coverage_count(2, 1026, 1024);
} // conditional
RV64IMACFD_raise(cpu, system, plugin_pointers, 0LL, code);
etiss_coverage_count(3, 1029, 1027, 1028);
} // block
}

etiss_uint64 RV64IMACFD_calc_irq_mcause(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 164);
{ // block
etiss_coverage_count(1, 1221);
etiss_uint64 pending_interrupts = *((RV64IMACFD*)cpu)->CSR[772ULL] & *((RV64IMACFD*)cpu)->CSR[836ULL];
etiss_coverage_count(4, 1039, 1038, 1034, 1037);
etiss_coverage_count(1, 1040);
if (!(pending_interrupts)) { // conditional
etiss_coverage_count(2, 1042, 1041);
etiss_coverage_count(1, 1044);
return 0LL;
etiss_coverage_count(1, 1043);
} // conditional
etiss_uint64 mie = (etiss_uint64)(RV64IMACFD_get_field(*((RV64IMACFD*)cpu)->CSR[768ULL], 8ULL));
etiss_coverage_count(4, 1053, 1052, 1050, 1048);
etiss_uint64 m_enabled = ((RV64IMACFD*)cpu)->PRIV < 3ULL || (((RV64IMACFD*)cpu)->PRIV == 3ULL && mie);
etiss_coverage_count(9, 1065, 1064, 1057, 1055, 1062, 1060, 1058, 1061, 1063);
etiss_uint64 enabled_interrupts = (etiss_uint64)((pending_interrupts & ~(*((RV64IMACFD*)cpu)->CSR[771ULL]) & -(m_enabled)));
etiss_coverage_count(10, 1079, 1078, 1075, 1072, 1067, 1071, 1070, 1074, 1073, 1076);
etiss_coverage_count(1, 1080);
if (enabled_interrupts == 0LL) { // conditional
etiss_coverage_count(3, 1083, 1081, 1082);
{ // block
etiss_coverage_count(1, 1120);
etiss_uint64 deleg = *((RV64IMACFD*)cpu)->CSR[771ULL];
etiss_coverage_count(2, 1088, 1087);
etiss_uint64 sie = (etiss_uint64)(RV64IMACFD_get_field(RV64IMACFD_csr_read(cpu, system, plugin_pointers, 256ULL), 2ULL));
etiss_coverage_count(4, 1096, 1095, 1093, 1091);
etiss_uint64 s_enabled = ((RV64IMACFD*)cpu)->PRIV < 1ULL || (((RV64IMACFD*)cpu)->PRIV == 1ULL && sie);
etiss_coverage_count(9, 1108, 1107, 1100, 1098, 1105, 1103, 1101, 1104, 1106);
enabled_interrupts = (etiss_uint64)((pending_interrupts & deleg & -(s_enabled)));
etiss_coverage_count(10, 1119, 1109, 1118, 1115, 1112, 1110, 1111, 1114, 1113, 1116);
} // block
} // conditional
etiss_coverage_count(1, 1121);
if (enabled_interrupts) { // conditional
etiss_coverage_count(1, 1122);
{ // block
etiss_coverage_count(1, 1218);
etiss_coverage_count(1, 1123);
if (enabled_interrupts >> 12ULL) { // conditional
etiss_coverage_count(2, 1129, 1124);
enabled_interrupts = enabled_interrupts >> 12ULL << 12ULL;
etiss_coverage_count(5, 1172, 1160, 1171, 1166, 1161);
} // conditional
 else if (enabled_interrupts & 2048ULL) { // conditional
etiss_coverage_count(2, 1132, 1130);
enabled_interrupts = 2048ULL;
etiss_coverage_count(2, 1175, 1173);
} // conditional
 else if (enabled_interrupts & 8ULL) { // conditional
etiss_coverage_count(2, 1135, 1133);
enabled_interrupts = 8ULL;
etiss_coverage_count(2, 1178, 1176);
} // conditional
 else if (enabled_interrupts & 128ULL) { // conditional
etiss_coverage_count(2, 1138, 1136);
enabled_interrupts = 128ULL;
etiss_coverage_count(2, 1181, 1179);
} // conditional
 else if (enabled_interrupts & 512ULL) { // conditional
etiss_coverage_count(2, 1141, 1139);
enabled_interrupts = 512ULL;
etiss_coverage_count(2, 1184, 1182);
} // conditional
 else if (enabled_interrupts & 2ULL) { // conditional
etiss_coverage_count(2, 1144, 1142);
enabled_interrupts = 2ULL;
etiss_coverage_count(2, 1187, 1185);
} // conditional
 else if (enabled_interrupts & 32ULL) { // conditional
etiss_coverage_count(2, 1147, 1145);
enabled_interrupts = 32ULL;
etiss_coverage_count(2, 1190, 1188);
} // conditional
 else if (enabled_interrupts & 8192ULL) { // conditional
etiss_coverage_count(2, 1150, 1148);
enabled_interrupts = 8192ULL;
etiss_coverage_count(2, 1193, 1191);
} // conditional
 else if (enabled_interrupts & 1024ULL) { // conditional
etiss_coverage_count(2, 1153, 1151);
enabled_interrupts = 1024ULL;
etiss_coverage_count(2, 1196, 1194);
} // conditional
 else if (enabled_interrupts & 4ULL) { // conditional
etiss_coverage_count(2, 1156, 1154);
enabled_interrupts = 4ULL;
etiss_coverage_count(2, 1199, 1197);
} // conditional
 else if (enabled_interrupts & 64ULL) { // conditional
etiss_coverage_count(2, 1159, 1157);
enabled_interrupts = 64ULL;
etiss_coverage_count(2, 1202, 1200);
} // conditional
else { // conditional
etiss_coverage_count(1, 1204);
return 0LL;
etiss_coverage_count(1, 1203);
} // conditional
etiss_coverage_count(1, 1217);
return 9223372036854775808ULL | RV64IMACFD_ctz(enabled_interrupts);
etiss_coverage_count(3, 1216, 1215, 1214);
} // block
} // conditional
etiss_coverage_count(1, 1220);
return 0LL;
etiss_coverage_count(1, 1219);
} // block
}

void RV64IMACFD_check_irq(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 165);
{ // block
etiss_coverage_count(1, 1230);
etiss_uint64 irq_mcause = RV64IMACFD_calc_irq_mcause(cpu, system, plugin_pointers);
etiss_coverage_count(2, 1224, 1223);
etiss_coverage_count(1, 1225);
if (irq_mcause) { // conditional
etiss_coverage_count(1, 1226);
RV64IMACFD_raise(cpu, system, plugin_pointers, 1ULL, irq_mcause);
etiss_coverage_count(3, 1229, 1227, 1228);
} // conditional
} // block
}

etiss_int64 RV64IMACFD_mulh(etiss_int64 x, etiss_int64 y)
{
etiss_coverage_count(1, 237);
{ // block
etiss_coverage_count(1, 8236);
etiss_int128 res = ((etiss_int128)(((etiss_int64)(((etiss_int64)x) << (0)) >> (0))) * (etiss_int128)(((etiss_int64)(((etiss_int64)y) << (0)) >> (0))));
etiss_coverage_count(6, 8228, 8227, 8223, 8221, 8226, 8224);
etiss_coverage_count(1, 8235);
return (etiss_int64)((res >> 64ULL));
etiss_coverage_count(4, 8234, 8231, 8229, 8232);
} // block
}

etiss_int64 RV64IMACFD_mulhsu(etiss_int64 x, etiss_uint64 y)
{
etiss_coverage_count(1, 238);
{ // block
etiss_coverage_count(1, 8253);
etiss_int128 res = ((etiss_int128)(((etiss_int64)(((etiss_int64)x) << (0)) >> (0))) * (etiss_int128)((etiss_uint64)(y)));
etiss_coverage_count(6, 8245, 8244, 8240, 8238, 8243, 8241);
etiss_coverage_count(1, 8252);
return (etiss_int64)((res >> 64ULL));
etiss_coverage_count(4, 8251, 8248, 8246, 8249);
} // block
}

etiss_uint64 RV64IMACFD_mulhu(etiss_uint64 x, etiss_uint64 y)
{
etiss_coverage_count(1, 239);
{ // block
etiss_coverage_count(1, 8270);
etiss_uint128 res = ((etiss_uint128)((etiss_uint64)(x)) * (etiss_uint128)((etiss_uint64)(y)));
etiss_coverage_count(6, 8262, 8261, 8257, 8255, 8260, 8258);
etiss_coverage_count(1, 8269);
return (etiss_uint64)((res >> 64ULL));
etiss_coverage_count(4, 8268, 8265, 8263, 8266);
} // block
}
// clang-format on
