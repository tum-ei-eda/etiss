/**
 * Generated on Mon, 04 Mar 2024 18:55:53 +0100.
 *
 * This file contains the instruction behavior models of the RV32M
 * instruction set for the RV32IMACFD core architecture.
 */

#include "RV32IMACFDArch.h"
#include "RV32IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// MUL -------------------------------------------------------------------------
static InstructionDefinition mul_rd_rs1_rs2 (
	ISA32_RV32IMACFD,
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
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 833, 829, 832);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 2259, 2258);\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_int64 res = (etiss_int64)((etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL])) * (etiss_int64)((etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]));\n";
cp.code() += "etiss_coverage_count(2, 2274, 2273);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint32)(res);\n";
cp.code() += "etiss_coverage_count(2, 2282, 2279);\n";
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
	ISA32_RV32IMACFD,
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
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 833, 829, 832);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 2290, 2289);\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_int64 res = (etiss_int64)((etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL])) * (etiss_int64)((etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]));\n";
cp.code() += "etiss_coverage_count(2, 2305, 2304);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint32)((res >> 32ULL));\n";
cp.code() += "etiss_coverage_count(2, 2316, 2310);\n";
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
	ISA32_RV32IMACFD,
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
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 833, 829, 832);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 2324, 2323);\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_int64 res = (etiss_int64)((etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL])) * (etiss_uint64)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(2, 2339, 2338);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint32)((res >> 32ULL));\n";
cp.code() += "etiss_coverage_count(2, 2350, 2344);\n";
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
	ISA32_RV32IMACFD,
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
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 833, 829, 832);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 2358, 2357);\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "etiss_uint64 res = (etiss_uint64)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) * (etiss_uint64)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(2, 2373, 2372);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_uint32)((res >> 32ULL));\n";
cp.code() += "etiss_coverage_count(2, 2384, 2378);\n";
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
	ISA32_RV32IMACFD,
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
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 833, 829, 832);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 2392, 2391);\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "if (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL] != 0ULL) { // conditional\n";
cp.code() += "etiss_coverage_count(2, 2398, 2397);\n";
{ // block
cp.code() += "{ // block\n";
etiss_uint32 MMIN = 2147483648ULL;
cp.code() += "etiss_coverage_count(1, 2404);\n";
cp.code() += "if (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] == " + std::to_string(MMIN) + "ULL && (etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) == -1LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 2420, 2411, 2419);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = " + std::to_string(MMIN) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 2427, 2425, 2426);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) / (etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(3, 2446, 2432, 2445);\n";
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = -1LL;\n";
cp.code() += "etiss_coverage_count(2, 2455, 2453);\n";
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
	ISA32_RV32IMACFD,
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
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 833, 829, 832);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 2464, 2463);\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "if (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL] != 0ULL) { // conditional\n";
cp.code() += "etiss_coverage_count(2, 2470, 2469);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] / *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(3, 2487, 2475, 2486);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = -1LL;\n";
cp.code() += "etiss_coverage_count(2, 2494, 2492);\n";
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
	ISA32_RV32IMACFD,
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
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 833, 829, 832);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 2503, 2502);\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "if (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL] != 0ULL) { // conditional\n";
cp.code() += "etiss_coverage_count(2, 2509, 2508);\n";
{ // block
cp.code() += "{ // block\n";
etiss_uint32 MMIN = 2147483648ULL;
cp.code() += "etiss_coverage_count(1, 2515);\n";
cp.code() += "if (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] == " + std::to_string(MMIN) + "ULL && (etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]) == -1LL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 2531, 2522, 2530);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = 0ULL;\n";
cp.code() += "etiss_coverage_count(2, 2537, 2536);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = (etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL]) % (etiss_int32)(*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL]);\n";
cp.code() += "etiss_coverage_count(3, 2556, 2542, 2555);\n";
cp.code() += "} // conditional\n";
cp.code() += "} // block\n";
} // block
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(3, 2569, 2563, 2568);\n";
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
	ISA32_RV32IMACFD,
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
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 833, 829, 832);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
if ((rd % 32ULL) != 0ULL) { // conditional
cp.code() += "etiss_coverage_count(2, 2578, 2577);\n";
{ // block
cp.code() += "{ // block\n";
cp.code() += "if (*((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL] != 0ULL) { // conditional\n";
cp.code() += "etiss_coverage_count(2, 2584, 2583);\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL] % *((RV32IMACFD*)cpu)->X[" + std::to_string(rs2 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(3, 2601, 2589, 2600);\n";
cp.code() += "} // conditional\n";
cp.code() += "else { // conditional\n";
cp.code() += "*((RV32IMACFD*)cpu)->X[" + std::to_string(rd % 32ULL) + "ULL] = *((RV32IMACFD*)cpu)->X[" + std::to_string(rs1 % 32ULL) + "ULL];\n";
cp.code() += "etiss_coverage_count(3, 2612, 2606, 2611);\n";
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
