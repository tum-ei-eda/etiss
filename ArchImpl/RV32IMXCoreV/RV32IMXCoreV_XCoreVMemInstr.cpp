// clang-format off
/**
 * Generated on Wed, 05 Aug 2026 14:25:16 +0200.
 *
 * This file contains the instruction behavior models of the XCoreVMem
 * instruction set for the RV32IMXCoreV core architecture.
 */

#include "RV32IMXCoreVArch.h"
#include "RV32IMXCoreVFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// CV_LB_ri_inc ----------------------------------------------------------------
static InstructionDefinition cv_lb_ri_inc_rd_rs1_imm12 (
	ISA32_RV32IMXCoreV,
	"cv_lb_ri_inc",
	(uint64_t) 0x00000b,
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
etiss_uint16 imm12 = 0;
static BitArrayRange R_imm12_0(31, 20);
imm12 += R_imm12_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_LB_ri_inc\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 417);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25764);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 load_address = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(3, 25739, 25738, 25737);\n";
cp.code() += "etiss_uint8 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 1);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int8 res = (etiss_int8)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(4, 25746, 25745, 25743, 25742);\n";
cp.code() += "etiss_coverage_count(1, 25747);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25750, 25748, 25749);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(res);\n";
cp.code() += "etiss_coverage_count(5, 25757, 25753, 25752, 25756, 25754);\n";
} // conditional
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm12) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 25763, 25760, 25759, 25759, 25762, 25761);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CV_LB_ri_inc\n");

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
etiss_uint16 imm12 = 0;
static BitArrayRange R_imm12_0(31, 20);
imm12 += R_imm12_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_lb_ri_inc" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | imm12=" + std::to_string(imm12) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_LBU_ri_inc ---------------------------------------------------------------
static InstructionDefinition cv_lbu_ri_inc_rd_rs1_imm12 (
	ISA32_RV32IMXCoreV,
	"cv_lbu_ri_inc",
	(uint64_t) 0x00400b,
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
etiss_uint16 imm12 = 0;
static BitArrayRange R_imm12_0(31, 20);
imm12 += R_imm12_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_LBU_ri_inc\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 418);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25794);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 load_address = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(3, 25769, 25768, 25767);\n";
cp.code() += "etiss_uint8 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 1);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint8 res = (etiss_uint8)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(4, 25776, 25775, 25773, 25772);\n";
cp.code() += "etiss_coverage_count(1, 25777);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25780, 25778, 25779);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(res);\n";
cp.code() += "etiss_coverage_count(5, 25787, 25783, 25782, 25786, 25784);\n";
} // conditional
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm12) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 25793, 25790, 25789, 25789, 25792, 25791);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CV_LBU_ri_inc\n");

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
etiss_uint16 imm12 = 0;
static BitArrayRange R_imm12_0(31, 20);
imm12 += R_imm12_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_lbu_ri_inc" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | imm12=" + std::to_string(imm12) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_LH_ri_inc ----------------------------------------------------------------
static InstructionDefinition cv_lh_ri_inc_rd_rs1_imm12 (
	ISA32_RV32IMXCoreV,
	"cv_lh_ri_inc",
	(uint64_t) 0x00100b,
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
etiss_uint16 imm12 = 0;
static BitArrayRange R_imm12_0(31, 20);
imm12 += R_imm12_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_LH_ri_inc\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 419);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25827);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 load_address = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(3, 25799, 25798, 25797);\n";
cp.code() += "etiss_uint16 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 2);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int16 res = (etiss_int16)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(6, 25809, 25808, 25806, 25804, 25802, 25803);\n";
cp.code() += "etiss_coverage_count(1, 25810);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25813, 25811, 25812);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(res);\n";
cp.code() += "etiss_coverage_count(5, 25820, 25816, 25815, 25819, 25817);\n";
} // conditional
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm12) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 25826, 25823, 25822, 25822, 25825, 25824);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CV_LH_ri_inc\n");

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
etiss_uint16 imm12 = 0;
static BitArrayRange R_imm12_0(31, 20);
imm12 += R_imm12_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_lh_ri_inc" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | imm12=" + std::to_string(imm12) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_LHU_ri_inc ---------------------------------------------------------------
static InstructionDefinition cv_lhu_ri_inc_rd_rs1_imm12 (
	ISA32_RV32IMXCoreV,
	"cv_lhu_ri_inc",
	(uint64_t) 0x00500b,
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
etiss_uint16 imm12 = 0;
static BitArrayRange R_imm12_0(31, 20);
imm12 += R_imm12_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_LHU_ri_inc\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 420);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25860);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 load_address = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(3, 25832, 25831, 25830);\n";
cp.code() += "etiss_uint16 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 2);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint16 res = (etiss_uint16)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(6, 25842, 25841, 25839, 25837, 25835, 25836);\n";
cp.code() += "etiss_coverage_count(1, 25843);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25846, 25844, 25845);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(res);\n";
cp.code() += "etiss_coverage_count(5, 25853, 25849, 25848, 25852, 25850);\n";
} // conditional
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm12) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 25859, 25856, 25855, 25855, 25858, 25857);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CV_LHU_ri_inc\n");

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
etiss_uint16 imm12 = 0;
static BitArrayRange R_imm12_0(31, 20);
imm12 += R_imm12_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_lhu_ri_inc" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | imm12=" + std::to_string(imm12) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_LW_ri_inc ----------------------------------------------------------------
static InstructionDefinition cv_lw_ri_inc_rd_rs1_imm12 (
	ISA32_RV32IMXCoreV,
	"cv_lw_ri_inc",
	(uint64_t) 0x00200b,
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
etiss_uint16 imm12 = 0;
static BitArrayRange R_imm12_0(31, 20);
imm12 += R_imm12_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_LW_ri_inc\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 421);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25893);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 load_address = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(3, 25865, 25864, 25863);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int32 res = (etiss_int32)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(6, 25875, 25874, 25872, 25870, 25868, 25869);\n";
cp.code() += "etiss_coverage_count(1, 25876);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25879, 25877, 25878);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(res);\n";
cp.code() += "etiss_coverage_count(5, 25886, 25882, 25881, 25885, 25883);\n";
} // conditional
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm12) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 25892, 25889, 25888, 25888, 25891, 25890);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CV_LW_ri_inc\n");

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
etiss_uint16 imm12 = 0;
static BitArrayRange R_imm12_0(31, 20);
imm12 += R_imm12_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_lw_ri_inc" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | imm12=" + std::to_string(imm12) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_LB_rr_inc ----------------------------------------------------------------
static InstructionDefinition cv_lb_rr_inc_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_lb_rr_inc",
	(uint64_t) 0x00302b,
	(uint64_t) 0xfe00707f,
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

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_LB_rr_inc\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 422);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25925);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 load_address = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(3, 25898, 25897, 25896);\n";
cp.code() += "etiss_uint8 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 1);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int8 res = (etiss_int8)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(4, 25905, 25904, 25902, 25901);\n";
cp.code() += "etiss_coverage_count(1, 25906);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25909, 25907, 25908);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(res);\n";
cp.code() += "etiss_coverage_count(5, 25916, 25912, 25911, 25915, 25913);\n";
} // conditional
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(7, 25924, 25919, 25918, 25918, 25923, 25922, 25921);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CV_LB_rr_inc\n");

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

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_lb_rr_inc" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_LBU_rr_inc ---------------------------------------------------------------
static InstructionDefinition cv_lbu_rr_inc_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_lbu_rr_inc",
	(uint64_t) 0x1000302b,
	(uint64_t) 0xfe00707f,
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

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_LBU_rr_inc\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 423);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25957);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 load_address = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(3, 25930, 25929, 25928);\n";
cp.code() += "etiss_uint8 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 1);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint8 res = (etiss_uint8)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(4, 25937, 25936, 25934, 25933);\n";
cp.code() += "etiss_coverage_count(1, 25938);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25941, 25939, 25940);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(res);\n";
cp.code() += "etiss_coverage_count(5, 25948, 25944, 25943, 25947, 25945);\n";
} // conditional
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(7, 25956, 25951, 25950, 25950, 25955, 25954, 25953);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CV_LBU_rr_inc\n");

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

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_lbu_rr_inc" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_LH_rr_inc ----------------------------------------------------------------
static InstructionDefinition cv_lh_rr_inc_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_lh_rr_inc",
	(uint64_t) 0x200302b,
	(uint64_t) 0xfe00707f,
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

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_LH_rr_inc\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 424);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 25992);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 load_address = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(3, 25962, 25961, 25960);\n";
cp.code() += "etiss_uint16 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 2);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int16 res = (etiss_int16)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(6, 25972, 25971, 25969, 25967, 25965, 25966);\n";
cp.code() += "etiss_coverage_count(1, 25973);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 25976, 25974, 25975);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(res);\n";
cp.code() += "etiss_coverage_count(5, 25983, 25979, 25978, 25982, 25980);\n";
} // conditional
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(7, 25991, 25986, 25985, 25985, 25990, 25989, 25988);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CV_LH_rr_inc\n");

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

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_lh_rr_inc" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_LHU_rr_inc ---------------------------------------------------------------
static InstructionDefinition cv_lhu_rr_inc_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_lhu_rr_inc",
	(uint64_t) 0x1200302b,
	(uint64_t) 0xfe00707f,
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

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_LHU_rr_inc\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 425);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26027);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 load_address = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(3, 25997, 25996, 25995);\n";
cp.code() += "etiss_uint16 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 2);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint16 res = (etiss_uint16)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(6, 26007, 26006, 26004, 26002, 26000, 26001);\n";
cp.code() += "etiss_coverage_count(1, 26008);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 26011, 26009, 26010);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(res);\n";
cp.code() += "etiss_coverage_count(5, 26018, 26014, 26013, 26017, 26015);\n";
} // conditional
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(7, 26026, 26021, 26020, 26020, 26025, 26024, 26023);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CV_LHU_rr_inc\n");

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

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_lhu_rr_inc" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_LW_rr_inc ----------------------------------------------------------------
static InstructionDefinition cv_lw_rr_inc_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_lw_rr_inc",
	(uint64_t) 0x400302b,
	(uint64_t) 0xfe00707f,
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

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_LW_rr_inc\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 426);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26062);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 load_address = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(3, 26032, 26031, 26030);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int32 res = (etiss_int32)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(6, 26042, 26041, 26039, 26037, 26035, 26036);\n";
cp.code() += "etiss_coverage_count(1, 26043);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 26046, 26044, 26045);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(res);\n";
cp.code() += "etiss_coverage_count(5, 26053, 26049, 26048, 26052, 26050);\n";
} // conditional
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(7, 26061, 26056, 26055, 26055, 26060, 26059, 26058);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CV_LW_rr_inc\n");

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

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_lw_rr_inc" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_LB_rr --------------------------------------------------------------------
static InstructionDefinition cv_lb_rr_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_lb_rr",
	(uint64_t) 0x800302b,
	(uint64_t) 0xfe00707f,
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

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_LB_rr\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 427);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26090);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 load_address = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL];\n";
cp.code() += "etiss_coverage_count(6, 26071, 26070, 26066, 26065, 26069, 26068);\n";
cp.code() += "etiss_uint8 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 1);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int8 res = (etiss_int8)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(4, 26078, 26077, 26075, 26074);\n";
cp.code() += "etiss_coverage_count(1, 26079);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 26082, 26080, 26081);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(res);\n";
cp.code() += "etiss_coverage_count(5, 26089, 26085, 26084, 26088, 26086);\n";
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CV_LB_rr\n");

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

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_lb_rr" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_LBU_rr -------------------------------------------------------------------
static InstructionDefinition cv_lbu_rr_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_lbu_rr",
	(uint64_t) 0x1800302b,
	(uint64_t) 0xfe00707f,
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

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_LBU_rr\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 428);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26118);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 load_address = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL];\n";
cp.code() += "etiss_coverage_count(6, 26099, 26098, 26094, 26093, 26097, 26096);\n";
cp.code() += "etiss_uint8 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 1);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint8 res = (etiss_uint8)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(4, 26106, 26105, 26103, 26102);\n";
cp.code() += "etiss_coverage_count(1, 26107);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 26110, 26108, 26109);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(res);\n";
cp.code() += "etiss_coverage_count(5, 26117, 26113, 26112, 26116, 26114);\n";
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CV_LBU_rr\n");

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

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_lbu_rr" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_LH_rr --------------------------------------------------------------------
static InstructionDefinition cv_lh_rr_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_lh_rr",
	(uint64_t) 0xa00302b,
	(uint64_t) 0xfe00707f,
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

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_LH_rr\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 429);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26149);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 load_address = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL];\n";
cp.code() += "etiss_coverage_count(6, 26127, 26126, 26122, 26121, 26125, 26124);\n";
cp.code() += "etiss_uint16 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 2);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int16 res = (etiss_int16)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(6, 26137, 26136, 26134, 26132, 26130, 26131);\n";
cp.code() += "etiss_coverage_count(1, 26138);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 26141, 26139, 26140);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(res);\n";
cp.code() += "etiss_coverage_count(5, 26148, 26144, 26143, 26147, 26145);\n";
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CV_LH_rr\n");

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

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_lh_rr" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_LHU_rr -------------------------------------------------------------------
static InstructionDefinition cv_lhu_rr_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_lhu_rr",
	(uint64_t) 0x1a00302b,
	(uint64_t) 0xfe00707f,
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

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_LHU_rr\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 430);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26180);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 load_address = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL];\n";
cp.code() += "etiss_coverage_count(6, 26158, 26157, 26153, 26152, 26156, 26155);\n";
cp.code() += "etiss_uint16 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 2);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint16 res = (etiss_uint16)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(6, 26168, 26167, 26165, 26163, 26161, 26162);\n";
cp.code() += "etiss_coverage_count(1, 26169);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 26172, 26170, 26171);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(res);\n";
cp.code() += "etiss_coverage_count(5, 26179, 26175, 26174, 26178, 26176);\n";
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CV_LHU_rr\n");

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

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_lhu_rr" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_LW_rr --------------------------------------------------------------------
static InstructionDefinition cv_lw_rr_rd_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_lw_rr",
	(uint64_t) 0xc00302b,
	(uint64_t) 0xfe00707f,
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

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_LW_rr\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 431);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26211);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 load_address = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL];\n";
cp.code() += "etiss_coverage_count(6, 26189, 26188, 26184, 26183, 26187, 26186);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int32 res = (etiss_int32)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(6, 26199, 26198, 26196, 26194, 26192, 26193);\n";
cp.code() += "etiss_coverage_count(1, 26200);\n";
if (rd != 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 26203, 26201, 26202);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rd) + "ULL] = (etiss_uint32)(res);\n";
cp.code() += "etiss_coverage_count(5, 26210, 26206, 26205, 26209, 26207);\n";
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CV_LW_rr\n");

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

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_lw_rr" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SB_ri_inc ----------------------------------------------------------------
static InstructionDefinition cv_sb_ri_inc_imm12_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sb_ri_inc",
	(uint64_t) 0x00002b,
	(uint64_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint16 imm12 = 0;
static BitArrayRange R_imm12_0(11, 7);
imm12 += R_imm12_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm12_5(31, 25);
imm12 += R_imm12_5.read(ba) << 5;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SB_ri_inc\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 432);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26232);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 store_address = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(3, 26216, 26215, 26214);\n";
cp.code() += "etiss_uint8 mem_val_0;\n";
cp.code() += "mem_val_0 = (etiss_int8)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(6, 26225, 26219, 26218, 26224, 26222, 26221);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, store_address, (etiss_uint8*)&mem_val_0, 1);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm12) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 26231, 26228, 26227, 26227, 26230, 26229);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CV_SB_ri_inc\n");

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
etiss_uint16 imm12 = 0;
static BitArrayRange R_imm12_0(11, 7);
imm12 += R_imm12_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm12_5(31, 25);
imm12 += R_imm12_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_sb_ri_inc" << " # " << ba << (" [imm12=" + std::to_string(imm12) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SH_ri_inc ----------------------------------------------------------------
static InstructionDefinition cv_sh_ri_inc_imm12_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sh_ri_inc",
	(uint64_t) 0x00102b,
	(uint64_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint16 imm12 = 0;
static BitArrayRange R_imm12_0(11, 7);
imm12 += R_imm12_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm12_5(31, 25);
imm12 += R_imm12_5.read(ba) << 5;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SH_ri_inc\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 433);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26256);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 store_address = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(3, 26237, 26236, 26235);\n";
cp.code() += "etiss_uint16 mem_val_0;\n";
cp.code() += "mem_val_0 = (etiss_int16)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(8, 26249, 26243, 26241, 26239, 26240, 26248, 26246, 26245);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, store_address, (etiss_uint8*)&mem_val_0, 2);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm12) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 26255, 26252, 26251, 26251, 26254, 26253);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CV_SH_ri_inc\n");

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
etiss_uint16 imm12 = 0;
static BitArrayRange R_imm12_0(11, 7);
imm12 += R_imm12_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm12_5(31, 25);
imm12 += R_imm12_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_sh_ri_inc" << " # " << ba << (" [imm12=" + std::to_string(imm12) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SW_ri_inc ----------------------------------------------------------------
static InstructionDefinition cv_sw_ri_inc_imm12_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sw_ri_inc",
	(uint64_t) 0x00202b,
	(uint64_t) 0x00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint16 imm12 = 0;
static BitArrayRange R_imm12_0(11, 7);
imm12 += R_imm12_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm12_5(31, 25);
imm12 += R_imm12_5.read(ba) << 5;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SW_ri_inc\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 434);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26280);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 store_address = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(3, 26261, 26260, 26259);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "mem_val_0 = (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(8, 26273, 26267, 26265, 26263, 26264, 26272, 26270, 26269);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, store_address, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)imm12) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 26279, 26276, 26275, 26275, 26278, 26277);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CV_SW_ri_inc\n");

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
etiss_uint16 imm12 = 0;
static BitArrayRange R_imm12_0(11, 7);
imm12 += R_imm12_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;
static BitArrayRange R_imm12_5(31, 25);
imm12 += R_imm12_5.read(ba) << 5;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_sw_ri_inc" << " # " << ba << (" [imm12=" + std::to_string(imm12) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SB_rr_inc ----------------------------------------------------------------
static InstructionDefinition cv_sb_rr_inc_rs3_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sb_rr_inc",
	(uint64_t) 0x2000302b,
	(uint64_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(11, 7);
rs3 += R_rs3_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SB_rr_inc\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 435);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26303);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 store_address = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(3, 26285, 26284, 26283);\n";
cp.code() += "etiss_uint8 mem_val_0;\n";
cp.code() += "mem_val_0 = (etiss_int8)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(6, 26294, 26288, 26287, 26293, 26291, 26290);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, store_address, (etiss_uint8*)&mem_val_0, 1);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs3) + "ULL]);\n";
cp.code() += "etiss_coverage_count(7, 26302, 26297, 26296, 26296, 26301, 26300, 26299);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CV_SB_rr_inc\n");

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
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(11, 7);
rs3 += R_rs3_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_sb_rr_inc" << " # " << ba << (" [rs3=" + std::to_string(rs3) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SH_rr_inc ----------------------------------------------------------------
static InstructionDefinition cv_sh_rr_inc_rs3_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sh_rr_inc",
	(uint64_t) 0x2200302b,
	(uint64_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(11, 7);
rs3 += R_rs3_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SH_rr_inc\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 436);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26329);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 store_address = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(3, 26308, 26307, 26306);\n";
cp.code() += "etiss_uint16 mem_val_0;\n";
cp.code() += "mem_val_0 = (etiss_int16)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(8, 26320, 26314, 26312, 26310, 26311, 26319, 26317, 26316);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, store_address, (etiss_uint8*)&mem_val_0, 2);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs3) + "ULL]);\n";
cp.code() += "etiss_coverage_count(7, 26328, 26323, 26322, 26322, 26327, 26326, 26325);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CV_SH_rr_inc\n");

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
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(11, 7);
rs3 += R_rs3_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_sh_rr_inc" << " # " << ba << (" [rs3=" + std::to_string(rs3) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SW_rr_inc ----------------------------------------------------------------
static InstructionDefinition cv_sw_rr_inc_rs3_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sw_rr_inc",
	(uint64_t) 0x2400302b,
	(uint64_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(11, 7);
rs3 += R_rs3_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SW_rr_inc\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 437);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26355);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 store_address = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL];\n";
cp.code() += "etiss_coverage_count(3, 26334, 26333, 26332);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "mem_val_0 = (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(8, 26346, 26340, 26338, 26336, 26337, 26345, 26343, 26342);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, store_address, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs3) + "ULL]);\n";
cp.code() += "etiss_coverage_count(7, 26354, 26349, 26348, 26348, 26353, 26352, 26351);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CV_SW_rr_inc\n");

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
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(11, 7);
rs3 += R_rs3_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_sw_rr_inc" << " # " << ba << (" [rs3=" + std::to_string(rs3) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SB_rr --------------------------------------------------------------------
static InstructionDefinition cv_sb_rr_rs3_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sb_rr",
	(uint64_t) 0x2800302b,
	(uint64_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(11, 7);
rs3 += R_rs3_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SB_rr\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 438);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26374);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 store_address = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs3) + "ULL];\n";
cp.code() += "etiss_coverage_count(6, 26364, 26363, 26359, 26358, 26362, 26361);\n";
cp.code() += "etiss_uint8 mem_val_0;\n";
cp.code() += "mem_val_0 = (etiss_int8)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(6, 26373, 26367, 26366, 26372, 26370, 26369);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, store_address, (etiss_uint8*)&mem_val_0, 1);\n";
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

		cp.code() = std::string("//CV_SB_rr\n");

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
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(11, 7);
rs3 += R_rs3_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_sb_rr" << " # " << ba << (" [rs3=" + std::to_string(rs3) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SH_rr --------------------------------------------------------------------
static InstructionDefinition cv_sh_rr_rs3_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sh_rr",
	(uint64_t) 0x2a00302b,
	(uint64_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(11, 7);
rs3 += R_rs3_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SH_rr\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 439);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26396);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 store_address = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs3) + "ULL];\n";
cp.code() += "etiss_coverage_count(6, 26383, 26382, 26378, 26377, 26381, 26380);\n";
cp.code() += "etiss_uint16 mem_val_0;\n";
cp.code() += "mem_val_0 = (etiss_int16)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(8, 26395, 26389, 26387, 26385, 26386, 26394, 26392, 26391);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, store_address, (etiss_uint8*)&mem_val_0, 2);\n";
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

		cp.code() = std::string("//CV_SH_rr\n");

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
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(11, 7);
rs3 += R_rs3_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_sh_rr" << " # " << ba << (" [rs3=" + std::to_string(rs3) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CV_SW_rr --------------------------------------------------------------------
static InstructionDefinition cv_sw_rr_rs3_rs1_rs2 (
	ISA32_RV32IMXCoreV,
	"cv_sw_rr",
	(uint64_t) 0x2c00302b,
	(uint64_t) 0xfe00707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(11, 7);
rs3 += R_rs3_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CV_SW_rr\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 440);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 26418);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 store_address = *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs1) + "ULL] + *((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs3) + "ULL];\n";
cp.code() += "etiss_coverage_count(6, 26405, 26404, 26400, 26399, 26403, 26402);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "mem_val_0 = (etiss_int32)(*((RV32IMXCoreV*)cpu)->X[" + std::to_string(rs2) + "ULL]);\n";
cp.code() += "etiss_coverage_count(8, 26417, 26411, 26409, 26407, 26408, 26416, 26414, 26413);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, store_address, (etiss_uint8*)&mem_val_0, 4);\n";
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

		cp.code() = std::string("//CV_SW_rr\n");

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
etiss_uint8 rs3 = 0;
static BitArrayRange R_rs3_0(11, 7);
rs3 += R_rs3_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(19, 15);
rs1 += R_rs1_0.read(ba) << 0;
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(24, 20);
rs2 += R_rs2_0.read(ba) << 0;

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "cv_sw_rr" << " # " << ba << (" [rs3=" + std::to_string(rs3) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
// clang-format on
