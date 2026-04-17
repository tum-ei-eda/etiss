// clang-format off
/**
 * Generated on Fri, 17 Apr 2026 09:57:47 +0200.
 *
 * This file contains the instruction behavior models of the RV32I
 * instruction set for the RV64IMACFD core architecture.
 */

#include "RV64IMACFDArch.h"
#include "RV64IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// LUI -------------------------------------------------------------------------
static InstructionDefinition lui_rd_imm (
	ISA32_RV64IMACFD,
	"lui",
	(uint32_t) 0x000037,
	(uint32_t) 0x00007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 imm = 0;
static BitArrayRange R_imm_12(31, 12);
imm += R_imm_12.read(ba) << 12;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//LUI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 0);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1190);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 1196, 1193, 1191, 1194, 1195);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = " + std::to_string((etiss_uint64)(((etiss_int32)(imm)))) + "ULL;\n";
cp.code() += "etiss_coverage_count(8, 1207, 1201, 1200, 1198, 1206, 1203, 1202, 1204);\n";
} // conditional
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
etiss_uint32 imm = 0;
static BitArrayRange R_imm_12(31, 12);
imm += R_imm_12.read(ba) << 12;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "lui" << " # " << ba << (" [rd=" + std::to_string(rd) + " | imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AUIPC -----------------------------------------------------------------------
static InstructionDefinition auipc_rd_imm (
	ISA32_RV64IMACFD,
	"auipc",
	(uint32_t) 0x000017,
	(uint32_t) 0x00007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 imm = 0;
static BitArrayRange R_imm_12(31, 12);
imm += R_imm_12.read(ba) << 12;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AUIPC\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 1);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1208);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 1214, 1211, 1209, 1212, 1213);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = " + std::to_string(ic.current_address_ + (etiss_int32)(imm)) + "LL;\n";
cp.code() += "etiss_coverage_count(8, 1224, 1219, 1218, 1216, 1223, 1220, 1222, 1221);\n";
} // conditional
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
etiss_uint32 imm = 0;
static BitArrayRange R_imm_12(31, 12);
imm += R_imm_12.read(ba) << 12;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "auipc" << " # " << ba << (" [rd=" + std::to_string(rd) + " | imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// JAL -------------------------------------------------------------------------
static InstructionDefinition jal_rd_imm (
	ISA32_RV64IMACFD,
	"jal",
	(uint32_t) 0x00006f,
	(uint32_t) 0x00007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 imm = 0;
static BitArrayRange R_imm_12(19, 12);
imm += R_imm_12.read(ba) << 12;
static BitArrayRange R_imm_11(20, 20);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(30, 21);
imm += R_imm_1.read(ba) << 1;
static BitArrayRange R_imm_20(31, 31);
imm += R_imm_20.read(ba) << 20;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//JAL\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 2);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1256);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1225);\n";
if (imm % 2ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 1228, 1226);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1232);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_raise(cpu, system, plugin_pointers, 0LL, 0LL);\n";
cp.code() += "etiss_coverage_count(2, 1231, 1229);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
} // conditional
else { // conditional
{ // block
cp.code() += "etiss_coverage_count(1, 1255);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1233);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 1239, 1236, 1234, 1237, 1238);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1248, 1244, 1243, 1241, 1247, 1245, 1246);\n";
} // conditional
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + ((etiss_int32)(((etiss_int32)imm) << (11)) >> (11))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 1254, 1249, 1253, 1250, 1252, 1251);\n";
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
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//JAL\n");

// -----------------------------------------------------------------------------
cp.code() += "return cpu->exception;\n";
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
etiss_uint32 imm = 0;
static BitArrayRange R_imm_12(19, 12);
imm += R_imm_12.read(ba) << 12;
static BitArrayRange R_imm_11(20, 20);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(30, 21);
imm += R_imm_1.read(ba) << 1;
static BitArrayRange R_imm_20(31, 31);
imm += R_imm_20.read(ba) << 20;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "jal" << " # " << ba << (" [rd=" + std::to_string(rd) + " | imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// JALR ------------------------------------------------------------------------
static InstructionDefinition jalr_rd_rs1_imm (
	ISA32_RV64IMACFD,
	"jalr",
	(uint32_t) 0x000067,
	(uint32_t) 0x00707f,
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//JALR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 3);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//JALR\n");

// -----------------------------------------------------------------------------
cp.code() += "return cpu->exception;\n";
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
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "jalr" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// BEQ -------------------------------------------------------------------------
static InstructionDefinition beq_imm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"beq",
	(uint32_t) 0x000063,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint16 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(30, 25);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_12(31, 31);
imm += R_imm_12.read(ba) << 12;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//BEQ\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 4);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1331);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1303);\n";
cp.code() += "if (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] == *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) { // conditional\n";
cp.code() += "etiss_coverage_count(7, 1314, 1308, 1307, 1305, 1313, 1312, 1310);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1330);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1315);\n";
if (imm % 2ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 1318, 1316);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1322);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_raise(cpu, system, plugin_pointers, 0LL, 0LL);\n";
cp.code() += "etiss_coverage_count(2, 1321, 1319);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
} // conditional
else { // conditional
{ // block
cp.code() += "etiss_coverage_count(1, 1329);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + ((etiss_int16)(((etiss_int16)imm) << (3)) >> (3))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 1328, 1323, 1327, 1324, 1326, 1325);\n";
cp.code() += "} // block\n";
} // block
} // conditional
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

		cp.code() = std::string("//BEQ\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception || cpu->nextPc != " + std::to_string(ic.current_address_ + 4) + "ULL) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint16 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(30, 25);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_12(31, 31);
imm += R_imm_12.read(ba) << 12;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "beq" << " # " << ba << (" [imm=" + std::to_string(imm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// BNE -------------------------------------------------------------------------
static InstructionDefinition bne_imm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"bne",
	(uint32_t) 0x001063,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint16 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(30, 25);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_12(31, 31);
imm += R_imm_12.read(ba) << 12;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//BNE\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 5);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1360);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1332);\n";
cp.code() += "if (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] != *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) { // conditional\n";
cp.code() += "etiss_coverage_count(7, 1343, 1337, 1336, 1334, 1342, 1341, 1339);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1359);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1344);\n";
if (imm % 2ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 1347, 1345);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1351);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_raise(cpu, system, plugin_pointers, 0LL, 0LL);\n";
cp.code() += "etiss_coverage_count(2, 1350, 1348);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
} // conditional
else { // conditional
{ // block
cp.code() += "etiss_coverage_count(1, 1358);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + ((etiss_int16)(((etiss_int16)imm) << (3)) >> (3))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 1357, 1352, 1356, 1353, 1355, 1354);\n";
cp.code() += "} // block\n";
} // block
} // conditional
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

		cp.code() = std::string("//BNE\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception || cpu->nextPc != " + std::to_string(ic.current_address_ + 4) + "ULL) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint16 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(30, 25);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_12(31, 31);
imm += R_imm_12.read(ba) << 12;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "bne" << " # " << ba << (" [imm=" + std::to_string(imm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// BLT -------------------------------------------------------------------------
static InstructionDefinition blt_imm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"blt",
	(uint32_t) 0x004063,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint16 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(30, 25);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_12(31, 31);
imm += R_imm_12.read(ba) << 12;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//BLT\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 6);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1393);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1361);\n";
cp.code() += "if ((etiss_int64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) < (etiss_int64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])) { // conditional\n";
cp.code() += "etiss_coverage_count(9, 1376, 1368, 1366, 1365, 1363, 1375, 1373, 1372, 1370);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1392);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1377);\n";
if (imm % 2ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 1380, 1378);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1384);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_raise(cpu, system, plugin_pointers, 0LL, 0LL);\n";
cp.code() += "etiss_coverage_count(2, 1383, 1381);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
} // conditional
else { // conditional
{ // block
cp.code() += "etiss_coverage_count(1, 1391);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + ((etiss_int16)(((etiss_int16)imm) << (3)) >> (3))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 1390, 1385, 1389, 1386, 1388, 1387);\n";
cp.code() += "} // block\n";
} // block
} // conditional
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

		cp.code() = std::string("//BLT\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception || cpu->nextPc != " + std::to_string(ic.current_address_ + 4) + "ULL) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint16 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(30, 25);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_12(31, 31);
imm += R_imm_12.read(ba) << 12;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "blt" << " # " << ba << (" [imm=" + std::to_string(imm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// BGE -------------------------------------------------------------------------
static InstructionDefinition bge_imm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"bge",
	(uint32_t) 0x005063,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint16 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(30, 25);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_12(31, 31);
imm += R_imm_12.read(ba) << 12;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//BGE\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 7);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1426);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1394);\n";
cp.code() += "if ((etiss_int64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) >= (etiss_int64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])) { // conditional\n";
cp.code() += "etiss_coverage_count(9, 1409, 1401, 1399, 1398, 1396, 1408, 1406, 1405, 1403);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1425);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1410);\n";
if (imm % 2ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 1413, 1411);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1417);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_raise(cpu, system, plugin_pointers, 0LL, 0LL);\n";
cp.code() += "etiss_coverage_count(2, 1416, 1414);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
} // conditional
else { // conditional
{ // block
cp.code() += "etiss_coverage_count(1, 1424);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + ((etiss_int16)(((etiss_int16)imm) << (3)) >> (3))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 1423, 1418, 1422, 1419, 1421, 1420);\n";
cp.code() += "} // block\n";
} // block
} // conditional
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

		cp.code() = std::string("//BGE\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception || cpu->nextPc != " + std::to_string(ic.current_address_ + 4) + "ULL) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint16 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(30, 25);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_12(31, 31);
imm += R_imm_12.read(ba) << 12;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "bge" << " # " << ba << (" [imm=" + std::to_string(imm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// BLTU ------------------------------------------------------------------------
static InstructionDefinition bltu_imm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"bltu",
	(uint32_t) 0x006063,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint16 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(30, 25);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_12(31, 31);
imm += R_imm_12.read(ba) << 12;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//BLTU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 8);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1455);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1427);\n";
cp.code() += "if (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] < *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) { // conditional\n";
cp.code() += "etiss_coverage_count(7, 1438, 1432, 1431, 1429, 1437, 1436, 1434);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1454);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1439);\n";
if (imm % 2ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 1442, 1440);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1446);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_raise(cpu, system, plugin_pointers, 0LL, 0LL);\n";
cp.code() += "etiss_coverage_count(2, 1445, 1443);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
} // conditional
else { // conditional
{ // block
cp.code() += "etiss_coverage_count(1, 1453);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + ((etiss_int16)(((etiss_int16)imm) << (3)) >> (3))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 1452, 1447, 1451, 1448, 1450, 1449);\n";
cp.code() += "} // block\n";
} // block
} // conditional
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

		cp.code() = std::string("//BLTU\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception || cpu->nextPc != " + std::to_string(ic.current_address_ + 4) + "ULL) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint16 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(30, 25);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_12(31, 31);
imm += R_imm_12.read(ba) << 12;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "bltu" << " # " << ba << (" [imm=" + std::to_string(imm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// BGEU ------------------------------------------------------------------------
static InstructionDefinition bgeu_imm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"bgeu",
	(uint32_t) 0x007063,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint16 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(30, 25);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_12(31, 31);
imm += R_imm_12.read(ba) << 12;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//BGEU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 9);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1484);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1456);\n";
cp.code() += "if (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] >= *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) { // conditional\n";
cp.code() += "etiss_coverage_count(7, 1467, 1461, 1460, 1458, 1466, 1465, 1463);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1483);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1468);\n";
if (imm % 2ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 1471, 1469);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1475);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_raise(cpu, system, plugin_pointers, 0LL, 0LL);\n";
cp.code() += "etiss_coverage_count(2, 1474, 1472);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
} // conditional
else { // conditional
{ // block
cp.code() += "etiss_coverage_count(1, 1482);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + ((etiss_int16)(((etiss_int16)imm) << (3)) >> (3))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 1481, 1476, 1480, 1477, 1479, 1478);\n";
cp.code() += "} // block\n";
} // block
} // conditional
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

		cp.code() = std::string("//BGEU\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception || cpu->nextPc != " + std::to_string(ic.current_address_ + 4) + "ULL) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint16 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(30, 25);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_12(31, 31);
imm += R_imm_12.read(ba) << 12;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "bgeu" << " # " << ba << (" [imm=" + std::to_string(imm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// LB --------------------------------------------------------------------------
static InstructionDefinition lb_rd_rs1_imm (
	ISA32_RV64IMACFD,
	"lb",
	(uint32_t) 0x000003,
	(uint32_t) 0x00707f,
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//LB\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 10);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1518);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 load_address = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(7, 1494, 1493, 1490, 1489, 1487, 1492, 1491);\n";
cp.code() += "etiss_uint8 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 1);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int8 res = (etiss_int8)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(4, 1501, 1500, 1498, 1497);\n";
cp.code() += "etiss_coverage_count(1, 1502);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 1508, 1505, 1503, 1506, 1507);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 1517, 1513, 1512, 1510, 1516, 1514);\n";
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//LB\n");

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
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "lb" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// LH --------------------------------------------------------------------------
static InstructionDefinition lh_rd_rs1_imm (
	ISA32_RV64IMACFD,
	"lh",
	(uint32_t) 0x001003,
	(uint32_t) 0x00707f,
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//LH\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 11);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1552);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 load_address = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(7, 1528, 1527, 1524, 1523, 1521, 1526, 1525);\n";
cp.code() += "etiss_uint16 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 2);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int16 res = (etiss_int16)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(4, 1535, 1534, 1532, 1531);\n";
cp.code() += "etiss_coverage_count(1, 1536);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 1542, 1539, 1537, 1540, 1541);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 1551, 1547, 1546, 1544, 1550, 1548);\n";
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//LH\n");

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
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "lh" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// LW --------------------------------------------------------------------------
static InstructionDefinition lw_rd_rs1_imm (
	ISA32_RV64IMACFD,
	"lw",
	(uint32_t) 0x002003,
	(uint32_t) 0x00707f,
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//LW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 12);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1586);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 load_address = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(7, 1562, 1561, 1558, 1557, 1555, 1560, 1559);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int32 res = (etiss_int32)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(4, 1569, 1568, 1566, 1565);\n";
cp.code() += "etiss_coverage_count(1, 1570);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 1576, 1573, 1571, 1574, 1575);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 1585, 1581, 1580, 1578, 1584, 1582);\n";
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//LW\n");

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
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "lw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// LBU -------------------------------------------------------------------------
static InstructionDefinition lbu_rd_rs1_imm (
	ISA32_RV64IMACFD,
	"lbu",
	(uint32_t) 0x004003,
	(uint32_t) 0x00707f,
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//LBU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 13);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1620);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 load_address = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(7, 1596, 1595, 1592, 1591, 1589, 1594, 1593);\n";
cp.code() += "etiss_uint8 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 1);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint8 res = (etiss_uint8)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(4, 1603, 1602, 1600, 1599);\n";
cp.code() += "etiss_coverage_count(1, 1604);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 1610, 1607, 1605, 1608, 1609);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 1619, 1615, 1614, 1612, 1618, 1616);\n";
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//LBU\n");

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
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "lbu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// LHU -------------------------------------------------------------------------
static InstructionDefinition lhu_rd_rs1_imm (
	ISA32_RV64IMACFD,
	"lhu",
	(uint32_t) 0x005003,
	(uint32_t) 0x00707f,
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//LHU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 14);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1654);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 load_address = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(7, 1630, 1629, 1626, 1625, 1623, 1628, 1627);\n";
cp.code() += "etiss_uint16 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 2);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint16 res = (etiss_uint16)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(4, 1637, 1636, 1634, 1633);\n";
cp.code() += "etiss_coverage_count(1, 1638);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 1644, 1641, 1639, 1642, 1643);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)(res);\n";
cp.code() += "etiss_coverage_count(6, 1653, 1649, 1648, 1646, 1652, 1650);\n";
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//LHU\n");

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
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "lhu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SB --------------------------------------------------------------------------
static InstructionDefinition sb_imm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"sb",
	(uint32_t) 0x000023,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(11, 7);
imm += R_imm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(31, 25);
imm += R_imm_5.read(ba) << 5;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SB\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 15);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1676);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 store_address = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(7, 1664, 1663, 1660, 1659, 1657, 1662, 1661);\n";
cp.code() += "etiss_uint8 mem_val_0;\n";
cp.code() += "mem_val_0 = (etiss_int8)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(7, 1675, 1667, 1666, 1674, 1672, 1671, 1669);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, store_address, (etiss_uint8*)&mem_val_0, 1);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
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

		cp.code() = std::string("//SB\n");

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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(11, 7);
imm += R_imm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(31, 25);
imm += R_imm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "sb" << " # " << ba << (" [imm=" + std::to_string(imm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SH --------------------------------------------------------------------------
static InstructionDefinition sh_imm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"sh",
	(uint32_t) 0x001023,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(11, 7);
imm += R_imm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(31, 25);
imm += R_imm_5.read(ba) << 5;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SH\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 16);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1698);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 store_address = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(7, 1686, 1685, 1682, 1681, 1679, 1684, 1683);\n";
cp.code() += "etiss_uint16 mem_val_0;\n";
cp.code() += "mem_val_0 = (etiss_int16)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(7, 1697, 1689, 1688, 1696, 1694, 1693, 1691);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, store_address, (etiss_uint8*)&mem_val_0, 2);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
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

		cp.code() = std::string("//SH\n");

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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(11, 7);
imm += R_imm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(31, 25);
imm += R_imm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "sh" << " # " << ba << (" [imm=" + std::to_string(imm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SW --------------------------------------------------------------------------
static InstructionDefinition sw_imm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"sw",
	(uint32_t) 0x002023,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(11, 7);
imm += R_imm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(31, 25);
imm += R_imm_5.read(ba) << 5;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 17);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1720);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 store_address = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(7, 1708, 1707, 1704, 1703, 1701, 1706, 1705);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "mem_val_0 = (etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(7, 1719, 1711, 1710, 1718, 1716, 1715, 1713);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, store_address, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
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

		cp.code() = std::string("//SW\n");

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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(11, 7);
imm += R_imm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(31, 25);
imm += R_imm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "sw" << " # " << ba << (" [imm=" + std::to_string(imm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// ADDI ------------------------------------------------------------------------
static InstructionDefinition addi_rd_rs1_imm (
	ISA32_RV64IMACFD,
	"addi",
	(uint32_t) 0x000013,
	(uint32_t) 0x00707f,
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//ADDI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 18);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1721);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 1727, 1724, 1722, 1725, 1726);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(10, 1741, 1732, 1731, 1729, 1740, 1737, 1736, 1734, 1739, 1738);\n";
} // conditional
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "addi" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SLTI ------------------------------------------------------------------------
static InstructionDefinition slti_rd_rs1_imm (
	ISA32_RV64IMACFD,
	"slti",
	(uint32_t) 0x002013,
	(uint32_t) 0x00707f,
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SLTI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 19);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1742);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 1748, 1745, 1743, 1746, 1747);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (((etiss_int64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) < " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL)) ? (1ULL) : (0LL);\n";
cp.code() += "etiss_coverage_count(15, 1767, 1753, 1752, 1750, 1766, 1762, 1759, 1758, 1757, 1755, 1761, 1760, 1763, 1764, 1765);\n";
} // conditional
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "slti" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SLTIU -----------------------------------------------------------------------
static InstructionDefinition sltiu_rd_rs1_imm (
	ISA32_RV64IMACFD,
	"sltiu",
	(uint32_t) 0x003013,
	(uint32_t) 0x00707f,
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SLTIU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 20);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1768);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 1774, 1771, 1769, 1772, 1773);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = ((*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] < " + std::to_string((etiss_uint64)((((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))))) + "ULL)) ? (1ULL) : (0LL);\n";
cp.code() += "etiss_coverage_count(16, 1795, 1779, 1778, 1776, 1794, 1790, 1784, 1783, 1781, 1789, 1786, 1785, 1787, 1791, 1792, 1793);\n";
} // conditional
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "sltiu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// XORI ------------------------------------------------------------------------
static InstructionDefinition xori_rd_rs1_imm (
	ISA32_RV64IMACFD,
	"xori",
	(uint32_t) 0x004013,
	(uint32_t) 0x00707f,
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//XORI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 21);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1796);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 1802, 1799, 1797, 1800, 1801);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] ^ " + std::to_string((etiss_uint64)((((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))))) + "ULL;\n";
cp.code() += "etiss_coverage_count(12, 1819, 1807, 1806, 1804, 1818, 1812, 1811, 1809, 1817, 1814, 1813, 1815);\n";
} // conditional
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "xori" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// ORI -------------------------------------------------------------------------
static InstructionDefinition ori_rd_rs1_imm (
	ISA32_RV64IMACFD,
	"ori",
	(uint32_t) 0x006013,
	(uint32_t) 0x00707f,
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//ORI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 22);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1820);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 1826, 1823, 1821, 1824, 1825);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] | " + std::to_string((etiss_uint64)((((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))))) + "ULL;\n";
cp.code() += "etiss_coverage_count(12, 1843, 1831, 1830, 1828, 1842, 1836, 1835, 1833, 1841, 1838, 1837, 1839);\n";
} // conditional
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "ori" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// ANDI ------------------------------------------------------------------------
static InstructionDefinition andi_rd_rs1_imm (
	ISA32_RV64IMACFD,
	"andi",
	(uint32_t) 0x007013,
	(uint32_t) 0x00707f,
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//ANDI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 23);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1844);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 1850, 1847, 1845, 1848, 1849);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] & " + std::to_string((etiss_uint64)((((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))))) + "ULL;\n";
cp.code() += "etiss_coverage_count(12, 1867, 1855, 1854, 1852, 1866, 1860, 1859, 1857, 1865, 1862, 1861, 1863);\n";
} // conditional
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "andi" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SLLI ------------------------------------------------------------------------
static InstructionDefinition slli_rd_rs1_shamt (
	ISA32_RV64IMACFD,
	"slli",
	(uint32_t) 0x001013,
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
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(24, 20);
shamt += R_shamt_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SLLI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 24);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1868);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 1874, 1871, 1869, 1872, 1873);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] << " + std::to_string(shamt) + "ULL;\n";
cp.code() += "etiss_coverage_count(9, 1887, 1879, 1878, 1876, 1886, 1884, 1883, 1881, 1885);\n";
} // conditional
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
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(24, 20);
shamt += R_shamt_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "slli" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | shamt=" + std::to_string(shamt) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SRLI ------------------------------------------------------------------------
static InstructionDefinition srli_rd_rs1_shamt (
	ISA32_RV64IMACFD,
	"srli",
	(uint32_t) 0x005013,
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
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(24, 20);
shamt += R_shamt_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SRLI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 25);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1888);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 1894, 1891, 1889, 1892, 1893);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] >> " + std::to_string(shamt) + "ULL;\n";
cp.code() += "etiss_coverage_count(9, 1907, 1899, 1898, 1896, 1906, 1904, 1903, 1901, 1905);\n";
} // conditional
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
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(24, 20);
shamt += R_shamt_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "srli" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | shamt=" + std::to_string(shamt) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SRAI ------------------------------------------------------------------------
static InstructionDefinition srai_rd_rs1_shamt (
	ISA32_RV64IMACFD,
	"srai",
	(uint32_t) 0x40005013,
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
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(24, 20);
shamt += R_shamt_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SRAI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 26);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1908);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 1914, 1911, 1909, 1912, 1913);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) >> " + std::to_string(shamt) + "ULL;\n";
cp.code() += "etiss_coverage_count(10, 1929, 1919, 1918, 1916, 1928, 1926, 1924, 1923, 1921, 1927);\n";
} // conditional
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
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(24, 20);
shamt += R_shamt_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "srai" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | shamt=" + std::to_string(shamt) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// ADD -------------------------------------------------------------------------
static InstructionDefinition add_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"add",
	(uint32_t) 0x000033,
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

		cp.code() = std::string("//ADD\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 27);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1930);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 1936, 1933, 1931, 1934, 1935);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(11, 1953, 1941, 1940, 1938, 1952, 1946, 1945, 1943, 1951, 1950, 1948);\n";
} // conditional
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
ss << "add" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SUB -------------------------------------------------------------------------
static InstructionDefinition sub_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"sub",
	(uint32_t) 0x40000033,
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

		cp.code() = std::string("//SUB\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 28);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1954);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 1960, 1957, 1955, 1958, 1959);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] - *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(11, 1977, 1965, 1964, 1962, 1976, 1970, 1969, 1967, 1975, 1974, 1972);\n";
} // conditional
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
ss << "sub" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SLL -------------------------------------------------------------------------
static InstructionDefinition sll_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"sll",
	(uint32_t) 0x001033,
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

		cp.code() = std::string("//SLL\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 29);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1978);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 1984, 1981, 1979, 1982, 1983);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] << (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL] & 63ULL);\n";
cp.code() += "etiss_coverage_count(13, 2007, 1989, 1988, 1986, 2006, 1994, 1993, 1991, 2004, 1999, 1998, 1996, 2005);\n";
} // conditional
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
ss << "sll" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SLT -------------------------------------------------------------------------
static InstructionDefinition slt_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"slt",
	(uint32_t) 0x002033,
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

		cp.code() = std::string("//SLT\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 30);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 2008);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 2014, 2011, 2009, 2012, 2013);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = ((etiss_int64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) < (etiss_int64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])) ? (1ULL) : (0LL);\n";
cp.code() += "etiss_coverage_count(16, 2036, 2019, 2018, 2016, 2035, 2032, 2025, 2024, 2023, 2021, 2031, 2030, 2029, 2027, 2033, 2034);\n";
} // conditional
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
ss << "slt" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SLTU ------------------------------------------------------------------------
static InstructionDefinition sltu_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"sltu",
	(uint32_t) 0x003033,
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

		cp.code() = std::string("//SLTU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 31);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 2037);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 2043, 2040, 2038, 2041, 2042);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] < *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) ? (1ULL) : (0LL);\n";
cp.code() += "etiss_coverage_count(14, 2063, 2048, 2047, 2045, 2062, 2059, 2053, 2052, 2050, 2058, 2057, 2055, 2060, 2061);\n";
} // conditional
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
ss << "sltu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// XOR -------------------------------------------------------------------------
static InstructionDefinition xor_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"xor",
	(uint32_t) 0x004033,
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

		cp.code() = std::string("//XOR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 32);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 2064);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 2070, 2067, 2065, 2068, 2069);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] ^ *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(11, 2087, 2075, 2074, 2072, 2086, 2080, 2079, 2077, 2085, 2084, 2082);\n";
} // conditional
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
ss << "xor" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SRL -------------------------------------------------------------------------
static InstructionDefinition srl_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"srl",
	(uint32_t) 0x005033,
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

		cp.code() = std::string("//SRL\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 33);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 2088);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 2094, 2091, 2089, 2092, 2093);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] >> (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL] & 63ULL);\n";
cp.code() += "etiss_coverage_count(13, 2117, 2099, 2098, 2096, 2116, 2104, 2103, 2101, 2114, 2109, 2108, 2106, 2115);\n";
} // conditional
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
ss << "srl" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SRA -------------------------------------------------------------------------
static InstructionDefinition sra_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"sra",
	(uint32_t) 0x40005033,
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

		cp.code() = std::string("//SRA\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 34);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 2118);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 2124, 2121, 2119, 2122, 2123);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) >> (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL] & 63ULL);\n";
cp.code() += "etiss_coverage_count(14, 2148, 2129, 2128, 2126, 2147, 2135, 2134, 2133, 2131, 2145, 2140, 2139, 2137, 2146);\n";
} // conditional
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
ss << "sra" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// OR --------------------------------------------------------------------------
static InstructionDefinition or_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"or",
	(uint32_t) 0x006033,
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

		cp.code() = std::string("//OR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 35);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 2149);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 2155, 2152, 2150, 2153, 2154);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] | *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(11, 2172, 2160, 2159, 2157, 2171, 2165, 2164, 2162, 2170, 2169, 2167);\n";
} // conditional
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
ss << "or" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AND -------------------------------------------------------------------------
static InstructionDefinition and_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"and",
	(uint32_t) 0x007033,
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

		cp.code() = std::string("//AND\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 36);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 2173);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 2179, 2176, 2174, 2177, 2178);\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] & *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(11, 2196, 2184, 2183, 2181, 2195, 2189, 2188, 2186, 2194, 2193, 2191);\n";
} // conditional
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
ss << "and" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FENCE -----------------------------------------------------------------------
static InstructionDefinition fence_rd_rs1_succ_pred_fm (
	ISA32_RV64IMACFD,
	"fence",
	(uint32_t) 0x00000f,
	(uint32_t) 0x00707f,
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
etiss_uint8 succ = 0;
static BitArrayRange R_succ_0(23, 20);
succ += R_succ_0.read(ba) << 0;
etiss_uint8 pred = 0;
static BitArrayRange R_pred_0(27, 24);
pred += R_pred_0.read(ba) << 0;
etiss_uint8 fm = 0;
static BitArrayRange R_fm_0(31, 28);
fm += R_fm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FENCE\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 37);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "((RV64IMACFD*)cpu)->FENCE[0ULL] = " + std::to_string(pred << 4ULL | succ) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 2205, 2199, 2204, 2202, 2200, 2201, 2203);\n";
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
etiss_uint8 succ = 0;
static BitArrayRange R_succ_0(23, 20);
succ += R_succ_0.read(ba) << 0;
etiss_uint8 pred = 0;
static BitArrayRange R_pred_0(27, 24);
pred += R_pred_0.read(ba) << 0;
etiss_uint8 fm = 0;
static BitArrayRange R_fm_0(31, 28);
fm += R_fm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fence" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | succ=" + std::to_string(succ) + " | pred=" + std::to_string(pred) + " | fm=" + std::to_string(fm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
// clang-format on
