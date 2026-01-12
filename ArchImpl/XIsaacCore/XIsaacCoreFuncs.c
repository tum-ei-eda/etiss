/**
 * Generated on Mon, 12 Jan 2026 12:41:11 +0100.
 *
 * This file contains the function implementations for the XIsaacCore core architecture.
 */

#include "XIsaacCoreFuncs.h"

etiss_uint8 XIsaacCore_extension_enabled(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int8 extension)
{
etiss_coverage_count(1, 81);
{ // block
etiss_coverage_count(1, 260);
etiss_coverage_count(1, 259);
return (*((XIsaacCore*)cpu)->CSR[769LL] >> (extension - 65ULL)) & 1ULL;
etiss_coverage_count(9, 258, 255, 250, 253, 251, 252, 254, 256, 257);
} // block
}

etiss_uint8 XIsaacCore_get_rm(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint8 rm)
{
etiss_coverage_count(1, 88);
{ // block
etiss_coverage_count(1, 280);
etiss_coverage_count(1, 261);
if (rm == 7ULL) { // conditional
etiss_coverage_count(3, 264, 262, 263);
rm = ((((((XIsaacCore*)cpu)->FCSR) >> (5ULL)) & 7ULL)) & 0x7;
etiss_coverage_count(6, 270, 265, 269, 266, 267, 268);
} // conditional
etiss_coverage_count(1, 271);
if (rm > 4ULL) { // conditional
etiss_coverage_count(3, 274, 272, 273);
XIsaacCore_raise(cpu, system, plugin_pointers, 0LL, 2LL);
etiss_coverage_count(2, 277, 275);
} // conditional
etiss_coverage_count(1, 279);
return rm;
etiss_coverage_count(1, 278);
} // block
}

etiss_uint32 XIsaacCore_sstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 150);
{ // block
etiss_coverage_count(1, 353);
etiss_uint32 mask = 0LL;
etiss_coverage_count(2, 283, 282);
etiss_coverage_count(1, 284);
if (XIsaacCore_extension_enabled(cpu, system, plugin_pointers, 83ULL)) { // conditional
etiss_coverage_count(2, 286, 285);
{ // block
etiss_coverage_count(1, 350);
mask = mask | 5767458ULL;
etiss_coverage_count(2, 302, 287);
etiss_coverage_count(1, 303);
if (XIsaacCore_extension_enabled(cpu, system, plugin_pointers, 86ULL)) { // conditional
etiss_coverage_count(2, 305, 304);
mask = mask | 1536LL;
etiss_coverage_count(2, 308, 306);
} // conditional
etiss_coverage_count(1, 309);
if (XIsaacCore_extension_enabled(cpu, system, plugin_pointers, 70ULL)) { // conditional
etiss_coverage_count(2, 311, 310);
mask = mask | 24576LL;
etiss_coverage_count(2, 314, 312);
} // conditional
etiss_coverage_count(1, 315);
if (XIsaacCore_extension_enabled(cpu, system, plugin_pointers, 88ULL)) { // conditional
etiss_coverage_count(2, 317, 316);
mask = mask | 98304LL;
etiss_coverage_count(2, 320, 318);
} // conditional
etiss_coverage_count(1, 321);
if ((XIsaacCore_get_field(*((XIsaacCore*)cpu)->CSR[384LL], 2147483648ULL))) { // conditional
etiss_coverage_count(3, 331, 327, 333);
mask = mask | 262144LL;
etiss_coverage_count(2, 349, 347);
} // conditional
} // block
} // conditional
etiss_coverage_count(1, 352);
return mask;
etiss_coverage_count(1, 351);
} // block
}

etiss_uint32 XIsaacCore_mstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 151);
{ // block
etiss_coverage_count(1, 368);
etiss_uint32 mask = 6280ULL;
etiss_coverage_count(1, 363);
etiss_coverage_count(1, 367);
return mask | XIsaacCore_sstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(3, 366, 364, 365);
} // block
}

etiss_uint32 XIsaacCore_csr_read(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr)
{
etiss_coverage_count(1, 152);
{ // block
etiss_coverage_count(1, 486);
etiss_coverage_count(1, 369);
if (csr == 1LL) { // conditional
etiss_coverage_count(2, 372, 370);
etiss_coverage_count(1, 378);
return *((XIsaacCore*)cpu)->CSR[3LL] & 31ULL;
etiss_coverage_count(3, 377, 375, 376);
} // conditional
etiss_coverage_count(1, 379);
if (csr == 2LL) { // conditional
etiss_coverage_count(2, 382, 380);
etiss_coverage_count(1, 391);
return (*((XIsaacCore*)cpu)->CSR[3LL] >> 5ULL) & 7ULL;
etiss_coverage_count(6, 390, 387, 385, 386, 388, 389);
} // conditional
etiss_coverage_count(1, 392);
if (csr == 3072LL) { // conditional
etiss_coverage_count(2, 395, 393);
etiss_coverage_count(1, 397);
return etiss_get_cycles(cpu, system, plugin_pointers);
etiss_coverage_count(1, 396);
} // conditional
etiss_coverage_count(1, 398);
if (csr == 3200LL) { // conditional
etiss_coverage_count(2, 401, 399);
etiss_coverage_count(1, 405);
return etiss_get_cycles(cpu, system, plugin_pointers) >> 32ULL;
etiss_coverage_count(3, 404, 402, 403);
} // conditional
etiss_coverage_count(1, 406);
if (csr == 3073LL) { // conditional
etiss_coverage_count(2, 409, 407);
etiss_coverage_count(1, 411);
return etiss_get_time();
etiss_coverage_count(1, 410);
} // conditional
etiss_coverage_count(1, 412);
if (csr == 3201LL) { // conditional
etiss_coverage_count(2, 415, 413);
etiss_coverage_count(1, 419);
return etiss_get_time() >> 32ULL;
etiss_coverage_count(3, 418, 416, 417);
} // conditional
etiss_coverage_count(1, 420);
if (csr == 3074LL) { // conditional
etiss_coverage_count(2, 423, 421);
etiss_coverage_count(1, 425);
return etiss_get_instret(cpu, system, plugin_pointers);
etiss_coverage_count(1, 424);
} // conditional
etiss_coverage_count(1, 426);
if (csr == 3202LL) { // conditional
etiss_coverage_count(2, 429, 427);
etiss_coverage_count(1, 433);
return etiss_get_instret(cpu, system, plugin_pointers) >> 32ULL;
etiss_coverage_count(3, 432, 430, 431);
} // conditional
etiss_coverage_count(1, 434);
if (csr == 768LL || csr == 256LL) { // conditional
etiss_coverage_count(5, 441, 437, 435, 440, 438);
etiss_coverage_count(1, 461);
return *((XIsaacCore*)cpu)->CSR[768LL] | 8589934592ULL | 34359738368ULL;
etiss_coverage_count(3, 460, 452, 444);
} // conditional
etiss_coverage_count(1, 462);
if (csr == 769LL) { // conditional
etiss_coverage_count(2, 465, 463);
etiss_coverage_count(1, 481);
return (((1ULL) << 30) | ((((*((XIsaacCore*)cpu)->CSR[769LL]) >> (0LL)) & 1073741823ULL)));
etiss_coverage_count(4, 480, 479, 474, 478);
} // conditional
etiss_coverage_count(1, 485);
return *((XIsaacCore*)cpu)->CSR[csr];
etiss_coverage_count(2, 484, 483);
} // block
}

void XIsaacCore_csr_write(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr, etiss_uint32 val)
{
etiss_coverage_count(1, 153);
{ // block
etiss_coverage_count(1, 568);
etiss_coverage_count(1, 487);
if (csr == 1LL) { // conditional
etiss_coverage_count(2, 490, 488);
*((XIsaacCore*)cpu)->CSR[3LL] = (*((XIsaacCore*)cpu)->CSR[3LL] & 224ULL) | (val & 31ULL);
etiss_coverage_count(10, 523, 508, 522, 516, 511, 517, 520, 518, 519, 521);
} // conditional
 else if (csr == 2LL) { // conditional
etiss_coverage_count(2, 493, 491);
*((XIsaacCore*)cpu)->CSR[3LL] = ((val & 7ULL) << 5ULL) | (*((XIsaacCore*)cpu)->CSR[3LL] & 31ULL);
etiss_coverage_count(14, 541, 526, 540, 532, 529, 527, 528, 530, 531, 533, 538, 536, 537, 539);
} // conditional
 else if (csr == 3LL) { // conditional
etiss_coverage_count(2, 496, 494);
*((XIsaacCore*)cpu)->CSR[3LL] = val & 255ULL;
etiss_coverage_count(5, 548, 544, 547, 545, 546);
} // conditional
 else if (csr == 768LL) { // conditional
etiss_coverage_count(2, 499, 497);
*((XIsaacCore*)cpu)->CSR[768LL] = val & XIsaacCore_mstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(5, 555, 551, 554, 552, 553);
} // conditional
 else if (csr == 256LL) { // conditional
etiss_coverage_count(2, 502, 500);
*((XIsaacCore*)cpu)->CSR[768LL] = val & XIsaacCore_sstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(5, 562, 558, 561, 559, 560);
} // conditional
 else if (csr != 769LL) { // conditional
etiss_coverage_count(2, 505, 503);
*((XIsaacCore*)cpu)->CSR[csr] = val;
etiss_coverage_count(4, 567, 565, 564, 566);
} // conditional
} // block
}

etiss_uint64 XIsaacCore_get_field(etiss_uint64 reg, etiss_uint64 mask)
{
etiss_coverage_count(1, 160);
{ // block
etiss_coverage_count(1, 588);
etiss_coverage_count(1, 569);
if (!(mask)) { // conditional
etiss_coverage_count(2, 571, 570);
etiss_coverage_count(1, 573);
return 0LL;
etiss_coverage_count(1, 572);
} // conditional
etiss_coverage_count(1, 587);
return (reg & mask) / (mask & ~((mask << 1ULL)));
etiss_coverage_count(13, 586, 576, 574, 575, 577, 584, 578, 583, 581, 579, 580, 582, 585);
} // block
}

etiss_uint64 XIsaacCore_set_field(etiss_uint64 reg, etiss_uint64 mask, etiss_uint64 val)
{
etiss_coverage_count(1, 161);
{ // block
etiss_coverage_count(1, 611);
etiss_coverage_count(1, 610);
return ((reg & ~(mask)) | ((val * (mask & ~((mask << 1ULL)))) & mask));
etiss_coverage_count(21, 608, 592, 589, 591, 590, 593, 606, 603, 594, 601, 595, 600, 598, 596, 597, 599, 602, 604, 605, 607, 609);
} // block
}

etiss_uint8 XIsaacCore_ctz(etiss_uint64 val)
{
etiss_coverage_count(1, 162);
{ // block
etiss_coverage_count(1, 706);
etiss_coverage_count(1, 612);
if (!(val)) { // conditional
etiss_coverage_count(2, 614, 613);
etiss_coverage_count(1, 616);
return 0LL;
etiss_coverage_count(1, 615);
} // conditional
etiss_uint8 res = 0LL;
etiss_coverage_count(2, 619, 618);
etiss_coverage_count(1, 620);
if ((val << 32ULL) == 0LL) { // conditional
etiss_coverage_count(6, 626, 623, 621, 622, 624, 625);
{ // block
etiss_coverage_count(1, 633);
res = res + 32ULL;
etiss_coverage_count(3, 629, 627, 628);
val = val >> 32ULL;
etiss_coverage_count(3, 632, 630, 631);
} // block
} // conditional
etiss_coverage_count(1, 634);
if ((val << 48ULL) == 0LL) { // conditional
etiss_coverage_count(6, 640, 637, 635, 636, 638, 639);
{ // block
etiss_coverage_count(1, 647);
res = res + 16ULL;
etiss_coverage_count(3, 643, 641, 642);
val = val >> 16ULL;
etiss_coverage_count(3, 646, 644, 645);
} // block
} // conditional
etiss_coverage_count(1, 648);
if ((val << 56ULL) == 0LL) { // conditional
etiss_coverage_count(6, 654, 651, 649, 650, 652, 653);
{ // block
etiss_coverage_count(1, 661);
res = res + 8ULL;
etiss_coverage_count(3, 657, 655, 656);
val = val >> 8ULL;
etiss_coverage_count(3, 660, 658, 659);
} // block
} // conditional
etiss_coverage_count(1, 662);
if ((val << 60ULL) == 0LL) { // conditional
etiss_coverage_count(6, 668, 665, 663, 664, 666, 667);
{ // block
etiss_coverage_count(1, 675);
res = res + 4ULL;
etiss_coverage_count(3, 671, 669, 670);
val = val >> 4ULL;
etiss_coverage_count(3, 674, 672, 673);
} // block
} // conditional
etiss_coverage_count(1, 676);
if ((val << 62ULL) == 0LL) { // conditional
etiss_coverage_count(6, 682, 679, 677, 678, 680, 681);
{ // block
etiss_coverage_count(1, 689);
res = res + 2ULL;
etiss_coverage_count(3, 685, 683, 684);
val = val >> 2ULL;
etiss_coverage_count(3, 688, 686, 687);
} // block
} // conditional
etiss_coverage_count(1, 690);
if ((val << 63ULL) == 0LL) { // conditional
etiss_coverage_count(6, 696, 693, 691, 692, 694, 695);
{ // block
etiss_coverage_count(1, 703);
res = res + 1ULL;
etiss_coverage_count(3, 699, 697, 698);
val = val >> 1ULL;
etiss_coverage_count(3, 702, 700, 701);
} // block
} // conditional
etiss_coverage_count(1, 705);
return res;
etiss_coverage_count(1, 704);
} // block
}

void XIsaacCore_raise(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 irq, etiss_uint32 mcause)
{
cpu->return_pending = 1;
cpu->exception = 0;
etiss_coverage_count(1, 163);
{ // block
etiss_coverage_count(1, 919);
etiss_uint32 epc = cpu->instructionPointer;
etiss_coverage_count(2, 709, 708);
etiss_uint32 deleg = 0LL;
etiss_coverage_count(1, 711);
etiss_uint32 vector = 0LL;
etiss_coverage_count(1, 712);
etiss_uint32 bit = mcause;
etiss_coverage_count(2, 714, 713);
etiss_int32 irq2 = (mcause & 2147483648ULL) != 0LL;
etiss_coverage_count(6, 730, 729, 726, 716, 727, 728);
etiss_coverage_count(1, 731);
if (irq2) { // conditional
etiss_coverage_count(1, 732);
{ // block
etiss_coverage_count(1, 757);
deleg = ((((XIsaacCore*)cpu)->PRIV <= 1LL)) ? (*((XIsaacCore*)cpu)->CSR[771LL]) : (0LL);
etiss_coverage_count(8, 743, 733, 742, 736, 734, 737, 740, 741);
bit = bit & 2147483647ULL;
etiss_coverage_count(2, 756, 744);
} // block
} // conditional
else { // conditional
{ // block
etiss_coverage_count(1, 769);
deleg = ((((XIsaacCore*)cpu)->PRIV <= 1LL)) ? (*((XIsaacCore*)cpu)->CSR[770LL]) : (0LL);
etiss_coverage_count(8, 768, 758, 767, 761, 759, 762, 765, 766);
} // block
} // conditional
etiss_coverage_count(1, 770);
if (((XIsaacCore*)cpu)->PRIV <= 1LL && (deleg >> bit) & 1ULL) { // conditional
etiss_coverage_count(9, 780, 773, 771, 779, 776, 774, 775, 777, 778);
{ // block
etiss_coverage_count(1, 849);
vector = ((*((XIsaacCore*)cpu)->CSR[261LL] & 1ULL) && irq2) ? (bit * 4ULL) : (0LL);
etiss_coverage_count(13, 795, 781, 794, 789, 786, 784, 785, 787, 788, 792, 790, 791, 793);
cpu->nextPc = (*((XIsaacCore*)cpu)->CSR[261LL] & -2LL) + vector;
etiss_coverage_count(7, 808, 796, 807, 804, 799, 805, 806);
*((XIsaacCore*)cpu)->CSR[321LL] = epc;
etiss_coverage_count(3, 813, 811, 812);
*((XIsaacCore*)cpu)->CSR[322LL] = mcause;
etiss_coverage_count(3, 818, 816, 817);
etiss_uint32 s = XIsaacCore_csr_read(cpu, system, plugin_pointers, 256LL);
etiss_coverage_count(2, 822, 821);
s = XIsaacCore_set_field(s, 32LL, XIsaacCore_get_field(s, 2LL));
etiss_coverage_count(6, 830, 823, 829, 824, 828, 826);
s = XIsaacCore_set_field(s, 256LL, ((XIsaacCore*)cpu)->PRIV);
etiss_coverage_count(5, 836, 831, 835, 832, 834);
s = XIsaacCore_set_field(s, 2LL, 0LL);
etiss_coverage_count(5, 842, 837, 841, 838, 840);
XIsaacCore_csr_write(cpu, system, plugin_pointers, 256LL, s);
etiss_coverage_count(2, 845, 844);
((XIsaacCore*)cpu)->PRIV = (1LL) & 0x7;
etiss_coverage_count(2, 848, 846);
} // block
} // conditional
else { // conditional
{ // block
etiss_coverage_count(1, 918);
vector = ((*((XIsaacCore*)cpu)->CSR[773LL] & 1ULL) && irq2) ? (bit * 4ULL) : (0LL);
etiss_coverage_count(13, 864, 850, 863, 858, 855, 853, 854, 856, 857, 861, 859, 860, 862);
cpu->nextPc = (*((XIsaacCore*)cpu)->CSR[773LL] & -2LL) + vector;
etiss_coverage_count(7, 877, 865, 876, 873, 868, 874, 875);
*((XIsaacCore*)cpu)->CSR[833LL] = epc;
etiss_coverage_count(3, 882, 880, 881);
*((XIsaacCore*)cpu)->CSR[834LL] = mcause;
etiss_coverage_count(3, 887, 885, 886);
etiss_uint32 s = XIsaacCore_csr_read(cpu, system, plugin_pointers, 768LL);
etiss_coverage_count(2, 891, 890);
s = XIsaacCore_set_field(s, 128LL, XIsaacCore_get_field(s, 8LL));
etiss_coverage_count(6, 899, 892, 898, 893, 897, 895);
s = XIsaacCore_set_field(s, 6144LL, ((XIsaacCore*)cpu)->PRIV);
etiss_coverage_count(5, 905, 900, 904, 901, 903);
s = XIsaacCore_set_field(s, 8LL, 0LL);
etiss_coverage_count(5, 911, 906, 910, 907, 909);
XIsaacCore_csr_write(cpu, system, plugin_pointers, 768LL, s);
etiss_coverage_count(2, 914, 913);
((XIsaacCore*)cpu)->PRIV = (3LL) & 0x7;
etiss_coverage_count(2, 917, 915);
} // block
} // conditional
} // block
}

void XIsaacCore_translate_exc_code(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 cause)
{
etiss_coverage_count(1, 164);
{ // block
etiss_coverage_count(1, 976);
etiss_uint32 code = 0LL;
etiss_coverage_count(2, 923, 922);
etiss_coverage_count(1, 924);
if (cause == -2147483648LL) { // conditional
etiss_coverage_count(2, 927, 925);
etiss_coverage_count(1, 946);
return;
} // conditional
 else if (cause == -5LL) { // conditional
etiss_coverage_count(2, 930, 928);
code = 5LL;
etiss_coverage_count(2, 949, 947);
} // conditional
 else if (cause == -14LL) { // conditional
etiss_coverage_count(2, 933, 931);
code = 13LL;
etiss_coverage_count(2, 952, 950);
} // conditional
 else if (cause == -6LL) { // conditional
etiss_coverage_count(2, 936, 934);
code = 7LL;
etiss_coverage_count(2, 955, 953);
} // conditional
 else if (cause == -15LL) { // conditional
etiss_coverage_count(2, 939, 937);
code = 15LL;
etiss_coverage_count(2, 958, 956);
} // conditional
 else if (cause == -7LL) { // conditional
etiss_coverage_count(2, 942, 940);
code = 1LL;
etiss_coverage_count(2, 961, 959);
} // conditional
 else if (cause == -9LL) { // conditional
etiss_coverage_count(2, 945, 943);
{ // block
etiss_coverage_count(1, 969);
code = XIsaacCore_calc_irq_mcause(cpu, system, plugin_pointers);
etiss_coverage_count(3, 964, 962, 963);
etiss_coverage_count(1, 965);
if (!(code)) { // conditional
etiss_coverage_count(2, 967, 966);
etiss_coverage_count(1, 968);
return;
} // conditional
} // block
} // conditional
else { // conditional
code = 2LL;
etiss_coverage_count(2, 972, 970);
} // conditional
XIsaacCore_raise(cpu, system, plugin_pointers, 0LL, code);
etiss_coverage_count(3, 975, 973, 974);
} // block
}

etiss_uint32 XIsaacCore_calc_irq_mcause(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 165);
{ // block
etiss_coverage_count(1, 1157);
etiss_uint32 pending_interrupts = *((XIsaacCore*)cpu)->CSR[772LL] & *((XIsaacCore*)cpu)->CSR[836LL];
etiss_coverage_count(4, 985, 984, 980, 983);
etiss_coverage_count(1, 986);
if (!(pending_interrupts)) { // conditional
etiss_coverage_count(2, 988, 987);
etiss_coverage_count(1, 990);
return 0LL;
etiss_coverage_count(1, 989);
} // conditional
etiss_uint32 mie = XIsaacCore_get_field(*((XIsaacCore*)cpu)->CSR[768LL], 8LL);
etiss_coverage_count(3, 997, 996, 994);
etiss_uint32 m_enabled = ((XIsaacCore*)cpu)->PRIV < 3LL || (((XIsaacCore*)cpu)->PRIV == 3LL && mie);
etiss_coverage_count(9, 1009, 1008, 1001, 999, 1006, 1004, 1002, 1005, 1007);
etiss_uint32 enabled_interrupts = pending_interrupts & ~(*((XIsaacCore*)cpu)->CSR[771LL]) & -(m_enabled);
etiss_coverage_count(8, 1020, 1019, 1016, 1011, 1015, 1014, 1018, 1017);
etiss_coverage_count(1, 1021);
if (enabled_interrupts == 0LL) { // conditional
etiss_coverage_count(3, 1024, 1022, 1023);
{ // block
etiss_coverage_count(1, 1056);
etiss_uint32 deleg = *((XIsaacCore*)cpu)->CSR[771LL];
etiss_coverage_count(2, 1029, 1028);
etiss_uint32 sie = XIsaacCore_get_field(XIsaacCore_csr_read(cpu, system, plugin_pointers, 256LL), 2LL);
etiss_coverage_count(3, 1035, 1034, 1032);
etiss_uint32 s_enabled = ((XIsaacCore*)cpu)->PRIV < 1LL || (((XIsaacCore*)cpu)->PRIV == 1LL && sie);
etiss_coverage_count(9, 1047, 1046, 1039, 1037, 1044, 1042, 1040, 1043, 1045);
enabled_interrupts = pending_interrupts & deleg & -(s_enabled);
etiss_coverage_count(8, 1055, 1048, 1054, 1051, 1049, 1050, 1053, 1052);
} // block
} // conditional
etiss_coverage_count(1, 1057);
if (enabled_interrupts) { // conditional
etiss_coverage_count(1, 1058);
{ // block
etiss_coverage_count(1, 1154);
etiss_coverage_count(1, 1059);
if (enabled_interrupts >> 12ULL) { // conditional
etiss_coverage_count(2, 1065, 1060);
enabled_interrupts = enabled_interrupts >> 12ULL << 12ULL;
etiss_coverage_count(5, 1108, 1096, 1107, 1102, 1097);
} // conditional
 else if (enabled_interrupts & 2048LL) { // conditional
etiss_coverage_count(2, 1068, 1066);
enabled_interrupts = 2048LL;
etiss_coverage_count(2, 1111, 1109);
} // conditional
 else if (enabled_interrupts & 8LL) { // conditional
etiss_coverage_count(2, 1071, 1069);
enabled_interrupts = 8LL;
etiss_coverage_count(2, 1114, 1112);
} // conditional
 else if (enabled_interrupts & 128LL) { // conditional
etiss_coverage_count(2, 1074, 1072);
enabled_interrupts = 128LL;
etiss_coverage_count(2, 1117, 1115);
} // conditional
 else if (enabled_interrupts & 512LL) { // conditional
etiss_coverage_count(2, 1077, 1075);
enabled_interrupts = 512LL;
etiss_coverage_count(2, 1120, 1118);
} // conditional
 else if (enabled_interrupts & 2LL) { // conditional
etiss_coverage_count(2, 1080, 1078);
enabled_interrupts = 2LL;
etiss_coverage_count(2, 1123, 1121);
} // conditional
 else if (enabled_interrupts & 32LL) { // conditional
etiss_coverage_count(2, 1083, 1081);
enabled_interrupts = 32LL;
etiss_coverage_count(2, 1126, 1124);
} // conditional
 else if (enabled_interrupts & 8192LL) { // conditional
etiss_coverage_count(2, 1086, 1084);
enabled_interrupts = 8192LL;
etiss_coverage_count(2, 1129, 1127);
} // conditional
 else if (enabled_interrupts & 1024LL) { // conditional
etiss_coverage_count(2, 1089, 1087);
enabled_interrupts = 1024LL;
etiss_coverage_count(2, 1132, 1130);
} // conditional
 else if (enabled_interrupts & 4LL) { // conditional
etiss_coverage_count(2, 1092, 1090);
enabled_interrupts = 4LL;
etiss_coverage_count(2, 1135, 1133);
} // conditional
 else if (enabled_interrupts & 64LL) { // conditional
etiss_coverage_count(2, 1095, 1093);
enabled_interrupts = 64LL;
etiss_coverage_count(2, 1138, 1136);
} // conditional
else { // conditional
etiss_coverage_count(1, 1140);
return 0LL;
etiss_coverage_count(1, 1139);
} // conditional
etiss_coverage_count(1, 1153);
return 2147483648ULL | XIsaacCore_ctz(enabled_interrupts);
etiss_coverage_count(3, 1152, 1151, 1150);
} // block
} // conditional
etiss_coverage_count(1, 1156);
return 0LL;
etiss_coverage_count(1, 1155);
} // block
}

void XIsaacCore_check_irq(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 166);
{ // block
etiss_coverage_count(1, 1166);
etiss_uint32 irq_mcause = XIsaacCore_calc_irq_mcause(cpu, system, plugin_pointers);
etiss_coverage_count(2, 1160, 1159);
etiss_coverage_count(1, 1161);
if (irq_mcause) { // conditional
etiss_coverage_count(1, 1162);
XIsaacCore_raise(cpu, system, plugin_pointers, 1ULL, irq_mcause);
etiss_coverage_count(3, 1165, 1163, 1164);
} // conditional
} // block
}
