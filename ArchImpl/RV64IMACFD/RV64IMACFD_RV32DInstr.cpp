/**
 * Generated on Mon, 02 Oct 2023 17:35:59 +0200.
 *
 * This file contains the instruction behavior models of the RV32D
 * instruction set for the RV64IMACFD core architecture.
 */

#include "RV64IMACFDArch.h"

#define ETISS_ARCH_STATIC_FN_ONLY
#include "RV64IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// FLD -------------------------------------------------------------------------
static InstructionDefinition fld_rd_rs1_imm (
	ISA32_RV64IMACFD,
	"fld",
	(uint32_t) 0x003007,
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

		cp.code() = std::string("//FLD\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_uint64 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 8);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint64 res = (etiss_uint64)(mem_val_0);\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = res;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getRegisterDependencies().add(reg_name[rs1 % 32ULL], 64);
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//FLD\n");

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
ss << "fld" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FSD -------------------------------------------------------------------------
static InstructionDefinition fsd_imm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fsd",
	(uint32_t) 0x003027,
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

		cp.code() = std::string("//FSD\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_uint64 mem_val_0;\n";
cp.code() += "mem_val_0 = (etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 8);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getRegisterDependencies().add(reg_name[rs1 % 32ULL], 64);
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//FSD\n");

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
ss << "fsd" << " # " << ba << (" [imm=" + std::to_string(imm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FMADD_D ---------------------------------------------------------------------
static InstructionDefinition fmadd_d_rd_rm_rs1_rs2_rs3 (
	ISA32_RV64IMACFD,
	"fmadd_d",
	(uint32_t) 0x2000043,
	(uint32_t) 0x600007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(31, 27);
rs3 += R_rs3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FMADD_D\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fmadd_d((etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), (etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]), (etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs3) + "ULL]), 0ULL, get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = res;\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
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
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(31, 27);
rs3 += R_rs3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fmadd_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rs3=" + std::to_string(rs3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FMSUB_D ---------------------------------------------------------------------
static InstructionDefinition fmsub_d_rd_rm_rs1_rs2_rs3 (
	ISA32_RV64IMACFD,
	"fmsub_d",
	(uint32_t) 0x2000047,
	(uint32_t) 0x600007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(31, 27);
rs3 += R_rs3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FMSUB_D\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fmadd_d((etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), (etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]), (etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs3) + "ULL]), 1ULL, get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = res;\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
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
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(31, 27);
rs3 += R_rs3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fmsub_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rs3=" + std::to_string(rs3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FNMADD_D --------------------------------------------------------------------
static InstructionDefinition fnmadd_d_rd_rm_rs1_rs2_rs3 (
	ISA32_RV64IMACFD,
	"fnmadd_d",
	(uint32_t) 0x200004f,
	(uint32_t) 0x600007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(31, 27);
rs3 += R_rs3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FNMADD_D\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fmadd_d((etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), (etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]), (etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs3) + "ULL]), 2ULL, get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = res;\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
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
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(31, 27);
rs3 += R_rs3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fnmadd_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rs3=" + std::to_string(rs3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FNMSUB_D --------------------------------------------------------------------
static InstructionDefinition fnmsub_d_rd_rm_rs1_rs2_rs3 (
	ISA32_RV64IMACFD,
	"fnmsub_d",
	(uint32_t) 0x200004b,
	(uint32_t) 0x600007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(31, 27);
rs3 += R_rs3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FNMSUB_D\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fmadd_d((etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), (etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]), (etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs3) + "ULL]), 3ULL, get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = res;\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
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
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(31, 27);
rs3 += R_rs3_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fnmsub_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rs3=" + std::to_string(rs3) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FADD_D ----------------------------------------------------------------------
static InstructionDefinition fadd_d_rd_rm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fadd_d",
	(uint32_t) 0x2000053,
	(uint32_t) 0xfe00007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FADD_D\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fadd_d((etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), (etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]), get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = res;\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
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
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fadd_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FSUB_D ----------------------------------------------------------------------
static InstructionDefinition fsub_d_rd_rm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fsub_d",
	(uint32_t) 0xa000053,
	(uint32_t) 0xfe00007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FSUB_D\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fsub_d((etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), (etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]), get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = res;\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
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
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fsub_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FMUL_D ----------------------------------------------------------------------
static InstructionDefinition fmul_d_rd_rm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fmul_d",
	(uint32_t) 0x12000053,
	(uint32_t) 0xfe00007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FMUL_D\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fmul_d((etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), (etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]), get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = res;\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
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
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fmul_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FDIV_D ----------------------------------------------------------------------
static InstructionDefinition fdiv_d_rd_rm_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fdiv_d",
	(uint32_t) 0x1a000053,
	(uint32_t) 0xfe00007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FDIV_D\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fdiv_d((etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), (etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]), get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = res;\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
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
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fdiv_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FSQRT_D ---------------------------------------------------------------------
static InstructionDefinition fsqrt_d_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fsqrt_d",
	(uint32_t) 0x5a000053,
	(uint32_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FSQRT_D\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fsqrt_d((etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), get_rm(cpu, system, plugin_pointers, " + std::to_string(rm) + "ULL));\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = res;\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
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
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fsqrt_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FSGNJ_D ---------------------------------------------------------------------
static InstructionDefinition fsgnj_d_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fsgnj_d",
	(uint32_t) 0x22000053,
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

		cp.code() = std::string("//FSGNJ_D\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = ((((((((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]) >> (63ULL)) & 1)) << 63) | ((((((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]) >> (0ULL)) & 9223372036854775807)));\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = res;\n";
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
ss << "fsgnj_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FSGNJN_D --------------------------------------------------------------------
static InstructionDefinition fsgnjn_d_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fsgnjn_d",
	(uint32_t) 0x22001053,
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

		cp.code() = std::string("//FSGNJN_D\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = (((~((((((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]) >> (63ULL)) & 1))) << 63) | ((((((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]) >> (0ULL)) & 9223372036854775807)));\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = res;\n";
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
ss << "fsgnjn_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FSGNJX_D --------------------------------------------------------------------
static InstructionDefinition fsgnjx_d_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fsgnjx_d",
	(uint32_t) 0x22002053,
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

		cp.code() = std::string("//FSGNJX_D\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = (etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]) ^ ((etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]) & 9223372036854775808ULL);\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = res;\n";
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
ss << "fsgnjx_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FMIN_D ----------------------------------------------------------------------
static InstructionDefinition fmin_d_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fmin_d",
	(uint32_t) 0x2a000053,
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

		cp.code() = std::string("//FMIN_D\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fsel_d((etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), (etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]), 0ULL);\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = res;\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
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
ss << "fmin_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FMAX_D ----------------------------------------------------------------------
static InstructionDefinition fmax_d_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fmax_d",
	(uint32_t) 0x2a001053,
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

		cp.code() = std::string("//FMAX_D\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fsel_d((etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), (etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL]), 1ULL);\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = res;\n";
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
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
ss << "fmax_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCVT_S_D --------------------------------------------------------------------
static InstructionDefinition fcvt_s_d_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fcvt_s_d",
	(uint32_t) 0x40100053,
	(uint32_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FCVT_S_D\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 res = fconv_d2f(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL], " + std::to_string(rm) + "ULL);\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = -4294967296LL + res;\n";
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
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fcvt_s_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCVT_D_S --------------------------------------------------------------------
static InstructionDefinition fcvt_d_s_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fcvt_d_s",
	(uint32_t) 0x42000053,
	(uint32_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FCVT_D_S\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fconv_f2d((etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]), " + std::to_string(rm) + "ULL);\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = res;\n";
cp.code() += "} // block\n";
} // block
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
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fcvt_d_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FEQ_D -----------------------------------------------------------------------
static InstructionDefinition feq_d_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"feq_d",
	(uint32_t) 0xa2002053,
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

		cp.code() = std::string("//FEQ_D\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = 0ULL;\n";
cp.code() += "res = fcmp_d(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL], ((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL], 0ULL);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res;\n";
} // conditional
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add(reg_name[rd % 32ULL], 64);
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
ss << "feq_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FLT_D -----------------------------------------------------------------------
static InstructionDefinition flt_d_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"flt_d",
	(uint32_t) 0xa2001053,
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

		cp.code() = std::string("//FLT_D\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = 0ULL;\n";
cp.code() += "res = fcmp_d(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL], ((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL], 2ULL);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res;\n";
} // conditional
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add(reg_name[rd % 32ULL], 64);
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
ss << "flt_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FLE_D -----------------------------------------------------------------------
static InstructionDefinition fle_d_rd_rs1_rs2 (
	ISA32_RV64IMACFD,
	"fle_d",
	(uint32_t) 0xa2000053,
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

		cp.code() = std::string("//FLE_D\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = 0ULL;\n";
cp.code() += "res = fcmp_d(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL], ((RV64IMACFD*)cpu)->F[" + std::to_string(rs2) + "ULL], 1ULL);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res;\n";
} // conditional
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add(reg_name[rd % 32ULL], 64);
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
ss << "fle_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCLASS_D --------------------------------------------------------------------
static InstructionDefinition fclass_d_rd_rs1 (
	ISA32_RV64IMACFD,
	"fclass_d",
	(uint32_t) 0xe2001053,
	(uint32_t) 0xfff0707f,
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

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FCLASS_D\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = fclass_d((etiss_uint64)(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL]));\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add(reg_name[rd % 32ULL], 64);
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

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fclass_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCVT_W_D --------------------------------------------------------------------
static InstructionDefinition fcvt_w_d_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fcvt_w_d",
	(uint32_t) 0xc2000053,
	(uint32_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FCVT_W_D\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_int32 res = 0ULL;\n";
cp.code() += "res = fcvt_64_32(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL], 0ULL, " + std::to_string(rm) + "ULL);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res;\n";
} // conditional
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add(reg_name[rd % 32ULL], 64);
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
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fcvt_w_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCVT_WU_D -------------------------------------------------------------------
static InstructionDefinition fcvt_wu_d_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fcvt_wu_d",
	(uint32_t) 0xc2100053,
	(uint32_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FCVT_WU_D\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 res = 0ULL;\n";
cp.code() += "res = fcvt_64_32(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "ULL], 1ULL, " + std::to_string(rm) + "ULL);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint64)((etiss_int32)(res));\n";
} // conditional
cp.code() += "etiss_uint32 flags = fget_flags();\n";
cp.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32LL) | (flags & 31ULL);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add(reg_name[rd % 32ULL], 64);
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
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fcvt_wu_d" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCVT_D_W --------------------------------------------------------------------
static InstructionDefinition fcvt_d_w_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fcvt_d_w",
	(uint32_t) 0xd2000053,
	(uint32_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FCVT_D_W\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_int64 res = fcvt_32_64((etiss_uint64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]), 2ULL, " + std::to_string(rm) + "ULL);\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = res;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getRegisterDependencies().add(reg_name[rs1 % 32ULL], 64);
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
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fcvt_d_w" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCVT_D_WU -------------------------------------------------------------------
static InstructionDefinition fcvt_d_wu_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fcvt_d_wu",
	(uint32_t) 0xd2100053,
	(uint32_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FCVT_D_WU\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4ULL) + "ULL;\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = fcvt_32_64((etiss_uint64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]), 3ULL, " + std::to_string(rm) + "ULL);\n";
cp.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "ULL] = res;\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getRegisterDependencies().add(reg_name[rs1 % 32ULL], 64);
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
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fcvt_d_wu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
