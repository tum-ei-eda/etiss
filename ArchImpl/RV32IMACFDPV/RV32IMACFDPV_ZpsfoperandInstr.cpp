/**
 * Generated on Mon, 04 Jul 2022 02:39:16 +0200.
 *
 * This file contains the instruction behavior models of the Zpsfoperand
 * instruction set for the RV32IMACFDPV core architecture.
 */

#include "RV32IMACFDPVArch.h"

#define ETISS_ARCH_STATIC_FN_ONLY
#include "RV32IMACFDPVFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// MULR64 ----------------------------------------------------------------------
static InstructionDefinition mulr64_rd_rs1_rs2 (
	ISA32_RV32IMACFDPV,
	"mulr64",
	(uint32_t) 0xf0001077,
	(uint32_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//MULR64\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_uint32 rs1_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "];\n";
partInit.code() += "etiss_uint32 rs2_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs2) + "];\n";
partInit.code() += "etiss_uint64 product = rs1_val * rs2_val;\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string((((rd) >> (1U)) & 15) * 2U + 1U) + "] = (((product) >> (32U)) & 4294967295);\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string((((rd) >> (1U)) & 15) * 2U) + "] = (((product) >> (0U)) & 4294967295);\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add(reg_name[(((rd) >> (1U)) & 15) * 2U], 32);
		partInit.getAffectedRegisters().add(reg_name[(((rd) >> (1U)) & 15) * 2U + 1U], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "mulr64" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
