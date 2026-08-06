// clang-format off
/**
 * Generated on Thu, 06 Aug 2026 13:26:11 +0200.
 *
 * This file contains the instruction behavior models of the tum_ret
 * instruction set for the RV32IMACFDV_zvl128b core architecture.
 */

#include "RV32IMACFDV_zvl128bArch.h"
#include "RV32IMACFDV_zvl128bFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// ECALL -----------------------------------------------------------------------
static InstructionDefinition ecall_ (
	ISA32_RV32IMACFDV_zvl128b,
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
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7105);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 8ULL + ((RV32IMACFDV_zvl128b*)cpu)->PRIV);\n";
cp.code() += "etiss_coverage_count(4, 7104, 7100, 7103, 7102);\n";
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
	ISA32_RV32IMACFDV_zvl128b,
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
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7034);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 6961);\n";
cp.code() += "if (((RV32IMACFDV_zvl128b*)cpu)->PRIV < 3ULL) { // conditional\n";
cp.code() += "etiss_coverage_count(2, 6964, 6962);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(2, 6967, 6965);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "cpu->nextPc = *((RV32IMACFDV_zvl128b*)cpu)->CSR[833ULL];\n";
cp.code() += "etiss_coverage_count(3, 6972, 6968, 6971);\n";
cp.code() += "etiss_uint32 s = RV32IMACFDV_zvl128b_csr_read(cpu, system, plugin_pointers, 768ULL);\n";
cp.code() += "etiss_coverage_count(2, 6976, 6975);\n";
cp.code() += "etiss_uint32 prev_prv = (etiss_uint32)(RV32IMACFDV_zvl128b_get_field(s, 6144ULL));\n";
cp.code() += "etiss_coverage_count(4, 6983, 6982, 6980, 6978);\n";
cp.code() += "etiss_coverage_count(1, 6984);\n";
cp.code() += "if (prev_prv != 3ULL) { // conditional\n";
cp.code() += "etiss_coverage_count(2, 6987, 6985);\n";
cp.code() += "s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 131072ULL, 0LL));\n";
cp.code() += "etiss_coverage_count(6, 6995, 6988, 6994, 6992, 6989, 6991);\n";
cp.code() += "} // conditional\n";
cp.code() += "s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 8ULL, RV32IMACFDV_zvl128b_get_field(s, 128ULL)));\n";
cp.code() += "etiss_coverage_count(7, 7005, 6996, 7004, 7002, 6997, 7001, 6999);\n";
cp.code() += "s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 128ULL, 1ULL));\n";
cp.code() += "etiss_coverage_count(6, 7013, 7006, 7012, 7010, 7007, 7009);\n";
cp.code() += "s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 6144ULL, (RV32IMACFDV_zvl128b_extension_enabled(cpu, system, plugin_pointers, 85ULL)) ? (0LL) : (3ULL)));\n";
cp.code() += "etiss_coverage_count(8, 7025, 7014, 7024, 7022, 7015, 7021, 7018, 7017);\n";
cp.code() += "RV32IMACFDV_zvl128b_csr_write(cpu, system, plugin_pointers, 768ULL, s);\n";
cp.code() += "etiss_coverage_count(2, 7028, 7027);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->PRIV = ((etiss_uint8)(prev_prv)) & 0x7ULL;\n";
cp.code() += "etiss_coverage_count(4, 7033, 7029, 7032, 7030);\n";
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
	ISA32_RV32IMACFDV_zvl128b,
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
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7106);\n";
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
	ISA32_RV32IMACFDV_zvl128b,
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
cp.code() += "etiss_coverage_count(1, 1602);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1601, 1594, 1600, 1597, 1595, 1596, 1598);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7099);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 7035);\n";
cp.code() += "if (((RV32IMACFDV_zvl128b*)cpu)->PRIV < ((RV32IMACFDV_zvl128b_get_field(RV32IMACFDV_zvl128b_csr_read(cpu, system, plugin_pointers, 768ULL), 4194304ULL)) ? (3ULL) : (1ULL))) { // conditional\n";
cp.code() += "etiss_coverage_count(6, 7045, 7036, 7043, 7040, 7038, 7044);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(2, 7048, 7046);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "cpu->nextPc = *((RV32IMACFDV_zvl128b*)cpu)->CSR[321ULL];\n";
cp.code() += "etiss_coverage_count(3, 7053, 7049, 7052);\n";
cp.code() += "etiss_uint32 s = RV32IMACFDV_zvl128b_csr_read(cpu, system, plugin_pointers, 256ULL);\n";
cp.code() += "etiss_coverage_count(2, 7057, 7056);\n";
cp.code() += "etiss_uint32 prev_prv = (etiss_uint32)(RV32IMACFDV_zvl128b_get_field(s, 256ULL));\n";
cp.code() += "etiss_coverage_count(4, 7064, 7063, 7061, 7059);\n";
cp.code() += "s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 2ULL, RV32IMACFDV_zvl128b_get_field(s, 32ULL)));\n";
cp.code() += "etiss_coverage_count(7, 7074, 7065, 7073, 7071, 7066, 7070, 7068);\n";
cp.code() += "s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 32ULL, 1ULL));\n";
cp.code() += "etiss_coverage_count(6, 7082, 7075, 7081, 7079, 7076, 7078);\n";
cp.code() += "s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 256ULL, 0LL));\n";
cp.code() += "etiss_coverage_count(5, 7090, 7083, 7089, 7087, 7084);\n";
cp.code() += "RV32IMACFDV_zvl128b_csr_write(cpu, system, plugin_pointers, 768ULL, s);\n";
cp.code() += "etiss_coverage_count(2, 7093, 7092);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->PRIV = ((etiss_uint8)(prev_prv)) & 0x7ULL;\n";
cp.code() += "etiss_coverage_count(4, 7098, 7094, 7097, 7095);\n";
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
