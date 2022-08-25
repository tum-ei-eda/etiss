/**
 * Generated on Thu, 25 Aug 2022 14:20:44 +0200.
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
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[3088U] = (*((RV32IMACFD*)cpu)->CSR[768] & 6144U) >> 11U;\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[768] = *((RV32IMACFD*)cpu)->CSR[768] ^ (*((RV32IMACFD*)cpu)->CSR[768] & 6144U);\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[768] = *((RV32IMACFD*)cpu)->CSR[768] ^ ((*((RV32IMACFD*)cpu)->CSR[768] & 128U) >> 4U) ^ (*((RV32IMACFD*)cpu)->CSR[768] & 8U);\n";
partInit.code() += "cpu->nextPc = *((RV32IMACFD*)cpu)->CSR[833];\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[0U] = *((RV32IMACFD*)cpu)->CSR[768];\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[" + std::to_string(256) + "] = *((RV32IMACFD*)cpu)->CSR[768];\n";
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
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[3088U] = 0U;\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[0U] = *((RV32IMACFD*)cpu)->CSR[0U] ^ ((*((RV32IMACFD*)cpu)->CSR[0U] & 16U) >> 4U) ^ (*((RV32IMACFD*)cpu)->CSR[0U] & 1U);\n";
partInit.code() += "cpu->nextPc = *((RV32IMACFD*)cpu)->CSR[65U];\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[" + std::to_string(768) + "] = *((RV32IMACFD*)cpu)->CSR[0U];\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[" + std::to_string(256) + "] = *((RV32IMACFD*)cpu)->CSR[0U];\n";
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
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[3088U] = (*((RV32IMACFD*)cpu)->CSR[256] & 256U) >> 8U;\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[256] = *((RV32IMACFD*)cpu)->CSR[256] ^ (*((RV32IMACFD*)cpu)->CSR[256] & 256U);\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[256] = *((RV32IMACFD*)cpu)->CSR[256] ^ ((*((RV32IMACFD*)cpu)->CSR[256] & 32U) >> 4U) ^ (*((RV32IMACFD*)cpu)->CSR[256] & 2U);\n";
partInit.code() += "cpu->nextPc = *((RV32IMACFD*)cpu)->CSR[321];\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[" + std::to_string(768) + "] = *((RV32IMACFD*)cpu)->CSR[256];\n";
partInit.code() += "*((RV32IMACFD*)cpu)->CSR[0U] = *((RV32IMACFD*)cpu)->CSR[256];\n";
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
ss << "sret" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
