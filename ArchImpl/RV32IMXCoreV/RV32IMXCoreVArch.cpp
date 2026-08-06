/**
 * Generated on Wed, 05 Aug 2026 14:56:03 +0200.
 *
 * This file contains the architecture class for the RV32IMXCoreV core architecture.
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
         calculated during process (if possible), otherwise it is assumed to be the register size. Problems may occur
         when var_1 encounters bit manipulation such as "~" due to bit expansion. To change the nml model with explicit
         slicing e.g var_1 = val_2<3..0> or avoid bit manipulation for dynamic sliced variable. Otherwise, you have to
         manually correct it.

     7. Implementation dependent functionalities such as exception handling should be manully added. Corresponding
         interfaces are provided in RV32IMXCoreVArchSpecificImp.h

     8. RV32IMXCoreVGDBCore.h provides the GDBCore class to support gdb flavor debugging feature, modify iy if in need.

 *********************************************************************************************************************************/

#include "RV32IMXCoreVArch.h"
#include "RV32IMXCoreVFuncs.h"

#define RV32IMXCoreV_DEBUG_CALL 0
using namespace etiss;
using namespace etiss::instr;

RV32IMXCoreVArch::RV32IMXCoreVArch(unsigned int coreno) : CPUArch("RV32IMXCoreV"), coreno_(coreno)
{
    headers_.insert("Arch/RV32IMXCoreV/RV32IMXCoreV.h");
}

const std::set<std::string> &RV32IMXCoreVArch::getListenerSupportedRegisters()
{
    return listenerSupportedRegisters_;
}

ETISS_CPU *RV32IMXCoreVArch::newCPU()
{
    ETISS_CPU *ret = (ETISS_CPU *)new RV32IMXCoreV();
    resetCPU(ret, 0);
    return ret;
}

void RV32IMXCoreVArch::resetCPU(ETISS_CPU *cpu, etiss::uint64 *startpointer)
{
    memset(cpu, 0, sizeof(RV32IMXCoreV));
    RV32IMXCoreV *rv32imxcorevcpu = (RV32IMXCoreV *)cpu;

    if (startpointer)
        cpu->instructionPointer = *startpointer & ~((etiss::uint64)0x1);
    else
        cpu->instructionPointer = 0x0; //  reference to manual
    cpu->nextPc = cpu->instructionPointer;
    cpu->mode = 1;
    cpu->cpuTime_ps = 0;
    cpu->cpuCycleTime_ps = 31250;

    for (int i = 0; i < 4096; ++i)
    {
        rv32imxcorevcpu->ins_CSR[i] = 0;
        rv32imxcorevcpu->CSR[i] = &rv32imxcorevcpu->ins_CSR[i];
    }
    for (int i = 0; i < 32; ++i)
    {
        rv32imxcorevcpu->ins_X[i] = 0;
        rv32imxcorevcpu->X[i] = &rv32imxcorevcpu->ins_X[i];
    }

    for (int i = 0; i < 8; ++i)
    {
        rv32imxcorevcpu->FENCE[i] = 0;
    }
    for (int i = 0; i < 8; ++i)
    {
        rv32imxcorevcpu->RES[i] = 0;
    }
    rv32imxcorevcpu->MSTATUS = 0;
    rv32imxcorevcpu->MIE = 0;
    rv32imxcorevcpu->MIP = 0;
    rv32imxcorevcpu->CYCLE = 0;
    rv32imxcorevcpu->CYCLEH = 0;
    rv32imxcorevcpu->MCYCLE = 0;
    rv32imxcorevcpu->MCYCLEH = 0;
    rv32imxcorevcpu->TIME = 0;
    rv32imxcorevcpu->TIMEH = 0;
    rv32imxcorevcpu->INSTRET = 0;
    rv32imxcorevcpu->INSTRETH = 0;
    rv32imxcorevcpu->MINSTRET = 0;
    rv32imxcorevcpu->MINSTRETH = 0;
    rv32imxcorevcpu->MVENDORID = 0;
    rv32imxcorevcpu->MARCHID = 0;
    rv32imxcorevcpu->MIMPID = 0;
    rv32imxcorevcpu->MHARTID = 0;
    rv32imxcorevcpu->MISA = 0;
    rv32imxcorevcpu->MEDELEG = 0;
    rv32imxcorevcpu->MIDELEG = 0;
    rv32imxcorevcpu->MTVEC = 0;
    rv32imxcorevcpu->MCOUNTEREN = 0;
    rv32imxcorevcpu->MSCRATCH = 0;
    rv32imxcorevcpu->MEPC = 0;
    rv32imxcorevcpu->MCAUSE = 0;
    rv32imxcorevcpu->MTVAL = 0;
    rv32imxcorevcpu->ZERO = 0;
    rv32imxcorevcpu->RA = 0;
    rv32imxcorevcpu->SP = 0;
    rv32imxcorevcpu->GP = 0;
    rv32imxcorevcpu->TP = 0;
    rv32imxcorevcpu->T0 = 0;
    rv32imxcorevcpu->T1 = 0;
    rv32imxcorevcpu->T2 = 0;
    rv32imxcorevcpu->S0 = 0;
    rv32imxcorevcpu->S1 = 0;
    rv32imxcorevcpu->A0 = 0;
    rv32imxcorevcpu->A1 = 0;
    rv32imxcorevcpu->A2 = 0;
    rv32imxcorevcpu->A3 = 0;
    rv32imxcorevcpu->A4 = 0;
    rv32imxcorevcpu->A5 = 0;
    rv32imxcorevcpu->A6 = 0;
    rv32imxcorevcpu->A7 = 0;
    rv32imxcorevcpu->S2 = 0;
    rv32imxcorevcpu->S3 = 0;
    rv32imxcorevcpu->S4 = 0;
    rv32imxcorevcpu->S5 = 0;
    rv32imxcorevcpu->S6 = 0;
    rv32imxcorevcpu->S7 = 0;
    rv32imxcorevcpu->S8 = 0;
    rv32imxcorevcpu->S9 = 0;
    rv32imxcorevcpu->S10 = 0;
    rv32imxcorevcpu->S11 = 0;
    rv32imxcorevcpu->T3 = 0;
    rv32imxcorevcpu->T4 = 0;
    rv32imxcorevcpu->T5 = 0;
    rv32imxcorevcpu->T6 = 0;
    rv32imxcorevcpu->PRIV = 0;
    rv32imxcorevcpu->DPC = 0;
    rv32imxcorevcpu->MSTATUS = 0;
    rv32imxcorevcpu->MIE = 0;
    rv32imxcorevcpu->MIP = 0;
    rv32imxcorevcpu->CYCLE = 0;
    rv32imxcorevcpu->CYCLEH = 0;
    rv32imxcorevcpu->MCYCLE = 0;
    rv32imxcorevcpu->MCYCLEH = 0;
    rv32imxcorevcpu->TIME = 0;
    rv32imxcorevcpu->TIMEH = 0;
    rv32imxcorevcpu->INSTRET = 0;
    rv32imxcorevcpu->INSTRETH = 0;
    rv32imxcorevcpu->MINSTRET = 0;
    rv32imxcorevcpu->MINSTRETH = 0;
    rv32imxcorevcpu->MVENDORID = 0;
    rv32imxcorevcpu->MARCHID = 0;
    rv32imxcorevcpu->MIMPID = 0;
    rv32imxcorevcpu->MHARTID = 0;
    rv32imxcorevcpu->MISA = 0;
    rv32imxcorevcpu->MEDELEG = 0;
    rv32imxcorevcpu->MIDELEG = 0;
    rv32imxcorevcpu->MTVEC = 0;
    rv32imxcorevcpu->MCOUNTEREN = 0;
    rv32imxcorevcpu->MSCRATCH = 0;
    rv32imxcorevcpu->MEPC = 0;
    rv32imxcorevcpu->MCAUSE = 0;
    rv32imxcorevcpu->MTVAL = 0;
    rv32imxcorevcpu->ZERO = 0;
    rv32imxcorevcpu->RA = 0;
    rv32imxcorevcpu->SP = 0;
    rv32imxcorevcpu->GP = 0;
    rv32imxcorevcpu->TP = 0;
    rv32imxcorevcpu->T0 = 0;
    rv32imxcorevcpu->T1 = 0;
    rv32imxcorevcpu->T2 = 0;
    rv32imxcorevcpu->S0 = 0;
    rv32imxcorevcpu->S1 = 0;
    rv32imxcorevcpu->A0 = 0;
    rv32imxcorevcpu->A1 = 0;
    rv32imxcorevcpu->A2 = 0;
    rv32imxcorevcpu->A3 = 0;
    rv32imxcorevcpu->A4 = 0;
    rv32imxcorevcpu->A5 = 0;
    rv32imxcorevcpu->A6 = 0;
    rv32imxcorevcpu->A7 = 0;
    rv32imxcorevcpu->S2 = 0;
    rv32imxcorevcpu->S3 = 0;
    rv32imxcorevcpu->S4 = 0;
    rv32imxcorevcpu->S5 = 0;
    rv32imxcorevcpu->S6 = 0;
    rv32imxcorevcpu->S7 = 0;
    rv32imxcorevcpu->S8 = 0;
    rv32imxcorevcpu->S9 = 0;
    rv32imxcorevcpu->S10 = 0;
    rv32imxcorevcpu->S11 = 0;
    rv32imxcorevcpu->T3 = 0;
    rv32imxcorevcpu->T4 = 0;
    rv32imxcorevcpu->T5 = 0;
    rv32imxcorevcpu->T6 = 0;

    rv32imxcorevcpu->CSR[768] = &rv32imxcorevcpu->MSTATUS;
    rv32imxcorevcpu->CSR[772] = &rv32imxcorevcpu->MIE;
    rv32imxcorevcpu->CSR[836] = &rv32imxcorevcpu->MIP;
    rv32imxcorevcpu->CSR[3072] = &rv32imxcorevcpu->CYCLE;
    rv32imxcorevcpu->CSR[3200] = &rv32imxcorevcpu->CYCLEH;
    rv32imxcorevcpu->CSR[2816] = &rv32imxcorevcpu->MCYCLE;
    rv32imxcorevcpu->CSR[2944] = &rv32imxcorevcpu->MCYCLEH;
    rv32imxcorevcpu->CSR[3073] = &rv32imxcorevcpu->TIME;
    rv32imxcorevcpu->CSR[3201] = &rv32imxcorevcpu->TIMEH;
    rv32imxcorevcpu->CSR[3074] = &rv32imxcorevcpu->INSTRET;
    rv32imxcorevcpu->CSR[3202] = &rv32imxcorevcpu->INSTRETH;
    rv32imxcorevcpu->CSR[2818] = &rv32imxcorevcpu->MINSTRET;
    rv32imxcorevcpu->CSR[2946] = &rv32imxcorevcpu->MINSTRETH;
    rv32imxcorevcpu->CSR[3857] = &rv32imxcorevcpu->MVENDORID;
    rv32imxcorevcpu->CSR[3858] = &rv32imxcorevcpu->MARCHID;
    rv32imxcorevcpu->CSR[3859] = &rv32imxcorevcpu->MIMPID;
    rv32imxcorevcpu->CSR[3860] = &rv32imxcorevcpu->MHARTID;
    rv32imxcorevcpu->CSR[769] = &rv32imxcorevcpu->MISA;
    rv32imxcorevcpu->CSR[770] = &rv32imxcorevcpu->MEDELEG;
    rv32imxcorevcpu->CSR[771] = &rv32imxcorevcpu->MIDELEG;
    rv32imxcorevcpu->CSR[773] = &rv32imxcorevcpu->MTVEC;
    rv32imxcorevcpu->CSR[774] = &rv32imxcorevcpu->MCOUNTEREN;
    rv32imxcorevcpu->CSR[832] = &rv32imxcorevcpu->MSCRATCH;
    rv32imxcorevcpu->CSR[833] = &rv32imxcorevcpu->MEPC;
    rv32imxcorevcpu->CSR[834] = &rv32imxcorevcpu->MCAUSE;
    rv32imxcorevcpu->CSR[835] = &rv32imxcorevcpu->MTVAL;
    rv32imxcorevcpu->X[0] = &rv32imxcorevcpu->ZERO;
    rv32imxcorevcpu->X[1] = &rv32imxcorevcpu->RA;
    rv32imxcorevcpu->X[2] = &rv32imxcorevcpu->SP;
    rv32imxcorevcpu->X[3] = &rv32imxcorevcpu->GP;
    rv32imxcorevcpu->X[4] = &rv32imxcorevcpu->TP;
    rv32imxcorevcpu->X[5] = &rv32imxcorevcpu->T0;
    rv32imxcorevcpu->X[6] = &rv32imxcorevcpu->T1;
    rv32imxcorevcpu->X[7] = &rv32imxcorevcpu->T2;
    rv32imxcorevcpu->X[8] = &rv32imxcorevcpu->S0;
    rv32imxcorevcpu->X[9] = &rv32imxcorevcpu->S1;
    rv32imxcorevcpu->X[10] = &rv32imxcorevcpu->A0;
    rv32imxcorevcpu->X[11] = &rv32imxcorevcpu->A1;
    rv32imxcorevcpu->X[12] = &rv32imxcorevcpu->A2;
    rv32imxcorevcpu->X[13] = &rv32imxcorevcpu->A3;
    rv32imxcorevcpu->X[14] = &rv32imxcorevcpu->A4;
    rv32imxcorevcpu->X[15] = &rv32imxcorevcpu->A5;
    rv32imxcorevcpu->X[16] = &rv32imxcorevcpu->A6;
    rv32imxcorevcpu->X[17] = &rv32imxcorevcpu->A7;
    rv32imxcorevcpu->X[18] = &rv32imxcorevcpu->S2;
    rv32imxcorevcpu->X[19] = &rv32imxcorevcpu->S3;
    rv32imxcorevcpu->X[20] = &rv32imxcorevcpu->S4;
    rv32imxcorevcpu->X[21] = &rv32imxcorevcpu->S5;
    rv32imxcorevcpu->X[22] = &rv32imxcorevcpu->S6;
    rv32imxcorevcpu->X[23] = &rv32imxcorevcpu->S7;
    rv32imxcorevcpu->X[24] = &rv32imxcorevcpu->S8;
    rv32imxcorevcpu->X[25] = &rv32imxcorevcpu->S9;
    rv32imxcorevcpu->X[26] = &rv32imxcorevcpu->S10;
    rv32imxcorevcpu->X[27] = &rv32imxcorevcpu->S11;
    rv32imxcorevcpu->X[28] = &rv32imxcorevcpu->T3;
    rv32imxcorevcpu->X[29] = &rv32imxcorevcpu->T4;
    rv32imxcorevcpu->X[30] = &rv32imxcorevcpu->T5;
    rv32imxcorevcpu->X[31] = &rv32imxcorevcpu->T6;

    *rv32imxcorevcpu->CSR[0] = 11ULL;
    *rv32imxcorevcpu->CSR[256] = 11ULL;
    *rv32imxcorevcpu->CSR[768] = 11ULL;
    *rv32imxcorevcpu->CSR[769] = 1075056941ULL;
    *rv32imxcorevcpu->CSR[3088] = 3ULL;
    *rv32imxcorevcpu->CSR[772] = 4294966203ULL;
    *rv32imxcorevcpu->CSR[260] = 4294964019ULL;
    *rv32imxcorevcpu->CSR[4] = 4294963473ULL;
    rv32imxcorevcpu->PRIV = 3ULL;
    rv32imxcorevcpu->DPC = 0LL;
}

void RV32IMXCoreVArch::deleteCPU(ETISS_CPU *cpu)
{
    delete (RV32IMXCoreV *)cpu;
}

/**
    @return 8 (jump instruction + instruction of delay slot)
*/
unsigned RV32IMXCoreVArch::getMaximumInstructionSizeInBytes()
{
    return 8;
}

/**
    @return 2
*/
unsigned RV32IMXCoreVArch::getInstructionSizeInBytes()
{
    return 2;
}

/**
    @brief required headers (RV32IMXCoreV.h)
*/
const std::set<std::string> &RV32IMXCoreVArch::getHeaders() const
{
    return headers_;
}

void RV32IMXCoreVArch::initCodeBlock(etiss::CodeBlock &cb) const
{
    cb.fileglobalCode().insert("#include \"Arch/RV32IMXCoreV/RV32IMXCoreV.h\"\n");
    cb.fileglobalCode().insert("#include \"Arch/RV32IMXCoreV/RV32IMXCoreVFuncs.h\"\n");
    cb.functionglobalCode().insert("cpu->exception = 0;\n");
    cb.functionglobalCode().insert("cpu->return_pending = 0;\n");
    cb.functionglobalCode().insert("etiss_uint32 mem_ret_code = 0;\n");
}

etiss::plugin::gdb::GDBCore &RV32IMXCoreVArch::getGDBCore()
{
    return gdbcore_;
}

// clang-format off
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
// clang-format on

etiss::instr::InstructionGroup ISA32_RV32IMXCoreV("ISA32_RV32IMXCoreV", 32);
etiss::instr::InstructionClass ISA32_RV32IMXCoreVClass(1, "ISA32_RV32IMXCoreV", 32, ISA32_RV32IMXCoreV);

etiss::instr::InstructionCollection RV32IMXCoreVISA("RV32IMXCoreVISA", ISA32_RV32IMXCoreVClass);
