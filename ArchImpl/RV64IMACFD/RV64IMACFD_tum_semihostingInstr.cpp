/**
 * Generated on Wed, 16 Nov 2022 11:39:01 +0100.
 *
 * This file contains the instruction behavior models of the tum_semihosting
 * instruction set for the RV64IMACFD core architecture.
 */

#include "RV64IMACFDArch.h"

#define ETISS_ARCH_STATIC_FN_ONLY
#include "RV64IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// EBREAK ----------------------------------------------------------------------
static InstructionDefinition ebreak_ (
	ISA32_RV64IMACFD,
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
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4UL) + "U;\n";
partInit.code() += "if (etiss_semihost_enabled()) {\n";
partInit.code() += "etiss_uint32 mem_val_0;\n";
partInit.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, " + std::to_string(ic.current_address_ - 4UL) + "U, (etiss_uint8*)&mem_val_0, 4);\n";
partInit.code() += "if (cpu->exception) {\n";
partInit.code() += "translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
partInit.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
partInit.code() += "}\n";
partInit.code() += "etiss_uint32 pre = (etiss_uint32)(mem_val_0);\n";
partInit.code() += "etiss_uint32 mem_val_1;\n";
partInit.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, " + std::to_string(ic.current_address_ + 0UL) + "U, (etiss_uint8*)&mem_val_1, 4);\n";
partInit.code() += "if (cpu->exception) {\n";
partInit.code() += "translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
partInit.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
partInit.code() += "}\n";
partInit.code() += "etiss_uint32 ebreak = (etiss_uint32)(mem_val_1);\n";
partInit.code() += "etiss_uint32 mem_val_2;\n";
partInit.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, " + std::to_string(ic.current_address_ + 4UL) + "U, (etiss_uint8*)&mem_val_2, 4);\n";
partInit.code() += "if (cpu->exception) {\n";
partInit.code() += "translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
partInit.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
partInit.code() += "}\n";
partInit.code() += "etiss_uint32 post = (etiss_uint32)(mem_val_2);\n";
partInit.code() += "if (pre == 32509971U && ebreak == 1048691U && post == 1081102355U) {\n";
partInit.code() += "etiss_uint64 operation = *((RV64IMACFD*)cpu)->X[10U];\n";
partInit.code() += "etiss_uint64 parameter = *((RV64IMACFD*)cpu)->X[11U];\n";
partInit.code() += "*((RV64IMACFD*)cpu)->X[10U] = (etiss_int64)(etiss_semihost(cpu, system, plugin_pointers, " + std::to_string(64) + "U, operation, parameter));\n";
partInit.code() += "}\n";
partInit.code() += "else {\n";
partInit.code() += "cpu->exception = 0; raise(cpu, system, plugin_pointers, 0U, " + std::to_string(3) + "U);\n";
partInit.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
partInit.code() += "}\n";
partInit.code() += "}\n";
partInit.code() += "else {\n";
partInit.code() += "cpu->exception = 0; raise(cpu, system, plugin_pointers, 0U, " + std::to_string(3) + "U);\n";
partInit.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
partInit.code() += "}\n";
partInit.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
partInit.code() += "cpu->instructionPointer = cpu->nextPc;\n";
partInit.code() += "if (cpu->return_pending | cpu->nextPc != " + std::to_string(ic.current_address_ + 4) + ") return cpu->exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[10U], 64);
		partInit.getRegisterDependencies().add(reg_name[11U], 64);
		partInit.getAffectedRegisters().add(reg_name[10U], 64);
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
