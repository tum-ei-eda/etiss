/**
 * Generated on Thu, 06 Aug 2026 12:56:16 +0200.
 *
 * This file contains the function implementations for the RV32IMACFDV_zvl128b core architecture.
 */

#include "RV32IMACFDV_zvl128bFuncs.h"
// clang-format off

etiss_uint8 RV32IMACFDV_zvl128b_extension_enabled(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int8 extension)
{
etiss_coverage_count(1, 80);
{ // block
etiss_coverage_count(1, 580);
etiss_coverage_count(1, 579);
return (*((RV32IMACFDV_zvl128b*)cpu)->CSR[769ULL] >> (extension - 65ULL)) & 1ULL;
etiss_coverage_count(9, 578, 575, 570, 573, 571, 572, 574, 576, 577);
} // block
}

etiss_uint8 RV32IMACFDV_zvl128b_get_rm(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint8 rm)
{
etiss_coverage_count(1, 399);
{ // block
etiss_coverage_count(1, 600);
etiss_coverage_count(1, 581);
if (rm == 7ULL) { // conditional
etiss_coverage_count(3, 584, 582, 583);
rm = ((((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL)) & 0x7ULL;
etiss_coverage_count(6, 590, 585, 589, 586, 587, 588);
} // conditional
etiss_coverage_count(1, 591);
if (rm > 4ULL) { // conditional
etiss_coverage_count(3, 594, 592, 593);
RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);
etiss_coverage_count(2, 597, 595);
} // conditional
etiss_coverage_count(1, 599);
return rm;
etiss_coverage_count(1, 598);
} // block
}

etiss_uint32 RV32IMACFDV_zvl128b_sstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 532);
{ // block
etiss_coverage_count(1, 673);
etiss_uint32 mask = 0LL;
etiss_coverage_count(2, 603, 602);
etiss_coverage_count(1, 604);
if (RV32IMACFDV_zvl128b_extension_enabled(cpu, system, plugin_pointers, 83ULL)) { // conditional
etiss_coverage_count(2, 606, 605);
{ // block
etiss_coverage_count(1, 670);
mask = mask | 5767458LL;
etiss_coverage_count(2, 622, 607);
etiss_coverage_count(1, 623);
if (RV32IMACFDV_zvl128b_extension_enabled(cpu, system, plugin_pointers, 86ULL)) { // conditional
etiss_coverage_count(2, 625, 624);
mask = mask | 1536ULL;
etiss_coverage_count(2, 628, 626);
} // conditional
etiss_coverage_count(1, 629);
if (RV32IMACFDV_zvl128b_extension_enabled(cpu, system, plugin_pointers, 70ULL)) { // conditional
etiss_coverage_count(2, 631, 630);
mask = mask | 24576ULL;
etiss_coverage_count(2, 634, 632);
} // conditional
etiss_coverage_count(1, 635);
if (RV32IMACFDV_zvl128b_extension_enabled(cpu, system, plugin_pointers, 88ULL)) { // conditional
etiss_coverage_count(2, 637, 636);
mask = mask | 98304ULL;
etiss_coverage_count(2, 640, 638);
} // conditional
etiss_coverage_count(1, 641);
if ((RV32IMACFDV_zvl128b_get_field(*((RV32IMACFDV_zvl128b*)cpu)->CSR[384ULL], 2147483648ULL))) { // conditional
etiss_coverage_count(3, 651, 647, 653);
mask = mask | 262144ULL;
etiss_coverage_count(2, 669, 667);
} // conditional
} // block
} // conditional
etiss_coverage_count(1, 672);
return mask;
etiss_coverage_count(1, 671);
} // block
}

etiss_uint32 RV32IMACFDV_zvl128b_mstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 533);
{ // block
etiss_coverage_count(1, 688);
etiss_uint32 mask = 6280LL;
etiss_coverage_count(1, 683);
etiss_coverage_count(1, 687);
return mask | RV32IMACFDV_zvl128b_sstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(3, 686, 684, 685);
} // block
}

etiss_uint32 RV32IMACFDV_zvl128b_csr_read(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr)
{
etiss_coverage_count(1, 534);
{ // block
etiss_coverage_count(1, 806);
etiss_coverage_count(1, 689);
if (csr == 1ULL) { // conditional
etiss_coverage_count(2, 692, 690);
etiss_coverage_count(1, 698);
return *((RV32IMACFDV_zvl128b*)cpu)->CSR[3ULL] & 31ULL;
etiss_coverage_count(3, 697, 695, 696);
} // conditional
etiss_coverage_count(1, 699);
if (csr == 2ULL) { // conditional
etiss_coverage_count(2, 702, 700);
etiss_coverage_count(1, 711);
return (*((RV32IMACFDV_zvl128b*)cpu)->CSR[3ULL] >> 5ULL) & 7ULL;
etiss_coverage_count(6, 710, 707, 705, 706, 708, 709);
} // conditional
etiss_coverage_count(1, 712);
if (csr == 3072ULL) { // conditional
etiss_coverage_count(2, 715, 713);
etiss_coverage_count(1, 717);
return etiss_get_cycles(cpu, system, plugin_pointers);
etiss_coverage_count(1, 716);
} // conditional
etiss_coverage_count(1, 718);
if (csr == 3200ULL) { // conditional
etiss_coverage_count(2, 721, 719);
etiss_coverage_count(1, 725);
return etiss_get_cycles(cpu, system, plugin_pointers) >> 32ULL;
etiss_coverage_count(3, 724, 722, 723);
} // conditional
etiss_coverage_count(1, 726);
if (csr == 3073ULL) { // conditional
etiss_coverage_count(2, 729, 727);
etiss_coverage_count(1, 731);
return etiss_get_time();
etiss_coverage_count(1, 730);
} // conditional
etiss_coverage_count(1, 732);
if (csr == 3201ULL) { // conditional
etiss_coverage_count(2, 735, 733);
etiss_coverage_count(1, 739);
return etiss_get_time() >> 32ULL;
etiss_coverage_count(3, 738, 736, 737);
} // conditional
etiss_coverage_count(1, 740);
if (csr == 3074ULL) { // conditional
etiss_coverage_count(2, 743, 741);
etiss_coverage_count(1, 745);
return etiss_get_instret(cpu, system, plugin_pointers);
etiss_coverage_count(1, 744);
} // conditional
etiss_coverage_count(1, 746);
if (csr == 3202ULL) { // conditional
etiss_coverage_count(2, 749, 747);
etiss_coverage_count(1, 753);
return etiss_get_instret(cpu, system, plugin_pointers) >> 32ULL;
etiss_coverage_count(3, 752, 750, 751);
} // conditional
etiss_coverage_count(1, 754);
if (csr == 768ULL || csr == 256ULL) { // conditional
etiss_coverage_count(5, 761, 757, 755, 760, 758);
etiss_coverage_count(1, 781);
return *((RV32IMACFDV_zvl128b*)cpu)->CSR[768ULL] | 8589934592ULL | 34359738368ULL;
etiss_coverage_count(3, 780, 772, 764);
} // conditional
etiss_coverage_count(1, 782);
if (csr == 769ULL) { // conditional
etiss_coverage_count(2, 785, 783);
etiss_coverage_count(1, 801);
return (((1ULL) << 30) | (((*((RV32IMACFDV_zvl128b*)cpu)->CSR[769ULL]) & 0x3fffffffULL)));
etiss_coverage_count(4, 800, 799, 794, 798);
} // conditional
etiss_coverage_count(1, 805);
return *((RV32IMACFDV_zvl128b*)cpu)->CSR[csr];
etiss_coverage_count(2, 804, 803);
} // block
}

void RV32IMACFDV_zvl128b_csr_write(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr, etiss_uint32 val)
{
etiss_coverage_count(1, 535);
{ // block
etiss_coverage_count(1, 888);
etiss_coverage_count(1, 807);
if (csr == 1ULL) { // conditional
etiss_coverage_count(2, 810, 808);
*((RV32IMACFDV_zvl128b*)cpu)->CSR[3ULL] = (*((RV32IMACFDV_zvl128b*)cpu)->CSR[3ULL] & 224ULL) | (val & 31ULL);
etiss_coverage_count(10, 843, 828, 842, 836, 831, 837, 840, 838, 839, 841);
} // conditional
 else if (csr == 2ULL) { // conditional
etiss_coverage_count(2, 813, 811);
*((RV32IMACFDV_zvl128b*)cpu)->CSR[3ULL] = ((val & 7ULL) << 5ULL) | (*((RV32IMACFDV_zvl128b*)cpu)->CSR[3ULL] & 31ULL);
etiss_coverage_count(14, 861, 846, 860, 852, 849, 847, 848, 850, 851, 853, 858, 856, 857, 859);
} // conditional
 else if (csr == 3ULL) { // conditional
etiss_coverage_count(2, 816, 814);
*((RV32IMACFDV_zvl128b*)cpu)->CSR[3ULL] = val & 255ULL;
etiss_coverage_count(5, 868, 864, 867, 865, 866);
} // conditional
 else if (csr == 768ULL) { // conditional
etiss_coverage_count(2, 819, 817);
*((RV32IMACFDV_zvl128b*)cpu)->CSR[768ULL] = val & RV32IMACFDV_zvl128b_mstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(5, 875, 871, 874, 872, 873);
} // conditional
 else if (csr == 256ULL) { // conditional
etiss_coverage_count(2, 822, 820);
*((RV32IMACFDV_zvl128b*)cpu)->CSR[768ULL] = val & RV32IMACFDV_zvl128b_sstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(5, 882, 878, 881, 879, 880);
} // conditional
 else if (csr != 769ULL) { // conditional
etiss_coverage_count(2, 825, 823);
*((RV32IMACFDV_zvl128b*)cpu)->CSR[csr] = val;
etiss_coverage_count(4, 887, 885, 884, 886);
} // conditional
} // block
}

etiss_uint64 RV32IMACFDV_zvl128b_get_field(etiss_uint64 reg, etiss_uint64 mask)
{
etiss_coverage_count(1, 542);
{ // block
etiss_coverage_count(1, 908);
etiss_coverage_count(1, 889);
if (!(mask)) { // conditional
etiss_coverage_count(2, 891, 890);
etiss_coverage_count(1, 893);
return 0LL;
etiss_coverage_count(1, 892);
} // conditional
etiss_coverage_count(1, 907);
return (reg & mask) / (mask & ~((mask << 1ULL)));
etiss_coverage_count(13, 906, 896, 894, 895, 897, 904, 898, 903, 901, 899, 900, 902, 905);
} // block
}

etiss_uint64 RV32IMACFDV_zvl128b_set_field(etiss_uint64 reg, etiss_uint64 mask, etiss_uint64 val)
{
etiss_coverage_count(1, 543);
{ // block
etiss_coverage_count(1, 931);
etiss_coverage_count(1, 930);
return ((reg & ~(mask)) | ((val * (mask & ~((mask << 1ULL)))) & mask));
etiss_coverage_count(21, 928, 912, 909, 911, 910, 913, 926, 923, 914, 921, 915, 920, 918, 916, 917, 919, 922, 924, 925, 927, 929);
} // block
}

etiss_uint8 RV32IMACFDV_zvl128b_ctz(etiss_uint64 val)
{
etiss_coverage_count(1, 544);
{ // block
etiss_coverage_count(1, 1023);
etiss_coverage_count(1, 932);
if (!(val)) { // conditional
etiss_coverage_count(2, 934, 933);
etiss_coverage_count(1, 936);
return 0LL;
etiss_coverage_count(1, 935);
} // conditional
etiss_uint8 res = 0LL;
etiss_coverage_count(2, 939, 938);
etiss_coverage_count(1, 940);
if ((val << 32ULL) == 0LL) { // conditional
etiss_coverage_count(6, 946, 943, 941, 942, 944, 945);
{ // block
etiss_coverage_count(1, 953);
res = res + 32ULL;
etiss_coverage_count(3, 949, 947, 948);
val = val >> 32ULL;
etiss_coverage_count(3, 952, 950, 951);
} // block
} // conditional
etiss_coverage_count(1, 954);
if ((val << 48ULL) == 0LL) { // conditional
etiss_coverage_count(6, 960, 957, 955, 956, 958, 959);
{ // block
etiss_coverage_count(1, 967);
res = res + 16ULL;
etiss_coverage_count(3, 963, 961, 962);
val = val >> 16ULL;
etiss_coverage_count(3, 966, 964, 965);
} // block
} // conditional
etiss_coverage_count(1, 968);
if ((val << 56ULL) == 0LL) { // conditional
etiss_coverage_count(6, 974, 971, 969, 970, 972, 973);
{ // block
etiss_coverage_count(1, 981);
res = res + 8ULL;
etiss_coverage_count(3, 977, 975, 976);
val = val >> 8ULL;
etiss_coverage_count(3, 980, 978, 979);
} // block
} // conditional
etiss_coverage_count(1, 982);
if ((val << 60ULL) == 0LL) { // conditional
etiss_coverage_count(6, 988, 985, 983, 984, 986, 987);
{ // block
etiss_coverage_count(1, 995);
res = res + 4ULL;
etiss_coverage_count(3, 991, 989, 990);
val = val >> 4ULL;
etiss_coverage_count(3, 994, 992, 993);
} // block
} // conditional
etiss_coverage_count(1, 996);
if ((val << 62ULL) == 0LL) { // conditional
etiss_coverage_count(6, 1002, 999, 997, 998, 1000, 1001);
{ // block
etiss_coverage_count(1, 1009);
res = res + 2ULL;
etiss_coverage_count(3, 1005, 1003, 1004);
val = val >> 2ULL;
etiss_coverage_count(3, 1008, 1006, 1007);
} // block
} // conditional
etiss_coverage_count(1, 1010);
if ((val << 63ULL) == 0LL) { // conditional
etiss_coverage_count(6, 1016, 1013, 1011, 1012, 1014, 1015);
{ // block
etiss_coverage_count(1, 1020);
res = res + 1ULL;
etiss_coverage_count(3, 1019, 1017, 1018);
} // block
} // conditional
etiss_coverage_count(1, 1022);
return res;
etiss_coverage_count(1, 1021);
} // block
}

void RV32IMACFDV_zvl128b_raise(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 irq, etiss_uint32 mcause)
{
cpu->return_pending = 1;
cpu->exception = 0;
etiss_coverage_count(1, 545);
{ // block
etiss_coverage_count(1, 1252);
etiss_uint32 epc = cpu->instructionPointer;
etiss_coverage_count(2, 1026, 1025);
etiss_int32 deleg = 0LL;
etiss_coverage_count(1, 1028);
etiss_int32 vector = 0LL;
etiss_coverage_count(1, 1029);
etiss_int32 bit = mcause;
etiss_coverage_count(2, 1031, 1030);
etiss_int32 irq2 = (mcause & 2147483648ULL) != 0LL;
etiss_coverage_count(6, 1047, 1046, 1043, 1033, 1044, 1045);
etiss_coverage_count(1, 1048);
if (irq2) { // conditional
etiss_coverage_count(1, 1049);
{ // block
etiss_coverage_count(1, 1074);
deleg = ((((RV32IMACFDV_zvl128b*)cpu)->PRIV <= 1ULL)) ? (*((RV32IMACFDV_zvl128b*)cpu)->CSR[771ULL]) : (0LL);
etiss_coverage_count(8, 1060, 1050, 1059, 1053, 1051, 1054, 1057, 1058);
bit = bit & 2147483647ULL;
etiss_coverage_count(2, 1073, 1061);
} // block
} // conditional
else { // conditional
{ // block
etiss_coverage_count(1, 1086);
deleg = ((((RV32IMACFDV_zvl128b*)cpu)->PRIV <= 1ULL)) ? (*((RV32IMACFDV_zvl128b*)cpu)->CSR[770ULL]) : (0LL);
etiss_coverage_count(8, 1085, 1075, 1084, 1078, 1076, 1079, 1082, 1083);
} // block
} // conditional
etiss_coverage_count(1, 1087);
if (((RV32IMACFDV_zvl128b*)cpu)->PRIV <= 1ULL && (deleg >> bit) & 1ULL) { // conditional
etiss_coverage_count(9, 1097, 1090, 1088, 1096, 1093, 1091, 1092, 1094, 1095);
{ // block
etiss_coverage_count(1, 1174);
vector = ((*((RV32IMACFDV_zvl128b*)cpu)->CSR[261ULL] & 1ULL) && irq2) ? (bit * 4ULL) : (0LL);
etiss_coverage_count(13, 1112, 1098, 1111, 1106, 1103, 1101, 1102, 1104, 1105, 1109, 1107, 1108, 1110);
cpu->nextPc = (*((RV32IMACFDV_zvl128b*)cpu)->CSR[261ULL] & -2LL) + vector;
etiss_coverage_count(7, 1125, 1113, 1124, 1121, 1116, 1122, 1123);
*((RV32IMACFDV_zvl128b*)cpu)->CSR[321ULL] = epc;
etiss_coverage_count(3, 1130, 1128, 1129);
*((RV32IMACFDV_zvl128b*)cpu)->CSR[322ULL] = mcause;
etiss_coverage_count(3, 1135, 1133, 1134);
etiss_uint32 s = RV32IMACFDV_zvl128b_csr_read(cpu, system, plugin_pointers, 256ULL);
etiss_coverage_count(2, 1139, 1138);
s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 32ULL, RV32IMACFDV_zvl128b_get_field(s, 2ULL)));
etiss_coverage_count(7, 1149, 1140, 1148, 1146, 1141, 1145, 1143);
s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 256ULL, ((RV32IMACFDV_zvl128b*)cpu)->PRIV));
etiss_coverage_count(6, 1157, 1150, 1156, 1154, 1151, 1153);
s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 2ULL, 0LL));
etiss_coverage_count(6, 1165, 1158, 1164, 1162, 1159, 1161);
RV32IMACFDV_zvl128b_csr_write(cpu, system, plugin_pointers, 256ULL, s);
etiss_coverage_count(2, 1168, 1167);
((RV32IMACFDV_zvl128b*)cpu)->PRIV = (1ULL) & 0x7ULL;
etiss_coverage_count(2, 1173, 1169);
} // block
} // conditional
else { // conditional
{ // block
etiss_coverage_count(1, 1251);
vector = ((*((RV32IMACFDV_zvl128b*)cpu)->CSR[773ULL] & 1ULL) && irq2) ? (bit * 4ULL) : (0LL);
etiss_coverage_count(13, 1189, 1175, 1188, 1183, 1180, 1178, 1179, 1181, 1182, 1186, 1184, 1185, 1187);
cpu->nextPc = (*((RV32IMACFDV_zvl128b*)cpu)->CSR[773ULL] & -2LL) + vector;
etiss_coverage_count(7, 1202, 1190, 1201, 1198, 1193, 1199, 1200);
*((RV32IMACFDV_zvl128b*)cpu)->CSR[833ULL] = epc;
etiss_coverage_count(3, 1207, 1205, 1206);
*((RV32IMACFDV_zvl128b*)cpu)->CSR[834ULL] = mcause;
etiss_coverage_count(3, 1212, 1210, 1211);
etiss_uint32 s = RV32IMACFDV_zvl128b_csr_read(cpu, system, plugin_pointers, 768ULL);
etiss_coverage_count(2, 1216, 1215);
s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 128ULL, RV32IMACFDV_zvl128b_get_field(s, 8ULL)));
etiss_coverage_count(7, 1226, 1217, 1225, 1223, 1218, 1222, 1220);
s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 6144ULL, ((RV32IMACFDV_zvl128b*)cpu)->PRIV));
etiss_coverage_count(6, 1234, 1227, 1233, 1231, 1228, 1230);
s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 8ULL, 0LL));
etiss_coverage_count(6, 1242, 1235, 1241, 1239, 1236, 1238);
RV32IMACFDV_zvl128b_csr_write(cpu, system, plugin_pointers, 768ULL, s);
etiss_coverage_count(2, 1245, 1244);
((RV32IMACFDV_zvl128b*)cpu)->PRIV = (3ULL) & 0x7ULL;
etiss_coverage_count(2, 1250, 1246);
} // block
} // conditional
} // block
}

void RV32IMACFDV_zvl128b_translate_exc_code(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 cause)
{
etiss_coverage_count(1, 546);
{ // block
etiss_coverage_count(1, 1309);
etiss_uint32 code = 0LL;
etiss_coverage_count(2, 1256, 1255);
etiss_coverage_count(1, 1257);
if (cause == -2147483648LL) { // conditional
etiss_coverage_count(2, 1260, 1258);
etiss_coverage_count(1, 1279);
return;
} // conditional
 else if (cause == -5LL) { // conditional
etiss_coverage_count(2, 1263, 1261);
code = 5ULL;
etiss_coverage_count(2, 1282, 1280);
} // conditional
 else if (cause == -14LL) { // conditional
etiss_coverage_count(2, 1266, 1264);
code = 13ULL;
etiss_coverage_count(2, 1285, 1283);
} // conditional
 else if (cause == -6LL) { // conditional
etiss_coverage_count(2, 1269, 1267);
code = 7ULL;
etiss_coverage_count(2, 1288, 1286);
} // conditional
 else if (cause == -15LL) { // conditional
etiss_coverage_count(2, 1272, 1270);
code = 15ULL;
etiss_coverage_count(2, 1291, 1289);
} // conditional
 else if (cause == -7LL) { // conditional
etiss_coverage_count(2, 1275, 1273);
code = 1ULL;
etiss_coverage_count(2, 1294, 1292);
} // conditional
 else if (cause == -9LL) { // conditional
etiss_coverage_count(2, 1278, 1276);
{ // block
etiss_coverage_count(1, 1302);
code = RV32IMACFDV_zvl128b_calc_irq_mcause(cpu, system, plugin_pointers);
etiss_coverage_count(3, 1297, 1295, 1296);
etiss_coverage_count(1, 1298);
if (!(code)) { // conditional
etiss_coverage_count(2, 1300, 1299);
etiss_coverage_count(1, 1301);
return;
} // conditional
} // block
} // conditional
else { // conditional
code = 2ULL;
etiss_coverage_count(2, 1305, 1303);
} // conditional
RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, code);
etiss_coverage_count(3, 1308, 1306, 1307);
} // block
}

etiss_uint32 RV32IMACFDV_zvl128b_calc_irq_mcause(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 547);
{ // block
etiss_coverage_count(1, 1494);
etiss_uint32 pending_interrupts = *((RV32IMACFDV_zvl128b*)cpu)->CSR[772ULL] & *((RV32IMACFDV_zvl128b*)cpu)->CSR[836ULL];
etiss_coverage_count(4, 1318, 1317, 1313, 1316);
etiss_coverage_count(1, 1319);
if (!(pending_interrupts)) { // conditional
etiss_coverage_count(2, 1321, 1320);
etiss_coverage_count(1, 1323);
return 0LL;
etiss_coverage_count(1, 1322);
} // conditional
etiss_uint32 mie = (etiss_uint32)(RV32IMACFDV_zvl128b_get_field(*((RV32IMACFDV_zvl128b*)cpu)->CSR[768ULL], 8ULL));
etiss_coverage_count(4, 1332, 1331, 1329, 1327);
etiss_uint32 m_enabled = ((RV32IMACFDV_zvl128b*)cpu)->PRIV < 3ULL || (((RV32IMACFDV_zvl128b*)cpu)->PRIV == 3ULL && mie);
etiss_coverage_count(9, 1344, 1343, 1336, 1334, 1341, 1339, 1337, 1340, 1342);
etiss_uint32 enabled_interrupts = pending_interrupts & ~(*((RV32IMACFDV_zvl128b*)cpu)->CSR[771ULL]) & -(m_enabled);
etiss_coverage_count(8, 1355, 1354, 1351, 1346, 1350, 1349, 1353, 1352);
etiss_coverage_count(1, 1356);
if (enabled_interrupts == 0LL) { // conditional
etiss_coverage_count(3, 1359, 1357, 1358);
{ // block
etiss_coverage_count(1, 1393);
etiss_uint32 deleg = *((RV32IMACFDV_zvl128b*)cpu)->CSR[771ULL];
etiss_coverage_count(2, 1364, 1363);
etiss_uint32 sie = (etiss_uint32)(RV32IMACFDV_zvl128b_get_field(RV32IMACFDV_zvl128b_csr_read(cpu, system, plugin_pointers, 256ULL), 2ULL));
etiss_coverage_count(4, 1372, 1371, 1369, 1367);
etiss_uint32 s_enabled = ((RV32IMACFDV_zvl128b*)cpu)->PRIV < 1ULL || (((RV32IMACFDV_zvl128b*)cpu)->PRIV == 1ULL && sie);
etiss_coverage_count(9, 1384, 1383, 1376, 1374, 1381, 1379, 1377, 1380, 1382);
enabled_interrupts = pending_interrupts & deleg & -(s_enabled);
etiss_coverage_count(8, 1392, 1385, 1391, 1388, 1386, 1387, 1390, 1389);
} // block
} // conditional
etiss_coverage_count(1, 1394);
if (enabled_interrupts) { // conditional
etiss_coverage_count(1, 1395);
{ // block
etiss_coverage_count(1, 1491);
etiss_coverage_count(1, 1396);
if (enabled_interrupts >> 12ULL) { // conditional
etiss_coverage_count(2, 1402, 1397);
enabled_interrupts = enabled_interrupts >> 12ULL << 12ULL;
etiss_coverage_count(5, 1445, 1433, 1444, 1439, 1434);
} // conditional
 else if (enabled_interrupts & 2048ULL) { // conditional
etiss_coverage_count(2, 1405, 1403);
enabled_interrupts = 2048ULL;
etiss_coverage_count(2, 1448, 1446);
} // conditional
 else if (enabled_interrupts & 8ULL) { // conditional
etiss_coverage_count(2, 1408, 1406);
enabled_interrupts = 8ULL;
etiss_coverage_count(2, 1451, 1449);
} // conditional
 else if (enabled_interrupts & 128ULL) { // conditional
etiss_coverage_count(2, 1411, 1409);
enabled_interrupts = 128ULL;
etiss_coverage_count(2, 1454, 1452);
} // conditional
 else if (enabled_interrupts & 512ULL) { // conditional
etiss_coverage_count(2, 1414, 1412);
enabled_interrupts = 512ULL;
etiss_coverage_count(2, 1457, 1455);
} // conditional
 else if (enabled_interrupts & 2ULL) { // conditional
etiss_coverage_count(2, 1417, 1415);
enabled_interrupts = 2ULL;
etiss_coverage_count(2, 1460, 1458);
} // conditional
 else if (enabled_interrupts & 32ULL) { // conditional
etiss_coverage_count(2, 1420, 1418);
enabled_interrupts = 32ULL;
etiss_coverage_count(2, 1463, 1461);
} // conditional
 else if (enabled_interrupts & 8192ULL) { // conditional
etiss_coverage_count(2, 1423, 1421);
enabled_interrupts = 8192ULL;
etiss_coverage_count(2, 1466, 1464);
} // conditional
 else if (enabled_interrupts & 1024ULL) { // conditional
etiss_coverage_count(2, 1426, 1424);
enabled_interrupts = 1024ULL;
etiss_coverage_count(2, 1469, 1467);
} // conditional
 else if (enabled_interrupts & 4ULL) { // conditional
etiss_coverage_count(2, 1429, 1427);
enabled_interrupts = 4ULL;
etiss_coverage_count(2, 1472, 1470);
} // conditional
 else if (enabled_interrupts & 64ULL) { // conditional
etiss_coverage_count(2, 1432, 1430);
enabled_interrupts = 64ULL;
etiss_coverage_count(2, 1475, 1473);
} // conditional
else { // conditional
etiss_coverage_count(1, 1477);
return 0LL;
etiss_coverage_count(1, 1476);
} // conditional
etiss_coverage_count(1, 1490);
return 2147483648ULL | RV32IMACFDV_zvl128b_ctz(enabled_interrupts);
etiss_coverage_count(3, 1489, 1488, 1487);
} // block
} // conditional
etiss_coverage_count(1, 1493);
return 0LL;
etiss_coverage_count(1, 1492);
} // block
}

void RV32IMACFDV_zvl128b_check_irq(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 548);
{ // block
etiss_coverage_count(1, 1503);
etiss_uint32 irq_mcause = RV32IMACFDV_zvl128b_calc_irq_mcause(cpu, system, plugin_pointers);
etiss_coverage_count(2, 1497, 1496);
etiss_coverage_count(1, 1498);
if (irq_mcause) { // conditional
etiss_coverage_count(1, 1499);
RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 1ULL, irq_mcause);
etiss_coverage_count(3, 1502, 1500, 1501);
} // conditional
} // block
}
// clang-format on
