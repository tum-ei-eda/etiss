/**
 * Generated on Mon, 09 May 2022 22:10:34 +0200.
 *
 * This file contains the instruction behavior models of the RV32IC
 * instruction set for the RV32IMACFD core architecture.
 */

#include "RV32IMACFDArch.h"

#define ETISS_ARCH_STATIC_FN_ONLY
#include "RV32IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// CADDI4SPN -------------------------------------------------------------------
static InstructionDefinition caddi4spn_rd_imm (
	ISA16_RV32IMACFD,
	"caddi4spn",
	(uint16_t) 0x00,
	(uint16_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(4, 2);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 imm = 0;
static BitArrayRange R_imm_3(5, 5);
imm += R_imm_3.read(ba) << 3;
static BitArrayRange R_imm_2(6, 6);
imm += R_imm_2.read(ba) << 2;
static BitArrayRange R_imm_6(10, 7);
imm += R_imm_6.read(ba) << 6;
static BitArrayRange R_imm_4(12, 11);
imm += R_imm_4.read(ba) << 4;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CADDI4SPN\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
if (imm) {
partInit.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd + 8U) + "] = *((RV32IMACFD*)cpu)->X[" + std::to_string(2U) + "] + " + std::to_string(imm) + ";\n";
} else {
partInit.code() += "exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION;\n";
}
partInit.code() += "if (exception) return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[2U], 32);
		partInit.getAffectedRegisters().add(reg_name[rd + 8U], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(4, 2);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 imm = 0;
static BitArrayRange R_imm_3(5, 5);
imm += R_imm_3.read(ba) << 3;
static BitArrayRange R_imm_2(6, 6);
imm += R_imm_2.read(ba) << 2;
static BitArrayRange R_imm_6(10, 7);
imm += R_imm_6.read(ba) << 6;
static BitArrayRange R_imm_4(12, 11);
imm += R_imm_4.read(ba) << 4;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "caddi4spn" << " # " << ba << (" [rd=" + std::to_string(rd) + " | imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CLW -------------------------------------------------------------------------
static InstructionDefinition clw_rd_uimm_rs1 (
	ISA16_RV32IMACFD,
	"clw",
	(uint16_t) 0x4000,
	(uint16_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(4, 2);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 uimm = 0;
static BitArrayRange R_uimm_6(5, 5);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_2(6, 6);
uimm += R_uimm_2.read(ba) << 2;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_uimm_3(12, 10);
uimm += R_uimm_3.read(ba) << 3;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CLW\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
partInit.code() += "etiss_uint32 load_address = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 + 8U) + "] + " + std::to_string(uimm) + ";\n";
partInit.code() += "etiss_uint32 mem_val_0;\n";
partInit.code() += "exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 4);\n";
partInit.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd + 8U) + "] = (etiss_int32)(mem_val_0);\n";
partInit.code() += "if (exception) return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1 + 8U], 32);
		partInit.getAffectedRegisters().add(reg_name[rd + 8U], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(4, 2);
rd += R_rd_0.read(ba) << 0;
etiss_uint32 uimm = 0;
static BitArrayRange R_uimm_6(5, 5);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_2(6, 6);
uimm += R_uimm_2.read(ba) << 2;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_uimm_3(12, 10);
uimm += R_uimm_3.read(ba) << 3;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "clw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | uimm=" + std::to_string(uimm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CSW -------------------------------------------------------------------------
static InstructionDefinition csw_rs2_uimm_rs1 (
	ISA16_RV32IMACFD,
	"csw",
	(uint16_t) 0xc000,
	(uint16_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint32 uimm = 0;
static BitArrayRange R_uimm_6(5, 5);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_2(6, 6);
uimm += R_uimm_2.read(ba) << 2;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_uimm_3(12, 10);
uimm += R_uimm_3.read(ba) << 3;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CSW\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
partInit.code() += "etiss_uint32 load_address = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 + 8U) + "] + " + std::to_string(uimm) + ";\n";
partInit.code() += "etiss_uint32 mem_val_0 = (etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 + 8U) + "]);\n";
partInit.code() += "exception |= (*(system->dwrite))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 4);\n";

partInit.code() += "if (exception) return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1 + 8U], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2 + 8U], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint32 uimm = 0;
static BitArrayRange R_uimm_6(5, 5);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_2(6, 6);
uimm += R_uimm_2.read(ba) << 2;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_uimm_3(12, 10);
uimm += R_uimm_3.read(ba) << 3;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "csw" << " # " << ba << (" [rs2=" + std::to_string(rs2) + " | uimm=" + std::to_string(uimm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CADDI -----------------------------------------------------------------------
static InstructionDefinition caddi_imm_rs1 (
	ISA16_RV32IMACFD,
	"caddi",
	(uint16_t) 0x01,
	(uint16_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_0(6, 2);
imm += R_imm_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(11, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_imm_5(12, 12);
imm += R_imm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CADDI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
if ((rs1 % 32U) != 0U) {
partInit.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32) + "] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32U) + "] + " + std::to_string(((etiss_int8)((imm) << (2)) >> (2))) + ";\n";
}
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1 % 32U], 32);
		partInit.getAffectedRegisters().add(reg_name[rs1 % 32], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_0(6, 2);
imm += R_imm_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(11, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_imm_5(12, 12);
imm += R_imm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "caddi" << " # " << ba << (" [imm=" + std::to_string(imm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CNOP ------------------------------------------------------------------------
static InstructionDefinition cnop_nzimm (
	ISA16_RV32IMACFD,
	"cnop",
	(uint16_t) 0x01,
	(uint16_t) 0xef83,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 nzimm = 0;
static BitArrayRange R_nzimm_0(6, 2);
nzimm += R_nzimm_0.read(ba) << 0;
static BitArrayRange R_nzimm_5(12, 12);
nzimm += R_nzimm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CNOP\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 nzimm = 0;
static BitArrayRange R_nzimm_0(6, 2);
nzimm += R_nzimm_0.read(ba) << 0;
static BitArrayRange R_nzimm_5(12, 12);
nzimm += R_nzimm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cnop" << " # " << ba << (" [nzimm=" + std::to_string(nzimm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CJAL ------------------------------------------------------------------------
static InstructionDefinition cjal_imm (
	ISA16_RV32IMACFD,
	"cjal",
	(uint16_t) 0x2001,
	(uint16_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_5(2, 2);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_1(5, 3);
imm += R_imm_1.read(ba) << 1;
static BitArrayRange R_imm_7(6, 6);
imm += R_imm_7.read(ba) << 7;
static BitArrayRange R_imm_6(7, 7);
imm += R_imm_6.read(ba) << 6;
static BitArrayRange R_imm_10(8, 8);
imm += R_imm_10.read(ba) << 10;
static BitArrayRange R_imm_8(10, 9);
imm += R_imm_8.read(ba) << 8;
static BitArrayRange R_imm_4(11, 11);
imm += R_imm_4.read(ba) << 4;
static BitArrayRange R_imm_11(12, 12);
imm += R_imm_11.read(ba) << 11;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CJAL\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
partInit.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(1U) + "] = " + std::to_string(ic.current_address_ + 2U) + ";\n";
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + ((etiss_int16)((imm) << (4)) >> (4))) + ";\n";
partInit.code() += "return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add(reg_name[1U], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_5(2, 2);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_1(5, 3);
imm += R_imm_1.read(ba) << 1;
static BitArrayRange R_imm_7(6, 6);
imm += R_imm_7.read(ba) << 7;
static BitArrayRange R_imm_6(7, 7);
imm += R_imm_6.read(ba) << 6;
static BitArrayRange R_imm_10(8, 8);
imm += R_imm_10.read(ba) << 10;
static BitArrayRange R_imm_8(10, 9);
imm += R_imm_8.read(ba) << 8;
static BitArrayRange R_imm_4(11, 11);
imm += R_imm_4.read(ba) << 4;
static BitArrayRange R_imm_11(12, 12);
imm += R_imm_11.read(ba) << 11;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cjal" << " # " << ba << (" [imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CLI -------------------------------------------------------------------------
static InstructionDefinition cli_imm_rd (
	ISA16_RV32IMACFD,
	"cli",
	(uint16_t) 0x4001,
	(uint16_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_0(6, 2);
imm += R_imm_0.read(ba) << 0;
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
static BitArrayRange R_imm_5(12, 12);
imm += R_imm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CLI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
if ((rd % 32U) != 0U) {
partInit.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "] = " + std::to_string(((etiss_int8)((imm) << (2)) >> (2))) + ";\n";
}
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add(reg_name[rd % 32], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_0(6, 2);
imm += R_imm_0.read(ba) << 0;
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
static BitArrayRange R_imm_5(12, 12);
imm += R_imm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cli" << " # " << ba << (" [imm=" + std::to_string(imm) + " | rd=" + std::to_string(rd) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CLUI ------------------------------------------------------------------------
static InstructionDefinition clui_imm_rd (
	ISA16_RV32IMACFD,
	"clui",
	(uint16_t) 0x6001,
	(uint16_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_12(6, 2);
imm += R_imm_12.read(ba) << 12;
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
static BitArrayRange R_imm_17(12, 12);
imm += R_imm_17.read(ba) << 17;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CLUI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
if (imm == 0U) {
partInit.code() += "exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION;\n";
}
if ((rd % 32U) != 0U) {
partInit.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "] = " + std::to_string(((etiss_int32)((imm) << (14)) >> (14))) + ";\n";
}
partInit.code() += "if (exception) return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add(reg_name[rd % 32], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_12(6, 2);
imm += R_imm_12.read(ba) << 12;
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
static BitArrayRange R_imm_17(12, 12);
imm += R_imm_17.read(ba) << 17;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "clui" << " # " << ba << (" [imm=" + std::to_string(imm) + " | rd=" + std::to_string(rd) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CADDI16SP -------------------------------------------------------------------
static InstructionDefinition caddi16sp_nzimm (
	ISA16_RV32IMACFD,
	"caddi16sp",
	(uint16_t) 0x6101,
	(uint16_t) 0xef83,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 nzimm = 0;
static BitArrayRange R_nzimm_5(2, 2);
nzimm += R_nzimm_5.read(ba) << 5;
static BitArrayRange R_nzimm_7(4, 3);
nzimm += R_nzimm_7.read(ba) << 7;
static BitArrayRange R_nzimm_6(5, 5);
nzimm += R_nzimm_6.read(ba) << 6;
static BitArrayRange R_nzimm_4(6, 6);
nzimm += R_nzimm_4.read(ba) << 4;
static BitArrayRange R_nzimm_9(12, 12);
nzimm += R_nzimm_9.read(ba) << 9;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CADDI16SP\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
if (nzimm) {
partInit.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(2U) + "] = *((RV32IMACFD*)cpu)->X[" + std::to_string(2U) + "] + " + std::to_string(((etiss_int16)((nzimm) << (6)) >> (6))) + ";\n";
} else {
partInit.code() += "exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION;\n";
}
partInit.code() += "if (exception) return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[2U], 32);
		partInit.getAffectedRegisters().add(reg_name[2U], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 nzimm = 0;
static BitArrayRange R_nzimm_5(2, 2);
nzimm += R_nzimm_5.read(ba) << 5;
static BitArrayRange R_nzimm_7(4, 3);
nzimm += R_nzimm_7.read(ba) << 7;
static BitArrayRange R_nzimm_6(5, 5);
nzimm += R_nzimm_6.read(ba) << 6;
static BitArrayRange R_nzimm_4(6, 6);
nzimm += R_nzimm_4.read(ba) << 4;
static BitArrayRange R_nzimm_9(12, 12);
nzimm += R_nzimm_9.read(ba) << 9;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "caddi16sp" << " # " << ba << (" [nzimm=" + std::to_string(nzimm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// __reserved_clui -------------------------------------------------------------
static InstructionDefinition __reserved_clui_rd (
	ISA16_RV32IMACFD,
	"__reserved_clui",
	(uint16_t) 0x6001,
	(uint16_t) 0xf07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//__reserved_clui\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
partInit.code() += "exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION;\n";
partInit.code() += "if (exception) return exception;\n";
// -----------------------------------------------------------------------------

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

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "__reserved_clui" << " # " << ba << (" [rd=" + std::to_string(rd) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CSRLI -----------------------------------------------------------------------
static InstructionDefinition csrli_shamt_rs1 (
	ISA16_RV32IMACFD,
	"csrli",
	(uint16_t) 0x8001,
	(uint16_t) 0xfc03,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 shamt = 0;
static BitArrayRange R_shamt_0(6, 2);
shamt += R_shamt_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CSRLI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
partInit.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 + 8U) + "] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 + 8U) + "] >> " + std::to_string(shamt) + ";\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1 + 8U], 32);
		partInit.getAffectedRegisters().add(reg_name[rs1 + 8U], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 shamt = 0;
static BitArrayRange R_shamt_0(6, 2);
shamt += R_shamt_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "csrli" << " # " << ba << (" [shamt=" + std::to_string(shamt) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CSRAI -----------------------------------------------------------------------
static InstructionDefinition csrai_shamt_rs1 (
	ISA16_RV32IMACFD,
	"csrai",
	(uint16_t) 0x8401,
	(uint16_t) 0xfc03,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 shamt = 0;
static BitArrayRange R_shamt_0(6, 2);
shamt += R_shamt_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CSRAI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
if (shamt) {
partInit.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 + 8U) + "] = ((etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 + 8U) + "])) >> " + std::to_string(shamt) + ";\n";
} else {
if (0U) {
partInit.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 + 8U) + "] = ((etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 + 8U) + "])) >> 64U;\n";
}
}
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1 + 8U], 32);
		partInit.getAffectedRegisters().add(reg_name[rs1 + 8U], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 shamt = 0;
static BitArrayRange R_shamt_0(6, 2);
shamt += R_shamt_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "csrai" << " # " << ba << (" [shamt=" + std::to_string(shamt) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CANDI -----------------------------------------------------------------------
static InstructionDefinition candi_imm_rs1 (
	ISA16_RV32IMACFD,
	"candi",
	(uint16_t) 0x8801,
	(uint16_t) 0xec03,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_0(6, 2);
imm += R_imm_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_imm_5(12, 12);
imm += R_imm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CANDI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
partInit.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 + 8U) + "] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 + 8U) + "] & " + std::to_string(((etiss_int8)((imm) << (2)) >> (2))) + ";\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1 + 8U], 32);
		partInit.getAffectedRegisters().add(reg_name[rs1 + 8U], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_0(6, 2);
imm += R_imm_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_imm_5(12, 12);
imm += R_imm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "candi" << " # " << ba << (" [imm=" + std::to_string(imm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CSUB ------------------------------------------------------------------------
static InstructionDefinition csub_rs2_rd (
	ISA16_RV32IMACFD,
	"csub",
	(uint16_t) 0x8c01,
	(uint16_t) 0xfc63,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(9, 7);
rd += R_rd_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CSUB\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
partInit.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd + 8U) + "] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rd + 8U) + "] - *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 + 8U) + "];\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rd + 8U], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2 + 8U], 32);
		partInit.getAffectedRegisters().add(reg_name[rd + 8U], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(9, 7);
rd += R_rd_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "csub" << " # " << ba << (" [rs2=" + std::to_string(rs2) + " | rd=" + std::to_string(rd) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CXOR ------------------------------------------------------------------------
static InstructionDefinition cxor_rs2_rd (
	ISA16_RV32IMACFD,
	"cxor",
	(uint16_t) 0x8c21,
	(uint16_t) 0xfc63,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(9, 7);
rd += R_rd_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CXOR\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
partInit.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd + 8U) + "] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rd + 8U) + "] ^ *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 + 8U) + "];\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rd + 8U], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2 + 8U], 32);
		partInit.getAffectedRegisters().add(reg_name[rd + 8U], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(9, 7);
rd += R_rd_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cxor" << " # " << ba << (" [rs2=" + std::to_string(rs2) + " | rd=" + std::to_string(rd) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// COR -------------------------------------------------------------------------
static InstructionDefinition cor_rs2_rd (
	ISA16_RV32IMACFD,
	"cor",
	(uint16_t) 0x8c41,
	(uint16_t) 0xfc63,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(9, 7);
rd += R_rd_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//COR\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
partInit.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd + 8U) + "] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rd + 8U) + "] | *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 + 8U) + "];\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rd + 8U], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2 + 8U], 32);
		partInit.getAffectedRegisters().add(reg_name[rd + 8U], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(9, 7);
rd += R_rd_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cor" << " # " << ba << (" [rs2=" + std::to_string(rs2) + " | rd=" + std::to_string(rd) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CAND ------------------------------------------------------------------------
static InstructionDefinition cand_rs2_rd (
	ISA16_RV32IMACFD,
	"cand",
	(uint16_t) 0x8c61,
	(uint16_t) 0xfc63,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(9, 7);
rd += R_rd_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CAND\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
partInit.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd + 8U) + "] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rd + 8U) + "] & *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 + 8U) + "];\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rd + 8U], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2 + 8U], 32);
		partInit.getAffectedRegisters().add(reg_name[rd + 8U], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(9, 7);
rd += R_rd_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cand" << " # " << ba << (" [rs2=" + std::to_string(rs2) + " | rd=" + std::to_string(rd) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CJ --------------------------------------------------------------------------
static InstructionDefinition cj_imm (
	ISA16_RV32IMACFD,
	"cj",
	(uint16_t) 0xa001,
	(uint16_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_5(2, 2);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_1(5, 3);
imm += R_imm_1.read(ba) << 1;
static BitArrayRange R_imm_7(6, 6);
imm += R_imm_7.read(ba) << 7;
static BitArrayRange R_imm_6(7, 7);
imm += R_imm_6.read(ba) << 6;
static BitArrayRange R_imm_10(8, 8);
imm += R_imm_10.read(ba) << 10;
static BitArrayRange R_imm_8(10, 9);
imm += R_imm_8.read(ba) << 8;
static BitArrayRange R_imm_4(11, 11);
imm += R_imm_4.read(ba) << 4;
static BitArrayRange R_imm_11(12, 12);
imm += R_imm_11.read(ba) << 11;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CJ\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + ((etiss_int16)((imm) << (4)) >> (4))) + ";\n";
partInit.code() += "return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_5(2, 2);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_1(5, 3);
imm += R_imm_1.read(ba) << 1;
static BitArrayRange R_imm_7(6, 6);
imm += R_imm_7.read(ba) << 7;
static BitArrayRange R_imm_6(7, 7);
imm += R_imm_6.read(ba) << 6;
static BitArrayRange R_imm_10(8, 8);
imm += R_imm_10.read(ba) << 10;
static BitArrayRange R_imm_8(10, 9);
imm += R_imm_8.read(ba) << 8;
static BitArrayRange R_imm_4(11, 11);
imm += R_imm_4.read(ba) << 4;
static BitArrayRange R_imm_11(12, 12);
imm += R_imm_11.read(ba) << 11;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cj" << " # " << ba << (" [imm=" + std::to_string(imm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CBEQZ -----------------------------------------------------------------------
static InstructionDefinition cbeqz_imm_rs1 (
	ISA16_RV32IMACFD,
	"cbeqz",
	(uint16_t) 0xc001,
	(uint16_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_5(2, 2);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_1(4, 3);
imm += R_imm_1.read(ba) << 1;
static BitArrayRange R_imm_6(6, 5);
imm += R_imm_6.read(ba) << 6;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_imm_3(11, 10);
imm += R_imm_3.read(ba) << 3;
static BitArrayRange R_imm_8(12, 12);
imm += R_imm_8.read(ba) << 8;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CBEQZ\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
partInit.code() += "if (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 + 8U) + "] == 0U) {\n";
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + ((etiss_int16)((imm) << (7)) >> (7))) + ";\n";
partInit.code() += "}\n";
partInit.code() += "if (cpu->instructionPointer != " + std::to_string(ic.current_address_ + 2) + ") return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1 + 8U], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_5(2, 2);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_1(4, 3);
imm += R_imm_1.read(ba) << 1;
static BitArrayRange R_imm_6(6, 5);
imm += R_imm_6.read(ba) << 6;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_imm_3(11, 10);
imm += R_imm_3.read(ba) << 3;
static BitArrayRange R_imm_8(12, 12);
imm += R_imm_8.read(ba) << 8;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cbeqz" << " # " << ba << (" [imm=" + std::to_string(imm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CBNEZ -----------------------------------------------------------------------
static InstructionDefinition cbnez_imm_rs1 (
	ISA16_RV32IMACFD,
	"cbnez",
	(uint16_t) 0xe001,
	(uint16_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_5(2, 2);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_1(4, 3);
imm += R_imm_1.read(ba) << 1;
static BitArrayRange R_imm_6(6, 5);
imm += R_imm_6.read(ba) << 6;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_imm_3(11, 10);
imm += R_imm_3.read(ba) << 3;
static BitArrayRange R_imm_8(12, 12);
imm += R_imm_8.read(ba) << 8;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CBNEZ\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
partInit.code() += "if (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 + 8U) + "] != 0U) {\n";
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + ((etiss_int16)((imm) << (7)) >> (7))) + ";\n";
partInit.code() += "}\n";
partInit.code() += "if (cpu->instructionPointer != " + std::to_string(ic.current_address_ + 2) + ") return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1 + 8U], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 imm = 0;
static BitArrayRange R_imm_5(2, 2);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_1(4, 3);
imm += R_imm_1.read(ba) << 1;
static BitArrayRange R_imm_6(6, 5);
imm += R_imm_6.read(ba) << 6;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_imm_3(11, 10);
imm += R_imm_3.read(ba) << 3;
static BitArrayRange R_imm_8(12, 12);
imm += R_imm_8.read(ba) << 8;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cbnez" << " # " << ba << (" [imm=" + std::to_string(imm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CSLLI -----------------------------------------------------------------------
static InstructionDefinition cslli_nzuimm_rs1 (
	ISA16_RV32IMACFD,
	"cslli",
	(uint16_t) 0x02,
	(uint16_t) 0xf003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 nzuimm = 0;
static BitArrayRange R_nzuimm_0(6, 2);
nzuimm += R_nzuimm_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(11, 7);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CSLLI\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
if (nzuimm) {
partInit.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32) + "] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32U) + "] << " + std::to_string(nzuimm) + ";\n";
}
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1 % 32U], 32);
		partInit.getAffectedRegisters().add(reg_name[rs1 % 32], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 nzuimm = 0;
static BitArrayRange R_nzuimm_0(6, 2);
nzuimm += R_nzuimm_0.read(ba) << 0;
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(11, 7);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cslli" << " # " << ba << (" [nzuimm=" + std::to_string(nzuimm) + " | rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CLWSP -----------------------------------------------------------------------
static InstructionDefinition clwsp_uimm_rd (
	ISA16_RV32IMACFD,
	"clwsp",
	(uint16_t) 0x4002,
	(uint16_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 uimm = 0;
static BitArrayRange R_uimm_6(3, 2);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_2(6, 4);
uimm += R_uimm_2.read(ba) << 2;
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
static BitArrayRange R_uimm_5(12, 12);
uimm += R_uimm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CLWSP\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
partInit.code() += "etiss_uint32 offs = *((RV32IMACFD*)cpu)->X[" + std::to_string(2U) + "] + " + std::to_string(uimm) + ";\n";
partInit.code() += "etiss_uint32 mem_val_0;\n";
partInit.code() += "exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
partInit.code() += "etiss_int32 res = mem_val_0;\n";
if (rd % 32U) {
partInit.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "] = res;\n";
} else {
partInit.code() += "exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION;\n";
}
partInit.code() += "if (exception) return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[2U], 32);
		partInit.getAffectedRegisters().add(reg_name[rd % 32], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 uimm = 0;
static BitArrayRange R_uimm_6(3, 2);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_2(6, 4);
uimm += R_uimm_2.read(ba) << 2;
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
static BitArrayRange R_uimm_5(12, 12);
uimm += R_uimm_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "clwsp" << " # " << ba << (" [uimm=" + std::to_string(uimm) + " | rd=" + std::to_string(rd) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CMV -------------------------------------------------------------------------
static InstructionDefinition cmv_rs2_rd (
	ISA16_RV32IMACFD,
	"cmv",
	(uint16_t) 0x8002,
	(uint16_t) 0xf003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(6, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CMV\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
if ((rd % 32U) != 0U) {
partInit.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "];\n";
}
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs2 % 32U], 32);
		partInit.getAffectedRegisters().add(reg_name[rd % 32], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(6, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cmv" << " # " << ba << (" [rs2=" + std::to_string(rs2) + " | rd=" + std::to_string(rd) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CJR -------------------------------------------------------------------------
static InstructionDefinition cjr_rs1 (
	ISA16_RV32IMACFD,
	"cjr",
	(uint16_t) 0x8002,
	(uint16_t) 0xf07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(11, 7);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CJR\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
if (rs1) {
partInit.code() += "cpu->instructionPointer = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32U) + "] & -2U;\n";
} else {
partInit.code() += "exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION;\n";
}
partInit.code() += "return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1 % 32U], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(11, 7);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cjr" << " # " << ba << (" [rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// __reserved_cmv --------------------------------------------------------------
static InstructionDefinition __reserved_cmv_ (
	ISA16_RV32IMACFD,
	"__reserved_cmv",
	(uint16_t) 0x8002,
	(uint16_t) 0xffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//__reserved_cmv\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
partInit.code() += "exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION;\n";
partInit.code() += "if (exception) return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "__reserved_cmv" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CADD ------------------------------------------------------------------------
static InstructionDefinition cadd_rs2_rd (
	ISA16_RV32IMACFD,
	"cadd",
	(uint16_t) 0x9002,
	(uint16_t) 0xf003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(6, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CADD\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
if ((rd % 32U) != 0U) {
partInit.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32) + "] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32U) + "] + *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "];\n";
}
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rd % 32U], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2 % 32U], 32);
		partInit.getAffectedRegisters().add(reg_name[rd % 32], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(6, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint32 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cadd" << " # " << ba << (" [rs2=" + std::to_string(rs2) + " | rd=" + std::to_string(rd) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CJALR -----------------------------------------------------------------------
static InstructionDefinition cjalr_rs1 (
	ISA16_RV32IMACFD,
	"cjalr",
	(uint16_t) 0x9002,
	(uint16_t) 0xf07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(11, 7);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CJALR\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
partInit.code() += "etiss_uint32 new_pc = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32U) + "];\n";
partInit.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(1U) + "] = " + std::to_string(ic.current_address_ + 2U) + ";\n";
partInit.code() += "cpu->instructionPointer = new_pc & -2U;\n";
partInit.code() += "return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[rs1 % 32U], 32);
		partInit.getAffectedRegisters().add(reg_name[1U], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rs1 = 0;
static BitArrayRange R_rs1_0(11, 7);
rs1 += R_rs1_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cjalr" << " # " << ba << (" [rs1=" + std::to_string(rs1) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CEBREAK ---------------------------------------------------------------------
static InstructionDefinition cebreak_ (
	ISA16_RV32IMACFD,
	"cebreak",
	(uint16_t) 0x9002,
	(uint16_t) 0xffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CEBREAK\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
partInit.code() += "exception = ETISS_RETURNCODE_CPUFINISHED;\n";
partInit.code() += "return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cebreak" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CSWSP -----------------------------------------------------------------------
static InstructionDefinition cswsp_rs2_uimm (
	ISA16_RV32IMACFD,
	"cswsp",
	(uint16_t) 0xc002,
	(uint16_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(6, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint32 uimm = 0;
static BitArrayRange R_uimm_6(8, 7);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_2(12, 9);
uimm += R_uimm_2.read(ba) << 2;

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//CSWSP\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
partInit.code() += "etiss_uint32 offs = *((RV32IMACFD*)cpu)->X[" + std::to_string(2U) + "] + " + std::to_string(uimm) + ";\n";
partInit.code() += "etiss_uint32 mem_val_0 = (etiss_uint32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32U) + "]);\n";
partInit.code() += "exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";

partInit.code() += "if (exception) return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getRegisterDependencies().add(reg_name[2U], 32);
		partInit.getRegisterDependencies().add(reg_name[rs2 % 32U], 32);
		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint32 rs2 = 0;
static BitArrayRange R_rs2_0(6, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint32 uimm = 0;
static BitArrayRange R_uimm_6(8, 7);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_2(12, 9);
uimm += R_uimm_2.read(ba) << 2;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cswsp" << " # " << ba << (" [rs2=" + std::to_string(rs2) + " | uimm=" + std::to_string(uimm) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// DII -------------------------------------------------------------------------
static InstructionDefinition dii_ (
	ISA16_RV32IMACFD,
	"dii",
	(uint16_t) 0x00,
	(uint16_t) 0xffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

		CodePart & partInit = cs.append(CodePart::INITIALREQUIRED);

		partInit.code() = std::string("//DII\n");

// -----------------------------------------------------------------------------
partInit.code() += "cpu->instructionPointer = " + std::to_string(ic.current_address_ + 2U) + ";\n";
partInit.code() += "exception = ETISS_RETURNCODE_ILLEGALINSTRUCTION;\n";
partInit.code() += "return exception;\n";
// -----------------------------------------------------------------------------

		partInit.getAffectedRegisters().add("instructionPointer", 32);

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "dii" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
