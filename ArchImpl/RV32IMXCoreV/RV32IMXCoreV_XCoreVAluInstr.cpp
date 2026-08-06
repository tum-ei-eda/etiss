// clang-format off
/**
 * Generated on Wed, 05 Aug 2026 14:56:03 +0200.
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

// CV_SLE ----------------------------------------------------------------------
static InstructionDefinition cv_sle_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sle",
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

		cp.code() = std::string("//CV_SLE\n");

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
ss << "cv_sle" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SLEU ---------------------------------------------------------------------
static InstructionDefinition cv_sleu_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sleu",
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

		cp.code() = std::string("//CV_SLEU\n");

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
ss << "cv_sleu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
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
cp.code() += "etiss_coverage_count(1, 24996);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24930);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 24933, 24931, 24932);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 24995);\n";
cp.code() += "{ // block\n";
etiss_int32 a = ((Iuimm5)) ? (-((1ULL << (Iuimm5 - 1ULL)))) : (-1LL);
cp.code() += "etiss_coverage_count(12, 24948, 24947, 24935, 24936, 24944, 24942, 24937, 24940, 24938, 24939, 24941, 24943);\n";
etiss_int32 b = ((Iuimm5)) ? (((1ULL << (Iuimm5 - 1ULL)) - 1ULL)) : (0LL);
cp.code() += "etiss_coverage_count(15, 24964, 24963, 24950, 24951, 24960, 24957, 24952, 24955, 24953, 24954, 24956, 24958, 24959, 24961, 24962);\n";
cp.code() += "etiss_coverage_count(1, 24965);\n";
cp.code() += "if ((etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) <= " + std::to_string(a) + "LL) { // conditional\n";
cp.code() += "etiss_coverage_count(5, 24971, 24969, 24968, 24967, 24970);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = " + std::to_string(a) + "LL;\n";
cp.code() += "etiss_coverage_count(4, 24982, 24980, 24979, 24981);\n";
cp.code() += "} // conditional\n";
cp.code() += " else if ((etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >= " + std::to_string(b) + "LL) { // conditional\n";
cp.code() += "etiss_coverage_count(5, 24977, 24975, 24974, 24973, 24976);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = " + std::to_string(b) + "LL;\n";
cp.code() += "etiss_coverage_count(4, 24987, 24985, 24984, 24986);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(5, 24994, 24990, 24989, 24993, 24992);\n";
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
cp.code() += "etiss_coverage_count(1, 25051);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 24997);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25000, 24998, 24999);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25050);\n";
cp.code() += "{ // block\n";
etiss_int32 a = 0LL;
cp.code() += "etiss_coverage_count(2, 25003, 25002);\n";
etiss_int32 b = ((Iuimm5)) ? (((1ULL << (Iuimm5 - 1ULL)) - 1ULL)) : (0LL);
cp.code() += "etiss_coverage_count(15, 25019, 25018, 25005, 25006, 25015, 25012, 25007, 25010, 25008, 25009, 25011, 25013, 25014, 25016, 25017);\n";
cp.code() += "etiss_coverage_count(1, 25020);\n";
cp.code() += "if ((etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) <= " + std::to_string(a) + "LL) { // conditional\n";
cp.code() += "etiss_coverage_count(5, 25026, 25024, 25023, 25022, 25025);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = " + std::to_string(a) + "LL;\n";
cp.code() += "etiss_coverage_count(4, 25037, 25035, 25034, 25036);\n";
cp.code() += "} // conditional\n";
cp.code() += " else if ((etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >= " + std::to_string(b) + "LL) { // conditional\n";
cp.code() += "etiss_coverage_count(5, 25032, 25030, 25029, 25028, 25031);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = " + std::to_string(b) + "LL;\n";
cp.code() += "etiss_coverage_count(4, 25042, 25040, 25039, 25041);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(5, 25049, 25045, 25044, 25048, 25047);\n";
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
cp.code() += "etiss_coverage_count(1, 25107);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25052);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25055, 25053, 25054);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25106);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 a = -((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL) + 1ULL));\n";
cp.code() += "etiss_coverage_count(10, 25067, 25066, 25064, 25062, 25059, 25058, 25060, 25061, 25063, 25065);\n";
cp.code() += "etiss_int32 b = ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(6, 25075, 25074, 25071, 25070, 25072, 25073);\n";
cp.code() += "etiss_coverage_count(1, 25076);\n";
cp.code() += "if ((etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) <= a) { // conditional\n";
cp.code() += "etiss_coverage_count(5, 25082, 25080, 25079, 25078, 25081);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = a;\n";
cp.code() += "etiss_coverage_count(4, 25093, 25091, 25090, 25092);\n";
cp.code() += "} // conditional\n";
cp.code() += " else if ((etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >= b) { // conditional\n";
cp.code() += "etiss_coverage_count(5, 25088, 25086, 25085, 25084, 25087);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = b;\n";
cp.code() += "etiss_coverage_count(4, 25098, 25096, 25095, 25097);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(5, 25105, 25101, 25100, 25104, 25103);\n";
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
cp.code() += "etiss_coverage_count(1, 25154);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25108);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25111, 25109, 25110);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25153);\n";
cp.code() += "{ // block\n";
etiss_int32 a = 0LL;
cp.code() += "etiss_coverage_count(2, 25114, 25113);\n";
cp.code() += "etiss_int32 b = ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL);\n";
cp.code() += "etiss_coverage_count(6, 25122, 25121, 25118, 25117, 25119, 25120);\n";
cp.code() += "etiss_coverage_count(1, 25123);\n";
cp.code() += "if ((etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) <= " + std::to_string(a) + "LL) { // conditional\n";
cp.code() += "etiss_coverage_count(5, 25129, 25127, 25126, 25125, 25128);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = " + std::to_string(a) + "LL;\n";
cp.code() += "etiss_coverage_count(4, 25140, 25138, 25137, 25139);\n";
cp.code() += "} // conditional\n";
cp.code() += " else if ((etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL]) >= b) { // conditional\n";
cp.code() += "etiss_coverage_count(5, 25135, 25133, 25132, 25131, 25134);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = b;\n";
cp.code() += "etiss_coverage_count(4, 25145, 25143, 25142, 25144);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(5, 25152, 25148, 25147, 25151, 25150);\n";
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
cp.code() += "etiss_coverage_count(1, 25178);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25155);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25158, 25156, 25157);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25177);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_int32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL))) >> " + std::to_string(Luimm5) + "ULL;\n";
cp.code() += "etiss_coverage_count(15, 25176, 25161, 25160, 25175, 25173, 25171, 25164, 25163, 25170, 25167, 25166, 25168, 25169, 25172, 25174);\n";
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
cp.code() += "etiss_coverage_count(1, 25202);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25179);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25182, 25180, 25181);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25201);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL))) >> " + std::to_string(Luimm5) + "ULL;\n";
cp.code() += "etiss_coverage_count(15, 25200, 25185, 25184, 25199, 25197, 25195, 25188, 25187, 25194, 25191, 25190, 25192, 25193, 25196, 25198);\n";
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
cp.code() += "etiss_coverage_count(1, 25234);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25203);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25206, 25204, 25205);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25233);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_int32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL) + " + std::to_string((1ULL << (Luimm5 - 1ULL))) + "ULL)) >> " + std::to_string(Luimm5) + "ULL;\n";
cp.code() += "etiss_coverage_count(23, 25232, 25209, 25208, 25231, 25229, 25227, 25219, 25212, 25211, 25218, 25215, 25214, 25216, 25217, 25225, 25220, 25223, 25221, 25222, 25224, 25226, 25228, 25230);\n";
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
cp.code() += "etiss_coverage_count(1, 25266);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25235);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25238, 25236, 25237);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25265);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL) + " + std::to_string((1ULL << (Luimm5 - 1ULL))) + "ULL)) >> " + std::to_string(Luimm5) + "ULL;\n";
cp.code() += "etiss_coverage_count(23, 25264, 25241, 25240, 25263, 25261, 25259, 25251, 25244, 25243, 25250, 25247, 25246, 25248, 25249, 25257, 25252, 25255, 25253, 25254, 25256, 25258, 25260, 25262);\n";
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
cp.code() += "etiss_coverage_count(1, 25290);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25267);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25270, 25268, 25269);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25289);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_int32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] - ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL))) >> " + std::to_string(Luimm5) + "ULL;\n";
cp.code() += "etiss_coverage_count(15, 25288, 25273, 25272, 25287, 25285, 25283, 25276, 25275, 25282, 25279, 25278, 25280, 25281, 25284, 25286);\n";
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
cp.code() += "etiss_coverage_count(1, 25314);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25291);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25294, 25292, 25293);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25313);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] - ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL))) >> " + std::to_string(Luimm5) + "ULL;\n";
cp.code() += "etiss_coverage_count(15, 25312, 25297, 25296, 25311, 25309, 25307, 25300, 25299, 25306, 25303, 25302, 25304, 25305, 25308, 25310);\n";
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
cp.code() += "etiss_coverage_count(1, 25346);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25315);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25318, 25316, 25317);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25345);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_int32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] - ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL) + " + std::to_string((1ULL << (Luimm5 - 1ULL))) + "ULL)) >> " + std::to_string(Luimm5) + "ULL;\n";
cp.code() += "etiss_coverage_count(23, 25344, 25321, 25320, 25343, 25341, 25339, 25331, 25324, 25323, 25330, 25327, 25326, 25328, 25329, 25337, 25332, 25335, 25333, 25334, 25336, 25338, 25340, 25342);\n";
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
cp.code() += "etiss_coverage_count(1, 25378);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25347);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25350, 25348, 25349);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25377);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] - ((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL) + " + std::to_string((1ULL << (Luimm5 - 1ULL))) + "ULL)) >> " + std::to_string(Luimm5) + "ULL;\n";
cp.code() += "etiss_coverage_count(23, 25376, 25353, 25352, 25375, 25373, 25371, 25363, 25356, 25355, 25362, 25359, 25358, 25360, 25361, 25369, 25364, 25367, 25365, 25366, 25368, 25370, 25372, 25374);\n";
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
cp.code() += "etiss_coverage_count(1, 25407);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25379);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25382, 25380, 25381);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25406);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_int32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL])) >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL);\n";
cp.code() += "etiss_coverage_count(19, 25405, 25385, 25384, 25404, 25394, 25392, 25388, 25387, 25391, 25390, 25393, 25403, 25400, 25397, 25396, 25398, 25399, 25401, 25402);\n";
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
cp.code() += "etiss_coverage_count(1, 25436);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25408);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25411, 25409, 25410);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25435);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL])) >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL);\n";
cp.code() += "etiss_coverage_count(19, 25434, 25414, 25413, 25433, 25423, 25421, 25417, 25416, 25420, 25419, 25422, 25432, 25429, 25426, 25425, 25427, 25428, 25430, 25431);\n";
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
cp.code() += "etiss_coverage_count(1, 25481);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25437);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25440, 25438, 25439);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25480);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_int32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + (1ULL << (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL) - 1ULL)))) >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL);\n";
cp.code() += "etiss_coverage_count(34, 25479, 25443, 25442, 25478, 25468, 25466, 25450, 25446, 25445, 25449, 25448, 25464, 25451, 25462, 25460, 25457, 25454, 25453, 25455, 25456, 25458, 25459, 25461, 25463, 25465, 25467, 25477, 25474, 25471, 25470, 25472, 25473, 25475, 25476);\n";
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
cp.code() += "etiss_coverage_count(1, 25526);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25482);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25485, 25483, 25484);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25525);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] + *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + (1ULL << (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL) - 1ULL)))) >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL);\n";
cp.code() += "etiss_coverage_count(34, 25524, 25488, 25487, 25523, 25513, 25511, 25495, 25491, 25490, 25494, 25493, 25509, 25496, 25507, 25505, 25502, 25499, 25498, 25500, 25501, 25503, 25504, 25506, 25508, 25510, 25512, 25522, 25519, 25516, 25515, 25517, 25518, 25520, 25521);\n";
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
cp.code() += "etiss_coverage_count(1, 25555);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25527);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25530, 25528, 25529);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25554);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_int32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] - *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL])) >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL);\n";
cp.code() += "etiss_coverage_count(19, 25553, 25533, 25532, 25552, 25542, 25540, 25536, 25535, 25539, 25538, 25541, 25551, 25548, 25545, 25544, 25546, 25547, 25549, 25550);\n";
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
cp.code() += "etiss_coverage_count(1, 25584);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25556);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25559, 25557, 25558);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25583);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] - *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL])) >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL);\n";
cp.code() += "etiss_coverage_count(19, 25582, 25562, 25561, 25581, 25571, 25569, 25565, 25564, 25568, 25567, 25570, 25580, 25577, 25574, 25573, 25575, 25576, 25578, 25579);\n";
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
cp.code() += "etiss_coverage_count(1, 25629);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25585);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25588, 25586, 25587);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25628);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_int32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] - *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + (1ULL << (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL) - 1ULL)))) >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL);\n";
cp.code() += "etiss_coverage_count(34, 25627, 25591, 25590, 25626, 25616, 25614, 25598, 25594, 25593, 25597, 25596, 25612, 25599, 25610, 25608, 25605, 25602, 25601, 25603, 25604, 25606, 25607, 25609, 25611, 25613, 25615, 25625, 25622, 25619, 25618, 25620, 25621, 25623, 25624);\n";
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
cp.code() += "etiss_coverage_count(1, 25674);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 25630);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25633, 25631, 25632);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 25673);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] - *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + (1ULL << (((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL) - 1ULL)))) >> ((((*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]) & 0xffffffffULL)) & 0x1fULL);\n";
cp.code() += "etiss_coverage_count(34, 25672, 25636, 25635, 25671, 25661, 25659, 25643, 25639, 25638, 25642, 25641, 25657, 25644, 25655, 25653, 25650, 25647, 25646, 25648, 25649, 25651, 25652, 25654, 25656, 25658, 25660, 25670, 25667, 25664, 25663, 25665, 25666, 25668, 25669);\n";
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
