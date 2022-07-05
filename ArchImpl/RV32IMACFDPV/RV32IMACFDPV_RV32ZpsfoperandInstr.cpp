/**
 * Generated on Mon, 04 Jul 2022 02:39:16 +0200.
 *
 * This file contains the instruction behavior models of the RV32Zpsfoperand
 * instruction set for the RV32IMACFDPV core architecture.
 */

#include "RV32IMACFDPVArch.h"

#define ETISS_ARCH_STATIC_FN_ONLY
#include "RV32IMACFDPVFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// ADD64 -----------------------------------------------------------------------
static InstructionDefinition add64_rd_rs1_rs2 (
	ISA32_RV32IMACFDPV,
	"add64",
	(uint32_t) 0xc0001077,
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

		partInit.code() = std::string("//ADD64\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_int64 rs1_val_hi = *((RV32IMACFDPV*)cpu)->X[" + std::to_string((((rs1) >> (1U)) & 15) * 2U + 1U) + "];\n";
partInit.code() += "etiss_uint32 rs1_val_lo = *((RV32IMACFDPV*)cpu)->X[" + std::to_string((((rs1) >> (1U)) & 15) * 2U) + "];\n";
partInit.code() += "etiss_int64 rs1_val = (((rs1_val_hi) << 32) | (rs1_val_lo));\n";
partInit.code() += "etiss_int64 rs2_val_hi = *((RV32IMACFDPV*)cpu)->X[" + std::to_string((((rs2) >> (1U)) & 15) * 2U + 1U) + "];\n";
partInit.code() += "etiss_uint32 rs2_val_lo = *((RV32IMACFDPV*)cpu)->X[" + std::to_string((((rs2) >> (1U)) & 15) * 2U) + "];\n";
partInit.code() += "etiss_int64 rs2_val = (((rs2_val_hi) << 32) | (rs2_val_lo));\n";
partInit.code() += "etiss_int64 sum = rs1_val + rs2_val;\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string((((rd) >> (1U)) & 15) * 2U + 1U) + "] = (((sum) >> (32U)) & 4294967295);\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string((((rd) >> (1U)) & 15) * 2U) + "] = (((sum) >> (0U)) & 4294967295);\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[(((rs1) >> (1U)) & 15) * 2U], 32);
		partInit.getRegisterDependencies().add(reg_name[(((rs1) >> (1U)) & 15) * 2U + 1U], 32);
		partInit.getRegisterDependencies().add(reg_name[(((rs2) >> (1U)) & 15) * 2U], 32);
		partInit.getRegisterDependencies().add(reg_name[(((rs2) >> (1U)) & 15) * 2U + 1U], 32);
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
ss << "add64" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SUB64 -----------------------------------------------------------------------
static InstructionDefinition sub64_rd_rs1_rs2 (
	ISA32_RV32IMACFDPV,
	"sub64",
	(uint32_t) 0xc2001077,
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

		partInit.code() = std::string("//SUB64\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
partInit.code() += "etiss_int64 rs1_val_hi = *((RV32IMACFDPV*)cpu)->X[" + std::to_string((((rs1) >> (1U)) & 15) * 2U + 1U) + "];\n";
partInit.code() += "etiss_int32 rs1_val_lo = *((RV32IMACFDPV*)cpu)->X[" + std::to_string((((rs1) >> (1U)) & 15) * 2U) + "];\n";
partInit.code() += "etiss_int64 rs1_val = (((rs1_val_hi) << 32) | (rs1_val_lo));\n";
partInit.code() += "etiss_int64 rs2_val_hi = *((RV32IMACFDPV*)cpu)->X[" + std::to_string((((rs2) >> (1U)) & 15) * 2U + 1U) + "];\n";
partInit.code() += "etiss_int32 rs2_val_lo = *((RV32IMACFDPV*)cpu)->X[" + std::to_string((((rs2) >> (1U)) & 15) * 2U) + "];\n";
partInit.code() += "etiss_int64 rs2_val = (((rs2_val_hi) << 32) | (rs2_val_lo));\n";
partInit.code() += "etiss_int64 sum = rs1_val - rs2_val;\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string((((rd) >> (1U)) & 15) * 2U + 1U) + "] = (((sum) >> (32U)) & 4294967295);\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string((((rd) >> (1U)) & 15) * 2U) + "] = (((sum) >> (0U)) & 4294967295);\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[(((rs1) >> (1U)) & 15) * 2U], 32);
		partInit.getRegisterDependencies().add(reg_name[(((rs1) >> (1U)) & 15) * 2U + 1U], 32);
		partInit.getRegisterDependencies().add(reg_name[(((rs2) >> (1U)) & 15) * 2U], 32);
		partInit.getRegisterDependencies().add(reg_name[(((rs2) >> (1U)) & 15) * 2U + 1U], 32);
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
ss << "sub64" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
