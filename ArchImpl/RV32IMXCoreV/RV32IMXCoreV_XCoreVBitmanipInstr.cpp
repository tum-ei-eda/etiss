// clang-format off
/**
 * Generated on Wed, 05 Aug 2026 14:56:03 +0200.
 *
 * This file contains the instruction behavior models of the XCoreVBitmanip
 * instruction set for the RV32IMXCoreV core architecture.
 */

#include "RV32IMXCoreVArch.h"
#include "RV32IMXCoreVFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// CV_EXTRACT ------------------------------------------------------------------
static InstructionDefinition cv_extract_rd_rs1_Iuimm5_Luimm5 (
	ISA32_RV32IMXCoreV,
	"cv_extract",
	(uint64_t) 0x00005b,
	(uint64_t) 0xc000707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 Iuimm5 = 0;
static BitArrayRange R_Iuimm5_0(24, 20);
Iuimm5 += R_Iuimm5_0.read(ba) << 0;
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_EXTRACT\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 369);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23778);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 23741);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 23744, 23742, 23743);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23777);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_int32)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] >> " + std::to_string(Iuimm5) + "ULL) & " + std::to_string(((2ULL << Luimm5) - 1ULL)) + "ULL) << " + std::to_string((31ULL - Luimm5)) + "ULL)) >> " + std::to_string((31ULL - Luimm5)) + "ULL;\n";
cp.code() += "etiss_coverage_count(29, 23776, 23747, 23746, 23775, 23770, 23767, 23761, 23752, 23750, 23749, 23751, 23753, 23759, 23756, 23754, 23755, 23757, 23758, 23760, 23762, 23765, 23763, 23764, 23766, 23768, 23773, 23771, 23772, 23774);\n";
cp.code() += "} // block\n";
} // block
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
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
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 Iuimm5 = 0;
static BitArrayRange R_Iuimm5_0(24, 20);
Iuimm5 += R_Iuimm5_0.read(ba) << 0;
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_extract" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Iuimm5=" + std::to_string(Iuimm5) + " | Luimm5=" + std::to_string(Luimm5) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_EXTRACTU -----------------------------------------------------------------
static InstructionDefinition cv_extractu_rd_rs1_Iuimm5_Luimm5 (
	ISA32_RV32IMXCoreV,
	"cv_extractu",
	(uint64_t) 0x4000005b,
	(uint64_t) 0xc000707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 Iuimm5 = 0;
static BitArrayRange R_Iuimm5_0(24, 20);
Iuimm5 += R_Iuimm5_0.read(ba) << 0;
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_EXTRACTU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 370);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23804);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 23779);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 23782, 23780, 23781);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23803);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] >> " + std::to_string(Iuimm5) + "ULL) & " + std::to_string(((2ULL << Luimm5) - 1ULL)) + "ULL));\n";
cp.code() += "etiss_coverage_count(18, 23802, 23785, 23784, 23801, 23799, 23790, 23788, 23787, 23789, 23791, 23797, 23794, 23792, 23793, 23795, 23796, 23798, 23800);\n";
cp.code() += "} // block\n";
} // block
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
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
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 Iuimm5 = 0;
static BitArrayRange R_Iuimm5_0(24, 20);
Iuimm5 += R_Iuimm5_0.read(ba) << 0;
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_extractu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Iuimm5=" + std::to_string(Iuimm5) + " | Luimm5=" + std::to_string(Luimm5) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_INSERT -------------------------------------------------------------------
static InstructionDefinition cv_insert_rd_rs1_Iuimm5_Luimm5 (
	ISA32_RV32IMXCoreV,
	"cv_insert",
	(uint64_t) 0x8000005b,
	(uint64_t) 0xc000707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 Iuimm5 = 0;
static BitArrayRange R_Iuimm5_0(24, 20);
Iuimm5 += R_Iuimm5_0.read(ba) << 0;
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_INSERT\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 371);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23876);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 23805);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 23808, 23806, 23807);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23875);\n";
cp.code() += "{ // block\n";
etiss_uint32 mask = 0LL;
cp.code() += "etiss_coverage_count(2, 23811, 23810);\n";
etiss_uint8 i = 0LL;
cp.code() += "etiss_coverage_count(2, 23814, 23813);\n";
etiss_uint8 width = Luimm5 + 1ULL;
cp.code() += "etiss_coverage_count(4, 23819, 23818, 23816, 23817);\n";
cp.code() += "etiss_coverage_count(1, 23820);\n";
if (width > (32ULL - Iuimm5)) { // conditional
cp.code() += "etiss_coverage_count(6, 23826, 23821, 23824, 23822, 23823, 23825);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23832);\n";
cp.code() += "{ // block\n";
width = (32ULL - Iuimm5) & 0x3fULL;
cp.code() += "etiss_coverage_count(5, 23831, 23827, 23830, 23828, 23829);\n";
cp.code() += "} // block\n";
} // block
} // conditional
while (i < width)
cp.code() += "etiss_coverage_count(3, 23852, 23850, 23851);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23849);\n";
cp.code() += "{ // block\n";
mask = mask | (1ULL << (Iuimm5 + i));
cp.code() += "etiss_coverage_count(11, 23843, 23833, 23842, 23834, 23840, 23835, 23838, 23836, 23837, 23839, 23841);\n";
i = (i + 1ULL) & 0x3fULL;
cp.code() += "etiss_coverage_count(5, 23848, 23844, 23847, 23845, 23846);\n";
cp.code() += "} // block\n";
} // block

cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] & " + std::to_string(~(mask)) + "ULL) | ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] << " + std::to_string(Iuimm5) + "ULL) & " + std::to_string(mask) + "ULL);\n";
cp.code() += "etiss_coverage_count(18, 23874, 23856, 23855, 23873, 23862, 23859, 23858, 23861, 23860, 23863, 23871, 23868, 23866, 23865, 23867, 23869, 23870, 23872);\n";
cp.code() += "} // block\n";
} // block
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
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
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 Iuimm5 = 0;
static BitArrayRange R_Iuimm5_0(24, 20);
Iuimm5 += R_Iuimm5_0.read(ba) << 0;
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_insert" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Iuimm5=" + std::to_string(Iuimm5) + " | Luimm5=" + std::to_string(Luimm5) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_BCLR ---------------------------------------------------------------------
static InstructionDefinition cv_bclr_rd_rs1_Iuimm5_Luimm5 (
	ISA32_RV32IMXCoreV,
	"cv_bclr",
	(uint64_t) 0x00105b,
	(uint64_t) 0xc000707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 Iuimm5 = 0;
static BitArrayRange R_Iuimm5_0(24, 20);
Iuimm5 += R_Iuimm5_0.read(ba) << 0;
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_BCLR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 372);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23937);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 23877);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 23880, 23878, 23879);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23936);\n";
cp.code() += "{ // block\n";
etiss_uint32 mask = 0LL;
cp.code() += "etiss_coverage_count(2, 23883, 23882);\n";
etiss_uint8 i = 0LL;
cp.code() += "etiss_coverage_count(2, 23886, 23885);\n";
etiss_uint8 width = Luimm5 + 1ULL;
cp.code() += "etiss_coverage_count(4, 23891, 23890, 23888, 23889);\n";
cp.code() += "etiss_coverage_count(1, 23892);\n";
if (width > (32ULL - Iuimm5)) { // conditional
cp.code() += "etiss_coverage_count(6, 23898, 23893, 23896, 23894, 23895, 23897);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23904);\n";
cp.code() += "{ // block\n";
width = (32ULL - Iuimm5) & 0x3fULL;
cp.code() += "etiss_coverage_count(5, 23903, 23899, 23902, 23900, 23901);\n";
cp.code() += "} // block\n";
} // block
} // conditional
while (i < width)
cp.code() += "etiss_coverage_count(3, 23924, 23922, 23923);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23921);\n";
cp.code() += "{ // block\n";
mask = mask | (1ULL << (Iuimm5 + i));
cp.code() += "etiss_coverage_count(11, 23915, 23905, 23914, 23906, 23912, 23907, 23910, 23908, 23909, 23911, 23913);\n";
i = (i + 1ULL) & 0x3fULL;
cp.code() += "etiss_coverage_count(5, 23920, 23916, 23919, 23917, 23918);\n";
cp.code() += "} // block\n";
} // block

cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] & " + std::to_string(~(mask)) + "ULL;\n";
cp.code() += "etiss_coverage_count(8, 23935, 23928, 23927, 23934, 23931, 23930, 23933, 23932);\n";
cp.code() += "} // block\n";
} // block
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
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
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 Iuimm5 = 0;
static BitArrayRange R_Iuimm5_0(24, 20);
Iuimm5 += R_Iuimm5_0.read(ba) << 0;
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_bclr" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Iuimm5=" + std::to_string(Iuimm5) + " | Luimm5=" + std::to_string(Luimm5) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_BSET ---------------------------------------------------------------------
static InstructionDefinition cv_bset_rd_rs1_Iuimm5_Luimm5 (
	ISA32_RV32IMXCoreV,
	"cv_bset",
	(uint64_t) 0x4000105b,
	(uint64_t) 0xc000707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 Iuimm5 = 0;
static BitArrayRange R_Iuimm5_0(24, 20);
Iuimm5 += R_Iuimm5_0.read(ba) << 0;
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_BSET\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 373);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 23997);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 23938);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 23941, 23939, 23940);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23996);\n";
cp.code() += "{ // block\n";
etiss_uint32 mask = 0LL;
cp.code() += "etiss_coverage_count(2, 23944, 23943);\n";
etiss_uint8 i = 0LL;
cp.code() += "etiss_coverage_count(2, 23947, 23946);\n";
etiss_uint8 width = Luimm5 + 1ULL;
cp.code() += "etiss_coverage_count(4, 23952, 23951, 23949, 23950);\n";
cp.code() += "etiss_coverage_count(1, 23953);\n";
if (width > (32ULL - Iuimm5)) { // conditional
cp.code() += "etiss_coverage_count(6, 23959, 23954, 23957, 23955, 23956, 23958);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23965);\n";
cp.code() += "{ // block\n";
width = (32ULL - Iuimm5) & 0x3fULL;
cp.code() += "etiss_coverage_count(5, 23964, 23960, 23963, 23961, 23962);\n";
cp.code() += "} // block\n";
} // block
} // conditional
while (i < width)
cp.code() += "etiss_coverage_count(3, 23985, 23983, 23984);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 23982);\n";
cp.code() += "{ // block\n";
mask = mask | (1ULL << (Iuimm5 + i));
cp.code() += "etiss_coverage_count(11, 23976, 23966, 23975, 23967, 23973, 23968, 23971, 23969, 23970, 23972, 23974);\n";
i = (i + 1ULL) & 0x3fULL;
cp.code() += "etiss_coverage_count(5, 23981, 23977, 23980, 23978, 23979);\n";
cp.code() += "} // block\n";
} // block

cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] | " + std::to_string(mask) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 23995, 23989, 23988, 23994, 23992, 23991, 23993);\n";
cp.code() += "} // block\n";
} // block
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
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
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 Iuimm5 = 0;
static BitArrayRange R_Iuimm5_0(24, 20);
Iuimm5 += R_Iuimm5_0.read(ba) << 0;
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_bset" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Iuimm5=" + std::to_string(Iuimm5) + " | Luimm5=" + std::to_string(Luimm5) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_BITREV -------------------------------------------------------------------
static InstructionDefinition cv_bitrev_rd_rs1_Iuimm5_Luimm2 (
	ISA32_RV32IMXCoreV,
	"cv_bitrev",
	(uint64_t) 0xc000105b,
	(uint64_t) 0xf800707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 Iuimm5 = 0;
static BitArrayRange R_Iuimm5_0(24, 20);
Iuimm5 += R_Iuimm5_0.read(ba) << 0;
etiss_uint8 Luimm2 = 0;
static BitArrayRange R_Luimm2_0(26, 25);
Luimm2 += R_Luimm2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_BITREV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 374);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24125);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 23998);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24001, 23999, 24000);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24124);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 source = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] << " + std::to_string(Iuimm5) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 24008, 24007, 24005, 24004, 24006);\n";
cp.code() += "etiss_uint32 result = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 24011, 24010);\n";
etiss_uint8 groupWidth = 1ULL;
cp.code() += "etiss_coverage_count(2, 24014, 24013);\n";
etiss_uint8 firstWidth = 1ULL;
cp.code() += "etiss_coverage_count(2, 24017, 24016);\n";
etiss_uint8 sourceBase = 0LL;
cp.code() += "etiss_coverage_count(2, 24020, 24019);\n";
etiss_uint8 destinationBase = 0LL;
cp.code() += "etiss_coverage_count(2, 24023, 24022);\n";
etiss_uint8 chunkWidth = 0LL;
cp.code() += "etiss_coverage_count(2, 24026, 24025);\n";
etiss_uint8 i = 0LL;
cp.code() += "etiss_coverage_count(2, 24029, 24028);\n";
cp.code() += "etiss_coverage_count(1, 24030);\n";
if (Luimm2 == 1ULL) { // conditional
cp.code() += "etiss_coverage_count(3, 24033, 24031, 24032);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24040);\n";
cp.code() += "{ // block\n";
groupWidth = (2ULL) & 0x7ULL;
cp.code() += "etiss_coverage_count(3, 24039, 24037, 24038);\n";
cp.code() += "} // block\n";
} // block
} // conditional
 else if (Luimm2 == 2ULL) { // conditional
cp.code() += "etiss_coverage_count(3, 24036, 24034, 24035);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24044);\n";
cp.code() += "{ // block\n";
groupWidth = (3ULL) & 0x7ULL;
cp.code() += "etiss_coverage_count(3, 24043, 24041, 24042);\n";
cp.code() += "} // block\n";
} // block
} // conditional
firstWidth = (32ULL % groupWidth) & 0x7ULL;
cp.code() += "etiss_coverage_count(5, 24049, 24045, 24048, 24046, 24047);\n";
cp.code() += "etiss_coverage_count(1, 24050);\n";
if (firstWidth == 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24053, 24051, 24052);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24057);\n";
cp.code() += "{ // block\n";
firstWidth = (groupWidth) & 0x7ULL;
cp.code() += "etiss_coverage_count(3, 24056, 24054, 24055);\n";
cp.code() += "} // block\n";
} // block
} // conditional
chunkWidth = (firstWidth) & 0x3fULL;
cp.code() += "etiss_coverage_count(3, 24060, 24058, 24059);\n";
while (sourceBase < 32ULL)
cp.code() += "etiss_coverage_count(3, 24117, 24115, 24116);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24114);\n";
cp.code() += "{ // block\n";
destinationBase = (32ULL - sourceBase - chunkWidth) & 0x3fULL;
cp.code() += "etiss_coverage_count(7, 24067, 24061, 24066, 24064, 24062, 24063, 24065);\n";
i = (0LL) & 0x3fULL;
cp.code() += "etiss_coverage_count(3, 24070, 24068, 24069);\n";
while (i < chunkWidth)
cp.code() += "etiss_coverage_count(3, 24104, 24102, 24103);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24101);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24071);\n";
cp.code() += "if (((source >> " + std::to_string((sourceBase + i)) + "ULL) & 1ULL) != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(12, 24083, 24080, 24077, 24072, 24075, 24073, 24074, 24076, 24078, 24079, 24081, 24082);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24095);\n";
cp.code() += "{ // block\n";
cp.code() += "result = result | " + std::to_string((1ULL << (destinationBase + i))) + "ULL;\n";
cp.code() += "etiss_coverage_count(11, 24094, 24084, 24093, 24085, 24091, 24086, 24089, 24087, 24088, 24090, 24092);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
i = (i + 1ULL) & 0x3fULL;
cp.code() += "etiss_coverage_count(5, 24100, 24096, 24099, 24097, 24098);\n";
cp.code() += "} // block\n";
} // block

sourceBase = (sourceBase + chunkWidth) & 0x3fULL;
cp.code() += "etiss_coverage_count(5, 24110, 24106, 24109, 24107, 24108);\n";
chunkWidth = (groupWidth) & 0x3fULL;
cp.code() += "etiss_coverage_count(3, 24113, 24111, 24112);\n";
cp.code() += "} // block\n";
} // block

cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = result;\n";
cp.code() += "etiss_coverage_count(4, 24123, 24121, 24120, 24122);\n";
cp.code() += "} // block\n";
} // block
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
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
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 Iuimm5 = 0;
static BitArrayRange R_Iuimm5_0(24, 20);
Iuimm5 += R_Iuimm5_0.read(ba) << 0;
etiss_uint8 Luimm2 = 0;
static BitArrayRange R_Luimm2_0(26, 25);
Luimm2 += R_Luimm2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_bitrev" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Iuimm5=" + std::to_string(Iuimm5) + " | Luimm2=" + std::to_string(Luimm2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_EXTRACTR -----------------------------------------------------------------
static InstructionDefinition cv_extractr_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_extractr",
	(uint64_t) 0x3000302b,
	(uint64_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_EXTRACTR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 375);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24195);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24126);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24129, 24127, 24128);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24194);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_int32)((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL)) & ((2ULL << (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) >> (5ULL)) & 0x1fULL)) - 1ULL)) << (31ULL - (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) >> (5ULL)) & 0x1fULL)))) >> (31ULL - (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) >> (5ULL)) & 0x1fULL));\n";
cp.code() += "etiss_coverage_count(57, 24193, 24132, 24131, 24192, 24179, 24176, 24162, 24145, 24135, 24134, 24144, 24141, 24138, 24137, 24139, 24140, 24142, 24143, 24146, 24160, 24157, 24147, 24156, 24153, 24150, 24149, 24151, 24152, 24154, 24155, 24158, 24159, 24161, 24163, 24174, 24164, 24173, 24170, 24167, 24166, 24168, 24169, 24171, 24172, 24175, 24177, 24190, 24180, 24189, 24186, 24183, 24182, 24184, 24185, 24187, 24188, 24191);\n";
cp.code() += "} // block\n";
} // block
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
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
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_extractr" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_EXTRACTUR ----------------------------------------------------------------
static InstructionDefinition cv_extractur_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_extractur",
	(uint64_t) 0x3200302b,
	(uint64_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_EXTRACTUR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 376);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24237);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24196);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24199, 24197, 24198);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24236);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL)) & ((2ULL << (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) >> (5ULL)) & 0x1fULL)) - 1ULL)));\n";
cp.code() += "etiss_coverage_count(32, 24235, 24202, 24201, 24234, 24232, 24215, 24205, 24204, 24214, 24211, 24208, 24207, 24209, 24210, 24212, 24213, 24216, 24230, 24227, 24217, 24226, 24223, 24220, 24219, 24221, 24222, 24224, 24225, 24228, 24229, 24231, 24233);\n";
cp.code() += "} // block\n";
} // block
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
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
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_extractur" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_INSERTR ------------------------------------------------------------------
static InstructionDefinition cv_insertr_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_insertr",
	(uint64_t) 0x3400302b,
	(uint64_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_INSERTR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 377);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24322);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24238);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24241, 24239, 24240);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24321);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint8 offset = ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0x1fULL);\n";
cp.code() += "etiss_coverage_count(6, 24249, 24248, 24245, 24244, 24246, 24247);\n";
cp.code() += "etiss_uint8 width = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (5ULL)) & 0x1fULL) + 1ULL;\n";
cp.code() += "etiss_coverage_count(8, 24259, 24258, 24256, 24253, 24252, 24254, 24255, 24257);\n";
cp.code() += "etiss_uint32 mask = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 24262, 24261);\n";
cp.code() += "etiss_uint8 i = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 24265, 24264);\n";
cp.code() += "etiss_coverage_count(1, 24266);\n";
cp.code() += "if (width > (32ULL - offset)) { // conditional\n";
cp.code() += "etiss_coverage_count(6, 24272, 24267, 24270, 24268, 24269, 24271);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24278);\n";
cp.code() += "{ // block\n";
cp.code() += "width = (32ULL - offset) & 0x3fULL;\n";
cp.code() += "etiss_coverage_count(5, 24277, 24273, 24276, 24274, 24275);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "while (i < width)\n";
cp.code() += "etiss_coverage_count(3, 24298, 24296, 24297);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24295);\n";
cp.code() += "{ // block\n";
cp.code() += "mask = mask | (1ULL << (offset + i));\n";
cp.code() += "etiss_coverage_count(11, 24289, 24279, 24288, 24280, 24286, 24281, 24284, 24282, 24283, 24285, 24287);\n";
cp.code() += "i = (i + 1ULL) & 0x3fULL;\n";
cp.code() += "etiss_coverage_count(5, 24294, 24290, 24293, 24291, 24292);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] & ~(mask)) | ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] << offset) & mask);\n";
cp.code() += "etiss_coverage_count(18, 24320, 24302, 24301, 24319, 24308, 24305, 24304, 24307, 24306, 24309, 24317, 24314, 24312, 24311, 24313, 24315, 24316, 24318);\n";
cp.code() += "} // block\n";
} // block
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
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
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_insertr" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_BCLRR --------------------------------------------------------------------
static InstructionDefinition cv_bclrr_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_bclrr",
	(uint64_t) 0x3800302b,
	(uint64_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_BCLRR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 378);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24396);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24323);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24326, 24324, 24325);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24395);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint8 offset = ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0x1fULL);\n";
cp.code() += "etiss_coverage_count(6, 24334, 24333, 24330, 24329, 24331, 24332);\n";
cp.code() += "etiss_uint8 width = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (5ULL)) & 0x1fULL) + 1ULL;\n";
cp.code() += "etiss_coverage_count(8, 24344, 24343, 24341, 24338, 24337, 24339, 24340, 24342);\n";
cp.code() += "etiss_uint32 mask = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 24347, 24346);\n";
cp.code() += "etiss_uint8 i = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 24350, 24349);\n";
cp.code() += "etiss_coverage_count(1, 24351);\n";
cp.code() += "if (width > (32ULL - offset)) { // conditional\n";
cp.code() += "etiss_coverage_count(6, 24357, 24352, 24355, 24353, 24354, 24356);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24363);\n";
cp.code() += "{ // block\n";
cp.code() += "width = (32ULL - offset) & 0x3fULL;\n";
cp.code() += "etiss_coverage_count(5, 24362, 24358, 24361, 24359, 24360);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "while (i < width)\n";
cp.code() += "etiss_coverage_count(3, 24383, 24381, 24382);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24380);\n";
cp.code() += "{ // block\n";
cp.code() += "mask = mask | (1ULL << (offset + i));\n";
cp.code() += "etiss_coverage_count(11, 24374, 24364, 24373, 24365, 24371, 24366, 24369, 24367, 24368, 24370, 24372);\n";
cp.code() += "i = (i + 1ULL) & 0x3fULL;\n";
cp.code() += "etiss_coverage_count(5, 24379, 24375, 24378, 24376, 24377);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] & ~(mask);\n";
cp.code() += "etiss_coverage_count(8, 24394, 24387, 24386, 24393, 24390, 24389, 24392, 24391);\n";
cp.code() += "} // block\n";
} // block
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
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
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_bclrr" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_BSETR --------------------------------------------------------------------
static InstructionDefinition cv_bsetr_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_bsetr",
	(uint64_t) 0x3a00302b,
	(uint64_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_BSETR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 379);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24469);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24397);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24400, 24398, 24399);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24468);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint8 offset = ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0x1fULL);\n";
cp.code() += "etiss_coverage_count(6, 24408, 24407, 24404, 24403, 24405, 24406);\n";
cp.code() += "etiss_uint8 width = (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) >> (5ULL)) & 0x1fULL) + 1ULL;\n";
cp.code() += "etiss_coverage_count(8, 24418, 24417, 24415, 24412, 24411, 24413, 24414, 24416);\n";
cp.code() += "etiss_uint32 mask = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 24421, 24420);\n";
cp.code() += "etiss_uint8 i = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 24424, 24423);\n";
cp.code() += "etiss_coverage_count(1, 24425);\n";
cp.code() += "if (width > (32ULL - offset)) { // conditional\n";
cp.code() += "etiss_coverage_count(6, 24431, 24426, 24429, 24427, 24428, 24430);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24437);\n";
cp.code() += "{ // block\n";
cp.code() += "width = (32ULL - offset) & 0x3fULL;\n";
cp.code() += "etiss_coverage_count(5, 24436, 24432, 24435, 24433, 24434);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "while (i < width)\n";
cp.code() += "etiss_coverage_count(3, 24457, 24455, 24456);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24454);\n";
cp.code() += "{ // block\n";
cp.code() += "mask = mask | (1ULL << (offset + i));\n";
cp.code() += "etiss_coverage_count(11, 24448, 24438, 24447, 24439, 24445, 24440, 24443, 24441, 24442, 24444, 24446);\n";
cp.code() += "i = (i + 1ULL) & 0x3fULL;\n";
cp.code() += "etiss_coverage_count(5, 24453, 24449, 24452, 24450, 24451);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] | mask;\n";
cp.code() += "etiss_coverage_count(7, 24467, 24461, 24460, 24466, 24464, 24463, 24465);\n";
cp.code() += "} // block\n";
} // block
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
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
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_bsetr" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_ROR ----------------------------------------------------------------------
static InstructionDefinition cv_ror_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_ror",
	(uint64_t) 0x4000302b,
	(uint64_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_ROR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 380);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24516);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24470);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24473, 24471, 24472);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24515);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint8 shift = ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0x1fULL);\n";
cp.code() += "etiss_coverage_count(6, 24481, 24480, 24477, 24476, 24478, 24479);\n";
cp.code() += "etiss_coverage_count(1, 24482);\n";
cp.code() += "if (shift == 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 24485, 24483, 24484);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24493);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(5, 24492, 24488, 24487, 24491, 24490);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24514);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] >> shift) | (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] << (32ULL - shift));\n";
cp.code() += "etiss_coverage_count(17, 24513, 24496, 24495, 24512, 24501, 24499, 24498, 24500, 24502, 24510, 24505, 24504, 24508, 24506, 24507, 24509, 24511);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
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
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_ror" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_FF1 ----------------------------------------------------------------------
static InstructionDefinition cv_ff1_rd_rs1 (
	ISA32_RV32IMXCoreV,
	"cv_ff1",
	(uint64_t) 0x4200302b,
	(uint64_t) 0xfff0707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_FF1\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 381);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24565);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24517);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24520, 24518, 24519);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24564);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint8 result = 32ULL;\n";
cp.code() += "etiss_coverage_count(2, 24523, 24522);\n";
etiss_uint8 i = 0LL;
cp.code() += "etiss_coverage_count(2, 24526, 24525);\n";
while (i < 32ULL)
cp.code() += "etiss_coverage_count(3, 24557, 24555, 24556);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24554);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24527);\n";
cp.code() += "if ((result == 32ULL) && (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] >> " + std::to_string(i) + "ULL) & 1ULL) != 0LL)) { // conditional\n";
cp.code() += "etiss_coverage_count(16, 24544, 24530, 24528, 24529, 24531, 24542, 24539, 24536, 24534, 24533, 24535, 24537, 24538, 24540, 24541, 24543);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24548);\n";
cp.code() += "{ // block\n";
cp.code() += "result = (" + std::to_string(i) + "ULL) & 0x3fULL;\n";
cp.code() += "etiss_coverage_count(3, 24547, 24545, 24546);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
i = (i + 1ULL) & 0x3fULL;
cp.code() += "etiss_coverage_count(5, 24553, 24549, 24552, 24550, 24551);\n";
cp.code() += "} // block\n";
} // block

cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = result;\n";
cp.code() += "etiss_coverage_count(4, 24563, 24561, 24560, 24562);\n";
cp.code() += "} // block\n";
} // block
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
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
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_ff1" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_FL1 ----------------------------------------------------------------------
static InstructionDefinition cv_fl1_rd_rs1 (
	ISA32_RV32IMXCoreV,
	"cv_fl1",
	(uint64_t) 0x4400302b,
	(uint64_t) 0xfff0707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_FL1\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 382);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24608);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24566);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24569, 24567, 24568);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24607);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint8 result = 32ULL;\n";
cp.code() += "etiss_coverage_count(2, 24572, 24571);\n";
etiss_uint8 i = 0LL;
cp.code() += "etiss_coverage_count(2, 24575, 24574);\n";
while (i < 32ULL)
cp.code() += "etiss_coverage_count(3, 24600, 24598, 24599);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24597);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24576);\n";
cp.code() += "if (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] >> " + std::to_string(i) + "ULL) & 1ULL) != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(10, 24587, 24584, 24581, 24579, 24578, 24580, 24582, 24583, 24585, 24586);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24591);\n";
cp.code() += "{ // block\n";
cp.code() += "result = (" + std::to_string(i) + "ULL) & 0x3fULL;\n";
cp.code() += "etiss_coverage_count(3, 24590, 24588, 24589);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
i = (i + 1ULL) & 0x3fULL;
cp.code() += "etiss_coverage_count(5, 24596, 24592, 24595, 24593, 24594);\n";
cp.code() += "} // block\n";
} // block

cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = result;\n";
cp.code() += "etiss_coverage_count(4, 24606, 24604, 24603, 24605);\n";
cp.code() += "} // block\n";
} // block
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
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
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_fl1" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CNT ----------------------------------------------------------------------
static InstructionDefinition cv_cnt_rd_rs1 (
	ISA32_RV32IMXCoreV,
	"cv_cnt",
	(uint64_t) 0x4800302b,
	(uint64_t) 0xfff0707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_CNT\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 383);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24648);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24609);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24612, 24610, 24611);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24647);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint8 result = 0LL;\n";
cp.code() += "etiss_coverage_count(2, 24615, 24614);\n";
etiss_uint8 i = 0LL;
cp.code() += "etiss_coverage_count(2, 24618, 24617);\n";
while (i < 32ULL)
cp.code() += "etiss_coverage_count(3, 24640, 24638, 24639);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24637);\n";
cp.code() += "{ // block\n";
cp.code() += "result = (result + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] >> " + std::to_string(i) + "ULL) & 1ULL)) & 0x3fULL;\n";
cp.code() += "etiss_coverage_count(12, 24631, 24619, 24630, 24620, 24628, 24625, 24623, 24622, 24624, 24626, 24627, 24629);\n";
i = (i + 1ULL) & 0x3fULL;
cp.code() += "etiss_coverage_count(5, 24636, 24632, 24635, 24633, 24634);\n";
cp.code() += "} // block\n";
} // block

cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = result;\n";
cp.code() += "etiss_coverage_count(4, 24646, 24644, 24643, 24645);\n";
cp.code() += "} // block\n";
} // block
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
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
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_cnt" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
// clang-format on
