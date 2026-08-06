// clang-format off
/**
 * Generated on Thu, 06 Aug 2026 12:56:16 +0200.
 *
 * This file contains the instruction behavior models of the RV32IC
 * instruction set for the RV32IMACFDV_zvl128b core architecture.
 */

#include "RV32IMACFDV_zvl128bArch.h"
#include "RV32IMACFDV_zvl128bFuncs.h"

using namespace etiss;
using namespace etiss::instr;

// CADDI4SPN -------------------------------------------------------------------
static InstructionDefinition caddi4spn_rd_imm (
	ISA16_RV32IMACFDV_zvl128b,
	"caddi4spn",
	(uint64_t) 0x00,
	(uint64_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(4, 2);
rd += R_rd_0.read(ba) << 0;
etiss_uint16 imm = 0;
static BitArrayRange R_imm_3(5, 5);
imm += R_imm_3.read(ba) << 3;
static BitArrayRange R_imm_2(6, 6);
imm += R_imm_2.read(ba) << 2;
static BitArrayRange R_imm_6(10, 7);
imm += R_imm_6.read(ba) << 6;
static BitArrayRange R_imm_4(12, 11);
imm += R_imm_4.read(ba) << 4;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CADDI4SPN\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 42);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 2563);\n";
if (imm) { // conditional
cp.code() += "etiss_coverage_count(1, 2564);\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rd + 8ULL) + "ULL] = *((RV32IMACFDV_zvl128b*)cpu)->X[2ULL] + " + std::to_string(imm) + "ULL;\n";
cp.code() += "etiss_coverage_count(9, 2575, 2569, 2568, 2566, 2567, 2574, 2572, 2571, 2573);\n";
} // conditional
else { // conditional
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(2, 2578, 2576);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
} // conditional
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CADDI4SPN\n");

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
static BitArrayRange R_rd_0(4, 2);
rd += R_rd_0.read(ba) << 0;
etiss_uint16 imm = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"clw",
	(uint64_t) 0x4000,
	(uint64_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(4, 2);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 uimm = 0;
static BitArrayRange R_uimm_6(5, 5);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_2(6, 6);
uimm += R_uimm_2.read(ba) << 2;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_uimm_3(12, 10);
uimm += R_uimm_3.read(ba) << 3;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CLW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 43);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 2602);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 load_address = *((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rs1 + 8ULL) + "ULL] + " + std::to_string(uimm) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 2587, 2586, 2584, 2583, 2581, 2582, 2585);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rd + 8ULL) + "ULL] = (etiss_int32)(mem_val_0);\n";
cp.code() += "etiss_coverage_count(10, 2601, 2592, 2591, 2589, 2590, 2600, 2598, 2596, 2594, 2595);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CLW\n");

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
static BitArrayRange R_rd_0(4, 2);
rd += R_rd_0.read(ba) << 0;
etiss_uint8 uimm = 0;
static BitArrayRange R_uimm_6(5, 5);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_2(6, 6);
uimm += R_uimm_2.read(ba) << 2;
etiss_uint8 rs1 = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"csw",
	(uint64_t) 0xc000,
	(uint64_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 uimm = 0;
static BitArrayRange R_uimm_6(5, 5);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_2(6, 6);
uimm += R_uimm_2.read(ba) << 2;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_uimm_3(12, 10);
uimm += R_uimm_3.read(ba) << 3;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CSW\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 44);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 2626);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 load_address = *((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rs1 + 8ULL) + "ULL] + " + std::to_string(uimm) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 2611, 2610, 2608, 2607, 2605, 2606, 2609);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "mem_val_0 = (etiss_int32)(*((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rs2 + 8ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(10, 2625, 2617, 2615, 2613, 2614, 2624, 2622, 2621, 2619, 2620);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, load_address, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
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

		cp.code() = std::string("//CSW\n");

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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 uimm = 0;
static BitArrayRange R_uimm_6(5, 5);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_2(6, 6);
uimm += R_uimm_2.read(ba) << 2;
etiss_uint8 rs1 = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"caddi",
	(uint64_t) 0x01,
	(uint64_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 imm = 0;
static BitArrayRange R_imm_0(6, 2);
imm += R_imm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(11, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_imm_5(12, 12);
imm += R_imm_5.read(ba) << 5;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CADDI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 45);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 2627);\n";
if ((rs1 % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 2633, 2630, 2628, 2631, 2632);\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] = *((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] + " + std::to_string(((etiss_int8)(((etiss_int8)imm) << (2)) >> (2))) + "LL;\n";
cp.code() += "etiss_coverage_count(10, 2648, 2638, 2637, 2635, 2647, 2643, 2642, 2640, 2646, 2644);\n";
} // conditional
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 imm = 0;
static BitArrayRange R_imm_0(6, 2);
imm += R_imm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"cnop",
	(uint64_t) 0x01,
	(uint64_t) 0xef83,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 nzimm = 0;
static BitArrayRange R_nzimm_0(6, 2);
nzimm += R_nzimm_0.read(ba) << 0;
static BitArrayRange R_nzimm_5(12, 12);
nzimm += R_nzimm_5.read(ba) << 5;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CNOP\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 46);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 2649);\n";
cp.code() += "{ // block\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 nzimm = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"cjal",
	(uint64_t) 0x2001,
	(uint64_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint16 imm = 0;
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

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CJAL\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 47);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 2664);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->X[1ULL] = " + std::to_string(ic.current_address_ + 2ULL) + "ULL;\n";
cp.code() += "etiss_coverage_count(6, 2656, 2652, 2651, 2655, 2653, 2654);\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + ((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 2663, 2657, 2662, 2658, 2661, 2659);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CJAL\n");

// -----------------------------------------------------------------------------
cp.code() += "return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint16 imm = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"cli",
	(uint64_t) 0x4001,
	(uint64_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 imm = 0;
static BitArrayRange R_imm_0(6, 2);
imm += R_imm_0.read(ba) << 0;
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
static BitArrayRange R_imm_5(12, 12);
imm += R_imm_5.read(ba) << 5;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CLI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 48);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 2681);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 2665);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 2671, 2668, 2666, 2669, 2670);\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = " + std::to_string(((etiss_int8)(((etiss_int8)imm) << (2)) >> (2))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 2680, 2676, 2675, 2673, 2679, 2677);\n";
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 imm = 0;
static BitArrayRange R_imm_0(6, 2);
imm += R_imm_0.read(ba) << 0;
etiss_uint8 rd = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"clui",
	(uint64_t) 0x6001,
	(uint64_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint32 imm = 0;
static BitArrayRange R_imm_12(6, 2);
imm += R_imm_12.read(ba) << 12;
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
static BitArrayRange R_imm_17(12, 12);
imm += R_imm_17.read(ba) << 17;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CLUI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 49);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 2705);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 2682);\n";
if (imm == 0LL) { // conditional
cp.code() += "etiss_coverage_count(3, 2685, 2683, 2684);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(2, 2688, 2686);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
} // conditional
cp.code() += "etiss_coverage_count(1, 2689);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 2695, 2692, 2690, 2693, 2694);\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = " + std::to_string(((etiss_int32)(((etiss_int32)imm) << (14)) >> (14))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 2704, 2700, 2699, 2697, 2703, 2701);\n";
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

		cp.code() = std::string("//CLUI\n");

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
etiss_uint32 imm = 0;
static BitArrayRange R_imm_12(6, 2);
imm += R_imm_12.read(ba) << 12;
etiss_uint8 rd = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"caddi16sp",
	(uint64_t) 0x6101,
	(uint64_t) 0xef83,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint16 nzimm = 0;
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

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CADDI16SP\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 50);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 2706);\n";
if (nzimm) { // conditional
cp.code() += "etiss_coverage_count(1, 2707);\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->X[2ULL] = *((RV32IMACFDV_zvl128b*)cpu)->X[2ULL] + " + std::to_string(((etiss_int16)(((etiss_int16)nzimm) << (6)) >> (6))) + "LL;\n";
cp.code() += "etiss_coverage_count(8, 2718, 2710, 2709, 2717, 2713, 2712, 2716, 2714);\n";
} // conditional
else { // conditional
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(2, 2721, 2719);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
} // conditional
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CADDI16SP\n");

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
etiss_uint16 nzimm = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"__reserved_clui",
	(uint64_t) 0x6001,
	(uint64_t) 0xf07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//__reserved_clui\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 51);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(2, 2724, 2722);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//__reserved_clui\n");

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
	ISA16_RV32IMACFDV_zvl128b,
	"csrli",
	(uint64_t) 0x8001,
	(uint64_t) 0xfc03,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(6, 2);
shamt += R_shamt_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CSRLI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 52);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 2741);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rs1 + 8ULL) + "ULL] = *((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rs1 + 8ULL) + "ULL] >> " + std::to_string(shamt) + "ULL;\n";
cp.code() += "etiss_coverage_count(11, 2740, 2732, 2731, 2729, 2730, 2739, 2737, 2736, 2734, 2735, 2738);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(6, 2);
shamt += R_shamt_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"csrai",
	(uint64_t) 0x8401,
	(uint64_t) 0xfc03,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(6, 2);
shamt += R_shamt_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CSRAI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 53);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 2784);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 2745);\n";
if (shamt) { // conditional
cp.code() += "etiss_coverage_count(1, 2746);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 2766);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rs1 + 8ULL) + "ULL] = ((etiss_int32)(*((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rs1 + 8ULL) + "ULL])) >> " + std::to_string(shamt) + "ULL;\n";
cp.code() += "etiss_coverage_count(13, 2765, 2754, 2753, 2751, 2752, 2764, 2761, 2759, 2758, 2756, 2757, 2762, 2763);\n";
cp.code() += "} // block\n";
} // block
} // conditional
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 shamt = 0;
static BitArrayRange R_shamt_0(6, 2);
shamt += R_shamt_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"candi",
	(uint64_t) 0x8801,
	(uint64_t) 0xec03,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 imm = 0;
static BitArrayRange R_imm_0(6, 2);
imm += R_imm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_imm_5(12, 12);
imm += R_imm_5.read(ba) << 5;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CANDI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 54);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 2800);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rs1 + 8ULL) + "ULL] = *((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rs1 + 8ULL) + "ULL] & " + std::to_string(((etiss_int8)(((etiss_int8)imm) << (2)) >> (2))) + "LL;\n";
cp.code() += "etiss_coverage_count(12, 2799, 2789, 2788, 2786, 2787, 2798, 2794, 2793, 2791, 2792, 2797, 2795);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 imm = 0;
static BitArrayRange R_imm_0(6, 2);
imm += R_imm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"csub",
	(uint64_t) 0x8c01,
	(uint64_t) 0xfc63,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(9, 7);
rd += R_rd_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CSUB\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 55);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 2818);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rd + 8ULL) + "ULL] = *((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rd + 8ULL) + "ULL] - *((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rs2 + 8ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(14, 2817, 2805, 2804, 2802, 2803, 2816, 2810, 2809, 2807, 2808, 2815, 2814, 2812, 2813);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rd = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"cxor",
	(uint64_t) 0x8c21,
	(uint64_t) 0xfc63,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(9, 7);
rd += R_rd_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CXOR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 56);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 2836);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rd + 8ULL) + "ULL] = *((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rd + 8ULL) + "ULL] ^ *((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rs2 + 8ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(14, 2835, 2823, 2822, 2820, 2821, 2834, 2828, 2827, 2825, 2826, 2833, 2832, 2830, 2831);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rd = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"cor",
	(uint64_t) 0x8c41,
	(uint64_t) 0xfc63,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(9, 7);
rd += R_rd_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//COR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 57);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 2854);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rd + 8ULL) + "ULL] = *((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rd + 8ULL) + "ULL] | *((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rs2 + 8ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(14, 2853, 2841, 2840, 2838, 2839, 2852, 2846, 2845, 2843, 2844, 2851, 2850, 2848, 2849);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rd = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"cand",
	(uint64_t) 0x8c61,
	(uint64_t) 0xfc63,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(9, 7);
rd += R_rd_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CAND\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 58);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 2872);\n";
cp.code() += "{ // block\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rd + 8ULL) + "ULL] = *((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rd + 8ULL) + "ULL] & *((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rs2 + 8ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(14, 2871, 2859, 2858, 2856, 2857, 2870, 2864, 2863, 2861, 2862, 2869, 2868, 2866, 2867);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(4, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rd = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"cj",
	(uint64_t) 0xa001,
	(uint64_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint16 imm = 0;
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

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CJ\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 59);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + ((etiss_int16)(((etiss_int16)imm) << (4)) >> (4))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 2879, 2873, 2878, 2874, 2877, 2875);\n";
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CJ\n");

// -----------------------------------------------------------------------------
cp.code() += "return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint16 imm = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"cbeqz",
	(uint64_t) 0xc001,
	(uint64_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint16 imm = 0;
static BitArrayRange R_imm_5(2, 2);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_1(4, 3);
imm += R_imm_1.read(ba) << 1;
static BitArrayRange R_imm_6(6, 5);
imm += R_imm_6.read(ba) << 6;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_imm_3(11, 10);
imm += R_imm_3.read(ba) << 3;
static BitArrayRange R_imm_8(12, 12);
imm += R_imm_8.read(ba) << 8;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CBEQZ\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 60);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 2880);\n";
cp.code() += "if (*((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rs1 + 8ULL) + "ULL] == 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(6, 2887, 2885, 2884, 2882, 2883, 2886);\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + ((etiss_int16)(((etiss_int16)imm) << (7)) >> (7))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 2894, 2888, 2893, 2889, 2892, 2890);\n";
cp.code() += "} // conditional\n";
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CBEQZ\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->nextPc != " + std::to_string(ic.current_address_ + 2) + "ULL) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint16 imm = 0;
static BitArrayRange R_imm_5(2, 2);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_1(4, 3);
imm += R_imm_1.read(ba) << 1;
static BitArrayRange R_imm_6(6, 5);
imm += R_imm_6.read(ba) << 6;
etiss_uint8 rs1 = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"cbnez",
	(uint64_t) 0xe001,
	(uint64_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint16 imm = 0;
static BitArrayRange R_imm_5(2, 2);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_1(4, 3);
imm += R_imm_1.read(ba) << 1;
static BitArrayRange R_imm_6(6, 5);
imm += R_imm_6.read(ba) << 6;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(9, 7);
rs1 += R_rs1_0.read(ba) << 0;
static BitArrayRange R_imm_3(11, 10);
imm += R_imm_3.read(ba) << 3;
static BitArrayRange R_imm_8(12, 12);
imm += R_imm_8.read(ba) << 8;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CBNEZ\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 61);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 2895);\n";
cp.code() += "if (*((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rs1 + 8ULL) + "ULL] != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(6, 2902, 2900, 2899, 2897, 2898, 2901);\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + ((etiss_int16)(((etiss_int16)imm) << (7)) >> (7))) + "LL;\n";
cp.code() += "etiss_coverage_count(6, 2909, 2903, 2908, 2904, 2907, 2905);\n";
cp.code() += "} // conditional\n";
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CBNEZ\n");

// -----------------------------------------------------------------------------
cp.code() += "if (cpu->nextPc != " + std::to_string(ic.current_address_ + 2) + "ULL) return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint16 imm = 0;
static BitArrayRange R_imm_5(2, 2);
imm += R_imm_5.read(ba) << 5;
static BitArrayRange R_imm_1(4, 3);
imm += R_imm_1.read(ba) << 1;
static BitArrayRange R_imm_6(6, 5);
imm += R_imm_6.read(ba) << 6;
etiss_uint8 rs1 = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"cslli",
	(uint64_t) 0x02,
	(uint64_t) 0xf003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 nzuimm = 0;
static BitArrayRange R_nzuimm_0(6, 2);
nzuimm += R_nzuimm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(11, 7);
rs1 += R_rs1_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CSLLI\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 62);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 2913);\n";
if (nzuimm) { // conditional
cp.code() += "etiss_coverage_count(1, 2914);\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] = *((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] << " + std::to_string(nzuimm) + "ULL;\n";
cp.code() += "etiss_coverage_count(9, 2927, 2919, 2918, 2916, 2926, 2924, 2923, 2921, 2925);\n";
} // conditional
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 nzuimm = 0;
static BitArrayRange R_nzuimm_0(6, 2);
nzuimm += R_nzuimm_0.read(ba) << 0;
etiss_uint8 rs1 = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"clwsp",
	(uint64_t) 0x4002,
	(uint64_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 uimm = 0;
static BitArrayRange R_uimm_6(3, 2);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_2(6, 4);
uimm += R_uimm_2.read(ba) << 2;
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;
static BitArrayRange R_uimm_5(12, 12);
uimm += R_uimm_5.read(ba) << 5;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CLWSP\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 63);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 2963);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 2928);\n";
if (rd % 32ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 2931, 2929);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 2959);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = (etiss_uint32)((*((RV32IMACFDV_zvl128b*)cpu)->X[2ULL] + " + std::to_string(uimm) + "ULL));\n";
cp.code() += "etiss_coverage_count(7, 2941, 2940, 2937, 2935, 2934, 2936, 2938);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "cpu->exception |= (*(system->dread))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "etiss_int32 res = mem_val_0;\n";
cp.code() += "etiss_coverage_count(5, 2949, 2948, 2946, 2944, 2945);\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int32)(res);\n";
cp.code() += "etiss_coverage_count(6, 2958, 2954, 2953, 2951, 2957, 2955);\n";
cp.code() += "} // block\n";
} // block
} // conditional
else { // conditional
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 2962, 2960, 2961);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
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

		cp.code() = std::string("//CLWSP\n");

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
etiss_uint8 uimm = 0;
static BitArrayRange R_uimm_6(3, 2);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_2(6, 4);
uimm += R_uimm_2.read(ba) << 2;
etiss_uint8 rd = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"cmv",
	(uint64_t) 0x8002,
	(uint64_t) 0xf003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(6, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CMV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 64);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 2964);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 2970, 2967, 2965, 2968, 2969);\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(7, 2981, 2975, 2974, 2972, 2980, 2979, 2977);\n";
} // conditional
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(6, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rd = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"cjr",
	(uint64_t) 0x8002,
	(uint64_t) 0xf07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(11, 7);
rs1 += R_rs1_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CJR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 65);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 2982);\n";
if (rs1) { // conditional
cp.code() += "etiss_coverage_count(1, 2983);\n";
cp.code() += "cpu->nextPc = *((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] & -2LL;\n";
cp.code() += "etiss_coverage_count(6, 2993, 2984, 2992, 2989, 2988, 2986);\n";
} // conditional
else { // conditional
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 2996, 2994, 2995);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
} // conditional
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CJR\n");

// -----------------------------------------------------------------------------
cp.code() += "return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rs1 = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"__reserved_cmv",
	(uint64_t) 0x8002,
	(uint64_t) 0xffff,
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

		cp.code() = std::string("//__reserved_cmv\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 66);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(3, 2999, 2997, 2998);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//__reserved_cmv\n");

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
	ISA16_RV32IMACFDV_zvl128b,
	"cadd",
	(uint64_t) 0x9002,
	(uint64_t) 0xf003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(6, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rd = 0;
static BitArrayRange R_rd_0(11, 7);
rd += R_rd_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CADD\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 67);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "etiss_coverage_count(1, 3000);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 3006, 3003, 3001, 3004, 3005);\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] + *((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(11, 3023, 3011, 3010, 3008, 3022, 3016, 3015, 3013, 3021, 3020, 3018);\n";
} // conditional
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(6, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 rd = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"cjalr",
	(uint64_t) 0x9002,
	(uint64_t) 0xf07f,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rs1 = 0;
static BitArrayRange R_rs1_0(11, 7);
rs1 += R_rs1_0.read(ba) << 0;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CJALR\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 68);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 3044);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 new_pc = *((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(4, 3030, 3029, 3028, 3026);\n";
cp.code() += "*((RV32IMACFDV_zvl128b*)cpu)->X[1ULL] = " + std::to_string(ic.current_address_ + 2ULL) + "ULL;\n";
cp.code() += "etiss_coverage_count(6, 3037, 3033, 3032, 3036, 3034, 3035);\n";
cp.code() += "cpu->nextPc = new_pc & -2LL;\n";
cp.code() += "etiss_coverage_count(4, 3043, 3038, 3042, 3039);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CJALR\n");

// -----------------------------------------------------------------------------
cp.code() += "return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------
etiss_uint8 rs1 = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"cebreak",
	(uint64_t) 0x9002,
	(uint64_t) 0xffff,
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

		cp.code() = std::string("//CEBREAK\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 69);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 3ULL);\n";
cp.code() += "etiss_coverage_count(2, 3047, 3045);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//CEBREAK\n");

// -----------------------------------------------------------------------------
cp.code() += "return cpu->exception;\n";
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
ss << "cebreak" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// CSWSP -----------------------------------------------------------------------
static InstructionDefinition cswsp_rs2_uimm (
	ISA16_RV32IMACFDV_zvl128b,
	"cswsp",
	(uint64_t) 0xc002,
	(uint64_t) 0xe003,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// NOLINTBEGIN(clang-diagnostic-unused-but-set-variable)
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(6, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 uimm = 0;
static BitArrayRange R_uimm_6(8, 7);
uimm += R_uimm_6.read(ba) << 6;
static BitArrayRange R_uimm_2(12, 9);
uimm += R_uimm_2.read(ba) << 2;

// NOLINTEND(clang-diagnostic-unused-but-set-variable)
// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//CSWSP\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 70);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 3069);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint32 offs = *((RV32IMACFDV_zvl128b*)cpu)->X[2ULL] + " + std::to_string(uimm) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 3054, 3053, 3051, 3050, 3052);\n";
cp.code() += "etiss_uint32 mem_val_0;\n";
cp.code() += "mem_val_0 = (etiss_uint32)(*((RV32IMACFDV_zvl128b*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(9, 3068, 3060, 3058, 3056, 3057, 3067, 3065, 3064, 3062);\n";
cp.code() += "cpu->exception |= (*(system->dwrite))(system->handle, cpu, offs, (etiss_uint8*)&mem_val_0, 4);\n";
cp.code() += "if (cpu->exception) { // conditional\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_translate_exc_code(cpu, system, plugin_pointers, cpu->exception);\n";
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

		cp.code() = std::string("//CSWSP\n");

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
etiss_uint8 rs2 = 0;
static BitArrayRange R_rs2_0(6, 2);
rs2 += R_rs2_0.read(ba) << 0;
etiss_uint8 uimm = 0;
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
	ISA16_RV32IMACFDV_zvl128b,
	"dii",
	(uint64_t) 0x00,
	(uint64_t) 0xffff,
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

		cp.code() = std::string("//DII\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 71);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1512);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string((etiss_uint32)((ic.current_address_ + 2))) + "ULL;\n";
cp.code() += "etiss_coverage_count(7, 1511, 1504, 1510, 1507, 1505, 1506, 1508);\n";
cp.code() += "} // block\n";
} // block
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFDV_zvl128b_raise(cpu, system, plugin_pointers, 0LL, 2ULL);\n";
cp.code() += "etiss_coverage_count(2, 3072, 3070);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//DII\n");

// -----------------------------------------------------------------------------
cp.code() += "return cpu->exception;\n";
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
ss << "dii" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
// clang-format on
