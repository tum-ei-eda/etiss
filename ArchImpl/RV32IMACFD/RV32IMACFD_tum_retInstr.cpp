/**
 * Generated on Wed, 12 Oct 2022 12:21:19 +0200.
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//MRET\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "cpu->nextPc = *((RV32IMACFD*)cpu)->CSR[833];\n";
partInit.code() += "etiss_uint32 s = *((RV32IMACFD*)cpu)->CSR[768];\n";
partInit.code() += "etiss_uint32 prev_prv = get_field(s, " + std::to_string(6144) + ");\n";
partInit.code() += "if (prev_prv != 3) {\n";
partInit.code() += "s = set_field(s, " + std::to_string(131072) + ", 0U);\n";
partInit.code() += "}\n";
partInit.code() += "s = set_field(s, " + std::to_string(8) + ", get_field(s, " + std::to_string(128) + "));\n";
partInit.code() += "s = set_field(s, " + std::to_string(128) + ", 1U);\n";
partInit.code() += "s = set_field(s, " + std::to_string(6144) + ", " + std::to_string(3) + ");\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[" + std::to_string(768) + "] = s;\n";
partInit.code() += "((RV32IMACFD*)cpu)->PRIV = (prev_prv) & 0x7;\n";
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
