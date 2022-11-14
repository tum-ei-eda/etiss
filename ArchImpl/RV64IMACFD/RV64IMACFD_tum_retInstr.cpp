/**
 * Generated on Mon, 14 Nov 2022 16:47:27 +0100.
 *
 * This file contains the instruction behavior models of the tum_ret
 * instruction set for the RV64IMACFD core architecture.
 */

#include "RV64IMACFDArch.h"

#define ETISS_ARCH_STATIC_FN_ONLY
#include "RV64IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// MRET ------------------------------------------------------------------------
static InstructionDefinition mret_ (
	ISA32_RV64IMACFD,
	"mret",
	(uint32_t) 0x30200073,
	(uint32_t) 0xffffffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//MRET\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4UL) + "U;\n";
partInit.code() += "cpu->nextPc = *((RV64IMACFD*)cpu)->CSR[833];\n";
partInit.code() += "etiss_uint64 s = *((RV64IMACFD*)cpu)->CSR[768];\n";
partInit.code() += "etiss_uint64 prev_prv = get_field(s, " + std::to_string(6144) + "U);\n";
partInit.code() += "if (prev_prv != 3L) {\n";
partInit.code() += "s = set_field(s, " + std::to_string(131072) + "U, 0U);\n";
partInit.code() += "}\n";
partInit.code() += "s = set_field(s, " + std::to_string(8) + "U, get_field(s, " + std::to_string(128) + "U));\n";
partInit.code() += "s = set_field(s, " + std::to_string(128) + "U, 1U);\n";
partInit.code() += "s = set_field(s, " + std::to_string(6144) + "U, " + std::to_string(3) + "U);\n";
partInit.code() += "*((RV64IMACFD*)cpu)->CSR[" + std::to_string(768) + "U] = s;\n";
partInit.code() += "((RV64IMACFD*)cpu)->PRIV = (prev_prv) & 0x7;\n";
partInit.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
partInit.code() += "cpu->instructionPointer = cpu->nextPc;\n";
partInit.code() += "return cpu->exception;\n";
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
ss << "mret" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
