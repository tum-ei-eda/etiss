/**
 * Generated on Wed, 13 Mar 2024 21:23:08 +0100.
 *
 * This file contains the instruction behavior models of the RV32I
 * instruction set for the RV32IMACFD core architecture.
 */

#include "RV32IMACFDArch.h"
#include "RV32IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// LUI -------------------------------------------------------------------------
static InstructionDefinition lui_rd_imm (
	ISA32_RV32IMACFD,
	"lui",
	(uint32_t) 0x000037,
	(uint32_t) 0x00007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 imm = 0;
static BitArrayRange R_imm_12(31, 12);
imm += R_imm_12.read(ba) << 12;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//LUI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 0);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1175);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 1172, 1170, 1173, 1174, 1187);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = " + std::to_string((etiss_uint32)(((etiss_int32)(imm)))) + "ULL;\n";
cp.code() += "etiss_coverage_count(8, 1186, 1180, 1179, 1177, 1185, 1182, 1181, 1183);\n";
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
	ISA32_RV32IMACFD,
	"auipc",
	(uint32_t) 0x000017,
	(uint32_t) 0x00007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 imm = 0;
static BitArrayRange R_imm_12(31, 12);
imm += R_imm_12.read(ba) << 12;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AUIPC\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 1);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1193);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 1190, 1188, 1191, 1192, 1204);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = " + std::to_string(ic.current_address_ + (etiss_int32)(imm)) + "LL;\n";
cp.code() += "etiss_coverage_count(8, 1203, 1198, 1197, 1195, 1202, 1199, 1201, 1200);\n";
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
	ISA32_RV32IMACFD,
	"jal",
	(uint32_t) 0x00006f,
	(uint32_t) 0x00007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//JAL\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 2);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1236);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1207);\n";
if (imm % 2ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 1205, 1235);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1211);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_raise(cpu, system, plugin_pointers, 0ULL, 0LL);\n";
cp.code() += "etiss_coverage_count(2, 1210, 1208);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
} // conditional
else { // conditional
{ // block
cp.code() += "etiss_coverage_count(1, 1234);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1217);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 1214, 1212, 1215, 1216, 1227);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1226, 1222, 1221, 1219, 1225, 1223, 1224);\n";
} // conditional
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + ((etiss_int32)(((etiss_int32)imm) << (11)) >> (11))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 1233, 1228, 1232, 1229, 1231, 1230);\n";
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
	ISA32_RV32IMACFD,
	"jalr",
	(uint32_t) 0x000067,
	(uint32_t) 0x00707f,
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//JALR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 3);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1282);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 new_pc = (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL) & -2LL;\n";
cp.code() += "etiss_coverage_count(9, 1250, 1249, 1245, 1242, 1241, 1239, 1244, 1243, 1246);\n";
cp.code() += "etiss_coverage_count(1, 1253);\n";
cp.code() += "if (new_pc % 2ULL) { // conditional\n";
cp.code() += "etiss_coverage_count(2, 1251, 1281);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1257);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_raise(cpu, system, plugin_pointers, 0ULL, 0LL);\n";
cp.code() += "etiss_coverage_count(2, 1256, 1254);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1280);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1263);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 1260, 1258, 1261, 1262, 1273);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1272, 1268, 1267, 1265, 1271, 1269, 1270);\n";
} // conditional
cp.code() += "cpu->nextPc = new_pc & -2LL;\n";
cp.code() += "etiss_coverage_count(4, 1279, 1274, 1278, 1275);\n";
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
	ISA32_RV32IMACFD,
	"beq",
	(uint32_t) 0x000063,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//BEQ\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 4);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1311);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1293);\n";
cp.code() += "if (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] == *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) { // conditional\n";
cp.code() += "etiss_coverage_count(7, 1287, 1286, 1284, 1292, 1291, 1289, 1310);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1309);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1296);\n";
if (imm % 2ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 1294, 1308);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1300);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_raise(cpu, system, plugin_pointers, 0ULL, 0LL);\n";
cp.code() += "etiss_coverage_count(2, 1299, 1297);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
} // conditional
else { // conditional
{ // block
cp.code() += "etiss_coverage_count(1, 1307);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + ((etiss_int16)(((etiss_int16)imm) << (3)) >> (3))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 1306, 1301, 1305, 1302, 1304, 1303);\n";
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
cp.code() += "if (cpu->return_pending | cpu->exception | cpu->nextPc != " + std::to_string(ic.current_address_ + 4) + "ULL) return cpu->exception;\n";
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
	ISA32_RV32IMACFD,
	"bne",
	(uint32_t) 0x001063,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//BNE\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 5);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1340);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1322);\n";
cp.code() += "if (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] != *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) { // conditional\n";
cp.code() += "etiss_coverage_count(7, 1316, 1315, 1313, 1321, 1320, 1318, 1339);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1338);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1325);\n";
if (imm % 2ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 1323, 1337);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1329);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_raise(cpu, system, plugin_pointers, 0ULL, 0LL);\n";
cp.code() += "etiss_coverage_count(2, 1328, 1326);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
} // conditional
else { // conditional
{ // block
cp.code() += "etiss_coverage_count(1, 1336);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + ((etiss_int16)(((etiss_int16)imm) << (3)) >> (3))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 1335, 1330, 1334, 1331, 1333, 1332);\n";
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
cp.code() += "if (cpu->return_pending | cpu->exception | cpu->nextPc != " + std::to_string(ic.current_address_ + 4) + "ULL) return cpu->exception;\n";
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
	ISA32_RV32IMACFD,
	"blt",
	(uint32_t) 0x004063,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//BLT\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 6);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1373);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1355);\n";
cp.code() += "if ((etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) < (etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])) { // conditional\n";
cp.code() += "etiss_coverage_count(9, 1347, 1345, 1344, 1342, 1354, 1352, 1351, 1349, 1372);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1371);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1358);\n";
if (imm % 2ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 1356, 1370);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1362);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_raise(cpu, system, plugin_pointers, 0ULL, 0LL);\n";
cp.code() += "etiss_coverage_count(2, 1361, 1359);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
} // conditional
else { // conditional
{ // block
cp.code() += "etiss_coverage_count(1, 1369);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + ((etiss_int16)(((etiss_int16)imm) << (3)) >> (3))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 1368, 1363, 1367, 1364, 1366, 1365);\n";
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
cp.code() += "if (cpu->return_pending | cpu->exception | cpu->nextPc != " + std::to_string(ic.current_address_ + 4) + "ULL) return cpu->exception;\n";
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
	ISA32_RV32IMACFD,
	"bge",
	(uint32_t) 0x005063,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//BGE\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 7);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1406);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1388);\n";
cp.code() += "if ((etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) >= (etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])) { // conditional\n";
cp.code() += "etiss_coverage_count(9, 1380, 1378, 1377, 1375, 1387, 1385, 1384, 1382, 1405);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1404);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1391);\n";
if (imm % 2ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 1389, 1403);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1395);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_raise(cpu, system, plugin_pointers, 0ULL, 0LL);\n";
cp.code() += "etiss_coverage_count(2, 1394, 1392);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
} // conditional
else { // conditional
{ // block
cp.code() += "etiss_coverage_count(1, 1402);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + ((etiss_int16)(((etiss_int16)imm) << (3)) >> (3))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 1401, 1396, 1400, 1397, 1399, 1398);\n";
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
cp.code() += "if (cpu->return_pending | cpu->exception | cpu->nextPc != " + std::to_string(ic.current_address_ + 4) + "ULL) return cpu->exception;\n";
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
	ISA32_RV32IMACFD,
	"bltu",
	(uint32_t) 0x006063,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//BLTU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 8);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1435);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1417);\n";
cp.code() += "if (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] < *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) { // conditional\n";
cp.code() += "etiss_coverage_count(7, 1411, 1410, 1408, 1416, 1415, 1413, 1434);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1433);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1420);\n";
if (imm % 2ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 1418, 1432);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1424);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_raise(cpu, system, plugin_pointers, 0ULL, 0LL);\n";
cp.code() += "etiss_coverage_count(2, 1423, 1421);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
} // conditional
else { // conditional
{ // block
cp.code() += "etiss_coverage_count(1, 1431);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + ((etiss_int16)(((etiss_int16)imm) << (3)) >> (3))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 1430, 1425, 1429, 1426, 1428, 1427);\n";
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
cp.code() += "if (cpu->return_pending | cpu->exception | cpu->nextPc != " + std::to_string(ic.current_address_ + 4) + "ULL) return cpu->exception;\n";
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
	ISA32_RV32IMACFD,
	"bgeu",
	(uint32_t) 0x007063,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//BGEU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 9);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1464);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1446);\n";
cp.code() += "if (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] >= *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) { // conditional\n";
cp.code() += "etiss_coverage_count(7, 1440, 1439, 1437, 1445, 1444, 1442, 1463);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1462);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 1449);\n";
if (imm % 2ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 1447, 1461);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1453);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_raise(cpu, system, plugin_pointers, 0ULL, 0LL);\n";
cp.code() += "etiss_coverage_count(2, 1452, 1450);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
} // conditional
else { // conditional
{ // block
cp.code() += "etiss_coverage_count(1, 1460);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + ((etiss_int16)(((etiss_int16)imm) << (3)) >> (3))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 1459, 1454, 1458, 1455, 1457, 1456);\n";
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
cp.code() += "if (cpu->return_pending | cpu->exception | cpu->nextPc != " + std::to_string(ic.current_address_ + 4) + "ULL) return cpu->exception;\n";
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
	ISA32_RV32IMACFD,
	"lb",
	(uint32_t) 0x000003,
	(uint32_t) 0x00707f,
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//LB\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 10);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1498);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 load_address = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(7, 1474, 1473, 1470, 1469, 1467, 1472, 1471);\n";
cp.code() += "etiss_uint8 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 1);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int8 res = (etiss_int8)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(4, 1481, 1480, 1478, 1477);\n";
cp.code() += "etiss_coverage_count(1, 1487);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 1484, 1482, 1485, 1486, 1497);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint32)(res);\n";
cp.code() += "etiss_coverage_count(6, 1496, 1492, 1491, 1489, 1495, 1493);\n";
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
cp.code() += "if (cpu->return_pending | cpu->exception) return cpu->exception;\n";
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
	ISA32_RV32IMACFD,
	"lh",
	(uint32_t) 0x001003,
	(uint32_t) 0x00707f,
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//LH\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 11);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1532);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 load_address = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(7, 1508, 1507, 1504, 1503, 1501, 1506, 1505);\n";
cp.code() += "etiss_uint16 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 2);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int16 res = (etiss_int16)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(4, 1515, 1514, 1512, 1511);\n";
cp.code() += "etiss_coverage_count(1, 1521);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 1518, 1516, 1519, 1520, 1531);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint32)(res);\n";
cp.code() += "etiss_coverage_count(6, 1530, 1526, 1525, 1523, 1529, 1527);\n";
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
cp.code() += "if (cpu->return_pending | cpu->exception) return cpu->exception;\n";
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
	ISA32_RV32IMACFD,
	"lw",
	(uint32_t) 0x002003,
	(uint32_t) 0x00707f,
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//LW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 12);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1566);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 load_address = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(7, 1542, 1541, 1538, 1537, 1535, 1540, 1539);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int32 res = (etiss_int32)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(4, 1549, 1548, 1546, 1545);\n";
cp.code() += "etiss_coverage_count(1, 1555);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 1552, 1550, 1553, 1554, 1565);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint32)(res);\n";
cp.code() += "etiss_coverage_count(6, 1564, 1560, 1559, 1557, 1563, 1561);\n";
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
cp.code() += "if (cpu->return_pending | cpu->exception) return cpu->exception;\n";
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
	ISA32_RV32IMACFD,
	"lbu",
	(uint32_t) 0x004003,
	(uint32_t) 0x00707f,
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//LBU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 13);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1600);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 load_address = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(7, 1576, 1575, 1572, 1571, 1569, 1574, 1573);\n";
cp.code() += "etiss_uint8 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 1);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint8 res = (etiss_uint8)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(4, 1583, 1582, 1580, 1579);\n";
cp.code() += "etiss_coverage_count(1, 1589);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 1586, 1584, 1587, 1588, 1599);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint32)(res);\n";
cp.code() += "etiss_coverage_count(6, 1598, 1594, 1593, 1591, 1597, 1595);\n";
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
cp.code() += "if (cpu->return_pending | cpu->exception) return cpu->exception;\n";
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
	ISA32_RV32IMACFD,
	"lhu",
	(uint32_t) 0x005003,
	(uint32_t) 0x00707f,
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//LHU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 14);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1634);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 load_address = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(7, 1610, 1609, 1606, 1605, 1603, 1608, 1607);\n";
cp.code() += "etiss_uint16 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 2);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint16 res = (etiss_uint16)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(4, 1617, 1616, 1614, 1613);\n";
cp.code() += "etiss_coverage_count(1, 1623);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 1620, 1618, 1621, 1622, 1633);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint32)(res);\n";
cp.code() += "etiss_coverage_count(6, 1632, 1628, 1627, 1625, 1631, 1629);\n";
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
cp.code() += "if (cpu->return_pending | cpu->exception) return cpu->exception;\n";
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
	ISA32_RV32IMACFD,
	"sb",
	(uint32_t) 0x000023,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SB\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 15);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1656);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 store_address = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(7, 1644, 1643, 1640, 1639, 1637, 1642, 1641);\n";
cp.code() += "etiss_uint8 mem_val_0;\n";
cp.code() += "mem_val_0 = (etiss_int8)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(7, 1655, 1647, 1646, 1654, 1652, 1651, 1649);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, store_address, (etiss_uint8*)&mem_val_0, 1);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
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
cp.code() += "if (cpu->return_pending | cpu->exception) return cpu->exception;\n";
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
	ISA32_RV32IMACFD,
	"sh",
	(uint32_t) 0x001023,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SH\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 16);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1678);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 store_address = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(7, 1666, 1665, 1662, 1661, 1659, 1664, 1663);\n";
cp.code() += "etiss_uint16 mem_val_0;\n";
cp.code() += "mem_val_0 = (etiss_int16)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(7, 1677, 1669, 1668, 1676, 1674, 1673, 1671);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, store_address, (etiss_uint8*)&mem_val_0, 2);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
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
cp.code() += "if (cpu->return_pending | cpu->exception) return cpu->exception;\n";
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
	ISA32_RV32IMACFD,
	"sw",
	(uint32_t) 0x002023,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 17);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 1700);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 store_address = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(7, 1688, 1687, 1684, 1683, 1681, 1686, 1685);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "mem_val_0 = (etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(7, 1699, 1691, 1690, 1698, 1696, 1695, 1693);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, store_address, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
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
cp.code() += "if (cpu->return_pending | cpu->exception) return cpu->exception;\n";
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
	ISA32_RV32IMACFD,
	"addi",
	(uint32_t) 0x000013,
	(uint32_t) 0x00707f,
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//ADDI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 18);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1706);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 1703, 1701, 1704, 1705, 1721);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(10, 1720, 1711, 1710, 1708, 1719, 1716, 1715, 1713, 1718, 1717);\n";
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
	ISA32_RV32IMACFD,
	"slti",
	(uint32_t) 0x002013,
	(uint32_t) 0x00707f,
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SLTI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 19);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1727);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 1724, 1722, 1725, 1726, 1747);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (((etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) < " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL)) ? (1ULL) : (0ULL);\n";
cp.code() += "etiss_coverage_count(15, 1746, 1732, 1731, 1729, 1745, 1741, 1738, 1737, 1736, 1734, 1740, 1739, 1742, 1743, 1744);\n";
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
	ISA32_RV32IMACFD,
	"sltiu",
	(uint32_t) 0x003013,
	(uint32_t) 0x00707f,
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SLTIU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 20);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1753);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 1750, 1748, 1751, 1752, 1775);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = ((*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] < " + std::to_string((etiss_uint32)((((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))))) + "ULL)) ? (1ULL) : (0ULL);\n";
cp.code() += "etiss_coverage_count(16, 1774, 1758, 1757, 1755, 1773, 1769, 1763, 1762, 1760, 1768, 1765, 1764, 1766, 1770, 1771, 1772);\n";
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
	ISA32_RV32IMACFD,
	"xori",
	(uint32_t) 0x004013,
	(uint32_t) 0x00707f,
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//XORI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 21);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1781);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 1778, 1776, 1779, 1780, 1799);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] ^ " + std::to_string((etiss_uint32)((((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))))) + "ULL;\n";
cp.code() += "etiss_coverage_count(12, 1798, 1786, 1785, 1783, 1797, 1791, 1790, 1788, 1796, 1793, 1792, 1794);\n";
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
	ISA32_RV32IMACFD,
	"ori",
	(uint32_t) 0x006013,
	(uint32_t) 0x00707f,
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//ORI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 22);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1805);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 1802, 1800, 1803, 1804, 1823);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] | " + std::to_string((etiss_uint32)((((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))))) + "ULL;\n";
cp.code() += "etiss_coverage_count(12, 1822, 1810, 1809, 1807, 1821, 1815, 1814, 1812, 1820, 1817, 1816, 1818);\n";
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
	ISA32_RV32IMACFD,
	"andi",
	(uint32_t) 0x007013,
	(uint32_t) 0x00707f,
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
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//ANDI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 23);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1829);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 1826, 1824, 1827, 1828, 1847);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] & " + std::to_string((etiss_uint32)((((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))))) + "ULL;\n";
cp.code() += "etiss_coverage_count(12, 1846, 1834, 1833, 1831, 1845, 1839, 1838, 1836, 1844, 1841, 1840, 1842);\n";
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
	ISA32_RV32IMACFD,
	"slli",
	(uint32_t) 0x001013,
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
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(24, 20);
shamt += R_shamt_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SLLI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 24);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1853);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 1850, 1848, 1851, 1852, 1867);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] << " + std::to_string(shamt) + "ULL;\n";
cp.code() += "etiss_coverage_count(9, 1866, 1858, 1857, 1855, 1865, 1863, 1862, 1860, 1864);\n";
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
	ISA32_RV32IMACFD,
	"srli",
	(uint32_t) 0x005013,
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
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(24, 20);
shamt += R_shamt_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SRLI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 25);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1873);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 1870, 1868, 1871, 1872, 1887);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] >> " + std::to_string(shamt) + "ULL;\n";
cp.code() += "etiss_coverage_count(9, 1886, 1878, 1877, 1875, 1885, 1883, 1882, 1880, 1884);\n";
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
	ISA32_RV32IMACFD,
	"srai",
	(uint32_t) 0x40005013,
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
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(24, 20);
shamt += R_shamt_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SRAI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 26);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1893);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 1890, 1888, 1891, 1892, 1909);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) >> " + std::to_string(shamt) + "ULL;\n";
cp.code() += "etiss_coverage_count(10, 1908, 1898, 1897, 1895, 1907, 1905, 1903, 1902, 1900, 1906);\n";
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
	ISA32_RV32IMACFD,
	"add",
	(uint32_t) 0x000033,
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

		cp.code() = std::string("//ADD\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 27);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1915);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 1912, 1910, 1913, 1914, 1933);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(11, 1932, 1920, 1919, 1917, 1931, 1925, 1924, 1922, 1930, 1929, 1927);\n";
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
	ISA32_RV32IMACFD,
	"sub",
	(uint32_t) 0x40000033,
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

		cp.code() = std::string("//SUB\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 28);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1939);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 1936, 1934, 1937, 1938, 1957);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] - *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(11, 1956, 1944, 1943, 1941, 1955, 1949, 1948, 1946, 1954, 1953, 1951);\n";
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
	ISA32_RV32IMACFD,
	"sll",
	(uint32_t) 0x001033,
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

		cp.code() = std::string("//SLL\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 29);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1963);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 1960, 1958, 1961, 1962, 1987);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] << (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL] & 31ULL);\n";
cp.code() += "etiss_coverage_count(13, 1986, 1968, 1967, 1965, 1985, 1973, 1972, 1970, 1983, 1978, 1977, 1975, 1984);\n";
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
	ISA32_RV32IMACFD,
	"slt",
	(uint32_t) 0x002033,
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

		cp.code() = std::string("//SLT\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 30);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 1993);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 1990, 1988, 1991, 1992, 2016);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = ((etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) < (etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])) ? (1ULL) : (0ULL);\n";
cp.code() += "etiss_coverage_count(16, 2015, 1998, 1997, 1995, 2014, 2011, 2004, 2003, 2002, 2000, 2010, 2009, 2008, 2006, 2012, 2013);\n";
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
	ISA32_RV32IMACFD,
	"sltu",
	(uint32_t) 0x003033,
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

		cp.code() = std::string("//SLTU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 31);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 2022);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 2019, 2017, 2020, 2021, 2043);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] < *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) ? (1ULL) : (0ULL);\n";
cp.code() += "etiss_coverage_count(14, 2042, 2027, 2026, 2024, 2041, 2038, 2032, 2031, 2029, 2037, 2036, 2034, 2039, 2040);\n";
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
	ISA32_RV32IMACFD,
	"xor",
	(uint32_t) 0x004033,
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

		cp.code() = std::string("//XOR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 32);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 2049);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 2046, 2044, 2047, 2048, 2067);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] ^ *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(11, 2066, 2054, 2053, 2051, 2065, 2059, 2058, 2056, 2064, 2063, 2061);\n";
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
	ISA32_RV32IMACFD,
	"srl",
	(uint32_t) 0x005033,
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

		cp.code() = std::string("//SRL\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 33);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 2073);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 2070, 2068, 2071, 2072, 2097);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] >> (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL] & 31ULL);\n";
cp.code() += "etiss_coverage_count(13, 2096, 2078, 2077, 2075, 2095, 2083, 2082, 2080, 2093, 2088, 2087, 2085, 2094);\n";
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
	ISA32_RV32IMACFD,
	"sra",
	(uint32_t) 0x40005033,
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

		cp.code() = std::string("//SRA\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 34);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 2103);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 2100, 2098, 2101, 2102, 2128);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) >> (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL] & 31ULL);\n";
cp.code() += "etiss_coverage_count(14, 2127, 2108, 2107, 2105, 2126, 2114, 2113, 2112, 2110, 2124, 2119, 2118, 2116, 2125);\n";
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
	ISA32_RV32IMACFD,
	"or",
	(uint32_t) 0x006033,
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

		cp.code() = std::string("//OR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 35);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 2134);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 2131, 2129, 2132, 2133, 2152);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] | *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(11, 2151, 2139, 2138, 2136, 2150, 2144, 2143, 2141, 2149, 2148, 2146);\n";
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
	ISA32_RV32IMACFD,
	"and",
	(uint32_t) 0x007033,
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

		cp.code() = std::string("//AND\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 36);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 2158);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(5, 2155, 2153, 2156, 2157, 2176);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] & *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(11, 2175, 2163, 2162, 2160, 2174, 2168, 2167, 2165, 2173, 2172, 2170);\n";
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
	ISA32_RV32IMACFD,
	"fence",
	(uint32_t) 0x00000f,
	(uint32_t) 0x00707f,
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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FENCE\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 37);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1169);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1168, 1164, 1167, 1165, 1166);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "((RV32IMACFD*)cpu)->FENCE[0ULL] = " + std::to_string(pred << 4ULL | succ) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 2185, 2179, 2184, 2182, 2180, 2181, 2183);\n";
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
