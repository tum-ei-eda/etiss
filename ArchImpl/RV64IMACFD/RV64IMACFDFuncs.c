/**
 * Generated on Tue, 05 Mar 2024 21:20:27 +0100.
 *
 * This file contains the function implementations for the RV64IMACFD core architecture.
 */

#include "RV64IMACFDFuncs.h"

etiss_uint8 RV64IMACFD_extension_enabled(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int8 extension)
{
{ // block
etiss_coverage_count(1, 5691);
return (*((RV64IMACFD*)cpu)->CSR[769LL] >> (extension - 65ULL)) & 1ULL;
etiss_coverage_count(2, 5689, 5688);
} // block
}

etiss_uint8 RV64IMACFD_get_rm(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint8 rm)
{
{ // block
etiss_coverage_count(1, 5706);
if (rm == 7ULL) { // conditional
etiss_coverage_count(2, 5693, 5692);
rm = ((((((RV64IMACFD*)cpu)->FCSR) >> (5ULL)) & 7)) & 0x7;
etiss_coverage_count(3, 5697, 5694, 5696);
} // conditional
if (rm > 4ULL) { // conditional
etiss_coverage_count(2, 5700, 5699);
RV64IMACFD_raise(cpu, system, plugin_pointers, 0ULL, 2LL);
etiss_coverage_count(1, 5702);
} // conditional
return rm;
etiss_coverage_count(1, 5704);
} // block
}

etiss_uint64 RV64IMACFD_sstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
{ // block
etiss_coverage_count(1, 5767);
etiss_uint64 mask = 0ULL;
etiss_coverage_count(1, 5708);
if (RV64IMACFD_extension_enabled(cpu, system, plugin_pointers, 83ULL)) { // conditional
etiss_coverage_count(1, 5709);
{ // block
etiss_coverage_count(1, 5763);
mask = mask | 5767458ULL;
etiss_coverage_count(2, 5724, 5710);
if (RV64IMACFD_extension_enabled(cpu, system, plugin_pointers, 86ULL)) { // conditional
etiss_coverage_count(1, 5725);
mask = mask | 1536LL;
etiss_coverage_count(2, 5728, 5726);
} // conditional
if (RV64IMACFD_extension_enabled(cpu, system, plugin_pointers, 70ULL)) { // conditional
etiss_coverage_count(1, 5730);
mask = mask | 24576LL;
etiss_coverage_count(2, 5733, 5731);
} // conditional
if (RV64IMACFD_extension_enabled(cpu, system, plugin_pointers, 88ULL)) { // conditional
etiss_coverage_count(1, 5735);
mask = mask | 98304LL;
etiss_coverage_count(2, 5738, 5736);
} // conditional
if ((RV64IMACFD_get_field(*((RV64IMACFD*)cpu)->CSR[384LL], 17293822569102704640ULL))) { // conditional
etiss_coverage_count(1, 5755);
mask = mask | 262144LL;
etiss_coverage_count(2, 5761, 5759);
} // conditional
} // block
} // conditional
return mask;
etiss_coverage_count(1, 5765);
} // block
}

etiss_uint64 RV64IMACFD_mstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
{ // block
etiss_coverage_count(1, 5781);
etiss_uint64 mask = 6280ULL;
etiss_coverage_count(1, 5776);
return mask | RV64IMACFD_sstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(3, 5779, 5777, 5778);
} // block
}

etiss_uint64 RV64IMACFD_csr_read(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr)
{
{ // block
etiss_coverage_count(1, 5886);
if (csr == 1LL) { // conditional
etiss_coverage_count(2, 5784, 5782);
return *((RV64IMACFD*)cpu)->CSR[3LL] & 31ULL;
etiss_coverage_count(2, 5788, 5787);
} // conditional
if (csr == 2LL) { // conditional
etiss_coverage_count(2, 5793, 5791);
return (*((RV64IMACFD*)cpu)->CSR[3LL] >> 5ULL) & 7ULL;
etiss_coverage_count(2, 5799, 5798);
} // conditional
if (csr == 3072LL) { // conditional
etiss_coverage_count(2, 5804, 5802);
return etiss_get_cycles(cpu, system, plugin_pointers);
etiss_coverage_count(1, 5805);
} // conditional
if (csr == 3200LL) { // conditional
etiss_coverage_count(2, 5810, 5808);
return etiss_get_cycles(cpu, system, plugin_pointers) >> 32ULL;
etiss_coverage_count(2, 5812, 5811);
} // conditional
if (csr == 3073LL) { // conditional
etiss_coverage_count(2, 5817, 5815);
return etiss_get_time();
etiss_coverage_count(1, 5818);
} // conditional
if (csr == 3201LL) { // conditional
etiss_coverage_count(2, 5823, 5821);
return etiss_get_time() >> 32ULL;
etiss_coverage_count(2, 5825, 5824);
} // conditional
if (csr == 3074LL) { // conditional
etiss_coverage_count(2, 5830, 5828);
return etiss_get_instret(cpu, system, plugin_pointers);
etiss_coverage_count(1, 5831);
} // conditional
if (csr == 3202LL) { // conditional
etiss_coverage_count(2, 5836, 5834);
return etiss_get_instret(cpu, system, plugin_pointers) >> 32ULL;
etiss_coverage_count(2, 5838, 5837);
} // conditional
if (csr == 768LL || csr == 256LL) { // conditional
etiss_coverage_count(3, 5847, 5843, 5846);
return *((RV64IMACFD*)cpu)->CSR[768LL] | 8589934592ULL | 34359738368ULL;
etiss_coverage_count(2, 5864, 5857);
} // conditional
if (csr == 769LL) { // conditional
etiss_coverage_count(2, 5869, 5867);
return (((2ULL) << 62) | ((((*((RV64IMACFD*)cpu)->CSR[769LL]) >> (0ULL)) & 4611686018427387903)));
etiss_coverage_count(2, 5879, 5878);
} // conditional
return *((RV64IMACFD*)cpu)->CSR[csr];
etiss_coverage_count(2, 5884, 5883);
} // block
}

void RV64IMACFD_csr_write(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr, etiss_uint64 val)
{
{ // block
etiss_coverage_count(1, 5961);
if (csr == 1LL) { // conditional
etiss_coverage_count(2, 5889, 5887);
*((RV64IMACFD*)cpu)->CSR[3LL] = (*((RV64IMACFD*)cpu)->CSR[3LL] & 224ULL) | (val & 31ULL);
etiss_coverage_count(3, 5919, 5907, 5918);
} // conditional
 else if (csr == 2LL) { // conditional
etiss_coverage_count(2, 5892, 5890);
*((RV64IMACFD*)cpu)->CSR[3LL] = ((val & 7ULL) << 5ULL) | (*((RV64IMACFD*)cpu)->CSR[3LL] & 31ULL);
etiss_coverage_count(3, 5934, 5922, 5933);
} // conditional
 else if (csr == 3LL) { // conditional
etiss_coverage_count(2, 5895, 5893);
*((RV64IMACFD*)cpu)->CSR[3LL] = val & 255ULL;
etiss_coverage_count(3, 5940, 5937, 5939);
} // conditional
 else if (csr == 768LL) { // conditional
etiss_coverage_count(2, 5898, 5896);
*((RV64IMACFD*)cpu)->CSR[768LL] = val & RV64IMACFD_mstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(3, 5947, 5943, 5946);
} // conditional
 else if (csr == 256LL) { // conditional
etiss_coverage_count(2, 5901, 5899);
*((RV64IMACFD*)cpu)->CSR[768LL] = val & RV64IMACFD_sstatus_mask(cpu, system, plugin_pointers);
etiss_coverage_count(3, 5954, 5950, 5953);
} // conditional
 else if (csr != 769LL) { // conditional
etiss_coverage_count(2, 5904, 5902);
*((RV64IMACFD*)cpu)->CSR[csr] = val;
etiss_coverage_count(3, 5959, 5957, 5958);
} // conditional
} // block
}

etiss_uint64 RV64IMACFD_get_field(etiss_uint64 reg, etiss_uint64 mask)
{
{ // block
etiss_coverage_count(1, 5979);
if (!(mask)) { // conditional
etiss_coverage_count(2, 5963, 5962);
return 0ULL;
} // conditional
return (reg & mask) / (mask & ~((mask << 1ULL)));
etiss_coverage_count(3, 5977, 5969, 5976);
} // block
}

etiss_uint64 RV64IMACFD_set_field(etiss_uint64 reg, etiss_uint64 mask, etiss_uint64 val)
{
{ // block
etiss_coverage_count(1, 6001);
return ((reg & ~(mask)) | ((val * (mask & ~((mask << 1ULL)))) & mask));
etiss_coverage_count(3, 5998, 5984, 5997);
} // block
}

etiss_uint8 RV64IMACFD_ctz(etiss_uint64 val)
{
{ // block
etiss_coverage_count(1, 6069);
if (!(val)) { // conditional
etiss_coverage_count(2, 6003, 6002);
return 0ULL;
} // conditional
etiss_uint8 res = 0ULL;
etiss_coverage_count(1, 6006);
if ((val << 32ULL) == 0ULL) { // conditional
etiss_coverage_count(2, 6010, 6009);
{ // block
etiss_coverage_count(1, 6015);
res = res + 32ULL;
etiss_coverage_count(2, 6012, 6011);
val = val >> 32ULL;
etiss_coverage_count(2, 6014, 6013);
} // block
} // conditional
if ((val << 48ULL) == 0ULL) { // conditional
etiss_coverage_count(2, 6020, 6019);
{ // block
etiss_coverage_count(1, 6025);
res = res + 16ULL;
etiss_coverage_count(2, 6022, 6021);
val = val >> 16ULL;
etiss_coverage_count(2, 6024, 6023);
} // block
} // conditional
if ((val << 56ULL) == 0ULL) { // conditional
etiss_coverage_count(2, 6030, 6029);
{ // block
etiss_coverage_count(1, 6035);
res = res + 8ULL;
etiss_coverage_count(2, 6032, 6031);
val = val >> 8ULL;
etiss_coverage_count(2, 6034, 6033);
} // block
} // conditional
if ((val << 60ULL) == 0ULL) { // conditional
etiss_coverage_count(2, 6040, 6039);
{ // block
etiss_coverage_count(1, 6045);
res = res + 4ULL;
etiss_coverage_count(2, 6042, 6041);
val = val >> 4ULL;
etiss_coverage_count(2, 6044, 6043);
} // block
} // conditional
if ((val << 62ULL) == 0ULL) { // conditional
etiss_coverage_count(2, 6050, 6049);
{ // block
etiss_coverage_count(1, 6055);
res = res + 2ULL;
etiss_coverage_count(2, 6052, 6051);
val = val >> 2ULL;
etiss_coverage_count(2, 6054, 6053);
} // block
} // conditional
if ((val << 63ULL) == 0ULL) { // conditional
etiss_coverage_count(2, 6060, 6059);
{ // block
etiss_coverage_count(1, 6065);
res = res + 1ULL;
etiss_coverage_count(2, 6062, 6061);
val = val >> 1ULL;
etiss_coverage_count(2, 6064, 6063);
} // block
} // conditional
return res;
etiss_coverage_count(1, 6067);
} // block
}

void RV64IMACFD_raise(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 irq, etiss_uint64 mcause)
{
cpu->return_pending = 1;
cpu->exception = 0;
{ // block
etiss_coverage_count(1, 6258);
etiss_uint64 epc = cpu->instructionPointer;
etiss_coverage_count(2, 6072, 6071);
etiss_uint64 deleg = 0ULL;
etiss_coverage_count(1, 6074);
etiss_uint64 vector = 0ULL;
etiss_coverage_count(1, 6075);
etiss_uint64 bit = mcause;
etiss_coverage_count(2, 6077, 6076);
etiss_int32 irq2 = (mcause & 9223372036854775808ULL) != 0ULL;
etiss_coverage_count(2, 6088, 6087);
if (irq2) { // conditional
etiss_coverage_count(1, 6089);
{ // block
etiss_coverage_count(1, 6109);
deleg = ((((RV64IMACFD*)cpu)->PRIV <= 1LL)) ? (*((RV64IMACFD*)cpu)->CSR[771LL]) : (0ULL);
etiss_coverage_count(3, 6099, 6090, 6098);
bit = bit & 9223372036854775807ULL;
etiss_coverage_count(2, 6108, 6100);
} // block
} // conditional
else { // conditional
{ // block
etiss_coverage_count(1, 6120);
deleg = ((((RV64IMACFD*)cpu)->PRIV <= 1LL)) ? (*((RV64IMACFD*)cpu)->CSR[770LL]) : (0ULL);
etiss_coverage_count(3, 6119, 6110, 6118);
} // block
} // conditional
if (((RV64IMACFD*)cpu)->PRIV <= 1LL && (deleg >> bit) & 1ULL) { // conditional
etiss_coverage_count(3, 6130, 6124, 6129);
{ // block
etiss_coverage_count(1, 6193);
vector = ((*((RV64IMACFD*)cpu)->CSR[261LL] & 1ULL) && irq2) ? (bit * 4ULL) : (0ULL);
etiss_coverage_count(3, 6142, 6131, 6141);
cpu->nextPc = (*((RV64IMACFD*)cpu)->CSR[261LL] & -2LL) + vector;
etiss_coverage_count(3, 6153, 6143, 6152);
*((RV64IMACFD*)cpu)->CSR[321LL] = epc;
etiss_coverage_count(3, 6158, 6156, 6157);
*((RV64IMACFD*)cpu)->CSR[322LL] = mcause;
etiss_coverage_count(3, 6163, 6161, 6162);
etiss_uint64 s = RV64IMACFD_csr_read(cpu, system, plugin_pointers, 256LL);
etiss_coverage_count(2, 6167, 6166);
s = RV64IMACFD_set_field(s, 32LL, RV64IMACFD_get_field(s, 2LL));
etiss_coverage_count(3, 6175, 6168, 6174);
s = RV64IMACFD_set_field(s, 256LL, ((RV64IMACFD*)cpu)->PRIV);
etiss_coverage_count(3, 6181, 6176, 6180);
s = RV64IMACFD_set_field(s, 2LL, 0ULL);
etiss_coverage_count(3, 6186, 6182, 6185);
RV64IMACFD_csr_write(cpu, system, plugin_pointers, 256LL, s);
etiss_coverage_count(1, 6189);
((RV64IMACFD*)cpu)->PRIV = (1LL) & 0x7;
etiss_coverage_count(2, 6192, 6190);
} // block
} // conditional
else { // conditional
{ // block
etiss_coverage_count(1, 6256);
vector = ((*((RV64IMACFD*)cpu)->CSR[773LL] & 1ULL) && irq2) ? (bit * 4ULL) : (0ULL);
etiss_coverage_count(3, 6205, 6194, 6204);
cpu->nextPc = (*((RV64IMACFD*)cpu)->CSR[773LL] & -2LL) + vector;
etiss_coverage_count(3, 6216, 6206, 6215);
*((RV64IMACFD*)cpu)->CSR[833LL] = epc;
etiss_coverage_count(3, 6221, 6219, 6220);
*((RV64IMACFD*)cpu)->CSR[834LL] = mcause;
etiss_coverage_count(3, 6226, 6224, 6225);
etiss_uint64 s = RV64IMACFD_csr_read(cpu, system, plugin_pointers, 768LL);
etiss_coverage_count(2, 6230, 6229);
s = RV64IMACFD_set_field(s, 128LL, RV64IMACFD_get_field(s, 8LL));
etiss_coverage_count(3, 6238, 6231, 6237);
s = RV64IMACFD_set_field(s, 6144LL, ((RV64IMACFD*)cpu)->PRIV);
etiss_coverage_count(3, 6244, 6239, 6243);
s = RV64IMACFD_set_field(s, 8LL, 0ULL);
etiss_coverage_count(3, 6249, 6245, 6248);
RV64IMACFD_csr_write(cpu, system, plugin_pointers, 768LL, s);
etiss_coverage_count(1, 6252);
((RV64IMACFD*)cpu)->PRIV = (3LL) & 0x7;
etiss_coverage_count(2, 6255, 6253);
} // block
} // conditional
} // block
}

void RV64IMACFD_translate_exc_code(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 cause)
{
{ // block
etiss_coverage_count(1, 6313);
etiss_uint64 code = 0ULL;
etiss_coverage_count(1, 6261);
if (cause == -2147483648LL) { // conditional
etiss_coverage_count(2, 6264, 6262);
return;
etiss_coverage_count(1, 6283);
} // conditional
 else if (cause == -5LL) { // conditional
etiss_coverage_count(2, 6267, 6265);
code = 5LL;
etiss_coverage_count(2, 6286, 6284);
} // conditional
 else if (cause == -14LL) { // conditional
etiss_coverage_count(2, 6270, 6268);
code = 13LL;
etiss_coverage_count(2, 6289, 6287);
} // conditional
 else if (cause == -6LL) { // conditional
etiss_coverage_count(2, 6273, 6271);
code = 7LL;
etiss_coverage_count(2, 6292, 6290);
} // conditional
 else if (cause == -15LL) { // conditional
etiss_coverage_count(2, 6276, 6274);
code = 15LL;
etiss_coverage_count(2, 6295, 6293);
} // conditional
 else if (cause == -7LL) { // conditional
etiss_coverage_count(2, 6279, 6277);
code = 1LL;
etiss_coverage_count(2, 6298, 6296);
} // conditional
 else if (cause == -9LL) { // conditional
etiss_coverage_count(2, 6282, 6280);
{ // block
etiss_coverage_count(1, 6306);
code = RV64IMACFD_calc_irq_mcause(cpu, system, plugin_pointers);
etiss_coverage_count(3, 6301, 6299, 6300);
if (!(code)) { // conditional
etiss_coverage_count(2, 6303, 6302);
return;
etiss_coverage_count(1, 6304);
} // conditional
} // block
} // conditional
else { // conditional
code = 2LL;
etiss_coverage_count(2, 6309, 6307);
} // conditional
RV64IMACFD_raise(cpu, system, plugin_pointers, 0ULL, code);
etiss_coverage_count(1, 6312);
} // block
}

etiss_uint64 RV64IMACFD_calc_irq_mcause(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
{ // block
etiss_coverage_count(1, 6484);
etiss_uint64 pending_interrupts = *((RV64IMACFD*)cpu)->CSR[772LL] & *((RV64IMACFD*)cpu)->CSR[836LL];
etiss_coverage_count(2, 6322, 6321);
if (!(pending_interrupts)) { // conditional
etiss_coverage_count(2, 6324, 6323);
return 0ULL;
} // conditional
etiss_uint64 mie = RV64IMACFD_get_field(*((RV64IMACFD*)cpu)->CSR[768LL], 8LL);
etiss_coverage_count(2, 6333, 6332);
etiss_uint64 m_enabled = ((RV64IMACFD*)cpu)->PRIV < 3LL || (((RV64IMACFD*)cpu)->PRIV == 3LL && mie);
etiss_coverage_count(2, 6345, 6344);
etiss_uint64 enabled_interrupts = pending_interrupts & ~(*((RV64IMACFD*)cpu)->CSR[771LL]) & -(m_enabled);
etiss_coverage_count(2, 6356, 6355);
if (enabled_interrupts == 0ULL) { // conditional
etiss_coverage_count(2, 6358, 6357);
{ // block
etiss_coverage_count(1, 6390);
etiss_uint64 deleg = *((RV64IMACFD*)cpu)->CSR[771LL];
etiss_coverage_count(2, 6363, 6362);
etiss_uint64 sie = RV64IMACFD_get_field(RV64IMACFD_csr_read(cpu, system, plugin_pointers, 256LL), 2LL);
etiss_coverage_count(2, 6369, 6368);
etiss_uint64 s_enabled = ((RV64IMACFD*)cpu)->PRIV < 1LL || (((RV64IMACFD*)cpu)->PRIV == 1LL && sie);
etiss_coverage_count(2, 6381, 6380);
enabled_interrupts = pending_interrupts & deleg & -(s_enabled);
etiss_coverage_count(3, 6389, 6382, 6388);
} // block
} // conditional
if (enabled_interrupts) { // conditional
etiss_coverage_count(1, 6392);
{ // block
etiss_coverage_count(1, 6481);
if (enabled_interrupts >> 12ULL) { // conditional
etiss_coverage_count(2, 6397, 6393);
enabled_interrupts = enabled_interrupts >> 12ULL << 12ULL;
etiss_coverage_count(3, 6438, 6428, 6437);
} // conditional
 else if (enabled_interrupts & 2048LL) { // conditional
etiss_coverage_count(2, 6400, 6398);
enabled_interrupts = 2048LL;
etiss_coverage_count(2, 6441, 6439);
} // conditional
 else if (enabled_interrupts & 8LL) { // conditional
etiss_coverage_count(2, 6403, 6401);
enabled_interrupts = 8LL;
etiss_coverage_count(2, 6444, 6442);
} // conditional
 else if (enabled_interrupts & 128LL) { // conditional
etiss_coverage_count(2, 6406, 6404);
enabled_interrupts = 128LL;
etiss_coverage_count(2, 6447, 6445);
} // conditional
 else if (enabled_interrupts & 512LL) { // conditional
etiss_coverage_count(2, 6409, 6407);
enabled_interrupts = 512LL;
etiss_coverage_count(2, 6450, 6448);
} // conditional
 else if (enabled_interrupts & 2LL) { // conditional
etiss_coverage_count(2, 6412, 6410);
enabled_interrupts = 2LL;
etiss_coverage_count(2, 6453, 6451);
} // conditional
 else if (enabled_interrupts & 32LL) { // conditional
etiss_coverage_count(2, 6415, 6413);
enabled_interrupts = 32LL;
etiss_coverage_count(2, 6456, 6454);
} // conditional
 else if (enabled_interrupts & 8192LL) { // conditional
etiss_coverage_count(2, 6418, 6416);
enabled_interrupts = 8192LL;
etiss_coverage_count(2, 6459, 6457);
} // conditional
 else if (enabled_interrupts & 1024LL) { // conditional
etiss_coverage_count(2, 6421, 6419);
enabled_interrupts = 1024LL;
etiss_coverage_count(2, 6462, 6460);
} // conditional
 else if (enabled_interrupts & 4LL) { // conditional
etiss_coverage_count(2, 6424, 6422);
enabled_interrupts = 4LL;
etiss_coverage_count(2, 6465, 6463);
} // conditional
 else if (enabled_interrupts & 64LL) { // conditional
etiss_coverage_count(2, 6427, 6425);
enabled_interrupts = 64LL;
etiss_coverage_count(2, 6468, 6466);
} // conditional
else { // conditional
return 0ULL;
} // conditional
return 9223372036854775808ULL | RV64IMACFD_ctz(enabled_interrupts);
etiss_coverage_count(2, 6479, 6478);
} // block
} // conditional
return 0ULL;
} // block
}

void RV64IMACFD_check_irq(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
{
{ // block
etiss_coverage_count(1, 6492);
etiss_uint64 irq_mcause = RV64IMACFD_calc_irq_mcause(cpu, system, plugin_pointers);
etiss_coverage_count(2, 6487, 6486);
if (irq_mcause) { // conditional
etiss_coverage_count(1, 6488);
RV64IMACFD_raise(cpu, system, plugin_pointers, 1ULL, irq_mcause);
etiss_coverage_count(1, 6490);
} // conditional
} // block
}

etiss_int64 RV64IMACFD_mulh(etiss_int64 x, etiss_int64 y)
{
{ // block
etiss_coverage_count(1, 6506);
etiss_int128 res = (etiss_int128)(x) * (etiss_int128)(y);
etiss_coverage_count(2, 6499, 6498);
return (etiss_int64)((res >> 64ULL));
etiss_coverage_count(1, 6503);
} // block
}

etiss_int64 RV64IMACFD_mulhsu(etiss_int64 x, etiss_uint64 y)
{
{ // block
etiss_coverage_count(1, 6520);
etiss_int128 res = (etiss_int128)(x) * (etiss_uint128)(y);
etiss_coverage_count(2, 6513, 6512);
return (etiss_int64)((res >> 64ULL));
etiss_coverage_count(1, 6517);
} // block
}

etiss_uint64 RV64IMACFD_mulhu(etiss_uint64 x, etiss_uint64 y)
{
{ // block
etiss_coverage_count(1, 6534);
etiss_uint128 res = (etiss_uint128)(x) * (etiss_uint128)(y);
etiss_coverage_count(2, 6527, 6526);
return (etiss_uint64)((res >> 64ULL));
etiss_coverage_count(1, 6531);
} // block
}
