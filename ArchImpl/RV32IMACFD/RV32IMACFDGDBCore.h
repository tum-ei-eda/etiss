/**
 * Generated on Mon, 27 Apr 2026 10:48:14 +0000.
 *
 * This file contains the GDBCore adapter for the RV32IMACFD core architecture.
 *
 * WARNING: This file contains user-added code, be mindful when overwriting this with
 * generated code!
 */

#ifndef ETISS_RV32IMACFDArch_RV32IMACFDGDBCORE_H_
#define ETISS_RV32IMACFDArch_RV32IMACFDGDBCORE_H_

#include "etiss/IntegratedLibrary/gdb/GDBCore.h"
#include <sstream>

/**
    @brief This class is the brige between RV32IMACFD architecture and gdbserver

    @details Gdbserver integrated in ETISS calls GDBCore to read/write registers via virtualStrruct
                The index in mapRegister() should strictly follow the RV32IMACFD gdb tool defined register
                order. Because gdbserver will send raw register data sequentially in strict order over
                RSP ->TCP/IP ->RSP protocal

                Check the order with gdb command:
                $(gdb) info all-registers
                which lists all registers supported and its order.

                By default only general purpose register and instruction pointer are supported. Further
                Special Function Register/Control and Status Register could be added manually. Meanwhile
                virtualStruct in RV32IMACFDArch.cpp should be modified as well as well

*/
class RV32IMACFDGDBCore : public etiss::plugin::gdb::GDBCore
{
  public:
    std::string mapRegister(unsigned index)
    {
        switch (index)
        {
        case 0:
            return "X0"; // zero
        case 1:
            return "X1"; // ra
        case 2:
            return "X2"; // sp
        case 3:
            return "X3"; // gp
        case 4:
            return "X4"; // tp
        case 5:
            return "X5"; // t0
        case 6:
            return "X6"; // t1
        case 7:
            return "X7"; // t2
        case 8:
            return "X8"; // fp
        case 9:
            return "X9"; // s1
        case 10:
            return "X10"; // a0
        case 11:
            return "X11"; // a1
        case 12:
            return "X12"; // a2
        case 13:
            return "X13"; // a3
        case 14:
            return "X14"; // a4
        case 15:
            return "X15"; // a5
        case 16:
            return "X16"; // a6
        case 17:
            return "X17"; // a7
        case 18:
            return "X18"; // s2
        case 19:
            return "X19"; // s3
        case 20:
            return "X20"; // s4
        case 21:
            return "X21"; // s5
        case 22:
            return "X22"; // s6
        case 23:
            return "X23"; // s7
        case 24:
            return "X24"; // s8
        case 25:
            return "X25"; // s9
        case 26:
            return "X26"; // s10
        case 27:
            return "X27"; // s11
        case 28:
            return "X28"; // t3
        case 29:
            return "X29"; // t4
        case 30:
            return "X30"; // t5
        case 31:
            return "X31"; // t6
        case 32:
            return "instructionPointer"; // pc
        case 33:
            return "F0"; // ft0
        case 34:
            return "F1"; // ft1
        case 35:
            return "F2"; // ft2
        case 36:
            return "F3"; // ft3
        case 37:
            return "F4"; // ft4
        case 38:
            return "F5"; // ft5
        case 39:
            return "F6"; // ft6
        case 40:
            return "F7"; // ft7
        case 41:
            return "F8"; // fs0
        case 42:
            return "F9"; // fs1
        case 43:
            return "F10"; // fa0
        case 44:
            return "F11"; // fa1
        case 45:
            return "F12"; // fa2
        case 46:
            return "F13"; // fa3
        case 47:
            return "F14"; // fa4
        case 48:
            return "F15"; // fa5
        case 49:
            return "F16"; // fa6
        case 50:
            return "F17"; // fa7
        case 51:
            return "F18"; // fs2
        case 52:
            return "F19"; // fs3
        case 53:
            return "F20"; // fs4
        case 54:
            return "F21"; // fs5
        case 55:
            return "F22"; // fs6
        case 56:
            return "F23"; // fs7
        case 57:
            return "F24"; // fs8
        case 58:
            return "F25"; // fs9
        case 59:
            return "F26"; // fs10
        case 60:
            return "F27"; // fs11
        case 61:
            return "F28"; // ft8
        case 62:
            return "F29"; // ft9
        case 63:
            return "F30"; // ft10
        case 64:
            return "F31"; // ft11
        case 66:
            return "CSR1"; // fflags
        case 67:
            return "CSR2"; // frm
        case 68:
            return "CSR3"; // fcsr
        case 3923:
            return "CSR3858"; // marchid
        case 3924:
            return "CSR3859"; // mimpid
        case 3925:
            return "CSR3860"; // mhartid
        case 833:
            return "CSR768"; // mstatus
        case 834:
            return "CSR769"; // misa
        case 835:
            return "CSR770"; // medeleg
        case 836:
            return "CSR771"; // mideleg
        case 837:
            return "CSR772"; // mie
        case 838:
            return "CSR773"; // mtvec
        case 839:
            return "CSR774"; // mcounteren
        case 897:
            return "CSR832"; // mscratch
        case 898:
            return "CSR833"; // mepc
        case 899:
            return "CSR834"; // mcause
        case 900:
            return "CSR835"; // mtval
        case 901:
            return "CSR836"; // mip
        case 2881:
            return "CSR2816"; // mcycle
        case 3009:
            return "CSR2944"; // mcycleh
        case 2883:
            return "CSR2818"; // minstret
        case 3011:
            return "CSR2946"; // minstreth
        case 3137:
            return "CSR3072"; // cycle
        case 3265:
            return "CSR3200"; // cycleh
        case 3138:
            return "CSR3073"; // time
        case 3266:
            return "CSR3201"; // timeh
        case 3139:
            return "CSR3074"; // instret
        case 3267:
            return "CSR3202"; // instreth
            /**************************************************************************
             *   Further register should be added here to send data over gdbserver	  *
             **************************************************************************/
        }
        return "";
  }

    unsigned mapRegister(std::string name) { return INVALIDMAPPING; }

    unsigned mappedRegisterCount()
    {
        // Modify according to sent register number
        return 33;
    }

    etiss::uint64 getInstructionPointer(ETISS_CPU *cpu) { return cpu->instructionPointer; }

    bool isLittleEndian()
    {
        // Modify according to RV32IMACFD manual
        return true;
    }
};

#endif
