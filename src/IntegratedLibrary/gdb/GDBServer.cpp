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

Server::~Server() {}

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
            // std::cout << "GDB: answer: " << "T"<<hex::fromByte(5) << std::endl;
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

void Server::process(etiss::CodeBlock &block, unsigned index)
{

    // add gdb callback code at the start of single instructions and at the start of meta instructions (NOT in between
    // parts of meta instructions)
    bool wasmeta = false;
    for (unsigned i = 0; i < block.length(); i++)
    {
        if (!wasmeta)
        { // may return
            CodeSet &cs = block.get(i).getCodeSet();
            CodePart &part = cs.append(CodePart::PREINITIALDEBUGRETURNING);
            std::stringstream ss;
            ss << "{\n";
            ss << "\tetiss_int32 _gdb_exception = gdb_pre_instruction(cpu,system,plugin_pointers[" << index << "]);\n";
            ss << "\tif (_gdb_exception != 0)\n\t return _gdb_exception==-16?0:_gdb_exception;";
            ss << "}";
            part.getCode() = ss.str();
        }
        else
        {
            CodeSet &cs = block.get(i).getCodeSet();
            CodePart &part = cs.prepend(CodePart::INITIALREQUIRED);
            std::stringstream ss;
            ss << "{\n";
            ss << "\tgdb_pre_instruction_noreturn(cpu,system,plugin_pointers[" << index << "]);\n";
            ss << "}";
            part.getCode() = ss.str();
        }
        // wasmeta = block.get(i).isMetaInstruction();
    }

    // add file global code
    block.fileglobalCode().insert("extern etiss_int32 gdb_pre_instruction(ETISS_CPU * ,ETISS_System * ,void * );extern "
                                  "void gdb_pre_instruction_noreturn(ETISS_CPU * ,ETISS_System * ,void * );");
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
        if (command.length() > 0)
        {
            if (!status_paused_)
            {
                if (!gdb_status_paused_)
                { // answer pending 'c'/'s' command
                    // std::cout << "GDB: answer: " << "T"<<hex::fromByte(5) << std::endl;
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
                for (unsigned i = 0; i < arch_->getGDBCore().mappedRegisterCount(); i++)
                {
                    std::string regname = arch_->getGDBCore().mapRegister(i);
                    auto f = plugin_core_->getStruct()->findName(regname);
                    if (!f)
                    {
                        answer = "EFF";
                        etiss::log(etiss::ERROR, "Faulty implementation of the GDBCore: Register not found", regname,
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
                        etiss::log(etiss::ERROR, "Faulty implementation of the GDBCore: Register not found",
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
                            etiss::log(etiss::ERROR, "Faulty implementation of the GDBCore: Register not found",
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
                    etiss::log(etiss::ERROR, "Faulty implementation of the GDBCore: Register not found",
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
                    etiss::log(etiss::ERROR, "Faulty implementation of the GDBCore: Register not found",
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
                // std::cout << "GDB: command: " << command << std::endl;
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
                // std::cout << "GDB: command: " << command << std::endl;
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
                    answer = "";
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
                    // std::cout << "GDB: unknown command: " << command << std::endl;
                }
                break;
            default:
                std::cout << "GDB: unknown command: " << command << std::endl;
                break;
            }
            if (!nodbgaction)
            {
                // std::cout << "GDB: command: " << command << std::endl;
                // std::cout << "GDB: answer: "<<answer << std::endl;
            }
            con_.snd(answer, answerisnotification);
        }
    }
}

etiss::int32 Server::preMemoryAccessCallback(etiss::uint64 addr, etiss::uint32 len, bool data, bool read)
{
    etiss::int32 exception = 0;
    uint64_t buf = 0;
    if (read)
    {
        if (!watchpoints_.isEmpty())
        {
            if (watchpoints_.get(addr) & BreakpointDB::BPTYPE_WATCH_READ)
            {
                status_paused_ = true;
            }
        }
        if (data)
        {
            exception = unwrappedSys_->dread(unwrappedSys_->handle, cpu_, addr, (etiss::uint8*)&buf, len);
        }
        else
        {
            exception = unwrappedSys_->iread(unwrappedSys_->handle, cpu_, addr, len);
        }
    }
    else
    {
        if (!watchpoints_.isEmpty())
        {
            if (watchpoints_.get(addr) & BreakpointDB::BPTYPE_WATCH_WRITE)
            {
                status_paused_ = true;
            }
        }
        if (data)
        {
            exception = unwrappedSys_->dwrite(unwrappedSys_->handle, cpu_, addr, (etiss::uint8*)&buf, len);
        }
        else
        {
            exception = unwrappedSys_->iwrite(unwrappedSys_->handle, cpu_, addr, (etiss::uint8*)&buf, len);
        }
    }
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
            }
        }
    }
    return RETURNCODE::NOERROR;
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
        auto f = options.find("port");
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
