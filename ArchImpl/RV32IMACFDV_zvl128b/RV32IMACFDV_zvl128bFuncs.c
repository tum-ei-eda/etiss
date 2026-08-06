/**
 * Generated on Thu, 06 Aug 2026 13:26:11 +0200.
 *
 * This file contains the function implementations for the RV32IMACFDV_zvl128b core architecture.
 */

#include "RV32IMACFDV_zvl128bFuncs.h"
// clang-format off

etiss_uint8 RV32IMACFDV_zvl128b_extension_enabled(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int8 extension)
{
etiss_coverage_count(1, 80);
{ // block
etiss_coverage_count(1, 670);
etiss_coverage_count(1, 669);
return (*((RV32IMACFDV_zvl128b*)cpu)->CSR[769ULL] >> (extension - 65ULL)) & 1ULL;
etiss_coverage_count(9, 668, 665, 660, 663, 661, 662, 664, 666, 667);
} // block
}

etiss_uint8 RV32IMACFDV_zvl128b_get_rm(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint8 rm)
{
etiss_coverage_count(1, 87);
{ // block
etiss_coverage_count(1, 690);
etiss_coverage_count(1, 671);
if (rm == 7ULL) { // conditional
etiss_coverage_count(3, 674, 672, 673);
rm = ((((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL)) & 0x7ULL;
etiss_coverage_count(6, 680, 675, 679, 676, 677, 678);
} // conditional
etiss_coverage_count(1, 681);
if (rm > 4ULL) { // conditional
etiss_coverage_count(3, 684, 682, 683);
RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);
etiss_coverage_count(2, 687, 685);
} // conditional
etiss_coverage_count(1, 689);
return rm;
etiss_coverage_count(1, 688);
} // block
}

etiss_uint32 RV32IMACFDV_zvl128b_sstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 149);
{ // block
etiss_coverage_count(1, 763);
etiss_uint32 mask = 0LL;
etiss_coverage_count(2, 693, 692);
etiss_coverage_count(1, 694);
if (RV32IMACFDV_zvl128b_extension_enabled(cpu, system, plugin_pointers, 83ULL)) { // conditional
etiss_coverage_count(2, 696, 695);
{ // block
etiss_coverage_count(1, 760);
mask = mask | 5767458LL;
etiss_coverage_count(2, 712, 697);
etiss_coverage_count(1, 713);
if (RV32IMACFDV_zvl128b_extension_enabled(cpu, system, plugin_pointers, 86ULL)) { // conditional
etiss_coverage_count(2, 715, 714);
mask = mask | 1536ULL;
etiss_coverage_count(2, 718, 716);
} // conditional
etiss_coverage_count(1, 719);
if (RV32IMACFDV_zvl128b_extension_enabled(cpu, system, plugin_pointers, 70ULL)) { // conditional
etiss_coverage_count(2, 721, 720);
mask = mask | 24576ULL;
etiss_coverage_count(2, 724, 722);
} // conditional
etiss_coverage_count(1, 725);
if (RV32IMACFDV_zvl128b_extension_enabled(cpu, system, plugin_pointers, 88ULL)) { // conditional
etiss_coverage_count(2, 727, 726);
mask = mask | 98304ULL;
etiss_coverage_count(2, 730, 728);
} // conditional
etiss_coverage_count(1, 731);
if ((RV32IMACFDV_zvl128b_get_field(*((RV32IMACFDV_zvl128b*)cpu)->CSR[384ULL], 2147483648ULL))) { // conditional
etiss_coverage_count(3, 741, 737, 743);
mask = mask | 262144ULL;
etiss_coverage_count(2, 759, 757);
} // conditional
} // block
} // conditional
etiss_coverage_count(1, 762);
return mask;
etiss_coverage_count(1, 761);
} // block
}

etiss_uint32 RV32IMACFDV_zvl128b_mstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 150);
{ // block
etiss_coverage_count(1, 778);
etiss_uint32 mask = 6280LL;
etiss_coverage_count(1, 773);
etiss_coverage_count(1, 777);
return mask | RV32IMACFDV_zvl128b_sstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(3, 776, 774, 775);
} // block
}

etiss_uint32 RV32IMACFDV_zvl128b_csr_read(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr)
{
etiss_coverage_count(1, 151);
{ // block
etiss_coverage_count(1, 896);
etiss_coverage_count(1, 779);
if (csr == 1ULL) { // conditional
etiss_coverage_count(2, 782, 780);
etiss_coverage_count(1, 788);
return *((RV32IMACFDV_zvl128b*)cpu)->CSR[3ULL] & 31ULL;
etiss_coverage_count(3, 787, 785, 786);
} // conditional
etiss_coverage_count(1, 789);
if (csr == 2ULL) { // conditional
etiss_coverage_count(2, 792, 790);
etiss_coverage_count(1, 801);
return (*((RV32IMACFDV_zvl128b*)cpu)->CSR[3ULL] >> 5ULL) & 7ULL;
etiss_coverage_count(6, 800, 797, 795, 796, 798, 799);
} // conditional
etiss_coverage_count(1, 802);
if (csr == 3072ULL) { // conditional
etiss_coverage_count(2, 805, 803);
etiss_coverage_count(1, 807);
return etiss_get_cycles(cpu, system, plugin_pointers);
etiss_coverage_count(1, 806);
} // conditional
etiss_coverage_count(1, 808);
if (csr == 3200ULL) { // conditional
etiss_coverage_count(2, 811, 809);
etiss_coverage_count(1, 815);
return etiss_get_cycles(cpu, system, plugin_pointers) >> 32ULL;
etiss_coverage_count(3, 814, 812, 813);
} // conditional
etiss_coverage_count(1, 816);
if (csr == 3073ULL) { // conditional
etiss_coverage_count(2, 819, 817);
etiss_coverage_count(1, 821);
return etiss_get_time();
etiss_coverage_count(1, 820);
} // conditional
etiss_coverage_count(1, 822);
if (csr == 3201ULL) { // conditional
etiss_coverage_count(2, 825, 823);
etiss_coverage_count(1, 829);
return etiss_get_time() >> 32ULL;
etiss_coverage_count(3, 828, 826, 827);
} // conditional
etiss_coverage_count(1, 830);
if (csr == 3074ULL) { // conditional
etiss_coverage_count(2, 833, 831);
etiss_coverage_count(1, 835);
return etiss_get_instret(cpu, system, plugin_pointers);
etiss_coverage_count(1, 834);
} // conditional
etiss_coverage_count(1, 836);
if (csr == 3202ULL) { // conditional
etiss_coverage_count(2, 839, 837);
etiss_coverage_count(1, 843);
return etiss_get_instret(cpu, system, plugin_pointers) >> 32ULL;
etiss_coverage_count(3, 842, 840, 841);
} // conditional
etiss_coverage_count(1, 844);
if (csr == 768ULL || csr == 256ULL) { // conditional
etiss_coverage_count(5, 851, 847, 845, 850, 848);
etiss_coverage_count(1, 871);
return *((RV32IMACFDV_zvl128b*)cpu)->CSR[768ULL] | 8589934592ULL | 34359738368ULL;
etiss_coverage_count(3, 870, 862, 854);
} // conditional
etiss_coverage_count(1, 872);
if (csr == 769ULL) { // conditional
etiss_coverage_count(2, 875, 873);
etiss_coverage_count(1, 891);
return (((1ULL) << 30) | (((*((RV32IMACFDV_zvl128b*)cpu)->CSR[769ULL]) & 0x3fffffffULL)));
etiss_coverage_count(4, 890, 889, 884, 888);
} // conditional
etiss_coverage_count(1, 895);
return *((RV32IMACFDV_zvl128b*)cpu)->CSR[csr];
etiss_coverage_count(2, 894, 893);
} // block
}

void RV32IMACFDV_zvl128b_csr_write(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr, etiss_uint32 val)
{
etiss_coverage_count(1, 152);
{ // block
etiss_coverage_count(1, 978);
etiss_coverage_count(1, 897);
if (csr == 1ULL) { // conditional
etiss_coverage_count(2, 900, 898);
*((RV32IMACFDV_zvl128b*)cpu)->CSR[3ULL] = (*((RV32IMACFDV_zvl128b*)cpu)->CSR[3ULL] & 224ULL) | (val & 31ULL);
etiss_coverage_count(10, 933, 918, 932, 926, 921, 927, 930, 928, 929, 931);
} // conditional
 else if (csr == 2ULL) { // conditional
etiss_coverage_count(2, 903, 901);
*((RV32IMACFDV_zvl128b*)cpu)->CSR[3ULL] = ((val & 7ULL) << 5ULL) | (*((RV32IMACFDV_zvl128b*)cpu)->CSR[3ULL] & 31ULL);
etiss_coverage_count(14, 951, 936, 950, 942, 939, 937, 938, 940, 941, 943, 948, 946, 947, 949);
} // conditional
 else if (csr == 3ULL) { // conditional
etiss_coverage_count(2, 906, 904);
*((RV32IMACFDV_zvl128b*)cpu)->CSR[3ULL] = val & 255ULL;
etiss_coverage_count(5, 958, 954, 957, 955, 956);
} // conditional
 else if (csr == 768ULL) { // conditional
etiss_coverage_count(2, 909, 907);
*((RV32IMACFDV_zvl128b*)cpu)->CSR[768ULL] = val & RV32IMACFDV_zvl128b_mstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(5, 965, 961, 964, 962, 963);
} // conditional
 else if (csr == 256ULL) { // conditional
etiss_coverage_count(2, 912, 910);
*((RV32IMACFDV_zvl128b*)cpu)->CSR[768ULL] = val & RV32IMACFDV_zvl128b_sstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(5, 972, 968, 971, 969, 970);
} // conditional
 else if (csr != 769ULL) { // conditional
etiss_coverage_count(2, 915, 913);
*((RV32IMACFDV_zvl128b*)cpu)->CSR[csr] = val;
etiss_coverage_count(4, 977, 975, 974, 976);
} // conditional
} // block
}

etiss_uint64 RV32IMACFDV_zvl128b_get_field(etiss_uint64 reg, etiss_uint64 mask)
{
etiss_coverage_count(1, 159);
{ // block
etiss_coverage_count(1, 998);
etiss_coverage_count(1, 979);
if (!(mask)) { // conditional
etiss_coverage_count(2, 981, 980);
etiss_coverage_count(1, 983);
return 0LL;
etiss_coverage_count(1, 982);
} // conditional
etiss_coverage_count(1, 997);
return (reg & mask) / (mask & ~((mask << 1ULL)));
etiss_coverage_count(13, 996, 986, 984, 985, 987, 994, 988, 993, 991, 989, 990, 992, 995);
} // block
}

etiss_uint64 RV32IMACFDV_zvl128b_set_field(etiss_uint64 reg, etiss_uint64 mask, etiss_uint64 val)
{
etiss_coverage_count(1, 160);
{ // block
etiss_coverage_count(1, 1021);
etiss_coverage_count(1, 1020);
return ((reg & ~(mask)) | ((val * (mask & ~((mask << 1ULL)))) & mask));
etiss_coverage_count(21, 1018, 1002, 999, 1001, 1000, 1003, 1016, 1013, 1004, 1011, 1005, 1010, 1008, 1006, 1007, 1009, 1012, 1014, 1015, 1017, 1019);
} // block
}

etiss_uint8 RV32IMACFDV_zvl128b_ctz(etiss_uint64 val)
{
etiss_coverage_count(1, 161);
{ // block
etiss_coverage_count(1, 1113);
etiss_coverage_count(1, 1022);
if (!(val)) { // conditional
etiss_coverage_count(2, 1024, 1023);
etiss_coverage_count(1, 1026);
return 0LL;
etiss_coverage_count(1, 1025);
} // conditional
etiss_uint8 res = 0LL;
etiss_coverage_count(2, 1029, 1028);
etiss_coverage_count(1, 1030);
if ((val << 32ULL) == 0LL) { // conditional
etiss_coverage_count(6, 1036, 1033, 1031, 1032, 1034, 1035);
{ // block
etiss_coverage_count(1, 1043);
res = res + 32ULL;
etiss_coverage_count(3, 1039, 1037, 1038);
val = val >> 32ULL;
etiss_coverage_count(3, 1042, 1040, 1041);
} // block
} // conditional
etiss_coverage_count(1, 1044);
if ((val << 48ULL) == 0LL) { // conditional
etiss_coverage_count(6, 1050, 1047, 1045, 1046, 1048, 1049);
{ // block
etiss_coverage_count(1, 1057);
res = res + 16ULL;
etiss_coverage_count(3, 1053, 1051, 1052);
val = val >> 16ULL;
etiss_coverage_count(3, 1056, 1054, 1055);
} // block
} // conditional
etiss_coverage_count(1, 1058);
if ((val << 56ULL) == 0LL) { // conditional
etiss_coverage_count(6, 1064, 1061, 1059, 1060, 1062, 1063);
{ // block
etiss_coverage_count(1, 1071);
res = res + 8ULL;
etiss_coverage_count(3, 1067, 1065, 1066);
val = val >> 8ULL;
etiss_coverage_count(3, 1070, 1068, 1069);
} // block
} // conditional
etiss_coverage_count(1, 1072);
if ((val << 60ULL) == 0LL) { // conditional
etiss_coverage_count(6, 1078, 1075, 1073, 1074, 1076, 1077);
{ // block
etiss_coverage_count(1, 1085);
res = res + 4ULL;
etiss_coverage_count(3, 1081, 1079, 1080);
val = val >> 4ULL;
etiss_coverage_count(3, 1084, 1082, 1083);
} // block
} // conditional
etiss_coverage_count(1, 1086);
if ((val << 62ULL) == 0LL) { // conditional
etiss_coverage_count(6, 1092, 1089, 1087, 1088, 1090, 1091);
{ // block
etiss_coverage_count(1, 1099);
res = res + 2ULL;
etiss_coverage_count(3, 1095, 1093, 1094);
val = val >> 2ULL;
etiss_coverage_count(3, 1098, 1096, 1097);
} // block
} // conditional
etiss_coverage_count(1, 1100);
if ((val << 63ULL) == 0LL) { // conditional
etiss_coverage_count(6, 1106, 1103, 1101, 1102, 1104, 1105);
{ // block
etiss_coverage_count(1, 1110);
res = res + 1ULL;
etiss_coverage_count(3, 1109, 1107, 1108);
} // block
} // conditional
etiss_coverage_count(1, 1112);
return res;
etiss_coverage_count(1, 1111);
} // block
}

void RV32IMACFDV_zvl128b_raise(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 irq, etiss_uint32 mcause)
{
cpu->return_pending = 1;
cpu->exception = 0;
etiss_coverage_count(1, 162);
{ // block
etiss_coverage_count(1, 1342);
etiss_uint32 epc = cpu->instructionPointer;
etiss_coverage_count(2, 1116, 1115);
etiss_int32 deleg = 0LL;
etiss_coverage_count(1, 1118);
etiss_int32 vector = 0LL;
etiss_coverage_count(1, 1119);
etiss_int32 bit = mcause;
etiss_coverage_count(2, 1121, 1120);
etiss_int32 irq2 = (mcause & 2147483648ULL) != 0LL;
etiss_coverage_count(6, 1137, 1136, 1133, 1123, 1134, 1135);
etiss_coverage_count(1, 1138);
if (irq2) { // conditional
etiss_coverage_count(1, 1139);
{ // block
etiss_coverage_count(1, 1164);
deleg = ((((RV32IMACFDV_zvl128b*)cpu)->PRIV <= 1ULL)) ? (*((RV32IMACFDV_zvl128b*)cpu)->CSR[771ULL]) : (0LL);
etiss_coverage_count(8, 1150, 1140, 1149, 1143, 1141, 1144, 1147, 1148);
bit = bit & 2147483647ULL;
etiss_coverage_count(2, 1163, 1151);
} // block
} // conditional
else { // conditional
{ // block
etiss_coverage_count(1, 1176);
deleg = ((((RV32IMACFDV_zvl128b*)cpu)->PRIV <= 1ULL)) ? (*((RV32IMACFDV_zvl128b*)cpu)->CSR[770ULL]) : (0LL);
etiss_coverage_count(8, 1175, 1165, 1174, 1168, 1166, 1169, 1172, 1173);
} // block
} // conditional
etiss_coverage_count(1, 1177);
if (((RV32IMACFDV_zvl128b*)cpu)->PRIV <= 1ULL && (deleg >> bit) & 1ULL) { // conditional
etiss_coverage_count(9, 1187, 1180, 1178, 1186, 1183, 1181, 1182, 1184, 1185);
{ // block
etiss_coverage_count(1, 1264);
vector = ((*((RV32IMACFDV_zvl128b*)cpu)->CSR[261ULL] & 1ULL) && irq2) ? (bit * 4ULL) : (0LL);
etiss_coverage_count(13, 1202, 1188, 1201, 1196, 1193, 1191, 1192, 1194, 1195, 1199, 1197, 1198, 1200);
cpu->nextPc = (*((RV32IMACFDV_zvl128b*)cpu)->CSR[261ULL] & -2LL) + vector;
etiss_coverage_count(7, 1215, 1203, 1214, 1211, 1206, 1212, 1213);
*((RV32IMACFDV_zvl128b*)cpu)->CSR[321ULL] = epc;
etiss_coverage_count(3, 1220, 1218, 1219);
*((RV32IMACFDV_zvl128b*)cpu)->CSR[322ULL] = mcause;
etiss_coverage_count(3, 1225, 1223, 1224);
etiss_uint32 s = RV32IMACFDV_zvl128b_csr_read(cpu, system, plugin_pointers, 256ULL);
etiss_coverage_count(2, 1229, 1228);
s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 32ULL, RV32IMACFDV_zvl128b_get_field(s, 2ULL)));
etiss_coverage_count(7, 1239, 1230, 1238, 1236, 1231, 1235, 1233);
s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 256ULL, ((RV32IMACFDV_zvl128b*)cpu)->PRIV));
etiss_coverage_count(6, 1247, 1240, 1246, 1244, 1241, 1243);
s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 2ULL, 0LL));
etiss_coverage_count(6, 1255, 1248, 1254, 1252, 1249, 1251);
RV32IMACFDV_zvl128b_csr_write(cpu, system, plugin_pointers, 256ULL, s);
etiss_coverage_count(2, 1258, 1257);
((RV32IMACFDV_zvl128b*)cpu)->PRIV = (1ULL) & 0x7ULL;
etiss_coverage_count(2, 1263, 1259);
} // block
} // conditional
else { // conditional
{ // block
etiss_coverage_count(1, 1341);
vector = ((*((RV32IMACFDV_zvl128b*)cpu)->CSR[773ULL] & 1ULL) && irq2) ? (bit * 4ULL) : (0LL);
etiss_coverage_count(13, 1279, 1265, 1278, 1273, 1270, 1268, 1269, 1271, 1272, 1276, 1274, 1275, 1277);
cpu->nextPc = (*((RV32IMACFDV_zvl128b*)cpu)->CSR[773ULL] & -2LL) + vector;
etiss_coverage_count(7, 1292, 1280, 1291, 1288, 1283, 1289, 1290);
*((RV32IMACFDV_zvl128b*)cpu)->CSR[833ULL] = epc;
etiss_coverage_count(3, 1297, 1295, 1296);
*((RV32IMACFDV_zvl128b*)cpu)->CSR[834ULL] = mcause;
etiss_coverage_count(3, 1302, 1300, 1301);
etiss_uint32 s = RV32IMACFDV_zvl128b_csr_read(cpu, system, plugin_pointers, 768ULL);
etiss_coverage_count(2, 1306, 1305);
s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 128ULL, RV32IMACFDV_zvl128b_get_field(s, 8ULL)));
etiss_coverage_count(7, 1316, 1307, 1315, 1313, 1308, 1312, 1310);
s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 6144ULL, ((RV32IMACFDV_zvl128b*)cpu)->PRIV));
etiss_coverage_count(6, 1324, 1317, 1323, 1321, 1318, 1320);
s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 8ULL, 0LL));
etiss_coverage_count(6, 1332, 1325, 1331, 1329, 1326, 1328);
RV32IMACFDV_zvl128b_csr_write(cpu, system, plugin_pointers, 768ULL, s);
etiss_coverage_count(2, 1335, 1334);
((RV32IMACFDV_zvl128b*)cpu)->PRIV = (3ULL) & 0x7ULL;
etiss_coverage_count(2, 1340, 1336);
} // block
} // conditional
} // block
}

void RV32IMACFDV_zvl128b_translate_exc_code(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 cause)
{
etiss_coverage_count(1, 163);
{ // block
etiss_coverage_count(1, 1399);
etiss_uint32 code = 0LL;
etiss_coverage_count(2, 1346, 1345);
etiss_coverage_count(1, 1347);
if (cause == -2147483648LL) { // conditional
etiss_coverage_count(2, 1350, 1348);
etiss_coverage_count(1, 1369);
return;
} // conditional
 else if (cause == -5LL) { // conditional
etiss_coverage_count(2, 1353, 1351);
code = 5ULL;
etiss_coverage_count(2, 1372, 1370);
} // conditional
 else if (cause == -14LL) { // conditional
etiss_coverage_count(2, 1356, 1354);
code = 13ULL;
etiss_coverage_count(2, 1375, 1373);
} // conditional
 else if (cause == -6LL) { // conditional
etiss_coverage_count(2, 1359, 1357);
code = 7ULL;
etiss_coverage_count(2, 1378, 1376);
} // conditional
 else if (cause == -15LL) { // conditional
etiss_coverage_count(2, 1362, 1360);
code = 15ULL;
etiss_coverage_count(2, 1381, 1379);
} // conditional
 else if (cause == -7LL) { // conditional
etiss_coverage_count(2, 1365, 1363);
code = 1ULL;
etiss_coverage_count(2, 1384, 1382);
} // conditional
 else if (cause == -9LL) { // conditional
etiss_coverage_count(2, 1368, 1366);
{ // block
etiss_coverage_count(1, 1392);
code = RV32IMACFDV_zvl128b_calc_irq_mcause(cpu, system, plugin_pointers);
etiss_coverage_count(3, 1387, 1385, 1386);
etiss_coverage_count(1, 1388);
if (!(code)) { // conditional
etiss_coverage_count(2, 1390, 1389);
etiss_coverage_count(1, 1391);
return;
} // conditional
} // block
} // conditional
else { // conditional
code = 2ULL;
etiss_coverage_count(2, 1395, 1393);
} // conditional
RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, code);
etiss_coverage_count(3, 1398, 1396, 1397);
} // block
}

etiss_uint32 RV32IMACFDV_zvl128b_calc_irq_mcause(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 164);
{ // block
etiss_coverage_count(1, 1584);
etiss_uint32 pending_interrupts = *((RV32IMACFDV_zvl128b*)cpu)->CSR[772ULL] & *((RV32IMACFDV_zvl128b*)cpu)->CSR[836ULL];
etiss_coverage_count(4, 1408, 1407, 1403, 1406);
etiss_coverage_count(1, 1409);
if (!(pending_interrupts)) { // conditional
etiss_coverage_count(2, 1411, 1410);
etiss_coverage_count(1, 1413);
return 0LL;
etiss_coverage_count(1, 1412);
} // conditional
etiss_uint32 mie = (etiss_uint32)(RV32IMACFDV_zvl128b_get_field(*((RV32IMACFDV_zvl128b*)cpu)->CSR[768ULL], 8ULL));
etiss_coverage_count(4, 1422, 1421, 1419, 1417);
etiss_uint32 m_enabled = ((RV32IMACFDV_zvl128b*)cpu)->PRIV < 3ULL || (((RV32IMACFDV_zvl128b*)cpu)->PRIV == 3ULL && mie);
etiss_coverage_count(9, 1434, 1433, 1426, 1424, 1431, 1429, 1427, 1430, 1432);
etiss_uint32 enabled_interrupts = pending_interrupts & ~(*((RV32IMACFDV_zvl128b*)cpu)->CSR[771ULL]) & -(m_enabled);
etiss_coverage_count(8, 1445, 1444, 1441, 1436, 1440, 1439, 1443, 1442);
etiss_coverage_count(1, 1446);
if (enabled_interrupts == 0LL) { // conditional
etiss_coverage_count(3, 1449, 1447, 1448);
{ // block
etiss_coverage_count(1, 1483);
etiss_uint32 deleg = *((RV32IMACFDV_zvl128b*)cpu)->CSR[771ULL];
etiss_coverage_count(2, 1454, 1453);
etiss_uint32 sie = (etiss_uint32)(RV32IMACFDV_zvl128b_get_field(RV32IMACFDV_zvl128b_csr_read(cpu, system, plugin_pointers, 256ULL), 2ULL));
etiss_coverage_count(4, 1462, 1461, 1459, 1457);
etiss_uint32 s_enabled = ((RV32IMACFDV_zvl128b*)cpu)->PRIV < 1ULL || (((RV32IMACFDV_zvl128b*)cpu)->PRIV == 1ULL && sie);
etiss_coverage_count(9, 1474, 1473, 1466, 1464, 1471, 1469, 1467, 1470, 1472);
enabled_interrupts = pending_interrupts & deleg & -(s_enabled);
etiss_coverage_count(8, 1482, 1475, 1481, 1478, 1476, 1477, 1480, 1479);
} // block
} // conditional
etiss_coverage_count(1, 1484);
if (enabled_interrupts) { // conditional
etiss_coverage_count(1, 1485);
{ // block
etiss_coverage_count(1, 1581);
etiss_coverage_count(1, 1486);
if (enabled_interrupts >> 12ULL) { // conditional
etiss_coverage_count(2, 1492, 1487);
enabled_interrupts = enabled_interrupts >> 12ULL << 12ULL;
etiss_coverage_count(5, 1535, 1523, 1534, 1529, 1524);
} // conditional
 else if (enabled_interrupts & 2048ULL) { // conditional
etiss_coverage_count(2, 1495, 1493);
enabled_interrupts = 2048ULL;
etiss_coverage_count(2, 1538, 1536);
} // conditional
 else if (enabled_interrupts & 8ULL) { // conditional
etiss_coverage_count(2, 1498, 1496);
enabled_interrupts = 8ULL;
etiss_coverage_count(2, 1541, 1539);
} // conditional
 else if (enabled_interrupts & 128ULL) { // conditional
etiss_coverage_count(2, 1501, 1499);
enabled_interrupts = 128ULL;
etiss_coverage_count(2, 1544, 1542);
} // conditional
 else if (enabled_interrupts & 512ULL) { // conditional
etiss_coverage_count(2, 1504, 1502);
enabled_interrupts = 512ULL;
etiss_coverage_count(2, 1547, 1545);
} // conditional
 else if (enabled_interrupts & 2ULL) { // conditional
etiss_coverage_count(2, 1507, 1505);
enabled_interrupts = 2ULL;
etiss_coverage_count(2, 1550, 1548);
} // conditional
 else if (enabled_interrupts & 32ULL) { // conditional
etiss_coverage_count(2, 1510, 1508);
enabled_interrupts = 32ULL;
etiss_coverage_count(2, 1553, 1551);
} // conditional
 else if (enabled_interrupts & 8192ULL) { // conditional
etiss_coverage_count(2, 1513, 1511);
enabled_interrupts = 8192ULL;
etiss_coverage_count(2, 1556, 1554);
} // conditional
 else if (enabled_interrupts & 1024ULL) { // conditional
etiss_coverage_count(2, 1516, 1514);
enabled_interrupts = 1024ULL;
etiss_coverage_count(2, 1559, 1557);
} // conditional
 else if (enabled_interrupts & 4ULL) { // conditional
etiss_coverage_count(2, 1519, 1517);
enabled_interrupts = 4ULL;
etiss_coverage_count(2, 1562, 1560);
} // conditional
 else if (enabled_interrupts & 64ULL) { // conditional
etiss_coverage_count(2, 1522, 1520);
enabled_interrupts = 64ULL;
etiss_coverage_count(2, 1565, 1563);
} // conditional
else { // conditional
etiss_coverage_count(1, 1567);
return 0LL;
etiss_coverage_count(1, 1566);
} // conditional
etiss_coverage_count(1, 1580);
return 2147483648ULL | RV32IMACFDV_zvl128b_ctz(enabled_interrupts);
etiss_coverage_count(3, 1579, 1578, 1577);
} // block
} // conditional
etiss_coverage_count(1, 1583);
return 0LL;
etiss_coverage_count(1, 1582);
} // block
}

void RV32IMACFDV_zvl128b_check_irq(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 165);
{ // block
etiss_coverage_count(1, 1593);
etiss_uint32 irq_mcause = RV32IMACFDV_zvl128b_calc_irq_mcause(cpu, system, plugin_pointers);
etiss_coverage_count(2, 1587, 1586);
etiss_coverage_count(1, 1588);
if (irq_mcause) { // conditional
etiss_coverage_count(1, 1589);
RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 1ULL, irq_mcause);
etiss_coverage_count(3, 1592, 1590, 1591);
} // conditional
} // block
}
// clang-format on
