/*

        @copyright

        <pre>

        Copyright 2018 Chair of Electronic Design Automation, TUM

        This file is part of ETISS tool, see <https://gitlab.lrz.de/de-tum-ei-eda-open/etiss>.

        The initial version of this software has been created with the funding support by the German Federal
        Ministry of Education and Research (BMBF) in the project EffektiV under grant 01IS13022.

        Redistribution and use in source and binary forms, with or without modification, are permitted
        provided that the following conditions are met:

        1. Redistributions of source code must retain the above copyright notice, this list of conditions and
        the following disclaimer.

        2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions
        and the following disclaimer in the documentation and/or other materials provided with the distribution.

        3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse
        or promote products derived from this software without specific prior written permission.

        THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
        WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
        PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
        DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
        PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
        HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
        NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
        POSSIBILITY OF SUCH DAMAGE.

        </pre>

        @author Chair of Electronic Design Automation, TUM

        @version 0.1

*/

// This file was generated on Thu Mar 22 15:15:02 CET 2018
// If necessary please modify this file according to the instructions
// Contact: eda@tum

#ifndef ETISS_RISCVArch_RISCVGDBCORE_H_
#define ETISS_RISCVArch_RISCVGDBCORE_H_

#include "etiss/IntegratedLibrary/gdb/GDBCore.h"
#include <sstream>

/**
        @brief This class is the brige between RISCV architecture and gdbserver

        @details Gdbserver integrated in ETISS calls GDBCore to read/write registers via virtualStrruct
                         The index in mapRegister() should strictly follow the RISCV gdb tool defined register
                         order. Because gdbserver will send raw register data sequentially in strict order over
                         RSP ->TCP/IP ->RSP protocal

                         Check the order with gdb command:
                         $(gdb) info all-registers
                         which lists all registers supported and its order.

                         By default only general purpose register and instruction pointer are supported. Further
                         Special Function Register/Control and Status Register could be added manually. Meanwhile
                         virtualStruct in RISCVArch.cpp should be modified as well as well

*/
class RISCVGDBCore : public etiss::plugin::gdb::GDBCore
{
  public:
    std::string mapRegister(unsigned index)
    {
        if (index < 32)
        {
            std::stringstream ss;
            ss << "R" << index;
            return ss.str();
        }
        switch (index)
        {
        case 32:
            return "instructionPointer";
            /**************************************************************************
             *   Further register should be added here to send data over gdbserver	  *
             ***************************************************************************/
        }
        if (index > 64)
        {
            std::stringstream ss;
            ss << "CSR" << index - 65;
            return ss.str();
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
        // Modify according to RISCV manual
        return true;
    }
};

#endif
