/**
 * Generated on Tue, 15 Feb 2022 21:11:54 +0100.
 *
 * This file contains the instruction behavior models of the RV32I
 * instruction set for the RV32IMCFD core architecture.
 */

#include "RV32IMCFDArch.h"

#define ETISS_ARCH_STATIC_FN_ONLY
#include "RV32IMCFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// LUI -------------------------------------------------------------------------
static InstructionDefinition lui_rd_imm (
	ISA32_RV32IMCFD,
	"lui",
	(uint32_t) 0x000037,
	(uint32_t) 0x00007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 imm = 0;
static BitArrayRange R_imm_12(31, 12);
imm += R_imm_12.read(ba) << 12;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//LUI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = " + std::to_string((etiss_int32)(imm)) + ";\n";
}
// -----------------------------------------------------------------------------

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
	ISA32_RV32IMCFD,
	"auipc",
	(uint32_t) 0x000017,
	(uint32_t) 0x00007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 imm = 0;
static BitArrayRange R_imm_12(31, 12);
imm += R_imm_12.read(ba) << 12;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//AUIPC\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = " + std::to_string(ic.current_address_ + (etiss_int32)(imm)) + ";\n";
}
// -----------------------------------------------------------------------------

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
	ISA32_RV32IMCFD,
	"jal",
	(uint32_t) 0x00006f,
	(uint32_t) 0x00007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//JAL\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (imm % 2) {
partInit.code() += "exception = ETISS_RETURNCODE_IBUS_READ_ERROR;\n";
} else {
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = " + std::to_string(ic.current_address_ + 4) + ";\n";
}
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + ((etiss_int32)((imm) << (11)) >> (11))) + ";\n";
}
partInit.code() += "return exception;\n";
// -----------------------------------------------------------------------------

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
	ISA32_RV32IMCFD,
	"jalr",
	(uint32_t) 0x000067,
	(uint32_t) 0x00707f,
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
etiss_uint32 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//JALR\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
partInit.code() += "etiss_uint32 new_pc = (*((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] + " + std::to_string(((etiss_int16)((imm) << (4)) >> (4))) + ") & " + std::to_string(~(1)) + ";\n";
partInit.code() += "if (new_pc % " + std::to_string(2) + ") {\n";
partInit.code() += "exception = ETISS_RETURNCODE_IBUS_READ_ERROR;\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = " + std::to_string(ic.current_address_ + 4) + ";\n";
}
partInit.code() += "cpu->instructionPointer = new_pc & " + std::to_string(~(1)) + ";\n";
partInit.code() += "}\n";
partInit.code() += "return exception;\n";
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
etiss_uint32 imm = 0;
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
	ISA32_RV32IMCFD,
	"beq",
	(uint32_t) 0x000063,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(30, 25);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_12(31, 31);
imm += R_imm_12.read(ba) << 12;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//BEQ\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
partInit.code() += "if (*((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] == *((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "]) {\n";
if (imm % 2) {
partInit.code() += "exception = ETISS_RETURNCODE_IBUS_READ_ERROR;\n";
} else {
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + ((etiss_int16)((imm) << (3)) >> (3))) + ";\n";
}
partInit.code() += "}\n";
partInit.code() += "return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
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
	ISA32_RV32IMCFD,
	"bne",
	(uint32_t) 0x001063,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(30, 25);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_12(31, 31);
imm += R_imm_12.read(ba) << 12;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//BNE\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
partInit.code() += "if (*((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] != *((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "]) {\n";
if (imm % 2) {
partInit.code() += "exception = ETISS_RETURNCODE_IBUS_READ_ERROR;\n";
} else {
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + ((etiss_int16)((imm) << (3)) >> (3))) + ";\n";
}
partInit.code() += "}\n";
partInit.code() += "return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
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
	ISA32_RV32IMCFD,
	"blt",
	(uint32_t) 0x004063,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(30, 25);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_12(31, 31);
imm += R_imm_12.read(ba) << 12;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//BLT\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
partInit.code() += "if ((etiss_int32)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "]) < (etiss_int32)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "])) {\n";
if (imm % 2) {
partInit.code() += "exception = ETISS_RETURNCODE_IBUS_READ_ERROR;\n";
} else {
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + ((etiss_int16)((imm) << (3)) >> (3))) + ";\n";
}
partInit.code() += "}\n";
partInit.code() += "return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
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
	ISA32_RV32IMCFD,
	"bge",
	(uint32_t) 0x005063,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(30, 25);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_12(31, 31);
imm += R_imm_12.read(ba) << 12;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//BGE\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
partInit.code() += "if ((etiss_int32)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "]) >= (etiss_int32)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "])) {\n";
if (imm % 2) {
partInit.code() += "exception = ETISS_RETURNCODE_IBUS_READ_ERROR;\n";
} else {
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + ((etiss_int16)((imm) << (3)) >> (3))) + ";\n";
}
partInit.code() += "}\n";
partInit.code() += "return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
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
	ISA32_RV32IMCFD,
	"bltu",
	(uint32_t) 0x006063,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(30, 25);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_12(31, 31);
imm += R_imm_12.read(ba) << 12;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//BLTU\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
partInit.code() += "if (*((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] < *((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "]) {\n";
if (imm % 2) {
partInit.code() += "exception = ETISS_RETURNCODE_IBUS_READ_ERROR;\n";
} else {
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + ((etiss_int16)((imm) << (3)) >> (3))) + ";\n";
}
partInit.code() += "}\n";
partInit.code() += "return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
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
	ISA32_RV32IMCFD,
	"bgeu",
	(uint32_t) 0x007063,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(30, 25);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_12(31, 31);
imm += R_imm_12.read(ba) << 12;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//BGEU\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
partInit.code() += "if (*((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] >= *((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "]) {\n";
if (imm % 2) {
partInit.code() += "exception = ETISS_RETURNCODE_IBUS_READ_ERROR;\n";
} else {
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + ((etiss_int16)((imm) << (3)) >> (3))) + ";\n";
}
partInit.code() += "}\n";
partInit.code() += "return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_11(7, 7);
imm += R_imm_11.read(ba) << 11;
static BitArrayRange R_imm_1(11, 8);
imm += R_imm_1.read(ba) << 1;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
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
	ISA32_RV32IMCFD,
	"lb",
	(uint32_t) 0x000003,
	(uint32_t) 0x00707f,
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
etiss_uint32 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//LB\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
partInit.code() += "etiss_uint32 load_address = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] + " + std::to_string(((etiss_int16)((imm) << (4)) >> (4))) + ";\n";
partInit.code() += "etiss_uint8 mem_val_0;\n";
partInit.code() += "exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 1);\n";
partInit.code() += "etiss_int8 res = (etiss_int8)(mem_val_0);\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = (etiss_int32)(res);\n";
}
partInit.code() += "if (exception) return exception;\n";
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
etiss_uint32 imm = 0;
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
	ISA32_RV32IMCFD,
	"lh",
	(uint32_t) 0x001003,
	(uint32_t) 0x00707f,
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
etiss_uint32 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//LH\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
partInit.code() += "etiss_uint32 load_address = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] + " + std::to_string(((etiss_int16)((imm) << (4)) >> (4))) + ";\n";
partInit.code() += "etiss_uint16 mem_val_0;\n";
partInit.code() += "exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 2);\n";
partInit.code() += "etiss_int16 res = (etiss_int16)(mem_val_0);\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = (etiss_int32)(res);\n";
}
partInit.code() += "if (exception) return exception;\n";
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
etiss_uint32 imm = 0;
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
	ISA32_RV32IMCFD,
	"lw",
	(uint32_t) 0x002003,
	(uint32_t) 0x00707f,
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
etiss_uint32 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//LW\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
partInit.code() += "etiss_uint32 load_address = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] + " + std::to_string(((etiss_int16)((imm) << (4)) >> (4))) + ";\n";
partInit.code() += "etiss_uint32 mem_val_0;\n";
partInit.code() += "exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 4);\n";
partInit.code() += "etiss_int32 res = (etiss_int32)(mem_val_0);\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = (etiss_int32)(res);\n";
}
partInit.code() += "if (exception) return exception;\n";
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
etiss_uint32 imm = 0;
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
	ISA32_RV32IMCFD,
	"lbu",
	(uint32_t) 0x004003,
	(uint32_t) 0x00707f,
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
etiss_uint32 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//LBU\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
partInit.code() += "etiss_uint32 load_address = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] + " + std::to_string(((etiss_int16)((imm) << (4)) >> (4))) + ";\n";
partInit.code() += "etiss_uint8 mem_val_0;\n";
partInit.code() += "exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 1);\n";
partInit.code() += "etiss_uint8 res = (etiss_uint8)(mem_val_0);\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = (etiss_uint32)(res);\n";
}
partInit.code() += "if (exception) return exception;\n";
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
etiss_uint32 imm = 0;
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
	ISA32_RV32IMCFD,
	"lhu",
	(uint32_t) 0x005003,
	(uint32_t) 0x00707f,
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
etiss_uint32 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//LHU\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
partInit.code() += "etiss_uint32 load_address = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] + " + std::to_string(((etiss_int16)((imm) << (4)) >> (4))) + ";\n";
partInit.code() += "etiss_uint16 mem_val_0;\n";
partInit.code() += "exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 2);\n";
partInit.code() += "etiss_uint16 res = (etiss_uint16)(mem_val_0);\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = (etiss_uint32)(res);\n";
}
partInit.code() += "if (exception) return exception;\n";
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
etiss_uint32 imm = 0;
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
	ISA32_RV32IMCFD,
	"sb",
	(uint32_t) 0x000023,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_0(11, 7);
imm += R_imm_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(31, 25);
imm += R_imm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//SB\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
partInit.code() += "etiss_uint32 store_address = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] + " + std::to_string(((etiss_int16)((imm) << (4)) >> (4))) + ";\n";
partInit.code() += "etiss_uint8 mem_val_0 = (etiss_int8)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "]);\n";
partInit.code() += "exception |= (*(system->dwrite))(system->handle, cpu, store_address, (etiss_uint8*)&mem_val_0, 1);\n";

partInit.code() += "if (exception) return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_0(11, 7);
imm += R_imm_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
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
	ISA32_RV32IMCFD,
	"sh",
	(uint32_t) 0x001023,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_0(11, 7);
imm += R_imm_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(31, 25);
imm += R_imm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//SH\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
partInit.code() += "etiss_uint32 store_address = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] + " + std::to_string(((etiss_int16)((imm) << (4)) >> (4))) + ";\n";
partInit.code() += "etiss_uint16 mem_val_0 = (etiss_int16)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "]);\n";
partInit.code() += "exception |= (*(system->dwrite))(system->handle, cpu, store_address, (etiss_uint8*)&mem_val_0, 2);\n";

partInit.code() += "if (exception) return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_0(11, 7);
imm += R_imm_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
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
	ISA32_RV32IMCFD,
	"sw",
	(uint32_t) 0x002023,
	(uint32_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_0(11, 7);
imm += R_imm_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm_5(31, 25);
imm += R_imm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//SW\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
partInit.code() += "etiss_uint32 store_address = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] + " + std::to_string(((etiss_int16)((imm) << (4)) >> (4))) + ";\n";
partInit.code() += "etiss_uint32 mem_val_0 = (etiss_int32)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "]);\n";
partInit.code() += "exception |= (*(system->dwrite))(system->handle, cpu, store_address, (etiss_uint8*)&mem_val_0, 4);\n";

partInit.code() += "if (exception) return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_0(11, 7);
imm += R_imm_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
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
	ISA32_RV32IMCFD,
	"addi",
	(uint32_t) 0x000013,
	(uint32_t) 0x00707f,
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
etiss_uint32 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//ADDI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] + " + std::to_string(((etiss_int16)((imm) << (4)) >> (4))) + ";\n";
}
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
etiss_uint32 imm = 0;
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
	ISA32_RV32IMCFD,
	"slti",
	(uint32_t) 0x002013,
	(uint32_t) 0x00707f,
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
etiss_uint32 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//SLTI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = (((etiss_int32)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "]) < " + std::to_string(((etiss_int16)((imm) << (4)) >> (4))) + ")) ? (" + std::to_string(1) + ") : (" + std::to_string(0) + ");\n";
}
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
etiss_uint32 imm = 0;
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
	ISA32_RV32IMCFD,
	"sltiu",
	(uint32_t) 0x003013,
	(uint32_t) 0x00707f,
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
etiss_uint32 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//SLTIU\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = ((*((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] < " + std::to_string((etiss_uint32)((((etiss_int16)((imm) << (4)) >> (4))))) + ")) ? (" + std::to_string(1) + ") : (" + std::to_string(0) + ");\n";
}
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
etiss_uint32 imm = 0;
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
	ISA32_RV32IMCFD,
	"xori",
	(uint32_t) 0x004013,
	(uint32_t) 0x00707f,
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
etiss_uint32 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//XORI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] ^ " + std::to_string(((etiss_int16)((imm) << (4)) >> (4))) + ";\n";
}
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
etiss_uint32 imm = 0;
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
	ISA32_RV32IMCFD,
	"ori",
	(uint32_t) 0x006013,
	(uint32_t) 0x00707f,
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
etiss_uint32 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//ORI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] | " + std::to_string(((etiss_int16)((imm) << (4)) >> (4))) + ";\n";
}
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
etiss_uint32 imm = 0;
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
	ISA32_RV32IMCFD,
	"andi",
	(uint32_t) 0x007013,
	(uint32_t) 0x00707f,
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
etiss_uint32 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//ANDI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] & " + std::to_string(((etiss_int16)((imm) << (4)) >> (4))) + ";\n";
}
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
etiss_uint32 imm = 0;
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
	ISA32_RV32IMCFD,
	"slli",
	(uint32_t) 0x001013,
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
etiss_uint32 shamt = 0;
static BitArrayRange R_shamt_0(24, 20);
shamt += R_shamt_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//SLLI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] << " + std::to_string(shamt) + ";\n";
}
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
etiss_uint32 shamt = 0;
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
	ISA32_RV32IMCFD,
	"srli",
	(uint32_t) 0x005013,
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
etiss_uint32 shamt = 0;
static BitArrayRange R_shamt_0(24, 20);
shamt += R_shamt_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//SRLI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] >> " + std::to_string(shamt) + ";\n";
}
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
etiss_uint32 shamt = 0;
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
	ISA32_RV32IMCFD,
	"srai",
	(uint32_t) 0x40005013,
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
etiss_uint32 shamt = 0;
static BitArrayRange R_shamt_0(24, 20);
shamt += R_shamt_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//SRAI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = (etiss_int32)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "]) >> " + std::to_string(shamt) + ";\n";
}
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
etiss_uint32 shamt = 0;
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
	ISA32_RV32IMCFD,
	"add",
	(uint32_t) 0x000033,
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

		partInit.code() = std::string("//ADD\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] + *((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "];\n";
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
ss << "add" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SUB -------------------------------------------------------------------------
static InstructionDefinition sub_rd_rs1_rs2 (
	ISA32_RV32IMCFD,
	"sub",
	(uint32_t) 0x40000033,
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

		partInit.code() = std::string("//SUB\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] - *((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "];\n";
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
ss << "sub" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SLL -------------------------------------------------------------------------
static InstructionDefinition sll_rd_rs1_rs2 (
	ISA32_RV32IMCFD,
	"sll",
	(uint32_t) 0x001033,
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

		partInit.code() = std::string("//SLL\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] << (*((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "] & " + std::to_string((32 - 1)) + ");\n";
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
ss << "sll" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SLT -------------------------------------------------------------------------
static InstructionDefinition slt_rd_rs1_rs2 (
	ISA32_RV32IMCFD,
	"slt",
	(uint32_t) 0x002033,
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

		partInit.code() = std::string("//SLT\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = ((etiss_int32)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "]) < (etiss_int32)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "])) ? (" + std::to_string(1) + ") : (" + std::to_string(0) + ");\n";
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
ss << "slt" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SLTU ------------------------------------------------------------------------
static InstructionDefinition sltu_rd_rs1_rs2 (
	ISA32_RV32IMCFD,
	"sltu",
	(uint32_t) 0x003033,
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

		partInit.code() = std::string("//SLTU\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = ((etiss_uint32)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "]) < (etiss_uint32)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "])) ? (" + std::to_string(1) + ") : (" + std::to_string(0) + ");\n";
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
ss << "sltu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// XOR -------------------------------------------------------------------------
static InstructionDefinition xor_rd_rs1_rs2 (
	ISA32_RV32IMCFD,
	"xor",
	(uint32_t) 0x004033,
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

		partInit.code() = std::string("//XOR\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] ^ *((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "];\n";
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
ss << "xor" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SRL -------------------------------------------------------------------------
static InstructionDefinition srl_rd_rs1_rs2 (
	ISA32_RV32IMCFD,
	"srl",
	(uint32_t) 0x005033,
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

		partInit.code() = std::string("//SRL\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] >> (*((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "] & " + std::to_string((32 - 1)) + ");\n";
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
ss << "srl" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SRA -------------------------------------------------------------------------
static InstructionDefinition sra_rd_rs1_rs2 (
	ISA32_RV32IMCFD,
	"sra",
	(uint32_t) 0x40005033,
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

		partInit.code() = std::string("//SRA\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = (etiss_int32)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "]) >> (*((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "] & " + std::to_string((32 - 1)) + ");\n";
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
ss << "sra" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// OR --------------------------------------------------------------------------
static InstructionDefinition or_rd_rs1_rs2 (
	ISA32_RV32IMCFD,
	"or",
	(uint32_t) 0x006033,
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

		partInit.code() = std::string("//OR\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] | *((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "];\n";
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
ss << "or" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AND -------------------------------------------------------------------------
static InstructionDefinition and_rd_rs1_rs2 (
	ISA32_RV32IMCFD,
	"and",
	(uint32_t) 0x007033,
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

		partInit.code() = std::string("//AND\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] & *((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "];\n";
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
ss << "and" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FENCE -----------------------------------------------------------------------
static InstructionDefinition fence_rd_rs1_succ_pred_fm (
	ISA32_RV32IMCFD,
	"fence",
	(uint32_t) 0x00000f,
	(uint32_t) 0x00707f,
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
etiss_uint32 succ = 0;
static BitArrayRange R_succ_0(23, 20);
succ += R_succ_0.read(ba) << 0;
etiss_uint32 pred = 0;
static BitArrayRange R_pred_0(27, 24);
pred += R_pred_0.read(ba) << 0;
etiss_uint32 fm = 0;
static BitArrayRange R_fm_0(31, 28);
fm += R_fm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//FENCE\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
partInit.code() += "((RV32IMCFD*)cpu)->FENCE[" + std::to_string(0) + "] = " + std::to_string(pred << 4 | succ) + ";\n";
// -----------------------------------------------------------------------------

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
etiss_uint32 succ = 0;
static BitArrayRange R_succ_0(23, 20);
succ += R_succ_0.read(ba) << 0;
etiss_uint32 pred = 0;
static BitArrayRange R_pred_0(27, 24);
pred += R_pred_0.read(ba) << 0;
etiss_uint32 fm = 0;
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

// ECALL -----------------------------------------------------------------------
static InstructionDefinition ecall_ (
	ISA32_RV32IMCFD,
	"ecall",
	(uint32_t) 0x000073,
	(uint32_t) 0xffffffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//ECALL\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
partInit.code() += "exception = ETISS_RETURNCODE_SYSCALL;\n";
partInit.code() += "return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "ecall" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// EBREAK ----------------------------------------------------------------------
static InstructionDefinition ebreak_ (
	ISA32_RV32IMCFD,
	"ebreak",
	(uint32_t) 0x100073,
	(uint32_t) 0xffffffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//EBREAK\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
partInit.code() += "exception = ETISS_RETURNCODE_CPUFINISHED;\n";
partInit.code() += "return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "ebreak" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// WFI -------------------------------------------------------------------------
static InstructionDefinition wfi_ (
	ISA32_RV32IMCFD,
	"wfi",
	(uint32_t) 0x10500073,
	(uint32_t) 0xffffffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//WFI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
partInit.code() += "exception = ETISS_RETURNCODE_CPUFINISHED;\n";
partInit.code() += "if (exception) return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "wfi" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// DRET ------------------------------------------------------------------------
static InstructionDefinition dret_ (
	ISA32_RV32IMCFD,
	"dret",
	(uint32_t) 0x7b200073,
	(uint32_t) 0xffffffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//DRET\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
partInit.code() += "if (((RV32IMCFD*)cpu)->PRIV < " + std::to_string(4) + ") {\n";
partInit.code() += "exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION;\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "cpu->instructionPointer = ((RV32IMCFD*)cpu)->DPC;\n";
partInit.code() += "((RV32IMCFD*)cpu)->PRIV = (((RV32IMCFD*)cpu)->PRIV & " + std::to_string(3) + ") & 0x7;\n";
partInit.code() += "}\n";
partInit.code() += "if (exception) return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "dret" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
