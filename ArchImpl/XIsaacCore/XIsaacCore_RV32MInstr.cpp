/**
 * Generated on Mon, 12 Jan 2026 12:41:11 +0100.
 *
 * This file contains the instruction behavior models of the RV32M
 * instruction set for the XIsaacCore core architecture.
 */

#include "XIsaacCoreArch.h"
#include "XIsaacCoreFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// MUL -------------------------------------------------------------------------
static InstructionDefinition mul_rd_rs1_rs2 (
	ISA32_XIsaacCore,
	"mul",
	(uint32_t) 0x2000033,
	(uint32_t) 0xfe00707f,
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

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//MUL\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 73);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 2873);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 2837);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 2843, 2840, 2838, 2841, 2842);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 2872);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int64 res = (etiss_int64)((etiss_int32)(*((XIsaacCore*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL])) * (etiss_int64)((etiss_int32)(*((XIsaacCore*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]));\n";
cp.code() += "etiss_coverage_count(12, 2862, 2861, 2852, 2850, 2849, 2848, 2846, 2860, 2858, 2857, 2856, 2854);\n";
cp.code() += "*((XIsaacCore*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint32)(res);\n";
cp.code() += "etiss_coverage_count(6, 2871, 2867, 2866, 2864, 2870, 2868);\n";
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
ss << "mul" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// MULH ------------------------------------------------------------------------
static InstructionDefinition mulh_rd_rs1_rs2 (
	ISA32_XIsaacCore,
	"mulh",
	(uint32_t) 0x2001033,
	(uint32_t) 0xfe00707f,
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

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//MULH\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 74);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 2913);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 2874);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 2880, 2877, 2875, 2878, 2879);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 2912);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int64 res = (etiss_int64)((etiss_int32)(*((XIsaacCore*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL])) * (etiss_int64)((etiss_int32)(*((XIsaacCore*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]));\n";
cp.code() += "etiss_coverage_count(12, 2899, 2898, 2889, 2887, 2886, 2885, 2883, 2897, 2895, 2894, 2893, 2891);\n";
cp.code() += "*((XIsaacCore*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint32)((res >> 32ULL));\n";
cp.code() += "etiss_coverage_count(8, 2911, 2904, 2903, 2901, 2910, 2907, 2905, 2908);\n";
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
ss << "mulh" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// MULHSU ----------------------------------------------------------------------
static InstructionDefinition mulhsu_rd_rs1_rs2 (
	ISA32_XIsaacCore,
	"mulhsu",
	(uint32_t) 0x2002033,
	(uint32_t) 0xfe00707f,
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

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//MULHSU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 75);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 2952);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 2914);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 2920, 2917, 2915, 2918, 2919);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 2951);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_int64 res = (etiss_int64)((etiss_int32)(*((XIsaacCore*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL])) * (etiss_uint64)(*((XIsaacCore*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(11, 2938, 2937, 2929, 2927, 2926, 2925, 2923, 2936, 2934, 2933, 2931);\n";
cp.code() += "*((XIsaacCore*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint32)((res >> 32ULL));\n";
cp.code() += "etiss_coverage_count(8, 2950, 2943, 2942, 2940, 2949, 2946, 2944, 2947);\n";
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
ss << "mulhsu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// MULHU -----------------------------------------------------------------------
static InstructionDefinition mulhu_rd_rs1_rs2 (
	ISA32_XIsaacCore,
	"mulhu",
	(uint32_t) 0x2003033,
	(uint32_t) 0xfe00707f,
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

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//MULHU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 76);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 2990);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 2953);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 2959, 2956, 2954, 2957, 2958);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 2989);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = (etiss_uint64)(*((XIsaacCore*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) * (etiss_uint64)(*((XIsaacCore*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(10, 2976, 2975, 2967, 2965, 2964, 2962, 2974, 2972, 2971, 2969);\n";
cp.code() += "*((XIsaacCore*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint32)((res >> 32ULL));\n";
cp.code() += "etiss_coverage_count(8, 2988, 2981, 2980, 2978, 2987, 2984, 2982, 2985);\n";
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
ss << "mulhu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// DIV -------------------------------------------------------------------------
static InstructionDefinition div_rd_rs1_rs2 (
	ISA32_XIsaacCore,
	"div",
	(uint32_t) 0x2004033,
	(uint32_t) 0xfe00707f,
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

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//DIV\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 77);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 3071);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 2991);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 2997, 2994, 2992, 2995, 2996);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 3070);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 2998);\n";
cp.code() += "if (*((XIsaacCore*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL] != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(5, 3005, 3003, 3002, 3000, 3004);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 3061);\n";
cp.code() += "{ // block\n";
etiss_uint32 MMIN = 2147483648ULL;
cp.code() += "etiss_coverage_count(1, 3013);\n";
cp.code() += "etiss_coverage_count(1, 3014);\n";
cp.code() += "if (*((XIsaacCore*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] == " + std::to_string(MMIN) + "ULL && (etiss_int32)(*((XIsaacCore*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) == -1LL) { // conditional\n";
cp.code() += "etiss_coverage_count(11, 3032, 3021, 3019, 3018, 3016, 3020, 3031, 3028, 3026, 3025, 3023);\n";
cp.code() += "*((XIsaacCore*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = " + std::to_string(MMIN) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 3039, 3037, 3036, 3034, 3038);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((XIsaacCore*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int32)(*((XIsaacCore*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) / (etiss_int32)(*((XIsaacCore*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(13, 3060, 3044, 3043, 3041, 3059, 3051, 3049, 3048, 3046, 3058, 3056, 3055, 3053);\n";
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((XIsaacCore*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = -1LL;\n";
cp.code() += "etiss_coverage_count(4, 3069, 3066, 3065, 3063);\n";
cp.code() += "} // conditional\n";
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
ss << "div" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// DIVU ------------------------------------------------------------------------
static InstructionDefinition divu_rd_rs1_rs2 (
	ISA32_XIsaacCore,
	"divu",
	(uint32_t) 0x2005033,
	(uint32_t) 0xfe00707f,
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

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//DIVU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 78);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 3113);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 3072);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 3078, 3075, 3073, 3076, 3077);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 3112);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 3079);\n";
cp.code() += "if (*((XIsaacCore*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL] != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(5, 3086, 3084, 3083, 3081, 3085);\n";
cp.code() += "*((XIsaacCore*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((XIsaacCore*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] / *((XIsaacCore*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(11, 3103, 3091, 3090, 3088, 3102, 3096, 3095, 3093, 3101, 3100, 3098);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((XIsaacCore*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = -1LL;\n";
cp.code() += "etiss_coverage_count(4, 3111, 3108, 3107, 3105);\n";
cp.code() += "} // conditional\n";
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
ss << "divu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// REM -------------------------------------------------------------------------
static InstructionDefinition rem_rd_rs1_rs2 (
	ISA32_XIsaacCore,
	"rem",
	(uint32_t) 0x2006033,
	(uint32_t) 0xfe00707f,
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

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//REM\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 79);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 3197);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 3114);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 3120, 3117, 3115, 3118, 3119);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 3196);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 3121);\n";
cp.code() += "if (*((XIsaacCore*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL] != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(5, 3128, 3126, 3125, 3123, 3127);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 3184);\n";
cp.code() += "{ // block\n";
etiss_uint32 MMIN = 2147483648ULL;
cp.code() += "etiss_coverage_count(1, 3136);\n";
cp.code() += "etiss_coverage_count(1, 3137);\n";
cp.code() += "if (*((XIsaacCore*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] == " + std::to_string(MMIN) + "ULL && (etiss_int32)(*((XIsaacCore*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) == -1LL) { // conditional\n";
cp.code() += "etiss_coverage_count(11, 3155, 3144, 3142, 3141, 3139, 3143, 3154, 3151, 3149, 3148, 3146);\n";
cp.code() += "*((XIsaacCore*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = 0LL;\n";
cp.code() += "etiss_coverage_count(5, 3162, 3160, 3159, 3157, 3161);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((XIsaacCore*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int32)(*((XIsaacCore*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) % (etiss_int32)(*((XIsaacCore*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(13, 3183, 3167, 3166, 3164, 3182, 3174, 3172, 3171, 3169, 3181, 3179, 3178, 3176);\n";
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((XIsaacCore*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((XIsaacCore*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(7, 3195, 3189, 3188, 3186, 3194, 3193, 3191);\n";
cp.code() += "} // conditional\n";
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
ss << "rem" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// REMU ------------------------------------------------------------------------
static InstructionDefinition remu_rd_rs1_rs2 (
	ISA32_XIsaacCore,
	"remu",
	(uint32_t) 0x2007033,
	(uint32_t) 0xfe00707f,
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

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//REMU\n");

// -----------------------------------------------------------------------------
cp.code() += "etiss_coverage_count(1, 80);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 1172);\n";
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(5, 1171, 1167, 1170, 1168, 1169);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "etiss_coverage_count(1, 3242);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 3198);\n";
if ((rd % 32ULL) != 0LL) { // conditional
cp.code() += "etiss_coverage_count(5, 3204, 3201, 3199, 3202, 3203);\n";
{ // block
cp.code() += "etiss_coverage_count(1, 3241);\n";
cp.code() += "{ // block\n";
cp.code() += "etiss_coverage_count(1, 3205);\n";
cp.code() += "if (*((XIsaacCore*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL] != 0LL) { // conditional\n";
cp.code() += "etiss_coverage_count(5, 3212, 3210, 3209, 3207, 3211);\n";
cp.code() += "*((XIsaacCore*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((XIsaacCore*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] % *((XIsaacCore*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(11, 3229, 3217, 3216, 3214, 3228, 3222, 3221, 3219, 3227, 3226, 3224);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((XIsaacCore*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((XIsaacCore*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(7, 3240, 3234, 3233, 3231, 3239, 3238, 3236);\n";
cp.code() += "} // conditional\n";
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
ss << "remu" << " # " << ba << (" [rd=" + std::to_string(rd) + " | rs1=" + std::to_string(rs1) + " | rs2=" + std::to_string(rs2) + "]");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
