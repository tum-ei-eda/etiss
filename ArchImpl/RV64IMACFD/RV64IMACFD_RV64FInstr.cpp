/**
 * Generated on Mon, 14 Nov 2022 16:47:27 +0100.
 *
 * This file contains the instruction behavior models of the RV64F
 * instruction set for the RV64IMACFD core architecture.
 */

#include "RV64IMACFDArch.h"

#define ETISS_ARCH_STATIC_FN_ONLY
#include "RV64IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// FCVT_L_S --------------------------------------------------------------------
static InstructionDefinition fcvt_l_s_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fcvt_l_s",
	(uint32_t) 0xc0200053,
	(uint32_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//FCVT_L_S\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4UL) + "U;\n";
partInit.code() += "etiss_int64 res = fcvt_32_64(unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "U]), 0U, " + std::to_string(rm) + "U);\n";
if ((rd % 32U) != 0U) {
partInit.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "U] = res;\n";
}
partInit.code() += "etiss_uint32 flags = fget_flags();\n";
partInit.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32L) | (flags & 31U);\n";
partInit.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
partInit.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add(reg_name[rd % 32], 64);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fcvt_l_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCVT_LU_S -------------------------------------------------------------------
static InstructionDefinition fcvt_lu_s_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fcvt_lu_s",
	(uint32_t) 0xc0300053,
	(uint32_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//FCVT_LU_S\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4UL) + "U;\n";
partInit.code() += "etiss_uint64 res = fcvt_32_64(unbox_s(((RV64IMACFD*)cpu)->F[" + std::to_string(rs1) + "U]), 1U, " + std::to_string(rm) + "U);\n";
if ((rd % 32U) != 0U) {
partInit.code() += "*((RV64IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "U] = res;\n";
}
partInit.code() += "etiss_uint32 flags = fget_flags();\n";
partInit.code() += "((RV64IMACFD*)cpu)->FCSR = (((RV64IMACFD*)cpu)->FCSR & -32L) | (flags & 31U);\n";
partInit.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
partInit.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add(reg_name[rd % 32], 64);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fcvt_lu_s" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCVT_S_L --------------------------------------------------------------------
static InstructionDefinition fcvt_s_l_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fcvt_s_l",
	(uint32_t) 0xd0200053,
	(uint32_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//FCVT_S_L\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4UL) + "U;\n";
partInit.code() += "etiss_uint32 res = fcvt_64_32(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32U) + "U], 2U, " + std::to_string(rm) + "U);\n";
partInit.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "U] = -4294967296L | (etiss_uint64)(res);\n";
partInit.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
partInit.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1 % 32U], 64);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fcvt_s_l" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// FCVT_S_LU -------------------------------------------------------------------
static InstructionDefinition fcvt_s_lu_rd_rm_rs1 (
	ISA32_RV64IMACFD,
	"fcvt_s_lu",
	(uint32_t) 0xd0300053,
	(uint32_t) 0xfff0007f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//FCVT_S_LU\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4UL) + "U;\n";
partInit.code() += "etiss_uint32 res = fcvt_64_32(*((RV64IMACFD*)cpu)->X[" + std::to_string(rs1 % 32U) + "U], 3U, " + std::to_string(rm) + "U);\n";
partInit.code() += "((RV64IMACFD*)cpu)->F[" + std::to_string(rd) + "U] = -4294967296L | (etiss_uint64)(res);\n";
partInit.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
partInit.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1 % 32U], 64);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 rm = 0;
static BitArrayRange R_rm_0(14, 12);
rm += R_rm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "fcvt_s_lu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rm=" + std::to_string(rm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
