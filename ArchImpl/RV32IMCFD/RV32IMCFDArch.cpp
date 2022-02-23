/**
 * Generated on Wed, 23 Feb 2022 20:40:41 +0100.
 *
 * This file contains the architecture class for the RV32IMCFD core architecture.
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
		 are provided in RV32IMCFDArchSpecificImp.h

	 8. RV32IMCFDGDBCore.h provides the GDBCore class to support gdb flavor debugging feature, modify iy if in need.

 *********************************************************************************************************************************/

#include "RV32IMCFDArch.h"

#define ETISS_ARCH_STATIC_FN_ONLY
#include "RV32IMCFDFuncs.h"

#define RV32IMCFD_DEBUG_CALL 0
using namespace etiss ;
using namespace etiss::instr ;

RV32IMCFDArch::RV32IMCFDArch():CPUArch("RV32IMCFD")
{
	headers_.insert("Arch/RV32IMCFD/RV32IMCFD.h");
}

const std::set<std::string> & RV32IMCFDArch::getListenerSupportedRegisters()
{
	return listenerSupportedRegisters_;
}

ETISS_CPU * RV32IMCFDArch::newCPU()
{
	ETISS_CPU * ret = (ETISS_CPU *) new RV32IMCFD() ;
	resetCPU (ret, 0);
	return ret;
}

void RV32IMCFDArch::resetCPU(ETISS_CPU * cpu,etiss::uint64 * startpointer)
{
	memset (cpu, 0, sizeof(RV32IMCFD));
	RV32IMCFD * rv32imcfdcpu = (RV32IMCFD *) cpu;

	if (startpointer) cpu->instructionPointer = *startpointer & ~((etiss::uint64)0x1);
	else cpu->instructionPointer = 0x0;   //  reference to manual
	cpu->mode = 1;
	cpu->cpuTime_ps = 0;
	cpu->cpuCycleTime_ps = 31250;


	for (int i = 0; i < 32; ++i) {
		rv32imcfdcpu->ins_X[i] = 0;
		rv32imcfdcpu->X[i] = &rv32imcfdcpu->ins_X[i];
	}
	for (int i = 0; i < 4096; ++i) {
		rv32imcfdcpu->ins_CSR[i] = 0;
		rv32imcfdcpu->CSR[i] = &rv32imcfdcpu->ins_CSR[i];
	}

	rv32imcfdcpu->ZERO = 0;
	rv32imcfdcpu->RA = 0;
	rv32imcfdcpu->SP = 0;
	rv32imcfdcpu->GP = 0;
	rv32imcfdcpu->TP = 0;
	rv32imcfdcpu->T0 = 0;
	rv32imcfdcpu->T1 = 0;
	rv32imcfdcpu->T2 = 0;
	rv32imcfdcpu->S0 = 0;
	rv32imcfdcpu->S1 = 0;
	rv32imcfdcpu->A0 = 0;
	rv32imcfdcpu->A1 = 0;
	rv32imcfdcpu->A2 = 0;
	rv32imcfdcpu->A3 = 0;
	rv32imcfdcpu->A4 = 0;
	rv32imcfdcpu->A5 = 0;
	rv32imcfdcpu->A6 = 0;
	rv32imcfdcpu->A7 = 0;
	rv32imcfdcpu->S2 = 0;
	rv32imcfdcpu->S3 = 0;
	rv32imcfdcpu->S4 = 0;
	rv32imcfdcpu->S5 = 0;
	rv32imcfdcpu->S6 = 0;
	rv32imcfdcpu->S7 = 0;
	rv32imcfdcpu->S8 = 0;
	rv32imcfdcpu->S9 = 0;
	rv32imcfdcpu->S10 = 0;
	rv32imcfdcpu->S11 = 0;
	rv32imcfdcpu->T3 = 0;
	rv32imcfdcpu->T4 = 0;
	rv32imcfdcpu->T5 = 0;
	rv32imcfdcpu->T6 = 0;
	for (int i = 0; i < 8; ++i) {
		rv32imcfdcpu->FENCE[i] = 0;
	}
	for (int i = 0; i < 8; ++i) {
		rv32imcfdcpu->RES[i] = 0;
	}
	rv32imcfdcpu->PRIV = 0;
	rv32imcfdcpu->DPC = 0;
	rv32imcfdcpu->FCSR = 0;
	for (int i = 0; i < 32; ++i) {
		rv32imcfdcpu->F[i] = 0;
	}

 	rv32imcfdcpu->X[0] = &rv32imcfdcpu->ZERO;
 	rv32imcfdcpu->X[1] = &rv32imcfdcpu->RA;
 	rv32imcfdcpu->X[2] = &rv32imcfdcpu->SP;
 	rv32imcfdcpu->X[3] = &rv32imcfdcpu->GP;
 	rv32imcfdcpu->X[4] = &rv32imcfdcpu->TP;
 	rv32imcfdcpu->X[5] = &rv32imcfdcpu->T0;
 	rv32imcfdcpu->X[6] = &rv32imcfdcpu->T1;
 	rv32imcfdcpu->X[7] = &rv32imcfdcpu->T2;
 	rv32imcfdcpu->X[8] = &rv32imcfdcpu->S0;
 	rv32imcfdcpu->X[9] = &rv32imcfdcpu->S1;
 	rv32imcfdcpu->X[10] = &rv32imcfdcpu->A0;
 	rv32imcfdcpu->X[11] = &rv32imcfdcpu->A1;
 	rv32imcfdcpu->X[12] = &rv32imcfdcpu->A2;
 	rv32imcfdcpu->X[13] = &rv32imcfdcpu->A3;
 	rv32imcfdcpu->X[14] = &rv32imcfdcpu->A4;
 	rv32imcfdcpu->X[15] = &rv32imcfdcpu->A5;
 	rv32imcfdcpu->X[16] = &rv32imcfdcpu->A6;
 	rv32imcfdcpu->X[17] = &rv32imcfdcpu->A7;
 	rv32imcfdcpu->X[18] = &rv32imcfdcpu->S2;
 	rv32imcfdcpu->X[19] = &rv32imcfdcpu->S3;
 	rv32imcfdcpu->X[20] = &rv32imcfdcpu->S4;
 	rv32imcfdcpu->X[21] = &rv32imcfdcpu->S5;
 	rv32imcfdcpu->X[22] = &rv32imcfdcpu->S6;
 	rv32imcfdcpu->X[23] = &rv32imcfdcpu->S7;
 	rv32imcfdcpu->X[24] = &rv32imcfdcpu->S8;
 	rv32imcfdcpu->X[25] = &rv32imcfdcpu->S9;
 	rv32imcfdcpu->X[26] = &rv32imcfdcpu->S10;
 	rv32imcfdcpu->X[27] = &rv32imcfdcpu->S11;
 	rv32imcfdcpu->X[28] = &rv32imcfdcpu->T3;
 	rv32imcfdcpu->X[29] = &rv32imcfdcpu->T4;
 	rv32imcfdcpu->X[30] = &rv32imcfdcpu->T5;
 	rv32imcfdcpu->X[31] = &rv32imcfdcpu->T6;
 	rv32imcfdcpu->CSR[3] = &rv32imcfdcpu->FCSR;

 	*rv32imcfdcpu->CSR[0] = 11;
	*rv32imcfdcpu->CSR[256] = 11;
	*rv32imcfdcpu->CSR[768] = 11;
	*rv32imcfdcpu->CSR[769] = 1075056941;
	*rv32imcfdcpu->CSR[3088] = 3;
	*rv32imcfdcpu->CSR[772] = 4294966203;
	*rv32imcfdcpu->CSR[260] = 4294964019;
	*rv32imcfdcpu->CSR[4] = 4294963473;
}

void RV32IMCFDArch::deleteCPU(ETISS_CPU *cpu)
{
	delete (RV32IMCFD *) cpu ;
}

/**
	@return 8 (jump instruction + instruction of delay slot)
*/
unsigned RV32IMCFDArch::getMaximumInstructionSizeInBytes()
{
	return 8;
}

/**
	@return 2
*/
unsigned RV32IMCFDArch::getInstructionSizeInBytes()
{
	return 2;
}

/**
	@brief required headers (RV32IMCFD.h)
*/
const std::set<std::string> & RV32IMCFDArch::getHeaders() const
{
	return headers_ ;
}

void RV32IMCFDArch::initCodeBlock(etiss::CodeBlock & cb) const
{
	cb.fileglobalCode().insert("#include \"Arch/RV32IMCFD/RV32IMCFD.h\"\n");
	cb.fileglobalCode().insert("#include \"Arch/RV32IMCFD/RV32IMCFDFuncs.h\"\n");
	cb.functionglobalCode().insert("etiss_uint32 exception = 0;\n");
}

etiss::plugin::gdb::GDBCore & RV32IMCFDArch::getGDBCore()
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

etiss::instr::InstructionGroup ISA16_RV32IMCFD("ISA16_RV32IMCFD", 16);
etiss::instr::InstructionClass ISA16_RV32IMCFDClass(1, "ISA16_RV32IMCFD", 16, ISA16_RV32IMCFD);
etiss::instr::InstructionGroup ISA32_RV32IMCFD("ISA32_RV32IMCFD", 32);
etiss::instr::InstructionClass ISA32_RV32IMCFDClass(1, "ISA32_RV32IMCFD", 32, ISA32_RV32IMCFD);

etiss::instr::InstructionCollection RV32IMCFDISA("RV32IMCFDISA", ISA16_RV32IMCFDClass, ISA32_RV32IMCFDClass);