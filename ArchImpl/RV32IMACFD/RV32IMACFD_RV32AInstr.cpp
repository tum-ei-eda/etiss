// clang-format off
/**
 * Generated on Mon, 27 Apr 2026 10:48:14 +0000.
 *
 * This file contains the instruction behavior models of the RV32A
 * instruction set for the RV32IMACFD core architecture.
 */

#include "RV32IMACFDArch.h"
#include "RV32IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// AMOSWAPW --------------------------------------------------------------------
static InstructionDefinition amoswapw_rd_rs1_rs2_rl_aq (
	ISA32_RV32IMACFD,
	"amoswapw",
	(uint64_t) 0x800202f,
	(uint64_t) 0xf800707f,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOSWAPW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 172);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6829);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 6790, 6789, 6788, 6786);\n";
cp.code() += "etiss_coverage_count(1, 6791);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 6797, 6794, 6792, 6795, 6796);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int32)(((etiss_int32)(mem_val_0)));\n";
cp.code() += "etiss_coverage_count(11, 6814, 6802, 6801, 6799, 6813, 6810, 6808, 6806, 6804, 6805, 6811);\n";
} // conditional
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = (etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(9, 6828, 6820, 6818, 6816, 6817, 6827, 6825, 6824, 6822);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//AMOSWAPW\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amoswapw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOADDW ---------------------------------------------------------------------
static InstructionDefinition amoaddw_rd_rs1_rs2_rl_aq (
	ISA32_RV32IMACFD,
	"amoaddw",
	(uint64_t) 0x00202f,
	(uint64_t) 0xf800707f,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOADDW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 173);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6876);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 6836, 6835, 6834, 6832);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int32 res1 = mem_val_0;\n";
cp.code() += "etiss_coverage_count(5, 6844, 6843, 6841, 6839, 6840);\n";
cp.code() += "etiss_coverage_count(1, 6845);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 6851, 6848, 6846, 6849, 6850);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res1;\n";
cp.code() += "etiss_coverage_count(5, 6858, 6856, 6855, 6853, 6857);\n";
} // conditional
cp.code() += "etiss_uint32 res2 = res1 + *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(6, 6867, 6866, 6860, 6865, 6864, 6862);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(6, 6875, 6873, 6871, 6869, 6870, 6874);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//AMOADDW\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amoaddw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOXORW ---------------------------------------------------------------------
static InstructionDefinition amoxorw_rd_rs1_rs2_rl_aq (
	ISA32_RV32IMACFD,
	"amoxorw",
	(uint64_t) 0x2000202f,
	(uint64_t) 0xf800707f,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOXORW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 174);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6923);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 6883, 6882, 6881, 6879);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int32 res1 = mem_val_0;\n";
cp.code() += "etiss_coverage_count(5, 6891, 6890, 6888, 6886, 6887);\n";
cp.code() += "etiss_coverage_count(1, 6892);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 6898, 6895, 6893, 6896, 6897);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res1;\n";
cp.code() += "etiss_coverage_count(5, 6905, 6903, 6902, 6900, 6904);\n";
} // conditional
cp.code() += "etiss_uint32 res2 = res1 ^ *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(6, 6914, 6913, 6907, 6912, 6911, 6909);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(6, 6922, 6920, 6918, 6916, 6917, 6921);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//AMOXORW\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amoxorw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOANDW ---------------------------------------------------------------------
static InstructionDefinition amoandw_rd_rs1_rs2_rl_aq (
	ISA32_RV32IMACFD,
	"amoandw",
	(uint64_t) 0x6000202f,
	(uint64_t) 0xf800707f,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOANDW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 175);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 6970);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 6930, 6929, 6928, 6926);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int32 res1 = mem_val_0;\n";
cp.code() += "etiss_coverage_count(5, 6938, 6937, 6935, 6933, 6934);\n";
cp.code() += "etiss_coverage_count(1, 6939);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 6945, 6942, 6940, 6943, 6944);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res1;\n";
cp.code() += "etiss_coverage_count(5, 6952, 6950, 6949, 6947, 6951);\n";
} // conditional
cp.code() += "etiss_uint32 res2 = res1 & *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(6, 6961, 6960, 6954, 6959, 6958, 6956);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(6, 6969, 6967, 6965, 6963, 6964, 6968);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//AMOANDW\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amoandw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOORW ----------------------------------------------------------------------
static InstructionDefinition amoorw_rd_rs1_rs2_rl_aq (
	ISA32_RV32IMACFD,
	"amoorw",
	(uint64_t) 0x4000202f,
	(uint64_t) 0xf800707f,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOORW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 176);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7017);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 6977, 6976, 6975, 6973);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int32 res1 = mem_val_0;\n";
cp.code() += "etiss_coverage_count(5, 6985, 6984, 6982, 6980, 6981);\n";
cp.code() += "etiss_coverage_count(1, 6986);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 6992, 6989, 6987, 6990, 6991);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res1;\n";
cp.code() += "etiss_coverage_count(5, 6999, 6997, 6996, 6994, 6998);\n";
} // conditional
cp.code() += "etiss_uint32 res2 = res1 | *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(6, 7008, 7007, 7001, 7006, 7005, 7003);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(6, 7016, 7014, 7012, 7010, 7011, 7015);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//AMOORW\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amoorw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOMINW ---------------------------------------------------------------------
static InstructionDefinition amominw_rd_rs1_rs2_rl_aq (
	ISA32_RV32IMACFD,
	"amominw",
	(uint64_t) 0x8000202f,
	(uint64_t) 0xf800707f,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOMINW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 177);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7073);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 7024, 7023, 7022, 7020);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int32 res1 = mem_val_0;\n";
cp.code() += "etiss_coverage_count(5, 7032, 7031, 7029, 7027, 7028);\n";
cp.code() += "etiss_coverage_count(1, 7033);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 7039, 7036, 7034, 7037, 7038);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res1;\n";
cp.code() += "etiss_coverage_count(5, 7046, 7044, 7043, 7041, 7045);\n";
} // conditional
cp.code() += "etiss_uint32 res2 = (res1 > (etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])) ? (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) : (res1);\n";
cp.code() += "etiss_coverage_count(12, 7064, 7063, 7056, 7048, 7055, 7053, 7052, 7050, 7061, 7060, 7058, 7062);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(6, 7072, 7070, 7068, 7066, 7067, 7071);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//AMOMINW\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amominw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOMAXW ---------------------------------------------------------------------
static InstructionDefinition amomaxw_rd_rs1_rs2_rl_aq (
	ISA32_RV32IMACFD,
	"amomaxw",
	(uint64_t) 0xa000202f,
	(uint64_t) 0xf800707f,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOMAXW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 178);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7129);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 7080, 7079, 7078, 7076);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int32 res1 = mem_val_0;\n";
cp.code() += "etiss_coverage_count(5, 7088, 7087, 7085, 7083, 7084);\n";
cp.code() += "etiss_coverage_count(1, 7089);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 7095, 7092, 7090, 7093, 7094);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res1;\n";
cp.code() += "etiss_coverage_count(5, 7102, 7100, 7099, 7097, 7101);\n";
} // conditional
cp.code() += "etiss_uint32 res2 = (res1 < (etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])) ? (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) : (res1);\n";
cp.code() += "etiss_coverage_count(12, 7120, 7119, 7112, 7104, 7111, 7109, 7108, 7106, 7117, 7116, 7114, 7118);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(6, 7128, 7126, 7124, 7122, 7123, 7127);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//AMOMAXW\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amomaxw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOMINUW --------------------------------------------------------------------
static InstructionDefinition amominuw_rd_rs1_rs2_rl_aq (
	ISA32_RV32IMACFD,
	"amominuw",
	(uint64_t) 0xc000202f,
	(uint64_t) 0xf800707f,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOMINUW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 179);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7187);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 7136, 7135, 7134, 7132);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 res1 = mem_val_0;\n";
cp.code() += "etiss_coverage_count(5, 7144, 7143, 7141, 7139, 7140);\n";
cp.code() += "etiss_coverage_count(1, 7145);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 7151, 7148, 7146, 7149, 7150);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int32)(res1);\n";
cp.code() += "etiss_coverage_count(6, 7160, 7156, 7155, 7153, 7159, 7157);\n";
} // conditional
cp.code() += "etiss_uint32 res2 = (res1 > (etiss_uint32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])) ? (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) : (res1);\n";
cp.code() += "etiss_coverage_count(12, 7178, 7177, 7170, 7162, 7169, 7167, 7166, 7164, 7175, 7174, 7172, 7176);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(6, 7186, 7184, 7182, 7180, 7181, 7185);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//AMOMINUW\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amominuw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// AMOMAXUW --------------------------------------------------------------------
static InstructionDefinition amomaxuw_rd_rs1_rs2_rl_aq (
	ISA32_RV32IMACFD,
	"amomaxuw",
	(uint64_t) 0xe000202f,
	(uint64_t) 0xf800707f,
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOMAXUW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 180);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1189);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1188, 1181, 1187, 1184, 1182, 1183, 1185);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 7245);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 7194, 7193, 7192, 7190);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 res1 = mem_val_0;\n";
cp.code() += "etiss_coverage_count(5, 7202, 7201, 7199, 7197, 7198);\n";
cp.code() += "etiss_coverage_count(1, 7203);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 7209, 7206, 7204, 7207, 7208);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int32)(res1);\n";
cp.code() += "etiss_coverage_count(6, 7218, 7214, 7213, 7211, 7217, 7215);\n";
} // conditional
cp.code() += "etiss_uint32 res2 = (res1 < (etiss_uint32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])) ? (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) : (res1);\n";
cp.code() += "etiss_coverage_count(12, 7236, 7235, 7228, 7220, 7227, 7225, 7224, 7222, 7233, 7232, 7230, 7234);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(6, 7244, 7242, 7240, 7238, 7239, 7243);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//AMOMAXUW\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception) return cpu->exception;\n";
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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rl = 0;
static BitArrayRange R_rl_0(25, 25);
rl += R_rl_0.read(ba) << 0;
etiss_uint8 aq = 0;
static BitArrayRange R_aq_0(26, 26);
aq += R_aq_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "amomaxuw" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + " | rl=" + std::to_string(rl) + " | aq=" + std::to_string(aq) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
// clang-format on
