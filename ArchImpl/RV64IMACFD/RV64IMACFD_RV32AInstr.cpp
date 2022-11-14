/**
 * Generated on Mon, 14 Nov 2022 16:47:27 +0100.
 *
 * This file contains the instruction behavior models of the RV32A
 * instruction set for the RV64IMACFD core architecture.
 */

#include "RV64IMACFDArch.h"

#define ETISS_ARCH_STATIC_FN_ONLY
#include "RV64IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// AMOSWAPW --------------------------------------------------------------------
static InstructionDefinition amoswapw_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amoswapw",
	(uint32_t) 0x800202f,
	(uint32_t) 0xf800707f,
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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//AMOSWAPW\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4UL) + "U;\n";
partInit.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32U) + "U];\n";
if ((rd % 32U) != 0U) {
partInit.code() += "etiss_uint32 mem_val_0;\n";
partInit.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
partInit.code() += "if (cpu->exception) {\n";
partInit.code() += "translate_exc_code(cpu, system, plugin_pointers, cpu->exception); goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
partInit.code() += "}\n";
partInit.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "U] = (etiss_int64)(((etiss_int32)(mem_val_0)));\n";
}
partInit.code() += "etiss_uint32 mem_val_1 = (etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "U]);\n";
partInit.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
partInit.code() += "if (cpu->exception) {\n";
partInit.code() += "translate_exc_code(cpu, system, plugin_pointers, cpu->exception); goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
partInit.code() += "}\n";
partInit.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
partInit.code() += "cpu->instructionPointer = cpu->nextPc;\n";
partInit.code() += "if (cpu->return_pending) return cpu->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1 % 32U], 64);
		partInit.getRegisterDependencies().add(reg_name[rs2 % 32U], 64);
		partInit.getAffectedRegisters().add(reg_name[rd % 32], 64);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amoswapw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOADDW ---------------------------------------------------------------------
static InstructionDefinition amoaddw_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amoaddw",
	(uint32_t) 0x00202f,
	(uint32_t) 0xf800707f,
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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//AMOADDW\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4UL) + "U;\n";
partInit.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32U) + "U];\n";
partInit.code() += "etiss_uint32 mem_val_0;\n";
partInit.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
partInit.code() += "if (cpu->exception) {\n";
partInit.code() += "translate_exc_code(cpu, system, plugin_pointers, cpu->exception); goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
partInit.code() += "}\n";
partInit.code() += "etiss_int32 res1 = mem_val_0;\n";
if ((rd % 32U) != 0U) {
partInit.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "U] = res1;\n";
}
partInit.code() += "etiss_uint32 res2 = res1 + *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "U];\n";
partInit.code() += "etiss_uint32 mem_val_1 = res2;\n";
partInit.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
partInit.code() += "if (cpu->exception) {\n";
partInit.code() += "translate_exc_code(cpu, system, plugin_pointers, cpu->exception); goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
partInit.code() += "}\n";
partInit.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
partInit.code() += "cpu->instructionPointer = cpu->nextPc;\n";
partInit.code() += "if (cpu->return_pending) return cpu->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1 % 32U], 64);
		partInit.getRegisterDependencies().add(reg_name[rs2 % 32U], 64);
		partInit.getAffectedRegisters().add(reg_name[rd % 32], 64);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amoaddw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOXORW ---------------------------------------------------------------------
static InstructionDefinition amoxorw_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amoxorw",
	(uint32_t) 0x2000202f,
	(uint32_t) 0xf800707f,
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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//AMOXORW\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4UL) + "U;\n";
partInit.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32U) + "U];\n";
partInit.code() += "etiss_uint32 mem_val_0;\n";
partInit.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
partInit.code() += "if (cpu->exception) {\n";
partInit.code() += "translate_exc_code(cpu, system, plugin_pointers, cpu->exception); goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
partInit.code() += "}\n";
partInit.code() += "etiss_int32 res1 = mem_val_0;\n";
if ((rd % 32U) != 0U) {
partInit.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "U] = res1;\n";
}
partInit.code() += "etiss_uint32 res2 = res1 ^ *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "U];\n";
partInit.code() += "etiss_uint32 mem_val_1 = res2;\n";
partInit.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
partInit.code() += "if (cpu->exception) {\n";
partInit.code() += "translate_exc_code(cpu, system, plugin_pointers, cpu->exception); goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
partInit.code() += "}\n";
partInit.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
partInit.code() += "cpu->instructionPointer = cpu->nextPc;\n";
partInit.code() += "if (cpu->return_pending) return cpu->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1 % 32U], 64);
		partInit.getRegisterDependencies().add(reg_name[rs2 % 32U], 64);
		partInit.getAffectedRegisters().add(reg_name[rd % 32], 64);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amoxorw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOANDW ---------------------------------------------------------------------
static InstructionDefinition amoandw_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amoandw",
	(uint32_t) 0x6000202f,
	(uint32_t) 0xf800707f,
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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//AMOANDW\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4UL) + "U;\n";
partInit.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32U) + "U];\n";
partInit.code() += "etiss_uint32 mem_val_0;\n";
partInit.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
partInit.code() += "if (cpu->exception) {\n";
partInit.code() += "translate_exc_code(cpu, system, plugin_pointers, cpu->exception); goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
partInit.code() += "}\n";
partInit.code() += "etiss_int32 res1 = mem_val_0;\n";
if ((rd % 32U) != 0U) {
partInit.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "U] = res1;\n";
}
partInit.code() += "etiss_uint32 res2 = res1 & *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "U];\n";
partInit.code() += "etiss_uint32 mem_val_1 = res2;\n";
partInit.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
partInit.code() += "if (cpu->exception) {\n";
partInit.code() += "translate_exc_code(cpu, system, plugin_pointers, cpu->exception); goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
partInit.code() += "}\n";
partInit.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
partInit.code() += "cpu->instructionPointer = cpu->nextPc;\n";
partInit.code() += "if (cpu->return_pending) return cpu->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1 % 32U], 64);
		partInit.getRegisterDependencies().add(reg_name[rs2 % 32U], 64);
		partInit.getAffectedRegisters().add(reg_name[rd % 32], 64);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amoandw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOORW ----------------------------------------------------------------------
static InstructionDefinition amoorw_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amoorw",
	(uint32_t) 0x4000202f,
	(uint32_t) 0xf800707f,
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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//AMOORW\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4UL) + "U;\n";
partInit.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32U) + "U];\n";
partInit.code() += "etiss_uint32 mem_val_0;\n";
partInit.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
partInit.code() += "if (cpu->exception) {\n";
partInit.code() += "translate_exc_code(cpu, system, plugin_pointers, cpu->exception); goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
partInit.code() += "}\n";
partInit.code() += "etiss_int32 res1 = mem_val_0;\n";
if ((rd % 32U) != 0U) {
partInit.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "U] = res1;\n";
}
partInit.code() += "etiss_uint32 res2 = res1 | *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "U];\n";
partInit.code() += "etiss_uint32 mem_val_1 = res2;\n";
partInit.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
partInit.code() += "if (cpu->exception) {\n";
partInit.code() += "translate_exc_code(cpu, system, plugin_pointers, cpu->exception); goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
partInit.code() += "}\n";
partInit.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
partInit.code() += "cpu->instructionPointer = cpu->nextPc;\n";
partInit.code() += "if (cpu->return_pending) return cpu->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1 % 32U], 64);
		partInit.getRegisterDependencies().add(reg_name[rs2 % 32U], 64);
		partInit.getAffectedRegisters().add(reg_name[rd % 32], 64);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amoorw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOMINW ---------------------------------------------------------------------
static InstructionDefinition amominw_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amominw",
	(uint32_t) 0x8000202f,
	(uint32_t) 0xf800707f,
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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//AMOMINW\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4UL) + "U;\n";
partInit.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32U) + "U];\n";
partInit.code() += "etiss_uint32 mem_val_0;\n";
partInit.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
partInit.code() += "if (cpu->exception) {\n";
partInit.code() += "translate_exc_code(cpu, system, plugin_pointers, cpu->exception); goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
partInit.code() += "}\n";
partInit.code() += "etiss_int32 res1 = mem_val_0;\n";
if ((rd % 32U) != 0U) {
partInit.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "U] = res1;\n";
}
partInit.code() += "etiss_uint32 res2 = (res1 > (etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "U])) ? (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "U]) : (res1);\n";
partInit.code() += "etiss_uint32 mem_val_1 = res2;\n";
partInit.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
partInit.code() += "if (cpu->exception) {\n";
partInit.code() += "translate_exc_code(cpu, system, plugin_pointers, cpu->exception); goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
partInit.code() += "}\n";
partInit.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
partInit.code() += "cpu->instructionPointer = cpu->nextPc;\n";
partInit.code() += "if (cpu->return_pending) return cpu->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1 % 32U], 64);
		partInit.getRegisterDependencies().add(reg_name[rs2 % 32U], 64);
		partInit.getAffectedRegisters().add(reg_name[rd % 32], 64);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amominw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOMAXW ---------------------------------------------------------------------
static InstructionDefinition amomaxw_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amomaxw",
	(uint32_t) 0xa000202f,
	(uint32_t) 0xf800707f,
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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//AMOMAXW\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4UL) + "U;\n";
partInit.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32U) + "U];\n";
partInit.code() += "etiss_uint32 mem_val_0;\n";
partInit.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
partInit.code() += "if (cpu->exception) {\n";
partInit.code() += "translate_exc_code(cpu, system, plugin_pointers, cpu->exception); goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
partInit.code() += "}\n";
partInit.code() += "etiss_int32 res1 = mem_val_0;\n";
if ((rd % 32U) != 0U) {
partInit.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "U] = res1;\n";
}
partInit.code() += "etiss_uint32 res2 = (res1 < (etiss_int32)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "U])) ? (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "U]) : (res1);\n";
partInit.code() += "etiss_uint32 mem_val_1 = res2;\n";
partInit.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
partInit.code() += "if (cpu->exception) {\n";
partInit.code() += "translate_exc_code(cpu, system, plugin_pointers, cpu->exception); goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
partInit.code() += "}\n";
partInit.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
partInit.code() += "cpu->instructionPointer = cpu->nextPc;\n";
partInit.code() += "if (cpu->return_pending) return cpu->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1 % 32U], 64);
		partInit.getRegisterDependencies().add(reg_name[rs2 % 32U], 64);
		partInit.getAffectedRegisters().add(reg_name[rd % 32], 64);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amomaxw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOMINUW --------------------------------------------------------------------
static InstructionDefinition amominuw_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amominuw",
	(uint32_t) 0xc000202f,
	(uint32_t) 0xf800707f,
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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//AMOMINUW\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4UL) + "U;\n";
partInit.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32U) + "U];\n";
partInit.code() += "etiss_uint32 mem_val_0;\n";
partInit.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
partInit.code() += "if (cpu->exception) {\n";
partInit.code() += "translate_exc_code(cpu, system, plugin_pointers, cpu->exception); goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
partInit.code() += "}\n";
partInit.code() += "etiss_uint32 res1 = mem_val_0;\n";
if ((rd % 32U) != 0U) {
partInit.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "U] = (etiss_int32)(res1);\n";
}
partInit.code() += "etiss_uint32 res2 = (res1 > *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "U]) ? (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "U]) : (res1);\n";
partInit.code() += "etiss_uint32 mem_val_1 = res2;\n";
partInit.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
partInit.code() += "if (cpu->exception) {\n";
partInit.code() += "translate_exc_code(cpu, system, plugin_pointers, cpu->exception); goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
partInit.code() += "}\n";
partInit.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
partInit.code() += "cpu->instructionPointer = cpu->nextPc;\n";
partInit.code() += "if (cpu->return_pending) return cpu->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1 % 32U], 64);
		partInit.getRegisterDependencies().add(reg_name[rs2 % 32U], 64);
		partInit.getAffectedRegisters().add(reg_name[rd % 32], 64);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amominuw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOMAXUW --------------------------------------------------------------------
static InstructionDefinition amomaxuw_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amomaxuw",
	(uint32_t) 0xe000202f,
	(uint32_t) 0xf800707f,
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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//AMOMAXUW\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4UL) + "U;\n";
partInit.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32U) + "U];\n";
partInit.code() += "etiss_uint32 mem_val_0;\n";
partInit.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
partInit.code() += "if (cpu->exception) {\n";
partInit.code() += "translate_exc_code(cpu, system, plugin_pointers, cpu->exception); goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
partInit.code() += "}\n";
partInit.code() += "etiss_uint32 res1 = mem_val_0;\n";
if ((rd % 32U) != 0U) {
partInit.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "U] = (etiss_int32)(res1);\n";
}
partInit.code() += "etiss_uint32 res2 = (res1 < *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "U]) ? (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "U]) : (res1);\n";
partInit.code() += "etiss_uint32 mem_val_1 = res2;\n";
partInit.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
partInit.code() += "if (cpu->exception) {\n";
partInit.code() += "translate_exc_code(cpu, system, plugin_pointers, cpu->exception); goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
partInit.code() += "}\n";
partInit.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
partInit.code() += "cpu->instructionPointer = cpu->nextPc;\n";
partInit.code() += "if (cpu->return_pending) return cpu->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1 % 32U], 64);
		partInit.getRegisterDependencies().add(reg_name[rs2 % 32U], 64);
		partInit.getAffectedRegisters().add(reg_name[rd % 32], 64);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

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
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amomaxuw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
