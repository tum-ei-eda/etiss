/**
 * Generated on Tue, 15 Feb 2022 21:11:54 +0100.
 *
 * This file contains the instruction behavior models of the tum_ret
 * instruction set for the RV32IMCFD core architecture.
 */

#include "RV32IMCFDArch.h"

#define ETISS_ARCH_STATIC_FN_ONLY
#include "RV32IMCFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// URET ------------------------------------------------------------------------
static InstructionDefinition uret_ (
	ISA32_RV32IMCFD,
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
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
partInit.code() += "*((RV32IMCFD*)cpu)->CSR[" + std::to_string(3088) + "] = " + std::to_string(0) + ";\n";
partInit.code() += "*((RV32IMCFD*)cpu)->CSR[" + std::to_string(0) + "] = *((RV32IMCFD*)cpu)->CSR[" + std::to_string(0) + "] ^ ((*((RV32IMCFD*)cpu)->CSR[" + std::to_string(0) + "] & " + std::to_string(16) + ") >> " + std::to_string(4) + ") ^ (*((RV32IMCFD*)cpu)->CSR[" + std::to_string(0) + "] & " + std::to_string(1) + ");\n";
partInit.code() += "cpu->instructionPointer = *((RV32IMCFD*)cpu)->CSR[" + std::to_string(65) + "];\n";
partInit.code() += "*((RV32IMCFD*)cpu)->CSR[" + std::to_string(768) + "] = *((RV32IMCFD*)cpu)->CSR[" + std::to_string(0) + "];\n";
partInit.code() += "*((RV32IMCFD*)cpu)->CSR[" + std::to_string(256) + "] = *((RV32IMCFD*)cpu)->CSR[" + std::to_string(0) + "];\n";
partInit.code() += "return 0;\n";
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
	ISA32_RV32IMCFD,
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
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
partInit.code() += "*((RV32IMCFD*)cpu)->CSR[" + std::to_string(3088) + "] = (*((RV32IMCFD*)cpu)->CSR[" + std::to_string(256) + "] & " + std::to_string(256) + ") >> " + std::to_string(8) + ";\n";
partInit.code() += "*((RV32IMCFD*)cpu)->CSR[" + std::to_string(256) + "] = *((RV32IMCFD*)cpu)->CSR[" + std::to_string(256) + "] ^ (*((RV32IMCFD*)cpu)->CSR[" + std::to_string(256) + "] & " + std::to_string(256) + ");\n";
partInit.code() += "*((RV32IMCFD*)cpu)->CSR[" + std::to_string(256) + "] = *((RV32IMCFD*)cpu)->CSR[" + std::to_string(256) + "] ^ ((*((RV32IMCFD*)cpu)->CSR[" + std::to_string(256) + "] & " + std::to_string(32) + ") >> " + std::to_string(4) + ") ^ (*((RV32IMCFD*)cpu)->CSR[" + std::to_string(256) + "] & " + std::to_string(2) + ");\n";
partInit.code() += "cpu->instructionPointer = *((RV32IMCFD*)cpu)->CSR[" + std::to_string(321) + "];\n";
partInit.code() += "*((RV32IMCFD*)cpu)->CSR[" + std::to_string(768) + "] = *((RV32IMCFD*)cpu)->CSR[" + std::to_string(256) + "];\n";
partInit.code() += "*((RV32IMCFD*)cpu)->CSR[" + std::to_string(0) + "] = *((RV32IMCFD*)cpu)->CSR[" + std::to_string(256) + "];\n";
partInit.code() += "return 0;\n";
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
	ISA32_RV32IMCFD,
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
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4) + ";\n";
partInit.code() += "*((RV32IMCFD*)cpu)->CSR[" + std::to_string(3088) + "] = (*((RV32IMCFD*)cpu)->CSR[" + std::to_string(768) + "] & " + std::to_string(6144) + ") >> " + std::to_string(11) + ";\n";
partInit.code() += "*((RV32IMCFD*)cpu)->CSR[" + std::to_string(768) + "] = *((RV32IMCFD*)cpu)->CSR[" + std::to_string(768) + "] ^ (*((RV32IMCFD*)cpu)->CSR[" + std::to_string(768) + "] & " + std::to_string(6144) + ");\n";
partInit.code() += "*((RV32IMCFD*)cpu)->CSR[" + std::to_string(768) + "] = *((RV32IMCFD*)cpu)->CSR[" + std::to_string(768) + "] ^ ((*((RV32IMCFD*)cpu)->CSR[" + std::to_string(768) + "] & " + std::to_string(128) + ") >> " + std::to_string(4) + ") ^ (*((RV32IMCFD*)cpu)->CSR[" + std::to_string(768) + "] & " + std::to_string(8) + ");\n";
partInit.code() += "cpu->instructionPointer = *((RV32IMCFD*)cpu)->CSR[" + std::to_string(833) + "];\n";
partInit.code() += "*((RV32IMCFD*)cpu)->CSR[" + std::to_string(0) + "] = *((RV32IMCFD*)cpu)->CSR[" + std::to_string(768) + "];\n";
partInit.code() += "*((RV32IMCFD*)cpu)->CSR[" + std::to_string(256) + "] = *((RV32IMCFD*)cpu)->CSR[" + std::to_string(768) + "];\n";
partInit.code() += "return 0;\n";
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
