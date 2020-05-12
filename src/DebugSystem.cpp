/**

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

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

        @author Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM

        @date July 29, 2014

        @version 0.1

*/
/**
        @file

        @brief implementation of etiss/DebugSystem.h

        @detail

*/

#include "etiss/DebugSystem.h"
#include "etiss/CPUArch.h"
#include "etiss/Misc.h"
#include <cstring>
#include <iostream>
#include <unordered_map>
#define ARMv6M_DEBUG_PRINT 0

using namespace etiss;

std::unordered_map<std::string, uint32_t> map_messageCounter;
uint32_t printMessage(std::string key, std::string message, uint32_t maxCount)
{
    uint32_t count = map_messageCounter[key]++;
    if (count < maxCount) // print only the first X messages of this type
        std::cout << message << "  (" << (count + 1) << "x)" << std::endl;
    return count;
}

DebugSystem::DebugSystem(uint32_t rom_start, uint32_t rom_size, uint32_t ram_start, uint32_t ram_size)
    : _rom_start(rom_start), _ram_start(ram_start)
{
    // mem = new etiss::uint8[DEBUGSYSTEM_MEMBLOCKSIZE*2];
    rom_mem.resize(rom_size, 0);
    ram_mem.resize(ram_size, 0);
    _print_ibus_access = etiss::cfg().get<bool>("DebugSystem::printIbusAccess", false);
    _print_dbus_access = etiss::cfg().get<bool>("DebugSystem::printDbusAccess", false);
    _print_dbgbus_access = etiss::cfg().get<bool>("DebugSystem::printDbgbusAccess", false);
    _print_to_file = etiss::cfg().get<bool>("DebugSystem::printToFile", false);
    message_max_cnt = etiss::cfg().get<int>("DebugSystem::message_max_cnt", 100);

    if (_print_dbus_access)
    {
        trace_file_dbus_.open(etiss::cfg().get<std::string>("ETISS::outputPathPrefix", "") + "dBusAccess.csv",
                              std::ios::binary);
    }
}

etiss::int32 DebugSystem::iread(ETISS_CPU *, etiss::uint64 addr, etiss::uint32 len)
{
    return RETURNCODE::NOERROR;
}
etiss::int32 DebugSystem::iwrite(ETISS_CPU *, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len)
{
    etiss::log(etiss::VERBOSE, "Blocked instruction write ");
    return RETURNCODE::IBUS_WRITE_ERROR;
}
static void Trace(etiss::uint64 addr, etiss::uint32 len, bool isWrite, bool toFile, std::ofstream &file)
{
    std::stringstream text;
    text << "0"                                                   // time
         << (isWrite ? ";w;" : ";r;")                             // type
         << std::setw(8) << std::setfill('0') << std::hex << addr // addr
         << ";" << len << std::endl;

    if (toFile)
        file << text.str();
    else
        std::cout << text.str();
}
etiss::int32 DebugSystem::dread(ETISS_CPU *, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len)
{
    if (len > 0)
    {
        // if (addr >= DEBUGSYSTEM_MEMBLOCKSIZE * 2 ||
        //     addr + len > DEBUGSYSTEM_MEMBLOCKSIZE * 2) {
        //   std::stringstream message;
        //   message << "Failed to read data: 0x";
        //   for (int i = 0; i < len; i++) {
        //     message << std::setfill('0') << std::setw(2) << std::hex <<
        //     (int)buf[i];
        //   }
        //   message << std::setfill(' ') << " from " << addr << "-" << addr + len -
        //   1
        //           << std::dec << std::endl;
        //   printMessage("data read error", message.str(), message_max_cnt);
        //   memset(buf, 0, len);
        //   return RETURNCODE::IBUS_READ_ERROR;
        // }
        //
        // memcpy(buf, mem + addr, len);

        if (addr >= _rom_start && addr < _rom_start + rom_mem.size())
        {
            addr -= _rom_start;
            memcpy(buf, rom_mem.data() + addr, len);
        }
        else if (addr >= _ram_start && addr < _ram_start + ram_mem.size())
        {
            addr -= _ram_start;
            memcpy(buf, ram_mem.data() + addr, len);

            if (_print_dbus_access)
            {
                Trace(addr, len, false, _print_to_file, trace_file_dbus_);
            }
        }
        else
        {
            std::cout << std::hex << addr << std::dec << std::endl;
            etiss::log(etiss::FATALERROR, "wrong address issued in DebugSystem::dread\n");
        }
    }
#if ARMv6M_DEBUG_PRINT
    else
    {
        // std::cout << "debug print: " << std::hex << addr << std::endl;
    }
#endif
    return RETURNCODE::NOERROR;
}
etiss::int32 DebugSystem::dwrite(ETISS_CPU *, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len)
{
    // if (addr >= DEBUGSYSTEM_MEMBLOCKSIZE * 2 ||
    //     addr + len > DEBUGSYSTEM_MEMBLOCKSIZE * 2) {
    //   std::stringstream message;
    //   message << "Failed to write data:0x";
    //   for (int i = 0; i < len; i++) {
    //     message << std::setfill('0') << std::setw(2) << std::hex <<
    //     (int)buf[i];
    //   }
    //   message << std::setfill(' ') << " to " << addr << "-" << addr + len - 1
    //           << std::dec << std::endl;
    //   printMessage("data write error", message.str(), message_max_cnt);
    //   return RETURNCODE::DBUS_WRITE_ERROR;
    // }
    // if ((addr > _rom_start && addr < _rom_end) ||
    //     (addr + len > _rom_start && addr + len < _rom_end)) {
    //   std::stringstream message;
    //   message << "Denied ROM write access!";
    //   for (int i = 0; i < len; i++) {
    //     message << std::setfill('0') << std::setw(2) << std::hex <<
    //     (int)buf[i];
    //   }
    //   message << std::setfill(' ') << " to " << addr << "-" << addr + len - 1
    //           << std::dec << std::endl;
    //   printMessage("data write error", message.str(), message_max_cnt);
    //   return RETURNCODE::NOERROR;
    // }

    if (addr >= _ram_start && addr < _ram_start + ram_mem.size())
    {
        addr -= _ram_start;
        memcpy(ram_mem.data() + addr, buf, len);

        if (_print_dbus_access)
        {
            Trace(addr, len, true, _print_to_file, trace_file_dbus_);
        }
    }
    else
    {
        std::cout << std::hex << addr << std::dec << std::endl;
        etiss::log(etiss::FATALERROR, "wrong address issued in DebugSystem::dwrite\n");
    }
    return RETURNCODE::NOERROR;
}
etiss::int32 DebugSystem::dbg_read(etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len)
{
    // if (addr >= DEBUGSYSTEM_MEMBLOCKSIZE * 2 ||
    //     addr + len > DEBUGSYSTEM_MEMBLOCKSIZE * 2) {
    //   std::stringstream message;
    //   message << "Failed to read debug data from 0x" << std::hex << addr << "-"
    //           << addr + len - 1 << std::dec << std::endl;
    //   printMessage("instr read error", message.str(), message_max_cnt);
    //   memset(buf, 0, len);
    //   return RETURNCODE::IBUS_READ_ERROR;
    // }
    //
    // memcpy(buf, mem + addr, len);
    //
    // if (_print_dbgbus_access) {
    //   std::stringstream text;
    //   text << "read dbg:0x";
    //   for (int i = 0; i < len; i++) {
    //     text << std::setfill('0') << std::setw(2) << std::hex << (int)buf[i];
    //   }
    //   text << std::setfill(' ') << " to " << addr << "-" << addr + len - 1
    //        << std::dec << std::endl;
    //
    //   if (_print_to_file) {
    //     std::ofstream fout;
    //     fout.open(etiss::cfg().get<std::string>("ETISS::outputPathPrefix", "")
    //     +
    //                   "dbgBusAccess.txt",
    //               std::ios::binary | std::ios::out | std::ios::app);
    //     fout << text.str();
    //   } else
    //     std::cout << text.str();
    // }
    //

    if (_print_dbgbus_access)
    {
        std::cout << "dbg_read: " << std::hex << addr << std::dec << ", len: " << len << std::endl;
    }

    if (addr >= _rom_start && addr < _rom_start + rom_mem.size())
    {
        addr -= _rom_start;
        memcpy(buf, rom_mem.data() + addr, len);
    }
    else if (addr >= _ram_start && addr < _ram_start + ram_mem.size())
    {
        addr -= _ram_start;
        memcpy(buf, ram_mem.data() + addr, len);
    }
    else
    {
        etiss::log(etiss::FATALERROR, "wrong address issued in DebugSystem::dbg_read\n");
    }
    // TODO(sharif) _print_dbus_access, _print_to_file
    return RETURNCODE::NOERROR;
}
etiss::int32 DebugSystem::dbg_write(etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len)
{
    // if (addr >= DEBUGSYSTEM_MEMBLOCKSIZE * 2 ||
    //     addr + len > DEBUGSYSTEM_MEMBLOCKSIZE * 2) {
    //   std::stringstream message;
    //   message << "Failed to write data to 0x" << std::hex << addr << "-"
    //           << addr + len - 1 << std::dec << std::endl;
    //   printMessage("instr write error", message.str(), message_max_cnt);
    //   return RETURNCODE::IBUS_WRITE_ERROR;
    // }
    //
    // memcpy(mem + addr, buf, len);
    //
    // if (_print_dbgbus_access) {
    //   std::stringstream text;
    //   text << "write dbg:0x";
    //   for (int i = 0; i < len; i++) {
    //     text << std::setfill('0') << std::setw(2) << std::hex << (int)buf[i];
    //   }
    //   text << std::setfill(' ') << " to " << addr << "-" << addr + len - 1
    //        << std::dec << std::endl;
    //
    //   if (_print_to_file) {
    //     std::ofstream fout;
    //     fout.open(etiss::cfg().get<std::string>("ETISS::outputPathPrefix", "")
    //     +
    //                   "dbgBusAccess.txt",
    //               std::ios::binary | std::ios::out | std::ios::app);
    //     fout << text.str();
    //   } else
    //     std::cout << text.str();
    // }

    if (_print_dbgbus_access)
    {
        std::cout << "dbg_write: " << std::hex << addr << std::dec << ", len: " << len << std::endl;
    }

    if (addr >= _rom_start && addr < _rom_start + rom_mem.size())
    {
        addr -= _rom_start;
        memcpy(rom_mem.data() + addr, buf, len);
    }
    else if (addr >= _ram_start && addr < _ram_start + ram_mem.size())
    {
        addr -= _ram_start;
        memcpy(ram_mem.data() + addr, buf, len);
    }
    else
    {
        etiss::log(etiss::FATALERROR, "wrong address issued in DebugSystem::dbg_write\n");
    }
    // TODO(sharif) _print_dbus_access, _print_to_file
    return RETURNCODE::NOERROR;
}
/*bool DebugSystem::load(etiss::uint64 addr,const char * file){
        std::ifstream in;
        in.open(file,std::ifstream::binary);

        if (!in.is_open())
        {
            std::cout <<"binary load failed! ("<< *file << ") " << std::endl;
            return false;
        }

        etiss::uint8 byte;
        while (in.good()){
                byte = (etiss::uint8) in.get();
                if (in.good()){
                        if (addr< DEBUGSYSTEM_MEMBLOCKSIZE*2){
                                mem[addr] = byte;
                        } else {
                                std::cout << "ERROR: failed to load data to
debug system memory: invalid address (" << std::hex << addr << std::dec << ")"
<< std::endl; return false;
                        }
                        addr++;
                }
        }
        std::cout <<"binary loaded!"<< std::endl;
        return true;
}*/

bool DebugSystem::loadRom(const char *file)
{
    std::ifstream in;
    in.open(file, std::ifstream::binary);

    if (!in)
    {
        std::cout << "rom binary load failed! (" << *file << ") " << std::endl;
        return false;
    }

    etiss::uint64 addr = 0;
    etiss::uint8 byte;
    while (in.good())
    {
        byte = (etiss::uint8)in.get();
        if (in.good())
        {
            if (addr < rom_mem.size())
            {
                rom_mem[addr] = byte;
            }
            else
            {
                std::cout << "ERROR: failed to load data to debug rom system memory: "
                             "invalid address ("
                          << std::hex << addr << std::dec << ")" << std::endl;
                return false;
            }
            addr++;
        }
    }
    std::cout << "rom binary loaded!" << std::endl;
    return true;
}

bool DebugSystem::loadRam(const char *file)
{
    std::ifstream in;
    in.open(file, std::ifstream::binary);

    if (!in)
    {
        std::cout << "ram binary load failed! (" << *file << ") " << std::endl;
        return false;
    }

    etiss::uint64 addr = 0;
    etiss::uint8 byte;
    while (in.good())
    {
        byte = (etiss::uint8)in.get();
        if (in.good())
        {
            if (addr < ram_mem.size())
            {
                ram_mem[addr] = byte;
            }
            else
            {
                std::cout << "ERROR: failed to load data to debug ram system memory: "
                             "invalid address ("
                          << std::hex << addr << std::dec << ")" << std::endl;
                in.close();
                return false;
            }
            addr++;
        }
    }
    std::cout << "ram binary loaded!" << std::endl;
    return true;
}

extern void global_sync_time(uint64 time_ps);
void DebugSystem::syncTime(ETISS_CPU *cpu)
{
    // std::cout << "CPU time: " << cpu -> cpuTime_ps << "ps" << std::endl;
    // global_sync_time(cpu->cpuTime_ps);
}
// void DebugSystem::swapEndian(unsigned align) {
//   etiss::uint8 buf_[8];
//   etiss::uint8* buf;
//   if (align > 8) {
//     buf = new etiss::uint8[align];
//   } else {
//     buf = buf_;
//   }
//   for (int i = 0; i < DEBUGSYSTEM_MEMBLOCKSIZE * 2; i += align) {
//     etiss::uint8* cur = mem + i;
//     for (unsigned j = 0; j < align; j++) {
//       buf[j] = cur[j];
//     }
//     for (unsigned j = 0; j < align; j++) {
//       cur[align - j - 1] = buf[j];
//     }
//   }
//   if (buf != buf_) delete[] buf;
// }
