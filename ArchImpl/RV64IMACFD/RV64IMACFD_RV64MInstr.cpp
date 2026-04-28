// clang-format off
/**
 * Generated on Mon, 27 Apr 2026 10:48:13 +0000.
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
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8206);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8172);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8178, 8175, 8173, 8176, 8177);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8205);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((etiss_int32)(((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) * (etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]))));\n";
cp.code() += "etiss_coverage_count(16, 8204, 8183, 8182, 8180, 8203, 8201, 8198, 8190, 8188, 8187, 8185, 8197, 8195, 8194, 8192, 8199);\n";
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
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8294);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8207);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8213, 8210, 8208, 8211, 8212);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8293);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8214);\n";
cp.code() += "if (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL] != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(5, 8221, 8219, 8218, 8216, 8220);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8284);\n";
cp.code() += "{ // block\n";
etiss_int32 MMIN = -2147483648LL;
cp.code() += "etiss_coverage_count(1, 8228);\n";
cp.code() += "etiss_coverage_count(1, 8229);\n";
cp.code() += "if ((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) == " + std::to_string(MMIN) + "LL && (etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) == -1LL) { // conditional\n";
cp.code() += "etiss_coverage_count(12, 8249, 8238, 8236, 8234, 8233, 8231, 8237, 8248, 8245, 8243, 8242, 8240);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = -2147483648LL;\n";
cp.code() += "etiss_coverage_count(4, 8259, 8254, 8253, 8251);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int64)(((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) / (etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])));\n";
cp.code() += "etiss_coverage_count(15, 8283, 8264, 8263, 8261, 8282, 8279, 8271, 8269, 8268, 8266, 8278, 8276, 8275, 8273, 8280);\n";
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = -1LL;\n";
cp.code() += "etiss_coverage_count(4, 8292, 8289, 8288, 8286);\n";
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
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8346);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8295);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8301, 8298, 8296, 8299, 8300);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8345);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8302);\n";
cp.code() += "if ((etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(6, 8311, 8309, 8307, 8306, 8304, 8310);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((etiss_int32)(((etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) / (etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]))));\n";
cp.code() += "etiss_coverage_count(16, 8336, 8316, 8315, 8313, 8335, 8333, 8331, 8323, 8321, 8320, 8318, 8330, 8328, 8327, 8325, 8332);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = -1LL;\n";
cp.code() += "etiss_coverage_count(4, 8344, 8341, 8340, 8338);\n";
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
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8439);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8347);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8353, 8350, 8348, 8351, 8352);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8438);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8354);\n";
cp.code() += "if (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL] != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(5, 8361, 8359, 8358, 8356, 8360);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8421);\n";
cp.code() += "{ // block\n";
etiss_int32 MMIN = -2147483648LL;
cp.code() += "etiss_coverage_count(1, 8368);\n";
cp.code() += "etiss_coverage_count(1, 8369);\n";
cp.code() += "if ((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) == " + std::to_string(MMIN) + "LL && (etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) == -1LL) { // conditional\n";
cp.code() += "etiss_coverage_count(12, 8389, 8378, 8376, 8374, 8373, 8371, 8377, 8388, 8385, 8383, 8382, 8380);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(5, 8396, 8394, 8393, 8391, 8395);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int64)(((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) % (etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])));\n";
cp.code() += "etiss_coverage_count(15, 8420, 8401, 8400, 8398, 8419, 8416, 8408, 8406, 8405, 8403, 8415, 8413, 8412, 8410, 8417);\n";
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int64)(((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL])));\n";
cp.code() += "etiss_coverage_count(10, 8437, 8426, 8425, 8423, 8436, 8433, 8431, 8430, 8428, 8434);\n";
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
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8499);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8440);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 8446, 8443, 8441, 8444, 8445);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8498);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8447);\n";
cp.code() += "if ((etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(6, 8456, 8454, 8452, 8451, 8449, 8455);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((etiss_int32)(((etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) % (etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]))));\n";
cp.code() += "etiss_coverage_count(16, 8481, 8461, 8460, 8458, 8480, 8478, 8476, 8468, 8466, 8465, 8463, 8475, 8473, 8472, 8470, 8477);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)(((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL])));\n";
cp.code() += "etiss_coverage_count(10, 8497, 8486, 8485, 8483, 8496, 8493, 8491, 8490, 8488, 8494);\n";
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
