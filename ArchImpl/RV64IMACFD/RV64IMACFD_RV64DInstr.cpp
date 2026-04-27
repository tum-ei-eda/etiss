// clang-format off
/**
 * Generated on Mon, 27 Apr 2026 10:48:13 +0000.
 *
 * This file contains the instruction behavior models of the RV64D
 * instruction set for the RV64IMACFD core architecture.
 */

#include "RV64IMACFDArch.h"
#include "RV64IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// FCVT_L_D --------------------------------------------------------------------
static InstructionDefinition fcvt_l_d_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fcvt_l_d",
	(uint64_t) 0xc2200053,
	(uint64_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FCVT_L_D\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 218);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8679);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = fcvt_d((etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), 0LL, " + std::to_string(rm) + "ULL);\n";
cp.code() += "etiss_coverage_count(10, 8663, 8654, 8653, 8651, 8662, 8659, 8657, 8656, 8660, 8661);\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 8666, 8665);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 8678, 8667, 8677, 8671, 8668, 8672, 8675, 8673, 8676);\n";
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
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fcvt_l_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCVT_LU_D -------------------------------------------------------------------
static InstructionDefinition fcvt_lu_d_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fcvt_lu_d",
	(uint64_t) 0xc2300053,
	(uint64_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FCVT_LU_D\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 219);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8709);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = fcvt_d((etiss_uint64)(*((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), 1ULL, " + std::to_string(rm) + "ULL);\n";
cp.code() += "etiss_coverage_count(10, 8693, 8684, 8683, 8681, 8692, 8689, 8687, 8686, 8690, 8691);\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "etiss_coverage_count(2, 8696, 8695);\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "etiss_coverage_count(9, 8708, 8697, 8707, 8701, 8698, 8702, 8705, 8703, 8706);\n";
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
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fcvt_lu_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCVT_D_L --------------------------------------------------------------------
static InstructionDefinition fcvt_d_l_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fcvt_d_l",
	(uint64_t) 0xd2200053,
	(uint64_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FCVT_D_L\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 220);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8741);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fcvt_d(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL], 2ULL, " + std::to_string(rm) + "ULL);\n";
cp.code() += "etiss_coverage_count(7, 8719, 8718, 8715, 8714, 8712, 8716, 8717);\n";
cp.code() += "*((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = res;\n";
cp.code() += "etiss_coverage_count(4, 8728, 8726, 8725, 8727);\n";
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
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fcvt_d_l" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCVT_D_LU -------------------------------------------------------------------
static InstructionDefinition fcvt_d_lu_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fcvt_d_lu",
	(uint64_t) 0xd2300053,
	(uint64_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FCVT_D_LU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 221);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8773);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fcvt_d(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL], 3ULL, " + std::to_string(rm) + "ULL);\n";
cp.code() += "etiss_coverage_count(7, 8751, 8750, 8747, 8746, 8744, 8748, 8749);\n";
cp.code() += "*((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = res;\n";
cp.code() += "etiss_coverage_count(4, 8760, 8758, 8757, 8759);\n";
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
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fcvt_d_lu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FMV_X_D ---------------------------------------------------------------------
static InstructionDefinition fmv_x_d_rd_rs1 (
	ISA32_RV64IMACFD,
	"fmv_x_d",
	(uint64_t) 0xe2000053,
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

		cp.code() = std::string("//FMV_X_D\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 222);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8783);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(6, 8782, 8778, 8777, 8775, 8781, 8780);\n";
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
ss << "fmv_x_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FMV_D_X ---------------------------------------------------------------------
static InstructionDefinition fmv_d_x_rd_rs1 (
	ISA32_RV64IMACFD,
	"fmv_d_x",
	(uint64_t) 0xf2000053,
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

		cp.code() = std::string("//FMV_D_X\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 223);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8793);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(6, 8792, 8786, 8785, 8791, 8790, 8788);\n";
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
ss << "fmv_d_x" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
// clang-format on
