/**

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

        This file is part of ETISS tool, see <https://github.com/tum-ei-eda/etiss>.

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

        @author Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM

        @date July 29, 2014

        @version 0.1

*/
/**
        @file

        @brief implementation of etiss/IntegratedLibrary/gdb/GDBServer.h

        @detail

*/
#include "etiss/IntegratedLibrary/gdb/GDBServer.h"
#include "etiss/CPUCore.h"
#include "etiss/IntegratedLibrary/gdb/Hex.h"
#include "etiss/IntegratedLibrary/gdb/UnixTCPGDBConnection.h"
#include "etiss/jit/types.h"
#include <chrono>
#include <cstring>
#include <thread>

using namespace etiss::plugin::gdb;

BreakpointDB::BreakpointDB()
{
    instrbrkpt_ = 0;
}

void BreakpointDB::set(etiss::uint64 addr, etiss::uint32 val)
{
    if (instrbrkpt_ == 0)
    {
        if (val == 0)
            return;
        instrbrkpt_ = new etiss::uint32 ***[1 << 16];
        memset(instrbrkpt_, 0, sizeof(etiss::uint32 * **[1 << 16]));
    }
    unsigned a1 = (addr)&0xFFFF;
    if (instrbrkpt_[a1] == 0)
    {
        if (val == 0)
            return;
        instrbrkpt_[a1] = new etiss::uint32 **[1 << 16];
        memset(instrbrkpt_[a1], 0, sizeof(etiss::uint32 * *[1 << 16]));
    }
    unsigned a2 = (addr >> 16) & 0xFFFF;
    if (instrbrkpt_[a1][a2] == 0)
    {
        if (val == 0)
            return;
        instrbrkpt_[a1][a2] = new etiss::uint32 *[1 << 16];
        memset(instrbrkpt_[a1][a2], 0, sizeof(etiss::uint32 * [1 << 16]));
    }
    unsigned a3 = (addr >> 32) & 0xFFFF;
    if (instrbrkpt_[a1][a2][a3] == 0)
    {
        if (val == 0)
            return;
        instrbrkpt_[a1][a2][a3] = new etiss::uint32[1 << 16];
        memset(instrbrkpt_[a1][a2][a3], 0, sizeof(etiss::uint32[1 << 16]));
    }
    unsigned a4 = (addr >> 48) & 0xFFFF;
    instrbrkpt_[a1][a2][a3][a4] = val;
    if (val == 0)
    { // cleanup
        bool empty = true;
        for (unsigned i = 0; i < (1 << 16); i++)
        {
            if (instrbrkpt_[a1][a2][a3][i] != 0)
            {
                empty = false;
                break;
            }
        }
        if (!empty)
            return;
        delete instrbrkpt_[a1][a2][a3];
        instrbrkpt_[a1][a2][a3] = 0;
        for (unsigned i = 0; i < (1 << 16); i++)
        {
            if (instrbrkpt_[a1][a2][i] != 0)
            {
                empty = false;
                break;
            }
        }
        if (!empty)
            return;
        delete instrbrkpt_[a1][a2];
        instrbrkpt_[a1][a2] = 0;
        for (unsigned i = 0; i < (1 << 16); i++)
        {
            if (instrbrkpt_[a1][i] != 0)
            {
                empty = false;
                break;
            }
        }
        if (!empty)
            return;
        delete instrbrkpt_[a1];
        instrbrkpt_[a1] = 0;
        for (unsigned i = 0; i < (1 << 16); i++)
        {
            if (instrbrkpt_[i] != 0)
            {
                empty = false;
                break;
            }
        }
        if (!empty)
            return;
        delete instrbrkpt_;
        instrbrkpt_ = 0;
    }
}

Server::Server(etiss::plugin::gdb::PacketProtocol &pp) : con_(pp)
{
    status_paused_ = true;
    gdb_status_paused_ = true;
    status_step_ = false;
    status_pending_jump_ = false;
    status_pending_kill_ = false;
    status_jumpaddr_ = false;
    arch_ = nullptr;
    cpu_ = nullptr;
    system_ = nullptr;
    execute_skip_count = 25;
    execute_skip_index = 0;
    minimal_pc_alignment = 2;
}

etiss::int32 Server::preInstructionCallback()
{
    // check for instruction breakpoints
    if (unlikely(!breakpoints_.isEmpty()))
    {
        etiss::uint32 bp = breakpoints_.get(arch_->getGDBCore().getInstructionPointer(cpu_) >> minimal_pc_alignment);
        if (unlikely(bp != 0))
        {
            if ((bp & (BreakpointDB::BPTYPE_BREAK_HW | BreakpointDB::BPTYPE_BREAK_MEM)) != 0)
            {
                status_paused_ = true;
            }
        }
    }
    // apply single step pause
    if (unlikely(status_step_ > 0))
    {
        status_paused_ = true;
        status_step_--;
    }
    if (unlikely(status_pending_kill_))
    {
        return RETURNCODE::CPUTERMINATED;
    }
    // check paused state (due to singlestep,ctrl+c)
    if (unlikely(status_paused_))
    {
        if (!gdb_status_paused_)
        { // answer pending 'c'/'s' command
            std::cout << "GDB: answer: " << "T"<<hex::fromByte(5) << std::endl;
            con_.snd("T" + hex::fromByte(5), false);
            gdb_status_paused_ = true;
        }

        while (unlikely(status_paused_))
        {
            handlePacket(true);
            if (unlikely(status_pending_kill_))
            {
                return RETURNCODE::CPUTERMINATED;
            }
            if (status_pending_jump_)
            {
                cpu_->instructionPointer = status_jumpaddr_;
                status_pending_jump_ = false;
            }
        }
    }

    return RETURNCODE::NOERROR;
}

etiss::int32 Server::execute()
{

    if (unlikely(status_pending_kill_))
    {
        return RETURNCODE::CPUTERMINATED;
    }

    if ((execute_skip_index++) > execute_skip_count)
    { // connections such as tcp sockets have a large overhead. to provide acceptable performance packet checks may not
      // be performed too frequent
        execute_skip_index = 0;
        // check for BREAK event in between blocks
        handlePacket(false);
    }
    if (unlikely(status_pending_kill_))
    {
        return RETURNCODE::CPUTERMINATED;
    }

    return 0;
}

static void Server_finalizeInstrSet(etiss::instr::InstructionSet *set, std::string pcode)
{
    if (set == nullptr)
        return;
    set->foreach ([pcode](etiss::instr::Instruction &instr) {
        instr.addCallback(
            [pcode](etiss::instr::BitArray &, etiss::CodeSet &cs, etiss::instr::InstructionContext &) {
                etiss::CodePart &cp = cs.prepend(etiss::CodePart::PREINITIALDEBUGRETURNING);
                cp.code() = std::string("{\n"
                                        "\tetiss_int32 _gdb_exception = gdb_pre_instruction(cpu,system,") +
                            pcode +
                            ");\n"
                            "\tif (_gdb_exception != 0)\n\t return _gdb_exception==-16?0:_gdb_exception;\n"
                            "}";
                return true;
            },
            0);
        /// TODO? ensure instruction pointer update
    });
}

void Server::finalizeInstrSet(etiss::instr::ModedInstructionSet &mis) const
{
    std::string pcode = getPointerCode();
    mis.foreach ([pcode](etiss::instr::VariableInstructionSet &vis) {
        vis.foreach ([pcode](etiss::instr::InstructionSet &set) { Server_finalizeInstrSet(&set, pcode); });
    });
}

void Server::finalizeCodeBlock(etiss::CodeBlock &cb) const
{

    cb.fileglobalCode().insert("extern etiss_int32 gdb_pre_instruction(ETISS_CPU * ,ETISS_System * ,void * );extern "
                               "void gdb_pre_instruction_noreturn(ETISS_CPU * ,ETISS_System * ,void * );");
}

void Server::handlePacket(bool block)
{

    if (con_.available(block))
    {
        bool isnotification;
        std::string command = con_.rcv(isnotification);
        std::cout << "command=" << command << std::endl;
        if (command.length() > 0)
        {
            if (!status_paused_)
            {
                if (!gdb_status_paused_)
                { // answer pending 'c'/'s' command
                    std::cout << "GDB: answer: " << "T"<<hex::fromByte(5) << std::endl;
                    con_.snd("T" + hex::fromByte(5), false);
                    gdb_status_paused_ = true;
                }
                status_paused_ = true;
            }
            bool nodbgaction = false;
            std::string answer;
            bool answerisnotification = false;
            switch (command[0])
            {
            case 'g': // read registers
            {
                // for (unsigned i = 0; i < arch_->getGDBCore().mappedRegisterCount(); i++)
                for (unsigned i = 0; i < 33; i++)
                {
                    std::string regname = arch_->getGDBCore().mapRegister(i);
                    auto f = plugin_core_->getStruct()->findName(regname);
                    if (!f)
                    {
                        answer = "EFF";
                        etiss::log(etiss::ERROR, "4: Faulty implementation of the GDBCore: Register not found", regname,
                                   *plugin_core_);
                        break;
                    }
                    switch (f->width_)
                    {
                    case 1:
                        hex::fromInt(answer, (uint8_t)f->read(), arch_->getGDBCore().isLittleEndian());
                        break;
                    case 2:
                        hex::fromInt(answer, (uint16_t)f->read(), arch_->getGDBCore().isLittleEndian());
                        break;
                    case 4:
                        hex::fromInt(answer, (uint32_t)f->read(), arch_->getGDBCore().isLittleEndian());
                        break;
                    case 8:
                        hex::fromInt(answer, (uint64_t)f->read(), arch_->getGDBCore().isLittleEndian());
                        break;
                    default:
                        answer = "EFF";
                        etiss::log(etiss::ERROR, "GDB g: Invalid read length");
                    }
                }
            }
            break;
            case 'G': // write registers
            {
                size_t treglen = 0;
                for (unsigned i = 0; i < arch_->getGDBCore().mappedRegisterCount(); i++)
                {
                    auto f = plugin_core_->getStruct()->findName(arch_->getGDBCore().mapRegister(i));
                    if (!f)
                    {
                        answer = "EFF";
                        etiss::log(etiss::ERROR, "2: Faulty implementation of the GDBCore: Register not found",
                                   arch_->getGDBCore().mapRegister(i), *plugin_core_);
                        break;
                    }
                    treglen += f->width_;
                }
                if (command.length() == (treglen * 2) + 1)
                {
                    answer = "OK";
                    size_t off = 1;
                    for (unsigned i = 0; i < arch_->getGDBCore().mappedRegisterCount(); i++)
                    {
                        std::string regname = arch_->getGDBCore().mapRegister(i);
                        auto f = plugin_core_->getStruct()->findName(regname);
                        if (!f)
                        {
                            answer = "EFF";
                            etiss::log(etiss::ERROR, "3: Faulty implementation of the GDBCore: Register not found",
                                       regname, *plugin_core_);
                            break;
                        }
                        switch (f->width_)
                        {
                        case 1:
                            f->write(hex::toInt<uint8_t>(command, arch_->getGDBCore().isLittleEndian(), off));
                            break;
                        case 2:
                            f->write(hex::toInt<uint16_t>(command, arch_->getGDBCore().isLittleEndian(), off));
                            break;
                        case 4:
                            f->write(hex::toInt<uint32_t>(command, arch_->getGDBCore().isLittleEndian(), off));
                            break;
                        case 8:
                            f->write(hex::toInt<uint64_t>(command, arch_->getGDBCore().isLittleEndian(), off));
                            break;
                        default:
                            answer = "EFF";
                            etiss::log(etiss::ERROR, "GDB G: Invalid write length");
                        }
                        off += f->width_ * 2;
                    }
                }
                else
                {
                    answer = "E11";
                }
            }
            break;
            case 'P': // write a register
            {
                size_t off = 1;
                unsigned regIndex = 0;
                std::string valToWrite;
                if (command.length() > 1)
                {
                    for (size_t i = 1; i < command.length(); ++i)
                    {
                        if (command[i] == '=' && command.length() > i + 1)
                        {
                            valToWrite = command.substr(i + 1);
                            break;
                        }
                        regIndex = (regIndex << 4) | hex::fromHex(command[i]);
                        answer = "OK";
                    }
                }
                auto f = plugin_core_->getStruct()->findName(arch_->getGDBCore().mapRegister(regIndex));
                if (!f)
                {
                    answer = "EFF";
                    etiss::log(etiss::ERROR, "1: Faulty implementation of the GDBCore: Register not found",
                               arch_->getGDBCore().mapRegister(regIndex), *plugin_core_);
                    break;
                }
                switch (f->width_)
                {
                case 1:
                    f->write(hex::toInt<uint8_t>(valToWrite, arch_->getGDBCore().isLittleEndian(), off));
                    break;
                case 2:
                    f->write(hex::toInt<uint16_t>(valToWrite, arch_->getGDBCore().isLittleEndian(), off));
                    break;
                case 4:
                    f->write(hex::toInt<uint32_t>(valToWrite, arch_->getGDBCore().isLittleEndian(), off));
                    break;
                case 8:
                    f->write(hex::toInt<uint64_t>(valToWrite, arch_->getGDBCore().isLittleEndian(), off));
                    break;
                default:
                    answer = "EFF";
                    etiss::log(etiss::ERROR, "GDB P: Invalid write length");
                }
                off += f->width_ * 2;
            }
            break;
            case 'p': // read a register
            {
                unsigned regIndex = 0;
                if (command.length() > 1)
                {
                    for (size_t i = 1; i < command.length(); ++i)
                    {
                        regIndex = (regIndex << 4) | hex::fromHex(command[i]);
                    }
                }
                auto f = plugin_core_->getStruct()->findName(arch_->getGDBCore().mapRegister(regIndex));
                if (!f)
                {
                    answer = "EFF";
                    etiss::log(etiss::ERROR, "5: Faulty implementation of the GDBCore: Register not found",
                               arch_->getGDBCore().mapRegister(regIndex), *plugin_core_);
                    break;
                }
                switch (f->width_)
                {
                case 1:
                    hex::fromInt(answer, (uint8_t)f->read(), arch_->getGDBCore().isLittleEndian());
                    break;
                case 2:
                    hex::fromInt(answer, (uint16_t)f->read(), arch_->getGDBCore().isLittleEndian());
                    break;
                case 4:
                    hex::fromInt(answer, (uint32_t)f->read(), arch_->getGDBCore().isLittleEndian());
                    break;
                case 8:
                    hex::fromInt(answer, (uint64_t)f->read(), arch_->getGDBCore().isLittleEndian());
                    break;
                default:
                    answer = "EFF";
                    etiss::log(etiss::ERROR, "GDB p: Invalid read length");
                }
            }
            break;
            case 'm': // read memory
            {
                unsigned pos = 1;
                etiss::uint64 addr = hex::tryInt<etiss::uint64>(command, pos);
                pos++;
                etiss::uint32 length = hex::tryInt<etiss::uint32>(command, pos);
                etiss::uint8 *buf = new etiss::uint8[length];
                etiss::int32 exception = (*system_->dbg_read)(system_->handle, addr, buf, length);
                if (exception != RETURNCODE::NOERROR)
                {
                    answer = "EFF";
                }
                else
                {
                    answer = hex::fromBytes(buf, length);
                }
                delete[] buf;
            }
            break;
            case 'M': // writes memory
            {
                unsigned pos = 1;
                etiss::uint64 addr = hex::tryInt<etiss::uint64>(command, pos);
                pos++; // comma
                etiss::uint32 length = hex::tryInt<etiss::uint32>(command, pos);
                pos++; // colon
                std::vector<etiss::uint8> buf(length);
                for (etiss::uint32 i = 0; i < length; i++)
                {
                    buf[i] = hex::tryInt<etiss::uint8>(command, pos);
                }
                etiss::int32 exception = (*system_->dbg_write)(system_->handle, addr, buf.data(), length);
                if (exception != RETURNCODE::NOERROR)
                {
                    answer = "EFF";
                }
                else
                {
                    answer = "OK";
                }
            }
            break;
            case 'c': // continue
            {
                if (command.length() > 1)
                {
                    etiss::uint64 addr = 0;
                    for (size_t i = 1; i < command.length(); i += 2)
                    {
                        addr = (addr << 8) | hex::toByte(command[i], command[i + 1]);
                    }
                    status_jumpaddr_ = addr;
                    status_pending_jump_ = true;
                }
                status_paused_ = false;
                gdb_status_paused_ = false;
                status_step_ = 0;
                std::cout << "GDB: command: " << command << std::endl;
                return;
            }
            break;
            case 's':
            {
                if (command.length() > 1)
                {
                    etiss::uint64 addr = 0;
                    for (size_t i = 1; i < command.length(); i += 2)
                    {
                        addr = (addr << 8) | hex::toByte(command[i], command[i + 1]);
                    }
                    status_jumpaddr_ = addr;
                    status_pending_jump_ = true;
                }
                status_paused_ = false;
                gdb_status_paused_ = false;
                status_step_ = 1;
                std::cout << "GDB: command: " << command << std::endl;
                return;
            }
            case '?':
            {
                answer = "T";
                hex::fromByte(answer, 5);
            }
            break;
            case 'v':
                break;
            case 'W': // custom break message; might be changed in future if W is used (apply changes also to
                      // Connection::BREAKMESSAGE)
            {
                status_paused_ = true;
                return;
            }
            break;
            case 'Z': // insert breakpoint
            {
                if (command.length() > 2 && command[2] == ',')
                {
                    BreakpointDB *bpDB = nullptr;
                    etiss::uint32 requestedFlags = 0;
                    switch (command[1])
                    {
                    case '0':
                        bpDB = &breakpoints_;
                        requestedFlags = BreakpointDB::BPTYPE_BREAK_MEM;
                        break;
                    case '1':
                        bpDB = &breakpoints_;
                        requestedFlags = BreakpointDB::BPTYPE_BREAK_HW;
                        break;
                    case '2':
                        bpDB = &watchpoints_;
                        requestedFlags = BreakpointDB::BPTYPE_WATCH_WRITE;
                        break;
                    case '3':
                        bpDB = &watchpoints_;
                        requestedFlags = BreakpointDB::BPTYPE_WATCH_READ;
                        break;
                    case '4':
                        bpDB = &watchpoints_;
                        requestedFlags = BreakpointDB::BPTYPE_WATCH_READ | BreakpointDB::BPTYPE_WATCH_WRITE;
                        break;
                    }
                    if (bpDB)
                    {
                        unsigned pos = 3;
                        etiss::uint64 addr = hex::tryInt<etiss::uint64>(command, pos);
                        if (pos > 3)
                        {
                            if (bpDB == &breakpoints_)
                            {
                                addr = addr >> minimal_pc_alignment;
                            }
                            etiss::uint32 existingFlags = bpDB->get(addr);
                            if ((existingFlags & requestedFlags) != requestedFlags)
                            {
                                bpDB->set(addr, existingFlags | requestedFlags);
                            }
                            answer = "OK";
                        }
                        else
                        {
                            answer = "EFF";
                        }
                    }
                }
            }
            break;
            case 'z': // remove breakpoint
            {
                if (command.length() > 2 && command[2] == ',')
                {
                    BreakpointDB *bpDB = nullptr;
                    etiss::uint32 flagsToDelete = 0;
                    switch (command[1])
                    {
                    case '0':
                        bpDB = &breakpoints_;
                        flagsToDelete = BreakpointDB::BPTYPE_BREAK_MEM;
                        break;
                    case '1':
                        bpDB = &breakpoints_;
                        flagsToDelete = BreakpointDB::BPTYPE_BREAK_HW;
                        break;
                    case '2':
                        bpDB = &watchpoints_;
                        flagsToDelete = BreakpointDB::BPTYPE_WATCH_WRITE;
                        break;
                    case '3':
                        bpDB = &watchpoints_;
                        flagsToDelete = BreakpointDB::BPTYPE_WATCH_READ;
                        break;
                    case '4':
                        bpDB = &watchpoints_;
                        flagsToDelete = BreakpointDB::BPTYPE_WATCH_READ | BreakpointDB::BPTYPE_WATCH_WRITE;
                        break;
                    }

                    if (bpDB)
                    {
                        unsigned pos = 3;
                        etiss::uint64 addr = hex::tryInt<etiss::uint64>(command, pos);
                        addr = addr >> minimal_pc_alignment;
                        if (pos > 3)
                        {
                            etiss::uint32 existingFlags = bpDB->get(addr);
                            if ((existingFlags & flagsToDelete) != 0)
                            {
                                bpDB->set(addr, existingFlags & ~flagsToDelete);
                            }
                            answer = "OK";
                        }
                        else
                        {
                            answer = "EFF";
                        }
                    }
                }
            }
            break;
            case 'q':
            {
                if (command.substr(1, 9) == "Supported")
                {
                    // answer = "";
                    // answer = "PacketSize=800";
                    // answer = "PacketSize=8000;qXfer:features:read+;qXfer:auxv:read+;qXfer:exec-file:read+;multiprocess+";
                    answer = "PacketSize=8000;qXfer:features:read+;";
                }
                else if (command.substr(1, 8) == "Attached")
                {
                    answer = "0";
                }
                else if (command.substr(1, 8) == "Symbol::")
                {
                    answer = "OK";
                }
                else if (command.substr(1, 1) == "C")
                {
                    answer = "0";
                }
                else if (command.substr(1, 7) == "TStatus")
                {
                    answer = "T0;tnotrun:0";
                }
                else if (command.substr(1, 11) == "fThreadInfo")
                {
                    answer = "m1";
                }
                else if (command.substr(1, 11) == "sThreadInfo")
                {
                    answer = "l";
                }
                else if (command.substr(1, 4) == "Xfer")
                {
                    std::cout << "TRIGGER" << std::endl;
                    std::string temp =
"<?xml version=\"1.0\"?>"
"<!DOCTYPE target SYSTEM \"gdb-target.dtd\">"
"<target>"
"  <architecture>riscv</architecture>"
"<feature name=\"org.gnu.gdb.riscv.cpu\">"
"  <reg name=\"zero\" bitsize=\"32\" type=\"int\" regnum=\"0\"/>"
"  <reg name=\"ra\" bitsize=\"32\" type=\"code_ptr\"/>"
"  <reg name=\"sp\" bitsize=\"32\" type=\"data_ptr\"/>"
"  <reg name=\"gp\" bitsize=\"32\" type=\"data_ptr\"/>"
"  <reg name=\"tp\" bitsize=\"32\" type=\"data_ptr\"/>"
"  <reg name=\"t0\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"t1\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"t2\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"fp\" bitsize=\"32\" type=\"data_ptr\"/>"
"  <reg name=\"s1\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"a0\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"a1\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"a2\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"a3\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"a4\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"a5\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"a6\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"a7\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"s2\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"s3\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"s4\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"s5\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"s6\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"s7\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"s8\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"s9\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"s10\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"s11\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"t3\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"t4\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"t5\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"t6\" bitsize=\"32\" type=\"int\"/>"
"  <reg name=\"pc\" bitsize=\"32\" type=\"code_ptr\"/>"
"</feature>"
// "<feature name=\"org.gnu.gdb.riscv.fpu\">"
// "  <reg name=\"ft0\" bitsize=\"32\" type=\"ieee_single\" regnum=\"33\"/>"
// "  <reg name=\"ft1\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"ft2\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"ft3\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"ft4\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"ft5\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"ft6\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"ft7\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"fs0\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"fs1\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"fa0\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"fa1\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"fa2\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"fa3\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"fa4\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"fa5\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"fa6\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"fa7\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"fs2\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"fs3\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"fs4\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"fs5\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"fs6\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"fs7\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"fs8\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"fs9\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"fs10\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"fs11\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"ft8\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"ft9\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"ft10\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"ft11\" bitsize=\"32\" type=\"ieee_single\"/>"
// "  <reg name=\"fcsr\" bitsize=\"32\" type=\"int\" regnum=\"68\"/>"
// "</feature>"
"<feature name=\"org.gnu.gdb.riscv.fpu\">"
"  <union id=\"riscv_double\">"
"    <field name=\"float\" type=\"ieee_single\"/>"
"    <field name=\"double\" type=\"ieee_double\"/>"
"  </union>"
"  <reg name=\"ft0\" bitsize=\"64\" type=\"riscv_double\" regnum=\"33\"/>"
"  <reg name=\"ft1\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"ft2\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"ft3\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"ft4\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"ft5\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"ft6\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"ft7\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"fs0\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"fs1\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"fa0\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"fa1\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"fa2\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"fa3\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"fa4\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"fa5\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"fa6\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"fa7\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"fs2\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"fs3\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"fs4\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"fs5\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"fs6\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"fs7\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"fs8\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"fs9\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"fs10\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"fs11\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"ft8\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"ft9\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"ft10\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"ft11\" bitsize=\"64\" type=\"riscv_double\"/>"
"  <reg name=\"fflags\" bitsize=\"32\" type=\"int\" regnum=\"66\"/>"
"  <reg name=\"frm\" bitsize=\"32\" type=\"int\" regnum=\"67\"/>"
"  <reg name=\"fcsr\" bitsize=\"32\" type=\"int\" regnum=\"68\"/>"
"</feature>"
"  <feature name=\"org.gnu.gdb.riscv.csr\">"
"    <reg name=\"cycle\" bitsize=\"32\" regnum=\"1000\"/>"
"    <reg name=\"cycleh\" bitsize=\"32\" regnum=\"1001\"/>"
"    <reg name=\"time\" bitsize=\"32\" regnum=\"1002\"/>"
"    <reg name=\"timeh\" bitsize=\"32\" regnum=\"1003\"/>"
"    <reg name=\"instret\" bitsize=\"32\" regnum=\"1004\"/>"
"    <reg name=\"instreth\" bitsize=\"32\" regnum=\"1005\"/>"
"    <reg name=\"mvendorid\" bitsize=\"32\" regnum=\"1006\"/>"
"    <reg name=\"marchid\" bitsize=\"32\" regnum=\"1007\"/>"
"    <reg name=\"mimpid\" bitsize=\"32\" regnum=\"1008\"/>"
"    <reg name=\"mhartid\" bitsize=\"32\" regnum=\"1009\"/>"
"    <reg name=\"mstatus\" bitsize=\"32\" regnum=\"1010\"/>"
"    <reg name=\"misa\" bitsize=\"32\" regnum=\"1011\"/>"
"    <reg name=\"medeleg\" bitsize=\"32\" regnum=\"1012\"/>"
"    <reg name=\"mideleg\" bitsize=\"32\" regnum=\"1013\"/>"
"    <reg name=\"mie\" bitsize=\"32\" regnum=\"1014\"/>"
"    <reg name=\"mtvec\" bitsize=\"32\" regnum=\"1015\"/>"
"    <reg name=\"mcounteren\" bitsize=\"32\" regnum=\"1016\"/>"
"    <reg name=\"mscratch\" bitsize=\"32\" regnum=\"1017\"/>"
"    <reg name=\"mepc\" bitsize=\"32\" regnum=\"1018\"/>"
"    <reg name=\"mcause\" bitsize=\"32\" regnum=\"1019\"/>"
"    <reg name=\"mtval\" bitsize=\"32\" regnum=\"1020\"/>"
"    <reg name=\"mip\" bitsize=\"32\" regnum=\"1021\"/>"

"    <reg name=\"vstart\" bitsize=\"32\" regnum=\"2032\" type=\"int\" group=\"vector\"/>"
"    <reg name=\"vxsat\" bitsize=\"32\" regnum=\"2033\" type=\"int\" group=\"vector\"/>"
"    <reg name=\"vxrm\" bitsize=\"32\" regnum=\"2034\" type=\"int\" group=\"vector\"/>"
"    <reg name=\"vcsr\" bitsize=\"32\" regnum=\"2035\" type=\"int\" group=\"vector\"/>"
"    <reg name=\"vl\" bitsize=\"32\" regnum=\"2036\" type=\"int\" group=\"vector\"/>"
"    <reg name=\"vtype\" bitsize=\"32\" regnum=\"2037\" type=\"int\" group=\"vector\"/>"
"    <reg name=\"vlenb\" bitsize=\"32\" regnum=\"2038\" type=\"int\" group=\"vector\"/>"

"  </feature>"
"  <feature name=\"org.gnu.gdb.riscv.vector\">"
"    <vector id=\"bytes\" type=\"uint8\" count=\"16\"/>"
"    <vector id=\"shorts\" type=\"uint16\" count=\"8\"/>"
"    <vector id=\"words\" type=\"uint32\" count=\"4\"/>"
"    <vector id=\"longs\" type=\"uint64\" count=\"2\"/>"
"    <vector id=\"quads\" type=\"uint128\" count=\"1\"/>"
"    <union id=\"riscv_vector\">"
"      <field name=\"b\" type=\"bytes\"/>"
"      <field name=\"s\" type=\"shorts\"/>"
"      <field name=\"w\" type=\"words\"/>"
"      <field name=\"l\" type=\"longs\"/>"
"      <field name=\"q\" type=\"quads\"/>"
"    </union>"
"    <reg name=\"v0\" bitsize=\"128\" regnum=\"2000\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v1\" bitsize=\"128\" regnum=\"2001\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v2\" bitsize=\"128\" regnum=\"2002\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v3\" bitsize=\"128\" regnum=\"2003\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v4\" bitsize=\"128\" regnum=\"2004\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v5\" bitsize=\"128\" regnum=\"2005\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v6\" bitsize=\"128\" regnum=\"2006\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v7\" bitsize=\"128\" regnum=\"2007\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v8\" bitsize=\"128\" regnum=\"2008\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v9\" bitsize=\"128\" regnum=\"2009\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v10\" bitsize=\"128\" regnum=\"2010\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v11\" bitsize=\"128\" regnum=\"2011\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v12\" bitsize=\"128\" regnum=\"2012\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v13\" bitsize=\"128\" regnum=\"2013\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v14\" bitsize=\"128\" regnum=\"2014\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v15\" bitsize=\"128\" regnum=\"2015\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v16\" bitsize=\"128\" regnum=\"2016\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v17\" bitsize=\"128\" regnum=\"2017\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v18\" bitsize=\"128\" regnum=\"2018\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v19\" bitsize=\"128\" regnum=\"2019\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v20\" bitsize=\"128\" regnum=\"2020\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v21\" bitsize=\"128\" regnum=\"2021\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v22\" bitsize=\"128\" regnum=\"2022\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v23\" bitsize=\"128\" regnum=\"2023\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v24\" bitsize=\"128\" regnum=\"2024\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v25\" bitsize=\"128\" regnum=\"2025\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v26\" bitsize=\"128\" regnum=\"2026\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v27\" bitsize=\"128\" regnum=\"2027\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v28\" bitsize=\"128\" regnum=\"2028\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v29\" bitsize=\"128\" regnum=\"2029\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v30\" bitsize=\"128\" regnum=\"2030\" type=\"riscv_vector\" group=\"vector\"/>"
"    <reg name=\"v31\" bitsize=\"128\" regnum=\"2031\" type=\"riscv_vector\" group=\"vector\"/>"
"  </feature>"
"</target>";
                    uint32_t target_reqxml_addr;
                    uint32_t target_reqxml_len;
                    uint32_t xml_len = temp.length();
                    sscanf(command.c_str(), "qXfer:features:read:target.xml:%x,%x", &target_reqxml_addr, &target_reqxml_len);
                    std::cout << "addr=" << target_reqxml_addr << std::endl;
                    std::cout << "len=" << target_reqxml_len << std::endl;
                    std::cout << "xml_len=" << xml_len << std::endl;
                    if (target_reqxml_len >= (xml_len - target_reqxml_addr)) {
                        answer = "l";
                        answer += temp.substr(target_reqxml_addr, xml_len - target_reqxml_addr);
                    } else {
                        answer = "m";
                        answer += temp.substr(target_reqxml_addr, target_reqxml_len);
                    }
/*
<?xml version=\"1.0\"?>
<!DOCTYPE target SYSTEM \"gdb-target.dtd\">
<target version=\"1.0\">
  <architecture>riscv:rv32</architecture>
  <feature name=\"org.gnu.gdb.riscv.csr\">
    <reg name=\"csr100\" bitsize=\"32\" regnum=\"110"\">
  </feature>

  <feature name=\"org.gnu.gdb.riscv.vector\">
    <vector id=\"bytes\" type=\"uint8\" count=\"16\"/>
    <vector id=\"shorts\" type=\"uint16\" count=\"8\"/>
    <vector id=\"words\" type=\"uint32\" count=\"4\"/>
    <vector id=\"longs\" type=\"uint64\" count=\"2\"/>
    <vector id=\"quads\" type=\"uint128\" count=\"1\"/>
    <union id=\"riscv_vector\">
      <field name=\"b\" type=\"bytes\"/>
      <field name=\"s\" type=\"shorts\"/>
      <field name=\"w\" type=\"words\"/>
      <field name=\"l\" type=\"longs\"/>
      <field name=\"q\" type=\"quads\"/>
    </union>

    <reg name=\"v0\" bitsize=\"128\" regnum=\"2000\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v1\" bitsize=\"128\" regnum=\"2001\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v2\" bitsize=\"128\" regnum=\"2002\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v3\" bitsize=\"128\" regnum=\"2003\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v4\" bitsize=\"128\" regnum=\"2004\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v5\" bitsize=\"128\" regnum=\"2005\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v6\" bitsize=\"128\" regnum=\"2006\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v7\" bitsize=\"128\" regnum=\"2007\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v8\" bitsize=\"128\" regnum=\"2008\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v9\" bitsize=\"128\" regnum=\"2009\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v10\" bitsize=\"128\" regnum=\"2010\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v11\" bitsize=\"128\" regnum=\"2011\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v12\" bitsize=\"128\" regnum=\"2012\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v13\" bitsize=\"128\" regnum=\"2013\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v14\" bitsize=\"128\" regnum=\"2014\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v15\" bitsize=\"128\" regnum=\"2015\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v16\" bitsize=\"128\" regnum=\"2016\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v17\" bitsize=\"128\" regnum=\"2017\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v18\" bitsize=\"128\" regnum=\"2018\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v19\" bitsize=\"128\" regnum=\"2019\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v20\" bitsize=\"128\" regnum=\"2020\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v21\" bitsize=\"128\" regnum=\"2021\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v22\" bitsize=\"128\" regnum=\"2022\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v23\" bitsize=\"128\" regnum=\"2023\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v24\" bitsize=\"128\" regnum=\"2024\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v25\" bitsize=\"128\" regnum=\"2025\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v26\" bitsize=\"128\" regnum=\"2026\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v27\" bitsize=\"128\" regnum=\"2027\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v28\" bitsize=\"128\" regnum=\"2028\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v29\" bitsize=\"128\" regnum=\"2029\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v30\" bitsize=\"128\" regnum=\"2030\" type=\"riscv_vector\" group=\"vector\"/>
    <reg name=\"v31\" bitsize=\"128\" regnum=\"2031\" type=\"riscv_vector\" group=\"vector\"/>


    <reg name=\"vstart\" bitsize=\"32\" regnum=\"2032\" type=\"int\" group=\"vector\"/>
    <reg name=\"vxsat\" bitsize=\"32\" regnum=\"2033\" type=\"int\" group=\"vector\"/>
    <reg name=\"vxrm\" bitsize=\"32\" regnum=\"2034\" type=\"int\" group=\"vector\"/>
    <reg name=\"vcsr\" bitsize=\"32\" regnum=\"2035\" type=\"int\" group=\"vector\"/>
    <reg name=\"vl\" bitsize=\"32\" regnum=\"2036\" type=\"int\" group=\"vector\"/>
    <reg name=\"vtype\" bitsize=\"32\" regnum=\"0327\" type=\"int\" group=\"vector\"/>
    <reg name=\"vlenb\" bitsize=\"32\" regnum=\"2038\" type=\"int\" group=\"vector\"/>

  </feature>
</target>
*/
                }
            }
            break;
            case 'k':
            {
                status_pending_kill_ = true;
                return;
            }
            break;
            case 'H':
                if (command.length() > 1)
                {
                    switch (command[1])
                    {
                    case 'c':
                    case 'g':
                        answer = "OK"; // only one thread. ignore thread selection and continue
                        break;
                    default:
                        std::cout << "GDB: unknown command: " << command << std::endl;
                    }
                }
                else
                {
                    std::cout << "GDB: unknown command: " << command << std::endl;
                }
                break;
            default:
                std::cout << "GDB: unknown command: " << command << std::endl;
                break;
            }
            std::cout << "GDB: command: " << command << std::endl;
            std::cout << "GDB: answer: "<<answer << std::endl;
            if (!nodbgaction)
            {
            }
            con_.snd(answer, answerisnotification);
        }
    }
}

void Server::preDReadCallback(etiss::uint64 addr)
{
    if (!watchpoints_.isEmpty())
    {
        if (watchpoints_.get(addr) & BreakpointDB::BPTYPE_WATCH_READ)
        {
            status_paused_ = true;
        }
    }
}
void Server::preDWriteCallback(etiss::uint64 addr)
{
    if (!watchpoints_.isEmpty())
    {
        if (watchpoints_.get(addr) & BreakpointDB::BPTYPE_WATCH_WRITE)
        {
            status_paused_ = true;
        }
    }
}

etiss::int32 Server::postMemAccessCallback(etiss::int32 exception)
{
    if (exception)
    {
        status_paused_ = true;
    }

    if (status_paused_)
    {
        if (!gdb_status_paused_)
        {
            con_.snd("T" + hex::fromByte(5), false);
            gdb_status_paused_ = true;
        }

        while (unlikely(status_paused_))
        {
            handlePacket(true);
            if (unlikely(status_pending_kill_))
            {
                return RETURNCODE::CPUTERMINATED;
            }
            if (status_pending_jump_)
            {
                cpu_->instructionPointer = status_jumpaddr_;
                status_pending_jump_ = false;
                exception = RETURNCODE::NOERROR;
            }
        }
    }

    return exception;
}

std::string Server::_getPluginName() const
{
    return "gdbserver";
}

void *Server::getPluginHandle()
{
    return (void *)this;
}

void Server::init(ETISS_CPU *cpu, ETISS_System *system, etiss::CPUArch *arch)
{
    arch_ = arch;
    cpu_ = cpu;
    system_ = system;
}

void Server::cleanup()
{
    arch_ = nullptr;
    cpu_ = nullptr;
    system_ = nullptr;
}

Server *Server::createTCPServer(std::map<std::string, std::string> options)
{
    int port = 2222;

    { // parse port
        auto f = options.find("plugin.gdbserver.port");
        if (f != options.end())
        {
            int tmp = atoi(f->second.c_str());
            if (tmp > 0)
                port = tmp;
            else
                etiss::log(etiss::ERROR,
                           std::string("etiss::plugin::gdb::Server: failed to parse port value for tcp socket: ") +
                               f->second);
        }
    }

    Server *s = createTCPServer(port);

    { // parse skip count
        auto f = options.find("skipcount");
        if (f != options.end())
        {
            int tmp = atoi(f->second.c_str());
            if (tmp >= 0)
                s->execute_skip_count = tmp;
        }
    }

    { // parse Minimal pc alignment

        auto f = options.find("minPcAlign");
        if (f != options.end())
        {
            int tmp = atoi(f->second.c_str());
            if (tmp >= 0)
                s->minimal_pc_alignment = tmp;
        }
    }
    return s;
}
Server *Server::createTCPServer(int port)
{

#if ETISS_USE_POSIX_SOCKET
    etiss::log(etiss::VERBOSE,
               std::string("etiss::plugin::gdb::Server: starting tcp server on port ") + etiss::toString(port));

    std::shared_ptr<Connection> cs(new etiss::plugin::gdb::UnixTCPGDBConnection(port));

    Server *s = new Server(cs.get()->getPacketProtocol());

    s->cinst_ = cs;

    return s;
#else

    return 0;

#endif
}

extern "C"
{
    etiss_int32 gdb_pre_instruction(ETISS_CPU *cpu, ETISS_System *system, void *gdbserver)
    {
        return ((etiss::plugin::gdb::Server *)gdbserver)->preInstructionCallback();
    }
    void gdb_pre_instruction_noreturn(ETISS_CPU *, ETISS_System *, void *gdbserver)
    {
        /// @todo fix possible exception loss
        ((etiss::plugin::gdb::Server *)gdbserver)->preInstructionCallback();
    }
}
