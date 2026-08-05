/**
 * Generated on Wed, 05 Aug 2026 14:25:16 +0200.
 *
 * This file contains the function implementations for the RV32IMXCoreV core architecture.
 */

#include "RV32IMXCoreVFuncs.h"
// clang-format off

etiss_int32 RV32IMXCoreV_cv_mac(etiss_int32 x, etiss_int32 y, etiss_int32 acc)
{
etiss_coverage_count(1, 459);
{ // block
etiss_coverage_count(1, 544);
etiss_int128 result = acc + (x * y);
etiss_coverage_count(7, 539, 538, 533, 536, 534, 535, 537);
etiss_coverage_count(1, 543);
return ((etiss_int32)(((etiss_int32)result) << (0)) >> (0));
etiss_coverage_count(2, 542, 540);
} // block
}

etiss_int32 RV32IMXCoreV_cv_msu(etiss_int32 x, etiss_int32 y, etiss_int32 acc)
{
etiss_coverage_count(1, 460);
{ // block
etiss_coverage_count(1, 557);
etiss_int128 result = acc - (x * y);
etiss_coverage_count(7, 552, 551, 546, 549, 547, 548, 550);
etiss_coverage_count(1, 556);
return ((etiss_int32)(((etiss_int32)result) << (0)) >> (0));
etiss_coverage_count(2, 555, 553);
} // block
}

etiss_uint8 RV32IMXCoreV_extension_enabled(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int8 extension)
{
etiss_coverage_count(1, 80);
{ // block
etiss_coverage_count(1, 511);
etiss_coverage_count(1, 510);
return (*((RV32IMXCoreV*)cpu)->CSR[769ULL] >> (extension - 65ULL)) & 1ULL;
etiss_coverage_count(9, 509, 506, 501, 504, 502, 503, 505, 507, 508);
} // block
}

etiss_uint32 RV32IMXCoreV_sstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 463);
{ // block
etiss_coverage_count(1, 630);
etiss_uint32 mask = 0LL;
etiss_coverage_count(2, 560, 559);
etiss_coverage_count(1, 561);
if (RV32IMXCoreV_extension_enabled(cpu, system, plugin_pointers, 83ULL)) { // conditional
etiss_coverage_count(2, 563, 562);
{ // block
etiss_coverage_count(1, 627);
mask = mask | 5767458LL;
etiss_coverage_count(2, 579, 564);
etiss_coverage_count(1, 580);
if (RV32IMXCoreV_extension_enabled(cpu, system, plugin_pointers, 86ULL)) { // conditional
etiss_coverage_count(2, 582, 581);
mask = mask | 1536ULL;
etiss_coverage_count(2, 585, 583);
} // conditional
etiss_coverage_count(1, 586);
if (RV32IMXCoreV_extension_enabled(cpu, system, plugin_pointers, 70ULL)) { // conditional
etiss_coverage_count(2, 588, 587);
mask = mask | 24576ULL;
etiss_coverage_count(2, 591, 589);
} // conditional
etiss_coverage_count(1, 592);
if (RV32IMXCoreV_extension_enabled(cpu, system, plugin_pointers, 88ULL)) { // conditional
etiss_coverage_count(2, 594, 593);
mask = mask | 98304ULL;
etiss_coverage_count(2, 597, 595);
} // conditional
etiss_coverage_count(1, 598);
if ((RV32IMXCoreV_get_field(*((RV32IMXCoreV*)cpu)->CSR[384ULL], 2147483648ULL))) { // conditional
etiss_coverage_count(3, 608, 604, 610);
mask = mask | 262144ULL;
etiss_coverage_count(2, 626, 624);
} // conditional
} // block
} // conditional
etiss_coverage_count(1, 629);
return mask;
etiss_coverage_count(1, 628);
} // block
}

etiss_uint32 RV32IMXCoreV_mstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 464);
{ // block
etiss_coverage_count(1, 645);
etiss_uint32 mask = 6280LL;
etiss_coverage_count(1, 640);
etiss_coverage_count(1, 644);
return mask | RV32IMXCoreV_sstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(3, 643, 641, 642);
} // block
}

etiss_uint32 RV32IMXCoreV_csr_read(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr)
{
etiss_coverage_count(1, 465);
{ // block
etiss_coverage_count(1, 763);
etiss_coverage_count(1, 646);
if (csr == 1ULL) { // conditional
etiss_coverage_count(2, 649, 647);
etiss_coverage_count(1, 655);
return *((RV32IMXCoreV*)cpu)->CSR[3ULL] & 31ULL;
etiss_coverage_count(3, 654, 652, 653);
} // conditional
etiss_coverage_count(1, 656);
if (csr == 2ULL) { // conditional
etiss_coverage_count(2, 659, 657);
etiss_coverage_count(1, 668);
return (*((RV32IMXCoreV*)cpu)->CSR[3ULL] >> 5ULL) & 7ULL;
etiss_coverage_count(6, 667, 664, 662, 663, 665, 666);
} // conditional
etiss_coverage_count(1, 669);
if (csr == 3072ULL) { // conditional
etiss_coverage_count(2, 672, 670);
etiss_coverage_count(1, 674);
return etiss_get_cycles(cpu, system, plugin_pointers);
etiss_coverage_count(1, 673);
} // conditional
etiss_coverage_count(1, 675);
if (csr == 3200ULL) { // conditional
etiss_coverage_count(2, 678, 676);
etiss_coverage_count(1, 682);
return etiss_get_cycles(cpu, system, plugin_pointers) >> 32ULL;
etiss_coverage_count(3, 681, 679, 680);
} // conditional
etiss_coverage_count(1, 683);
if (csr == 3073ULL) { // conditional
etiss_coverage_count(2, 686, 684);
etiss_coverage_count(1, 688);
return etiss_get_time();
etiss_coverage_count(1, 687);
} // conditional
etiss_coverage_count(1, 689);
if (csr == 3201ULL) { // conditional
etiss_coverage_count(2, 692, 690);
etiss_coverage_count(1, 696);
return etiss_get_time() >> 32ULL;
etiss_coverage_count(3, 695, 693, 694);
} // conditional
etiss_coverage_count(1, 697);
if (csr == 3074ULL) { // conditional
etiss_coverage_count(2, 700, 698);
etiss_coverage_count(1, 702);
return etiss_get_instret(cpu, system, plugin_pointers);
etiss_coverage_count(1, 701);
} // conditional
etiss_coverage_count(1, 703);
if (csr == 3202ULL) { // conditional
etiss_coverage_count(2, 706, 704);
etiss_coverage_count(1, 710);
return etiss_get_instret(cpu, system, plugin_pointers) >> 32ULL;
etiss_coverage_count(3, 709, 707, 708);
} // conditional
etiss_coverage_count(1, 711);
if (csr == 768ULL || csr == 256ULL) { // conditional
etiss_coverage_count(5, 718, 714, 712, 717, 715);
etiss_coverage_count(1, 738);
return *((RV32IMXCoreV*)cpu)->CSR[768ULL] | 8589934592ULL | 34359738368ULL;
etiss_coverage_count(3, 737, 729, 721);
} // conditional
etiss_coverage_count(1, 739);
if (csr == 769ULL) { // conditional
etiss_coverage_count(2, 742, 740);
etiss_coverage_count(1, 758);
return (((1ULL) << 30) | (((*((RV32IMXCoreV*)cpu)->CSR[769ULL]) & 0x3fffffffULL)));
etiss_coverage_count(4, 757, 756, 751, 755);
} // conditional
etiss_coverage_count(1, 762);
return *((RV32IMXCoreV*)cpu)->CSR[csr];
etiss_coverage_count(2, 761, 760);
} // block
}

void RV32IMXCoreV_csr_write(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr, etiss_uint32 val)
{
etiss_coverage_count(1, 466);
{ // block
etiss_coverage_count(1, 845);
etiss_coverage_count(1, 764);
if (csr == 1ULL) { // conditional
etiss_coverage_count(2, 767, 765);
*((RV32IMXCoreV*)cpu)->CSR[3ULL] = (*((RV32IMXCoreV*)cpu)->CSR[3ULL] & 224ULL) | (val & 31ULL);
etiss_coverage_count(10, 800, 785, 799, 793, 788, 794, 797, 795, 796, 798);
} // conditional
 else if (csr == 2ULL) { // conditional
etiss_coverage_count(2, 770, 768);
*((RV32IMXCoreV*)cpu)->CSR[3ULL] = ((val & 7ULL) << 5ULL) | (*((RV32IMXCoreV*)cpu)->CSR[3ULL] & 31ULL);
etiss_coverage_count(14, 818, 803, 817, 809, 806, 804, 805, 807, 808, 810, 815, 813, 814, 816);
} // conditional
 else if (csr == 3ULL) { // conditional
etiss_coverage_count(2, 773, 771);
*((RV32IMXCoreV*)cpu)->CSR[3ULL] = val & 255ULL;
etiss_coverage_count(5, 825, 821, 824, 822, 823);
} // conditional
 else if (csr == 768ULL) { // conditional
etiss_coverage_count(2, 776, 774);
*((RV32IMXCoreV*)cpu)->CSR[768ULL] = val & RV32IMXCoreV_mstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(5, 832, 828, 831, 829, 830);
} // conditional
 else if (csr == 256ULL) { // conditional
etiss_coverage_count(2, 779, 777);
*((RV32IMXCoreV*)cpu)->CSR[768ULL] = val & RV32IMXCoreV_sstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(5, 839, 835, 838, 836, 837);
} // conditional
 else if (csr != 769ULL) { // conditional
etiss_coverage_count(2, 782, 780);
*((RV32IMXCoreV*)cpu)->CSR[csr] = val;
etiss_coverage_count(4, 844, 842, 841, 843);
} // conditional
} // block
}

etiss_uint64 RV32IMXCoreV_get_field(etiss_uint64 reg, etiss_uint64 mask)
{
etiss_coverage_count(1, 473);
{ // block
etiss_coverage_count(1, 865);
etiss_coverage_count(1, 846);
if (!(mask)) { // conditional
etiss_coverage_count(2, 848, 847);
etiss_coverage_count(1, 850);
return 0LL;
etiss_coverage_count(1, 849);
} // conditional
etiss_coverage_count(1, 864);
return (reg & mask) / (mask & ~((mask << 1ULL)));
etiss_coverage_count(13, 863, 853, 851, 852, 854, 861, 855, 860, 858, 856, 857, 859, 862);
} // block
}

etiss_uint64 RV32IMXCoreV_set_field(etiss_uint64 reg, etiss_uint64 mask, etiss_uint64 val)
{
etiss_coverage_count(1, 474);
{ // block
etiss_coverage_count(1, 888);
etiss_coverage_count(1, 887);
return ((reg & ~(mask)) | ((val * (mask & ~((mask << 1ULL)))) & mask));
etiss_coverage_count(21, 885, 869, 866, 868, 867, 870, 883, 880, 871, 878, 872, 877, 875, 873, 874, 876, 879, 881, 882, 884, 886);
} // block
}

etiss_uint8 RV32IMXCoreV_ctz(etiss_uint64 val)
{
etiss_coverage_count(1, 475);
{ // block
etiss_coverage_count(1, 980);
etiss_coverage_count(1, 889);
if (!(val)) { // conditional
etiss_coverage_count(2, 891, 890);
etiss_coverage_count(1, 893);
return 0LL;
etiss_coverage_count(1, 892);
} // conditional
etiss_uint8 res = 0LL;
etiss_coverage_count(2, 896, 895);
etiss_coverage_count(1, 897);
if ((val << 32ULL) == 0LL) { // conditional
etiss_coverage_count(6, 903, 900, 898, 899, 901, 902);
{ // block
etiss_coverage_count(1, 910);
res = res + 32ULL;
etiss_coverage_count(3, 906, 904, 905);
val = val >> 32ULL;
etiss_coverage_count(3, 909, 907, 908);
} // block
} // conditional
etiss_coverage_count(1, 911);
if ((val << 48ULL) == 0LL) { // conditional
etiss_coverage_count(6, 917, 914, 912, 913, 915, 916);
{ // block
etiss_coverage_count(1, 924);
res = res + 16ULL;
etiss_coverage_count(3, 920, 918, 919);
val = val >> 16ULL;
etiss_coverage_count(3, 923, 921, 922);
} // block
} // conditional
etiss_coverage_count(1, 925);
if ((val << 56ULL) == 0LL) { // conditional
etiss_coverage_count(6, 931, 928, 926, 927, 929, 930);
{ // block
etiss_coverage_count(1, 938);
res = res + 8ULL;
etiss_coverage_count(3, 934, 932, 933);
val = val >> 8ULL;
etiss_coverage_count(3, 937, 935, 936);
} // block
} // conditional
etiss_coverage_count(1, 939);
if ((val << 60ULL) == 0LL) { // conditional
etiss_coverage_count(6, 945, 942, 940, 941, 943, 944);
{ // block
etiss_coverage_count(1, 952);
res = res + 4ULL;
etiss_coverage_count(3, 948, 946, 947);
val = val >> 4ULL;
etiss_coverage_count(3, 951, 949, 950);
} // block
} // conditional
etiss_coverage_count(1, 953);
if ((val << 62ULL) == 0LL) { // conditional
etiss_coverage_count(6, 959, 956, 954, 955, 957, 958);
{ // block
etiss_coverage_count(1, 966);
res = res + 2ULL;
etiss_coverage_count(3, 962, 960, 961);
val = val >> 2ULL;
etiss_coverage_count(3, 965, 963, 964);
} // block
} // conditional
etiss_coverage_count(1, 967);
if ((val << 63ULL) == 0LL) { // conditional
etiss_coverage_count(6, 973, 970, 968, 969, 971, 972);
{ // block
etiss_coverage_count(1, 977);
res = res + 1ULL;
etiss_coverage_count(3, 976, 974, 975);
} // block
} // conditional
etiss_coverage_count(1, 979);
return res;
etiss_coverage_count(1, 978);
} // block
}

void RV32IMXCoreV_raise(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 irq, etiss_uint32 mcause)
{
cpu->return_pending = 1;
cpu->exception = 0;
etiss_coverage_count(1, 476);
{ // block
etiss_coverage_count(1, 1209);
etiss_uint32 epc = cpu->instructionPointer;
etiss_coverage_count(2, 983, 982);
etiss_int32 deleg = 0LL;
etiss_coverage_count(1, 985);
etiss_int32 vector = 0LL;
etiss_coverage_count(1, 986);
etiss_int32 bit = mcause;
etiss_coverage_count(2, 988, 987);
etiss_int32 irq2 = (mcause & 2147483648ULL) != 0LL;
etiss_coverage_count(6, 1004, 1003, 1000, 990, 1001, 1002);
etiss_coverage_count(1, 1005);
if (irq2) { // conditional
etiss_coverage_count(1, 1006);
{ // block
etiss_coverage_count(1, 1031);
deleg = ((((RV32IMXCoreV*)cpu)->PRIV <= 1ULL)) ? (*((RV32IMXCoreV*)cpu)->CSR[771ULL]) : (0LL);
etiss_coverage_count(8, 1017, 1007, 1016, 1010, 1008, 1011, 1014, 1015);
bit = bit & 2147483647ULL;
etiss_coverage_count(2, 1030, 1018);
} // block
} // conditional
else { // conditional
{ // block
etiss_coverage_count(1, 1043);
deleg = ((((RV32IMXCoreV*)cpu)->PRIV <= 1ULL)) ? (*((RV32IMXCoreV*)cpu)->CSR[770ULL]) : (0LL);
etiss_coverage_count(8, 1042, 1032, 1041, 1035, 1033, 1036, 1039, 1040);
} // block
} // conditional
etiss_coverage_count(1, 1044);
if (((RV32IMXCoreV*)cpu)->PRIV <= 1ULL && (deleg >> bit) & 1ULL) { // conditional
etiss_coverage_count(9, 1054, 1047, 1045, 1053, 1050, 1048, 1049, 1051, 1052);
{ // block
etiss_coverage_count(1, 1131);
vector = ((*((RV32IMXCoreV*)cpu)->CSR[261ULL] & 1ULL) && irq2) ? (bit * 4ULL) : (0LL);
etiss_coverage_count(13, 1069, 1055, 1068, 1063, 1060, 1058, 1059, 1061, 1062, 1066, 1064, 1065, 1067);
cpu->nextPc = (*((RV32IMXCoreV*)cpu)->CSR[261ULL] & -2LL) + vector;
etiss_coverage_count(7, 1082, 1070, 1081, 1078, 1073, 1079, 1080);
*((RV32IMXCoreV*)cpu)->CSR[321ULL] = epc;
etiss_coverage_count(3, 1087, 1085, 1086);
*((RV32IMXCoreV*)cpu)->CSR[322ULL] = mcause;
etiss_coverage_count(3, 1092, 1090, 1091);
etiss_uint32 s = RV32IMXCoreV_csr_read(cpu, system, plugin_pointers, 256ULL);
etiss_coverage_count(2, 1096, 1095);
s = (etiss_uint32)(RV32IMXCoreV_set_field(s, 32ULL, RV32IMXCoreV_get_field(s, 2ULL)));
etiss_coverage_count(7, 1106, 1097, 1105, 1103, 1098, 1102, 1100);
s = (etiss_uint32)(RV32IMXCoreV_set_field(s, 256ULL, ((RV32IMXCoreV*)cpu)->PRIV));
etiss_coverage_count(6, 1114, 1107, 1113, 1111, 1108, 1110);
s = (etiss_uint32)(RV32IMXCoreV_set_field(s, 2ULL, 0LL));
etiss_coverage_count(6, 1122, 1115, 1121, 1119, 1116, 1118);
RV32IMXCoreV_csr_write(cpu, system, plugin_pointers, 256ULL, s);
etiss_coverage_count(2, 1125, 1124);
((RV32IMXCoreV*)cpu)->PRIV = (1ULL) & 0x7ULL;
etiss_coverage_count(2, 1130, 1126);
} // block
} // conditional
else { // conditional
{ // block
etiss_coverage_count(1, 1208);
vector = ((*((RV32IMXCoreV*)cpu)->CSR[773ULL] & 1ULL) && irq2) ? (bit * 4ULL) : (0LL);
etiss_coverage_count(13, 1146, 1132, 1145, 1140, 1137, 1135, 1136, 1138, 1139, 1143, 1141, 1142, 1144);
cpu->nextPc = (*((RV32IMXCoreV*)cpu)->CSR[773ULL] & -2LL) + vector;
etiss_coverage_count(7, 1159, 1147, 1158, 1155, 1150, 1156, 1157);
*((RV32IMXCoreV*)cpu)->CSR[833ULL] = epc;
etiss_coverage_count(3, 1164, 1162, 1163);
*((RV32IMXCoreV*)cpu)->CSR[834ULL] = mcause;
etiss_coverage_count(3, 1169, 1167, 1168);
etiss_uint32 s = RV32IMXCoreV_csr_read(cpu, system, plugin_pointers, 768ULL);
etiss_coverage_count(2, 1173, 1172);
s = (etiss_uint32)(RV32IMXCoreV_set_field(s, 128ULL, RV32IMXCoreV_get_field(s, 8ULL)));
etiss_coverage_count(7, 1183, 1174, 1182, 1180, 1175, 1179, 1177);
s = (etiss_uint32)(RV32IMXCoreV_set_field(s, 6144ULL, ((RV32IMXCoreV*)cpu)->PRIV));
etiss_coverage_count(6, 1191, 1184, 1190, 1188, 1185, 1187);
s = (etiss_uint32)(RV32IMXCoreV_set_field(s, 8ULL, 0LL));
etiss_coverage_count(6, 1199, 1192, 1198, 1196, 1193, 1195);
RV32IMXCoreV_csr_write(cpu, system, plugin_pointers, 768ULL, s);
etiss_coverage_count(2, 1202, 1201);
((RV32IMXCoreV*)cpu)->PRIV = (3ULL) & 0x7ULL;
etiss_coverage_count(2, 1207, 1203);
} // block
} // conditional
} // block
}

void RV32IMXCoreV_translate_exc_code(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 cause)
{
etiss_coverage_count(1, 477);
{ // block
etiss_coverage_count(1, 1266);
etiss_uint32 code = 0LL;
etiss_coverage_count(2, 1213, 1212);
etiss_coverage_count(1, 1214);
if (cause == -2147483648LL) { // conditional
etiss_coverage_count(2, 1217, 1215);
etiss_coverage_count(1, 1236);
return;
} // conditional
 else if (cause == -5LL) { // conditional
etiss_coverage_count(2, 1220, 1218);
code = 5ULL;
etiss_coverage_count(2, 1239, 1237);
} // conditional
 else if (cause == -14LL) { // conditional
etiss_coverage_count(2, 1223, 1221);
code = 13ULL;
etiss_coverage_count(2, 1242, 1240);
} // conditional
 else if (cause == -6LL) { // conditional
etiss_coverage_count(2, 1226, 1224);
code = 7ULL;
etiss_coverage_count(2, 1245, 1243);
} // conditional
 else if (cause == -15LL) { // conditional
etiss_coverage_count(2, 1229, 1227);
code = 15ULL;
etiss_coverage_count(2, 1248, 1246);
} // conditional
 else if (cause == -7LL) { // conditional
etiss_coverage_count(2, 1232, 1230);
code = 1ULL;
etiss_coverage_count(2, 1251, 1249);
} // conditional
 else if (cause == -9LL) { // conditional
etiss_coverage_count(2, 1235, 1233);
{ // block
etiss_coverage_count(1, 1259);
code = RV32IMXCoreV_calc_irq_mcause(cpu, system, plugin_pointers);
etiss_coverage_count(3, 1254, 1252, 1253);
etiss_coverage_count(1, 1255);
if (!(code)) { // conditional
etiss_coverage_count(2, 1257, 1256);
etiss_coverage_count(1, 1258);
return;
} // conditional
} // block
} // conditional
else { // conditional
code = 2ULL;
etiss_coverage_count(2, 1262, 1260);
} // conditional
RV32IMXCoreV_raise(cpu, system, plugin_pointers, 0LL, code);
etiss_coverage_count(3, 1265, 1263, 1264);
} // block
}

etiss_uint32 RV32IMXCoreV_calc_irq_mcause(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 478);
{ // block
etiss_coverage_count(1, 1451);
etiss_uint32 pending_interrupts = *((RV32IMXCoreV*)cpu)->CSR[772ULL] & *((RV32IMXCoreV*)cpu)->CSR[836ULL];
etiss_coverage_count(4, 1275, 1274, 1270, 1273);
etiss_coverage_count(1, 1276);
if (!(pending_interrupts)) { // conditional
etiss_coverage_count(2, 1278, 1277);
etiss_coverage_count(1, 1280);
return 0LL;
etiss_coverage_count(1, 1279);
} // conditional
etiss_uint32 mie = (etiss_uint32)(RV32IMXCoreV_get_field(*((RV32IMXCoreV*)cpu)->CSR[768ULL], 8ULL));
etiss_coverage_count(4, 1289, 1288, 1286, 1284);
etiss_uint32 m_enabled = ((RV32IMXCoreV*)cpu)->PRIV < 3ULL || (((RV32IMXCoreV*)cpu)->PRIV == 3ULL && mie);
etiss_coverage_count(9, 1301, 1300, 1293, 1291, 1298, 1296, 1294, 1297, 1299);
etiss_uint32 enabled_interrupts = pending_interrupts & ~(*((RV32IMXCoreV*)cpu)->CSR[771ULL]) & -(m_enabled);
etiss_coverage_count(8, 1312, 1311, 1308, 1303, 1307, 1306, 1310, 1309);
etiss_coverage_count(1, 1313);
if (enabled_interrupts == 0LL) { // conditional
etiss_coverage_count(3, 1316, 1314, 1315);
{ // block
etiss_coverage_count(1, 1350);
etiss_uint32 deleg = *((RV32IMXCoreV*)cpu)->CSR[771ULL];
etiss_coverage_count(2, 1321, 1320);
etiss_uint32 sie = (etiss_uint32)(RV32IMXCoreV_get_field(RV32IMXCoreV_csr_read(cpu, system, plugin_pointers, 256ULL), 2ULL));
etiss_coverage_count(4, 1329, 1328, 1326, 1324);
etiss_uint32 s_enabled = ((RV32IMXCoreV*)cpu)->PRIV < 1ULL || (((RV32IMXCoreV*)cpu)->PRIV == 1ULL && sie);
etiss_coverage_count(9, 1341, 1340, 1333, 1331, 1338, 1336, 1334, 1337, 1339);
enabled_interrupts = pending_interrupts & deleg & -(s_enabled);
etiss_coverage_count(8, 1349, 1342, 1348, 1345, 1343, 1344, 1347, 1346);
} // block
} // conditional
etiss_coverage_count(1, 1351);
if (enabled_interrupts) { // conditional
etiss_coverage_count(1, 1352);
{ // block
etiss_coverage_count(1, 1448);
etiss_coverage_count(1, 1353);
if (enabled_interrupts >> 12ULL) { // conditional
etiss_coverage_count(2, 1359, 1354);
enabled_interrupts = enabled_interrupts >> 12ULL << 12ULL;
etiss_coverage_count(5, 1402, 1390, 1401, 1396, 1391);
} // conditional
 else if (enabled_interrupts & 2048ULL) { // conditional
etiss_coverage_count(2, 1362, 1360);
enabled_interrupts = 2048ULL;
etiss_coverage_count(2, 1405, 1403);
} // conditional
 else if (enabled_interrupts & 8ULL) { // conditional
etiss_coverage_count(2, 1365, 1363);
enabled_interrupts = 8ULL;
etiss_coverage_count(2, 1408, 1406);
} // conditional
 else if (enabled_interrupts & 128ULL) { // conditional
etiss_coverage_count(2, 1368, 1366);
enabled_interrupts = 128ULL;
etiss_coverage_count(2, 1411, 1409);
} // conditional
 else if (enabled_interrupts & 512ULL) { // conditional
etiss_coverage_count(2, 1371, 1369);
enabled_interrupts = 512ULL;
etiss_coverage_count(2, 1414, 1412);
} // conditional
 else if (enabled_interrupts & 2ULL) { // conditional
etiss_coverage_count(2, 1374, 1372);
enabled_interrupts = 2ULL;
etiss_coverage_count(2, 1417, 1415);
} // conditional
 else if (enabled_interrupts & 32ULL) { // conditional
etiss_coverage_count(2, 1377, 1375);
enabled_interrupts = 32ULL;
etiss_coverage_count(2, 1420, 1418);
} // conditional
 else if (enabled_interrupts & 8192ULL) { // conditional
etiss_coverage_count(2, 1380, 1378);
enabled_interrupts = 8192ULL;
etiss_coverage_count(2, 1423, 1421);
} // conditional
 else if (enabled_interrupts & 1024ULL) { // conditional
etiss_coverage_count(2, 1383, 1381);
enabled_interrupts = 1024ULL;
etiss_coverage_count(2, 1426, 1424);
} // conditional
 else if (enabled_interrupts & 4ULL) { // conditional
etiss_coverage_count(2, 1386, 1384);
enabled_interrupts = 4ULL;
etiss_coverage_count(2, 1429, 1427);
} // conditional
 else if (enabled_interrupts & 64ULL) { // conditional
etiss_coverage_count(2, 1389, 1387);
enabled_interrupts = 64ULL;
etiss_coverage_count(2, 1432, 1430);
} // conditional
else { // conditional
etiss_coverage_count(1, 1434);
return 0LL;
etiss_coverage_count(1, 1433);
} // conditional
etiss_coverage_count(1, 1447);
return 2147483648ULL | RV32IMXCoreV_ctz(enabled_interrupts);
etiss_coverage_count(3, 1446, 1445, 1444);
} // block
} // conditional
etiss_coverage_count(1, 1450);
return 0LL;
etiss_coverage_count(1, 1449);
} // block
}

void RV32IMXCoreV_check_irq(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
etiss_coverage_count(1, 479);
{ // block
etiss_coverage_count(1, 1460);
etiss_uint32 irq_mcause = RV32IMXCoreV_calc_irq_mcause(cpu, system, plugin_pointers);
etiss_coverage_count(2, 1454, 1453);
etiss_coverage_count(1, 1455);
if (irq_mcause) { // conditional
etiss_coverage_count(1, 1456);
RV32IMXCoreV_raise(cpu, system, plugin_pointers, 1ULL, irq_mcause);
etiss_coverage_count(3, 1459, 1457, 1458);
} // conditional
} // block
}
// clang-format on
