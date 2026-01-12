/**
 * Generated on Mon, 12 Jan 2026 12:41:11 +0100.
 *
 * This file contains the architecture class for the XIsaacCore core architecture.
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
		 are provided in XIsaacCoreArchSpecificImp.h

	 8. XIsaacCoreGDBCore.h provides the GDBCore class to support gdb flavor debugging feature, modify iy if in need.

 *********************************************************************************************************************************/

#include "XIsaacCoreArch.h"
#include "XIsaacCoreFuncs.h"

#define XIsaacCore_DEBUG_CALL 0
using namespace etiss ;
using namespace etiss::instr ;

XIsaacCoreArch::XIsaacCoreArch(unsigned int coreno):CPUArch("XIsaacCore"), coreno_(coreno)
{
	headers_.insert("Arch/XIsaacCore/XIsaacCore.h");
}

const std::set<std::string> & XIsaacCoreArch::getListenerSupportedRegisters()
{
	return listenerSupportedRegisters_;
}

ETISS_CPU * XIsaacCoreArch::newCPU()
{
	ETISS_CPU * ret = (ETISS_CPU *) new XIsaacCore() ;
	resetCPU (ret, 0);
	return ret;
}

void XIsaacCoreArch::resetCPU(ETISS_CPU * cpu,etiss::uint64 * startpointer)
{
	memset (cpu, 0, sizeof(XIsaacCore));
	XIsaacCore * xisaaccorecpu = (XIsaacCore *) cpu;

	if (startpointer) cpu->instructionPointer = *startpointer & ~((etiss::uint64)0x1);
	else cpu->instructionPointer = 0x0;   //  reference to manual
	cpu->nextPc = cpu->instructionPointer;
	cpu->mode = 1;
	cpu->cpuTime_ps = 0;
	cpu->cpuCycleTime_ps = 31250;


	for (int i = 0; i < 32; ++i) {
		xisaaccorecpu->ins_X[i] = 0;
		xisaaccorecpu->X[i] = &xisaaccorecpu->ins_X[i];
	}
	for (int i = 0; i < 4096; ++i) {
		xisaaccorecpu->ins_CSR[i] = 0;
		xisaaccorecpu->CSR[i] = &xisaaccorecpu->ins_CSR[i];
	}

	xisaaccorecpu->ZERO = 0;
	xisaaccorecpu->RA = 0;
	xisaaccorecpu->SP = 0;
	xisaaccorecpu->GP = 0;
	xisaaccorecpu->TP = 0;
	xisaaccorecpu->T0 = 0;
	xisaaccorecpu->T1 = 0;
	xisaaccorecpu->T2 = 0;
	xisaaccorecpu->S0 = 0;
	xisaaccorecpu->S1 = 0;
	xisaaccorecpu->A0 = 0;
	xisaaccorecpu->A1 = 0;
	xisaaccorecpu->A2 = 0;
	xisaaccorecpu->A3 = 0;
	xisaaccorecpu->A4 = 0;
	xisaaccorecpu->A5 = 0;
	xisaaccorecpu->A6 = 0;
	xisaaccorecpu->A7 = 0;
	xisaaccorecpu->S2 = 0;
	xisaaccorecpu->S3 = 0;
	xisaaccorecpu->S4 = 0;
	xisaaccorecpu->S5 = 0;
	xisaaccorecpu->S6 = 0;
	xisaaccorecpu->S7 = 0;
	xisaaccorecpu->S8 = 0;
	xisaaccorecpu->S9 = 0;
	xisaaccorecpu->S10 = 0;
	xisaaccorecpu->S11 = 0;
	xisaaccorecpu->T3 = 0;
	xisaaccorecpu->T4 = 0;
	xisaaccorecpu->T5 = 0;
	xisaaccorecpu->T6 = 0;
	for (int i = 0; i < 8; ++i) {
		xisaaccorecpu->FENCE[i] = 0;
	}
	for (int i = 0; i < 8; ++i) {
		xisaaccorecpu->RES[i] = 0;
	}
	xisaaccorecpu->PRIV = 0;
	xisaaccorecpu->DPC = 0;
	xisaaccorecpu->FCSR = 0;
	xisaaccorecpu->MSTATUS = 0;
	xisaaccorecpu->MIE = 0;
	xisaaccorecpu->MIP = 0;
	for (int i = 0; i < 32; ++i) {
		xisaaccorecpu->F[i] = 0;
	}
	xisaaccorecpu->RES_ADDR = 0;

 	xisaaccorecpu->X[0] = &xisaaccorecpu->ZERO;
 	xisaaccorecpu->X[1] = &xisaaccorecpu->RA;
 	xisaaccorecpu->X[2] = &xisaaccorecpu->SP;
 	xisaaccorecpu->X[3] = &xisaaccorecpu->GP;
 	xisaaccorecpu->X[4] = &xisaaccorecpu->TP;
 	xisaaccorecpu->X[5] = &xisaaccorecpu->T0;
 	xisaaccorecpu->X[6] = &xisaaccorecpu->T1;
 	xisaaccorecpu->X[7] = &xisaaccorecpu->T2;
 	xisaaccorecpu->X[8] = &xisaaccorecpu->S0;
 	xisaaccorecpu->X[9] = &xisaaccorecpu->S1;
 	xisaaccorecpu->X[10] = &xisaaccorecpu->A0;
 	xisaaccorecpu->X[11] = &xisaaccorecpu->A1;
 	xisaaccorecpu->X[12] = &xisaaccorecpu->A2;
 	xisaaccorecpu->X[13] = &xisaaccorecpu->A3;
 	xisaaccorecpu->X[14] = &xisaaccorecpu->A4;
 	xisaaccorecpu->X[15] = &xisaaccorecpu->A5;
 	xisaaccorecpu->X[16] = &xisaaccorecpu->A6;
 	xisaaccorecpu->X[17] = &xisaaccorecpu->A7;
 	xisaaccorecpu->X[18] = &xisaaccorecpu->S2;
 	xisaaccorecpu->X[19] = &xisaaccorecpu->S3;
 	xisaaccorecpu->X[20] = &xisaaccorecpu->S4;
 	xisaaccorecpu->X[21] = &xisaaccorecpu->S5;
 	xisaaccorecpu->X[22] = &xisaaccorecpu->S6;
 	xisaaccorecpu->X[23] = &xisaaccorecpu->S7;
 	xisaaccorecpu->X[24] = &xisaaccorecpu->S8;
 	xisaaccorecpu->X[25] = &xisaaccorecpu->S9;
 	xisaaccorecpu->X[26] = &xisaaccorecpu->S10;
 	xisaaccorecpu->X[27] = &xisaaccorecpu->S11;
 	xisaaccorecpu->X[28] = &xisaaccorecpu->T3;
 	xisaaccorecpu->X[29] = &xisaaccorecpu->T4;
 	xisaaccorecpu->X[30] = &xisaaccorecpu->T5;
 	xisaaccorecpu->X[31] = &xisaaccorecpu->T6;
 	xisaaccorecpu->CSR[3] = &xisaaccorecpu->FCSR;
 	xisaaccorecpu->CSR[768] = &xisaaccorecpu->MSTATUS;
 	xisaaccorecpu->CSR[772] = &xisaaccorecpu->MIE;
 	xisaaccorecpu->CSR[836] = &xisaaccorecpu->MIP;

   	xisaaccorecpu->PRIV = 3ULL;
   	xisaaccorecpu->DPC = 0LL;
  	*xisaaccorecpu->CSR[0] = 11ULL;
 	*xisaaccorecpu->CSR[256] = 11ULL;
 	*xisaaccorecpu->CSR[768] = 11ULL;
 	*xisaaccorecpu->CSR[769] = 1075056941ULL;
 	*xisaaccorecpu->CSR[3088] = 3ULL;
 	*xisaaccorecpu->CSR[772] = 4294966203ULL;
 	*xisaaccorecpu->CSR[260] = 4294964019ULL;
 	*xisaaccorecpu->CSR[4] = 4294963473ULL;
   	xisaaccorecpu->RES_ADDR = -1LL;

}

void XIsaacCoreArch::deleteCPU(ETISS_CPU *cpu)
{
	delete (XIsaacCore *) cpu ;
}

/**
	@return 8 (jump instruction + instruction of delay slot)
*/
unsigned XIsaacCoreArch::getMaximumInstructionSizeInBytes()
{
	return 8;
}

/**
	@return 2
*/
unsigned XIsaacCoreArch::getInstructionSizeInBytes()
{
	return 2;
}

/**
	@brief required headers (XIsaacCore.h)
*/
const std::set<std::string> & XIsaacCoreArch::getHeaders() const
{
	return headers_ ;
}

void XIsaacCoreArch::initCodeBlock(etiss::CodeBlock & cb) const
{
	cb.fileglobalCode().insert("#include \"Arch/XIsaacCore/XIsaacCore.h\"\n");
	cb.fileglobalCode().insert("#include \"Arch/XIsaacCore/XIsaacCoreFuncs.h\"\n");
	cb.functionglobalCode().insert("cpu->exception = 0;\n");
	cb.functionglobalCode().insert("cpu->return_pending = 0;\n");
	cb.functionglobalCode().insert("etiss_uint32 mem_ret_code = 0;\n");
}

etiss::plugin::gdb::GDBCore & XIsaacCoreArch::getGDBCore()
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

etiss::instr::InstructionGroup ISA16_XIsaacCore("ISA16_XIsaacCore", 16);
etiss::instr::InstructionClass ISA16_XIsaacCoreClass(1, "ISA16_XIsaacCore", 16, ISA16_XIsaacCore);
etiss::instr::InstructionGroup ISA32_XIsaacCore("ISA32_XIsaacCore", 32);
etiss::instr::InstructionClass ISA32_XIsaacCoreClass(1, "ISA32_XIsaacCore", 32, ISA32_XIsaacCore);

etiss::instr::InstructionCollection XIsaacCoreISA("XIsaacCoreISA", ISA16_XIsaacCoreClass, ISA32_XIsaacCoreClass);