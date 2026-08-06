// clang-format off
/**
 * Generated on Wed, 05 Aug 2026 14:56:03 +0200.
 *
 * This file contains the instruction behavior models of the tum_ret
 * instruction set for the RV32IMXCoreV core architecture.
 */

#include "RV32IMXCoreVArch.h"
#include "RV32IMXCoreVFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// ECALL -----------------------------------------------------------------------
static InstructionDefinition ecall_ (
	ISA32_RV32IMXCoreV,
	"ecall",
	(uint64_t) 0x000073,
	(uint64_t) 0xffffffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//ECALL\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 482);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27541);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_raise(cpu, system, plugin_pointers, 0LL, 8ULL + ((RV32IMXCoreV*)cpu)->PRIV);\n";
cp.code() += "etiss_coverage_count(4, 27540, 27536, 27539, 27538);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//ECALL\n");

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
ss << "ecall" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// MRET ------------------------------------------------------------------------
static InstructionDefinition mret_ (
	ISA32_RV32IMXCoreV,
	"mret",
	(uint64_t) 0x30200073,
	(uint64_t) 0xffffffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//MRET\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 480);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27470);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 27397);\n";
cp.code() += "if (((RV32IMXCoreV*)cpu)->PRIV < 3ULL) { // conditional\n";
cp.code() += "etiss_coverage_count(2, 27400, 27398);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(2, 27403, 27401);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "cpu->nextPc = *((RV32IMXCoreV*)cpu)->CSR[833ULL];\n";
cp.code() += "etiss_coverage_count(3, 27408, 27404, 27407);\n";
cp.code() += "etiss_uint32 s = RV32IMXCoreV_csr_read(cpu, system, plugin_pointers, 768ULL);\n";
cp.code() += "etiss_coverage_count(2, 27412, 27411);\n";
cp.code() += "etiss_uint32 prev_prv = (etiss_uint32)(RV32IMXCoreV_get_field(s, 6144ULL));\n";
cp.code() += "etiss_coverage_count(4, 27419, 27418, 27416, 27414);\n";
cp.code() += "etiss_coverage_count(1, 27420);\n";
cp.code() += "if (prev_prv != 3ULL) { // conditional\n";
cp.code() += "etiss_coverage_count(2, 27423, 27421);\n";
cp.code() += "s = (etiss_uint32)(RV32IMXCoreV_set_field(s, 131072ULL, 0LL));\n";
cp.code() += "etiss_coverage_count(6, 27431, 27424, 27430, 27428, 27425, 27427);\n";
cp.code() += "} // conditional\n";
cp.code() += "s = (etiss_uint32)(RV32IMXCoreV_set_field(s, 8ULL, RV32IMXCoreV_get_field(s, 128ULL)));\n";
cp.code() += "etiss_coverage_count(7, 27441, 27432, 27440, 27438, 27433, 27437, 27435);\n";
cp.code() += "s = (etiss_uint32)(RV32IMXCoreV_set_field(s, 128ULL, 1ULL));\n";
cp.code() += "etiss_coverage_count(6, 27449, 27442, 27448, 27446, 27443, 27445);\n";
cp.code() += "s = (etiss_uint32)(RV32IMXCoreV_set_field(s, 6144ULL, (RV32IMXCoreV_extension_enabled(cpu, system, plugin_pointers, 85ULL)) ? (0LL) : (3ULL)));\n";
cp.code() += "etiss_coverage_count(8, 27461, 27450, 27460, 27458, 27451, 27457, 27454, 27453);\n";
cp.code() += "RV32IMXCoreV_csr_write(cpu, system, plugin_pointers, 768ULL, s);\n";
cp.code() += "etiss_coverage_count(2, 27464, 27463);\n";
cp.code() += "((RV32IMXCoreV*)cpu)->PRIV = ((etiss_uint8)(prev_prv)) & 0x7ULL;\n";
cp.code() += "etiss_coverage_count(4, 27469, 27465, 27468, 27466);\n";
cp.code() += "} // block\n";
} // block
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

// WFI -------------------------------------------------------------------------
static InstructionDefinition wfi_ (
	ISA32_RV32IMXCoreV,
	"wfi",
	(uint64_t) 0x10500073,
	(uint64_t) 0xffffffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//WFI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 483);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27542);\n";
cp.code() += "{ // block\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//WFI\n");

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
ss << "wfi" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SRET ------------------------------------------------------------------------
static InstructionDefinition sret_ (
	ISA32_RV32IMXCoreV,
	"sret",
	(uint64_t) 0x10200073,
	(uint64_t) 0xffffffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SRET\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 481);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27535);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 27471);\n";
cp.code() += "if (((RV32IMXCoreV*)cpu)->PRIV < ((RV32IMXCoreV_get_field(RV32IMXCoreV_csr_read(cpu, system, plugin_pointers, 768ULL), 4194304ULL)) ? (3ULL) : (1ULL))) { // conditional\n";
cp.code() += "etiss_coverage_count(6, 27481, 27472, 27479, 27476, 27474, 27480);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(2, 27484, 27482);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "cpu->nextPc = *((RV32IMXCoreV*)cpu)->CSR[321ULL];\n";
cp.code() += "etiss_coverage_count(3, 27489, 27485, 27488);\n";
cp.code() += "etiss_uint32 s = RV32IMXCoreV_csr_read(cpu, system, plugin_pointers, 256ULL);\n";
cp.code() += "etiss_coverage_count(2, 27493, 27492);\n";
cp.code() += "etiss_uint32 prev_prv = (etiss_uint32)(RV32IMXCoreV_get_field(s, 256ULL));\n";
cp.code() += "etiss_coverage_count(4, 27500, 27499, 27497, 27495);\n";
cp.code() += "s = (etiss_uint32)(RV32IMXCoreV_set_field(s, 2ULL, RV32IMXCoreV_get_field(s, 32ULL)));\n";
cp.code() += "etiss_coverage_count(7, 27510, 27501, 27509, 27507, 27502, 27506, 27504);\n";
cp.code() += "s = (etiss_uint32)(RV32IMXCoreV_set_field(s, 32ULL, 1ULL));\n";
cp.code() += "etiss_coverage_count(6, 27518, 27511, 27517, 27515, 27512, 27514);\n";
cp.code() += "s = (etiss_uint32)(RV32IMXCoreV_set_field(s, 256ULL, 0LL));\n";
cp.code() += "etiss_coverage_count(5, 27526, 27519, 27525, 27523, 27520);\n";
cp.code() += "RV32IMXCoreV_csr_write(cpu, system, plugin_pointers, 768ULL, s);\n";
cp.code() += "etiss_coverage_count(2, 27529, 27528);\n";
cp.code() += "((RV32IMXCoreV*)cpu)->PRIV = ((etiss_uint8)(prev_prv)) & 0x7ULL;\n";
cp.code() += "etiss_coverage_count(4, 27534, 27530, 27533, 27531);\n";
cp.code() += "} // block\n";
} // block
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
// clang-format on
