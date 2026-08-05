// clang-format off
/**
 * Generated on Wed, 05 Aug 2026 14:25:16 +0200.
 *
 * This file contains the instruction behavior models of the tum_semihosting
 * instruction set for the RV32IMXCoreV core architecture.
 */

#include "RV32IMXCoreVArch.h"
#include "RV32IMXCoreVFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// EBREAK ----------------------------------------------------------------------
static InstructionDefinition ebreak_ (
	ISA32_RV32IMXCoreV,
	"ebreak",
	(uint64_t) 0x100073,
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

		cp.code() = std::string("//EBREAK\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 497);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1469);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 4))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1468, 1461, 1467, 1464, 1462, 1463, 1465);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 28265);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 28175);\n";
cp.code() += "if (etiss_semihost_enabled()) { // conditional\n";
cp.code() += "etiss_coverage_count(1, 28176);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28260);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 pc_m4 = " + std::to_string((etiss_uint32)((ic.current_address_ - 4ULL))) + "ULL;\n";
cp.code() += "etiss_coverage_count(6, 28184, 28183, 28180, 28178, 28179, 28181);\n";
cp.code() += "etiss_uint32 pc_p4 = " + std::to_string((etiss_uint32)((ic.current_address_ + 4ULL))) + "ULL;\n";
cp.code() += "etiss_coverage_count(6, 28192, 28191, 28188, 28186, 28187, 28189);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, pc_m4, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 pre = (etiss_uint32)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(6, 28202, 28201, 28199, 28197, 28195, 28196);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, " + std::to_string(ic.current_address_) + "ULL, (etiss_uint8*)&mem_val_1, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 ebreak = (etiss_uint32)(mem_val_1);\n";
cp.code() += "etiss_coverage_count(6, 28212, 28211, 28209, 28207, 28205, 28206);\n";
cp.code() += "etiss_uint32 mem_val_2;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, pc_p4, (etiss_uint8*)&mem_val_2, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_uint32 post = (etiss_uint32)(mem_val_2);\n";
cp.code() += "etiss_coverage_count(6, 28222, 28221, 28219, 28217, 28215, 28216);\n";
cp.code() += "etiss_coverage_count(1, 28223);\n";
cp.code() += "if (pre == 32509971ULL && ebreak == 1048691ULL && post == 1081102355ULL) { // conditional\n";
cp.code() += "etiss_coverage_count(11, 28234, 28230, 28226, 28224, 28225, 28229, 28227, 28228, 28233, 28231, 28232);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28255);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 operation = *((RV32IMXCoreV*)cpu)->X[10ULL];\n";
cp.code() += "etiss_coverage_count(3, 28239, 28238, 28237);\n";
cp.code() += "etiss_uint32 parameter = *((RV32IMXCoreV*)cpu)->X[11ULL];\n";
cp.code() += "etiss_coverage_count(3, 28244, 28243, 28242);\n";
cp.code() += "*((RV32IMXCoreV*)cpu)->X[10ULL] = (etiss_int32)(etiss_semihost(cpu, system, plugin_pointers, 32ULL, operation, parameter));\n";
cp.code() += "etiss_coverage_count(7, 28254, 28247, 28246, 28253, 28251, 28249, 28250);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28259);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_raise(cpu, system, plugin_pointers, 0LL, 3ULL);\n";
cp.code() += "etiss_coverage_count(2, 28258, 28256);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
{ // block
cp.code() += "etiss_coverage_count(1, 28264);\n";
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMXCoreV_raise(cpu, system, plugin_pointers, 0LL, 3ULL);\n";
cp.code() += "etiss_coverage_count(2, 28263, 28261);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
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

		cp.code() = std::string("//EBREAK\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->return_pending || cpu->exception || cpu->nextPc != " + std::to_string(ic.current_address_ + 4) + "ULL) return cpu->exception;\n";
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
ss << "ebreak" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
// clang-format on
