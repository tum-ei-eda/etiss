/**
 * Generated on Tue, 01 Mar 2022 00:20:25 +0100.
 *
 * This file contains the architecture class for the RV32IMACFD core architecture.
 */

/*********************************************************************************************************************************

* Modification guidelines:

	 1. The initial value of SP register should be initialized by ctr0.S/board.S. If not, it could be initialized
		 through utility class etiss::VirtualStruct::Field.

	 2. Debug mode print out all assignment results. GDB in 8 is prefered.

	 3. Manually copy the content in bracket ["return ETISS_RETURNCODE_CPUFINISHED; \n"] to terminating instruction,
		 otherwise the emulation can not be ended.

	 4. If subset of encoding error occurs, it means the format of the encoding in the input model was not appropriate

	 5. If the PC register points to wrong address, please notice that some assembly may cause branch operation
		 implicitly such as "MOV Rd Rn" in ARMv6-M

	 6. If a variable is the result of dynamic slicing such as, var_1 = var_2<Hshift-1..Lshift-2>, the size would be
		 calculated during process (if possible), otherwise it is assumed to be the register size. Problems may occur when
		 var_1 encounters bit manipulation such as "~" due to bit expansion. To change the nml model with explicit slicing
		 e.g var_1 = val_2<3..0> or avoid bit manipulation for dynamic sliced variable. Otherwise, you have to manually
		 correct it.

	 7. Implementation dependent functionalities such as exception handling should be manully added. Corresponding interfaces
		 are provided in RV32IMACFDArchSpecificImp.h

	 8. RV32IMACFDGDBCore.h provides the GDBCore class to support gdb flavor debugging feature, modify iy if in need.

 *********************************************************************************************************************************/

#include "RV32IMACFDArch.h"

#define ETISS_ARCH_STATIC_FN_ONLY
#include "RV32IMACFDFuncs.h"

#define RV32IMACFD_DEBUG_CALL 0
using namespace etiss ;
using namespace etiss::instr ;

RV32IMACFDArch::RV32IMACFDArch():CPUArch("RV32IMACFD")
{
	headers_.insert("Arch/RV32IMACFD/RV32IMACFD.h");
}

const std::set<std::string> & RV32IMACFDArch::getListenerSupportedRegisters()
{
	return listenerSupportedRegisters_;
}

ETISS_CPU * RV32IMACFDArch::newCPU()
{
	ETISS_CPU * ret = (ETISS_CPU *) new RV32IMACFD() ;
	resetCPU (ret, 0);
	return ret;
}

void RV32IMACFDArch::resetCPU(ETISS_CPU * cpu,etiss::uint64 * startpointer)
{
	memset (cpu, 0, sizeof(RV32IMACFD));
	RV32IMACFD * rv32imacfdcpu = (RV32IMACFD *) cpu;

	if (startpointer) cpu->instructionPointer = *startpointer & ~((etiss::uint64)0x1);
	else cpu->instructionPointer = 0x0;   //  reference to manual
	cpu->mode = 1;
	cpu->cpuTime_ps = 0;
	cpu->cpuCycleTime_ps = 31250;


	for (int i = 0; i < 32; ++i) {
		rv32imacfdcpu->ins_X[i] = 0;
		rv32imacfdcpu->X[i] = &rv32imacfdcpu->ins_X[i];
	}
	for (int i = 0; i < 4096; ++i) {
		rv32imacfdcpu->ins_CSR[i] = 0;
		rv32imacfdcpu->CSR[i] = &rv32imacfdcpu->ins_CSR[i];
	}

	rv32imacfdcpu->ZERO = 0;
	rv32imacfdcpu->RA = 0;
	rv32imacfdcpu->SP = 0;
	rv32imacfdcpu->GP = 0;
	rv32imacfdcpu->TP = 0;
	rv32imacfdcpu->T0 = 0;
	rv32imacfdcpu->T1 = 0;
	rv32imacfdcpu->T2 = 0;
	rv32imacfdcpu->S0 = 0;
	rv32imacfdcpu->S1 = 0;
	rv32imacfdcpu->A0 = 0;
	rv32imacfdcpu->A1 = 0;
	rv32imacfdcpu->A2 = 0;
	rv32imacfdcpu->A3 = 0;
	rv32imacfdcpu->A4 = 0;
	rv32imacfdcpu->A5 = 0;
	rv32imacfdcpu->A6 = 0;
	rv32imacfdcpu->A7 = 0;
	rv32imacfdcpu->S2 = 0;
	rv32imacfdcpu->S3 = 0;
	rv32imacfdcpu->S4 = 0;
	rv32imacfdcpu->S5 = 0;
	rv32imacfdcpu->S6 = 0;
	rv32imacfdcpu->S7 = 0;
	rv32imacfdcpu->S8 = 0;
	rv32imacfdcpu->S9 = 0;
	rv32imacfdcpu->S10 = 0;
	rv32imacfdcpu->S11 = 0;
	rv32imacfdcpu->T3 = 0;
	rv32imacfdcpu->T4 = 0;
	rv32imacfdcpu->T5 = 0;
	rv32imacfdcpu->T6 = 0;
	for (int i = 0; i < 8; ++i) {
		rv32imacfdcpu->FENCE[i] = 0;
	}
	for (int i = 0; i < 8; ++i) {
		rv32imacfdcpu->RES[i] = 0;
	}
	rv32imacfdcpu->PRIV = 0;
	rv32imacfdcpu->DPC = 0;
	rv32imacfdcpu->FCSR = 0;
	for (int i = 0; i < 32; ++i) {
		rv32imacfdcpu->F[i] = 0;
	}
	rv32imacfdcpu->RES_ADDR = 0;

 	rv32imacfdcpu->X[0] = &rv32imacfdcpu->ZERO;
 	rv32imacfdcpu->X[1] = &rv32imacfdcpu->RA;
 	rv32imacfdcpu->X[2] = &rv32imacfdcpu->SP;
 	rv32imacfdcpu->X[3] = &rv32imacfdcpu->GP;
 	rv32imacfdcpu->X[4] = &rv32imacfdcpu->TP;
 	rv32imacfdcpu->X[5] = &rv32imacfdcpu->T0;
 	rv32imacfdcpu->X[6] = &rv32imacfdcpu->T1;
 	rv32imacfdcpu->X[7] = &rv32imacfdcpu->T2;
 	rv32imacfdcpu->X[8] = &rv32imacfdcpu->S0;
 	rv32imacfdcpu->X[9] = &rv32imacfdcpu->S1;
 	rv32imacfdcpu->X[10] = &rv32imacfdcpu->A0;
 	rv32imacfdcpu->X[11] = &rv32imacfdcpu->A1;
 	rv32imacfdcpu->X[12] = &rv32imacfdcpu->A2;
 	rv32imacfdcpu->X[13] = &rv32imacfdcpu->A3;
 	rv32imacfdcpu->X[14] = &rv32imacfdcpu->A4;
 	rv32imacfdcpu->X[15] = &rv32imacfdcpu->A5;
 	rv32imacfdcpu->X[16] = &rv32imacfdcpu->A6;
 	rv32imacfdcpu->X[17] = &rv32imacfdcpu->A7;
 	rv32imacfdcpu->X[18] = &rv32imacfdcpu->S2;
 	rv32imacfdcpu->X[19] = &rv32imacfdcpu->S3;
 	rv32imacfdcpu->X[20] = &rv32imacfdcpu->S4;
 	rv32imacfdcpu->X[21] = &rv32imacfdcpu->S5;
 	rv32imacfdcpu->X[22] = &rv32imacfdcpu->S6;
 	rv32imacfdcpu->X[23] = &rv32imacfdcpu->S7;
 	rv32imacfdcpu->X[24] = &rv32imacfdcpu->S8;
 	rv32imacfdcpu->X[25] = &rv32imacfdcpu->S9;
 	rv32imacfdcpu->X[26] = &rv32imacfdcpu->S10;
 	rv32imacfdcpu->X[27] = &rv32imacfdcpu->S11;
 	rv32imacfdcpu->X[28] = &rv32imacfdcpu->T3;
 	rv32imacfdcpu->X[29] = &rv32imacfdcpu->T4;
 	rv32imacfdcpu->X[30] = &rv32imacfdcpu->T5;
 	rv32imacfdcpu->X[31] = &rv32imacfdcpu->T6;
 	rv32imacfdcpu->CSR[3] = &rv32imacfdcpu->FCSR;

 	rv32imacfdcpu->PRIV = 3;
 	rv32imacfdcpu->DPC = 0;
 	*rv32imacfdcpu->CSR[0] = 11;
	*rv32imacfdcpu->CSR[256] = 11;
	*rv32imacfdcpu->CSR[768] = 11;
	*rv32imacfdcpu->CSR[769] = 1075056941;
	*rv32imacfdcpu->CSR[3088] = 3;
	*rv32imacfdcpu->CSR[772] = 4294966203;
	*rv32imacfdcpu->CSR[260] = 4294964019;
	*rv32imacfdcpu->CSR[4] = 4294963473;
 	rv32imacfdcpu->RES_ADDR = -1;
}

void RV32IMACFDArch::deleteCPU(ETISS_CPU *cpu)
{
	delete (RV32IMACFD *) cpu ;
}

/**
	@return 8 (jump instruction + instruction of delay slot)
*/
unsigned RV32IMACFDArch::getMaximumInstructionSizeInBytes()
{
	return 8;
}

/**
	@return 2
*/
unsigned RV32IMACFDArch::getInstructionSizeInBytes()
{
	return 2;
}

/**
	@brief required headers (RV32IMACFD.h)
*/
const std::set<std::string> & RV32IMACFDArch::getHeaders() const
{
	return headers_ ;
}

void RV32IMACFDArch::initCodeBlock(etiss::CodeBlock & cb) const
{
	cb.fileglobalCode().insert("#include \"Arch/RV32IMACFD/RV32IMACFD.h\"\n");
	cb.fileglobalCode().insert("#include \"Arch/RV32IMACFD/RV32IMACFDFuncs.h\"\n");
	cb.functionglobalCode().insert("etiss_uint32 exception = 0;\n");
}

etiss::plugin::gdb::GDBCore & RV32IMACFDArch::getGDBCore()
{
	return gdbcore_;
}

const char * const reg_name[] =
{
	"X0",
	"X1",
	"X2",
	"X3",
	"X4",
	"X5",
	"X6",
	"X7",
	"X8",
	"X9",
	"X10",
	"X11",
	"X12",
	"X13",
	"X14",
	"X15",
	"X16",
	"X17",
	"X18",
	"X19",
	"X20",
	"X21",
	"X22",
	"X23",
	"X24",
	"X25",
	"X26",
	"X27",
	"X28",
	"X29",
	"X30",
	"X31",
};

etiss::instr::InstructionGroup ISA16_RV32IMACFD("ISA16_RV32IMACFD", 16);
etiss::instr::InstructionClass ISA16_RV32IMACFDClass(1, "ISA16_RV32IMACFD", 16, ISA16_RV32IMACFD);
etiss::instr::InstructionGroup ISA32_RV32IMACFD("ISA32_RV32IMACFD", 32);
etiss::instr::InstructionClass ISA32_RV32IMACFDClass(1, "ISA32_RV32IMACFD", 32, ISA32_RV32IMACFD);

etiss::instr::InstructionCollection RV32IMACFDISA("RV32IMACFDISA", ISA16_RV32IMACFDClass, ISA32_RV32IMACFDClass);