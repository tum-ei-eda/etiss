// clang-format off
/**
 * Generated on Fri, 17 Apr 2026 09:57:47 +0200.
 *
 * This file contains the instruction behavior models of the tum_ret
 * instruction set for the RV32IMACFD core architecture.
 */

#include "RV32IMACFDArch.h"
#include "RV32IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// ECALL -----------------------------------------------------------------------
static InstructionDefinition ecall_ (
	ISA32_RV32IMACFD,
	"ecall",
	(uint32_t) 0x000073,
	(uint32_t) 0xffffffff,
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
cp.code() += "etiss_coverage_count(1, 168);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6605);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_raise(cpu, system, plugin_pointers, 0LL, 8LL + ((RV32IMACFD*)cpu)->PRIV);\n";
cp.code() += "etiss_coverage_count(4, 6604, 6600, 6603, 6602);\n";
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
	ISA32_RV32IMACFD,
	"mret",
	(uint32_t) 0x30200073,
	(uint32_t) 0xffffffff,
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
cp.code() += "etiss_coverage_count(1, 166);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6534);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 6461);\n";
cp.code() += "if (((RV32IMACFD*)cpu)->PRIV < 3LL) { // conditional\n";
cp.code() += "etiss_coverage_count(2, 6464, 6462);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_raise(cpu, system, plugin_pointers, 0LL, 2LL);\n";
cp.code() += "etiss_coverage_count(2, 6467, 6465);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "cpu->nextPc = *((RV32IMACFD*)cpu)->CSR[833LL];\n";
cp.code() += "etiss_coverage_count(3, 6472, 6468, 6471);\n";
cp.code() += "etiss_uint32 s = RV32IMACFD_csr_read(cpu, system, plugin_pointers, 768LL);\n";
cp.code() += "etiss_coverage_count(2, 6476, 6475);\n";
cp.code() += "etiss_uint32 prev_prv = (etiss_uint32)(RV32IMACFD_get_field(s, 6144LL));\n";
cp.code() += "etiss_coverage_count(4, 6483, 6482, 6480, 6478);\n";
cp.code() += "etiss_coverage_count(1, 6484);\n";
cp.code() += "if (prev_prv != 3LL) { // conditional\n";
cp.code() += "etiss_coverage_count(2, 6487, 6485);\n";
cp.code() += "s = (etiss_uint32)(RV32IMACFD_set_field(s, 131072LL, 0LL));\n";
cp.code() += "etiss_coverage_count(6, 6495, 6488, 6494, 6492, 6489, 6491);\n";
cp.code() += "} // conditional\n";
cp.code() += "s = (etiss_uint32)(RV32IMACFD_set_field(s, 8LL, RV32IMACFD_get_field(s, 128LL)));\n";
cp.code() += "etiss_coverage_count(7, 6505, 6496, 6504, 6502, 6497, 6501, 6499);\n";
cp.code() += "s = (etiss_uint32)(RV32IMACFD_set_field(s, 128LL, 1ULL));\n";
cp.code() += "etiss_coverage_count(6, 6513, 6506, 6512, 6510, 6507, 6509);\n";
cp.code() += "s = (etiss_uint32)(RV32IMACFD_set_field(s, 6144LL, (RV32IMACFD_extension_enabled(cpu, system, plugin_pointers, 85ULL)) ? (0LL) : (3LL)));\n";
cp.code() += "etiss_coverage_count(8, 6525, 6514, 6524, 6522, 6515, 6521, 6518, 6517);\n";
cp.code() += "RV32IMACFD_csr_write(cpu, system, plugin_pointers, 768LL, s);\n";
cp.code() += "etiss_coverage_count(2, 6528, 6527);\n";
cp.code() += "((RV32IMACFD*)cpu)->PRIV = ((etiss_uint8)(prev_prv)) & 0x7ULL;\n";
cp.code() += "etiss_coverage_count(4, 6533, 6529, 6532, 6530);\n";
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
	ISA32_RV32IMACFD,
	"wfi",
	(uint32_t) 0x10500073,
	(uint32_t) 0xffffffff,
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
cp.code() += "etiss_coverage_count(1, 169);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6606);\n";
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
	ISA32_RV32IMACFD,
	"sret",
	(uint32_t) 0x10200073,
	(uint32_t) 0xffffffff,
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
cp.code() += "etiss_coverage_count(1, 167);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6599);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 6535);\n";
cp.code() += "if (((RV32IMACFD*)cpu)->PRIV < ((RV32IMACFD_get_field(RV32IMACFD_csr_read(cpu, system, plugin_pointers, 768LL), 4194304LL)) ? (3LL) : (1LL))) { // conditional\n";
cp.code() += "etiss_coverage_count(6, 6545, 6536, 6543, 6540, 6538, 6544);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_raise(cpu, system, plugin_pointers, 0LL, 2LL);\n";
cp.code() += "etiss_coverage_count(2, 6548, 6546);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "cpu->nextPc = *((RV32IMACFD*)cpu)->CSR[321LL];\n";
cp.code() += "etiss_coverage_count(3, 6553, 6549, 6552);\n";
cp.code() += "etiss_uint32 s = RV32IMACFD_csr_read(cpu, system, plugin_pointers, 256LL);\n";
cp.code() += "etiss_coverage_count(2, 6557, 6556);\n";
cp.code() += "etiss_uint32 prev_prv = (etiss_uint32)(RV32IMACFD_get_field(s, 256LL));\n";
cp.code() += "etiss_coverage_count(4, 6564, 6563, 6561, 6559);\n";
cp.code() += "s = (etiss_uint32)(RV32IMACFD_set_field(s, 2LL, RV32IMACFD_get_field(s, 32LL)));\n";
cp.code() += "etiss_coverage_count(7, 6574, 6565, 6573, 6571, 6566, 6570, 6568);\n";
cp.code() += "s = (etiss_uint32)(RV32IMACFD_set_field(s, 32LL, 1ULL));\n";
cp.code() += "etiss_coverage_count(6, 6582, 6575, 6581, 6579, 6576, 6578);\n";
cp.code() += "s = (etiss_uint32)(RV32IMACFD_set_field(s, 256LL, 0LL));\n";
cp.code() += "etiss_coverage_count(5, 6590, 6583, 6589, 6587, 6584);\n";
cp.code() += "RV32IMACFD_csr_write(cpu, system, plugin_pointers, 768LL, s);\n";
cp.code() += "etiss_coverage_count(2, 6593, 6592);\n";
cp.code() += "((RV32IMACFD*)cpu)->PRIV = ((etiss_uint8)(prev_prv)) & 0x7ULL;\n";
cp.code() += "etiss_coverage_count(4, 6598, 6594, 6597, 6595);\n";
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
