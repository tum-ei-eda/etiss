// clang-format off
/**
 * Generated on Wed, 05 Aug 2026 14:25:16 +0200.
 *
 * This file contains the instruction behavior models of the XCoreVAlu
 * instruction set for the RV32IMXCoreV core architecture.
 */

#include "RV32IMXCoreVArch.h"
#include "RV32IMXCoreVFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// CV_ABS ----------------------------------------------------------------------
static InstructionDefinition cv_abs_rd_rs1 (
	ISA32_RV32IMXCoreV,
	"cv_abs",
	(uint64_t) 0x5000302b,
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

		cp.code() = std::string("//CV_ABS\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 384);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24679);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24649);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24652, 24650, 24651);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24678);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) < 0LL)) ? ((((-(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]))) & 0xffffffffULL)) : (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]);\n";
cp.code() += "etiss_coverage_count(18, 24677, 24655, 24654, 24676, 24661, 24659, 24658, 24657, 24660, 24662, 24672, 24666, 24665, 24664, 24667, 24671, 24675, 24674);\n";
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
ss << "cv_abs" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SLET ---------------------------------------------------------------------
static InstructionDefinition cv_slet_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_slet",
	(uint64_t) 0x5200302b,
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

		cp.code() = std::string("//CV_SLET\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 385);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24704);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24680);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24683, 24681, 24682);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24703);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint8)(((etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) <= (etiss_int32)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL))));\n";
cp.code() += "etiss_coverage_count(15, 24702, 24686, 24685, 24701, 24698, 24690, 24689, 24688, 24697, 24696, 24693, 24692, 24694, 24695, 24699);\n";
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
ss << "cv_slet" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SLETU --------------------------------------------------------------------
static InstructionDefinition cv_sletu_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sletu",
	(uint64_t) 0x5400302b,
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

		cp.code() = std::string("//CV_SLETU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 386);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24729);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24705);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24708, 24706, 24707);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24728);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint8)(((etiss_uint32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) <= (etiss_uint32)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL))));\n";
cp.code() += "etiss_coverage_count(15, 24727, 24711, 24710, 24726, 24723, 24715, 24714, 24713, 24722, 24721, 24718, 24717, 24719, 24720, 24724);\n";
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
ss << "cv_sletu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MIN ----------------------------------------------------------------------
static InstructionDefinition cv_min_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_min",
	(uint64_t) 0x5600302b,
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

		cp.code() = std::string("//CV_MIN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 387);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24762);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24730);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24733, 24731, 24732);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24761);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) < (etiss_int32)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)))) ? (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL));\n";
cp.code() += "etiss_coverage_count(22, 24760, 24736, 24735, 24759, 24748, 24740, 24739, 24738, 24747, 24746, 24743, 24742, 24744, 24745, 24749, 24752, 24751, 24758, 24755, 24754, 24756, 24757);\n";
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
ss << "cv_min" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MINU ---------------------------------------------------------------------
static InstructionDefinition cv_minu_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_minu",
	(uint64_t) 0x5800302b,
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

		cp.code() = std::string("//CV_MINU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 388);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24795);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24763);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24766, 24764, 24765);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24794);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((etiss_uint32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) < (etiss_uint32)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)))) ? (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL));\n";
cp.code() += "etiss_coverage_count(22, 24793, 24769, 24768, 24792, 24781, 24773, 24772, 24771, 24780, 24779, 24776, 24775, 24777, 24778, 24782, 24785, 24784, 24791, 24788, 24787, 24789, 24790);\n";
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
ss << "cv_minu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MAX ----------------------------------------------------------------------
static InstructionDefinition cv_max_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_max",
	(uint64_t) 0x5a00302b,
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

		cp.code() = std::string("//CV_MAX\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 389);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24828);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24796);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24799, 24797, 24798);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24827);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) > (etiss_int32)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)))) ? (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL));\n";
cp.code() += "etiss_coverage_count(22, 24826, 24802, 24801, 24825, 24814, 24806, 24805, 24804, 24813, 24812, 24809, 24808, 24810, 24811, 24815, 24818, 24817, 24824, 24821, 24820, 24822, 24823);\n";
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
ss << "cv_max" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_MAXU ---------------------------------------------------------------------
static InstructionDefinition cv_maxu_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_maxu",
	(uint64_t) 0x5c00302b,
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

		cp.code() = std::string("//CV_MAXU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 390);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24861);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24829);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24832, 24830, 24831);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24860);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (((etiss_uint32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) > (etiss_uint32)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)))) ? (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) : (((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL));\n";
cp.code() += "etiss_coverage_count(22, 24859, 24835, 24834, 24858, 24847, 24839, 24838, 24837, 24846, 24845, 24842, 24841, 24843, 24844, 24848, 24851, 24850, 24857, 24854, 24853, 24855, 24856);\n";
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
ss << "cv_maxu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_EXTHS --------------------------------------------------------------------
static InstructionDefinition cv_exths_rd_rs1 (
	ISA32_RV32IMXCoreV,
	"cv_exths",
	(uint64_t) 0x6000302b,
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

		cp.code() = std::string("//CV_EXTHS\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 391);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24878);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24862);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24865, 24863, 24864);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24877);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_int16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL));\n";
cp.code() += "etiss_coverage_count(9, 24876, 24868, 24867, 24875, 24874, 24871, 24870, 24872, 24873);\n";
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
ss << "cv_exths" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_EXTHZ --------------------------------------------------------------------
static InstructionDefinition cv_exthz_rd_rs1 (
	ISA32_RV32IMXCoreV,
	"cv_exthz",
	(uint64_t) 0x6200302b,
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

		cp.code() = std::string("//CV_EXTHZ\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 392);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24895);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24879);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24882, 24880, 24881);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24894);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint16)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffffULL));\n";
cp.code() += "etiss_coverage_count(9, 24893, 24885, 24884, 24892, 24891, 24888, 24887, 24889, 24890);\n";
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
ss << "cv_exthz" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_EXTBS --------------------------------------------------------------------
static InstructionDefinition cv_extbs_rd_rs1 (
	ISA32_RV32IMXCoreV,
	"cv_extbs",
	(uint64_t) 0x6400302b,
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

		cp.code() = std::string("//CV_EXTBS\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 393);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24912);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24896);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24899, 24897, 24898);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24911);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_int8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL));\n";
cp.code() += "etiss_coverage_count(9, 24910, 24902, 24901, 24909, 24908, 24905, 24904, 24906, 24907);\n";
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
ss << "cv_extbs" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_EXTBZ --------------------------------------------------------------------
static InstructionDefinition cv_extbz_rd_rs1 (
	ISA32_RV32IMXCoreV,
	"cv_extbz",
	(uint64_t) 0x6600302b,
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

		cp.code() = std::string("//CV_EXTBZ\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 394);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24929);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24913);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24916, 24914, 24915);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24928);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint8)(((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) & 0xffULL));\n";
cp.code() += "etiss_coverage_count(9, 24927, 24919, 24918, 24926, 24925, 24922, 24921, 24923, 24924);\n";
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
ss << "cv_extbz" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CLIP ---------------------------------------------------------------------
static InstructionDefinition cv_clip_rd_rs1_Iuimm5 (
	ISA32_RV32IMXCoreV,
	"cv_clip",
	(uint64_t) 0x7000302b,
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
etiss_uint8 Iuimm5 = 0;
static BitArrayRange R_Iuimm5_0(24, 20);
Iuimm5 += R_Iuimm5_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_CLIP\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 395);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 24994);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24930);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24933, 24931, 24932);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24993);\n";
cp.code() += "{ // block\n";
etiss_int32 a = ((Iuimm5)) ? (-((1ULL << (Iuimm5 - 1ULL)))) : (-1LL);
cp.code() += "etiss_coverage_count(12, 24948, 24947, 24935, 24936, 24944, 24942, 24937, 24940, 24938, 24939, 24941, 24943);\n";
etiss_int32 b = ((Iuimm5)) ? (((1ULL << (Iuimm5 - 1ULL)) - 1ULL)) : (0LL);
cp.code() += "etiss_coverage_count(15, 24964, 24963, 24950, 24951, 24960, 24957, 24952, 24955, 24953, 24954, 24956, 24958, 24959, 24961, 24962);\n";
cp.code() += "etiss_coverage_count(1, 24965);\n";
cp.code() += "if (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] <= " + std::to_string(a) + "LL) { // conditional\n";
cp.code() += "etiss_coverage_count(4, 24970, 24968, 24967, 24969);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = " + std::to_string(a) + "LL;\n";
cp.code() += "etiss_coverage_count(4, 24980, 24978, 24977, 24979);\n";
cp.code() += "} // conditional\n";
cp.code() += " else if (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] >= " + std::to_string(b) + "LL) { // conditional\n";
cp.code() += "etiss_coverage_count(4, 24975, 24973, 24972, 24974);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = " + std::to_string(b) + "LL;\n";
cp.code() += "etiss_coverage_count(4, 24985, 24983, 24982, 24984);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(5, 24992, 24988, 24987, 24991, 24990);\n";
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
etiss_uint8 Iuimm5 = 0;
static BitArrayRange R_Iuimm5_0(24, 20);
Iuimm5 += R_Iuimm5_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_clip" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Iuimm5=" + std::to_string(Iuimm5) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CLIPU --------------------------------------------------------------------
static InstructionDefinition cv_clipu_rd_rs1_Iuimm5 (
	ISA32_RV32IMXCoreV,
	"cv_clipu",
	(uint64_t) 0x7200302b,
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
etiss_uint8 Iuimm5 = 0;
static BitArrayRange R_Iuimm5_0(24, 20);
Iuimm5 += R_Iuimm5_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_CLIPU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 396);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25049);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24995);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24998, 24996, 24997);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25048);\n";
cp.code() += "{ // block\n";
etiss_int32 a = 0LL;
cp.code() += "etiss_coverage_count(2, 25001, 25000);\n";
etiss_int32 b = ((Iuimm5)) ? (((1ULL << (Iuimm5 - 1ULL)) - 1ULL)) : (0LL);
cp.code() += "etiss_coverage_count(15, 25017, 25016, 25003, 25004, 25013, 25010, 25005, 25008, 25006, 25007, 25009, 25011, 25012, 25014, 25015);\n";
cp.code() += "etiss_coverage_count(1, 25018);\n";
cp.code() += "if ((etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) <= " + std::to_string(a) + "LL) { // conditional\n";
cp.code() += "etiss_coverage_count(5, 25024, 25022, 25021, 25020, 25023);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = " + std::to_string(a) + "LL;\n";
cp.code() += "etiss_coverage_count(4, 25035, 25033, 25032, 25034);\n";
cp.code() += "} // conditional\n";
cp.code() += " else if ((etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >= " + std::to_string(b) + "LL) { // conditional\n";
cp.code() += "etiss_coverage_count(5, 25030, 25028, 25027, 25026, 25029);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = " + std::to_string(b) + "LL;\n";
cp.code() += "etiss_coverage_count(4, 25040, 25038, 25037, 25039);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(5, 25047, 25043, 25042, 25046, 25045);\n";
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
etiss_uint8 Iuimm5 = 0;
static BitArrayRange R_Iuimm5_0(24, 20);
Iuimm5 += R_Iuimm5_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_clipu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | Iuimm5=" + std::to_string(Iuimm5) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CLIPR --------------------------------------------------------------------
static InstructionDefinition cv_clipr_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_clipr",
	(uint64_t) 0x7400302b,
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

		cp.code() = std::string("//CV_CLIPR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 397);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25105);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25050);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25053, 25051, 25052);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25104);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 a = -((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL) + 1ULL));\n";
cp.code() += "etiss_coverage_count(10, 25065, 25064, 25062, 25060, 25057, 25056, 25058, 25059, 25061, 25063);\n";
cp.code() += "etiss_int32 b = ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(6, 25073, 25072, 25069, 25068, 25070, 25071);\n";
cp.code() += "etiss_coverage_count(1, 25074);\n";
cp.code() += "if ((etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) <= a) { // conditional\n";
cp.code() += "etiss_coverage_count(5, 25080, 25078, 25077, 25076, 25079);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = a;\n";
cp.code() += "etiss_coverage_count(4, 25091, 25089, 25088, 25090);\n";
cp.code() += "} // conditional\n";
cp.code() += " else if ((etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >= b) { // conditional\n";
cp.code() += "etiss_coverage_count(5, 25086, 25084, 25083, 25082, 25085);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = b;\n";
cp.code() += "etiss_coverage_count(4, 25096, 25094, 25093, 25095);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(5, 25103, 25099, 25098, 25102, 25101);\n";
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
ss << "cv_clipr" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_CLIPUR -------------------------------------------------------------------
static InstructionDefinition cv_clipur_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_clipur",
	(uint64_t) 0x7600302b,
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

		cp.code() = std::string("//CV_CLIPUR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 398);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25152);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25106);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25109, 25107, 25108);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25151);\n";
cp.code() += "{ // block\n";
etiss_int32 a = 0LL;
cp.code() += "etiss_coverage_count(2, 25112, 25111);\n";
cp.code() += "etiss_int32 b = ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(6, 25120, 25119, 25116, 25115, 25117, 25118);\n";
cp.code() += "etiss_coverage_count(1, 25121);\n";
cp.code() += "if ((etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) <= " + std::to_string(a) + "LL) { // conditional\n";
cp.code() += "etiss_coverage_count(5, 25127, 25125, 25124, 25123, 25126);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = " + std::to_string(a) + "LL;\n";
cp.code() += "etiss_coverage_count(4, 25138, 25136, 25135, 25137);\n";
cp.code() += "} // conditional\n";
cp.code() += " else if ((etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >= b) { // conditional\n";
cp.code() += "etiss_coverage_count(5, 25133, 25131, 25130, 25129, 25132);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = b;\n";
cp.code() += "etiss_coverage_count(4, 25143, 25141, 25140, 25142);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(5, 25150, 25146, 25145, 25149, 25148);\n";
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
ss << "cv_clipur" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_ADDN ---------------------------------------------------------------------
static InstructionDefinition cv_addn_rd_rs1_rs2_Luimm5 (
	ISA32_RV32IMXCoreV,
	"cv_addn",
	(uint64_t) 0x00205b,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_ADDN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 399);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25176);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25153);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25156, 25154, 25155);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25175);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_int32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL))) >> " + std::to_string(Luimm5) + "ULL;\n";
cp.code() += "etiss_coverage_count(15, 25174, 25159, 25158, 25173, 25171, 25169, 25162, 25161, 25168, 25165, 25164, 25166, 25167, 25170, 25172);\n";
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
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_addn" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | Luimm5=" + std::to_string(Luimm5) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_ADDUN --------------------------------------------------------------------
static InstructionDefinition cv_addun_rd_rs1_rs2_Luimm5 (
	ISA32_RV32IMXCoreV,
	"cv_addun",
	(uint64_t) 0x4000205b,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_ADDUN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 400);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25200);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25177);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25180, 25178, 25179);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25199);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL))) >> " + std::to_string(Luimm5) + "ULL;\n";
cp.code() += "etiss_coverage_count(15, 25198, 25183, 25182, 25197, 25195, 25193, 25186, 25185, 25192, 25189, 25188, 25190, 25191, 25194, 25196);\n";
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
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_addun" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | Luimm5=" + std::to_string(Luimm5) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_ADDRN --------------------------------------------------------------------
static InstructionDefinition cv_addrn_rd_rs1_rs2_Luimm5 (
	ISA32_RV32IMXCoreV,
	"cv_addrn",
	(uint64_t) 0x8000205b,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_ADDRN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 401);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25232);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25201);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25204, 25202, 25203);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25231);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_int32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL) + " + std::to_string((1ULL << (Luimm5 - 1ULL))) + "ULL)) >> " + std::to_string(Luimm5) + "ULL;\n";
cp.code() += "etiss_coverage_count(23, 25230, 25207, 25206, 25229, 25227, 25225, 25217, 25210, 25209, 25216, 25213, 25212, 25214, 25215, 25223, 25218, 25221, 25219, 25220, 25222, 25224, 25226, 25228);\n";
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
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_addrn" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | Luimm5=" + std::to_string(Luimm5) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_ADDURN -------------------------------------------------------------------
static InstructionDefinition cv_addurn_rd_rs1_rs2_Luimm5 (
	ISA32_RV32IMXCoreV,
	"cv_addurn",
	(uint64_t) 0xc000205b,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_ADDURN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 402);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25264);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25233);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25236, 25234, 25235);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25263);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL) + " + std::to_string((1ULL << (Luimm5 - 1ULL))) + "ULL)) >> " + std::to_string(Luimm5) + "ULL;\n";
cp.code() += "etiss_coverage_count(23, 25262, 25239, 25238, 25261, 25259, 25257, 25249, 25242, 25241, 25248, 25245, 25244, 25246, 25247, 25255, 25250, 25253, 25251, 25252, 25254, 25256, 25258, 25260);\n";
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
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_addurn" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | Luimm5=" + std::to_string(Luimm5) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SUBN ---------------------------------------------------------------------
static InstructionDefinition cv_subn_rd_rs1_rs2_Luimm5 (
	ISA32_RV32IMXCoreV,
	"cv_subn",
	(uint64_t) 0x00305b,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SUBN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 403);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25288);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25265);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25268, 25266, 25267);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25287);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_int32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] - ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL))) >> " + std::to_string(Luimm5) + "ULL;\n";
cp.code() += "etiss_coverage_count(15, 25286, 25271, 25270, 25285, 25283, 25281, 25274, 25273, 25280, 25277, 25276, 25278, 25279, 25282, 25284);\n";
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
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_subn" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | Luimm5=" + std::to_string(Luimm5) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SUBUN --------------------------------------------------------------------
static InstructionDefinition cv_subun_rd_rs1_rs2_Luimm5 (
	ISA32_RV32IMXCoreV,
	"cv_subun",
	(uint64_t) 0x4000305b,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SUBUN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 404);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25312);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25289);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25292, 25290, 25291);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25311);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] - ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL))) >> " + std::to_string(Luimm5) + "ULL;\n";
cp.code() += "etiss_coverage_count(15, 25310, 25295, 25294, 25309, 25307, 25305, 25298, 25297, 25304, 25301, 25300, 25302, 25303, 25306, 25308);\n";
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
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_subun" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | Luimm5=" + std::to_string(Luimm5) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SUBRN --------------------------------------------------------------------
static InstructionDefinition cv_subrn_rd_rs1_rs2_Luimm5 (
	ISA32_RV32IMXCoreV,
	"cv_subrn",
	(uint64_t) 0x8000305b,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SUBRN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 405);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25344);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25313);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25316, 25314, 25315);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25343);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_int32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] - ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL) + " + std::to_string((1ULL << (Luimm5 - 1ULL))) + "ULL)) >> " + std::to_string(Luimm5) + "ULL;\n";
cp.code() += "etiss_coverage_count(23, 25342, 25319, 25318, 25341, 25339, 25337, 25329, 25322, 25321, 25328, 25325, 25324, 25326, 25327, 25335, 25330, 25333, 25331, 25332, 25334, 25336, 25338, 25340);\n";
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
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_subrn" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | Luimm5=" + std::to_string(Luimm5) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SUBURN -------------------------------------------------------------------
static InstructionDefinition cv_suburn_rd_rs1_rs2_Luimm5 (
	ISA32_RV32IMXCoreV,
	"cv_suburn",
	(uint64_t) 0xc000305b,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SUBURN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 406);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25376);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25345);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25348, 25346, 25347);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25375);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] - ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL) + " + std::to_string((1ULL << (Luimm5 - 1ULL))) + "ULL)) >> " + std::to_string(Luimm5) + "ULL;\n";
cp.code() += "etiss_coverage_count(23, 25374, 25351, 25350, 25373, 25371, 25369, 25361, 25354, 25353, 25360, 25357, 25356, 25358, 25359, 25367, 25362, 25365, 25363, 25364, 25366, 25368, 25370, 25372);\n";
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
etiss_uint8 Luimm5 = 0;
static BitArrayRange R_Luimm5_0(29, 25);
Luimm5 += R_Luimm5_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_suburn" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | Luimm5=" + std::to_string(Luimm5) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_ADDNR --------------------------------------------------------------------
static InstructionDefinition cv_addnr_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_addnr",
	(uint64_t) 0x8000302b,
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

		cp.code() = std::string("//CV_ADDNR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 407);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25405);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25377);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25380, 25378, 25379);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25404);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_int32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL])) >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL);\n";
cp.code() += "etiss_coverage_count(19, 25403, 25383, 25382, 25402, 25392, 25390, 25386, 25385, 25389, 25388, 25391, 25401, 25398, 25395, 25394, 25396, 25397, 25399, 25400);\n";
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
ss << "cv_addnr" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_ADDUNR -------------------------------------------------------------------
static InstructionDefinition cv_addunr_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_addunr",
	(uint64_t) 0x8200302b,
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

		cp.code() = std::string("//CV_ADDUNR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 408);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25434);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25406);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25409, 25407, 25408);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25433);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL])) >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL);\n";
cp.code() += "etiss_coverage_count(19, 25432, 25412, 25411, 25431, 25421, 25419, 25415, 25414, 25418, 25417, 25420, 25430, 25427, 25424, 25423, 25425, 25426, 25428, 25429);\n";
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
ss << "cv_addunr" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_ADDRNR -------------------------------------------------------------------
static InstructionDefinition cv_addrnr_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_addrnr",
	(uint64_t) 0x8400302b,
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

		cp.code() = std::string("//CV_ADDRNR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 409);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25479);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25435);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25438, 25436, 25437);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25478);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_int32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + (1ULL << (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL) - 1ULL)))) >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL);\n";
cp.code() += "etiss_coverage_count(34, 25477, 25441, 25440, 25476, 25466, 25464, 25448, 25444, 25443, 25447, 25446, 25462, 25449, 25460, 25458, 25455, 25452, 25451, 25453, 25454, 25456, 25457, 25459, 25461, 25463, 25465, 25475, 25472, 25469, 25468, 25470, 25471, 25473, 25474);\n";
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
ss << "cv_addrnr" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_ADDURNR ------------------------------------------------------------------
static InstructionDefinition cv_addurnr_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_addurnr",
	(uint64_t) 0x8600302b,
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

		cp.code() = std::string("//CV_ADDURNR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 410);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25524);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25480);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25483, 25481, 25482);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25523);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + (1ULL << (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL) - 1ULL)))) >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL);\n";
cp.code() += "etiss_coverage_count(34, 25522, 25486, 25485, 25521, 25511, 25509, 25493, 25489, 25488, 25492, 25491, 25507, 25494, 25505, 25503, 25500, 25497, 25496, 25498, 25499, 25501, 25502, 25504, 25506, 25508, 25510, 25520, 25517, 25514, 25513, 25515, 25516, 25518, 25519);\n";
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
ss << "cv_addurnr" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SUBNR --------------------------------------------------------------------
static InstructionDefinition cv_subnr_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_subnr",
	(uint64_t) 0x8800302b,
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

		cp.code() = std::string("//CV_SUBNR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 411);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25553);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25525);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25528, 25526, 25527);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25552);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_int32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] - *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL])) >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL);\n";
cp.code() += "etiss_coverage_count(19, 25551, 25531, 25530, 25550, 25540, 25538, 25534, 25533, 25537, 25536, 25539, 25549, 25546, 25543, 25542, 25544, 25545, 25547, 25548);\n";
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
ss << "cv_subnr" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SUBUNR -------------------------------------------------------------------
static InstructionDefinition cv_subunr_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_subunr",
	(uint64_t) 0x8a00302b,
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

		cp.code() = std::string("//CV_SUBUNR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 412);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25582);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25554);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25557, 25555, 25556);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25581);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] - *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL])) >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL);\n";
cp.code() += "etiss_coverage_count(19, 25580, 25560, 25559, 25579, 25569, 25567, 25563, 25562, 25566, 25565, 25568, 25578, 25575, 25572, 25571, 25573, 25574, 25576, 25577);\n";
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
ss << "cv_subunr" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SUBRNR -------------------------------------------------------------------
static InstructionDefinition cv_subrnr_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_subrnr",
	(uint64_t) 0x8c00302b,
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

		cp.code() = std::string("//CV_SUBRNR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 413);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25627);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25583);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25586, 25584, 25585);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25626);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_int32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] - *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + (1ULL << (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL) - 1ULL)))) >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL);\n";
cp.code() += "etiss_coverage_count(34, 25625, 25589, 25588, 25624, 25614, 25612, 25596, 25592, 25591, 25595, 25594, 25610, 25597, 25608, 25606, 25603, 25600, 25599, 25601, 25602, 25604, 25605, 25607, 25609, 25611, 25613, 25623, 25620, 25617, 25616, 25618, 25619, 25621, 25622);\n";
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
ss << "cv_subrnr" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SUBURNR ------------------------------------------------------------------
static InstructionDefinition cv_suburnr_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_suburnr",
	(uint64_t) 0x8e00302b,
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

		cp.code() = std::string("//CV_SUBURNR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 414);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25672);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25628);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25631, 25629, 25630);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25671);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] - *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + (1ULL << (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL) - 1ULL)))) >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL);\n";
cp.code() += "etiss_coverage_count(34, 25670, 25634, 25633, 25669, 25659, 25657, 25641, 25637, 25636, 25640, 25639, 25655, 25642, 25653, 25651, 25648, 25645, 25644, 25646, 25647, 25649, 25650, 25652, 25654, 25656, 25658, 25668, 25665, 25662, 25661, 25663, 25664, 25666, 25667);\n";
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
ss << "cv_suburnr" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
// clang-format on
