// clang-format off
/**
 * Generated on Thu, 06 Aug 2026 12:56:16 +0200.
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
cp.code() += "etiss_coverage_count(1, 551);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 30659);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 8ULL + ((RV32IMACFDV_zvl128b*)cpu)->PRIV);\n";
cp.code() += "etiss_coverage_count(4, 30658, 30654, 30657, 30656);\n";
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
cp.code() += "etiss_coverage_count(1, 549);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 30588);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 30515);\n";
cp.code() += "if (((RV32IMACFDV_zvl128b*)cpu)->PRIV < 3ULL) { // conditional\n";
cp.code() += "etiss_coverage_count(2, 30518, 30516);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(2, 30521, 30519);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "cpu->nextPc = *((RV32IMACFDV_zvl128b*)cpu)->CSR[833ULL];\n";
cp.code() += "etiss_coverage_count(3, 30526, 30522, 30525);\n";
cp.code() += "etiss_uint32 s = RV32IMACFDV_zvl128b_csr_read(cpu, system, plugin_pointers, 768ULL);\n";
cp.code() += "etiss_coverage_count(2, 30530, 30529);\n";
cp.code() += "etiss_uint32 prev_prv = (etiss_uint32)(RV32IMACFDV_zvl128b_get_field(s, 6144ULL));\n";
cp.code() += "etiss_coverage_count(4, 30537, 30536, 30534, 30532);\n";
cp.code() += "etiss_coverage_count(1, 30538);\n";
cp.code() += "if (prev_prv != 3ULL) { // conditional\n";
cp.code() += "etiss_coverage_count(2, 30541, 30539);\n";
cp.code() += "s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 131072ULL, 0LL));\n";
cp.code() += "etiss_coverage_count(6, 30549, 30542, 30548, 30546, 30543, 30545);\n";
cp.code() += "} // conditional\n";
cp.code() += "s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 8ULL, RV32IMACFDV_zvl128b_get_field(s, 128ULL)));\n";
cp.code() += "etiss_coverage_count(7, 30559, 30550, 30558, 30556, 30551, 30555, 30553);\n";
cp.code() += "s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 128ULL, 1ULL));\n";
cp.code() += "etiss_coverage_count(6, 30567, 30560, 30566, 30564, 30561, 30563);\n";
cp.code() += "s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 6144ULL, (RV32IMACFDV_zvl128b_extension_enabled(cpu, system, plugin_pointers, 85ULL)) ? (0LL) : (3ULL)));\n";
cp.code() += "etiss_coverage_count(8, 30579, 30568, 30578, 30576, 30569, 30575, 30572, 30571);\n";
cp.code() += "RV32IMACFDV_zvl128b_csr_write(cpu, system, plugin_pointers, 768ULL, s);\n";
cp.code() += "etiss_coverage_count(2, 30582, 30581);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->PRIV = ((etiss_uint8)(prev_prv)) & 0x7ULL;\n";
cp.code() += "etiss_coverage_count(4, 30587, 30583, 30586, 30584);\n";
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
cp.code() += "etiss_coverage_count(1, 552);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 30660);\n";
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
cp.code() += "etiss_coverage_count(1, 550);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 30653);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 30589);\n";
cp.code() += "if (((RV32IMACFDV_zvl128b*)cpu)->PRIV < ((RV32IMACFDV_zvl128b_get_field(RV32IMACFDV_zvl128b_csr_read(cpu, system, plugin_pointers, 768ULL), 4194304ULL)) ? (3ULL) : (1ULL))) { // conditional\n";
cp.code() += "etiss_coverage_count(6, 30599, 30590, 30597, 30594, 30592, 30598);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(2, 30602, 30600);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "cpu->nextPc = *((RV32IMACFDV_zvl128b*)cpu)->CSR[321ULL];\n";
cp.code() += "etiss_coverage_count(3, 30607, 30603, 30606);\n";
cp.code() += "etiss_uint32 s = RV32IMACFDV_zvl128b_csr_read(cpu, system, plugin_pointers, 256ULL);\n";
cp.code() += "etiss_coverage_count(2, 30611, 30610);\n";
cp.code() += "etiss_uint32 prev_prv = (etiss_uint32)(RV32IMACFDV_zvl128b_get_field(s, 256ULL));\n";
cp.code() += "etiss_coverage_count(4, 30618, 30617, 30615, 30613);\n";
cp.code() += "s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 2ULL, RV32IMACFDV_zvl128b_get_field(s, 32ULL)));\n";
cp.code() += "etiss_coverage_count(7, 30628, 30619, 30627, 30625, 30620, 30624, 30622);\n";
cp.code() += "s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 32ULL, 1ULL));\n";
cp.code() += "etiss_coverage_count(6, 30636, 30629, 30635, 30633, 30630, 30632);\n";
cp.code() += "s = (etiss_uint32)(RV32IMACFDV_zvl128b_set_field(s, 256ULL, 0LL));\n";
cp.code() += "etiss_coverage_count(5, 30644, 30637, 30643, 30641, 30638);\n";
cp.code() += "RV32IMACFDV_zvl128b_csr_write(cpu, system, plugin_pointers, 768ULL, s);\n";
cp.code() += "etiss_coverage_count(2, 30647, 30646);\n";
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->PRIV = ((etiss_uint8)(prev_prv)) & 0x7ULL;\n";
cp.code() += "etiss_coverage_count(4, 30652, 30648, 30651, 30649);\n";
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
