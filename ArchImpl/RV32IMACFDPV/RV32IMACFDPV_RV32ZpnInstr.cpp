/**
 * Generated on Mon, 04 Jul 2022 02:39:16 +0200.
 *
 * This file contains the instruction behavior models of the RV32Zpn
 * instruction set for the RV32IMACFDPV core architecture.
 */

#include "RV32IMACFDPVArch.h"

#define ETISS_ARCH_STATIC_FN_ONLY
#include "RV32IMACFDPVFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// ADD8 ------------------------------------------------------------------------
static InstructionDefinition add8_rd_rs1_rs2 (
	ISA32_RV32IMACFDPV,
	"add8",
	(uint32_t) 0x48000077,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//ADD8\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
if (rd != 0U) {
partInit.code() += "etiss_uint32 rs1_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "];\n";
partInit.code() += "etiss_uint32 rs2_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs2) + "];\n";
partInit.code() += "etiss_uint8 rd_val0 = (((rs1_val) >> (0U)) & 255) + (((rs2_val) >> (0U)) & 255);\n";
partInit.code() += "etiss_uint8 rd_val1 = (((rs1_val) >> (8U)) & 255) + (((rs2_val) >> (8U)) & 255);\n";
partInit.code() += "etiss_uint8 rd_val2 = (((rs1_val) >> (16U)) & 255) + (((rs2_val) >> (16U)) & 255);\n";
partInit.code() += "etiss_uint8 rd_val3 = (((rs1_val) >> (24U)) & 255) + (((rs2_val) >> (24U)) & 255);\n";
partInit.code() += "etiss_uint32 rd_val = (((((((((rd_val3) << 8) | (rd_val2))) << 8) | (rd_val1))) << 8) | (rd_val0));\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rd) + "] = rd_val;\n";
}
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add(reg_name[rd], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "add8" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// ADD16 -----------------------------------------------------------------------
static InstructionDefinition add16_rd_rs1_rs2 (
	ISA32_RV32IMACFDPV,
	"add16",
	(uint32_t) 0x40000077,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//ADD16\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
if (rd != 0U) {
partInit.code() += "etiss_uint32 rs1_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "];\n";
partInit.code() += "etiss_uint32 rs2_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs2) + "];\n";
partInit.code() += "etiss_uint16 rd_val0 = (((rs1_val) >> (0U)) & 65535) + (((rs2_val) >> (0U)) & 65535);\n";
partInit.code() += "etiss_uint16 rd_val1 = (((rs1_val) >> (16U)) & 65535) + (((rs2_val) >> (16U)) & 65535);\n";
partInit.code() += "etiss_uint32 rd_val = (((rd_val1) << 16) | (rd_val0));\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rd) + "] = rd_val;\n";
}
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add(reg_name[rd], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "add16" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// KMADA -----------------------------------------------------------------------
static InstructionDefinition kmada_rd_rs1_rs2 (
	ISA32_RV32IMACFDPV,
	"kmada",
	(uint32_t) 0x48001077,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//KMADA\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
if (rd != 0U) {
partInit.code() += "etiss_int32 rs1_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "];\n";
partInit.code() += "etiss_int32 rs2_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs2) + "];\n";
partInit.code() += "etiss_int32 rd_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rd) + "];\n";
partInit.code() += "etiss_int16 rs1_val_lo = (((rs1_val) >> (0U)) & 65535);\n";
partInit.code() += "etiss_int16 rs1_val_hi = (((rs1_val) >> (16U)) & 65535);\n";
partInit.code() += "etiss_int16 rs2_val_lo = (((rs2_val) >> (0U)) & 65535);\n";
partInit.code() += "etiss_int16 rs2_val_hi = (((rs2_val) >> (16U)) & 65535);\n";
partInit.code() += "etiss_int32 mula32 = rs1_val_hi * rs2_val_hi;\n";
partInit.code() += "etiss_int32 mulb32 = rs1_val_lo * rs2_val_lo;\n";
partInit.code() += "etiss_int64 res34 = ((etiss_int64)((rd_val & 0x3ffffffff)) + (etiss_int64)((mula32 & 0x3ffffffff)) + (etiss_int64)((mulb32 & 0x3ffffffff))) & 0x3ffffffff;\n";
partInit.code() += "if (res34 >= 4294967296UL) {\n";
partInit.code() += "res34 = (4294967295UL) & 0x3ffffffff;\n";
partInit.code() += "(((((RV32IMACFDPV*)cpu)->VXSAT_CSR__) >> (0U)) & 1) = (1U) & 0x1;\n";
partInit.code() += "}\n";partInit.code() += " else if (res34 < -4294967296UL) {\n";
partInit.code() += "res34 = (-4294967296UL) & 0x3ffffffff;\n";
partInit.code() += "(((((RV32IMACFDPV*)cpu)->VXSAT_CSR__) >> (0U)) & 1) = (1U) & 0x1;\n";
partInit.code() += "}\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rd) + "] = (((res34) >> (0U)) & 4294967295);\n";
}
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rd], 32);
		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add(reg_name[rd], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "kmada" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// KMAXDA ----------------------------------------------------------------------
static InstructionDefinition kmaxda_rd_rs1_rs2 (
	ISA32_RV32IMACFDPV,
	"kmaxda",
	(uint32_t) 0x4a001077,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//KMAXDA\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
if (rd != 0U) {
partInit.code() += "etiss_int32 rs1_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "];\n";
partInit.code() += "etiss_int32 rs2_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs2) + "];\n";
partInit.code() += "etiss_int32 rd_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rd) + "];\n";
partInit.code() += "etiss_int16 rs1_val_lo = (((rs1_val) >> (0U)) & 65535);\n";
partInit.code() += "etiss_int16 rs1_val_hi = (((rs1_val) >> (16U)) & 65535);\n";
partInit.code() += "etiss_int16 rs2_val_lo = (((rs2_val) >> (0U)) & 65535);\n";
partInit.code() += "etiss_int16 rs2_val_hi = (((rs2_val) >> (16U)) & 65535);\n";
partInit.code() += "etiss_int32 mula32 = rs1_val_hi * rs2_val_lo;\n";
partInit.code() += "etiss_int32 mulb32 = rs1_val_lo * rs2_val_hi;\n";
partInit.code() += "etiss_int64 res34 = ((etiss_int64)((rd_val & 0x3ffffffff)) + (etiss_int64)((mula32 & 0x3ffffffff)) + (etiss_int64)((mulb32 & 0x3ffffffff))) & 0x3ffffffff;\n";
partInit.code() += "if (res34 >= 4294967296UL) {\n";
partInit.code() += "res34 = (4294967295UL) & 0x3ffffffff;\n";
partInit.code() += "(((((RV32IMACFDPV*)cpu)->VXSAT_CSR__) >> (0U)) & 1) = (1U) & 0x1;\n";
partInit.code() += "}\n";partInit.code() += " else if (res34 < -4294967296UL) {\n";
partInit.code() += "res34 = (-4294967296UL) & 0x3ffffffff;\n";
partInit.code() += "(((((RV32IMACFDPV*)cpu)->VXSAT_CSR__) >> (0U)) & 1) = (1U) & 0x1;\n";
partInit.code() += "}\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rd) + "] = (((res34) >> (0U)) & 4294967295);\n";
}
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rd], 32);
		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add(reg_name[rd], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "kmaxda" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// MADDR32 ---------------------------------------------------------------------
static InstructionDefinition maddr32_rd_rs1_rs2 (
	ISA32_RV32IMACFDPV,
	"maddr32",
	(uint32_t) 0xc4001077,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//MADDR32\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
if (rd != 0U) {
partInit.code() += "etiss_int32 rs1_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "];\n";
partInit.code() += "etiss_int32 rs2_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs2) + "];\n";
partInit.code() += "etiss_int64 temp = rs1_val * rs2_val;\n";
partInit.code() += "etiss_int32 rd_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rd) + "] + (((temp) >> (0U)) & 4294967295);\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rd) + "] = rd_val;\n";
}
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rd], 32);
		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add(reg_name[rd], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "maddr32" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SCMPLE8 ---------------------------------------------------------------------
static InstructionDefinition scmple8_rd_rs1_rs2 (
	ISA32_RV32IMACFDPV,
	"scmple8",
	(uint32_t) 0x1e000077,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//SCMPLE8\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
if (rd != 0U) {
partInit.code() += "etiss_uint32 rs1_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "];\n";
partInit.code() += "etiss_uint32 rs2_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs2) + "];\n";
partInit.code() += "etiss_uint8 rd_val0 = ((((rs1_val) >> (0U)) & 255) <= (((rs2_val) >> (0U)) & 255)) ? (255U) : (0U);\n";
partInit.code() += "etiss_uint8 rd_val1 = ((((rs1_val) >> (8U)) & 255) <= (((rs2_val) >> (8U)) & 255)) ? (255U) : (0U);\n";
partInit.code() += "etiss_uint8 rd_val2 = ((((rs1_val) >> (16U)) & 255) <= (((rs2_val) >> (16U)) & 255)) ? (255U) : (0U);\n";
partInit.code() += "etiss_uint8 rd_val3 = ((((rs1_val) >> (24U)) & 255) <= (((rs2_val) >> (24U)) & 255)) ? (255U) : (0U);\n";
partInit.code() += "etiss_uint32 rd_val = (((((((((rd_val3) << 8) | (rd_val2))) << 8) | (rd_val1))) << 8) | (rd_val0));\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rd) + "] = rd_val;\n";
}
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add(reg_name[rd], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "scmple8" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SLL8 ------------------------------------------------------------------------
static InstructionDefinition sll8_rd_rs1_rs2 (
	ISA32_RV32IMACFDPV,
	"sll8",
	(uint32_t) 0x5c000077,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//SLL8\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
if (rd != 0U) {
partInit.code() += "etiss_uint32 rs1_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "];\n";
partInit.code() += "etiss_uint32 rs2_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs2) + "];\n";
partInit.code() += "etiss_uint8 rd_val0 = (((rs1_val) >> (0U)) & 255) << (((rs2_val) >> (0U)) & 7);\n";
partInit.code() += "etiss_uint8 rd_val1 = (((rs1_val) >> (8U)) & 255) << (((rs2_val) >> (8U)) & 7);\n";
partInit.code() += "etiss_uint8 rd_val2 = (((rs1_val) >> (16U)) & 255) << (((rs2_val) >> (16U)) & 7);\n";
partInit.code() += "etiss_uint8 rd_val3 = (((rs1_val) >> (24U)) & 255) << (((rs2_val) >> (24U)) & 7);\n";
partInit.code() += "etiss_uint32 rd_val = (((((((((rd_val3) << 8) | (rd_val2))) << 8) | (rd_val1))) << 8) | (rd_val0));\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rd) + "] = rd_val;\n";
}
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add(reg_name[rd], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "sll8" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SMAQA -----------------------------------------------------------------------
static InstructionDefinition smaqa_rd_rs1_rs2 (
	ISA32_RV32IMACFDPV,
	"smaqa",
	(uint32_t) 0xc8000077,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//SMAQA\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
if (rd != 0U) {
partInit.code() += "etiss_uint32 rs1_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "];\n";
partInit.code() += "etiss_uint32 rs2_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs2) + "];\n";
partInit.code() += "etiss_int32 rd_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rd) + "];\n";
partInit.code() += "etiss_int32 tmp_val0 = (etiss_int8)((((rs1_val) >> (0U)) & 255)) * (etiss_int8)((((rs2_val) >> (0U)) & 255)) + (etiss_int8)((((rd_val) >> (0U)) & 255));\n";
partInit.code() += "etiss_int32 tmp_val1 = (etiss_int8)((((rs1_val) >> (8U)) & 255)) * (etiss_int8)((((rs2_val) >> (8U)) & 255)) + (etiss_int8)((((rd_val) >> (8U)) & 255));\n";
partInit.code() += "etiss_int32 tmp_val2 = (etiss_int8)((((rs1_val) >> (16U)) & 255)) * (etiss_int8)((((rs2_val) >> (16U)) & 255)) + (etiss_int8)((((rd_val) >> (16U)) & 255));\n";
partInit.code() += "etiss_int32 tmp_val3 = (etiss_int8)((((rs1_val) >> (24U)) & 255)) * (etiss_int8)((((rs2_val) >> (24U)) & 255)) + (etiss_int8)((((rd_val) >> (24U)) & 255));\n";
partInit.code() += "rd_val = rd_val + tmp_val3 + tmp_val2 + tmp_val1 + tmp_val0;\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rd) + "] = rd_val;\n";
}
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rd], 32);
		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add(reg_name[rd], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "smaqa" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SMAX8 -----------------------------------------------------------------------
static InstructionDefinition smax8_rd_rs1_rs2 (
	ISA32_RV32IMACFDPV,
	"smax8",
	(uint32_t) 0x8a000077,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//SMAX8\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
if (rd != 0U) {
partInit.code() += "etiss_uint32 rs1_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "];\n";
partInit.code() += "etiss_uint32 rs2_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs2) + "];\n";
partInit.code() += "etiss_uint8 rd_val0 = ((((rs1_val) >> (0U)) & 255) > (((rs2_val) >> (0U)) & 255)) ? ((((rs1_val) >> (0U)) & 255)) : ((((rs2_val) >> (0U)) & 255));\n";
partInit.code() += "etiss_uint8 rd_val1 = ((((rs1_val) >> (8U)) & 255) > (((rs2_val) >> (8U)) & 255)) ? ((((rs1_val) >> (8U)) & 255)) : ((((rs2_val) >> (8U)) & 255));\n";
partInit.code() += "etiss_uint8 rd_val2 = ((((rs1_val) >> (16U)) & 255) > (((rs2_val) >> (16U)) & 255)) ? ((((rs1_val) >> (16U)) & 255)) : ((((rs2_val) >> (16U)) & 255));\n";
partInit.code() += "etiss_uint8 rd_val3 = ((((rs1_val) >> (24U)) & 255) > (((rs2_val) >> (24U)) & 255)) ? ((((rs1_val) >> (24U)) & 255)) : ((((rs2_val) >> (24U)) & 255));\n";
partInit.code() += "etiss_uint32 rd_val = (((((((((rd_val3) << 8) | (rd_val2))) << 8) | (rd_val1))) << 8) | (rd_val0));\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rd) + "] = rd_val;\n";
}
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add(reg_name[rd], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "smax8" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SMAX16 ----------------------------------------------------------------------
static InstructionDefinition smax16_rd_rs1_rs2 (
	ISA32_RV32IMACFDPV,
	"smax16",
	(uint32_t) 0x82000077,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//SMAX16\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
if (rd != 0U) {
partInit.code() += "etiss_uint32 rs1_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "];\n";
partInit.code() += "etiss_uint32 rs2_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs2) + "];\n";
partInit.code() += "etiss_uint16 rd_val0 = ((((rs1_val) >> (0U)) & 65535) > (((rs2_val) >> (0U)) & 65535)) ? ((((rs1_val) >> (0U)) & 255)) : ((((rs2_val) >> (0U)) & 65535));\n";
partInit.code() += "etiss_uint16 rd_val1 = ((((rs1_val) >> (16U)) & 65535) > (((rs2_val) >> (16U)) & 65535)) ? ((((rs1_val) >> (16U)) & 65535)) : ((((rs2_val) >> (16U)) & 65535));\n";
partInit.code() += "etiss_uint32 rd_val = (((rd_val1) << 16) | (rd_val0));\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rd) + "] = rd_val;\n";
}
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add(reg_name[rd], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "smax16" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SMIN8 -----------------------------------------------------------------------
static InstructionDefinition smin8_rd_rs1_rs2 (
	ISA32_RV32IMACFDPV,
	"smin8",
	(uint32_t) 0x88000077,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//SMIN8\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
if (rd != 0U) {
partInit.code() += "etiss_uint32 rs1_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "];\n";
partInit.code() += "etiss_uint32 rs2_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs2) + "];\n";
partInit.code() += "etiss_uint8 rd_val0 = ((((rs1_val) >> (0U)) & 255) < (((rs2_val) >> (0U)) & 255)) ? ((((rs1_val) >> (0U)) & 255)) : ((((rs2_val) >> (0U)) & 255));\n";
partInit.code() += "etiss_uint8 rd_val1 = ((((rs1_val) >> (8U)) & 255) < (((rs2_val) >> (8U)) & 255)) ? ((((rs1_val) >> (8U)) & 255)) : ((((rs2_val) >> (8U)) & 255));\n";
partInit.code() += "etiss_uint8 rd_val2 = ((((rs1_val) >> (16U)) & 255) < (((rs2_val) >> (16U)) & 255)) ? ((((rs1_val) >> (16U)) & 255)) : ((((rs2_val) >> (16U)) & 255));\n";
partInit.code() += "etiss_uint8 rd_val3 = ((((rs1_val) >> (24U)) & 255) < (((rs2_val) >> (24U)) & 255)) ? ((((rs1_val) >> (24U)) & 255)) : ((((rs2_val) >> (24U)) & 255));\n";
partInit.code() += "etiss_uint32 rd_val = (((((((((rd_val3) << 8) | (rd_val2))) << 8) | (rd_val1))) << 8) | (rd_val0));\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rd) + "] = rd_val;\n";
}
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add(reg_name[rd], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "smin8" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SUB8 ------------------------------------------------------------------------
static InstructionDefinition sub8_rd_rs1_rs2 (
	ISA32_RV32IMACFDPV,
	"sub8",
	(uint32_t) 0x4a000077,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//SUB8\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
if (rd != 0U) {
partInit.code() += "etiss_uint32 rs1_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "];\n";
partInit.code() += "etiss_uint32 rs2_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs2) + "];\n";
partInit.code() += "etiss_int8 rd_val0 = (etiss_int8)((((rs1_val) >> (0U)) & 255)) - (etiss_int8)((((rs2_val) >> (0U)) & 255));\n";
partInit.code() += "etiss_int8 rd_val1 = (etiss_int8)((((rs1_val) >> (8U)) & 255)) - (etiss_int8)((((rs2_val) >> (8U)) & 255));\n";
partInit.code() += "etiss_int8 rd_val2 = (etiss_int8)((((rs1_val) >> (16U)) & 255)) - (etiss_int8)((((rs2_val) >> (16U)) & 255));\n";
partInit.code() += "etiss_int8 rd_val3 = (etiss_int8)((((rs1_val) >> (24U)) & 255)) - (etiss_int8)((((rs2_val) >> (24U)) & 255));\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rd) + "] = (((((((((rd_val3) << 8) | (rd_val2))) << 8) | (rd_val1))) << 8) | (rd_val0));\n";
}
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add(reg_name[rd], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "sub8" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SUNPKD8 ---------------------------------------------------------------------
static InstructionDefinition sunpkd8_rd_rs1_code (
	ISA32_RV32IMACFDPV,
	"sunpkd8",
	(uint32_t) 0xac000077,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 code = 0;
static BitArrayRange R_code_0(24, 20);
code += R_code_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//SUNPKD8\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
if (rd != 0U) {
partInit.code() += "etiss_uint32 rs1_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "];\n";
if (code & 8U) {
partInit.code() += "etiss_int8 rs1_val_hi = (((rs1_val) >> (8U)) & 255);\n";
partInit.code() += "etiss_int8 rs1_val_lo = (((rs1_val) >> (0U)) & 255);\n";
} else if (code & 9U) {
partInit.code() += "etiss_int8 rs1_val_hi = (((rs1_val) >> (16U)) & 255);\n";
partInit.code() += "etiss_int8 rs1_val_lo = (((rs1_val) >> (0U)) & 255);\n";
} else if (code & 10U) {
partInit.code() += "etiss_int8 rs1_val_hi = (((rs1_val) >> (24U)) & 255);\n";
partInit.code() += "etiss_int8 rs1_val_lo = (((rs1_val) >> (0U)) & 255);\n";
} else if (code & 11U) {
partInit.code() += "etiss_int8 rs1_val_hi = (((rs1_val) >> (24U)) & 255);\n";
partInit.code() += "etiss_int8 rs1_val_lo = (((rs1_val) >> (8U)) & 255);\n";
} else if (code & 19U) {
partInit.code() += "etiss_int8 rs1_val_hi = (((rs1_val) >> (24U)) & 255);\n";
partInit.code() += "etiss_int8 rs1_val_lo = (((rs1_val) >> (16U)) & 255);\n";
} else {
partInit.code() += "((RV32IMACFDPV*)cpu)->exception = raise(cpu, system, plugin_pointers, 0U, 2U);\n";
}
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rd) + "] = ((((etiss_int16)(rs1_val_hi)) << 16) | ((etiss_int16)(rs1_val_lo)));\n";
}
partInit.code() += "if (((RV32IMACFDPV*)cpu)->exception) return ((RV32IMACFDPV*)cpu)->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getAffectedRegisters().add(reg_name[rd], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 code = 0;
static BitArrayRange R_code_0(24, 20);
code += R_code_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "sunpkd8" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | code=" + std::to_string(code) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
