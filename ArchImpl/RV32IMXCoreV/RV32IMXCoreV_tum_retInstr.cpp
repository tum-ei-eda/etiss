// clang-format off
/**
 * Generated on Wed, 05 Aug 2026 14:25:16 +0200.
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
cp.code() += "etiss_coverage_count(1, 27539);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_raise(cpu, system, plugin_pointers, 0LL, 8ULL + ((RV32IMXCoreV*)cpu)->PRIV);\n";
cp.code() += "etiss_coverage_count(4, 27538, 27534, 27537, 27536);\n";
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
cp.code() += "etiss_coverage_count(1, 27468);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 27395);\n";
cp.code() += "if (((RV32IMXCoreV*)cpu)->PRIV < 3ULL) { // conditional\n";
cp.code() += "etiss_coverage_count(2, 27398, 27396);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(2, 27401, 27399);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "cpu->nextPc = *((RV32IMXCoreV*)cpu)->CSR[833ULL];\n";
cp.code() += "etiss_coverage_count(3, 27406, 27402, 27405);\n";
cp.code() += "etiss_uint32 s = RV32IMXCoreV_csr_read(cpu, system, plugin_pointers, 768ULL);\n";
cp.code() += "etiss_coverage_count(2, 27410, 27409);\n";
cp.code() += "etiss_uint32 prev_prv = (etiss_uint32)(RV32IMXCoreV_get_field(s, 6144ULL));\n";
cp.code() += "etiss_coverage_count(4, 27417, 27416, 27414, 27412);\n";
cp.code() += "etiss_coverage_count(1, 27418);\n";
cp.code() += "if (prev_prv != 3ULL) { // conditional\n";
cp.code() += "etiss_coverage_count(2, 27421, 27419);\n";
cp.code() += "s = (etiss_uint32)(RV32IMXCoreV_set_field(s, 131072ULL, 0LL));\n";
cp.code() += "etiss_coverage_count(6, 27429, 27422, 27428, 27426, 27423, 27425);\n";
cp.code() += "} // conditional\n";
cp.code() += "s = (etiss_uint32)(RV32IMXCoreV_set_field(s, 8ULL, RV32IMXCoreV_get_field(s, 128ULL)));\n";
cp.code() += "etiss_coverage_count(7, 27439, 27430, 27438, 27436, 27431, 27435, 27433);\n";
cp.code() += "s = (etiss_uint32)(RV32IMXCoreV_set_field(s, 128ULL, 1ULL));\n";
cp.code() += "etiss_coverage_count(6, 27447, 27440, 27446, 27444, 27441, 27443);\n";
cp.code() += "s = (etiss_uint32)(RV32IMXCoreV_set_field(s, 6144ULL, (RV32IMXCoreV_extension_enabled(cpu, system, plugin_pointers, 85ULL)) ? (0LL) : (3ULL)));\n";
cp.code() += "etiss_coverage_count(8, 27459, 27448, 27458, 27456, 27449, 27455, 27452, 27451);\n";
cp.code() += "RV32IMXCoreV_csr_write(cpu, system, plugin_pointers, 768ULL, s);\n";
cp.code() += "etiss_coverage_count(2, 27462, 27461);\n";
cp.code() += "((RV32IMXCoreV*)cpu)->PRIV = ((etiss_uint8)(prev_prv)) & 0x7ULL;\n";
cp.code() += "etiss_coverage_count(4, 27467, 27463, 27466, 27464);\n";
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
cp.code() += "etiss_coverage_count(1, 27540);\n";
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
cp.code() += "etiss_coverage_count(1, 27533);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 27469);\n";
cp.code() += "if (((RV32IMXCoreV*)cpu)->PRIV < ((RV32IMXCoreV_get_field(RV32IMXCoreV_csr_read(cpu, system, plugin_pointers, 768ULL), 4194304ULL)) ? (3ULL) : (1ULL))) { // conditional\n";
cp.code() += "etiss_coverage_count(6, 27479, 27470, 27477, 27474, 27472, 27478);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(2, 27482, 27480);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "cpu->nextPc = *((RV32IMXCoreV*)cpu)->CSR[321ULL];\n";
cp.code() += "etiss_coverage_count(3, 27487, 27483, 27486);\n";
cp.code() += "etiss_uint32 s = RV32IMXCoreV_csr_read(cpu, system, plugin_pointers, 256ULL);\n";
cp.code() += "etiss_coverage_count(2, 27491, 27490);\n";
cp.code() += "etiss_uint32 prev_prv = (etiss_uint32)(RV32IMXCoreV_get_field(s, 256ULL));\n";
cp.code() += "etiss_coverage_count(4, 27498, 27497, 27495, 27493);\n";
cp.code() += "s = (etiss_uint32)(RV32IMXCoreV_set_field(s, 2ULL, RV32IMXCoreV_get_field(s, 32ULL)));\n";
cp.code() += "etiss_coverage_count(7, 27508, 27499, 27507, 27505, 27500, 27504, 27502);\n";
cp.code() += "s = (etiss_uint32)(RV32IMXCoreV_set_field(s, 32ULL, 1ULL));\n";
cp.code() += "etiss_coverage_count(6, 27516, 27509, 27515, 27513, 27510, 27512);\n";
cp.code() += "s = (etiss_uint32)(RV32IMXCoreV_set_field(s, 256ULL, 0LL));\n";
cp.code() += "etiss_coverage_count(5, 27524, 27517, 27523, 27521, 27518);\n";
cp.code() += "RV32IMXCoreV_csr_write(cpu, system, plugin_pointers, 768ULL, s);\n";
cp.code() += "etiss_coverage_count(2, 27527, 27526);\n";
cp.code() += "((RV32IMXCoreV*)cpu)->PRIV = ((etiss_uint8)(prev_prv)) & 0x7ULL;\n";
cp.code() += "etiss_coverage_count(4, 27532, 27528, 27531, 27529);\n";
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
