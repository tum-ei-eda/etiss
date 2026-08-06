// clang-format off
/**
 * Generated on Thu, 06 Aug 2026 13:26:11 +0200.
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
cp.code() += "etiss_coverage_count(1, 556);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27195);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27122, 27121);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27127, 27126);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 27132, 27131);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 27139, 27138, 27136, 27137);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 27145, 27144, 27141, 27142, 27143);\n";
cp.code() += "etiss_uint32 ret = vfadd_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 27158, 27157, 27147, 27148, 27149, 27150, 27151, 27152, 27153, 27154, 27155, 27156);\n";
cp.code() += "etiss_coverage_count(1, 27159);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 27162, 27160, 27161);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27173);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 27169, 27165, 27168, 27166, 27167);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 27172, 27170, 27171);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27179);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 27178, 27176, 27177);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 27182, 27181);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 27194, 27183, 27193, 27187, 27184, 27188, 27191, 27189, 27192);\n";
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
cp.code() += "etiss_coverage_count(1, 557);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27275);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27200, 27199);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27205, 27204);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 27210, 27209);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 27217, 27216, 27214, 27215);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 27223, 27222, 27219, 27220, 27221);\n";
cp.code() += "etiss_uint32 ret = vfadd_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 27238, 27237, 27225, 27226, 27227, 27228, 27229, 27230, 27231, 27232, 27233, 27234, 27236);\n";
cp.code() += "etiss_coverage_count(1, 27239);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 27242, 27240, 27241);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27253);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 27249, 27245, 27248, 27246, 27247);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 27252, 27250, 27251);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27259);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 27258, 27256, 27257);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 27262, 27261);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 27274, 27263, 27273, 27267, 27264, 27268, 27271, 27269, 27272);\n";
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
cp.code() += "etiss_coverage_count(1, 558);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27353);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27280, 27279);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27285, 27284);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 27290, 27289);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 27297, 27296, 27294, 27295);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 27303, 27302, 27299, 27300, 27301);\n";
cp.code() += "etiss_uint32 ret = vfsub_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 27316, 27315, 27305, 27306, 27307, 27308, 27309, 27310, 27311, 27312, 27313, 27314);\n";
cp.code() += "etiss_coverage_count(1, 27317);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 27320, 27318, 27319);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27331);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 27327, 27323, 27326, 27324, 27325);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 27330, 27328, 27329);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27337);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 27336, 27334, 27335);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 27340, 27339);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 27352, 27341, 27351, 27345, 27342, 27346, 27349, 27347, 27350);\n";
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
cp.code() += "etiss_coverage_count(1, 559);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27433);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27358, 27357);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27363, 27362);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 27368, 27367);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 27375, 27374, 27372, 27373);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 27381, 27380, 27377, 27378, 27379);\n";
cp.code() += "etiss_uint32 ret = vfsub_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 27396, 27395, 27383, 27384, 27385, 27386, 27387, 27388, 27389, 27390, 27391, 27392, 27394);\n";
cp.code() += "etiss_coverage_count(1, 27397);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 27400, 27398, 27399);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27411);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 27407, 27403, 27406, 27404, 27405);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 27410, 27408, 27409);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27417);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 27416, 27414, 27415);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 27420, 27419);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 27432, 27421, 27431, 27425, 27422, 27426, 27429, 27427, 27430);\n";
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
cp.code() += "etiss_coverage_count(1, 560);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27513);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27438, 27437);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27443, 27442);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 27448, 27447);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 27455, 27454, 27452, 27453);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 27461, 27460, 27457, 27458, 27459);\n";
cp.code() += "etiss_uint32 ret = vfrsub_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 27476, 27475, 27463, 27464, 27465, 27466, 27467, 27468, 27469, 27470, 27471, 27472, 27474);\n";
cp.code() += "etiss_coverage_count(1, 27477);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 27480, 27478, 27479);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27491);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 27487, 27483, 27486, 27484, 27485);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 27490, 27488, 27489);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27497);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 27496, 27494, 27495);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 27500, 27499);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 27512, 27501, 27511, 27505, 27502, 27506, 27509, 27507, 27510);\n";
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
cp.code() += "etiss_coverage_count(1, 561);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27591);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27518, 27517);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27523, 27522);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 27528, 27527);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 27535, 27534, 27532, 27533);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 27541, 27540, 27537, 27538, 27539);\n";
cp.code() += "etiss_uint32 ret = vfwadd_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 27554, 27553, 27543, 27544, 27545, 27546, 27547, 27548, 27549, 27550, 27551, 27552);\n";
cp.code() += "etiss_coverage_count(1, 27555);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 27558, 27556, 27557);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27569);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 27565, 27561, 27564, 27562, 27563);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 27568, 27566, 27567);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27575);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 27574, 27572, 27573);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 27578, 27577);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 27590, 27579, 27589, 27583, 27580, 27584, 27587, 27585, 27588);\n";
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
cp.code() += "etiss_coverage_count(1, 562);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27671);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27596, 27595);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27601, 27600);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 27606, 27605);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 27613, 27612, 27610, 27611);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 27619, 27618, 27615, 27616, 27617);\n";
cp.code() += "etiss_uint32 ret = vfwadd_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 27634, 27633, 27621, 27622, 27623, 27624, 27625, 27626, 27627, 27628, 27629, 27630, 27632);\n";
cp.code() += "etiss_coverage_count(1, 27635);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 27638, 27636, 27637);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27649);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 27645, 27641, 27644, 27642, 27643);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 27648, 27646, 27647);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27655);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 27654, 27652, 27653);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 27658, 27657);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 27670, 27659, 27669, 27663, 27660, 27664, 27667, 27665, 27668);\n";
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
cp.code() += "etiss_coverage_count(1, 563);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27749);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27676, 27675);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27681, 27680);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 27686, 27685);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 27693, 27692, 27690, 27691);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 27699, 27698, 27695, 27696, 27697);\n";
cp.code() += "etiss_uint32 ret = vfwsub_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 27712, 27711, 27701, 27702, 27703, 27704, 27705, 27706, 27707, 27708, 27709, 27710);\n";
cp.code() += "etiss_coverage_count(1, 27713);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 27716, 27714, 27715);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27727);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 27723, 27719, 27722, 27720, 27721);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 27726, 27724, 27725);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27733);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 27732, 27730, 27731);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 27736, 27735);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 27748, 27737, 27747, 27741, 27738, 27742, 27745, 27743, 27746);\n";
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
cp.code() += "etiss_coverage_count(1, 564);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27829);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27754, 27753);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27759, 27758);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 27764, 27763);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 27771, 27770, 27768, 27769);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 27777, 27776, 27773, 27774, 27775);\n";
cp.code() += "etiss_uint32 ret = vfwsub_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 27792, 27791, 27779, 27780, 27781, 27782, 27783, 27784, 27785, 27786, 27787, 27788, 27790);\n";
cp.code() += "etiss_coverage_count(1, 27793);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 27796, 27794, 27795);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27807);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 27803, 27799, 27802, 27800, 27801);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 27806, 27804, 27805);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27813);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 27812, 27810, 27811);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 27816, 27815);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 27828, 27817, 27827, 27821, 27818, 27822, 27825, 27823, 27826);\n";
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
cp.code() += "etiss_coverage_count(1, 565);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27907);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27834, 27833);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27839, 27838);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 27844, 27843);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 27851, 27850, 27848, 27849);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 27857, 27856, 27853, 27854, 27855);\n";
cp.code() += "etiss_uint32 ret = vfwadd_wv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 27870, 27869, 27859, 27860, 27861, 27862, 27863, 27864, 27865, 27866, 27867, 27868);\n";
cp.code() += "etiss_coverage_count(1, 27871);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 27874, 27872, 27873);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27885);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 27881, 27877, 27880, 27878, 27879);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 27884, 27882, 27883);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27891);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 27890, 27888, 27889);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 27894, 27893);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 27906, 27895, 27905, 27899, 27896, 27900, 27903, 27901, 27904);\n";
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
cp.code() += "etiss_coverage_count(1, 566);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27987);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27912, 27911);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27917, 27916);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 27922, 27921);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 27929, 27928, 27926, 27927);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 27935, 27934, 27931, 27932, 27933);\n";
cp.code() += "etiss_uint32 ret = vfwadd_wf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 27950, 27949, 27937, 27938, 27939, 27940, 27941, 27942, 27943, 27944, 27945, 27946, 27948);\n";
cp.code() += "etiss_coverage_count(1, 27951);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 27954, 27952, 27953);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27965);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 27961, 27957, 27960, 27958, 27959);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 27964, 27962, 27963);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 27971);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 27970, 27968, 27969);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 27974, 27973);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 27986, 27975, 27985, 27979, 27976, 27980, 27983, 27981, 27984);\n";
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
cp.code() += "etiss_coverage_count(1, 567);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28065);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 27992, 27991);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 27997, 27996);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28002, 28001);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28009, 28008, 28006, 28007);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28015, 28014, 28011, 28012, 28013);\n";
cp.code() += "etiss_uint32 ret = vfwsub_wv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 28028, 28027, 28017, 28018, 28019, 28020, 28021, 28022, 28023, 28024, 28025, 28026);\n";
cp.code() += "etiss_coverage_count(1, 28029);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28032, 28030, 28031);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28043);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28039, 28035, 28038, 28036, 28037);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28042, 28040, 28041);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28049);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28048, 28046, 28047);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28052, 28051);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28064, 28053, 28063, 28057, 28054, 28058, 28061, 28059, 28062);\n";
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
cp.code() += "etiss_coverage_count(1, 568);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28145);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28070, 28069);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28075, 28074);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28080, 28079);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28087, 28086, 28084, 28085);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28093, 28092, 28089, 28090, 28091);\n";
cp.code() += "etiss_uint32 ret = vfwsub_wf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 28108, 28107, 28095, 28096, 28097, 28098, 28099, 28100, 28101, 28102, 28103, 28104, 28106);\n";
cp.code() += "etiss_coverage_count(1, 28109);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28112, 28110, 28111);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28123);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28119, 28115, 28118, 28116, 28117);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28122, 28120, 28121);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28129);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28128, 28126, 28127);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28132, 28131);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28144, 28133, 28143, 28137, 28134, 28138, 28141, 28139, 28142);\n";
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
cp.code() += "etiss_coverage_count(1, 569);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28223);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28150, 28149);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28155, 28154);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28160, 28159);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28167, 28166, 28164, 28165);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28173, 28172, 28169, 28170, 28171);\n";
cp.code() += "etiss_uint32 ret = vfmul_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 28186, 28185, 28175, 28176, 28177, 28178, 28179, 28180, 28181, 28182, 28183, 28184);\n";
cp.code() += "etiss_coverage_count(1, 28187);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28190, 28188, 28189);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28201);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28197, 28193, 28196, 28194, 28195);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28200, 28198, 28199);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28207);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28206, 28204, 28205);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28210, 28209);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28222, 28211, 28221, 28215, 28212, 28216, 28219, 28217, 28220);\n";
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
cp.code() += "etiss_coverage_count(1, 570);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28303);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28228, 28227);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28233, 28232);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28238, 28237);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28245, 28244, 28242, 28243);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28251, 28250, 28247, 28248, 28249);\n";
cp.code() += "etiss_uint32 ret = vfmul_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 28266, 28265, 28253, 28254, 28255, 28256, 28257, 28258, 28259, 28260, 28261, 28262, 28264);\n";
cp.code() += "etiss_coverage_count(1, 28267);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28270, 28268, 28269);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28281);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28277, 28273, 28276, 28274, 28275);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28280, 28278, 28279);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28287);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28286, 28284, 28285);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28290, 28289);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28302, 28291, 28301, 28295, 28292, 28296, 28299, 28297, 28300);\n";
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
cp.code() += "etiss_coverage_count(1, 571);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28381);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28308, 28307);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28313, 28312);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28318, 28317);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28325, 28324, 28322, 28323);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28331, 28330, 28327, 28328, 28329);\n";
cp.code() += "etiss_uint32 ret = vfdiv_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 28344, 28343, 28333, 28334, 28335, 28336, 28337, 28338, 28339, 28340, 28341, 28342);\n";
cp.code() += "etiss_coverage_count(1, 28345);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28348, 28346, 28347);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28359);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28355, 28351, 28354, 28352, 28353);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28358, 28356, 28357);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28365);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28364, 28362, 28363);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28368, 28367);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28380, 28369, 28379, 28373, 28370, 28374, 28377, 28375, 28378);\n";
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
cp.code() += "etiss_coverage_count(1, 572);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28461);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28386, 28385);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28391, 28390);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28396, 28395);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28403, 28402, 28400, 28401);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28409, 28408, 28405, 28406, 28407);\n";
cp.code() += "etiss_uint32 ret = vfdiv_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 28424, 28423, 28411, 28412, 28413, 28414, 28415, 28416, 28417, 28418, 28419, 28420, 28422);\n";
cp.code() += "etiss_coverage_count(1, 28425);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28428, 28426, 28427);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28439);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28435, 28431, 28434, 28432, 28433);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28438, 28436, 28437);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28445);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28444, 28442, 28443);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28448, 28447);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28460, 28449, 28459, 28453, 28450, 28454, 28457, 28455, 28458);\n";
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
cp.code() += "etiss_coverage_count(1, 573);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28541);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28466, 28465);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28471, 28470);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28476, 28475);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28483, 28482, 28480, 28481);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28489, 28488, 28485, 28486, 28487);\n";
cp.code() += "etiss_uint32 ret = vfrdiv_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 28504, 28503, 28491, 28492, 28493, 28494, 28495, 28496, 28497, 28498, 28499, 28500, 28502);\n";
cp.code() += "etiss_coverage_count(1, 28505);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28508, 28506, 28507);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28519);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28515, 28511, 28514, 28512, 28513);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28518, 28516, 28517);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28525);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28524, 28522, 28523);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28528, 28527);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28540, 28529, 28539, 28533, 28530, 28534, 28537, 28535, 28538);\n";
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
cp.code() += "etiss_coverage_count(1, 574);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28619);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28546, 28545);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28551, 28550);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28556, 28555);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28563, 28562, 28560, 28561);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28569, 28568, 28565, 28566, 28567);\n";
cp.code() += "etiss_uint32 ret = vfwmul_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 28582, 28581, 28571, 28572, 28573, 28574, 28575, 28576, 28577, 28578, 28579, 28580);\n";
cp.code() += "etiss_coverage_count(1, 28583);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28586, 28584, 28585);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28597);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28593, 28589, 28592, 28590, 28591);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28596, 28594, 28595);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28603);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28602, 28600, 28601);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28606, 28605);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28618, 28607, 28617, 28611, 28608, 28612, 28615, 28613, 28616);\n";
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
cp.code() += "etiss_coverage_count(1, 575);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28699);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28624, 28623);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28629, 28628);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28634, 28633);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28641, 28640, 28638, 28639);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28647, 28646, 28643, 28644, 28645);\n";
cp.code() += "etiss_uint32 ret = vfwmul_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 28662, 28661, 28649, 28650, 28651, 28652, 28653, 28654, 28655, 28656, 28657, 28658, 28660);\n";
cp.code() += "etiss_coverage_count(1, 28663);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28666, 28664, 28665);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28677);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28673, 28669, 28672, 28670, 28671);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28676, 28674, 28675);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28683);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28682, 28680, 28681);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28686, 28685);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28698, 28687, 28697, 28691, 28688, 28692, 28695, 28693, 28696);\n";
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
cp.code() += "etiss_coverage_count(1, 576);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28777);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28704, 28703);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28709, 28708);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28714, 28713);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28721, 28720, 28718, 28719);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28727, 28726, 28723, 28724, 28725);\n";
cp.code() += "etiss_uint32 ret = vfmacc_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 28740, 28739, 28729, 28730, 28731, 28732, 28733, 28734, 28735, 28736, 28737, 28738);\n";
cp.code() += "etiss_coverage_count(1, 28741);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28744, 28742, 28743);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28755);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28751, 28747, 28750, 28748, 28749);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28754, 28752, 28753);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28761);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28760, 28758, 28759);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28764, 28763);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28776, 28765, 28775, 28769, 28766, 28770, 28773, 28771, 28774);\n";
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
cp.code() += "etiss_coverage_count(1, 577);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28857);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28782, 28781);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28787, 28786);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28792, 28791);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28799, 28798, 28796, 28797);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28805, 28804, 28801, 28802, 28803);\n";
cp.code() += "etiss_uint32 ret = vfmacc_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 28820, 28819, 28807, 28808, 28809, 28810, 28811, 28812, 28813, 28814, 28815, 28816, 28818);\n";
cp.code() += "etiss_coverage_count(1, 28821);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28824, 28822, 28823);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28835);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28831, 28827, 28830, 28828, 28829);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28834, 28832, 28833);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28841);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28840, 28838, 28839);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28844, 28843);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28856, 28845, 28855, 28849, 28846, 28850, 28853, 28851, 28854);\n";
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
cp.code() += "etiss_coverage_count(1, 578);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28935);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28862, 28861);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28867, 28866);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28872, 28871);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28879, 28878, 28876, 28877);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28885, 28884, 28881, 28882, 28883);\n";
cp.code() += "etiss_uint32 ret = vfnmacc_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 28898, 28897, 28887, 28888, 28889, 28890, 28891, 28892, 28893, 28894, 28895, 28896);\n";
cp.code() += "etiss_coverage_count(1, 28899);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28902, 28900, 28901);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28913);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28909, 28905, 28908, 28906, 28907);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28912, 28910, 28911);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28919);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28918, 28916, 28917);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 28922, 28921);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 28934, 28923, 28933, 28927, 28924, 28928, 28931, 28929, 28932);\n";
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
cp.code() += "etiss_coverage_count(1, 579);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29015);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 28940, 28939);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 28945, 28944);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 28950, 28949);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 28957, 28956, 28954, 28955);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 28963, 28962, 28959, 28960, 28961);\n";
cp.code() += "etiss_uint32 ret = vfnmacc_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 28978, 28977, 28965, 28966, 28967, 28968, 28969, 28970, 28971, 28972, 28973, 28974, 28976);\n";
cp.code() += "etiss_coverage_count(1, 28979);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 28982, 28980, 28981);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28993);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 28989, 28985, 28988, 28986, 28987);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 28992, 28990, 28991);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28999);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 28998, 28996, 28997);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29002, 29001);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29014, 29003, 29013, 29007, 29004, 29008, 29011, 29009, 29012);\n";
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
cp.code() += "etiss_coverage_count(1, 580);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29093);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29020, 29019);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29025, 29024);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29030, 29029);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29037, 29036, 29034, 29035);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29043, 29042, 29039, 29040, 29041);\n";
cp.code() += "etiss_uint32 ret = vfmsac_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 29056, 29055, 29045, 29046, 29047, 29048, 29049, 29050, 29051, 29052, 29053, 29054);\n";
cp.code() += "etiss_coverage_count(1, 29057);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29060, 29058, 29059);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29071);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29067, 29063, 29066, 29064, 29065);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29070, 29068, 29069);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29077);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29076, 29074, 29075);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29080, 29079);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29092, 29081, 29091, 29085, 29082, 29086, 29089, 29087, 29090);\n";
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
cp.code() += "etiss_coverage_count(1, 581);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29173);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29098, 29097);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29103, 29102);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29108, 29107);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29115, 29114, 29112, 29113);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29121, 29120, 29117, 29118, 29119);\n";
cp.code() += "etiss_uint32 ret = vfmsac_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 29136, 29135, 29123, 29124, 29125, 29126, 29127, 29128, 29129, 29130, 29131, 29132, 29134);\n";
cp.code() += "etiss_coverage_count(1, 29137);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29140, 29138, 29139);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29151);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29147, 29143, 29146, 29144, 29145);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29150, 29148, 29149);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29157);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29156, 29154, 29155);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29160, 29159);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29172, 29161, 29171, 29165, 29162, 29166, 29169, 29167, 29170);\n";
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
cp.code() += "etiss_coverage_count(1, 582);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29251);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29178, 29177);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29183, 29182);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29188, 29187);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29195, 29194, 29192, 29193);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29201, 29200, 29197, 29198, 29199);\n";
cp.code() += "etiss_uint32 ret = vfnmsac_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 29214, 29213, 29203, 29204, 29205, 29206, 29207, 29208, 29209, 29210, 29211, 29212);\n";
cp.code() += "etiss_coverage_count(1, 29215);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29218, 29216, 29217);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29229);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29225, 29221, 29224, 29222, 29223);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29228, 29226, 29227);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29235);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29234, 29232, 29233);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29238, 29237);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29250, 29239, 29249, 29243, 29240, 29244, 29247, 29245, 29248);\n";
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
cp.code() += "etiss_coverage_count(1, 583);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29331);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29256, 29255);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29261, 29260);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29266, 29265);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29273, 29272, 29270, 29271);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29279, 29278, 29275, 29276, 29277);\n";
cp.code() += "etiss_uint32 ret = vfnmsac_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 29294, 29293, 29281, 29282, 29283, 29284, 29285, 29286, 29287, 29288, 29289, 29290, 29292);\n";
cp.code() += "etiss_coverage_count(1, 29295);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29298, 29296, 29297);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29309);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29305, 29301, 29304, 29302, 29303);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29308, 29306, 29307);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29315);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29314, 29312, 29313);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29318, 29317);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29330, 29319, 29329, 29323, 29320, 29324, 29327, 29325, 29328);\n";
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
cp.code() += "etiss_coverage_count(1, 584);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29409);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29336, 29335);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29341, 29340);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29346, 29345);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29353, 29352, 29350, 29351);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29359, 29358, 29355, 29356, 29357);\n";
cp.code() += "etiss_uint32 ret = vfmadd_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 29372, 29371, 29361, 29362, 29363, 29364, 29365, 29366, 29367, 29368, 29369, 29370);\n";
cp.code() += "etiss_coverage_count(1, 29373);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29376, 29374, 29375);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29387);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29383, 29379, 29382, 29380, 29381);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29386, 29384, 29385);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29393);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29392, 29390, 29391);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29396, 29395);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29408, 29397, 29407, 29401, 29398, 29402, 29405, 29403, 29406);\n";
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
cp.code() += "etiss_coverage_count(1, 585);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29489);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29414, 29413);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29419, 29418);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29424, 29423);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29431, 29430, 29428, 29429);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29437, 29436, 29433, 29434, 29435);\n";
cp.code() += "etiss_uint32 ret = vfmadd_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 29452, 29451, 29439, 29440, 29441, 29442, 29443, 29444, 29445, 29446, 29447, 29448, 29450);\n";
cp.code() += "etiss_coverage_count(1, 29453);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29456, 29454, 29455);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29467);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29463, 29459, 29462, 29460, 29461);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29466, 29464, 29465);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29473);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29472, 29470, 29471);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29476, 29475);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29488, 29477, 29487, 29481, 29478, 29482, 29485, 29483, 29486);\n";
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
cp.code() += "etiss_coverage_count(1, 586);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29567);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29494, 29493);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29499, 29498);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29504, 29503);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29511, 29510, 29508, 29509);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29517, 29516, 29513, 29514, 29515);\n";
cp.code() += "etiss_uint32 ret = vfnmadd_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 29530, 29529, 29519, 29520, 29521, 29522, 29523, 29524, 29525, 29526, 29527, 29528);\n";
cp.code() += "etiss_coverage_count(1, 29531);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29534, 29532, 29533);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29545);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29541, 29537, 29540, 29538, 29539);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29544, 29542, 29543);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29551);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29550, 29548, 29549);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29554, 29553);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29566, 29555, 29565, 29559, 29556, 29560, 29563, 29561, 29564);\n";
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
cp.code() += "etiss_coverage_count(1, 587);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29647);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29572, 29571);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29577, 29576);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29582, 29581);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29589, 29588, 29586, 29587);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29595, 29594, 29591, 29592, 29593);\n";
cp.code() += "etiss_uint32 ret = vfnmadd_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 29610, 29609, 29597, 29598, 29599, 29600, 29601, 29602, 29603, 29604, 29605, 29606, 29608);\n";
cp.code() += "etiss_coverage_count(1, 29611);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29614, 29612, 29613);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29625);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29621, 29617, 29620, 29618, 29619);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29624, 29622, 29623);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29631);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29630, 29628, 29629);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29634, 29633);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29646, 29635, 29645, 29639, 29636, 29640, 29643, 29641, 29644);\n";
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
cp.code() += "etiss_coverage_count(1, 588);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29725);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29652, 29651);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29657, 29656);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29662, 29661);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29669, 29668, 29666, 29667);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29675, 29674, 29671, 29672, 29673);\n";
cp.code() += "etiss_uint32 ret = vfmsub_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 29688, 29687, 29677, 29678, 29679, 29680, 29681, 29682, 29683, 29684, 29685, 29686);\n";
cp.code() += "etiss_coverage_count(1, 29689);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29692, 29690, 29691);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29703);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29699, 29695, 29698, 29696, 29697);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29702, 29700, 29701);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29709);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29708, 29706, 29707);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29712, 29711);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29724, 29713, 29723, 29717, 29714, 29718, 29721, 29719, 29722);\n";
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
cp.code() += "etiss_coverage_count(1, 589);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29805);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29730, 29729);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29735, 29734);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29740, 29739);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29747, 29746, 29744, 29745);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29753, 29752, 29749, 29750, 29751);\n";
cp.code() += "etiss_uint32 ret = vfmsub_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 29768, 29767, 29755, 29756, 29757, 29758, 29759, 29760, 29761, 29762, 29763, 29764, 29766);\n";
cp.code() += "etiss_coverage_count(1, 29769);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29772, 29770, 29771);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29783);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29779, 29775, 29778, 29776, 29777);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29782, 29780, 29781);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29789);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29788, 29786, 29787);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29792, 29791);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29804, 29793, 29803, 29797, 29794, 29798, 29801, 29799, 29802);\n";
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
cp.code() += "etiss_coverage_count(1, 590);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29883);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29810, 29809);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29815, 29814);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29820, 29819);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29827, 29826, 29824, 29825);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29833, 29832, 29829, 29830, 29831);\n";
cp.code() += "etiss_uint32 ret = vfnmsub_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 29846, 29845, 29835, 29836, 29837, 29838, 29839, 29840, 29841, 29842, 29843, 29844);\n";
cp.code() += "etiss_coverage_count(1, 29847);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29850, 29848, 29849);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29861);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29857, 29853, 29856, 29854, 29855);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29860, 29858, 29859);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29867);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29866, 29864, 29865);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29870, 29869);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29882, 29871, 29881, 29875, 29872, 29876, 29879, 29877, 29880);\n";
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
cp.code() += "etiss_coverage_count(1, 591);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 29963);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29888, 29887);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29893, 29892);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29898, 29897);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29905, 29904, 29902, 29903);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29911, 29910, 29907, 29908, 29909);\n";
cp.code() += "etiss_uint32 ret = vfnmsub_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 29926, 29925, 29913, 29914, 29915, 29916, 29917, 29918, 29919, 29920, 29921, 29922, 29924);\n";
cp.code() += "etiss_coverage_count(1, 29927);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 29930, 29928, 29929);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29941);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 29937, 29933, 29936, 29934, 29935);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 29940, 29938, 29939);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 29947);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 29946, 29944, 29945);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 29950, 29949);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 29962, 29951, 29961, 29955, 29952, 29956, 29959, 29957, 29960);\n";
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
cp.code() += "etiss_coverage_count(1, 592);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 30041);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 29968, 29967);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 29973, 29972);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 29978, 29977);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 29985, 29984, 29982, 29983);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 29991, 29990, 29987, 29988, 29989);\n";
cp.code() += "etiss_uint32 ret = vfwmacc_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 30004, 30003, 29993, 29994, 29995, 29996, 29997, 29998, 29999, 30000, 30001, 30002);\n";
cp.code() += "etiss_coverage_count(1, 30005);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 30008, 30006, 30007);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30019);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 30015, 30011, 30014, 30012, 30013);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 30018, 30016, 30017);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30025);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 30024, 30022, 30023);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 30028, 30027);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 30040, 30029, 30039, 30033, 30030, 30034, 30037, 30035, 30038);\n";
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
cp.code() += "etiss_coverage_count(1, 593);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 30121);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 30046, 30045);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 30051, 30050);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 30056, 30055);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 30063, 30062, 30060, 30061);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 30069, 30068, 30065, 30066, 30067);\n";
cp.code() += "etiss_uint32 ret = vfwmacc_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 30084, 30083, 30071, 30072, 30073, 30074, 30075, 30076, 30077, 30078, 30079, 30080, 30082);\n";
cp.code() += "etiss_coverage_count(1, 30085);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 30088, 30086, 30087);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30099);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 30095, 30091, 30094, 30092, 30093);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 30098, 30096, 30097);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30105);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 30104, 30102, 30103);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 30108, 30107);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 30120, 30109, 30119, 30113, 30110, 30114, 30117, 30115, 30118);\n";
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
cp.code() += "etiss_coverage_count(1, 594);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 30199);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 30126, 30125);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 30131, 30130);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 30136, 30135);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 30143, 30142, 30140, 30141);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 30149, 30148, 30145, 30146, 30147);\n";
cp.code() += "etiss_uint32 ret = vfwnmacc_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 30162, 30161, 30151, 30152, 30153, 30154, 30155, 30156, 30157, 30158, 30159, 30160);\n";
cp.code() += "etiss_coverage_count(1, 30163);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 30166, 30164, 30165);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30177);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 30173, 30169, 30172, 30170, 30171);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 30176, 30174, 30175);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30183);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 30182, 30180, 30181);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 30186, 30185);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 30198, 30187, 30197, 30191, 30188, 30192, 30195, 30193, 30196);\n";
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
cp.code() += "etiss_coverage_count(1, 595);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 30279);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 30204, 30203);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 30209, 30208);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 30214, 30213);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 30221, 30220, 30218, 30219);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 30227, 30226, 30223, 30224, 30225);\n";
cp.code() += "etiss_uint32 ret = vfwnmacc_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 30242, 30241, 30229, 30230, 30231, 30232, 30233, 30234, 30235, 30236, 30237, 30238, 30240);\n";
cp.code() += "etiss_coverage_count(1, 30243);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 30246, 30244, 30245);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30257);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 30253, 30249, 30252, 30250, 30251);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 30256, 30254, 30255);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30263);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 30262, 30260, 30261);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 30266, 30265);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 30278, 30267, 30277, 30271, 30268, 30272, 30275, 30273, 30276);\n";
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
cp.code() += "etiss_coverage_count(1, 596);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 30357);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 30284, 30283);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 30289, 30288);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 30294, 30293);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 30301, 30300, 30298, 30299);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 30307, 30306, 30303, 30304, 30305);\n";
cp.code() += "etiss_uint32 ret = vfwmsac_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 30320, 30319, 30309, 30310, 30311, 30312, 30313, 30314, 30315, 30316, 30317, 30318);\n";
cp.code() += "etiss_coverage_count(1, 30321);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 30324, 30322, 30323);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30335);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 30331, 30327, 30330, 30328, 30329);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 30334, 30332, 30333);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30341);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 30340, 30338, 30339);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 30344, 30343);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 30356, 30345, 30355, 30349, 30346, 30350, 30353, 30351, 30354);\n";
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
cp.code() += "etiss_coverage_count(1, 597);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 30437);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 30362, 30361);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 30367, 30366);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 30372, 30371);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 30379, 30378, 30376, 30377);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 30385, 30384, 30381, 30382, 30383);\n";
cp.code() += "etiss_uint32 ret = vfwmsac_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 30400, 30399, 30387, 30388, 30389, 30390, 30391, 30392, 30393, 30394, 30395, 30396, 30398);\n";
cp.code() += "etiss_coverage_count(1, 30401);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 30404, 30402, 30403);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30415);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 30411, 30407, 30410, 30408, 30409);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 30414, 30412, 30413);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30421);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 30420, 30418, 30419);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 30424, 30423);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 30436, 30425, 30435, 30429, 30426, 30430, 30433, 30431, 30434);\n";
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
cp.code() += "etiss_coverage_count(1, 598);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 30515);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 30442, 30441);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 30447, 30446);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 30452, 30451);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 30459, 30458, 30456, 30457);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 30465, 30464, 30461, 30462, 30463);\n";
cp.code() += "etiss_uint32 ret = vfwnmsac_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 30478, 30477, 30467, 30468, 30469, 30470, 30471, 30472, 30473, 30474, 30475, 30476);\n";
cp.code() += "etiss_coverage_count(1, 30479);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 30482, 30480, 30481);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30493);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 30489, 30485, 30488, 30486, 30487);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 30492, 30490, 30491);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30499);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 30498, 30496, 30497);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 30502, 30501);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 30514, 30503, 30513, 30507, 30504, 30508, 30511, 30509, 30512);\n";
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
cp.code() += "etiss_coverage_count(1, 599);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 30595);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 30520, 30519);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 30525, 30524);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 30530, 30529);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 30537, 30536, 30534, 30535);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 30543, 30542, 30539, 30540, 30541);\n";
cp.code() += "etiss_uint32 ret = vfwnmsac_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 30558, 30557, 30545, 30546, 30547, 30548, 30549, 30550, 30551, 30552, 30553, 30554, 30556);\n";
cp.code() += "etiss_coverage_count(1, 30559);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 30562, 30560, 30561);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30573);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 30569, 30565, 30568, 30566, 30567);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 30572, 30570, 30571);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30579);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 30578, 30576, 30577);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 30582, 30581);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 30594, 30583, 30593, 30587, 30584, 30588, 30591, 30589, 30592);\n";
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
cp.code() += "etiss_coverage_count(1, 600);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 30672);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 30600, 30599);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 30605, 30604);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 30610, 30609);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 30617, 30616, 30614, 30615);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 30623, 30622, 30619, 30620, 30621);\n";
cp.code() += "etiss_uint32 ret = vfsqrt_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 30635, 30634, 30625, 30626, 30627, 30628, 30629, 30630, 30631, 30632, 30633);\n";
cp.code() += "etiss_coverage_count(1, 30636);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 30639, 30637, 30638);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30650);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 30646, 30642, 30645, 30643, 30644);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 30649, 30647, 30648);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30656);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 30655, 30653, 30654);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 30659, 30658);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 30671, 30660, 30670, 30664, 30661, 30665, 30668, 30666, 30669);\n";
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
cp.code() += "etiss_coverage_count(1, 601);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 30749);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 30677, 30676);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 30682, 30681);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 30687, 30686);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 30694, 30693, 30691, 30692);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 30700, 30699, 30696, 30697, 30698);\n";
cp.code() += "etiss_uint32 ret = vfrsqrt7_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 30712, 30711, 30702, 30703, 30704, 30705, 30706, 30707, 30708, 30709, 30710);\n";
cp.code() += "etiss_coverage_count(1, 30713);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 30716, 30714, 30715);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30727);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 30723, 30719, 30722, 30720, 30721);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 30726, 30724, 30725);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30733);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 30732, 30730, 30731);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 30736, 30735);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 30748, 30737, 30747, 30741, 30738, 30742, 30745, 30743, 30746);\n";
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
cp.code() += "etiss_coverage_count(1, 602);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 30826);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 30754, 30753);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 30759, 30758);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 30764, 30763);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 30771, 30770, 30768, 30769);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 30777, 30776, 30773, 30774, 30775);\n";
cp.code() += "etiss_uint32 ret = vfrec7_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 30789, 30788, 30779, 30780, 30781, 30782, 30783, 30784, 30785, 30786, 30787);\n";
cp.code() += "etiss_coverage_count(1, 30790);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 30793, 30791, 30792);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30804);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 30800, 30796, 30799, 30797, 30798);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 30803, 30801, 30802);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30810);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 30809, 30807, 30808);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 30813, 30812);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 30825, 30814, 30824, 30818, 30815, 30819, 30822, 30820, 30823);\n";
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
cp.code() += "etiss_coverage_count(1, 603);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 30904);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 30831, 30830);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 30836, 30835);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 30841, 30840);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 30848, 30847, 30845, 30846);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 30854, 30853, 30850, 30851, 30852);\n";
cp.code() += "etiss_uint32 ret = vfmin_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 30867, 30866, 30856, 30857, 30858, 30859, 30860, 30861, 30862, 30863, 30864, 30865);\n";
cp.code() += "etiss_coverage_count(1, 30868);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 30871, 30869, 30870);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30882);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 30878, 30874, 30877, 30875, 30876);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 30881, 30879, 30880);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30888);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 30887, 30885, 30886);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 30891, 30890);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 30903, 30892, 30902, 30896, 30893, 30897, 30900, 30898, 30901);\n";
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
cp.code() += "etiss_coverage_count(1, 604);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 30984);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 30909, 30908);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 30914, 30913);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 30919, 30918);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 30926, 30925, 30923, 30924);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 30932, 30931, 30928, 30929, 30930);\n";
cp.code() += "etiss_uint32 ret = vfmin_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 30947, 30946, 30934, 30935, 30936, 30937, 30938, 30939, 30940, 30941, 30942, 30943, 30945);\n";
cp.code() += "etiss_coverage_count(1, 30948);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 30951, 30949, 30950);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30962);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 30958, 30954, 30957, 30955, 30956);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 30961, 30959, 30960);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 30968);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 30967, 30965, 30966);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 30971, 30970);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 30983, 30972, 30982, 30976, 30973, 30977, 30980, 30978, 30981);\n";
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
cp.code() += "etiss_coverage_count(1, 605);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 31062);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 30989, 30988);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 30994, 30993);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 30999, 30998);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 31006, 31005, 31003, 31004);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 31012, 31011, 31008, 31009, 31010);\n";
cp.code() += "etiss_uint32 ret = vfmax_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 31025, 31024, 31014, 31015, 31016, 31017, 31018, 31019, 31020, 31021, 31022, 31023);\n";
cp.code() += "etiss_coverage_count(1, 31026);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 31029, 31027, 31028);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31040);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 31036, 31032, 31035, 31033, 31034);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 31039, 31037, 31038);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31046);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 31045, 31043, 31044);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 31049, 31048);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 31061, 31050, 31060, 31054, 31051, 31055, 31058, 31056, 31059);\n";
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
cp.code() += "etiss_coverage_count(1, 606);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 31142);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 31067, 31066);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 31072, 31071);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 31077, 31076);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 31084, 31083, 31081, 31082);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 31090, 31089, 31086, 31087, 31088);\n";
cp.code() += "etiss_uint32 ret = vfmax_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 31105, 31104, 31092, 31093, 31094, 31095, 31096, 31097, 31098, 31099, 31100, 31101, 31103);\n";
cp.code() += "etiss_coverage_count(1, 31106);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 31109, 31107, 31108);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31120);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 31116, 31112, 31115, 31113, 31114);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 31119, 31117, 31118);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31126);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 31125, 31123, 31124);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 31129, 31128);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 31141, 31130, 31140, 31134, 31131, 31135, 31138, 31136, 31139);\n";
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
cp.code() += "etiss_coverage_count(1, 607);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 31220);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 31147, 31146);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 31152, 31151);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 31157, 31156);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 31164, 31163, 31161, 31162);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 31170, 31169, 31166, 31167, 31168);\n";
cp.code() += "etiss_uint32 ret = vfsgnj_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 31183, 31182, 31172, 31173, 31174, 31175, 31176, 31177, 31178, 31179, 31180, 31181);\n";
cp.code() += "etiss_coverage_count(1, 31184);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 31187, 31185, 31186);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31198);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 31194, 31190, 31193, 31191, 31192);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 31197, 31195, 31196);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31204);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 31203, 31201, 31202);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 31207, 31206);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 31219, 31208, 31218, 31212, 31209, 31213, 31216, 31214, 31217);\n";
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
cp.code() += "etiss_coverage_count(1, 608);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 31300);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 31225, 31224);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 31230, 31229);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 31235, 31234);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 31242, 31241, 31239, 31240);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 31248, 31247, 31244, 31245, 31246);\n";
cp.code() += "etiss_uint32 ret = vfsgnj_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 31263, 31262, 31250, 31251, 31252, 31253, 31254, 31255, 31256, 31257, 31258, 31259, 31261);\n";
cp.code() += "etiss_coverage_count(1, 31264);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 31267, 31265, 31266);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31278);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 31274, 31270, 31273, 31271, 31272);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 31277, 31275, 31276);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31284);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 31283, 31281, 31282);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 31287, 31286);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 31299, 31288, 31298, 31292, 31289, 31293, 31296, 31294, 31297);\n";
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
cp.code() += "etiss_coverage_count(1, 609);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 31378);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 31305, 31304);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 31310, 31309);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 31315, 31314);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 31322, 31321, 31319, 31320);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 31328, 31327, 31324, 31325, 31326);\n";
cp.code() += "etiss_uint32 ret = vfsgnjn_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 31341, 31340, 31330, 31331, 31332, 31333, 31334, 31335, 31336, 31337, 31338, 31339);\n";
cp.code() += "etiss_coverage_count(1, 31342);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 31345, 31343, 31344);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31356);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 31352, 31348, 31351, 31349, 31350);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 31355, 31353, 31354);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31362);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 31361, 31359, 31360);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 31365, 31364);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 31377, 31366, 31376, 31370, 31367, 31371, 31374, 31372, 31375);\n";
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
cp.code() += "etiss_coverage_count(1, 610);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 31458);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 31383, 31382);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 31388, 31387);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 31393, 31392);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 31400, 31399, 31397, 31398);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 31406, 31405, 31402, 31403, 31404);\n";
cp.code() += "etiss_uint32 ret = vfsgnjn_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 31421, 31420, 31408, 31409, 31410, 31411, 31412, 31413, 31414, 31415, 31416, 31417, 31419);\n";
cp.code() += "etiss_coverage_count(1, 31422);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 31425, 31423, 31424);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31436);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 31432, 31428, 31431, 31429, 31430);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 31435, 31433, 31434);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31442);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 31441, 31439, 31440);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 31445, 31444);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 31457, 31446, 31456, 31450, 31447, 31451, 31454, 31452, 31455);\n";
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
cp.code() += "etiss_coverage_count(1, 611);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 31536);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 31463, 31462);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 31468, 31467);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 31473, 31472);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 31480, 31479, 31477, 31478);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 31486, 31485, 31482, 31483, 31484);\n";
cp.code() += "etiss_uint32 ret = vfsgnjx_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 31499, 31498, 31488, 31489, 31490, 31491, 31492, 31493, 31494, 31495, 31496, 31497);\n";
cp.code() += "etiss_coverage_count(1, 31500);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 31503, 31501, 31502);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31514);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 31510, 31506, 31509, 31507, 31508);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 31513, 31511, 31512);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31520);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 31519, 31517, 31518);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 31523, 31522);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 31535, 31524, 31534, 31528, 31525, 31529, 31532, 31530, 31533);\n";
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
cp.code() += "etiss_coverage_count(1, 612);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 31616);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 31541, 31540);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 31546, 31545);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 31551, 31550);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 31558, 31557, 31555, 31556);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 31564, 31563, 31560, 31561, 31562);\n";
cp.code() += "etiss_uint32 ret = vfsgnjx_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 31579, 31578, 31566, 31567, 31568, 31569, 31570, 31571, 31572, 31573, 31574, 31575, 31577);\n";
cp.code() += "etiss_coverage_count(1, 31580);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 31583, 31581, 31582);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31594);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 31590, 31586, 31589, 31587, 31588);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 31593, 31591, 31592);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31600);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 31599, 31597, 31598);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 31603, 31602);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 31615, 31604, 31614, 31608, 31605, 31609, 31612, 31610, 31613);\n";
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
cp.code() += "etiss_coverage_count(1, 613);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 31694);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 31621, 31620);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 31626, 31625);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 31631, 31630);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 31638, 31637, 31635, 31636);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 31644, 31643, 31640, 31641, 31642);\n";
cp.code() += "etiss_uint32 ret = vmfeq_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 31657, 31656, 31646, 31647, 31648, 31649, 31650, 31651, 31652, 31653, 31654, 31655);\n";
cp.code() += "etiss_coverage_count(1, 31658);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 31661, 31659, 31660);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31672);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 31668, 31664, 31667, 31665, 31666);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 31671, 31669, 31670);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31678);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 31677, 31675, 31676);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 31681, 31680);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 31693, 31682, 31692, 31686, 31683, 31687, 31690, 31688, 31691);\n";
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
cp.code() += "etiss_coverage_count(1, 614);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 31774);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 31699, 31698);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 31704, 31703);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 31709, 31708);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 31716, 31715, 31713, 31714);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 31722, 31721, 31718, 31719, 31720);\n";
cp.code() += "etiss_uint32 ret = vmfeq_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 31737, 31736, 31724, 31725, 31726, 31727, 31728, 31729, 31730, 31731, 31732, 31733, 31735);\n";
cp.code() += "etiss_coverage_count(1, 31738);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 31741, 31739, 31740);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31752);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 31748, 31744, 31747, 31745, 31746);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 31751, 31749, 31750);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31758);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 31757, 31755, 31756);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 31761, 31760);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 31773, 31762, 31772, 31766, 31763, 31767, 31770, 31768, 31771);\n";
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
cp.code() += "etiss_coverage_count(1, 615);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 31852);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 31779, 31778);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 31784, 31783);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 31789, 31788);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 31796, 31795, 31793, 31794);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 31802, 31801, 31798, 31799, 31800);\n";
cp.code() += "etiss_uint32 ret = vmfne_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 31815, 31814, 31804, 31805, 31806, 31807, 31808, 31809, 31810, 31811, 31812, 31813);\n";
cp.code() += "etiss_coverage_count(1, 31816);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 31819, 31817, 31818);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31830);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 31826, 31822, 31825, 31823, 31824);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 31829, 31827, 31828);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31836);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 31835, 31833, 31834);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 31839, 31838);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 31851, 31840, 31850, 31844, 31841, 31845, 31848, 31846, 31849);\n";
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
cp.code() += "etiss_coverage_count(1, 616);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 31932);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 31857, 31856);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 31862, 31861);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 31867, 31866);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 31874, 31873, 31871, 31872);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 31880, 31879, 31876, 31877, 31878);\n";
cp.code() += "etiss_uint32 ret = vmfne_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 31895, 31894, 31882, 31883, 31884, 31885, 31886, 31887, 31888, 31889, 31890, 31891, 31893);\n";
cp.code() += "etiss_coverage_count(1, 31896);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 31899, 31897, 31898);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31910);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 31906, 31902, 31905, 31903, 31904);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 31909, 31907, 31908);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31916);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 31915, 31913, 31914);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 31919, 31918);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 31931, 31920, 31930, 31924, 31921, 31925, 31928, 31926, 31929);\n";
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
cp.code() += "etiss_coverage_count(1, 617);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 32010);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 31937, 31936);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 31942, 31941);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 31947, 31946);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 31954, 31953, 31951, 31952);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 31960, 31959, 31956, 31957, 31958);\n";
cp.code() += "etiss_uint32 ret = vmflt_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 31973, 31972, 31962, 31963, 31964, 31965, 31966, 31967, 31968, 31969, 31970, 31971);\n";
cp.code() += "etiss_coverage_count(1, 31974);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 31977, 31975, 31976);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31988);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 31984, 31980, 31983, 31981, 31982);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 31987, 31985, 31986);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 31994);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 31993, 31991, 31992);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 31997, 31996);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 32009, 31998, 32008, 32002, 31999, 32003, 32006, 32004, 32007);\n";
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
cp.code() += "etiss_coverage_count(1, 618);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 32090);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 32015, 32014);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 32020, 32019);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 32025, 32024);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 32032, 32031, 32029, 32030);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 32038, 32037, 32034, 32035, 32036);\n";
cp.code() += "etiss_uint32 ret = vmflt_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 32053, 32052, 32040, 32041, 32042, 32043, 32044, 32045, 32046, 32047, 32048, 32049, 32051);\n";
cp.code() += "etiss_coverage_count(1, 32054);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 32057, 32055, 32056);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32068);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 32064, 32060, 32063, 32061, 32062);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 32067, 32065, 32066);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32074);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 32073, 32071, 32072);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 32077, 32076);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 32089, 32078, 32088, 32082, 32079, 32083, 32086, 32084, 32087);\n";
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
cp.code() += "etiss_coverage_count(1, 619);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 32168);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 32095, 32094);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 32100, 32099);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 32105, 32104);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 32112, 32111, 32109, 32110);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 32118, 32117, 32114, 32115, 32116);\n";
cp.code() += "etiss_uint32 ret = vmfle_vv(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 32131, 32130, 32120, 32121, 32122, 32123, 32124, 32125, 32126, 32127, 32128, 32129);\n";
cp.code() += "etiss_coverage_count(1, 32132);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 32135, 32133, 32134);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32146);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 32142, 32138, 32141, 32139, 32140);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 32145, 32143, 32144);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32152);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 32151, 32149, 32150);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 32155, 32154);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 32167, 32156, 32166, 32160, 32157, 32161, 32164, 32162, 32165);\n";
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
cp.code() += "etiss_coverage_count(1, 620);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 32248);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 32173, 32172);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 32178, 32177);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 32183, 32182);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 32190, 32189, 32187, 32188);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 32196, 32195, 32192, 32193, 32194);\n";
cp.code() += "etiss_uint32 ret = vmfle_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 32211, 32210, 32198, 32199, 32200, 32201, 32202, 32203, 32204, 32205, 32206, 32207, 32209);\n";
cp.code() += "etiss_coverage_count(1, 32212);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 32215, 32213, 32214);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32226);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 32222, 32218, 32221, 32219, 32220);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 32225, 32223, 32224);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32232);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 32231, 32229, 32230);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 32235, 32234);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 32247, 32236, 32246, 32240, 32237, 32241, 32244, 32242, 32245);\n";
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
cp.code() += "etiss_coverage_count(1, 621);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 32328);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 32253, 32252);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 32258, 32257);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 32263, 32262);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 32270, 32269, 32267, 32268);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 32276, 32275, 32272, 32273, 32274);\n";
cp.code() += "etiss_uint32 ret = vmfgt_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 32291, 32290, 32278, 32279, 32280, 32281, 32282, 32283, 32284, 32285, 32286, 32287, 32289);\n";
cp.code() += "etiss_coverage_count(1, 32292);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 32295, 32293, 32294);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32306);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 32302, 32298, 32301, 32299, 32300);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 32305, 32303, 32304);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32312);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 32311, 32309, 32310);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 32315, 32314);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 32327, 32316, 32326, 32320, 32317, 32321, 32324, 32322, 32325);\n";
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
cp.code() += "etiss_coverage_count(1, 622);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 32408);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 32333, 32332);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 32338, 32337);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 32343, 32342);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 32350, 32349, 32347, 32348);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 32356, 32355, 32352, 32353, 32354);\n";
cp.code() += "etiss_uint32 ret = vmfge_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(13, 32371, 32370, 32358, 32359, 32360, 32361, 32362, 32363, 32364, 32365, 32366, 32367, 32369);\n";
cp.code() += "etiss_coverage_count(1, 32372);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 32375, 32373, 32374);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32386);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 32382, 32378, 32381, 32379, 32380);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 32385, 32383, 32384);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32392);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 32391, 32389, 32390);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 32395, 32394);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 32407, 32396, 32406, 32400, 32397, 32401, 32404, 32402, 32405);\n";
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
cp.code() += "etiss_coverage_count(1, 623);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 32485);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 32413, 32412);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 32418, 32417);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 32423, 32422);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 32430, 32429, 32427, 32428);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 32436, 32435, 32432, 32433, 32434);\n";
cp.code() += "etiss_uint32 ret = vfclass_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 32448, 32447, 32438, 32439, 32440, 32441, 32442, 32443, 32444, 32445, 32446);\n";
cp.code() += "etiss_coverage_count(1, 32449);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 32452, 32450, 32451);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32463);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 32459, 32455, 32458, 32456, 32457);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 32462, 32460, 32461);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32469);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 32468, 32466, 32467);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 32472, 32471);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 32484, 32473, 32483, 32477, 32474, 32478, 32481, 32479, 32482);\n";
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
cp.code() += "etiss_coverage_count(1, 624);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 32557);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 32490, 32489);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 32495, 32494);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 32500, 32499);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 32507, 32506, 32504, 32505);\n";
cp.code() += "etiss_uint32 ret = vfmerge_vfm(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL);\n";
cp.code() += "etiss_coverage_count(11, 32520, 32519, 32509, 32510, 32511, 32512, 32513, 32514, 32515, 32516, 32517);\n";
cp.code() += "etiss_coverage_count(1, 32521);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 32524, 32522, 32523);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32535);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 32531, 32527, 32530, 32528, 32529);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 32534, 32532, 32533);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32541);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 32540, 32538, 32539);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 32544, 32543);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 32556, 32545, 32555, 32549, 32546, 32550, 32553, 32551, 32554);\n";
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
cp.code() += "etiss_coverage_count(1, 625);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 32628);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 32562, 32561);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 32567, 32566);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 32572, 32571);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 32579, 32578, 32576, 32577);\n";
cp.code() += "etiss_uint32 ret = vfmv_v_f(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vd) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL);\n";
cp.code() += "etiss_coverage_count(10, 32591, 32590, 32581, 32582, 32583, 32584, 32585, 32586, 32587, 32588);\n";
cp.code() += "etiss_coverage_count(1, 32592);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 32595, 32593, 32594);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32606);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 32602, 32598, 32601, 32599, 32600);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 32605, 32603, 32604);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32612);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 32611, 32609, 32610);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 32615, 32614);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 32627, 32616, 32626, 32620, 32617, 32621, 32624, 32622, 32625);\n";
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
cp.code() += "etiss_coverage_count(1, 626);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 32705);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 32633, 32632);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 32638, 32637);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 32643, 32642);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 32650, 32649, 32647, 32648);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 32656, 32655, 32652, 32653, 32654);\n";
cp.code() += "etiss_uint32 ret = vfcvt_xu_f_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 32668, 32667, 32658, 32659, 32660, 32661, 32662, 32663, 32664, 32665, 32666);\n";
cp.code() += "etiss_coverage_count(1, 32669);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 32672, 32670, 32671);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32683);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 32679, 32675, 32678, 32676, 32677);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 32682, 32680, 32681);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32689);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 32688, 32686, 32687);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 32692, 32691);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 32704, 32693, 32703, 32697, 32694, 32698, 32701, 32699, 32702);\n";
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
cp.code() += "etiss_coverage_count(1, 627);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 32782);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 32710, 32709);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 32715, 32714);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 32720, 32719);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 32727, 32726, 32724, 32725);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 32733, 32732, 32729, 32730, 32731);\n";
cp.code() += "etiss_uint32 ret = vfcvt_x_f_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 32745, 32744, 32735, 32736, 32737, 32738, 32739, 32740, 32741, 32742, 32743);\n";
cp.code() += "etiss_coverage_count(1, 32746);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 32749, 32747, 32748);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32760);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 32756, 32752, 32755, 32753, 32754);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 32759, 32757, 32758);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32766);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 32765, 32763, 32764);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 32769, 32768);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 32781, 32770, 32780, 32774, 32771, 32775, 32778, 32776, 32779);\n";
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
cp.code() += "etiss_coverage_count(1, 628);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 32859);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 32787, 32786);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 32792, 32791);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 32797, 32796);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 32804, 32803, 32801, 32802);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 32810, 32809, 32806, 32807, 32808);\n";
cp.code() += "etiss_uint32 ret = vfcvt_rtz_xu_f_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 32822, 32821, 32812, 32813, 32814, 32815, 32816, 32817, 32818, 32819, 32820);\n";
cp.code() += "etiss_coverage_count(1, 32823);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 32826, 32824, 32825);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32837);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 32833, 32829, 32832, 32830, 32831);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 32836, 32834, 32835);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32843);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 32842, 32840, 32841);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 32846, 32845);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 32858, 32847, 32857, 32851, 32848, 32852, 32855, 32853, 32856);\n";
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
cp.code() += "etiss_coverage_count(1, 629);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 32936);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 32864, 32863);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 32869, 32868);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 32874, 32873);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 32881, 32880, 32878, 32879);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 32887, 32886, 32883, 32884, 32885);\n";
cp.code() += "etiss_uint32 ret = vfcvt_rtz_x_f_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 32899, 32898, 32889, 32890, 32891, 32892, 32893, 32894, 32895, 32896, 32897);\n";
cp.code() += "etiss_coverage_count(1, 32900);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 32903, 32901, 32902);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32914);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 32910, 32906, 32909, 32907, 32908);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 32913, 32911, 32912);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32920);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 32919, 32917, 32918);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 32923, 32922);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 32935, 32924, 32934, 32928, 32925, 32929, 32932, 32930, 32933);\n";
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
cp.code() += "etiss_coverage_count(1, 630);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 33013);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 32941, 32940);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 32946, 32945);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 32951, 32950);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 32958, 32957, 32955, 32956);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 32964, 32963, 32960, 32961, 32962);\n";
cp.code() += "etiss_uint32 ret = vfcvt_f_xu_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 32976, 32975, 32966, 32967, 32968, 32969, 32970, 32971, 32972, 32973, 32974);\n";
cp.code() += "etiss_coverage_count(1, 32977);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 32980, 32978, 32979);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32991);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 32987, 32983, 32986, 32984, 32985);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 32990, 32988, 32989);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 32997);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 32996, 32994, 32995);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 33000, 32999);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 33012, 33001, 33011, 33005, 33002, 33006, 33009, 33007, 33010);\n";
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
cp.code() += "etiss_coverage_count(1, 631);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 33090);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 33018, 33017);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 33023, 33022);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 33028, 33027);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 33035, 33034, 33032, 33033);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 33041, 33040, 33037, 33038, 33039);\n";
cp.code() += "etiss_uint32 ret = vfcvt_f_x_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 33053, 33052, 33043, 33044, 33045, 33046, 33047, 33048, 33049, 33050, 33051);\n";
cp.code() += "etiss_coverage_count(1, 33054);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 33057, 33055, 33056);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33068);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 33064, 33060, 33063, 33061, 33062);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 33067, 33065, 33066);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33074);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 33073, 33071, 33072);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 33077, 33076);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 33089, 33078, 33088, 33082, 33079, 33083, 33086, 33084, 33087);\n";
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
cp.code() += "etiss_coverage_count(1, 632);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 33167);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 33095, 33094);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 33100, 33099);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 33105, 33104);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 33112, 33111, 33109, 33110);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 33118, 33117, 33114, 33115, 33116);\n";
cp.code() += "etiss_uint32 ret = vfwcvt_xu_f_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 33130, 33129, 33120, 33121, 33122, 33123, 33124, 33125, 33126, 33127, 33128);\n";
cp.code() += "etiss_coverage_count(1, 33131);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 33134, 33132, 33133);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33145);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 33141, 33137, 33140, 33138, 33139);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 33144, 33142, 33143);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33151);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 33150, 33148, 33149);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 33154, 33153);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 33166, 33155, 33165, 33159, 33156, 33160, 33163, 33161, 33164);\n";
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
cp.code() += "etiss_coverage_count(1, 633);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 33244);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 33172, 33171);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 33177, 33176);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 33182, 33181);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 33189, 33188, 33186, 33187);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 33195, 33194, 33191, 33192, 33193);\n";
cp.code() += "etiss_uint32 ret = vfwcvt_x_f_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 33207, 33206, 33197, 33198, 33199, 33200, 33201, 33202, 33203, 33204, 33205);\n";
cp.code() += "etiss_coverage_count(1, 33208);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 33211, 33209, 33210);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33222);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 33218, 33214, 33217, 33215, 33216);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 33221, 33219, 33220);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33228);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 33227, 33225, 33226);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 33231, 33230);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 33243, 33232, 33242, 33236, 33233, 33237, 33240, 33238, 33241);\n";
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
cp.code() += "etiss_coverage_count(1, 634);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 33321);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 33249, 33248);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 33254, 33253);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 33259, 33258);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 33266, 33265, 33263, 33264);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 33272, 33271, 33268, 33269, 33270);\n";
cp.code() += "etiss_uint32 ret = vfwcvt_rtz_xu_f_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 33284, 33283, 33274, 33275, 33276, 33277, 33278, 33279, 33280, 33281, 33282);\n";
cp.code() += "etiss_coverage_count(1, 33285);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 33288, 33286, 33287);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33299);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 33295, 33291, 33294, 33292, 33293);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 33298, 33296, 33297);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33305);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 33304, 33302, 33303);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 33308, 33307);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 33320, 33309, 33319, 33313, 33310, 33314, 33317, 33315, 33318);\n";
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
cp.code() += "etiss_coverage_count(1, 635);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 33398);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 33326, 33325);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 33331, 33330);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 33336, 33335);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 33343, 33342, 33340, 33341);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 33349, 33348, 33345, 33346, 33347);\n";
cp.code() += "etiss_uint32 ret = vfwcvt_rtz_x_f_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 33361, 33360, 33351, 33352, 33353, 33354, 33355, 33356, 33357, 33358, 33359);\n";
cp.code() += "etiss_coverage_count(1, 33362);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 33365, 33363, 33364);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33376);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 33372, 33368, 33371, 33369, 33370);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 33375, 33373, 33374);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33382);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 33381, 33379, 33380);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 33385, 33384);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 33397, 33386, 33396, 33390, 33387, 33391, 33394, 33392, 33395);\n";
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
cp.code() += "etiss_coverage_count(1, 636);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 33475);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 33403, 33402);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 33408, 33407);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 33413, 33412);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 33420, 33419, 33417, 33418);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 33426, 33425, 33422, 33423, 33424);\n";
cp.code() += "etiss_uint32 ret = vfwcvt_f_xu_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 33438, 33437, 33428, 33429, 33430, 33431, 33432, 33433, 33434, 33435, 33436);\n";
cp.code() += "etiss_coverage_count(1, 33439);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 33442, 33440, 33441);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33453);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 33449, 33445, 33448, 33446, 33447);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 33452, 33450, 33451);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33459);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 33458, 33456, 33457);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 33462, 33461);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 33474, 33463, 33473, 33467, 33464, 33468, 33471, 33469, 33472);\n";
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
cp.code() += "etiss_coverage_count(1, 637);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 33552);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 33480, 33479);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 33485, 33484);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 33490, 33489);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 33497, 33496, 33494, 33495);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 33503, 33502, 33499, 33500, 33501);\n";
cp.code() += "etiss_uint32 ret = vfwcvt_f_x_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 33515, 33514, 33505, 33506, 33507, 33508, 33509, 33510, 33511, 33512, 33513);\n";
cp.code() += "etiss_coverage_count(1, 33516);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 33519, 33517, 33518);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33530);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 33526, 33522, 33525, 33523, 33524);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 33529, 33527, 33528);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33536);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 33535, 33533, 33534);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 33539, 33538);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 33551, 33540, 33550, 33544, 33541, 33545, 33548, 33546, 33549);\n";
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
cp.code() += "etiss_coverage_count(1, 638);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 33629);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 33557, 33556);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 33562, 33561);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 33567, 33566);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 33574, 33573, 33571, 33572);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 33580, 33579, 33576, 33577, 33578);\n";
cp.code() += "etiss_uint32 ret = vfwcvt_f_f_v(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 33592, 33591, 33582, 33583, 33584, 33585, 33586, 33587, 33588, 33589, 33590);\n";
cp.code() += "etiss_coverage_count(1, 33593);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 33596, 33594, 33595);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33607);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 33603, 33599, 33602, 33600, 33601);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 33606, 33604, 33605);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33613);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 33612, 33610, 33611);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 33616, 33615);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 33628, 33617, 33627, 33621, 33618, 33622, 33625, 33623, 33626);\n";
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
cp.code() += "etiss_coverage_count(1, 639);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 33706);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 33634, 33633);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 33639, 33638);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 33644, 33643);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 33651, 33650, 33648, 33649);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 33657, 33656, 33653, 33654, 33655);\n";
cp.code() += "etiss_uint32 ret = vfncvt_xu_f_w(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 33669, 33668, 33659, 33660, 33661, 33662, 33663, 33664, 33665, 33666, 33667);\n";
cp.code() += "etiss_coverage_count(1, 33670);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 33673, 33671, 33672);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33684);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 33680, 33676, 33679, 33677, 33678);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 33683, 33681, 33682);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33690);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 33689, 33687, 33688);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 33693, 33692);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 33705, 33694, 33704, 33698, 33695, 33699, 33702, 33700, 33703);\n";
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
cp.code() += "etiss_coverage_count(1, 640);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 33783);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 33711, 33710);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 33716, 33715);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 33721, 33720);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 33728, 33727, 33725, 33726);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 33734, 33733, 33730, 33731, 33732);\n";
cp.code() += "etiss_uint32 ret = vfncvt_x_f_w(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 33746, 33745, 33736, 33737, 33738, 33739, 33740, 33741, 33742, 33743, 33744);\n";
cp.code() += "etiss_coverage_count(1, 33747);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 33750, 33748, 33749);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33761);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 33757, 33753, 33756, 33754, 33755);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 33760, 33758, 33759);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33767);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 33766, 33764, 33765);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 33770, 33769);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 33782, 33771, 33781, 33775, 33772, 33776, 33779, 33777, 33780);\n";
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
cp.code() += "etiss_coverage_count(1, 641);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 33860);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 33788, 33787);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 33793, 33792);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 33798, 33797);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 33805, 33804, 33802, 33803);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 33811, 33810, 33807, 33808, 33809);\n";
cp.code() += "etiss_uint32 ret = vfncvt_rtz_xu_f_w(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 33823, 33822, 33813, 33814, 33815, 33816, 33817, 33818, 33819, 33820, 33821);\n";
cp.code() += "etiss_coverage_count(1, 33824);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 33827, 33825, 33826);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33838);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 33834, 33830, 33833, 33831, 33832);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 33837, 33835, 33836);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33844);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 33843, 33841, 33842);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 33847, 33846);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 33859, 33848, 33858, 33852, 33849, 33853, 33856, 33854, 33857);\n";
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
cp.code() += "etiss_coverage_count(1, 642);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 33937);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 33865, 33864);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 33870, 33869);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 33875, 33874);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 33882, 33881, 33879, 33880);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 33888, 33887, 33884, 33885, 33886);\n";
cp.code() += "etiss_uint32 ret = vfncvt_rtz_x_f_w(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 33900, 33899, 33890, 33891, 33892, 33893, 33894, 33895, 33896, 33897, 33898);\n";
cp.code() += "etiss_coverage_count(1, 33901);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 33904, 33902, 33903);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33915);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 33911, 33907, 33910, 33908, 33909);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 33914, 33912, 33913);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33921);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 33920, 33918, 33919);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 33924, 33923);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 33936, 33925, 33935, 33929, 33926, 33930, 33933, 33931, 33934);\n";
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
cp.code() += "etiss_coverage_count(1, 643);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 34014);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 33942, 33941);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 33947, 33946);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 33952, 33951);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 33959, 33958, 33956, 33957);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 33965, 33964, 33961, 33962, 33963);\n";
cp.code() += "etiss_uint32 ret = vfncvt_f_xu_w(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 33977, 33976, 33967, 33968, 33969, 33970, 33971, 33972, 33973, 33974, 33975);\n";
cp.code() += "etiss_coverage_count(1, 33978);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 33981, 33979, 33980);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33992);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 33988, 33984, 33987, 33985, 33986);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 33991, 33989, 33990);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 33998);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 33997, 33995, 33996);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 34001, 34000);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 34013, 34002, 34012, 34006, 34003, 34007, 34010, 34008, 34011);\n";
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
cp.code() += "etiss_coverage_count(1, 644);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 34091);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 34019, 34018);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 34024, 34023);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 34029, 34028);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 34036, 34035, 34033, 34034);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 34042, 34041, 34038, 34039, 34040);\n";
cp.code() += "etiss_uint32 ret = vfncvt_f_x_w(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 34054, 34053, 34044, 34045, 34046, 34047, 34048, 34049, 34050, 34051, 34052);\n";
cp.code() += "etiss_coverage_count(1, 34055);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 34058, 34056, 34057);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34069);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 34065, 34061, 34064, 34062, 34063);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 34068, 34066, 34067);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34075);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 34074, 34072, 34073);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 34078, 34077);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 34090, 34079, 34089, 34083, 34080, 34084, 34087, 34085, 34088);\n";
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
cp.code() += "etiss_coverage_count(1, 645);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 34168);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 34096, 34095);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 34101, 34100);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 34106, 34105);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 34113, 34112, 34110, 34111);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 34119, 34118, 34115, 34116, 34117);\n";
cp.code() += "etiss_uint32 ret = vfncvt_f_f_w(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 34131, 34130, 34121, 34122, 34123, 34124, 34125, 34126, 34127, 34128, 34129);\n";
cp.code() += "etiss_coverage_count(1, 34132);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 34135, 34133, 34134);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34146);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 34142, 34138, 34141, 34139, 34140);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 34145, 34143, 34144);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34152);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 34151, 34149, 34150);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 34155, 34154);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 34167, 34156, 34166, 34160, 34157, 34161, 34164, 34162, 34165);\n";
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
cp.code() += "etiss_coverage_count(1, 646);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 34245);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 34173, 34172);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 34178, 34177);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 34183, 34182);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 34190, 34189, 34187, 34188);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 34196, 34195, 34192, 34193, 34194);\n";
cp.code() += "etiss_uint32 ret = vfncvt_rod_f_f_w(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(11, 34208, 34207, 34198, 34199, 34200, 34201, 34202, 34203, 34204, 34205, 34206);\n";
cp.code() += "etiss_coverage_count(1, 34209);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 34212, 34210, 34211);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34223);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 34219, 34215, 34218, 34216, 34217);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 34222, 34220, 34221);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34229);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 34228, 34226, 34227);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 34232, 34231);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 34244, 34233, 34243, 34237, 34234, 34238, 34241, 34239, 34242);\n";
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
cp.code() += "etiss_coverage_count(1, 647);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 34323);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 34250, 34249);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 34255, 34254);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 34260, 34259);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 34267, 34266, 34264, 34265);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 34273, 34272, 34269, 34270, 34271);\n";
cp.code() += "etiss_uint32 ret = vfredosum_vs(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 34286, 34285, 34275, 34276, 34277, 34278, 34279, 34280, 34281, 34282, 34283, 34284);\n";
cp.code() += "etiss_coverage_count(1, 34287);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 34290, 34288, 34289);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34301);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 34297, 34293, 34296, 34294, 34295);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 34300, 34298, 34299);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34307);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 34306, 34304, 34305);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 34310, 34309);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 34322, 34311, 34321, 34315, 34312, 34316, 34319, 34317, 34320);\n";
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
cp.code() += "etiss_coverage_count(1, 648);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 34401);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 34328, 34327);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 34333, 34332);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 34338, 34337);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 34345, 34344, 34342, 34343);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 34351, 34350, 34347, 34348, 34349);\n";
cp.code() += "etiss_uint32 ret = vfredusum_vs(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 34364, 34363, 34353, 34354, 34355, 34356, 34357, 34358, 34359, 34360, 34361, 34362);\n";
cp.code() += "etiss_coverage_count(1, 34365);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 34368, 34366, 34367);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34379);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 34375, 34371, 34374, 34372, 34373);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 34378, 34376, 34377);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34385);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 34384, 34382, 34383);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 34388, 34387);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 34400, 34389, 34399, 34393, 34390, 34394, 34397, 34395, 34398);\n";
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
cp.code() += "etiss_coverage_count(1, 649);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 34479);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 34406, 34405);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 34411, 34410);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 34416, 34415);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 34423, 34422, 34420, 34421);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 34429, 34428, 34425, 34426, 34427);\n";
cp.code() += "etiss_uint32 ret = vfredmax_vs(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 34442, 34441, 34431, 34432, 34433, 34434, 34435, 34436, 34437, 34438, 34439, 34440);\n";
cp.code() += "etiss_coverage_count(1, 34443);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 34446, 34444, 34445);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34457);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 34453, 34449, 34452, 34450, 34451);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 34456, 34454, 34455);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34463);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 34462, 34460, 34461);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 34466, 34465);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 34478, 34467, 34477, 34471, 34468, 34472, 34475, 34473, 34476);\n";
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
cp.code() += "etiss_coverage_count(1, 650);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 34557);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 34484, 34483);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 34489, 34488);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 34494, 34493);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 34501, 34500, 34498, 34499);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 34507, 34506, 34503, 34504, 34505);\n";
cp.code() += "etiss_uint32 ret = vfredmin_vs(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 34520, 34519, 34509, 34510, 34511, 34512, 34513, 34514, 34515, 34516, 34517, 34518);\n";
cp.code() += "etiss_coverage_count(1, 34521);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 34524, 34522, 34523);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34535);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 34531, 34527, 34530, 34528, 34529);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 34534, 34532, 34533);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34541);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 34540, 34538, 34539);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 34544, 34543);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 34556, 34545, 34555, 34549, 34546, 34550, 34553, 34551, 34554);\n";
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
cp.code() += "etiss_coverage_count(1, 651);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 34635);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 34562, 34561);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 34567, 34566);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 34572, 34571);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 34579, 34578, 34576, 34577);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 34585, 34584, 34581, 34582, 34583);\n";
cp.code() += "etiss_uint32 ret = vfwredosum_vs(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 34598, 34597, 34587, 34588, 34589, 34590, 34591, 34592, 34593, 34594, 34595, 34596);\n";
cp.code() += "etiss_coverage_count(1, 34599);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 34602, 34600, 34601);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34613);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 34609, 34605, 34608, 34606, 34607);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 34612, 34610, 34611);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34619);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 34618, 34616, 34617);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 34622, 34621);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 34634, 34623, 34633, 34627, 34624, 34628, 34631, 34629, 34632);\n";
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
cp.code() += "etiss_coverage_count(1, 652);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 34713);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 34640, 34639);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 34645, 34644);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 34650, 34649);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 34657, 34656, 34654, 34655);\n";
cp.code() += "etiss_uint32 _rounding_mode = (((((RV32IMACFDV_zvl128b*)cpu)->FCSR) >> (5ULL)) & 0x7ULL);\n";
cp.code() += "etiss_coverage_count(5, 34663, 34662, 34659, 34660, 34661);\n";
cp.code() += "etiss_uint32 ret = vfwredusum_vs(((RV32IMACFDV_zvl128b*)cpu)->V, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs1) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, _rounding_mode);\n";
cp.code() += "etiss_coverage_count(12, 34676, 34675, 34665, 34666, 34667, 34668, 34669, 34670, 34671, 34672, 34673, 34674);\n";
cp.code() += "etiss_coverage_count(1, 34677);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 34680, 34678, 34679);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34691);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 34687, 34683, 34686, 34684, 34685);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 34690, 34688, 34689);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34697);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 34696, 34694, 34695);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 34700, 34699);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FCSR = (((RV32IMACFDV_zvl128b*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 34712, 34701, 34711, 34705, 34702, 34706, 34709, 34707, 34710);\n";
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
cp.code() += "etiss_coverage_count(1, 653);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 34769);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 34718, 34717);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 34723, 34722);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 34728, 34727);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 34735, 34734, 34732, 34733);\n";
cp.code() += "etiss_uint32 ret = vfmv_f_s(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(rd) + "ULL, " + std::to_string(vs2) + "ULL, _vstart, _vlen, _vl, 32ULL);\n";
cp.code() += "etiss_coverage_count(10, 34747, 34746, 34737, 34738, 34739, 34740, 34741, 34742, 34743, 34744);\n";
cp.code() += "etiss_coverage_count(1, 34748);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 34751, 34749, 34750);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34762);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 34758, 34754, 34757, 34755, 34756);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 34761, 34759, 34760);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34768);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 34767, 34765, 34766);\n";
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
cp.code() += "etiss_coverage_count(1, 654);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 34825);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 34774, 34773);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 34779, 34778);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 34784, 34783);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 34791, 34790, 34788, 34789);\n";
cp.code() += "etiss_uint32 ret = vfmv_s_f(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vd) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL);\n";
cp.code() += "etiss_coverage_count(10, 34803, 34802, 34793, 34794, 34795, 34796, 34797, 34798, 34799, 34800);\n";
cp.code() += "etiss_coverage_count(1, 34804);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 34807, 34805, 34806);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34818);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 34814, 34810, 34813, 34811, 34812);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 34817, 34815, 34816);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34824);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 34823, 34821, 34822);\n";
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
cp.code() += "etiss_coverage_count(1, 655);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 34883);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 34830, 34829);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 34835, 34834);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 34840, 34839);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 34847, 34846, 34844, 34845);\n";
cp.code() += "etiss_uint32 ret = vfslide1up_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL);\n";
cp.code() += "etiss_coverage_count(12, 34861, 34860, 34849, 34850, 34851, 34852, 34853, 34854, 34855, 34856, 34857, 34858);\n";
cp.code() += "etiss_coverage_count(1, 34862);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 34865, 34863, 34864);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34876);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 34872, 34868, 34871, 34869, 34870);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 34875, 34873, 34874);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34882);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 34881, 34879, 34880);\n";
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
cp.code() += "etiss_coverage_count(1, 656);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 34941);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 _vtype = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3105ULL];\n";
cp.code() += "etiss_coverage_count(2, 34888, 34887);\n";
cp.code() += "etiss_uint32 _vstart = *((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL];\n";
cp.code() += "etiss_coverage_count(2, 34893, 34892);\n";
cp.code() += "etiss_uint32 _vl = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3104ULL];\n";
cp.code() += "etiss_coverage_count(2, 34898, 34897);\n";
cp.code() += "etiss_uint32 _vlen = *((RV32IMACFDV_zvl128b*)cpu)->CSR[3106ULL] * 8ULL;\n";
cp.code() += "etiss_coverage_count(4, 34905, 34904, 34902, 34903);\n";
cp.code() += "etiss_uint32 ret = vfslide1down_vf(((RV32IMACFDV_zvl128b*)cpu)->V, *((RV32IMACFDV_zvl128b*)cpu)->F, _vtype, " + std::to_string(vm) + "ULL, " + std::to_string(vd) + "ULL, " + std::to_string(vs2) + "ULL, " + std::to_string(rs1) + "ULL, _vstart, _vlen, _vl, 32ULL);\n";
cp.code() += "etiss_coverage_count(12, 34919, 34918, 34907, 34908, 34909, 34910, 34911, 34912, 34913, 34914, 34915, 34916);\n";
cp.code() += "etiss_coverage_count(1, 34920);\n";
cp.code() += "if (ret != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 34923, 34921, 34922);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34934);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = ret >> 8ULL;\n";
cp.code() += "etiss_coverage_count(5, 34930, 34926, 34929, 34927, 34928);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 34933, 34931, 34932);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 34940);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->CSR[8ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(3, 34939, 34937, 34938);\n";
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
