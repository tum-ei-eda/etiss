/**
 * Generated on Mon, 04 Jul 2022 08:07:06 +0200.
 *
 * This file contains the instruction behavior models of the Zbpo
 * instruction set for the RV32IMACFDPV core architecture.
 */

#include "RV32IMACFDPVArch.h"

#define ETISS_ARCH_STATIC_FN_ONLY
#include "RV32IMACFDPVFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// PACK ------------------------------------------------------------------------
static InstructionDefinition pack_rd_rs1_rs2 (
	ISA32_RV32IMACFDPV,
	"pack",
	(uint32_t) 0x8004033,
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

		partInit.code() = std::string("//PACK\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
if (rd != 0U) {
partInit.code() += "etiss_uint32 rs1_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "];\n";
partInit.code() += "etiss_uint32 rs2_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs2) + "];\n";
partInit.code() += "etiss_uint16 rd_val_lo = (((rs1_val) >> (0U)) & 65535);\n";
partInit.code() += "etiss_uint16 rd_val_hi = (((rs2_val) >> (0U)) & 65535);\n";
partInit.code() += "etiss_uint32 rd_val = (((rd_val_hi) << 16) | (rd_val_lo));\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rd) + "] = rd_val;\n";
}
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add(reg_name[rd], 32);
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
ss << "pack" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// PACKU -----------------------------------------------------------------------
static InstructionDefinition packu_rd_rs1_rs2 (
	ISA32_RV32IMACFDPV,
	"packu",
	(uint32_t) 0x48004033,
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

		partInit.code() = std::string("//PACKU\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
if (rd != 0U) {
partInit.code() += "etiss_uint32 rs1_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "];\n";
partInit.code() += "etiss_uint32 rs2_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs2) + "];\n";
partInit.code() += "etiss_uint16 rd_val_lo = (((rs1_val) >> (16U)) & 65535);\n";
partInit.code() += "etiss_uint16 rd_val_hi = (((rs2_val) >> (16U)) & 65535);\n";
partInit.code() += "etiss_uint32 rd_val = (((rd_val_hi) << 16) | (rd_val_lo));\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rd) + "] = rd_val;\n";
}
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add(reg_name[rd], 32);
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
ss << "packu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// MIN -------------------------------------------------------------------------
static InstructionDefinition min_rd_rs1_rs2 (
	ISA32_RV32IMACFDPV,
	"min",
	(uint32_t) 0xa004033,
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

		partInit.code() = std::string("//MIN\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
if (rd != 0U) {
partInit.code() += "etiss_int32 rs1_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "];\n";
partInit.code() += "etiss_int32 rs2_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs2) + "];\n";
partInit.code() += "etiss_int32 rd_val = (rs1_val < rs2_val) ? (rs1_val) : (rs2_val);\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rd) + "] = rd_val;\n";
}
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add(reg_name[rd], 32);
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
ss << "min" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// MAX -------------------------------------------------------------------------
static InstructionDefinition max_rd_rs1_rs2 (
	ISA32_RV32IMACFDPV,
	"max",
	(uint32_t) 0xa006033,
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

		partInit.code() = std::string("//MAX\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 4U) + ";\n";
if (rd != 0U) {
partInit.code() += "etiss_int32 rs1_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs1) + "];\n";
partInit.code() += "etiss_int32 rs2_val = *((RV32IMACFDPV*)cpu)->X[" + std::to_string(rs2) + "];\n";
partInit.code() += "etiss_int32 rd_val = (rs1_val >= rs2_val) ? (rs1_val) : (rs2_val);\n";
partInit.code() += "*((RV32IMACFDPV*)cpu)->X[" + std::to_string(rd) + "] = rd_val;\n";
}
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2], 32);
		partInit.getAffectedRegisters().add(reg_name[rd], 32);
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
ss << "max" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
