/**
 * Generated on Mon, 04 Mar 2024 18:55:53 +0100.
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
	(uint32_t) 0x800202f,
	(uint32_t) 0xf800707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOSWAPW\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 833, 829, 832);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(2, 5348, 5347);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 5353, 5352);\n";
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
cp.code() += "etiss_coverage_count(2, 5364, 5358);\n";
} // conditional
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = (etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(2, 5374, 5368);\n";
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
cp.code() += "if (cpu->return_pending | cpu->exception) return cpu->exception;\n";
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
	(uint32_t) 0x00202f,
	(uint32_t) 0xf800707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOADDW\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 833, 829, 832);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(2, 5382, 5381);\n";
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
cp.code() += "etiss_coverage_count(2, 5386, 5385);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 5391, 5390);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res1;\n";
cp.code() += "etiss_coverage_count(3, 5398, 5396, 5397);\n";
} // conditional
cp.code() += "etiss_uint32 res2 = res1 + *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(2, 5407, 5406);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(3, 5412, 5410, 5411);\n";
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
cp.code() += "if (cpu->return_pending | cpu->exception) return cpu->exception;\n";
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
	(uint32_t) 0x2000202f,
	(uint32_t) 0xf800707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOXORW\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 833, 829, 832);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(2, 5420, 5419);\n";
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
cp.code() += "etiss_coverage_count(2, 5424, 5423);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 5429, 5428);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res1;\n";
cp.code() += "etiss_coverage_count(3, 5436, 5434, 5435);\n";
} // conditional
cp.code() += "etiss_uint32 res2 = res1 ^ *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(2, 5445, 5444);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(3, 5450, 5448, 5449);\n";
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
cp.code() += "if (cpu->return_pending | cpu->exception) return cpu->exception;\n";
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
	(uint32_t) 0x6000202f,
	(uint32_t) 0xf800707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOANDW\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 833, 829, 832);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(2, 5458, 5457);\n";
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
cp.code() += "etiss_coverage_count(2, 5462, 5461);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 5467, 5466);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res1;\n";
cp.code() += "etiss_coverage_count(3, 5474, 5472, 5473);\n";
} // conditional
cp.code() += "etiss_uint32 res2 = res1 & *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(2, 5483, 5482);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(3, 5488, 5486, 5487);\n";
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
cp.code() += "if (cpu->return_pending | cpu->exception) return cpu->exception;\n";
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
	(uint32_t) 0x4000202f,
	(uint32_t) 0xf800707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOORW\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 833, 829, 832);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(2, 5496, 5495);\n";
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
cp.code() += "etiss_coverage_count(2, 5500, 5499);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 5505, 5504);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res1;\n";
cp.code() += "etiss_coverage_count(3, 5512, 5510, 5511);\n";
} // conditional
cp.code() += "etiss_uint32 res2 = res1 | *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(2, 5521, 5520);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(3, 5526, 5524, 5525);\n";
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
cp.code() += "if (cpu->return_pending | cpu->exception) return cpu->exception;\n";
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
	(uint32_t) 0x8000202f,
	(uint32_t) 0xf800707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOMINW\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 833, 829, 832);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(2, 5534, 5533);\n";
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
cp.code() += "etiss_coverage_count(2, 5538, 5537);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 5543, 5542);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res1;\n";
cp.code() += "etiss_coverage_count(3, 5550, 5548, 5549);\n";
} // conditional
cp.code() += "etiss_uint32 res2 = (res1 > (etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])) ? (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) : (res1);\n";
cp.code() += "etiss_coverage_count(2, 5566, 5565);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(3, 5571, 5569, 5570);\n";
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
cp.code() += "if (cpu->return_pending | cpu->exception) return cpu->exception;\n";
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
	(uint32_t) 0xa000202f,
	(uint32_t) 0xf800707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOMAXW\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 833, 829, 832);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(2, 5579, 5578);\n";
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
cp.code() += "etiss_coverage_count(2, 5583, 5582);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 5588, 5587);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = res1;\n";
cp.code() += "etiss_coverage_count(3, 5595, 5593, 5594);\n";
} // conditional
cp.code() += "etiss_uint32 res2 = (res1 < (etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])) ? (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) : (res1);\n";
cp.code() += "etiss_coverage_count(2, 5611, 5610);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(3, 5616, 5614, 5615);\n";
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
cp.code() += "if (cpu->return_pending | cpu->exception) return cpu->exception;\n";
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
	(uint32_t) 0xc000202f,
	(uint32_t) 0xf800707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOMINUW\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 833, 829, 832);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(2, 5624, 5623);\n";
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
cp.code() += "etiss_coverage_count(2, 5628, 5627);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 5633, 5632);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int32)(res1);\n";
cp.code() += "etiss_coverage_count(2, 5640, 5638);\n";
} // conditional
cp.code() += "etiss_uint32 res2 = (res1 > (etiss_uint32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])) ? (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) : (res1);\n";
cp.code() += "etiss_coverage_count(2, 5656, 5655);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(3, 5661, 5659, 5660);\n";
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
cp.code() += "if (cpu->return_pending | cpu->exception) return cpu->exception;\n";
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
	(uint32_t) 0xe000202f,
	(uint32_t) 0xf800707f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

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

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//AMOMAXUW\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 833, 829, 832);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(2, 5669, 5668);\n";
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
cp.code() += "etiss_coverage_count(2, 5673, 5672);\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 5678, 5677);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int32)(res1);\n";
cp.code() += "etiss_coverage_count(2, 5685, 5683);\n";
} // conditional
cp.code() += "etiss_uint32 res2 = (res1 < (etiss_uint32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL])) ? (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) : (res1);\n";
cp.code() += "etiss_coverage_count(2, 5701, 5700);\n";
cp.code() += "etiss_uint32 mem_val_1;\n";
cp.code() += "mem_val_1 = res2;\n";
cp.code() += "etiss_coverage_count(3, 5706, 5704, 5705);\n";
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
cp.code() += "if (cpu->return_pending | cpu->exception) return cpu->exception;\n";
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
