/**
 * Generated on Tue, 07 Feb 2023 18:20:18 +0100.
 *
 * This file contains the instruction behavior models of the tum_ret
 * instruction set for the RV32IMACFD core architecture.
 */

#include "RV32IMACFDArch.h"

#define ETISS_ARCH_STATIC_FN_ONLY
#include "RV32IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// MRET ------------------------------------------------------------------------
static InstructionDefinition mret_ (
	ISA32_RV32IMACFD,
	"mret",
	(uint32_t) 0x30200073,
	(uint32_t) 0xffffffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//MRET\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4U) + "U;\n";
cp.code() += "if (((RV32IMACFD*)cpu)->PRIV < 3) {\n";
cp.code() += "cpu->exception = 0; raise(cpu, system, plugin_pointers, 0U, 2);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "}\n";
cp.code() += "cpu->nextPc = *((RV32IMACFD*)cpu)->CSR[833];\n";
cp.code() += "etiss_uint32 s = *((RV32IMACFD*)cpu)->CSR[768];\n";
cp.code() += "etiss_uint32 prev_prv = get_field(s, 6144);\n";
cp.code() += "if (prev_prv != 3) {\n";
cp.code() += "s = set_field(s, 131072, 0U);\n";
cp.code() += "}\n";
cp.code() += "s = set_field(s, 8, get_field(s, 128));\n";
cp.code() += "s = set_field(s, 128, 1U);\n";
cp.code() += "s = set_field(s, 6144, (extension_enabled(cpu, system, plugin_pointers, 85U)) ? (0) : (3));\n";
cp.code() += "*((RV32IMACFD*)cpu)->CSR[768] = s;\n";
cp.code() += "((RV32IMACFD*)cpu)->PRIV = (prev_prv) & 0x7;\n";
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//MRET\n");

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

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "mret" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SRET ------------------------------------------------------------------------
static InstructionDefinition sret_ (
	ISA32_RV32IMACFD,
	"sret",
	(uint32_t) 0x10200073,
	(uint32_t) 0xffffffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SRET\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4U) + "U;\n";
cp.code() += "if (((RV32IMACFD*)cpu)->PRIV < ((get_field(*((RV32IMACFD*)cpu)->CSR[768], 4194304)) ? (3) : (1))) {\n";
cp.code() += "cpu->exception = 0; raise(cpu, system, plugin_pointers, 0U, 2);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "}\n";
cp.code() += "cpu->nextPc = *((RV32IMACFD*)cpu)->CSR[321];\n";
cp.code() += "etiss_uint32 s = *((RV32IMACFD*)cpu)->CSR[256];\n";
cp.code() += "etiss_uint32 prev_prv = get_field(s, 256);\n";
cp.code() += "s = set_field(s, 2, get_field(s, 32));\n";
cp.code() += "s = set_field(s, 32, 1U);\n";
cp.code() += "s = set_field(s, 256, 0);\n";
cp.code() += "*((RV32IMACFD*)cpu)->CSR[768] = s;\n";
cp.code() += "((RV32IMACFD*)cpu)->PRIV = (prev_prv) & 0x7;\n";
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//SRET\n");

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

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "sret" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
