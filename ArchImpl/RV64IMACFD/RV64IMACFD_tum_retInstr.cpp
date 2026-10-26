// clang-format off
/**
 * Generated on Mon, 26 Oct 2026 08:39:20 +0000.
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
cp.code() += "etiss_coverage_count(1, 168);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7433);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_raise(cpu, system, plugin_pointers, 0LL, (etiss_uint32)((8ULL + ((RV64IMACFD*)cpu)->PRIV)));\n";
cp.code() += "etiss_coverage_count(6, 7432, 7425, 7431, 7428, 7427, 7429);\n";
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
cp.code() += "etiss_coverage_count(1, 166);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7359);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7283);\n";
cp.code() += "if (((RV64IMACFD*)cpu)->PRIV < 3ULL) { // conditional\n";
cp.code() += "etiss_coverage_count(2, 7286, 7284);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(2, 7289, 7287);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "cpu->nextPc = *((RV64IMACFD*)cpu)->CSR[833ULL];\n";
cp.code() += "etiss_coverage_count(3, 7294, 7290, 7293);\n";
cp.code() += "etiss_uint64 s = RV64IMACFD_csr_read(cpu, system, plugin_pointers, 768ULL);\n";
cp.code() += "etiss_coverage_count(2, 7298, 7297);\n";
cp.code() += "etiss_uint64 prev_prv = (etiss_uint64)(RV64IMACFD_get_field(s, 6144ULL));\n";
cp.code() += "etiss_coverage_count(4, 7305, 7304, 7302, 7300);\n";
cp.code() += "etiss_coverage_count(1, 7306);\n";
cp.code() += "if (prev_prv != 3ULL) { // conditional\n";
cp.code() += "etiss_coverage_count(2, 7309, 7307);\n";
cp.code() += "s = (etiss_uint64)(RV64IMACFD_set_field(s, 131072ULL, 0LL));\n";
cp.code() += "etiss_coverage_count(6, 7317, 7310, 7316, 7314, 7311, 7313);\n";
cp.code() += "} // conditional\n";
cp.code() += "s = (etiss_uint64)(RV64IMACFD_set_field(s, 8ULL, RV64IMACFD_get_field(s, 128ULL)));\n";
cp.code() += "etiss_coverage_count(7, 7327, 7318, 7326, 7324, 7319, 7323, 7321);\n";
cp.code() += "s = (etiss_uint64)(RV64IMACFD_set_field(s, 128ULL, 1ULL));\n";
cp.code() += "etiss_coverage_count(6, 7335, 7328, 7334, 7332, 7329, 7331);\n";
cp.code() += "s = (etiss_uint64)(RV64IMACFD_set_field(s, 6144ULL, (etiss_uint64)(((RV64IMACFD_extension_enabled(cpu, system, plugin_pointers, 85ULL)) ? (0LL) : (3ULL)))));\n";
cp.code() += "etiss_coverage_count(10, 7350, 7336, 7349, 7347, 7337, 7346, 7343, 7340, 7339, 7344);\n";
cp.code() += "RV64IMACFD_csr_write(cpu, system, plugin_pointers, 768ULL, s);\n";
cp.code() += "etiss_coverage_count(2, 7353, 7352);\n";
cp.code() += "((RV64IMACFD*)cpu)->PRIV = ((etiss_uint8)(prev_prv)) & 0x7ULL;\n";
cp.code() += "etiss_coverage_count(4, 7358, 7354, 7357, 7355);\n";
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
cp.code() += "etiss_coverage_count(1, 169);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7434);\n";
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
cp.code() += "etiss_coverage_count(1, 167);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1239);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint64)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1238, 1231, 1237, 1234, 1232, 1233, 1235);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7424);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7360);\n";
cp.code() += "if (((RV64IMACFD*)cpu)->PRIV < ((RV64IMACFD_get_field(RV64IMACFD_csr_read(cpu, system, plugin_pointers, 768ULL), 4194304ULL)) ? (3ULL) : (1ULL))) { // conditional\n";
cp.code() += "etiss_coverage_count(6, 7370, 7361, 7368, 7365, 7363, 7369);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV64IMACFD_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(2, 7373, 7371);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "cpu->nextPc = *((RV64IMACFD*)cpu)->CSR[321ULL];\n";
cp.code() += "etiss_coverage_count(3, 7378, 7374, 7377);\n";
cp.code() += "etiss_uint64 s = RV64IMACFD_csr_read(cpu, system, plugin_pointers, 256ULL);\n";
cp.code() += "etiss_coverage_count(2, 7382, 7381);\n";
cp.code() += "etiss_uint64 prev_prv = (etiss_uint64)(RV64IMACFD_get_field(s, 256ULL));\n";
cp.code() += "etiss_coverage_count(4, 7389, 7388, 7386, 7384);\n";
cp.code() += "s = (etiss_uint64)(RV64IMACFD_set_field(s, 2ULL, RV64IMACFD_get_field(s, 32ULL)));\n";
cp.code() += "etiss_coverage_count(7, 7399, 7390, 7398, 7396, 7391, 7395, 7393);\n";
cp.code() += "s = (etiss_uint64)(RV64IMACFD_set_field(s, 32ULL, 1ULL));\n";
cp.code() += "etiss_coverage_count(6, 7407, 7400, 7406, 7404, 7401, 7403);\n";
cp.code() += "s = (etiss_uint64)(RV64IMACFD_set_field(s, 256ULL, 0LL));\n";
cp.code() += "etiss_coverage_count(5, 7415, 7408, 7414, 7412, 7409);\n";
cp.code() += "RV64IMACFD_csr_write(cpu, system, plugin_pointers, 768ULL, s);\n";
cp.code() += "etiss_coverage_count(2, 7418, 7417);\n";
cp.code() += "((RV64IMACFD*)cpu)->PRIV = ((etiss_uint8)(prev_prv)) & 0x7ULL;\n";
cp.code() += "etiss_coverage_count(4, 7423, 7419, 7422, 7420);\n";
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
