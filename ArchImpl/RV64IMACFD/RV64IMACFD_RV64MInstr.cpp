/**
 * Generated on Wed, 13 Mar 2024 21:23:08 +0100.
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
	(uint32_t) 0x200003b,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//MULW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 209);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7771);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7742);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 7739, 7737, 7740, 7741, 7770);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 7769);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((etiss_int32)(((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) * (etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]))));\n";
cp.code() += "etiss_coverage_count(16, 7768, 7747, 7746, 7744, 7767, 7765, 7762, 7754, 7752, 7751, 7749, 7761, 7759, 7758, 7756, 7763);\n";
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
	(uint32_t) 0x200403b,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//DIVW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 210);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7859);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7777);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 7774, 7772, 7775, 7776, 7858);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 7857);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7784);\n";
cp.code() += "if (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL] != 0ULL) { // conditional\n";
cp.code() += "etiss_coverage_count(5, 7782, 7781, 7779, 7783, 7856);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 7847);\n";
cp.code() += "{ // block\n";
etiss_int32 MMIN = -2147483648LL;
cp.code() += "etiss_coverage_count(1, 7791);\n";
cp.code() += "etiss_coverage_count(1, 7811);\n";
cp.code() += "if ((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) == " + std::to_string(MMIN) + "LL && (etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) == -1LL) { // conditional\n";
cp.code() += "etiss_coverage_count(12, 7800, 7798, 7796, 7795, 7793, 7799, 7810, 7807, 7805, 7804, 7802, 7846);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = -2147483648LL;\n";
cp.code() += "etiss_coverage_count(4, 7821, 7816, 7815, 7813);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int64)(((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) / (etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])));\n";
cp.code() += "etiss_coverage_count(15, 7845, 7826, 7825, 7823, 7844, 7841, 7833, 7831, 7830, 7828, 7840, 7838, 7837, 7835, 7842);\n";
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = -1LL;\n";
cp.code() += "etiss_coverage_count(4, 7855, 7852, 7851, 7849);\n";
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
	(uint32_t) 0x200503b,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//DIVUW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 211);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7911);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7865);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 7862, 7860, 7863, 7864, 7910);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 7909);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7874);\n";
cp.code() += "if ((etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) != 0ULL) { // conditional\n";
cp.code() += "etiss_coverage_count(6, 7872, 7870, 7869, 7867, 7873, 7908);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((etiss_int32)(((etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) / (etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]))));\n";
cp.code() += "etiss_coverage_count(16, 7899, 7879, 7878, 7876, 7898, 7896, 7894, 7886, 7884, 7883, 7881, 7893, 7891, 7890, 7888, 7895);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = -1LL;\n";
cp.code() += "etiss_coverage_count(4, 7907, 7904, 7903, 7901);\n";
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
	(uint32_t) 0x200603b,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//REMW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 212);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8004);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7917);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 7914, 7912, 7915, 7916, 8003);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8002);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7924);\n";
cp.code() += "if (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL] != 0ULL) { // conditional\n";
cp.code() += "etiss_coverage_count(5, 7922, 7921, 7919, 7923, 8001);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 7984);\n";
cp.code() += "{ // block\n";
etiss_int32 MMIN = -2147483648LL;
cp.code() += "etiss_coverage_count(1, 7931);\n";
cp.code() += "etiss_coverage_count(1, 7951);\n";
cp.code() += "if ((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) == " + std::to_string(MMIN) + "LL && (etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) == -1LL) { // conditional\n";
cp.code() += "etiss_coverage_count(12, 7940, 7938, 7936, 7935, 7933, 7939, 7950, 7947, 7945, 7944, 7942, 7983);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = 0ULL;\n";
cp.code() += "etiss_coverage_count(5, 7958, 7956, 7955, 7953, 7957);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int64)(((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) % (etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])));\n";
cp.code() += "etiss_coverage_count(15, 7982, 7963, 7962, 7960, 7981, 7978, 7970, 7968, 7967, 7965, 7977, 7975, 7974, 7972, 7979);\n";
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int64)(((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL])));\n";
cp.code() += "etiss_coverage_count(10, 8000, 7989, 7988, 7986, 7999, 7996, 7994, 7993, 7991, 7997);\n";
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
	(uint32_t) 0x200703b,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//REMUW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 213);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 8064);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8010);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 8007, 8005, 8008, 8009, 8063);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 8062);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 8019);\n";
cp.code() += "if ((etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) != 0ULL) { // conditional\n";
cp.code() += "etiss_coverage_count(6, 8017, 8015, 8014, 8012, 8018, 8061);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((etiss_int32)(((etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) % (etiss_uint32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]))));\n";
cp.code() += "etiss_coverage_count(16, 8044, 8024, 8023, 8021, 8043, 8041, 8039, 8031, 8029, 8028, 8026, 8038, 8036, 8035, 8033, 8040);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)(((etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL])));\n";
cp.code() += "etiss_coverage_count(10, 8060, 8049, 8048, 8046, 8059, 8056, 8054, 8053, 8051, 8057);\n";
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
