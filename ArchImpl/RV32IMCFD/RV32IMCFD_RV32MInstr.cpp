/**
 * Generated on Tue, 15 Feb 2022 21:11:54 +0100.
 *
 * This file contains the instruction behavior models of the RV32M
 * instruction set for the RV32IMCFD core architecture.
 */

#include "RV32IMCFDArch.h"

#define ETISS_ARCH_STATIC_FN_ONLY
#include "RV32IMCFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// MUL -------------------------------------------------------------------------
static InstructionDefinition mul_rd_rs1_rs2 (
	ISA32_RV32IMCFD,
	"mul",
	(uint32_t) 0x2000033,
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

		partInit.code() = std::string("//MUL\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "etiss_int64 res = (etiss_int64)((etiss_int32)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "])) * (etiss_int64)((etiss_int32)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "]));\n";
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = (etiss_uint32)(res);\n";
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
ss << "mul" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// MULH ------------------------------------------------------------------------
static InstructionDefinition mulh_rd_rs1_rs2 (
	ISA32_RV32IMCFD,
	"mulh",
	(uint32_t) 0x2001033,
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

		partInit.code() = std::string("//MULH\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "etiss_int64 res = (etiss_int64)((etiss_int32)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "])) * (etiss_int64)((etiss_int32)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "]));\n";
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = (etiss_uint32)((res >> " + std::to_string(32) + "));\n";
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
ss << "mulh" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// MULHSU ----------------------------------------------------------------------
static InstructionDefinition mulhsu_rd_rs1_rs2 (
	ISA32_RV32IMCFD,
	"mulhsu",
	(uint32_t) 0x2002033,
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

		partInit.code() = std::string("//MULHSU\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "etiss_int64 res = (etiss_int64)((etiss_int32)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "])) * (etiss_uint64)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "]);\n";
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = (etiss_uint32)((res >> " + std::to_string(32) + "));\n";
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
ss << "mulhsu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// MULHU -----------------------------------------------------------------------
static InstructionDefinition mulhu_rd_rs1_rs2 (
	ISA32_RV32IMCFD,
	"mulhu",
	(uint32_t) 0x2003033,
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

		partInit.code() = std::string("//MULHU\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "etiss_uint64 res = (etiss_uint64)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "]) * (etiss_uint64)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "]);\n";
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = (etiss_uint32)((res >> " + std::to_string(32) + "));\n";
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
ss << "mulhu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// DIV -------------------------------------------------------------------------
static InstructionDefinition div_rd_rs1_rs2 (
	ISA32_RV32IMCFD,
	"div",
	(uint32_t) 0x2004033,
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

		partInit.code() = std::string("//DIV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "if (*((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "] != " + std::to_string(0) + ") {\n";
etiss_uint32 MMIN = 1 << (32 - 1);
partInit.code() += "if (*((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] == " + std::to_string(MMIN) + " && (etiss_int32)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "]) == " + std::to_string(-(1)) + ") {\n";
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = " + std::to_string(MMIN) + ";\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = (etiss_int32)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "]) / (etiss_int32)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "]);\n";
partInit.code() += "}\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = " + std::to_string(-(1)) + ";\n";
partInit.code() += "}\n";
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
ss << "div" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// DIVU ------------------------------------------------------------------------
static InstructionDefinition divu_rd_rs1_rs2 (
	ISA32_RV32IMCFD,
	"divu",
	(uint32_t) 0x2005033,
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

		partInit.code() = std::string("//DIVU\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "if (*((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "] != " + std::to_string(0) + ") {\n";
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] / *((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "];\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = " + std::to_string(-(1)) + ";\n";
partInit.code() += "}\n";
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
ss << "divu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// REM -------------------------------------------------------------------------
static InstructionDefinition rem_rd_rs1_rs2 (
	ISA32_RV32IMCFD,
	"rem",
	(uint32_t) 0x2006033,
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

		partInit.code() = std::string("//REM\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "if (*((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "] != " + std::to_string(0) + ") {\n";
etiss_uint32 MMIN = 1 << (32 - 1);
partInit.code() += "if (*((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] == " + std::to_string(MMIN) + " && (etiss_int32)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "]) == " + std::to_string(-(1)) + ") {\n";
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = " + std::to_string(0) + ";\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = (etiss_int32)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "]) % (etiss_int32)(*((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "]);\n";
partInit.code() += "}\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "];\n";
partInit.code() += "}\n";
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
ss << "rem" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// REMU ------------------------------------------------------------------------
static InstructionDefinition remu_rd_rs1_rs2 (
	ISA32_RV32IMCFD,
	"remu",
	(uint32_t) 0x2007033,
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

		partInit.code() = std::string("//REMU\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
if (rd != 0) {
partInit.code() += "if (*((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "] != " + std::to_string(0) + ") {\n";
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "] % *((RV32IMCFD*)cpu)->X[" + std::to_string(rs2) + "];\n";
partInit.code() += "}\n";
partInit.code() += " else {\n";
partInit.code() += "*((RV32IMCFD*)cpu)->X[" + std::to_string(rd) + "] = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1) + "];\n";
partInit.code() += "}\n";
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
ss << "remu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
