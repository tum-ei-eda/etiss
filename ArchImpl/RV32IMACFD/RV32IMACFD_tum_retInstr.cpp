/**
 * Generated on Thu, 03 Mar 2022 12:13:52 +0100.
 *
 * This file contains the instruction behavior models of the tum_ret
 * instruction set for the RV32IMACFD core architecture.
 */

#include "RV32IMACFDArch.h"

#define ETISS_ARCH_STATIC_FN_ONLY
#include "RV32IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// URET ------------------------------------------------------------------------
static InstructionDefinition uret_ (
	ISA32_RV32IMACFD,
	"uret",
	(uint32_t) 0x200073,
	(uint32_t) 0xffffffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//URET\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[" + std::to_string(3088U) + "] = 0U;\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[" + std::to_string(0U) + "] = *((RV32IMACFD*)cpu)->CSR[" + std::to_string(0U) + "] ^ ((*((RV32IMACFD*)cpu)->CSR[" + std::to_string(0U) + "] & 16U) >> 4U) ^ (*((RV32IMACFD*)cpu)->CSR[" + std::to_string(0U) + "] & 1U);\n";
partInit.code() += "cpu->instructionPointer = *((RV32IMACFD*)cpu)->CSR[" + std::to_string(65U) + "];\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[" + std::to_string(768U) + "] = *((RV32IMACFD*)cpu)->CSR[" + std::to_string(0U) + "];\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[" + std::to_string(256U) + "] = *((RV32IMACFD*)cpu)->CSR[" + std::to_string(0U) + "];\n";
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
ss << "uret" << " # " << ba << (" []");
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

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//SRET\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[" + std::to_string(3088U) + "] = (*((RV32IMACFD*)cpu)->CSR[" + std::to_string(256U) + "] & 256U) >> 8U;\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[" + std::to_string(256U) + "] = *((RV32IMACFD*)cpu)->CSR[" + std::to_string(256U) + "] ^ (*((RV32IMACFD*)cpu)->CSR[" + std::to_string(256U) + "] & 256U);\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[" + std::to_string(256U) + "] = *((RV32IMACFD*)cpu)->CSR[" + std::to_string(256U) + "] ^ ((*((RV32IMACFD*)cpu)->CSR[" + std::to_string(256U) + "] & 32U) >> 4U) ^ (*((RV32IMACFD*)cpu)->CSR[" + std::to_string(256U) + "] & 2U);\n";
partInit.code() += "cpu->instructionPointer = *((RV32IMACFD*)cpu)->CSR[" + std::to_string(321U) + "];\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[" + std::to_string(768U) + "] = *((RV32IMACFD*)cpu)->CSR[" + std::to_string(256U) + "];\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[" + std::to_string(0U) + "] = *((RV32IMACFD*)cpu)->CSR[" + std::to_string(256U) + "];\n";
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
ss << "sret" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

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
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[" + std::to_string(3088U) + "] = (*((RV32IMACFD*)cpu)->CSR[" + std::to_string(768U) + "] & 6144U) >> 11U;\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[" + std::to_string(768U) + "] = *((RV32IMACFD*)cpu)->CSR[" + std::to_string(768U) + "] ^ (*((RV32IMACFD*)cpu)->CSR[" + std::to_string(768U) + "] & 6144U);\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[" + std::to_string(768U) + "] = *((RV32IMACFD*)cpu)->CSR[" + std::to_string(768U) + "] ^ ((*((RV32IMACFD*)cpu)->CSR[" + std::to_string(768U) + "] & 128U) >> 4U) ^ (*((RV32IMACFD*)cpu)->CSR[" + std::to_string(768U) + "] & 8U);\n";
partInit.code() += "cpu->instructionPointer = *((RV32IMACFD*)cpu)->CSR[" + std::to_string(833U) + "];\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[" + std::to_string(0U) + "] = *((RV32IMACFD*)cpu)->CSR[" + std::to_string(768U) + "];\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[" + std::to_string(256U) + "] = *((RV32IMACFD*)cpu)->CSR[" + std::to_string(768U) + "];\n";
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
ss << "mret" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
