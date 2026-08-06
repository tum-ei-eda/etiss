// clang-format off
/**
 * Generated on Thu, 06 Aug 2026 12:56:16 +0200.
 *
 * This file contains the instruction behavior models of the Zifencei
 * instruction set for the RV32IMACFDV_zvl128b core architecture.
 */

#include "RV32IMACFDV_zvl128bArch.h"
#include "RV32IMACFDV_zvl128bFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// FENCE_I ---------------------------------------------------------------------
static InstructionDefinition fence_i_rd_rs1_imm (
	ISA32_RV32IMACFDV_zvl128b,
	"fence_i",
	(uint64_t) 0x00100f,
	(uint64_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//FENCE_I\n");

// -----------------------------------------------------------------------------
cp.code() += "cpu->exception = ETISS_RETURNCODE_RELOADBLOCKS;\n";
cp.code() += "etiss_coverage_count(1, 531);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "((RV32IMACFDV_zvl128b*)cpu)->FENCE[1ULL] = " + std::to_string(imm) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 30323, 30321, 30322);\n";
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//FENCE_I\n");

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
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint16 imm = 0;
static BitArrayRange R_imm_0(31, 20);
imm += R_imm_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fence_i" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
// clang-format on
