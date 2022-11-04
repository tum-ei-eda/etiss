/**
 * Generated on Wed, 12 Oct 2022 12:54:05 +0200.
 *
 * This file contains the instruction behavior models of the RV64A
 * instruction set for the RV64IMACFD core architecture.
 */

#include "RV64IMACFDArch.h"

#define ETISS_ARCH_STATIC_FN_ONLY
#include "RV64IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// AMOSWAPD --------------------------------------------------------------------
static InstructionDefinition amoswapd_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amoswapd",
	(uint32_t) 0x800302f,
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

		partInit.code() = std::string("//AMOSWAPD\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4UL) + ";\n";
partInit.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32U) + "];\n";
if ((rd % 32U) != 0U) {
partInit.code() += "etiss_uint64 mem_val_0;\n";
partInit.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 8);\n";
partInit.code() += "if (cpu->exception) translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
partInit.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "] = (etiss_int64)(((etiss_int64)(mem_val_0)));\n";
}
partInit.code() += "etiss_uint64 mem_val_1 = (etiss_int64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "]);\n";
partInit.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 8);\n";
partInit.code() += "if (cpu->exception) translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
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
ss << "amoswapd" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOADDD ---------------------------------------------------------------------
static InstructionDefinition amoaddd_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amoaddd",
	(uint32_t) 0x00302f,
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

		partInit.code() = std::string("//AMOADDD\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4UL) + ";\n";
partInit.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32U) + "];\n";
partInit.code() += "etiss_uint64 mem_val_0;\n";
partInit.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 8);\n";
partInit.code() += "if (cpu->exception) translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
partInit.code() += "etiss_int64 res = mem_val_0;\n";
if ((rd % 32U) != 0U) {
partInit.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "] = res;\n";
}
partInit.code() += "etiss_uint64 res2 = res + *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "];\n";
partInit.code() += "etiss_uint64 mem_val_1 = res2;\n";
partInit.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 8);\n";
partInit.code() += "if (cpu->exception) translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
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
ss << "amoaddd" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOXORD ---------------------------------------------------------------------
static InstructionDefinition amoxord_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amoxord",
	(uint32_t) 0x2000302f,
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

		partInit.code() = std::string("//AMOXORD\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4UL) + ";\n";
partInit.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32U) + "];\n";
partInit.code() += "etiss_uint64 mem_val_0;\n";
partInit.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 8);\n";
partInit.code() += "if (cpu->exception) translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
partInit.code() += "etiss_int64 res = mem_val_0;\n";
if ((rd % 32U) != 0U) {
partInit.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "] = res;\n";
}
partInit.code() += "etiss_uint64 res2 = res ^ *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "];\n";
partInit.code() += "etiss_uint64 mem_val_1 = res2;\n";
partInit.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 8);\n";
partInit.code() += "if (cpu->exception) translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
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
ss << "amoxord" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOANDD ---------------------------------------------------------------------
static InstructionDefinition amoandd_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amoandd",
	(uint32_t) 0x6000302f,
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

		partInit.code() = std::string("//AMOANDD\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4UL) + ";\n";
partInit.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32U) + "];\n";
partInit.code() += "etiss_uint64 mem_val_0;\n";
partInit.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 8);\n";
partInit.code() += "if (cpu->exception) translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
partInit.code() += "etiss_int64 res = mem_val_0;\n";
if ((rd % 32U) != 0U) {
partInit.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "] = res;\n";
}
partInit.code() += "etiss_uint64 res2 = res & *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "];\n";
partInit.code() += "etiss_uint64 mem_val_1 = res2;\n";
partInit.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 8);\n";
partInit.code() += "if (cpu->exception) translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
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
ss << "amoandd" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOORD ----------------------------------------------------------------------
static InstructionDefinition amoord_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amoord",
	(uint32_t) 0x4000302f,
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

		partInit.code() = std::string("//AMOORD\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4UL) + ";\n";
partInit.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32U) + "];\n";
partInit.code() += "etiss_uint64 mem_val_0;\n";
partInit.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 8);\n";
partInit.code() += "if (cpu->exception) translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
partInit.code() += "etiss_int64 res = mem_val_0;\n";
if ((rd % 32U) != 0U) {
partInit.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "] = res;\n";
}
partInit.code() += "etiss_uint64 res2 = (((res) << 64) | (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "]));\n";
partInit.code() += "etiss_uint64 mem_val_1 = res2;\n";
partInit.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 8);\n";
partInit.code() += "if (cpu->exception) translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
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
ss << "amoord" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOMIND ---------------------------------------------------------------------
static InstructionDefinition amomind_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amomind",
	(uint32_t) 0x8000302f,
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

		partInit.code() = std::string("//AMOMIND\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4UL) + ";\n";
partInit.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32U) + "];\n";
partInit.code() += "etiss_uint64 mem_val_0;\n";
partInit.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 8);\n";
partInit.code() += "if (cpu->exception) translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
partInit.code() += "etiss_int64 res1 = mem_val_0;\n";
if ((rd % 32U) != 0U) {
partInit.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "] = res1;\n";
}
partInit.code() += "etiss_uint64 res2 = (res1 > (etiss_int64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "])) ? (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "]) : (res1);\n";
partInit.code() += "etiss_uint64 mem_val_1 = res2;\n";
partInit.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 8);\n";
partInit.code() += "if (cpu->exception) translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
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
ss << "amomind" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOMAXD ---------------------------------------------------------------------
static InstructionDefinition amomaxd_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amomaxd",
	(uint32_t) 0xa000302f,
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

		partInit.code() = std::string("//AMOMAXD\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4UL) + ";\n";
partInit.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32U) + "];\n";
partInit.code() += "etiss_uint64 mem_val_0;\n";
partInit.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 8);\n";
partInit.code() += "if (cpu->exception) translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
partInit.code() += "etiss_int64 res = mem_val_0;\n";
if ((rd % 32U) != 0U) {
partInit.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "] = res;\n";
}
partInit.code() += "etiss_uint64 res2 = (res < (etiss_int64)(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "])) ? (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "]) : (res);\n";
partInit.code() += "etiss_uint64 mem_val_1 = res2;\n";
partInit.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 8);\n";
partInit.code() += "if (cpu->exception) translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
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
ss << "amomaxd" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOMINUD --------------------------------------------------------------------
static InstructionDefinition amominud_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amominud",
	(uint32_t) 0xc000302f,
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

		partInit.code() = std::string("//AMOMINUD\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4UL) + ";\n";
partInit.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32U) + "];\n";
partInit.code() += "etiss_uint64 mem_val_0;\n";
partInit.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 8);\n";
partInit.code() += "if (cpu->exception) translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
partInit.code() += "etiss_uint64 res = mem_val_0;\n";
if ((rd % 32U) != 0U) {
partInit.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "] = (etiss_int64)(res);\n";
}
partInit.code() += "etiss_uint64 res2 = (res > *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "]) ? (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "]) : (res);\n";
partInit.code() += "etiss_uint64 mem_val_1 = res2;\n";
partInit.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 8);\n";
partInit.code() += "if (cpu->exception) translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
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
ss << "amominud" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOMAXUD --------------------------------------------------------------------
static InstructionDefinition amomaxud_rd_rs1_rs2_rl_aq (
	ISA32_RV64IMACFD,
	"amomaxud",
	(uint32_t) 0xe000302f,
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

		partInit.code() = std::string("//AMOMAXUD\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4UL) + ";\n";
partInit.code() += "etiss_uint64 offs = *((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32U) + "];\n";
partInit.code() += "etiss_uint64 mem_val_0;\n";
partInit.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 8);\n";
partInit.code() += "if (cpu->exception) translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
partInit.code() += "etiss_uint64 res1 = mem_val_0;\n";
if ((rd % 32U) != 0U) {
partInit.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "] = (etiss_int64)(res1);\n";
}
partInit.code() += "etiss_uint64 res2 = (res1 < *((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "]) ? (*((RV64IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "]) : (res1);\n";
partInit.code() += "etiss_uint64 mem_val_1 = res2;\n";
partInit.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 8);\n";
partInit.code() += "if (cpu->exception) translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
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
ss << "amomaxud" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
