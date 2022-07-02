/**
 * Generated on Thu, 12 May 2022 16:30:21 +0200.
 *
 * This file contains the instruction behavior models of the RV32P
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

// MULR64 ----------------------------------------------------------------------
static InstructionDefinition mulr64_rd_rs1_rs2 (
	ISA32_RV32IMACFDPV,
	"mulr64",
	(uint32_t) 0xf0001077,
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

		partInit.code() = std::string("//MULR64\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 rs1_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "];\n";
partInit.code() += "etiss_uint32 rs2_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs2) + "];\n";
partInit.code() += "etiss_uint64 product = rs1_val * rs2_val;\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string((((rd) >> (1U)) & 15) * 2U + 1U) + "] = (((product) >> (32U)) & 4294967295);\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string((((rd) >> (1U)) & 15) * 2U) + "] = (((product) >> (0U)) & 4294967295);\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add(reg_name[(((rd) >> (1U)) & 15) * 2U], 32);
		partInit.getAffectedRegisters().add(reg_name[(((rd) >> (1U)) & 15) * 2U + 1U], 32);
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
ss << "mulr64" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// ADD64 -----------------------------------------------------------------------
static InstructionDefinition add64_rd_rs1_rs2 (
	ISA32_RV32IMACFDPV,
	"add64",
	(uint32_t) 0xc0001077,
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

		partInit.code() = std::string("//ADD64\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_int64 rs1_val = (((*((RV32IMACFDPV*)cpu)->X[" + std::to_string((((rs1) >> (1U)) & 15) * 2U + 1U) + "]) << 32) | (*((RV32IMACFDPV*)cpu)->X[" + std::to_string((((rs1) >> (1U)) & 15) * 2U) + "]));\n";
partInit.code() += "etiss_int64 rs2_val = (((*((RV32IMACFDPV*)cpu)->X[" + std::to_string((((rs2) >> (1U)) & 15) * 2U + 1U) + "]) << 32) | (*((RV32IMACFDPV*)cpu)->X[" + std::to_string((((rs2) >> (1U)) & 15) * 2U) + "]));\n";
partInit.code() += "etiss_int64 sum = rs1_val + rs2_val;\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string((((rd) >> (1U)) & 15) * 2U + 1U) + "] = (((sum) >> (32U)) & 4294967295);\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string((((rd) >> (1U)) & 15) * 2U) + "] = (((sum) >> (0U)) & 4294967295);\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[(((rs1) >> (1U)) & 15) * 2U], 32);
		partInit.getRegisterDependencies().add(reg_name[(((rs1) >> (1U)) & 15) * 2U + 1U], 32);
		partInit.getRegisterDependencies().add(reg_name[(((rs2) >> (1U)) & 15) * 2U], 32);
		partInit.getRegisterDependencies().add(reg_name[(((rs2) >> (1U)) & 15) * 2U + 1U], 32);
		partInit.getAffectedRegisters().add(reg_name[(((rd) >> (1U)) & 15) * 2U], 32);
		partInit.getAffectedRegisters().add(reg_name[(((rd) >> (1U)) & 15) * 2U + 1U], 32);
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
ss << "add64" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// MIN -------------------------------------------------------------------------
static InstructionDefinition min_rd_rs1_rs2 (
	ISA32_RV32IMACFDPV,
	"min",
	(uint32_t) 0xa004033,
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

		partInit.code() = std::string("//MIN\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
if (rd != 0U) {
partInit.code() += "etiss_int32 rs1_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "];\n";
partInit.code() += "etiss_int32 rs2_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs2) + "];\n";
partInit.code() += "etiss_int32 rd_val = (rs1_val < rs2_val) ? (rs1_val) : (rs2_val);\n";
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
ss << "min" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// MAX -------------------------------------------------------------------------
static InstructionDefinition max_rd_rs1_rs2 (
	ISA32_RV32IMACFDPV,
	"max",
	(uint32_t) 0xa006033,
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

		partInit.code() = std::string("//MAX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
if (rd != 0U) {
partInit.code() += "etiss_int32 rs1_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "];\n";
partInit.code() += "etiss_int32 rs2_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs2) + "];\n";
partInit.code() += "etiss_int32 rd_val = (rs1_val >= rs2_val) ? (rs1_val) : (rs2_val);\n";
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
ss << "max" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
