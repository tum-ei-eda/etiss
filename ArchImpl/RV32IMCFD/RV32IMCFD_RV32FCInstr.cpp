/**
 * Generated on Tue, 15 Feb 2022 21:11:54 +0100.
 *
 * This file contains the instruction behavior models of the RV32FC
 * instruction set for the RV32IMCFD core architecture.
 */

#include "RV32IMCFDArch.h"

#define ETISS_ARCH_STATIC_FN_ONLY
#include "RV32IMCFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// CFLW ------------------------------------------------------------------------
static InstructionDefinition cflw_rd_uimm_rs1 (
	ISA16_RV32IMCFD,
	"cflw",
	(uint16_t) 0x6000,
	(uint16_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(4, 2);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 uimm = 0;
static BitArrayRange R_uimm_6(5, 5);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_2(6, 6);
uimm += R_uimm_2.read(ba) << 2;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_uimm_3(12, 10);
uimm += R_uimm_3.read(ba) << 3;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CFLW\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2) + ";\n";
partInit.code() += "etiss_uint32 offs = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1 + 8) + "] + " + std::to_string(uimm) + ";\n";
partInit.code() += "etiss_uint32 mem_val_0;\n";
partInit.code() += "exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
partInit.code() += "etiss_uint32 res = (etiss_uint32)(mem_val_0);\n";
if (64 == 32) {
partInit.code() += "((RV32IMCFD*)cpu)->F[" + std::to_string(rd + 8) + "] = res;\n";
} else {
etiss_uint64 upper = -(1);
partInit.code() += "((RV32IMCFD*)cpu)->F[" + std::to_string(rd + 8) + "] = " + std::to_string((upper << 32)) + " | res;\n";
}
partInit.code() += "if (exception) return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1 + 8], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(4, 2);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 uimm = 0;
static BitArrayRange R_uimm_6(5, 5);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_2(6, 6);
uimm += R_uimm_2.read(ba) << 2;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_uimm_3(12, 10);
uimm += R_uimm_3.read(ba) << 3;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cflw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | uimm=" + std::to_string(uimm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CFSW ------------------------------------------------------------------------
static InstructionDefinition cfsw_rs2_uimm_rs1 (
	ISA16_RV32IMCFD,
	"cfsw",
	(uint16_t) 0xe000,
	(uint16_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint32 uimm = 0;
static BitArrayRange R_uimm_6(5, 5);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_2(6, 6);
uimm += R_uimm_2.read(ba) << 2;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_uimm_3(12, 10);
uimm += R_uimm_3.read(ba) << 3;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CFSW\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2) + ";\n";
partInit.code() += "etiss_uint32 offs = *((RV32IMCFD*)cpu)->X[" + std::to_string(rs1 + 8) + "] + " + std::to_string(uimm) + ";\n";
partInit.code() += "etiss_uint32 mem_val_0 = (etiss_uint32)(((RV32IMCFD*)cpu)->F[" + std::to_string(rs2 + 8) + "]);\n";
partInit.code() += "exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";

partInit.code() += "if (exception) return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1 + 8], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint32 uimm = 0;
static BitArrayRange R_uimm_6(5, 5);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_2(6, 6);
uimm += R_uimm_2.read(ba) << 2;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_uimm_3(12, 10);
uimm += R_uimm_3.read(ba) << 3;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cfsw" << " # " << ba << (" [rs2=" + std::to_string(rs2) + " | uimm=" + std::to_string(uimm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CFLWSP ----------------------------------------------------------------------
static InstructionDefinition cflwsp_uimm_rd (
	ISA16_RV32IMCFD,
	"cflwsp",
	(uint16_t) 0x6002,
	(uint16_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 uimm = 0;
static BitArrayRange R_uimm_6(3, 2);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_2(6, 4);
uimm += R_uimm_2.read(ba) << 2;
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
static BitArrayRange R_uimm_5(12, 12);
uimm += R_uimm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CFLWSP\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2) + ";\n";
partInit.code() += "etiss_uint32 offs = *((RV32IMCFD*)cpu)->X[" + std::to_string(2) + "] + " + std::to_string(uimm) + ";\n";
partInit.code() += "etiss_uint32 mem_val_0;\n";
partInit.code() += "exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
partInit.code() += "etiss_uint32 res = (etiss_uint32)(mem_val_0);\n";
if (64 == 32) {
partInit.code() += "((RV32IMCFD*)cpu)->F[" + std::to_string(rd) + "] = res;\n";
} else {
etiss_uint64 upper = -(1);
partInit.code() += "((RV32IMCFD*)cpu)->F[" + std::to_string(rd) + "] = " + std::to_string((upper << 32)) + " | res;\n";
}
partInit.code() += "if (exception) return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[2], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 uimm = 0;
static BitArrayRange R_uimm_6(3, 2);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_2(6, 4);
uimm += R_uimm_2.read(ba) << 2;
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
static BitArrayRange R_uimm_5(12, 12);
uimm += R_uimm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cflwsp" << " # " << ba << (" [uimm=" + std::to_string(uimm) + " | rd=" + std::to_string(rd) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CFSWSP ----------------------------------------------------------------------
static InstructionDefinition cfswsp_rs2_uimm (
	ISA16_RV32IMCFD,
	"cfswsp",
	(uint16_t) 0xe002,
	(uint16_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(6, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint32 uimm = 0;
static BitArrayRange R_uimm_6(8, 7);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_2(12, 9);
uimm += R_uimm_2.read(ba) << 2;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CFSWSP\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2) + ";\n";
partInit.code() += "etiss_uint32 offs = *((RV32IMCFD*)cpu)->X[" + std::to_string(2) + "] + " + std::to_string(uimm) + ";\n";
partInit.code() += "etiss_uint32 mem_val_0 = (etiss_uint32)(((RV32IMCFD*)cpu)->F[" + std::to_string(rs2) + "]);\n";
partInit.code() += "exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";

partInit.code() += "if (exception) return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[2], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(6, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint32 uimm = 0;
static BitArrayRange R_uimm_6(8, 7);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_2(12, 9);
uimm += R_uimm_2.read(ba) << 2;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cfswsp" << " # " << ba << (" [rs2=" + std::to_string(rs2) + " | uimm=" + std::to_string(uimm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
