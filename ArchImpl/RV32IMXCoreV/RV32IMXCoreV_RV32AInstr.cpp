// clang-format off
/**
 * Generated on Tue, 04 Aug 2026 12:23:10 +0200.
 *
 * This file contains the instruction behavior models of the RV32A
 * instruction set for the RV32IMXCoreV core architecture.
 */

#include "RV32IMXCoreVArch.h"
#include "RV32IMXCoreVFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// AMOSWAPW --------------------------------------------------------------------
static InstructionDefinition amoswapw_rd_rs1_rs2_rl_aq (
	ISA32_RV32IMXCoreV,
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
cp.code() += "etiss_coverage_count(1, 471);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1428);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1427, 1420, 1426, 1423, 1421, 1422, 1424);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26780);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 26741, 26740, 26739, 26737);\n";
cp.code() += "etiss_coverage_count(1, 26742);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 26748, 26745, 26743, 26746, 26747);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int32)(((etiss_int32)(mem_val_0)));\n";
cp.code() += "etiss_coverage_count(11, 26765, 26753, 26752, 26750, 26764, 26761, 26759, 26757, 26755, 26756, 26762);\n";
} // conditional
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(9, 26779, 26771, 26769, 26767, 26768, 26778, 26776, 26775, 26773);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
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
	ISA32_RV32IMXCoreV,
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
cp.code() += "etiss_coverage_count(1, 472);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1428);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1427, 1420, 1426, 1423, 1421, 1422, 1424);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26827);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 26787, 26786, 26785, 26783);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int32 res1 = mem_val_0;\n";
cp.code() += "etiss_coverage_count(5, 26795, 26794, 26792, 26790, 26791);\n";
cp.code() += "etiss_coverage_count(1, 26796);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 26802, 26799, 26797, 26800, 26801);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res1;\n";
cp.code() += "etiss_coverage_count(5, 26809, 26807, 26806, 26804, 26808);\n";
} // conditional
cp.code() += "etiss_uint32 res2 = res1 + *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(6, 26818, 26817, 26811, 26816, 26815, 26813);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(6, 26826, 26824, 26822, 26820, 26821, 26825);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
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
	ISA32_RV32IMXCoreV,
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
cp.code() += "etiss_coverage_count(1, 473);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1428);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1427, 1420, 1426, 1423, 1421, 1422, 1424);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26874);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 26834, 26833, 26832, 26830);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int32 res1 = mem_val_0;\n";
cp.code() += "etiss_coverage_count(5, 26842, 26841, 26839, 26837, 26838);\n";
cp.code() += "etiss_coverage_count(1, 26843);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 26849, 26846, 26844, 26847, 26848);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res1;\n";
cp.code() += "etiss_coverage_count(5, 26856, 26854, 26853, 26851, 26855);\n";
} // conditional
cp.code() += "etiss_uint32 res2 = res1 ^ *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(6, 26865, 26864, 26858, 26863, 26862, 26860);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(6, 26873, 26871, 26869, 26867, 26868, 26872);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
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
	ISA32_RV32IMXCoreV,
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
cp.code() += "etiss_coverage_count(1, 474);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1428);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1427, 1420, 1426, 1423, 1421, 1422, 1424);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26921);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 26881, 26880, 26879, 26877);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int32 res1 = mem_val_0;\n";
cp.code() += "etiss_coverage_count(5, 26889, 26888, 26886, 26884, 26885);\n";
cp.code() += "etiss_coverage_count(1, 26890);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 26896, 26893, 26891, 26894, 26895);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res1;\n";
cp.code() += "etiss_coverage_count(5, 26903, 26901, 26900, 26898, 26902);\n";
} // conditional
cp.code() += "etiss_uint32 res2 = res1 & *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(6, 26912, 26911, 26905, 26910, 26909, 26907);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(6, 26920, 26918, 26916, 26914, 26915, 26919);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
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
	ISA32_RV32IMXCoreV,
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
cp.code() += "etiss_coverage_count(1, 475);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1428);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1427, 1420, 1426, 1423, 1421, 1422, 1424);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26968);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 26928, 26927, 26926, 26924);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int32 res1 = mem_val_0;\n";
cp.code() += "etiss_coverage_count(5, 26936, 26935, 26933, 26931, 26932);\n";
cp.code() += "etiss_coverage_count(1, 26937);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 26943, 26940, 26938, 26941, 26942);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res1;\n";
cp.code() += "etiss_coverage_count(5, 26950, 26948, 26947, 26945, 26949);\n";
} // conditional
cp.code() += "etiss_uint32 res2 = res1 | *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(6, 26959, 26958, 26952, 26957, 26956, 26954);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(6, 26967, 26965, 26963, 26961, 26962, 26966);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
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
	ISA32_RV32IMXCoreV,
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
cp.code() += "etiss_coverage_count(1, 476);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1428);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1427, 1420, 1426, 1423, 1421, 1422, 1424);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27024);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 26975, 26974, 26973, 26971);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int32 res1 = mem_val_0;\n";
cp.code() += "etiss_coverage_count(5, 26983, 26982, 26980, 26978, 26979);\n";
cp.code() += "etiss_coverage_count(1, 26984);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 26990, 26987, 26985, 26988, 26989);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res1;\n";
cp.code() += "etiss_coverage_count(5, 26997, 26995, 26994, 26992, 26996);\n";
} // conditional
cp.code() += "etiss_uint32 res2 = (res1 > (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])) ? (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) : (res1);\n";
cp.code() += "etiss_coverage_count(12, 27015, 27014, 27007, 26999, 27006, 27004, 27003, 27001, 27012, 27011, 27009, 27013);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(6, 27023, 27021, 27019, 27017, 27018, 27022);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
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
	ISA32_RV32IMXCoreV,
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
cp.code() += "etiss_coverage_count(1, 477);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1428);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1427, 1420, 1426, 1423, 1421, 1422, 1424);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27080);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 27031, 27030, 27029, 27027);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int32 res1 = mem_val_0;\n";
cp.code() += "etiss_coverage_count(5, 27039, 27038, 27036, 27034, 27035);\n";
cp.code() += "etiss_coverage_count(1, 27040);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 27046, 27043, 27041, 27044, 27045);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res1;\n";
cp.code() += "etiss_coverage_count(5, 27053, 27051, 27050, 27048, 27052);\n";
} // conditional
cp.code() += "etiss_uint32 res2 = (res1 < (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])) ? (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) : (res1);\n";
cp.code() += "etiss_coverage_count(12, 27071, 27070, 27063, 27055, 27062, 27060, 27059, 27057, 27068, 27067, 27065, 27069);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(6, 27079, 27077, 27075, 27073, 27074, 27078);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
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
	ISA32_RV32IMXCoreV,
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
cp.code() += "etiss_coverage_count(1, 478);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1428);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1427, 1420, 1426, 1423, 1421, 1422, 1424);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27138);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 27087, 27086, 27085, 27083);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 res1 = mem_val_0;\n";
cp.code() += "etiss_coverage_count(5, 27095, 27094, 27092, 27090, 27091);\n";
cp.code() += "etiss_coverage_count(1, 27096);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 27102, 27099, 27097, 27100, 27101);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int32)(res1);\n";
cp.code() += "etiss_coverage_count(6, 27111, 27107, 27106, 27104, 27110, 27108);\n";
} // conditional
cp.code() += "etiss_uint32 res2 = (res1 > (etiss_uint32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])) ? (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) : (res1);\n";
cp.code() += "etiss_coverage_count(12, 27129, 27128, 27121, 27113, 27120, 27118, 27117, 27115, 27126, 27125, 27123, 27127);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(6, 27137, 27135, 27133, 27131, 27132, 27136);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
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
	ISA32_RV32IMXCoreV,
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
cp.code() += "etiss_coverage_count(1, 479);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1428);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1427, 1420, 1426, 1423, 1421, 1422, 1424);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 27196);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 27145, 27144, 27143, 27141);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 res1 = mem_val_0;\n";
cp.code() += "etiss_coverage_count(5, 27153, 27152, 27150, 27148, 27149);\n";
cp.code() += "etiss_coverage_count(1, 27154);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 27160, 27157, 27155, 27158, 27159);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int32)(res1);\n";
cp.code() += "etiss_coverage_count(6, 27169, 27165, 27164, 27162, 27168, 27166);\n";
} // conditional
cp.code() += "etiss_uint32 res2 = (res1 < (etiss_uint32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])) ? (*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) : (res1);\n";
cp.code() += "etiss_coverage_count(12, 27187, 27186, 27179, 27171, 27178, 27176, 27175, 27173, 27184, 27183, 27181, 27185);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(6, 27195, 27193, 27191, 27189, 27190, 27194);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_1, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
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
