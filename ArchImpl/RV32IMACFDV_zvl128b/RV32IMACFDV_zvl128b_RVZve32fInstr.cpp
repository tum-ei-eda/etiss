// clang-format off
/**
 * Generated on Thu, 06 Aug 2026 12:56:16 +0200.
 *
 * This file contains the instruction behavior models of the RVZve32f
 * instruction set for the RV32IMACFDV_zvl128b core architecture.
 */

#include "RV32IMACFDV_zvl128bArch.h"
#include "RV32IMACFDV_zvl128bFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// VFADD_VV --------------------------------------------------------------------
static InstructionDefinition vfadd_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfadd_vv",
	(uint64_t) 0x001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFADD_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 426);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 22440);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 22367, 22366);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 22372, 22371);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 22377, 22376);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 22384, 22383, 22381, 22382);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 22390, 22389, 22386, 22387, 22388);\n";
cp.code() += "etiss_uint32 ret = vfadd_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 22403, 22402, 22392, 22393, 22394, 22395, 22396, 22397, 22398, 22399, 22400, 22401);\n";
cp.code() += "etiss_coverage_count(1, 22404);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 22407, 22405, 22406);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22418);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 22414, 22410, 22413, 22411, 22412);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 22417, 22415, 22416);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22424);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 22423, 22421, 22422);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 22427, 22426);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 22439, 22428, 22438, 22432, 22429, 22433, 22436, 22434, 22437);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFADD_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfadd_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFADD_VF --------------------------------------------------------------------
static InstructionDefinition vfadd_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfadd_vf",
	(uint64_t) 0x005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFADD_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 427);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 22520);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 22445, 22444);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 22450, 22449);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 22455, 22454);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 22462, 22461, 22459, 22460);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 22468, 22467, 22464, 22465, 22466);\n";
cp.code() += "etiss_uint32 ret = vfadd_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 22483, 22482, 22470, 22471, 22472, 22473, 22474, 22475, 22476, 22477, 22478, 22479, 22481);\n";
cp.code() += "etiss_coverage_count(1, 22484);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 22487, 22485, 22486);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22498);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 22494, 22490, 22493, 22491, 22492);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 22497, 22495, 22496);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22504);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 22503, 22501, 22502);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 22507, 22506);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 22519, 22508, 22518, 22512, 22509, 22513, 22516, 22514, 22517);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFADD_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfadd_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFSUB_VV --------------------------------------------------------------------
static InstructionDefinition vfsub_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfsub_vv",
	(uint64_t) 0x8001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFSUB_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 428);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 22598);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 22525, 22524);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 22530, 22529);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 22535, 22534);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 22542, 22541, 22539, 22540);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 22548, 22547, 22544, 22545, 22546);\n";
cp.code() += "etiss_uint32 ret = vfsub_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 22561, 22560, 22550, 22551, 22552, 22553, 22554, 22555, 22556, 22557, 22558, 22559);\n";
cp.code() += "etiss_coverage_count(1, 22562);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 22565, 22563, 22564);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22576);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 22572, 22568, 22571, 22569, 22570);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 22575, 22573, 22574);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22582);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 22581, 22579, 22580);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 22585, 22584);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 22597, 22586, 22596, 22590, 22587, 22591, 22594, 22592, 22595);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFSUB_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfsub_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFSUB_VF --------------------------------------------------------------------
static InstructionDefinition vfsub_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfsub_vf",
	(uint64_t) 0x8005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFSUB_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 429);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 22678);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 22603, 22602);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 22608, 22607);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 22613, 22612);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 22620, 22619, 22617, 22618);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 22626, 22625, 22622, 22623, 22624);\n";
cp.code() += "etiss_uint32 ret = vfsub_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 22641, 22640, 22628, 22629, 22630, 22631, 22632, 22633, 22634, 22635, 22636, 22637, 22639);\n";
cp.code() += "etiss_coverage_count(1, 22642);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 22645, 22643, 22644);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22656);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 22652, 22648, 22651, 22649, 22650);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 22655, 22653, 22654);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22662);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 22661, 22659, 22660);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 22665, 22664);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 22677, 22666, 22676, 22670, 22667, 22671, 22674, 22672, 22675);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFSUB_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfsub_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFRSUB_VF -------------------------------------------------------------------
static InstructionDefinition vfrsub_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfrsub_vf",
	(uint64_t) 0x9c005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFRSUB_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 430);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 22758);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 22683, 22682);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 22688, 22687);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 22693, 22692);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 22700, 22699, 22697, 22698);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 22706, 22705, 22702, 22703, 22704);\n";
cp.code() += "etiss_uint32 ret = vfrsub_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 22721, 22720, 22708, 22709, 22710, 22711, 22712, 22713, 22714, 22715, 22716, 22717, 22719);\n";
cp.code() += "etiss_coverage_count(1, 22722);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 22725, 22723, 22724);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22736);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 22732, 22728, 22731, 22729, 22730);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 22735, 22733, 22734);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22742);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 22741, 22739, 22740);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 22745, 22744);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 22757, 22746, 22756, 22750, 22747, 22751, 22754, 22752, 22755);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFRSUB_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfrsub_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWADD_VV -------------------------------------------------------------------
static InstructionDefinition vfwadd_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwadd_vv",
	(uint64_t) 0xc0001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWADD_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 431);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 22836);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 22763, 22762);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 22768, 22767);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 22773, 22772);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 22780, 22779, 22777, 22778);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 22786, 22785, 22782, 22783, 22784);\n";
cp.code() += "etiss_uint32 ret = vfwadd_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 22799, 22798, 22788, 22789, 22790, 22791, 22792, 22793, 22794, 22795, 22796, 22797);\n";
cp.code() += "etiss_coverage_count(1, 22800);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 22803, 22801, 22802);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22814);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 22810, 22806, 22809, 22807, 22808);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 22813, 22811, 22812);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22820);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 22819, 22817, 22818);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 22823, 22822);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 22835, 22824, 22834, 22828, 22825, 22829, 22832, 22830, 22833);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWADD_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwadd_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWADD_VF -------------------------------------------------------------------
static InstructionDefinition vfwadd_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwadd_vf",
	(uint64_t) 0xc0005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWADD_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 432);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 22916);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 22841, 22840);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 22846, 22845);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 22851, 22850);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 22858, 22857, 22855, 22856);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 22864, 22863, 22860, 22861, 22862);\n";
cp.code() += "etiss_uint32 ret = vfwadd_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 22879, 22878, 22866, 22867, 22868, 22869, 22870, 22871, 22872, 22873, 22874, 22875, 22877);\n";
cp.code() += "etiss_coverage_count(1, 22880);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 22883, 22881, 22882);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22894);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 22890, 22886, 22889, 22887, 22888);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 22893, 22891, 22892);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22900);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 22899, 22897, 22898);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 22903, 22902);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 22915, 22904, 22914, 22908, 22905, 22909, 22912, 22910, 22913);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWADD_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwadd_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWSUB_VV -------------------------------------------------------------------
static InstructionDefinition vfwsub_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwsub_vv",
	(uint64_t) 0xc8001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWSUB_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 433);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 22994);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 22921, 22920);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 22926, 22925);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 22931, 22930);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 22938, 22937, 22935, 22936);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 22944, 22943, 22940, 22941, 22942);\n";
cp.code() += "etiss_uint32 ret = vfwsub_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 22957, 22956, 22946, 22947, 22948, 22949, 22950, 22951, 22952, 22953, 22954, 22955);\n";
cp.code() += "etiss_coverage_count(1, 22958);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 22961, 22959, 22960);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22972);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 22968, 22964, 22967, 22965, 22966);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 22971, 22969, 22970);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 22978);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 22977, 22975, 22976);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 22981, 22980);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 22993, 22982, 22992, 22986, 22983, 22987, 22990, 22988, 22991);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWSUB_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwsub_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWSUB_VF -------------------------------------------------------------------
static InstructionDefinition vfwsub_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwsub_vf",
	(uint64_t) 0xc8005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWSUB_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 434);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23074);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 22999, 22998);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 23004, 23003);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 23009, 23008);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 23016, 23015, 23013, 23014);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 23022, 23021, 23018, 23019, 23020);\n";
cp.code() += "etiss_uint32 ret = vfwsub_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 23037, 23036, 23024, 23025, 23026, 23027, 23028, 23029, 23030, 23031, 23032, 23033, 23035);\n";
cp.code() += "etiss_coverage_count(1, 23038);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 23041, 23039, 23040);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23052);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 23048, 23044, 23047, 23045, 23046);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 23051, 23049, 23050);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23058);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 23057, 23055, 23056);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 23061, 23060);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 23073, 23062, 23072, 23066, 23063, 23067, 23070, 23068, 23071);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWSUB_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwsub_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWADD_WV -------------------------------------------------------------------
static InstructionDefinition vfwadd_wv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwadd_wv",
	(uint64_t) 0xd0001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWADD_WV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 435);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23152);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 23079, 23078);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 23084, 23083);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 23089, 23088);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 23096, 23095, 23093, 23094);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 23102, 23101, 23098, 23099, 23100);\n";
cp.code() += "etiss_uint32 ret = vfwadd_wv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 23115, 23114, 23104, 23105, 23106, 23107, 23108, 23109, 23110, 23111, 23112, 23113);\n";
cp.code() += "etiss_coverage_count(1, 23116);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 23119, 23117, 23118);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23130);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 23126, 23122, 23125, 23123, 23124);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 23129, 23127, 23128);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23136);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 23135, 23133, 23134);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 23139, 23138);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 23151, 23140, 23150, 23144, 23141, 23145, 23148, 23146, 23149);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWADD_WV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwadd_wv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWADD_WF -------------------------------------------------------------------
static InstructionDefinition vfwadd_wf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwadd_wf",
	(uint64_t) 0xd0005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWADD_WF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 436);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23232);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 23157, 23156);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 23162, 23161);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 23167, 23166);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 23174, 23173, 23171, 23172);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 23180, 23179, 23176, 23177, 23178);\n";
cp.code() += "etiss_uint32 ret = vfwadd_wf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 23195, 23194, 23182, 23183, 23184, 23185, 23186, 23187, 23188, 23189, 23190, 23191, 23193);\n";
cp.code() += "etiss_coverage_count(1, 23196);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 23199, 23197, 23198);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23210);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 23206, 23202, 23205, 23203, 23204);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 23209, 23207, 23208);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23216);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 23215, 23213, 23214);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 23219, 23218);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 23231, 23220, 23230, 23224, 23221, 23225, 23228, 23226, 23229);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWADD_WF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwadd_wf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWSUB_WV -------------------------------------------------------------------
static InstructionDefinition vfwsub_wv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwsub_wv",
	(uint64_t) 0xd8001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWSUB_WV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 437);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23310);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 23237, 23236);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 23242, 23241);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 23247, 23246);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 23254, 23253, 23251, 23252);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 23260, 23259, 23256, 23257, 23258);\n";
cp.code() += "etiss_uint32 ret = vfwsub_wv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 23273, 23272, 23262, 23263, 23264, 23265, 23266, 23267, 23268, 23269, 23270, 23271);\n";
cp.code() += "etiss_coverage_count(1, 23274);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 23277, 23275, 23276);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23288);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 23284, 23280, 23283, 23281, 23282);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 23287, 23285, 23286);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23294);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 23293, 23291, 23292);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 23297, 23296);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 23309, 23298, 23308, 23302, 23299, 23303, 23306, 23304, 23307);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWSUB_WV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwsub_wv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWSUB_WF -------------------------------------------------------------------
static InstructionDefinition vfwsub_wf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwsub_wf",
	(uint64_t) 0xd8005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWSUB_WF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 438);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23390);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 23315, 23314);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 23320, 23319);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 23325, 23324);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 23332, 23331, 23329, 23330);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 23338, 23337, 23334, 23335, 23336);\n";
cp.code() += "etiss_uint32 ret = vfwsub_wf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 23353, 23352, 23340, 23341, 23342, 23343, 23344, 23345, 23346, 23347, 23348, 23349, 23351);\n";
cp.code() += "etiss_coverage_count(1, 23354);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 23357, 23355, 23356);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23368);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 23364, 23360, 23363, 23361, 23362);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 23367, 23365, 23366);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23374);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 23373, 23371, 23372);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 23377, 23376);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 23389, 23378, 23388, 23382, 23379, 23383, 23386, 23384, 23387);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWSUB_WF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwsub_wf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMUL_VV --------------------------------------------------------------------
static InstructionDefinition vfmul_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfmul_vv",
	(uint64_t) 0x90001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMUL_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 439);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23468);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 23395, 23394);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 23400, 23399);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 23405, 23404);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 23412, 23411, 23409, 23410);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 23418, 23417, 23414, 23415, 23416);\n";
cp.code() += "etiss_uint32 ret = vfmul_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 23431, 23430, 23420, 23421, 23422, 23423, 23424, 23425, 23426, 23427, 23428, 23429);\n";
cp.code() += "etiss_coverage_count(1, 23432);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 23435, 23433, 23434);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23446);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 23442, 23438, 23441, 23439, 23440);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 23445, 23443, 23444);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23452);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 23451, 23449, 23450);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 23455, 23454);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 23467, 23456, 23466, 23460, 23457, 23461, 23464, 23462, 23465);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMUL_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmul_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMUL_VF --------------------------------------------------------------------
static InstructionDefinition vfmul_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfmul_vf",
	(uint64_t) 0x90005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMUL_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 440);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23548);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 23473, 23472);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 23478, 23477);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 23483, 23482);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 23490, 23489, 23487, 23488);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 23496, 23495, 23492, 23493, 23494);\n";
cp.code() += "etiss_uint32 ret = vfmul_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 23511, 23510, 23498, 23499, 23500, 23501, 23502, 23503, 23504, 23505, 23506, 23507, 23509);\n";
cp.code() += "etiss_coverage_count(1, 23512);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 23515, 23513, 23514);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23526);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 23522, 23518, 23521, 23519, 23520);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 23525, 23523, 23524);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23532);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 23531, 23529, 23530);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 23535, 23534);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 23547, 23536, 23546, 23540, 23537, 23541, 23544, 23542, 23545);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMUL_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmul_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFDIV_VV --------------------------------------------------------------------
static InstructionDefinition vfdiv_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfdiv_vv",
	(uint64_t) 0x80001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFDIV_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 441);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23626);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 23553, 23552);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 23558, 23557);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 23563, 23562);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 23570, 23569, 23567, 23568);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 23576, 23575, 23572, 23573, 23574);\n";
cp.code() += "etiss_uint32 ret = vfdiv_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 23589, 23588, 23578, 23579, 23580, 23581, 23582, 23583, 23584, 23585, 23586, 23587);\n";
cp.code() += "etiss_coverage_count(1, 23590);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 23593, 23591, 23592);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23604);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 23600, 23596, 23599, 23597, 23598);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 23603, 23601, 23602);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23610);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 23609, 23607, 23608);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 23613, 23612);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 23625, 23614, 23624, 23618, 23615, 23619, 23622, 23620, 23623);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFDIV_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfdiv_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFDIV_VF --------------------------------------------------------------------
static InstructionDefinition vfdiv_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfdiv_vf",
	(uint64_t) 0x80005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFDIV_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 442);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23706);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 23631, 23630);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 23636, 23635);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 23641, 23640);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 23648, 23647, 23645, 23646);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 23654, 23653, 23650, 23651, 23652);\n";
cp.code() += "etiss_uint32 ret = vfdiv_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 23669, 23668, 23656, 23657, 23658, 23659, 23660, 23661, 23662, 23663, 23664, 23665, 23667);\n";
cp.code() += "etiss_coverage_count(1, 23670);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 23673, 23671, 23672);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23684);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 23680, 23676, 23679, 23677, 23678);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 23683, 23681, 23682);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23690);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 23689, 23687, 23688);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 23693, 23692);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 23705, 23694, 23704, 23698, 23695, 23699, 23702, 23700, 23703);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFDIV_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfdiv_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFRDIV_VF -------------------------------------------------------------------
static InstructionDefinition vfrdiv_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfrdiv_vf",
	(uint64_t) 0x84005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFRDIV_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 443);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23786);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 23711, 23710);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 23716, 23715);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 23721, 23720);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 23728, 23727, 23725, 23726);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 23734, 23733, 23730, 23731, 23732);\n";
cp.code() += "etiss_uint32 ret = vfrdiv_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 23749, 23748, 23736, 23737, 23738, 23739, 23740, 23741, 23742, 23743, 23744, 23745, 23747);\n";
cp.code() += "etiss_coverage_count(1, 23750);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 23753, 23751, 23752);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23764);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 23760, 23756, 23759, 23757, 23758);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 23763, 23761, 23762);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23770);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 23769, 23767, 23768);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 23773, 23772);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 23785, 23774, 23784, 23778, 23775, 23779, 23782, 23780, 23783);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFRDIV_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfrdiv_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWMUL_VV -------------------------------------------------------------------
static InstructionDefinition vfwmul_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwmul_vv",
	(uint64_t) 0xe0001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWMUL_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 444);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23864);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 23791, 23790);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 23796, 23795);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 23801, 23800);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 23808, 23807, 23805, 23806);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 23814, 23813, 23810, 23811, 23812);\n";
cp.code() += "etiss_uint32 ret = vfwmul_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 23827, 23826, 23816, 23817, 23818, 23819, 23820, 23821, 23822, 23823, 23824, 23825);\n";
cp.code() += "etiss_coverage_count(1, 23828);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 23831, 23829, 23830);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23842);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 23838, 23834, 23837, 23835, 23836);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 23841, 23839, 23840);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23848);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 23847, 23845, 23846);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 23851, 23850);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 23863, 23852, 23862, 23856, 23853, 23857, 23860, 23858, 23861);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWMUL_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwmul_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWMUL_VF -------------------------------------------------------------------
static InstructionDefinition vfwmul_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwmul_vf",
	(uint64_t) 0xe0005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWMUL_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 445);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23944);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 23869, 23868);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 23874, 23873);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 23879, 23878);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 23886, 23885, 23883, 23884);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 23892, 23891, 23888, 23889, 23890);\n";
cp.code() += "etiss_uint32 ret = vfwmul_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 23907, 23906, 23894, 23895, 23896, 23897, 23898, 23899, 23900, 23901, 23902, 23903, 23905);\n";
cp.code() += "etiss_coverage_count(1, 23908);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 23911, 23909, 23910);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23922);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 23918, 23914, 23917, 23915, 23916);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 23921, 23919, 23920);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23928);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 23927, 23925, 23926);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 23931, 23930);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 23943, 23932, 23942, 23936, 23933, 23937, 23940, 23938, 23941);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWMUL_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwmul_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMACC_VV -------------------------------------------------------------------
static InstructionDefinition vfmacc_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfmacc_vv",
	(uint64_t) 0xb0001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMACC_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 446);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24022);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 23949, 23948);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 23954, 23953);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 23959, 23958);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 23966, 23965, 23963, 23964);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 23972, 23971, 23968, 23969, 23970);\n";
cp.code() += "etiss_uint32 ret = vfmacc_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 23985, 23984, 23974, 23975, 23976, 23977, 23978, 23979, 23980, 23981, 23982, 23983);\n";
cp.code() += "etiss_coverage_count(1, 23986);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 23989, 23987, 23988);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24000);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 23996, 23992, 23995, 23993, 23994);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 23999, 23997, 23998);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24006);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 24005, 24003, 24004);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 24009, 24008);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 24021, 24010, 24020, 24014, 24011, 24015, 24018, 24016, 24019);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMACC_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmacc_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMACC_VF -------------------------------------------------------------------
static InstructionDefinition vfmacc_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfmacc_vf",
	(uint64_t) 0xb0005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMACC_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 447);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24102);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 24027, 24026);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 24032, 24031);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 24037, 24036);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 24044, 24043, 24041, 24042);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 24050, 24049, 24046, 24047, 24048);\n";
cp.code() += "etiss_uint32 ret = vfmacc_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 24065, 24064, 24052, 24053, 24054, 24055, 24056, 24057, 24058, 24059, 24060, 24061, 24063);\n";
cp.code() += "etiss_coverage_count(1, 24066);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 24069, 24067, 24068);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24080);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 24076, 24072, 24075, 24073, 24074);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 24079, 24077, 24078);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24086);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 24085, 24083, 24084);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 24089, 24088);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 24101, 24090, 24100, 24094, 24091, 24095, 24098, 24096, 24099);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMACC_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmacc_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFNMACC_VV ------------------------------------------------------------------
static InstructionDefinition vfnmacc_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfnmacc_vv",
	(uint64_t) 0xb4001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFNMACC_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 448);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24180);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 24107, 24106);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 24112, 24111);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 24117, 24116);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 24124, 24123, 24121, 24122);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 24130, 24129, 24126, 24127, 24128);\n";
cp.code() += "etiss_uint32 ret = vfnmacc_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 24143, 24142, 24132, 24133, 24134, 24135, 24136, 24137, 24138, 24139, 24140, 24141);\n";
cp.code() += "etiss_coverage_count(1, 24144);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 24147, 24145, 24146);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24158);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 24154, 24150, 24153, 24151, 24152);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 24157, 24155, 24156);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24164);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 24163, 24161, 24162);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 24167, 24166);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 24179, 24168, 24178, 24172, 24169, 24173, 24176, 24174, 24177);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFNMACC_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfnmacc_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFNMACC_VF ------------------------------------------------------------------
static InstructionDefinition vfnmacc_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfnmacc_vf",
	(uint64_t) 0xb4005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFNMACC_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 449);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24260);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 24185, 24184);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 24190, 24189);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 24195, 24194);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 24202, 24201, 24199, 24200);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 24208, 24207, 24204, 24205, 24206);\n";
cp.code() += "etiss_uint32 ret = vfnmacc_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 24223, 24222, 24210, 24211, 24212, 24213, 24214, 24215, 24216, 24217, 24218, 24219, 24221);\n";
cp.code() += "etiss_coverage_count(1, 24224);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 24227, 24225, 24226);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24238);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 24234, 24230, 24233, 24231, 24232);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 24237, 24235, 24236);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24244);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 24243, 24241, 24242);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 24247, 24246);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 24259, 24248, 24258, 24252, 24249, 24253, 24256, 24254, 24257);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFNMACC_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfnmacc_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMSAC_VV -------------------------------------------------------------------
static InstructionDefinition vfmsac_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfmsac_vv",
	(uint64_t) 0xb8001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMSAC_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 450);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24338);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 24265, 24264);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 24270, 24269);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 24275, 24274);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 24282, 24281, 24279, 24280);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 24288, 24287, 24284, 24285, 24286);\n";
cp.code() += "etiss_uint32 ret = vfmsac_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 24301, 24300, 24290, 24291, 24292, 24293, 24294, 24295, 24296, 24297, 24298, 24299);\n";
cp.code() += "etiss_coverage_count(1, 24302);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 24305, 24303, 24304);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24316);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 24312, 24308, 24311, 24309, 24310);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 24315, 24313, 24314);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24322);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 24321, 24319, 24320);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 24325, 24324);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 24337, 24326, 24336, 24330, 24327, 24331, 24334, 24332, 24335);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMSAC_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmsac_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMSAC_VF -------------------------------------------------------------------
static InstructionDefinition vfmsac_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfmsac_vf",
	(uint64_t) 0xb8005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMSAC_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 451);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24418);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 24343, 24342);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 24348, 24347);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 24353, 24352);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 24360, 24359, 24357, 24358);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 24366, 24365, 24362, 24363, 24364);\n";
cp.code() += "etiss_uint32 ret = vfmsac_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 24381, 24380, 24368, 24369, 24370, 24371, 24372, 24373, 24374, 24375, 24376, 24377, 24379);\n";
cp.code() += "etiss_coverage_count(1, 24382);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 24385, 24383, 24384);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24396);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 24392, 24388, 24391, 24389, 24390);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 24395, 24393, 24394);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24402);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 24401, 24399, 24400);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 24405, 24404);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 24417, 24406, 24416, 24410, 24407, 24411, 24414, 24412, 24415);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMSAC_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmsac_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFNMSAC_VV ------------------------------------------------------------------
static InstructionDefinition vfnmsac_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfnmsac_vv",
	(uint64_t) 0xbc001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFNMSAC_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 452);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24496);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 24423, 24422);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 24428, 24427);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 24433, 24432);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 24440, 24439, 24437, 24438);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 24446, 24445, 24442, 24443, 24444);\n";
cp.code() += "etiss_uint32 ret = vfnmsac_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 24459, 24458, 24448, 24449, 24450, 24451, 24452, 24453, 24454, 24455, 24456, 24457);\n";
cp.code() += "etiss_coverage_count(1, 24460);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 24463, 24461, 24462);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24474);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 24470, 24466, 24469, 24467, 24468);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 24473, 24471, 24472);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24480);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 24479, 24477, 24478);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 24483, 24482);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 24495, 24484, 24494, 24488, 24485, 24489, 24492, 24490, 24493);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFNMSAC_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfnmsac_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFNMSAC_VF ------------------------------------------------------------------
static InstructionDefinition vfnmsac_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfnmsac_vf",
	(uint64_t) 0xbc005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFNMSAC_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 453);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24576);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 24501, 24500);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 24506, 24505);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 24511, 24510);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 24518, 24517, 24515, 24516);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 24524, 24523, 24520, 24521, 24522);\n";
cp.code() += "etiss_uint32 ret = vfnmsac_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 24539, 24538, 24526, 24527, 24528, 24529, 24530, 24531, 24532, 24533, 24534, 24535, 24537);\n";
cp.code() += "etiss_coverage_count(1, 24540);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 24543, 24541, 24542);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24554);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 24550, 24546, 24549, 24547, 24548);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 24553, 24551, 24552);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24560);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 24559, 24557, 24558);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 24563, 24562);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 24575, 24564, 24574, 24568, 24565, 24569, 24572, 24570, 24573);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFNMSAC_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfnmsac_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMADD_VV -------------------------------------------------------------------
static InstructionDefinition vfmadd_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfmadd_vv",
	(uint64_t) 0xa0001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMADD_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 454);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24654);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 24581, 24580);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 24586, 24585);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 24591, 24590);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 24598, 24597, 24595, 24596);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 24604, 24603, 24600, 24601, 24602);\n";
cp.code() += "etiss_uint32 ret = vfmadd_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 24617, 24616, 24606, 24607, 24608, 24609, 24610, 24611, 24612, 24613, 24614, 24615);\n";
cp.code() += "etiss_coverage_count(1, 24618);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 24621, 24619, 24620);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24632);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 24628, 24624, 24627, 24625, 24626);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 24631, 24629, 24630);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24638);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 24637, 24635, 24636);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 24641, 24640);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 24653, 24642, 24652, 24646, 24643, 24647, 24650, 24648, 24651);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMADD_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmadd_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMADD_VF -------------------------------------------------------------------
static InstructionDefinition vfmadd_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfmadd_vf",
	(uint64_t) 0xa0005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMADD_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 455);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24734);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 24659, 24658);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 24664, 24663);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 24669, 24668);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 24676, 24675, 24673, 24674);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 24682, 24681, 24678, 24679, 24680);\n";
cp.code() += "etiss_uint32 ret = vfmadd_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 24697, 24696, 24684, 24685, 24686, 24687, 24688, 24689, 24690, 24691, 24692, 24693, 24695);\n";
cp.code() += "etiss_coverage_count(1, 24698);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 24701, 24699, 24700);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24712);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 24708, 24704, 24707, 24705, 24706);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 24711, 24709, 24710);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24718);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 24717, 24715, 24716);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 24721, 24720);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 24733, 24722, 24732, 24726, 24723, 24727, 24730, 24728, 24731);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMADD_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmadd_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFNMADD_VV ------------------------------------------------------------------
static InstructionDefinition vfnmadd_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfnmadd_vv",
	(uint64_t) 0xa4001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFNMADD_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 456);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24812);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 24739, 24738);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 24744, 24743);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 24749, 24748);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 24756, 24755, 24753, 24754);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 24762, 24761, 24758, 24759, 24760);\n";
cp.code() += "etiss_uint32 ret = vfnmadd_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 24775, 24774, 24764, 24765, 24766, 24767, 24768, 24769, 24770, 24771, 24772, 24773);\n";
cp.code() += "etiss_coverage_count(1, 24776);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 24779, 24777, 24778);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24790);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 24786, 24782, 24785, 24783, 24784);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 24789, 24787, 24788);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24796);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 24795, 24793, 24794);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 24799, 24798);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 24811, 24800, 24810, 24804, 24801, 24805, 24808, 24806, 24809);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFNMADD_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfnmadd_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFNMADD_VF ------------------------------------------------------------------
static InstructionDefinition vfnmadd_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfnmadd_vf",
	(uint64_t) 0xa4005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFNMADD_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 457);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24892);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 24817, 24816);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 24822, 24821);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 24827, 24826);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 24834, 24833, 24831, 24832);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 24840, 24839, 24836, 24837, 24838);\n";
cp.code() += "etiss_uint32 ret = vfnmadd_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 24855, 24854, 24842, 24843, 24844, 24845, 24846, 24847, 24848, 24849, 24850, 24851, 24853);\n";
cp.code() += "etiss_coverage_count(1, 24856);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 24859, 24857, 24858);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24870);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 24866, 24862, 24865, 24863, 24864);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 24869, 24867, 24868);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24876);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 24875, 24873, 24874);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 24879, 24878);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 24891, 24880, 24890, 24884, 24881, 24885, 24888, 24886, 24889);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFNMADD_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfnmadd_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMSUB_VV -------------------------------------------------------------------
static InstructionDefinition vfmsub_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfmsub_vv",
	(uint64_t) 0xa8001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMSUB_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 458);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24970);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 24897, 24896);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 24902, 24901);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 24907, 24906);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 24914, 24913, 24911, 24912);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 24920, 24919, 24916, 24917, 24918);\n";
cp.code() += "etiss_uint32 ret = vfmsub_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 24933, 24932, 24922, 24923, 24924, 24925, 24926, 24927, 24928, 24929, 24930, 24931);\n";
cp.code() += "etiss_coverage_count(1, 24934);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 24937, 24935, 24936);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24948);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 24944, 24940, 24943, 24941, 24942);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 24947, 24945, 24946);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24954);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 24953, 24951, 24952);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 24957, 24956);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 24969, 24958, 24968, 24962, 24959, 24963, 24966, 24964, 24967);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMSUB_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmsub_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMSUB_VF -------------------------------------------------------------------
static InstructionDefinition vfmsub_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfmsub_vf",
	(uint64_t) 0xa8005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMSUB_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 459);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25050);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 24975, 24974);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 24980, 24979);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 24985, 24984);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 24992, 24991, 24989, 24990);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 24998, 24997, 24994, 24995, 24996);\n";
cp.code() += "etiss_uint32 ret = vfmsub_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 25013, 25012, 25000, 25001, 25002, 25003, 25004, 25005, 25006, 25007, 25008, 25009, 25011);\n";
cp.code() += "etiss_coverage_count(1, 25014);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 25017, 25015, 25016);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25028);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 25024, 25020, 25023, 25021, 25022);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 25027, 25025, 25026);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25034);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 25033, 25031, 25032);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 25037, 25036);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 25049, 25038, 25048, 25042, 25039, 25043, 25046, 25044, 25047);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMSUB_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmsub_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFNMSUB_VV ------------------------------------------------------------------
static InstructionDefinition vfnmsub_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfnmsub_vv",
	(uint64_t) 0xac001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFNMSUB_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 460);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25128);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 25055, 25054);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 25060, 25059);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 25065, 25064);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 25072, 25071, 25069, 25070);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 25078, 25077, 25074, 25075, 25076);\n";
cp.code() += "etiss_uint32 ret = vfnmsub_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 25091, 25090, 25080, 25081, 25082, 25083, 25084, 25085, 25086, 25087, 25088, 25089);\n";
cp.code() += "etiss_coverage_count(1, 25092);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 25095, 25093, 25094);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25106);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 25102, 25098, 25101, 25099, 25100);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 25105, 25103, 25104);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25112);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 25111, 25109, 25110);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 25115, 25114);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 25127, 25116, 25126, 25120, 25117, 25121, 25124, 25122, 25125);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFNMSUB_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfnmsub_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFNMSUB_VF ------------------------------------------------------------------
static InstructionDefinition vfnmsub_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfnmsub_vf",
	(uint64_t) 0xac005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFNMSUB_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 461);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25208);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 25133, 25132);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 25138, 25137);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 25143, 25142);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 25150, 25149, 25147, 25148);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 25156, 25155, 25152, 25153, 25154);\n";
cp.code() += "etiss_uint32 ret = vfnmsub_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 25171, 25170, 25158, 25159, 25160, 25161, 25162, 25163, 25164, 25165, 25166, 25167, 25169);\n";
cp.code() += "etiss_coverage_count(1, 25172);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 25175, 25173, 25174);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25186);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 25182, 25178, 25181, 25179, 25180);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 25185, 25183, 25184);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25192);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 25191, 25189, 25190);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 25195, 25194);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 25207, 25196, 25206, 25200, 25197, 25201, 25204, 25202, 25205);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFNMSUB_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfnmsub_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWMACC_VV ------------------------------------------------------------------
static InstructionDefinition vfwmacc_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwmacc_vv",
	(uint64_t) 0xf0001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWMACC_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 462);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25286);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 25213, 25212);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 25218, 25217);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 25223, 25222);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 25230, 25229, 25227, 25228);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 25236, 25235, 25232, 25233, 25234);\n";
cp.code() += "etiss_uint32 ret = vfwmacc_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 25249, 25248, 25238, 25239, 25240, 25241, 25242, 25243, 25244, 25245, 25246, 25247);\n";
cp.code() += "etiss_coverage_count(1, 25250);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 25253, 25251, 25252);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25264);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 25260, 25256, 25259, 25257, 25258);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 25263, 25261, 25262);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25270);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 25269, 25267, 25268);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 25273, 25272);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 25285, 25274, 25284, 25278, 25275, 25279, 25282, 25280, 25283);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWMACC_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwmacc_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWMACC_VF ------------------------------------------------------------------
static InstructionDefinition vfwmacc_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwmacc_vf",
	(uint64_t) 0xf0005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWMACC_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 463);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25366);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 25291, 25290);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 25296, 25295);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 25301, 25300);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 25308, 25307, 25305, 25306);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 25314, 25313, 25310, 25311, 25312);\n";
cp.code() += "etiss_uint32 ret = vfwmacc_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 25329, 25328, 25316, 25317, 25318, 25319, 25320, 25321, 25322, 25323, 25324, 25325, 25327);\n";
cp.code() += "etiss_coverage_count(1, 25330);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 25333, 25331, 25332);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25344);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 25340, 25336, 25339, 25337, 25338);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 25343, 25341, 25342);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25350);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 25349, 25347, 25348);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 25353, 25352);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 25365, 25354, 25364, 25358, 25355, 25359, 25362, 25360, 25363);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWMACC_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwmacc_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWNMACC_VV -----------------------------------------------------------------
static InstructionDefinition vfwnmacc_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwnmacc_vv",
	(uint64_t) 0xf4001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWNMACC_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 464);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25444);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 25371, 25370);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 25376, 25375);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 25381, 25380);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 25388, 25387, 25385, 25386);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 25394, 25393, 25390, 25391, 25392);\n";
cp.code() += "etiss_uint32 ret = vfwnmacc_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 25407, 25406, 25396, 25397, 25398, 25399, 25400, 25401, 25402, 25403, 25404, 25405);\n";
cp.code() += "etiss_coverage_count(1, 25408);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 25411, 25409, 25410);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25422);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 25418, 25414, 25417, 25415, 25416);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 25421, 25419, 25420);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25428);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 25427, 25425, 25426);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 25431, 25430);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 25443, 25432, 25442, 25436, 25433, 25437, 25440, 25438, 25441);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWNMACC_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwnmacc_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWNMACC_VF -----------------------------------------------------------------
static InstructionDefinition vfwnmacc_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwnmacc_vf",
	(uint64_t) 0xf4005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWNMACC_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 465);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25524);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 25449, 25448);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 25454, 25453);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 25459, 25458);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 25466, 25465, 25463, 25464);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 25472, 25471, 25468, 25469, 25470);\n";
cp.code() += "etiss_uint32 ret = vfwnmacc_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 25487, 25486, 25474, 25475, 25476, 25477, 25478, 25479, 25480, 25481, 25482, 25483, 25485);\n";
cp.code() += "etiss_coverage_count(1, 25488);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 25491, 25489, 25490);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25502);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 25498, 25494, 25497, 25495, 25496);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 25501, 25499, 25500);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25508);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 25507, 25505, 25506);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 25511, 25510);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 25523, 25512, 25522, 25516, 25513, 25517, 25520, 25518, 25521);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWNMACC_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwnmacc_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWMSAC_VV ------------------------------------------------------------------
static InstructionDefinition vfwmsac_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwmsac_vv",
	(uint64_t) 0xf8001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWMSAC_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 466);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25602);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 25529, 25528);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 25534, 25533);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 25539, 25538);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 25546, 25545, 25543, 25544);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 25552, 25551, 25548, 25549, 25550);\n";
cp.code() += "etiss_uint32 ret = vfwmsac_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 25565, 25564, 25554, 25555, 25556, 25557, 25558, 25559, 25560, 25561, 25562, 25563);\n";
cp.code() += "etiss_coverage_count(1, 25566);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 25569, 25567, 25568);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25580);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 25576, 25572, 25575, 25573, 25574);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 25579, 25577, 25578);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25586);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 25585, 25583, 25584);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 25589, 25588);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 25601, 25590, 25600, 25594, 25591, 25595, 25598, 25596, 25599);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWMSAC_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwmsac_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWMSAC_VF ------------------------------------------------------------------
static InstructionDefinition vfwmsac_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwmsac_vf",
	(uint64_t) 0xf8005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWMSAC_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 467);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25682);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 25607, 25606);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 25612, 25611);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 25617, 25616);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 25624, 25623, 25621, 25622);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 25630, 25629, 25626, 25627, 25628);\n";
cp.code() += "etiss_uint32 ret = vfwmsac_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 25645, 25644, 25632, 25633, 25634, 25635, 25636, 25637, 25638, 25639, 25640, 25641, 25643);\n";
cp.code() += "etiss_coverage_count(1, 25646);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 25649, 25647, 25648);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25660);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 25656, 25652, 25655, 25653, 25654);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 25659, 25657, 25658);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25666);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 25665, 25663, 25664);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 25669, 25668);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 25681, 25670, 25680, 25674, 25671, 25675, 25678, 25676, 25679);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWMSAC_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwmsac_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWNMSAC_VV -----------------------------------------------------------------
static InstructionDefinition vfwnmsac_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwnmsac_vv",
	(uint64_t) 0xfc001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWNMSAC_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 468);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25760);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 25687, 25686);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 25692, 25691);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 25697, 25696);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 25704, 25703, 25701, 25702);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 25710, 25709, 25706, 25707, 25708);\n";
cp.code() += "etiss_uint32 ret = vfwnmsac_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 25723, 25722, 25712, 25713, 25714, 25715, 25716, 25717, 25718, 25719, 25720, 25721);\n";
cp.code() += "etiss_coverage_count(1, 25724);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 25727, 25725, 25726);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25738);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 25734, 25730, 25733, 25731, 25732);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 25737, 25735, 25736);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25744);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 25743, 25741, 25742);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 25747, 25746);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 25759, 25748, 25758, 25752, 25749, 25753, 25756, 25754, 25757);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWNMSAC_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwnmsac_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWNMSAC_VF -----------------------------------------------------------------
static InstructionDefinition vfwnmsac_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwnmsac_vf",
	(uint64_t) 0xfc005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWNMSAC_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 469);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25840);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 25765, 25764);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 25770, 25769);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 25775, 25774);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 25782, 25781, 25779, 25780);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 25788, 25787, 25784, 25785, 25786);\n";
cp.code() += "etiss_uint32 ret = vfwnmsac_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 25803, 25802, 25790, 25791, 25792, 25793, 25794, 25795, 25796, 25797, 25798, 25799, 25801);\n";
cp.code() += "etiss_coverage_count(1, 25804);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 25807, 25805, 25806);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25818);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 25814, 25810, 25813, 25811, 25812);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 25817, 25815, 25816);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25824);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 25823, 25821, 25822);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 25827, 25826);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 25839, 25828, 25838, 25832, 25829, 25833, 25836, 25834, 25837);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWNMSAC_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwnmsac_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFSQRT_V --------------------------------------------------------------------
static InstructionDefinition vfsqrt_v_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfsqrt_v",
	(uint64_t) 0x4c001057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFSQRT_V\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 470);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25917);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 25845, 25844);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 25850, 25849);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 25855, 25854);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 25862, 25861, 25859, 25860);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 25868, 25867, 25864, 25865, 25866);\n";
cp.code() += "etiss_uint32 ret = vfsqrt_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 25880, 25879, 25870, 25871, 25872, 25873, 25874, 25875, 25876, 25877, 25878);\n";
cp.code() += "etiss_coverage_count(1, 25881);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 25884, 25882, 25883);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25895);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 25891, 25887, 25890, 25888, 25889);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 25894, 25892, 25893);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25901);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 25900, 25898, 25899);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 25904, 25903);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 25916, 25905, 25915, 25909, 25906, 25910, 25913, 25911, 25914);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFSQRT_V\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfsqrt_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFRSQRT7_V ------------------------------------------------------------------
static InstructionDefinition vfrsqrt7_v_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfrsqrt7_v",
	(uint64_t) 0x4c021057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFRSQRT7_V\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 471);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25994);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 25922, 25921);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 25927, 25926);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 25932, 25931);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 25939, 25938, 25936, 25937);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 25945, 25944, 25941, 25942, 25943);\n";
cp.code() += "etiss_uint32 ret = vfrsqrt7_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 25957, 25956, 25947, 25948, 25949, 25950, 25951, 25952, 25953, 25954, 25955);\n";
cp.code() += "etiss_coverage_count(1, 25958);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 25961, 25959, 25960);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25972);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 25968, 25964, 25967, 25965, 25966);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 25971, 25969, 25970);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25978);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 25977, 25975, 25976);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 25981, 25980);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 25993, 25982, 25992, 25986, 25983, 25987, 25990, 25988, 25991);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFRSQRT7_V\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfrsqrt7_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFREC7_V --------------------------------------------------------------------
static InstructionDefinition vfrec7_v_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfrec7_v",
	(uint64_t) 0x4c029057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFREC7_V\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 472);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26071);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 25999, 25998);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 26004, 26003);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 26009, 26008);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 26016, 26015, 26013, 26014);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 26022, 26021, 26018, 26019, 26020);\n";
cp.code() += "etiss_uint32 ret = vfrec7_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 26034, 26033, 26024, 26025, 26026, 26027, 26028, 26029, 26030, 26031, 26032);\n";
cp.code() += "etiss_coverage_count(1, 26035);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 26038, 26036, 26037);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26049);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 26045, 26041, 26044, 26042, 26043);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 26048, 26046, 26047);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26055);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 26054, 26052, 26053);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 26058, 26057);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 26070, 26059, 26069, 26063, 26060, 26064, 26067, 26065, 26068);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFREC7_V\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfrec7_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMIN_VV --------------------------------------------------------------------
static InstructionDefinition vfmin_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfmin_vv",
	(uint64_t) 0x10001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMIN_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 473);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26149);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 26076, 26075);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 26081, 26080);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 26086, 26085);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 26093, 26092, 26090, 26091);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 26099, 26098, 26095, 26096, 26097);\n";
cp.code() += "etiss_uint32 ret = vfmin_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 26112, 26111, 26101, 26102, 26103, 26104, 26105, 26106, 26107, 26108, 26109, 26110);\n";
cp.code() += "etiss_coverage_count(1, 26113);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 26116, 26114, 26115);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26127);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 26123, 26119, 26122, 26120, 26121);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 26126, 26124, 26125);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26133);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 26132, 26130, 26131);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 26136, 26135);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 26148, 26137, 26147, 26141, 26138, 26142, 26145, 26143, 26146);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMIN_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmin_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMIN_VF --------------------------------------------------------------------
static InstructionDefinition vfmin_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfmin_vf",
	(uint64_t) 0x10005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMIN_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 474);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26229);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 26154, 26153);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 26159, 26158);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 26164, 26163);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 26171, 26170, 26168, 26169);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 26177, 26176, 26173, 26174, 26175);\n";
cp.code() += "etiss_uint32 ret = vfmin_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 26192, 26191, 26179, 26180, 26181, 26182, 26183, 26184, 26185, 26186, 26187, 26188, 26190);\n";
cp.code() += "etiss_coverage_count(1, 26193);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 26196, 26194, 26195);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26207);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 26203, 26199, 26202, 26200, 26201);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 26206, 26204, 26205);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26213);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 26212, 26210, 26211);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 26216, 26215);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 26228, 26217, 26227, 26221, 26218, 26222, 26225, 26223, 26226);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMIN_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmin_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMAX_VV --------------------------------------------------------------------
static InstructionDefinition vfmax_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfmax_vv",
	(uint64_t) 0x18001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMAX_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 475);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26307);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 26234, 26233);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 26239, 26238);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 26244, 26243);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 26251, 26250, 26248, 26249);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 26257, 26256, 26253, 26254, 26255);\n";
cp.code() += "etiss_uint32 ret = vfmax_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 26270, 26269, 26259, 26260, 26261, 26262, 26263, 26264, 26265, 26266, 26267, 26268);\n";
cp.code() += "etiss_coverage_count(1, 26271);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 26274, 26272, 26273);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26285);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 26281, 26277, 26280, 26278, 26279);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 26284, 26282, 26283);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26291);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 26290, 26288, 26289);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 26294, 26293);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 26306, 26295, 26305, 26299, 26296, 26300, 26303, 26301, 26304);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMAX_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmax_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMAX_VF --------------------------------------------------------------------
static InstructionDefinition vfmax_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfmax_vf",
	(uint64_t) 0x18005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMAX_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 476);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26387);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 26312, 26311);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 26317, 26316);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 26322, 26321);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 26329, 26328, 26326, 26327);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 26335, 26334, 26331, 26332, 26333);\n";
cp.code() += "etiss_uint32 ret = vfmax_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 26350, 26349, 26337, 26338, 26339, 26340, 26341, 26342, 26343, 26344, 26345, 26346, 26348);\n";
cp.code() += "etiss_coverage_count(1, 26351);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 26354, 26352, 26353);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26365);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 26361, 26357, 26360, 26358, 26359);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 26364, 26362, 26363);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26371);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 26370, 26368, 26369);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 26374, 26373);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 26386, 26375, 26385, 26379, 26376, 26380, 26383, 26381, 26384);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMAX_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmax_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFSGNJ_VV -------------------------------------------------------------------
static InstructionDefinition vfsgnj_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfsgnj_vv",
	(uint64_t) 0x20001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFSGNJ_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 477);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26465);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 26392, 26391);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 26397, 26396);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 26402, 26401);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 26409, 26408, 26406, 26407);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 26415, 26414, 26411, 26412, 26413);\n";
cp.code() += "etiss_uint32 ret = vfsgnj_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 26428, 26427, 26417, 26418, 26419, 26420, 26421, 26422, 26423, 26424, 26425, 26426);\n";
cp.code() += "etiss_coverage_count(1, 26429);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 26432, 26430, 26431);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26443);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 26439, 26435, 26438, 26436, 26437);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 26442, 26440, 26441);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26449);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 26448, 26446, 26447);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 26452, 26451);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 26464, 26453, 26463, 26457, 26454, 26458, 26461, 26459, 26462);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFSGNJ_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfsgnj_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFSGNJ_VF -------------------------------------------------------------------
static InstructionDefinition vfsgnj_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfsgnj_vf",
	(uint64_t) 0x20005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFSGNJ_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 478);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26545);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 26470, 26469);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 26475, 26474);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 26480, 26479);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 26487, 26486, 26484, 26485);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 26493, 26492, 26489, 26490, 26491);\n";
cp.code() += "etiss_uint32 ret = vfsgnj_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 26508, 26507, 26495, 26496, 26497, 26498, 26499, 26500, 26501, 26502, 26503, 26504, 26506);\n";
cp.code() += "etiss_coverage_count(1, 26509);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 26512, 26510, 26511);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26523);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 26519, 26515, 26518, 26516, 26517);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 26522, 26520, 26521);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26529);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 26528, 26526, 26527);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 26532, 26531);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 26544, 26533, 26543, 26537, 26534, 26538, 26541, 26539, 26542);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFSGNJ_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfsgnj_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFSGNJN_VV ------------------------------------------------------------------
static InstructionDefinition vfsgnjn_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfsgnjn_vv",
	(uint64_t) 0x24001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFSGNJN_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 479);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26623);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 26550, 26549);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 26555, 26554);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 26560, 26559);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 26567, 26566, 26564, 26565);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 26573, 26572, 26569, 26570, 26571);\n";
cp.code() += "etiss_uint32 ret = vfsgnjn_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 26586, 26585, 26575, 26576, 26577, 26578, 26579, 26580, 26581, 26582, 26583, 26584);\n";
cp.code() += "etiss_coverage_count(1, 26587);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 26590, 26588, 26589);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26601);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 26597, 26593, 26596, 26594, 26595);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 26600, 26598, 26599);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26607);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 26606, 26604, 26605);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 26610, 26609);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 26622, 26611, 26621, 26615, 26612, 26616, 26619, 26617, 26620);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFSGNJN_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfsgnjn_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFSGNJN_VF ------------------------------------------------------------------
static InstructionDefinition vfsgnjn_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfsgnjn_vf",
	(uint64_t) 0x24005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFSGNJN_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 480);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26703);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 26628, 26627);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 26633, 26632);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 26638, 26637);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 26645, 26644, 26642, 26643);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 26651, 26650, 26647, 26648, 26649);\n";
cp.code() += "etiss_uint32 ret = vfsgnjn_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 26666, 26665, 26653, 26654, 26655, 26656, 26657, 26658, 26659, 26660, 26661, 26662, 26664);\n";
cp.code() += "etiss_coverage_count(1, 26667);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 26670, 26668, 26669);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26681);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 26677, 26673, 26676, 26674, 26675);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 26680, 26678, 26679);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26687);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 26686, 26684, 26685);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 26690, 26689);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 26702, 26691, 26701, 26695, 26692, 26696, 26699, 26697, 26700);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFSGNJN_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfsgnjn_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFSGNJX_VV ------------------------------------------------------------------
static InstructionDefinition vfsgnjx_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfsgnjx_vv",
	(uint64_t) 0x28001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFSGNJX_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 481);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26781);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 26708, 26707);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 26713, 26712);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 26718, 26717);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 26725, 26724, 26722, 26723);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 26731, 26730, 26727, 26728, 26729);\n";
cp.code() += "etiss_uint32 ret = vfsgnjx_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 26744, 26743, 26733, 26734, 26735, 26736, 26737, 26738, 26739, 26740, 26741, 26742);\n";
cp.code() += "etiss_coverage_count(1, 26745);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 26748, 26746, 26747);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26759);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 26755, 26751, 26754, 26752, 26753);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 26758, 26756, 26757);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26765);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 26764, 26762, 26763);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 26768, 26767);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 26780, 26769, 26779, 26773, 26770, 26774, 26777, 26775, 26778);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFSGNJX_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfsgnjx_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFSGNJX_VF ------------------------------------------------------------------
static InstructionDefinition vfsgnjx_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfsgnjx_vf",
	(uint64_t) 0x28005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFSGNJX_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 482);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26861);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 26786, 26785);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 26791, 26790);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 26796, 26795);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 26803, 26802, 26800, 26801);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 26809, 26808, 26805, 26806, 26807);\n";
cp.code() += "etiss_uint32 ret = vfsgnjx_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 26824, 26823, 26811, 26812, 26813, 26814, 26815, 26816, 26817, 26818, 26819, 26820, 26822);\n";
cp.code() += "etiss_coverage_count(1, 26825);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 26828, 26826, 26827);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26839);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 26835, 26831, 26834, 26832, 26833);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 26838, 26836, 26837);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26845);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 26844, 26842, 26843);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 26848, 26847);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 26860, 26849, 26859, 26853, 26850, 26854, 26857, 26855, 26858);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFSGNJX_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfsgnjx_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMFEQ_VV --------------------------------------------------------------------
static InstructionDefinition vmfeq_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vmfeq_vv",
	(uint64_t) 0x60001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VMFEQ_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 483);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26939);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 26866, 26865);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 26871, 26870);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 26876, 26875);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 26883, 26882, 26880, 26881);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 26889, 26888, 26885, 26886, 26887);\n";
cp.code() += "etiss_uint32 ret = vmfeq_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 26902, 26901, 26891, 26892, 26893, 26894, 26895, 26896, 26897, 26898, 26899, 26900);\n";
cp.code() += "etiss_coverage_count(1, 26903);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 26906, 26904, 26905);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26917);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 26913, 26909, 26912, 26910, 26911);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 26916, 26914, 26915);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26923);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 26922, 26920, 26921);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 26926, 26925);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 26938, 26927, 26937, 26931, 26928, 26932, 26935, 26933, 26936);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VMFEQ_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmfeq_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMFEQ_VF --------------------------------------------------------------------
static InstructionDefinition vmfeq_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vmfeq_vf",
	(uint64_t) 0x60005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VMFEQ_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 484);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27019);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 26944, 26943);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 26949, 26948);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 26954, 26953);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 26961, 26960, 26958, 26959);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 26967, 26966, 26963, 26964, 26965);\n";
cp.code() += "etiss_uint32 ret = vmfeq_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 26982, 26981, 26969, 26970, 26971, 26972, 26973, 26974, 26975, 26976, 26977, 26978, 26980);\n";
cp.code() += "etiss_coverage_count(1, 26983);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 26986, 26984, 26985);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 26997);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 26993, 26989, 26992, 26990, 26991);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 26996, 26994, 26995);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27003);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 27002, 27000, 27001);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 27006, 27005);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 27018, 27007, 27017, 27011, 27008, 27012, 27015, 27013, 27016);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VMFEQ_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmfeq_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMFNE_VV --------------------------------------------------------------------
static InstructionDefinition vmfne_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vmfne_vv",
	(uint64_t) 0x70001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VMFNE_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 485);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27097);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27024, 27023);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27029, 27028);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 27034, 27033);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 27041, 27040, 27038, 27039);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 27047, 27046, 27043, 27044, 27045);\n";
cp.code() += "etiss_uint32 ret = vmfne_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 27060, 27059, 27049, 27050, 27051, 27052, 27053, 27054, 27055, 27056, 27057, 27058);\n";
cp.code() += "etiss_coverage_count(1, 27061);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 27064, 27062, 27063);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27075);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 27071, 27067, 27070, 27068, 27069);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 27074, 27072, 27073);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27081);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 27080, 27078, 27079);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 27084, 27083);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 27096, 27085, 27095, 27089, 27086, 27090, 27093, 27091, 27094);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VMFNE_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmfne_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMFNE_VF --------------------------------------------------------------------
static InstructionDefinition vmfne_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vmfne_vf",
	(uint64_t) 0x70005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VMFNE_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 486);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27177);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27102, 27101);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27107, 27106);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 27112, 27111);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 27119, 27118, 27116, 27117);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 27125, 27124, 27121, 27122, 27123);\n";
cp.code() += "etiss_uint32 ret = vmfne_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 27140, 27139, 27127, 27128, 27129, 27130, 27131, 27132, 27133, 27134, 27135, 27136, 27138);\n";
cp.code() += "etiss_coverage_count(1, 27141);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 27144, 27142, 27143);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27155);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 27151, 27147, 27150, 27148, 27149);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 27154, 27152, 27153);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27161);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 27160, 27158, 27159);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 27164, 27163);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 27176, 27165, 27175, 27169, 27166, 27170, 27173, 27171, 27174);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VMFNE_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmfne_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMFLT_VV --------------------------------------------------------------------
static InstructionDefinition vmflt_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vmflt_vv",
	(uint64_t) 0x6c001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VMFLT_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 487);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27255);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27182, 27181);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27187, 27186);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 27192, 27191);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 27199, 27198, 27196, 27197);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 27205, 27204, 27201, 27202, 27203);\n";
cp.code() += "etiss_uint32 ret = vmflt_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 27218, 27217, 27207, 27208, 27209, 27210, 27211, 27212, 27213, 27214, 27215, 27216);\n";
cp.code() += "etiss_coverage_count(1, 27219);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 27222, 27220, 27221);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27233);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 27229, 27225, 27228, 27226, 27227);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 27232, 27230, 27231);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27239);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 27238, 27236, 27237);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 27242, 27241);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 27254, 27243, 27253, 27247, 27244, 27248, 27251, 27249, 27252);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VMFLT_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmflt_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMFLT_VF --------------------------------------------------------------------
static InstructionDefinition vmflt_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vmflt_vf",
	(uint64_t) 0x6c005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VMFLT_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 488);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27335);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27260, 27259);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27265, 27264);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 27270, 27269);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 27277, 27276, 27274, 27275);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 27283, 27282, 27279, 27280, 27281);\n";
cp.code() += "etiss_uint32 ret = vmflt_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 27298, 27297, 27285, 27286, 27287, 27288, 27289, 27290, 27291, 27292, 27293, 27294, 27296);\n";
cp.code() += "etiss_coverage_count(1, 27299);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 27302, 27300, 27301);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27313);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 27309, 27305, 27308, 27306, 27307);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 27312, 27310, 27311);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27319);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 27318, 27316, 27317);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 27322, 27321);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 27334, 27323, 27333, 27327, 27324, 27328, 27331, 27329, 27332);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VMFLT_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmflt_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMFLE_VV --------------------------------------------------------------------
static InstructionDefinition vmfle_vv_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vmfle_vv",
	(uint64_t) 0x64001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VMFLE_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 489);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27413);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27340, 27339);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27345, 27344);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 27350, 27349);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 27357, 27356, 27354, 27355);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 27363, 27362, 27359, 27360, 27361);\n";
cp.code() += "etiss_uint32 ret = vmfle_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 27376, 27375, 27365, 27366, 27367, 27368, 27369, 27370, 27371, 27372, 27373, 27374);\n";
cp.code() += "etiss_coverage_count(1, 27377);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 27380, 27378, 27379);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27391);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 27387, 27383, 27386, 27384, 27385);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 27390, 27388, 27389);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27397);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 27396, 27394, 27395);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 27400, 27399);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 27412, 27401, 27411, 27405, 27402, 27406, 27409, 27407, 27410);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VMFLE_VV\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmfle_vv" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMFLE_VF --------------------------------------------------------------------
static InstructionDefinition vmfle_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vmfle_vf",
	(uint64_t) 0x64005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VMFLE_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 490);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27493);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27418, 27417);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27423, 27422);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 27428, 27427);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 27435, 27434, 27432, 27433);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 27441, 27440, 27437, 27438, 27439);\n";
cp.code() += "etiss_uint32 ret = vmfle_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 27456, 27455, 27443, 27444, 27445, 27446, 27447, 27448, 27449, 27450, 27451, 27452, 27454);\n";
cp.code() += "etiss_coverage_count(1, 27457);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 27460, 27458, 27459);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27471);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 27467, 27463, 27466, 27464, 27465);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 27470, 27468, 27469);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27477);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 27476, 27474, 27475);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 27480, 27479);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 27492, 27481, 27491, 27485, 27482, 27486, 27489, 27487, 27490);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VMFLE_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmfle_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMFGT_VF --------------------------------------------------------------------
static InstructionDefinition vmfgt_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vmfgt_vf",
	(uint64_t) 0x74005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VMFGT_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 491);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27573);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27498, 27497);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27503, 27502);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 27508, 27507);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 27515, 27514, 27512, 27513);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 27521, 27520, 27517, 27518, 27519);\n";
cp.code() += "etiss_uint32 ret = vmfgt_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 27536, 27535, 27523, 27524, 27525, 27526, 27527, 27528, 27529, 27530, 27531, 27532, 27534);\n";
cp.code() += "etiss_coverage_count(1, 27537);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 27540, 27538, 27539);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27551);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 27547, 27543, 27546, 27544, 27545);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 27550, 27548, 27549);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27557);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 27556, 27554, 27555);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 27560, 27559);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 27572, 27561, 27571, 27565, 27562, 27566, 27569, 27567, 27570);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VMFGT_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmfgt_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VMFGE_VF --------------------------------------------------------------------
static InstructionDefinition vmfge_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vmfge_vf",
	(uint64_t) 0x7c005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VMFGE_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 492);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27653);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27578, 27577);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27583, 27582);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 27588, 27587);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 27595, 27594, 27592, 27593);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 27601, 27600, 27597, 27598, 27599);\n";
cp.code() += "etiss_uint32 ret = vmfge_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 27616, 27615, 27603, 27604, 27605, 27606, 27607, 27608, 27609, 27610, 27611, 27612, 27614);\n";
cp.code() += "etiss_coverage_count(1, 27617);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 27620, 27618, 27619);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27631);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 27627, 27623, 27626, 27624, 27625);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 27630, 27628, 27629);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27637);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 27636, 27634, 27635);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 27640, 27639);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 27652, 27641, 27651, 27645, 27642, 27646, 27649, 27647, 27650);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VMFGE_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vmfge_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFCLASS_V -------------------------------------------------------------------
static InstructionDefinition vfclass_v_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfclass_v",
	(uint64_t) 0x4c081057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFCLASS_V\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 493);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27730);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27658, 27657);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27663, 27662);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 27668, 27667);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 27675, 27674, 27672, 27673);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 27681, 27680, 27677, 27678, 27679);\n";
cp.code() += "etiss_uint32 ret = vfclass_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 27693, 27692, 27683, 27684, 27685, 27686, 27687, 27688, 27689, 27690, 27691);\n";
cp.code() += "etiss_coverage_count(1, 27694);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 27697, 27695, 27696);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27708);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 27704, 27700, 27703, 27701, 27702);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 27707, 27705, 27706);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27714);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 27713, 27711, 27712);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 27717, 27716);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 27729, 27718, 27728, 27722, 27719, 27723, 27726, 27724, 27727);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFCLASS_V\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfclass_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMERGE_VFM -----------------------------------------------------------------
static InstructionDefinition vfmerge_vfm_vd_rs1_vs2 (
	ISA32_RV32IMACFDV_zvl128b,
	"vfmerge_vfm",
	(uint64_t) 0x5c005057,
	(uint64_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMERGE_VFM\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 494);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27802);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27735, 27734);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27740, 27739);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 27745, 27744);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 27752, 27751, 27749, 27750);\n";
cp.code() += "etiss_uint32 ret = vfmerge_vfm(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL);\n";
cp.code() += "etiss_coverage_count(11, 27765, 27764, 27754, 27755, 27756, 27757, 27758, 27759, 27760, 27761, 27762);\n";
cp.code() += "etiss_coverage_count(1, 27766);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 27769, 27767, 27768);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27780);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 27776, 27772, 27775, 27773, 27774);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 27779, 27777, 27778);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27786);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 27785, 27783, 27784);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 27789, 27788);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 27801, 27790, 27800, 27794, 27791, 27795, 27798, 27796, 27799);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMERGE_VFM\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmerge_vfm" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMV_V_F --------------------------------------------------------------------
static InstructionDefinition vfmv_v_f_vd_rs1 (
	ISA32_RV32IMACFDV_zvl128b,
	"vfmv_v_f",
	(uint64_t) 0x5e005057,
	(uint64_t) 0xfff0707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMV_V_F\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 495);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27873);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27807, 27806);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27812, 27811);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 27817, 27816);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 27824, 27823, 27821, 27822);\n";
cp.code() += "etiss_uint32 ret = vfmv_v_f(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vd) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL);\n";
cp.code() += "etiss_coverage_count(10, 27836, 27835, 27826, 27827, 27828, 27829, 27830, 27831, 27832, 27833);\n";
cp.code() += "etiss_coverage_count(1, 27837);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 27840, 27838, 27839);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27851);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 27847, 27843, 27846, 27844, 27845);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 27850, 27848, 27849);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27857);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 27856, 27854, 27855);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 27860, 27859);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 27872, 27861, 27871, 27865, 27862, 27866, 27869, 27867, 27870);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMV_V_F\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmv_v_f" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFCVT_XU_F_V ----------------------------------------------------------------
static InstructionDefinition vfcvt_xu_f_v_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfcvt_xu_f_v",
	(uint64_t) 0x48001057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFCVT_XU_F_V\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 496);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27950);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27878, 27877);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27883, 27882);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 27888, 27887);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 27895, 27894, 27892, 27893);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 27901, 27900, 27897, 27898, 27899);\n";
cp.code() += "etiss_uint32 ret = vfcvt_xu_f_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 27913, 27912, 27903, 27904, 27905, 27906, 27907, 27908, 27909, 27910, 27911);\n";
cp.code() += "etiss_coverage_count(1, 27914);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 27917, 27915, 27916);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27928);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 27924, 27920, 27923, 27921, 27922);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 27927, 27925, 27926);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27934);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 27933, 27931, 27932);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 27937, 27936);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 27949, 27938, 27948, 27942, 27939, 27943, 27946, 27944, 27947);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFCVT_XU_F_V\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfcvt_xu_f_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFCVT_X_F_V -----------------------------------------------------------------
static InstructionDefinition vfcvt_x_f_v_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfcvt_x_f_v",
	(uint64_t) 0x48009057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFCVT_X_F_V\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 497);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28027);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27955, 27954);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27960, 27959);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 27965, 27964);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 27972, 27971, 27969, 27970);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 27978, 27977, 27974, 27975, 27976);\n";
cp.code() += "etiss_uint32 ret = vfcvt_x_f_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 27990, 27989, 27980, 27981, 27982, 27983, 27984, 27985, 27986, 27987, 27988);\n";
cp.code() += "etiss_coverage_count(1, 27991);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 27994, 27992, 27993);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28005);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28001, 27997, 28000, 27998, 27999);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28004, 28002, 28003);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28011);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28010, 28008, 28009);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28014, 28013);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28026, 28015, 28025, 28019, 28016, 28020, 28023, 28021, 28024);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFCVT_X_F_V\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfcvt_x_f_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFCVT_RTZ_XU_F_V ------------------------------------------------------------
static InstructionDefinition vfcvt_rtz_xu_f_v_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfcvt_rtz_xu_f_v",
	(uint64_t) 0x48031057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFCVT_RTZ_XU_F_V\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 498);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28104);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28032, 28031);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28037, 28036);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28042, 28041);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28049, 28048, 28046, 28047);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28055, 28054, 28051, 28052, 28053);\n";
cp.code() += "etiss_uint32 ret = vfcvt_rtz_xu_f_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 28067, 28066, 28057, 28058, 28059, 28060, 28061, 28062, 28063, 28064, 28065);\n";
cp.code() += "etiss_coverage_count(1, 28068);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28071, 28069, 28070);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28082);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28078, 28074, 28077, 28075, 28076);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28081, 28079, 28080);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28088);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28087, 28085, 28086);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28091, 28090);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28103, 28092, 28102, 28096, 28093, 28097, 28100, 28098, 28101);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFCVT_RTZ_XU_F_V\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfcvt_rtz_xu_f_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFCVT_RTZ_X_F_V -------------------------------------------------------------
static InstructionDefinition vfcvt_rtz_x_f_v_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfcvt_rtz_x_f_v",
	(uint64_t) 0x48039057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFCVT_RTZ_X_F_V\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 499);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28181);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28109, 28108);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28114, 28113);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28119, 28118);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28126, 28125, 28123, 28124);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28132, 28131, 28128, 28129, 28130);\n";
cp.code() += "etiss_uint32 ret = vfcvt_rtz_x_f_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 28144, 28143, 28134, 28135, 28136, 28137, 28138, 28139, 28140, 28141, 28142);\n";
cp.code() += "etiss_coverage_count(1, 28145);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28148, 28146, 28147);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28159);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28155, 28151, 28154, 28152, 28153);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28158, 28156, 28157);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28165);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28164, 28162, 28163);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28168, 28167);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28180, 28169, 28179, 28173, 28170, 28174, 28177, 28175, 28178);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFCVT_RTZ_X_F_V\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfcvt_rtz_x_f_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFCVT_F_XU_V ----------------------------------------------------------------
static InstructionDefinition vfcvt_f_xu_v_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfcvt_f_xu_v",
	(uint64_t) 0x48011057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFCVT_F_XU_V\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 500);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28258);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28186, 28185);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28191, 28190);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28196, 28195);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28203, 28202, 28200, 28201);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28209, 28208, 28205, 28206, 28207);\n";
cp.code() += "etiss_uint32 ret = vfcvt_f_xu_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 28221, 28220, 28211, 28212, 28213, 28214, 28215, 28216, 28217, 28218, 28219);\n";
cp.code() += "etiss_coverage_count(1, 28222);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28225, 28223, 28224);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28236);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28232, 28228, 28231, 28229, 28230);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28235, 28233, 28234);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28242);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28241, 28239, 28240);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28245, 28244);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28257, 28246, 28256, 28250, 28247, 28251, 28254, 28252, 28255);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFCVT_F_XU_V\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfcvt_f_xu_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFCVT_F_X_V -----------------------------------------------------------------
static InstructionDefinition vfcvt_f_x_v_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfcvt_f_x_v",
	(uint64_t) 0x48019057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFCVT_F_X_V\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 501);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28335);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28263, 28262);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28268, 28267);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28273, 28272);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28280, 28279, 28277, 28278);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28286, 28285, 28282, 28283, 28284);\n";
cp.code() += "etiss_uint32 ret = vfcvt_f_x_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 28298, 28297, 28288, 28289, 28290, 28291, 28292, 28293, 28294, 28295, 28296);\n";
cp.code() += "etiss_coverage_count(1, 28299);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28302, 28300, 28301);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28313);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28309, 28305, 28308, 28306, 28307);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28312, 28310, 28311);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28319);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28318, 28316, 28317);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28322, 28321);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28334, 28323, 28333, 28327, 28324, 28328, 28331, 28329, 28332);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFCVT_F_X_V\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfcvt_f_x_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWCVT_XU_F_V ---------------------------------------------------------------
static InstructionDefinition vfwcvt_xu_f_v_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwcvt_xu_f_v",
	(uint64_t) 0x48041057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWCVT_XU_F_V\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 502);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28412);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28340, 28339);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28345, 28344);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28350, 28349);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28357, 28356, 28354, 28355);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28363, 28362, 28359, 28360, 28361);\n";
cp.code() += "etiss_uint32 ret = vfwcvt_xu_f_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 28375, 28374, 28365, 28366, 28367, 28368, 28369, 28370, 28371, 28372, 28373);\n";
cp.code() += "etiss_coverage_count(1, 28376);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28379, 28377, 28378);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28390);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28386, 28382, 28385, 28383, 28384);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28389, 28387, 28388);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28396);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28395, 28393, 28394);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28399, 28398);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28411, 28400, 28410, 28404, 28401, 28405, 28408, 28406, 28409);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWCVT_XU_F_V\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwcvt_xu_f_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWCVT_X_F_V ----------------------------------------------------------------
static InstructionDefinition vfwcvt_x_f_v_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwcvt_x_f_v",
	(uint64_t) 0x48049057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWCVT_X_F_V\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 503);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28489);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28417, 28416);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28422, 28421);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28427, 28426);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28434, 28433, 28431, 28432);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28440, 28439, 28436, 28437, 28438);\n";
cp.code() += "etiss_uint32 ret = vfwcvt_x_f_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 28452, 28451, 28442, 28443, 28444, 28445, 28446, 28447, 28448, 28449, 28450);\n";
cp.code() += "etiss_coverage_count(1, 28453);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28456, 28454, 28455);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28467);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28463, 28459, 28462, 28460, 28461);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28466, 28464, 28465);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28473);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28472, 28470, 28471);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28476, 28475);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28488, 28477, 28487, 28481, 28478, 28482, 28485, 28483, 28486);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWCVT_X_F_V\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwcvt_x_f_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWCVT_RTZ_XU_F_V -----------------------------------------------------------
static InstructionDefinition vfwcvt_rtz_xu_f_v_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwcvt_rtz_xu_f_v",
	(uint64_t) 0x48071057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWCVT_RTZ_XU_F_V\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 504);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28566);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28494, 28493);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28499, 28498);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28504, 28503);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28511, 28510, 28508, 28509);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28517, 28516, 28513, 28514, 28515);\n";
cp.code() += "etiss_uint32 ret = vfwcvt_rtz_xu_f_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 28529, 28528, 28519, 28520, 28521, 28522, 28523, 28524, 28525, 28526, 28527);\n";
cp.code() += "etiss_coverage_count(1, 28530);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28533, 28531, 28532);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28544);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28540, 28536, 28539, 28537, 28538);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28543, 28541, 28542);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28550);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28549, 28547, 28548);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28553, 28552);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28565, 28554, 28564, 28558, 28555, 28559, 28562, 28560, 28563);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWCVT_RTZ_XU_F_V\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwcvt_rtz_xu_f_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWCVT_RTZ_X_F_V ------------------------------------------------------------
static InstructionDefinition vfwcvt_rtz_x_f_v_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwcvt_rtz_x_f_v",
	(uint64_t) 0x48079057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWCVT_RTZ_X_F_V\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 505);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28643);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28571, 28570);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28576, 28575);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28581, 28580);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28588, 28587, 28585, 28586);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28594, 28593, 28590, 28591, 28592);\n";
cp.code() += "etiss_uint32 ret = vfwcvt_rtz_x_f_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 28606, 28605, 28596, 28597, 28598, 28599, 28600, 28601, 28602, 28603, 28604);\n";
cp.code() += "etiss_coverage_count(1, 28607);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28610, 28608, 28609);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28621);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28617, 28613, 28616, 28614, 28615);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28620, 28618, 28619);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28627);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28626, 28624, 28625);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28630, 28629);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28642, 28631, 28641, 28635, 28632, 28636, 28639, 28637, 28640);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWCVT_RTZ_X_F_V\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwcvt_rtz_x_f_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWCVT_F_XU_V ---------------------------------------------------------------
static InstructionDefinition vfwcvt_f_xu_v_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwcvt_f_xu_v",
	(uint64_t) 0x48051057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWCVT_F_XU_V\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 506);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28720);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28648, 28647);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28653, 28652);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28658, 28657);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28665, 28664, 28662, 28663);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28671, 28670, 28667, 28668, 28669);\n";
cp.code() += "etiss_uint32 ret = vfwcvt_f_xu_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 28683, 28682, 28673, 28674, 28675, 28676, 28677, 28678, 28679, 28680, 28681);\n";
cp.code() += "etiss_coverage_count(1, 28684);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28687, 28685, 28686);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28698);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28694, 28690, 28693, 28691, 28692);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28697, 28695, 28696);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28704);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28703, 28701, 28702);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28707, 28706);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28719, 28708, 28718, 28712, 28709, 28713, 28716, 28714, 28717);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWCVT_F_XU_V\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwcvt_f_xu_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWCVT_F_X_V ----------------------------------------------------------------
static InstructionDefinition vfwcvt_f_x_v_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwcvt_f_x_v",
	(uint64_t) 0x48059057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWCVT_F_X_V\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 507);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28797);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28725, 28724);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28730, 28729);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28735, 28734);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28742, 28741, 28739, 28740);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28748, 28747, 28744, 28745, 28746);\n";
cp.code() += "etiss_uint32 ret = vfwcvt_f_x_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 28760, 28759, 28750, 28751, 28752, 28753, 28754, 28755, 28756, 28757, 28758);\n";
cp.code() += "etiss_coverage_count(1, 28761);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28764, 28762, 28763);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28775);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28771, 28767, 28770, 28768, 28769);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28774, 28772, 28773);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28781);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28780, 28778, 28779);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28784, 28783);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28796, 28785, 28795, 28789, 28786, 28790, 28793, 28791, 28794);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWCVT_F_X_V\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwcvt_f_x_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWCVT_F_F_V ----------------------------------------------------------------
static InstructionDefinition vfwcvt_f_f_v_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwcvt_f_f_v",
	(uint64_t) 0x48061057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWCVT_F_F_V\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 508);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28874);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28802, 28801);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28807, 28806);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28812, 28811);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28819, 28818, 28816, 28817);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28825, 28824, 28821, 28822, 28823);\n";
cp.code() += "etiss_uint32 ret = vfwcvt_f_f_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 28837, 28836, 28827, 28828, 28829, 28830, 28831, 28832, 28833, 28834, 28835);\n";
cp.code() += "etiss_coverage_count(1, 28838);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28841, 28839, 28840);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28852);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28848, 28844, 28847, 28845, 28846);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28851, 28849, 28850);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28858);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28857, 28855, 28856);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28861, 28860);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28873, 28862, 28872, 28866, 28863, 28867, 28870, 28868, 28871);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWCVT_F_F_V\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwcvt_f_f_v" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VNFCVT_XU_F_W ---------------------------------------------------------------
static InstructionDefinition vnfcvt_xu_f_w_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vnfcvt_xu_f_w",
	(uint64_t) 0x48081057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VNFCVT_XU_F_W\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 509);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28951);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28879, 28878);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28884, 28883);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28889, 28888);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28896, 28895, 28893, 28894);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28902, 28901, 28898, 28899, 28900);\n";
cp.code() += "etiss_uint32 ret = vfncvt_xu_f_w(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 28914, 28913, 28904, 28905, 28906, 28907, 28908, 28909, 28910, 28911, 28912);\n";
cp.code() += "etiss_coverage_count(1, 28915);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28918, 28916, 28917);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28929);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28925, 28921, 28924, 28922, 28923);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28928, 28926, 28927);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28935);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28934, 28932, 28933);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28938, 28937);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28950, 28939, 28949, 28943, 28940, 28944, 28947, 28945, 28948);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VNFCVT_XU_F_W\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vnfcvt_xu_f_w" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VNFCVT_X_F_W ----------------------------------------------------------------
static InstructionDefinition vnfcvt_x_f_w_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vnfcvt_x_f_w",
	(uint64_t) 0x48089057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VNFCVT_X_F_W\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 510);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29028);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28956, 28955);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28961, 28960);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28966, 28965);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28973, 28972, 28970, 28971);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28979, 28978, 28975, 28976, 28977);\n";
cp.code() += "etiss_uint32 ret = vfncvt_x_f_w(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 28991, 28990, 28981, 28982, 28983, 28984, 28985, 28986, 28987, 28988, 28989);\n";
cp.code() += "etiss_coverage_count(1, 28992);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28995, 28993, 28994);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29006);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29002, 28998, 29001, 28999, 29000);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29005, 29003, 29004);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29012);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29011, 29009, 29010);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29015, 29014);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29027, 29016, 29026, 29020, 29017, 29021, 29024, 29022, 29025);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VNFCVT_X_F_W\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vnfcvt_x_f_w" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VNFCVT_RTZ_XU_F_W -----------------------------------------------------------
static InstructionDefinition vnfcvt_rtz_xu_f_w_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vnfcvt_rtz_xu_f_w",
	(uint64_t) 0x480b1057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VNFCVT_RTZ_XU_F_W\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 511);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29105);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29033, 29032);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29038, 29037);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29043, 29042);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29050, 29049, 29047, 29048);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29056, 29055, 29052, 29053, 29054);\n";
cp.code() += "etiss_uint32 ret = vfncvt_rtz_xu_f_w(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 29068, 29067, 29058, 29059, 29060, 29061, 29062, 29063, 29064, 29065, 29066);\n";
cp.code() += "etiss_coverage_count(1, 29069);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29072, 29070, 29071);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29083);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29079, 29075, 29078, 29076, 29077);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29082, 29080, 29081);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29089);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29088, 29086, 29087);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29092, 29091);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29104, 29093, 29103, 29097, 29094, 29098, 29101, 29099, 29102);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VNFCVT_RTZ_XU_F_W\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vnfcvt_rtz_xu_f_w" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VNFCVT_RTZ_X_F_W ------------------------------------------------------------
static InstructionDefinition vnfcvt_rtz_x_f_w_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vnfcvt_rtz_x_f_w",
	(uint64_t) 0x480b9057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VNFCVT_RTZ_X_F_W\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 512);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29182);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29110, 29109);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29115, 29114);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29120, 29119);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29127, 29126, 29124, 29125);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29133, 29132, 29129, 29130, 29131);\n";
cp.code() += "etiss_uint32 ret = vfncvt_rtz_x_f_w(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 29145, 29144, 29135, 29136, 29137, 29138, 29139, 29140, 29141, 29142, 29143);\n";
cp.code() += "etiss_coverage_count(1, 29146);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29149, 29147, 29148);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29160);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29156, 29152, 29155, 29153, 29154);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29159, 29157, 29158);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29166);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29165, 29163, 29164);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29169, 29168);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29181, 29170, 29180, 29174, 29171, 29175, 29178, 29176, 29179);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VNFCVT_RTZ_X_F_W\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vnfcvt_rtz_x_f_w" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VNFCVT_F_XU_W ---------------------------------------------------------------
static InstructionDefinition vnfcvt_f_xu_w_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vnfcvt_f_xu_w",
	(uint64_t) 0x48091057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VNFCVT_F_XU_W\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 513);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29259);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29187, 29186);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29192, 29191);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29197, 29196);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29204, 29203, 29201, 29202);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29210, 29209, 29206, 29207, 29208);\n";
cp.code() += "etiss_uint32 ret = vfncvt_f_xu_w(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 29222, 29221, 29212, 29213, 29214, 29215, 29216, 29217, 29218, 29219, 29220);\n";
cp.code() += "etiss_coverage_count(1, 29223);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29226, 29224, 29225);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29237);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29233, 29229, 29232, 29230, 29231);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29236, 29234, 29235);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29243);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29242, 29240, 29241);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29246, 29245);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29258, 29247, 29257, 29251, 29248, 29252, 29255, 29253, 29256);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VNFCVT_F_XU_W\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vnfcvt_f_xu_w" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VNFCVT_F_X_W ----------------------------------------------------------------
static InstructionDefinition vnfcvt_f_x_w_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vnfcvt_f_x_w",
	(uint64_t) 0x48099057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VNFCVT_F_X_W\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 514);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29336);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29264, 29263);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29269, 29268);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29274, 29273);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29281, 29280, 29278, 29279);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29287, 29286, 29283, 29284, 29285);\n";
cp.code() += "etiss_uint32 ret = vfncvt_f_x_w(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 29299, 29298, 29289, 29290, 29291, 29292, 29293, 29294, 29295, 29296, 29297);\n";
cp.code() += "etiss_coverage_count(1, 29300);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29303, 29301, 29302);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29314);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29310, 29306, 29309, 29307, 29308);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29313, 29311, 29312);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29320);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29319, 29317, 29318);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29323, 29322);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29335, 29324, 29334, 29328, 29325, 29329, 29332, 29330, 29333);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VNFCVT_F_X_W\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vnfcvt_f_x_w" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VNFCVT_F_F_W ----------------------------------------------------------------
static InstructionDefinition vnfcvt_f_f_w_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vnfcvt_f_f_w",
	(uint64_t) 0x480a1057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VNFCVT_F_F_W\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 515);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29413);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29341, 29340);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29346, 29345);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29351, 29350);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29358, 29357, 29355, 29356);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29364, 29363, 29360, 29361, 29362);\n";
cp.code() += "etiss_uint32 ret = vfncvt_f_f_w(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 29376, 29375, 29366, 29367, 29368, 29369, 29370, 29371, 29372, 29373, 29374);\n";
cp.code() += "etiss_coverage_count(1, 29377);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29380, 29378, 29379);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29391);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29387, 29383, 29386, 29384, 29385);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29390, 29388, 29389);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29397);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29396, 29394, 29395);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29400, 29399);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29412, 29401, 29411, 29405, 29402, 29406, 29409, 29407, 29410);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VNFCVT_F_F_W\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vnfcvt_f_f_w" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VNFCVT_ROD_F_F_W ------------------------------------------------------------
static InstructionDefinition vnfcvt_rod_f_f_w_vd_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vnfcvt_rod_f_f_w",
	(uint64_t) 0x480a9057,
	(uint64_t) 0xfc0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VNFCVT_ROD_F_F_W\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 516);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29490);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29418, 29417);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29423, 29422);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29428, 29427);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29435, 29434, 29432, 29433);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29441, 29440, 29437, 29438, 29439);\n";
cp.code() += "etiss_uint32 ret = vfncvt_rod_f_f_w(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 29453, 29452, 29443, 29444, 29445, 29446, 29447, 29448, 29449, 29450, 29451);\n";
cp.code() += "etiss_coverage_count(1, 29454);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29457, 29455, 29456);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29468);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29464, 29460, 29463, 29461, 29462);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29467, 29465, 29466);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29474);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29473, 29471, 29472);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29477, 29476);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29489, 29478, 29488, 29482, 29479, 29483, 29486, 29484, 29487);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VNFCVT_ROD_F_F_W\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vnfcvt_rod_f_f_w" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFREDOSUM_VS ----------------------------------------------------------------
static InstructionDefinition vfredosum_vs_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfredosum_vs",
	(uint64_t) 0xc001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFREDOSUM_VS\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 517);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29568);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29495, 29494);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29500, 29499);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29505, 29504);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29512, 29511, 29509, 29510);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29518, 29517, 29514, 29515, 29516);\n";
cp.code() += "etiss_uint32 ret = vfredosum_vs(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 29531, 29530, 29520, 29521, 29522, 29523, 29524, 29525, 29526, 29527, 29528, 29529);\n";
cp.code() += "etiss_coverage_count(1, 29532);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29535, 29533, 29534);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29546);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29542, 29538, 29541, 29539, 29540);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29545, 29543, 29544);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29552);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29551, 29549, 29550);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29555, 29554);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29567, 29556, 29566, 29560, 29557, 29561, 29564, 29562, 29565);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFREDOSUM_VS\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfredosum_vs" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFREDUSUM_VS ----------------------------------------------------------------
static InstructionDefinition vfredusum_vs_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfredusum_vs",
	(uint64_t) 0x4001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFREDUSUM_VS\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 518);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29646);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29573, 29572);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29578, 29577);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29583, 29582);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29590, 29589, 29587, 29588);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29596, 29595, 29592, 29593, 29594);\n";
cp.code() += "etiss_uint32 ret = vfredusum_vs(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 29609, 29608, 29598, 29599, 29600, 29601, 29602, 29603, 29604, 29605, 29606, 29607);\n";
cp.code() += "etiss_coverage_count(1, 29610);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29613, 29611, 29612);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29624);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29620, 29616, 29619, 29617, 29618);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29623, 29621, 29622);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29630);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29629, 29627, 29628);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29633, 29632);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29645, 29634, 29644, 29638, 29635, 29639, 29642, 29640, 29643);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFREDUSUM_VS\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfredusum_vs" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFREDMAX_VS -----------------------------------------------------------------
static InstructionDefinition vfredmax_vs_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfredmax_vs",
	(uint64_t) 0x1c001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFREDMAX_VS\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 519);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29724);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29651, 29650);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29656, 29655);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29661, 29660);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29668, 29667, 29665, 29666);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29674, 29673, 29670, 29671, 29672);\n";
cp.code() += "etiss_uint32 ret = vfredmax_vs(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 29687, 29686, 29676, 29677, 29678, 29679, 29680, 29681, 29682, 29683, 29684, 29685);\n";
cp.code() += "etiss_coverage_count(1, 29688);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29691, 29689, 29690);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29702);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29698, 29694, 29697, 29695, 29696);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29701, 29699, 29700);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29708);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29707, 29705, 29706);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29711, 29710);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29723, 29712, 29722, 29716, 29713, 29717, 29720, 29718, 29721);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFREDMAX_VS\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfredmax_vs" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFREDMIN_VS -----------------------------------------------------------------
static InstructionDefinition vfredmin_vs_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfredmin_vs",
	(uint64_t) 0x14001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFREDMIN_VS\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 520);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29802);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29729, 29728);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29734, 29733);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29739, 29738);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29746, 29745, 29743, 29744);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29752, 29751, 29748, 29749, 29750);\n";
cp.code() += "etiss_uint32 ret = vfredmin_vs(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 29765, 29764, 29754, 29755, 29756, 29757, 29758, 29759, 29760, 29761, 29762, 29763);\n";
cp.code() += "etiss_coverage_count(1, 29766);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29769, 29767, 29768);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29780);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29776, 29772, 29775, 29773, 29774);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29779, 29777, 29778);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29786);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29785, 29783, 29784);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29789, 29788);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29801, 29790, 29800, 29794, 29791, 29795, 29798, 29796, 29799);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFREDMIN_VS\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfredmin_vs" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWREDOSUM_VS ---------------------------------------------------------------
static InstructionDefinition vfwredosum_vs_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwredosum_vs",
	(uint64_t) 0xcc001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWREDOSUM_VS\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 521);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29880);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29807, 29806);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29812, 29811);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29817, 29816);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29824, 29823, 29821, 29822);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29830, 29829, 29826, 29827, 29828);\n";
cp.code() += "etiss_uint32 ret = vfwredosum_vs(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 29843, 29842, 29832, 29833, 29834, 29835, 29836, 29837, 29838, 29839, 29840, 29841);\n";
cp.code() += "etiss_coverage_count(1, 29844);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29847, 29845, 29846);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29858);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29854, 29850, 29853, 29851, 29852);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29857, 29855, 29856);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29864);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29863, 29861, 29862);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29867, 29866);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29879, 29868, 29878, 29872, 29869, 29873, 29876, 29874, 29877);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWREDOSUM_VS\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwredosum_vs" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFWREDUSUM_VS ---------------------------------------------------------------
static InstructionDefinition vfwredusum_vs_vd_vs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfwredusum_vs",
	(uint64_t) 0xc4001057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFWREDUSUM_VS\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 522);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29958);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29885, 29884);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29890, 29889);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29895, 29894);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29902, 29901, 29899, 29900);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29908, 29907, 29904, 29905, 29906);\n";
cp.code() += "etiss_uint32 ret = vfwredusum_vs(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 29921, 29920, 29910, 29911, 29912, 29913, 29914, 29915, 29916, 29917, 29918, 29919);\n";
cp.code() += "etiss_coverage_count(1, 29922);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29925, 29923, 29924);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29936);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29932, 29928, 29931, 29929, 29930);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29935, 29933, 29934);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29942);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29941, 29939, 29940);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29945, 29944);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29957, 29946, 29956, 29950, 29947, 29951, 29954, 29952, 29955);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFWREDUSUM_VS\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 vs1 = 0;
static BitArrayRange R_vs1_0(19, 15);
vs1 += R_vs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfwredusum_vs" << " # " << ba << (" [vd=" + std::to_string(vd) + " | vs1=" + std::to_string(vs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMV_F_S --------------------------------------------------------------------
static InstructionDefinition vfmv_f_s_rd_vs2 (
	ISA32_RV32IMACFDV_zvl128b,
	"vfmv_f_s",
	(uint64_t) 0x42001057,
	(uint64_t) 0xfe0ff07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMV_F_S\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 523);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 30014);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29963, 29962);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29968, 29967);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29973, 29972);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29980, 29979, 29977, 29978);\n";
cp.code() += "etiss_uint32 ret = vfmv_f_s(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(rd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, 32ULL);\n";
cp.code() += "etiss_coverage_count(10, 29992, 29991, 29982, 29983, 29984, 29985, 29986, 29987, 29988, 29989);\n";
cp.code() += "etiss_coverage_count(1, 29993);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29996, 29994, 29995);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30007);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 30003, 29999, 30002, 30000, 30001);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 30006, 30004, 30005);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30013);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 30012, 30010, 30011);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMV_F_S\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmv_f_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | vs2=" + std::to_string(vs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFMV_S_F --------------------------------------------------------------------
static InstructionDefinition vfmv_s_f_vd_rs1 (
	ISA32_RV32IMACFDV_zvl128b,
	"vfmv_s_f",
	(uint64_t) 0x42005057,
	(uint64_t) 0xfff0707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFMV_S_F\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 524);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 30070);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 30019, 30018);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 30024, 30023);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 30029, 30028);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 30036, 30035, 30033, 30034);\n";
cp.code() += "etiss_uint32 ret = vfmv_s_f(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vd) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL);\n";
cp.code() += "etiss_coverage_count(10, 30048, 30047, 30038, 30039, 30040, 30041, 30042, 30043, 30044, 30045);\n";
cp.code() += "etiss_coverage_count(1, 30049);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 30052, 30050, 30051);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30063);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 30059, 30055, 30058, 30056, 30057);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 30062, 30060, 30061);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30069);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 30068, 30066, 30067);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFMV_S_F\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfmv_s_f" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFSLIDE1UP_VX ---------------------------------------------------------------
static InstructionDefinition vfslide1up_vx_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfslide1up_vx",
	(uint64_t) 0x38005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFSLIDE1UP_VX\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 525);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 30128);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 30075, 30074);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 30080, 30079);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 30085, 30084);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 30092, 30091, 30089, 30090);\n";
cp.code() += "etiss_uint32 ret = vfslide1up_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL);\n";
cp.code() += "etiss_coverage_count(12, 30106, 30105, 30094, 30095, 30096, 30097, 30098, 30099, 30100, 30101, 30102, 30103);\n";
cp.code() += "etiss_coverage_count(1, 30107);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 30110, 30108, 30109);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30121);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 30117, 30113, 30116, 30114, 30115);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 30120, 30118, 30119);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30127);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 30126, 30124, 30125);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFSLIDE1UP_VX\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfslide1up_vx" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// VFSLIDE1DOWN_VF -------------------------------------------------------------
static InstructionDefinition vfslide1down_vf_vd_rs1_vs2_vm (
	ISA32_RV32IMACFDV_zvl128b,
	"vfslide1down_vf",
	(uint64_t) 0x3c005057,
	(uint64_t) 0xfc00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//VFSLIDE1DOWN_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 526);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 30186);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 30133, 30132);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 30138, 30137);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 30143, 30142);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 30150, 30149, 30147, 30148);\n";
cp.code() += "etiss_uint32 ret = vfslide1down_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL);\n";
cp.code() += "etiss_coverage_count(12, 30164, 30163, 30152, 30153, 30154, 30155, 30156, 30157, 30158, 30159, 30160, 30161);\n";
cp.code() += "etiss_coverage_count(1, 30165);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 30168, 30166, 30167);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30179);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 30175, 30171, 30174, 30172, 30173);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 30178, 30176, 30177);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30185);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 30184, 30182, 30183);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//VFSLIDE1DOWN_VF\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 vd = 0;
static BitArrayRange R_vd_0(11, 7);
vd += R_vd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 vs2 = 0;
static BitArrayRange R_vs2_0(24, 20);
vs2 += R_vs2_0.read(ba) << 0;
etiss_uint8 vm = 0;
static BitArrayRange R_vm_0(25, 25);
vm += R_vm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "vfslide1down_vf" << " # " << ba << (" [vd=" + std::to_string(vd) + " | rs1=" + std::to_string(rs1) + " | vs2=" + std::to_string(vs2) + " | vm=" + std::to_string(vm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
// clang-format on
