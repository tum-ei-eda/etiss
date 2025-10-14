/**
 * Generated on Tue, 16 Sep 2025 12:56:33 +0200.
 *
 * This file contains the architecture class for the RV64IMACFD core architecture.
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
		 are provided in RV64IMACFDArchSpecificImp.h

	 8. RV64IMACFDGDBCore.h provides the GDBCore class to support gdb flavor debugging feature, modify iy if in need.

 *********************************************************************************************************************************/

#include "RV64IMACFDArch.h"
#include "RV64IMACFDFuncs.h"

#define RV64IMACFD_DEBUG_CALL 0
#define memcpy_to_user(addr, val, len) (*(system->dwrite))(system->handle, cpu, addr, val, len);
using namespace etiss ;
using namespace etiss::instr ;

RV64IMACFDArch::RV64IMACFDArch(unsigned int coreno):CPUArch("RV64IMACFD"), coreno_(coreno)
{
	headers_.insert("Arch/RV64IMACFD/RV64IMACFD.h");
}

const std::set<std::string> & RV64IMACFDArch::getListenerSupportedRegisters()
{
	return listenerSupportedRegisters_;
}

ETISS_CPU * RV64IMACFDArch::newCPU()
{
	ETISS_CPU * ret = (ETISS_CPU *) new RV64IMACFD() ;
	resetCPU (ret, 0);
	return ret;
}
void RV64IMACFDArch::setupCmdline(ETISS_CPU * cpu, ETISS_System *system, int argc, char *argv[])
{
	RV64IMACFD * rv64imacfdcpu = (RV64IMACFD *) cpu;
  etiss_uint32 stack_top = rv64imacfdcpu->SP;
  std::vector<etiss_uint64> user_argv;
  user_argv.reserve(argc);
  for (int i = 0; i < argc; i++) {
    size_t len = strlen((char*)(uintptr_t)argv[i])+1;
    stack_top -= len;
    memcpy_to_user(stack_top, (etiss_uint8*)argv[i], len);
    user_argv[i] = stack_top;
  }
}

void RV64IMACFDArch::resetCPU(ETISS_CPU * cpu,etiss::uint64 * startpointer)
{
	memset (cpu, 0, sizeof(RV64IMACFD));
	RV64IMACFD * rv64imacfdcpu = (RV64IMACFD *) cpu;

	if (startpointer) cpu->instructionPointer = *startpointer & ~((etiss::uint64)0x1);
	else cpu->instructionPointer = 0x0;   //  reference to manual
	cpu->nextPc = cpu->instructionPointer;
	cpu->mode = 1;
	cpu->cpuTime_ps = 0;
	cpu->cpuCycleTime_ps = 31250;


	for (int i = 0; i < 32; ++i) {
		rv64imacfdcpu->ins_X[i] = 0;
		rv64imacfdcpu->X[i] = &rv64imacfdcpu->ins_X[i];
	}
	for (int i = 0; i < 4096; ++i) {
		rv64imacfdcpu->ins_CSR[i] = 0;
		rv64imacfdcpu->CSR[i] = &rv64imacfdcpu->ins_CSR[i];
	}

	rv64imacfdcpu->ZERO = 0;
	rv64imacfdcpu->RA = 0;
	rv64imacfdcpu->SP = 0;
	rv64imacfdcpu->GP = 0;
	rv64imacfdcpu->TP = 0;
	rv64imacfdcpu->T0 = 0;
	rv64imacfdcpu->T1 = 0;
	rv64imacfdcpu->T2 = 0;
	rv64imacfdcpu->S0 = 0;
	rv64imacfdcpu->S1 = 0;
	rv64imacfdcpu->A0 = 0;
	rv64imacfdcpu->A1 = 0;
	rv64imacfdcpu->A2 = 0;
	rv64imacfdcpu->A3 = 0;
	rv64imacfdcpu->A4 = 0;
	rv64imacfdcpu->A5 = 0;
	rv64imacfdcpu->A6 = 0;
	rv64imacfdcpu->A7 = 0;
	rv64imacfdcpu->S2 = 0;
	rv64imacfdcpu->S3 = 0;
	rv64imacfdcpu->S4 = 0;
	rv64imacfdcpu->S5 = 0;
	rv64imacfdcpu->S6 = 0;
	rv64imacfdcpu->S7 = 0;
	rv64imacfdcpu->S8 = 0;
	rv64imacfdcpu->S9 = 0;
	rv64imacfdcpu->S10 = 0;
	rv64imacfdcpu->S11 = 0;
	rv64imacfdcpu->T3 = 0;
	rv64imacfdcpu->T4 = 0;
	rv64imacfdcpu->T5 = 0;
	rv64imacfdcpu->T6 = 0;
	for (int i = 0; i < 8; ++i) {
		rv64imacfdcpu->FENCE[i] = 0;
	}
	for (int i = 0; i < 8; ++i) {
		rv64imacfdcpu->RES[i] = 0;
	}
	rv64imacfdcpu->PRIV = 0;
	rv64imacfdcpu->DPC = 0;
	rv64imacfdcpu->FCSR = 0;
	rv64imacfdcpu->MSTATUS = 0;
	rv64imacfdcpu->MIE = 0;
	rv64imacfdcpu->MIP = 0;
	for (int i = 0; i < 32; ++i) {
		rv64imacfdcpu->F[i] = 0;
	}
	rv64imacfdcpu->RES_ADDR = 0;

 	rv64imacfdcpu->X[0] = &rv64imacfdcpu->ZERO;
 	rv64imacfdcpu->X[1] = &rv64imacfdcpu->RA;
 	rv64imacfdcpu->X[2] = &rv64imacfdcpu->SP;
 	rv64imacfdcpu->X[3] = &rv64imacfdcpu->GP;
 	rv64imacfdcpu->X[4] = &rv64imacfdcpu->TP;
 	rv64imacfdcpu->X[5] = &rv64imacfdcpu->T0;
 	rv64imacfdcpu->X[6] = &rv64imacfdcpu->T1;
 	rv64imacfdcpu->X[7] = &rv64imacfdcpu->T2;
 	rv64imacfdcpu->X[8] = &rv64imacfdcpu->S0;
 	rv64imacfdcpu->X[9] = &rv64imacfdcpu->S1;
 	rv64imacfdcpu->X[10] = &rv64imacfdcpu->A0;
 	rv64imacfdcpu->X[11] = &rv64imacfdcpu->A1;
 	rv64imacfdcpu->X[12] = &rv64imacfdcpu->A2;
 	rv64imacfdcpu->X[13] = &rv64imacfdcpu->A3;
 	rv64imacfdcpu->X[14] = &rv64imacfdcpu->A4;
 	rv64imacfdcpu->X[15] = &rv64imacfdcpu->A5;
 	rv64imacfdcpu->X[16] = &rv64imacfdcpu->A6;
 	rv64imacfdcpu->X[17] = &rv64imacfdcpu->A7;
 	rv64imacfdcpu->X[18] = &rv64imacfdcpu->S2;
 	rv64imacfdcpu->X[19] = &rv64imacfdcpu->S3;
 	rv64imacfdcpu->X[20] = &rv64imacfdcpu->S4;
 	rv64imacfdcpu->X[21] = &rv64imacfdcpu->S5;
 	rv64imacfdcpu->X[22] = &rv64imacfdcpu->S6;
 	rv64imacfdcpu->X[23] = &rv64imacfdcpu->S7;
 	rv64imacfdcpu->X[24] = &rv64imacfdcpu->S8;
 	rv64imacfdcpu->X[25] = &rv64imacfdcpu->S9;
 	rv64imacfdcpu->X[26] = &rv64imacfdcpu->S10;
 	rv64imacfdcpu->X[27] = &rv64imacfdcpu->S11;
 	rv64imacfdcpu->X[28] = &rv64imacfdcpu->T3;
 	rv64imacfdcpu->X[29] = &rv64imacfdcpu->T4;
 	rv64imacfdcpu->X[30] = &rv64imacfdcpu->T5;
 	rv64imacfdcpu->X[31] = &rv64imacfdcpu->T6;
 	rv64imacfdcpu->CSR[3] = &rv64imacfdcpu->FCSR;
 	rv64imacfdcpu->CSR[768] = &rv64imacfdcpu->MSTATUS;
 	rv64imacfdcpu->CSR[772] = &rv64imacfdcpu->MIE;
 	rv64imacfdcpu->CSR[836] = &rv64imacfdcpu->MIP;

   	rv64imacfdcpu->PRIV = 3ULL;
   	rv64imacfdcpu->DPC = 0LL;
  	*rv64imacfdcpu->CSR[0] = 11ULL;
 	*rv64imacfdcpu->CSR[256] = 11ULL;
 	*rv64imacfdcpu->CSR[768] = 11ULL;
 	*rv64imacfdcpu->CSR[769] = 9223372036856090925ULL;
 	*rv64imacfdcpu->CSR[3088] = 3ULL;
 	*rv64imacfdcpu->CSR[772] = 4294966203ULL;
 	*rv64imacfdcpu->CSR[260] = 4294964019ULL;
 	*rv64imacfdcpu->CSR[4] = 4294963473ULL;
   	rv64imacfdcpu->RES_ADDR = -1LL;

}

void RV64IMACFDArch::deleteCPU(ETISS_CPU *cpu)
{
	delete (RV64IMACFD *) cpu ;
}

/**
	@return 8 (jump instruction + instruction of delay slot)
*/
unsigned RV64IMACFDArch::getMaximumInstructionSizeInBytes()
{
	return 8;
}

/**
	@return 2
*/
unsigned RV64IMACFDArch::getInstructionSizeInBytes()
{
	return 2;
}

/**
	@brief required headers (RV64IMACFD.h)
*/
const std::set<std::string> & RV64IMACFDArch::getHeaders() const
{
	return headers_ ;
}

void RV64IMACFDArch::initCodeBlock(etiss::CodeBlock & cb) const
{
	cb.fileglobalCode().insert("#include \"Arch/RV64IMACFD/RV64IMACFD.h\"\n");
	cb.fileglobalCode().insert("#include \"Arch/RV64IMACFD/RV64IMACFDFuncs.h\"\n");
	cb.functionglobalCode().insert("cpu->exception = 0;\n");
	cb.functionglobalCode().insert("cpu->return_pending = 0;\n");
	cb.functionglobalCode().insert("etiss_uint32 mem_ret_code = 0;\n");
}

etiss::plugin::gdb::GDBCore & RV64IMACFDArch::getGDBCore()
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

etiss::instr::InstructionGroup ISA16_RV64IMACFD("ISA16_RV64IMACFD", 16);
etiss::instr::InstructionClass ISA16_RV64IMACFDClass(1, "ISA16_RV64IMACFD", 16, ISA16_RV64IMACFD);
etiss::instr::InstructionGroup ISA32_RV64IMACFD("ISA32_RV64IMACFD", 32);
etiss::instr::InstructionClass ISA32_RV64IMACFDClass(1, "ISA32_RV64IMACFD", 32, ISA32_RV64IMACFD);

etiss::instr::InstructionCollection RV64IMACFDISA("RV64IMACFDISA", ISA16_RV64IMACFDClass, ISA32_RV64IMACFDClass);
