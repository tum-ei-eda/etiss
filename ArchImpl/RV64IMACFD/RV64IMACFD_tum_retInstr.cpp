// clang-format off
/**
 * Generated on Fri, 17 Apr 2026 10:56:08 +0200.
 *
 * This file contains the instruction behavior models of the tum_ret
 * instruction set for the RV64IMACFD core architecture.
 */

#include "RV64IMACFDArch.h"
#include "RV64IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// ECALL -----------------------------------------------------------------------
static InstructionDefinition ecall_ (
	ISA32_RV64IMACFD,
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
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6674);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_raise(cpu, system, plugin_pointers, 0LL, 8LL + ((RV64IMACFD*)cpu)->PRIV);\n";
cp.code() += "etiss_coverage_count(4, 6673, 6669, 6672, 6671);\n";
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
	ISA32_RV64IMACFD,
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
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6603);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 6530);\n";
cp.code() += "if (((RV64IMACFD*)cpu)->PRIV < 3LL) { // conditional\n";
cp.code() += "etiss_coverage_count(2, 6533, 6531);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_raise(cpu, system, plugin_pointers, 0LL, 2LL);\n";
cp.code() += "etiss_coverage_count(2, 6536, 6534);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "cpu->nextPc = *((RV64IMACFD*)cpu)->CSR[833LL];\n";
cp.code() += "etiss_coverage_count(3, 6541, 6537, 6540);\n";
cp.code() += "etiss_uint64 s = RV64IMACFD_csr_read(cpu, system, plugin_pointers, 768LL);\n";
cp.code() += "etiss_coverage_count(2, 6545, 6544);\n";
cp.code() += "etiss_uint64 prev_prv = (etiss_uint64)(RV64IMACFD_get_field(s, 6144LL));\n";
cp.code() += "etiss_coverage_count(4, 6552, 6551, 6549, 6547);\n";
cp.code() += "etiss_coverage_count(1, 6553);\n";
cp.code() += "if (prev_prv != 3LL) { // conditional\n";
cp.code() += "etiss_coverage_count(2, 6556, 6554);\n";
cp.code() += "s = (etiss_uint64)(RV64IMACFD_set_field(s, 131072LL, 0LL));\n";
cp.code() += "etiss_coverage_count(6, 6564, 6557, 6563, 6561, 6558, 6560);\n";
cp.code() += "} // conditional\n";
cp.code() += "s = (etiss_uint64)(RV64IMACFD_set_field(s, 8LL, RV64IMACFD_get_field(s, 128LL)));\n";
cp.code() += "etiss_coverage_count(7, 6574, 6565, 6573, 6571, 6566, 6570, 6568);\n";
cp.code() += "s = (etiss_uint64)(RV64IMACFD_set_field(s, 128LL, 1ULL));\n";
cp.code() += "etiss_coverage_count(6, 6582, 6575, 6581, 6579, 6576, 6578);\n";
cp.code() += "s = (etiss_uint64)(RV64IMACFD_set_field(s, 6144LL, (RV64IMACFD_extension_enabled(cpu, system, plugin_pointers, 85ULL)) ? (0LL) : (3LL)));\n";
cp.code() += "etiss_coverage_count(8, 6594, 6583, 6593, 6591, 6584, 6590, 6587, 6586);\n";
cp.code() += "RV64IMACFD_csr_write(cpu, system, plugin_pointers, 768LL, s);\n";
cp.code() += "etiss_coverage_count(2, 6597, 6596);\n";
cp.code() += "((RV64IMACFD*)cpu)->PRIV = ((etiss_uint8)(prev_prv)) & 0x7ULL;\n";
cp.code() += "etiss_coverage_count(4, 6602, 6598, 6601, 6599);\n";
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
	ISA32_RV64IMACFD,
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
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6675);\n";
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
	ISA32_RV64IMACFD,
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
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6668);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 6604);\n";
cp.code() += "if (((RV64IMACFD*)cpu)->PRIV < ((RV64IMACFD_get_field(RV64IMACFD_csr_read(cpu, system, plugin_pointers, 768LL), 4194304LL)) ? (3LL) : (1LL))) { // conditional\n";
cp.code() += "etiss_coverage_count(6, 6614, 6605, 6612, 6609, 6607, 6613);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_raise(cpu, system, plugin_pointers, 0LL, 2LL);\n";
cp.code() += "etiss_coverage_count(2, 6617, 6615);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "cpu->nextPc = *((RV64IMACFD*)cpu)->CSR[321LL];\n";
cp.code() += "etiss_coverage_count(3, 6622, 6618, 6621);\n";
cp.code() += "etiss_uint64 s = RV64IMACFD_csr_read(cpu, system, plugin_pointers, 256LL);\n";
cp.code() += "etiss_coverage_count(2, 6626, 6625);\n";
cp.code() += "etiss_uint64 prev_prv = (etiss_uint64)(RV64IMACFD_get_field(s, 256LL));\n";
cp.code() += "etiss_coverage_count(4, 6633, 6632, 6630, 6628);\n";
cp.code() += "s = (etiss_uint64)(RV64IMACFD_set_field(s, 2LL, RV64IMACFD_get_field(s, 32LL)));\n";
cp.code() += "etiss_coverage_count(7, 6643, 6634, 6642, 6640, 6635, 6639, 6637);\n";
cp.code() += "s = (etiss_uint64)(RV64IMACFD_set_field(s, 32LL, 1ULL));\n";
cp.code() += "etiss_coverage_count(6, 6651, 6644, 6650, 6648, 6645, 6647);\n";
cp.code() += "s = (etiss_uint64)(RV64IMACFD_set_field(s, 256LL, 0LL));\n";
cp.code() += "etiss_coverage_count(5, 6659, 6652, 6658, 6656, 6653);\n";
cp.code() += "RV64IMACFD_csr_write(cpu, system, plugin_pointers, 768LL, s);\n";
cp.code() += "etiss_coverage_count(2, 6662, 6661);\n";
cp.code() += "((RV64IMACFD*)cpu)->PRIV = ((etiss_uint8)(prev_prv)) & 0x7ULL;\n";
cp.code() += "etiss_coverage_count(4, 6667, 6663, 6666, 6664);\n";
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
