// clang-format off
/**
 * Generated on Mon, 26 Oct 2026 08:39:20 +0000.
 *
 * This file contains the instruction behavior models of the RV64M
 * instruction set for the RV64IMACFD core architecture.
 */

#include "RV64IMACFDArch.h"
#include "RV64IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// MULW ------------------------------------------------------------------------
static InstructionDefinition mulw_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"mulw",
	(uint64_t) 0x200003b,
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

		cp.code() = std::string("//MULW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 209);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 9071);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 9037);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 9043, 9040, 9038, 9041, 9042);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 9070);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((etiss_int32)(((etiss_uint32)((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL])) * (etiss_uint32)((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])))));\n";
cp.code() += "etiss_coverage_count(16, 9069, 9048, 9047, 9045, 9068, 9066, 9063, 9055, 9053, 9052, 9050, 9062, 9060, 9059, 9057, 9064);\n";
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
ss << "mulw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// DIVW ------------------------------------------------------------------------
static InstructionDefinition divw_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"divw",
	(uint64_t) 0x200403b,
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

		cp.code() = std::string("//DIVW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 210);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 9166);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 9072);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 9078, 9075, 9073, 9076, 9077);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 9165);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 9079);\n";
cp.code() += "if (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL] != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(5, 9086, 9084, 9083, 9081, 9085);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 9154);\n";
cp.code() += "{ // block\n";
etiss_int32 MMIN = -2147483648LL;
cp.code() += "etiss_coverage_count(1, 9093);\n";
cp.code() += "etiss_coverage_count(1, 9094);\n";
cp.code() += "if ((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) == " + std::to_string(MMIN) + "LL && (etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) == -1LL) { // conditional\n";
cp.code() += "etiss_coverage_count(12, 9114, 9103, 9101, 9099, 9098, 9096, 9102, 9113, 9110, 9108, 9107, 9105);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = -2147483648LL;\n";
cp.code() += "etiss_coverage_count(4, 9127, 9119, 9118, 9116);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((etiss_int64)(((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) / (etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]))));\n";
cp.code() += "etiss_coverage_count(16, 9153, 9132, 9131, 9129, 9152, 9150, 9147, 9139, 9137, 9136, 9134, 9146, 9144, 9143, 9141, 9148);\n";
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = -1LL;\n";
cp.code() += "etiss_coverage_count(4, 9164, 9159, 9158, 9156);\n";
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
ss << "divw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// DIVUW -----------------------------------------------------------------------
static InstructionDefinition divuw_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"divuw",
	(uint64_t) 0x200503b,
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

		cp.code() = std::string("//DIVUW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 211);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 9220);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 9167);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 9173, 9170, 9168, 9171, 9172);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 9219);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 9174);\n";
cp.code() += "if ((etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(6, 9183, 9181, 9179, 9178, 9176, 9182);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((etiss_int32)(((etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) / (etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]))));\n";
cp.code() += "etiss_coverage_count(16, 9208, 9188, 9187, 9185, 9207, 9205, 9203, 9195, 9193, 9192, 9190, 9202, 9200, 9199, 9197, 9204);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = -1LL;\n";
cp.code() += "etiss_coverage_count(4, 9218, 9213, 9212, 9210);\n";
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
ss << "divuw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// REMW ------------------------------------------------------------------------
static InstructionDefinition remw_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"remw",
	(uint64_t) 0x200603b,
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

		cp.code() = std::string("//REMW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 212);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 9317);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 9221);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 9227, 9224, 9222, 9225, 9226);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 9316);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 9228);\n";
cp.code() += "if (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL] != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(5, 9235, 9233, 9232, 9230, 9234);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 9297);\n";
cp.code() += "{ // block\n";
etiss_int32 MMIN = -2147483648LL;
cp.code() += "etiss_coverage_count(1, 9242);\n";
cp.code() += "etiss_coverage_count(1, 9243);\n";
cp.code() += "if ((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) == " + std::to_string(MMIN) + "LL && (etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) == -1LL) { // conditional\n";
cp.code() += "etiss_coverage_count(12, 9263, 9252, 9250, 9248, 9247, 9245, 9251, 9262, 9259, 9257, 9256, 9254);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(5, 9270, 9268, 9267, 9265, 9269);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((etiss_int64)(((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) % (etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]))));\n";
cp.code() += "etiss_coverage_count(16, 9296, 9275, 9274, 9272, 9295, 9293, 9290, 9282, 9280, 9279, 9277, 9289, 9287, 9286, 9284, 9291);\n";
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((etiss_int64)(((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]))));\n";
cp.code() += "etiss_coverage_count(11, 9315, 9302, 9301, 9299, 9314, 9312, 9309, 9307, 9306, 9304, 9310);\n";
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
ss << "remw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// REMUW -----------------------------------------------------------------------
static InstructionDefinition remuw_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"remuw",
	(uint64_t) 0x200703b,
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

		cp.code() = std::string("//REMUW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 213);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 9377);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 9318);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 9324, 9321, 9319, 9322, 9323);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 9376);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 9325);\n";
cp.code() += "if ((etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(6, 9334, 9332, 9330, 9329, 9327, 9333);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((etiss_int32)(((etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) % (etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]))));\n";
cp.code() += "etiss_coverage_count(16, 9359, 9339, 9338, 9336, 9358, 9356, 9354, 9346, 9344, 9343, 9341, 9353, 9351, 9350, 9348, 9355);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)(((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL])));\n";
cp.code() += "etiss_coverage_count(10, 9375, 9364, 9363, 9361, 9374, 9371, 9369, 9368, 9366, 9372);\n";
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
ss << "remuw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
// clang-format on
