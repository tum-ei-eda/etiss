// clang-format off
/**
 * Generated on Fri, 17 Apr 2026 09:57:47 +0200.
 *
 * This file contains the instruction behavior models of the tum_rvm
 * instruction set for the RV64IMACFD core architecture.
 */

#include "RV64IMACFDArch.h"
#include "RV64IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// MUL -------------------------------------------------------------------------
static InstructionDefinition mul_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"mul",
	(uint32_t) 0x2000033,
	(uint32_t) 0xfe00707f,
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

		cp.code() = std::string("//MUL\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 240);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 9186);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 9154);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 9160, 9157, 9155, 9158, 9159);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 9185);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int64 res = (etiss_int64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) * (etiss_int64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(10, 9175, 9174, 9167, 9166, 9165, 9163, 9173, 9172, 9171, 9169);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 9184, 9180, 9179, 9177, 9183, 9181);\n";
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
ss << "mul" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// MULH ------------------------------------------------------------------------
static InstructionDefinition mulh_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"mulh",
	(uint32_t) 0x2001033,
	(uint32_t) 0xfe00707f,
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

		cp.code() = std::string("//MULH\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 241);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 9214);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 9187);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 9193, 9190, 9188, 9191, 9192);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 9213);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = RV64IMACFD_mulh((etiss_int64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]), (etiss_int64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]));\n";
cp.code() += "etiss_coverage_count(13, 9212, 9198, 9197, 9195, 9211, 9204, 9203, 9202, 9200, 9210, 9209, 9208, 9206);\n";
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
ss << "mulh" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// MULHSU ----------------------------------------------------------------------
static InstructionDefinition mulhsu_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"mulhsu",
	(uint32_t) 0x2002033,
	(uint32_t) 0xfe00707f,
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

		cp.code() = std::string("//MULHSU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 242);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 9241);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 9215);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 9221, 9218, 9216, 9219, 9220);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 9240);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = RV64IMACFD_mulhsu((etiss_int64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]), *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(12, 9239, 9226, 9225, 9223, 9238, 9232, 9231, 9230, 9228, 9237, 9236, 9234);\n";
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
ss << "mulhsu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// MULHU -----------------------------------------------------------------------
static InstructionDefinition mulhu_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"mulhu",
	(uint32_t) 0x2003033,
	(uint32_t) 0xfe00707f,
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

		cp.code() = std::string("//MULHU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 243);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 9267);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 9242);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 9248, 9245, 9243, 9246, 9247);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 9266);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = RV64IMACFD_mulhu(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL], *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(11, 9265, 9253, 9252, 9250, 9264, 9258, 9257, 9255, 9263, 9262, 9260);\n";
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
ss << "mulhu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
// clang-format on
