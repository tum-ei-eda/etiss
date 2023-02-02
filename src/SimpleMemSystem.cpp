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

        @brief implementation of etiss/SimpleMemSystem.h

        @detail

*/

#include "etiss/SimpleMemSystem.h"
#include "etiss/CPUArch.h"
#include "etiss/Misc.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <unordered_map>

#include "elfio/elfio.hpp"
#include <memory>

#define ARMv6M_DEBUG_PRINT 0
#define MAX_MEMSEGS 99

using namespace etiss;

std::unordered_map<std::string, uint32_t> map_messageCounter;
uint32_t printMessage(std::string key, std::string message, uint32_t maxCount)
{
    uint32_t count = map_messageCounter[key]++;
    if (count < maxCount) // print only the first X messages of this type
        std::cout << message << "  (" << (count + 1) << "x)" << std::endl;
    return count;
}

void SimpleMemSystem::init_memory() {
    load_segments();
    load_elf();
    std::sort(msegs_.begin(), msegs_.end(), [](std::unique_ptr<MemSegment> & a, std::unique_ptr<MemSegment> & b) {return a->start_addr_ < b->start_addr_;});
}

void SimpleMemSystem::load_segments() {
    std::stringstream ss;

    for (int i = 0; i < MAX_MEMSEGS; ++i) {
        ss << "simple_mem_system.memseg_origin_" << std::setw(2) << std::setfill('0') << i;
        uint64_t origin = etiss::cfg().get<uint64_t>(ss.str(), -1);
        std::stringstream().swap(ss);

        ss << "simple_mem_system.memseg_length_" << std::setw(2) << std::setfill('0') << i;
        uint64_t length = etiss::cfg().get<uint64_t>(ss.str(), -1);
        if (length == 0) {
            etiss::log(etiss::FATALERROR, "Empty memsegs are not allowed!");
        }
        std::stringstream().swap(ss);

        ss << "simple_mem_system.memseg_image_" << std::setw(2) << std::setfill('0') << i;
        std::string image = etiss::cfg().get<std::string>(ss.str(), "");
        std::stringstream().swap(ss);

        ss << "simple_mem_system.memseg_mode_" << std::setw(2) << std::setfill('0') << i;
        std::string mode = etiss::cfg().get<std::string>(ss.str(), "");
        std::stringstream().swap(ss);

        if (origin != (etiss::uint64) -1 && length != (etiss::uint64) -1) {
            configured_address_spaces_[origin] = length;

            int access = MemSegment::UNSET;
            std::string modestr = "";
            if (mode.find('R') != mode.npos) {
                access |= MemSegment::READ;
                modestr += "R";
            }
            if (mode.find('W') != mode.npos) {
                access |= MemSegment::WRITE;
                modestr += "W";
            }
            if (mode.find('X') != mode.npos) {
                access |= MemSegment::EXEC;
                modestr += "X";
            }

            std::stringstream sname;
            sname << i + 1 << " - " << modestr
                << "[0x" << std::hex << std::setfill('0') << std::setw(sizeof(etiss::uint64) * 2) << origin + length - 1 << " - "
                << "0x" << std::hex << std::setfill('0') << std::setw(sizeof(etiss::uint64) * 2) << origin << "]";

            etiss::uint8 *buf = nullptr;
            size_t fsize = 0;

            if (image != "")
            {
                std::ifstream ifs(image, std::ifstream::binary | std::ifstream::ate);
                if (!ifs) {
                    std::stringstream msg;
                    msg << "Error during read of segment image file " << image << "!";
                    etiss::log(etiss::FATALERROR, msg.str());
                }
                fsize = ifs.tellg();
                ifs.seekg(0, std::ifstream::beg);

                buf = new etiss::uint8[fsize];

                ifs.read((char*)buf, fsize);
            }

            auto mseg = std::make_unique<MemSegment>(origin, length, static_cast<MemSegment::access_t>(access), sname.str(), nullptr);
            add_memsegment(mseg, buf, fsize);
        }
    }
}

void SimpleMemSystem::load_elf()
{
    if (!etiss::cfg().isSet("vp.elf_file")) return;

    std::string elf_file = etiss::cfg().get<std::string>("vp.elf_file", "");

    ELFIO::elfio reader;

    if (!reader.load(elf_file))
    {
        etiss::log(etiss::FATALERROR, "ELF reader could not process file");
    }

    if (etiss::cfg().isSet("arch.cpu")) {
        std::stringstream ss;
        ss << "Assuming CPU architecture " << etiss::cfg().get<std::string>("arch.cpu", "") << " as set in configuration file. ELF architecture field will be ignored";
        etiss::log(etiss::INFO, ss.str());
    } else {
        // set architecture automatically
        if (reader.get_machine() == EM_RISCV)
        {
            if ((reader.get_class() == ELFCLASS64)) {
                etiss::cfg().set<std::string>("arch.cpu", "RISCV64"); // RISCV and OR1K work as well
            } else if ((reader.get_class() == ELFCLASS32)) {
                etiss::cfg().set<std::string>("arch.cpu", "RV32IMACFD");
            // add conditions
            } else {
                etiss::log(etiss::FATALERROR, "System architecture is neither 64 nor 32 bit!");
            }
        }
        else if (reader.get_machine() == EM_OPENRISC)
        {
            if ((reader.get_class() == ELFCLASS32))
                etiss::cfg().set<std::string>("arch.cpu", "OR1K");
            if ((reader.get_class() == ELFCLASS64))
                etiss::log(etiss::FATALERROR, "OR1k 64 is not supported");
        }
        else
        {
            std::stringstream ss;
            ss << "Target architecture with code 0x" << std::hex << std::setw(2) << std::setfill('0') << reader.get_machine() << " was not automatically recognized, please set the arch.cpu parameter manually!";
            etiss::log(etiss::FATALERROR, ss.str());
        }
        std::stringstream ss;
        ss << "Set ETISS architecture to " << etiss::cfg().get<std::string>("arch.cpu", "") << " as specified in ELF-file.";
        etiss::log(etiss::INFO, ss.str());
    }

    for (auto &seg : reader.segments)
    {
        etiss::uint64 start_addr = seg->get_physical_address();
        etiss::uint64 size = seg->get_memory_size();
        if (size == 0) continue;
        size_t file_size = seg->get_file_size();
        if (seg->get_type() != PT_LOAD) continue;

        int mode = 0;
        std::string modestr = "";
        if (seg->get_flags() & PF_R) {
            mode |= MemSegment::READ;
            modestr += "R";
        }
        if (seg->get_flags() & PF_W) {
            mode |= MemSegment::WRITE;
            modestr += "W";
        }
        if (seg->get_flags() & PF_X) {
            mode |= MemSegment::EXEC;
            modestr += "X";
        }

        std::stringstream sname;
        sname << seg->get_index() << " - " << modestr
              << "[0x" << std::hex << std::setfill('0') << std::setw(sizeof(etiss::uint64) * 2) << start_addr << " - "
              << "0x" << std::hex << std::setfill('0') << std::setw(sizeof(etiss::uint64) * 2) << start_addr + size - 1 << "]";

        auto mseg_it = std::find_if(msegs_.begin(), msegs_.end(), find_fitting_mseg(start_addr, size));

        if (mseg_it != msegs_.end()) {
            auto & mseg = *mseg_it;

            mseg->name_ = sname.str();
            mseg->mode_ = static_cast<MemSegment::access_t>(mode);

            mseg->load(seg->get_data(), start_addr - mseg->start_addr_, file_size);

            std::stringstream msg;
            msg << "Initialized the memory segment " << mseg->name_ << " from ELF-file";
            etiss::log(etiss::INFO, msg.str());

            continue;
        }

        std::stringstream msg;
        msg << "Found no matching memory segments at 0x" << std::hex << std::setfill('0') << std::setw(8) << start_addr;

        if (error_on_seg_mismatch_) {
            msg << "! As you turned on error_on_seg_mismatch, ETISS will now terminate.";
            etiss::log(etiss::FATALERROR, msg.str());
        } else {
            msg << ", creating one. WARNING: the segment will be created with the size information present in the ELF-file, the resulting segment may be too small to fit dynamic data (cache, heap)!";
            etiss::log(etiss::WARNING, msg.str());
        }

        auto mseg = std::make_unique<MemSegment>(start_addr, size, static_cast<MemSegment::access_t>(mode), sname.str());
        add_memsegment(mseg, seg->get_data(), file_size);
    }

    // read start or rather program boot address from ELF
    start_addr_ = reader.get_entry();
}

void SimpleMemSystem::add_memsegment(std::unique_ptr<MemSegment>& mseg, const void *raw_data, size_t file_size_bytes)
{
    std::stringstream msg;
    msg << "New Memory segment added: " << mseg->name_;
    etiss::log(etiss::INFO, msg.str().c_str());

    mseg->load(raw_data, 0, file_size_bytes);

    msegs_.push_back(std::move(mseg));
}

SimpleMemSystem::SimpleMemSystem() :
    print_ibus_access_(etiss::cfg().get<bool>("simple_mem_system.print_ibus_access", false)),
    print_dbus_access_(etiss::cfg().get<bool>("simple_mem_system.print_dbus_access", false)),
    print_dbgbus_access_(etiss::cfg().get<bool>("simple_mem_system.print_dbgbus_access", false)),
    print_to_file_(etiss::cfg().get<bool>("simple_mem_system.print_to_file", false)),
    error_on_seg_mismatch_(etiss::cfg().get<bool>("simple_mem_system.error_on_seg_mismatch", false)),
    message_max_cnt_(etiss::cfg().get<int>("simple_mem_system.message_max_cnt", 100))
{
    if (print_dbus_access_)
    {
        trace_file_dbus_.open(etiss::cfg().get<std::string>("etiss.output_path_prefix", "") + "dBusAccess.csv",
                              std::ios::binary);
    }
}

void access_error(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint32 len, std::string error, etiss::Verbosity verbosity) {
    uint64 pc = cpu ? cpu->instructionPointer : 0;
    std::stringstream ss;

    ss << error << ", PC = 0x" << std::hex << std::setw(8) << std::setfill('0') << pc
        << ", address 0x" << std::hex << std::setw(8) << std::setfill('0') << addr << ", length " << len;

    etiss::log(verbosity, ss.str());
}

etiss::int32 SimpleMemSystem::iread(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint32 len)
{
    auto it = std::find_if(msegs_.begin(), msegs_.end(), find_fitting_mseg(addr, len));
    if (it != msegs_.end()) return RETURNCODE::NOERROR;

    access_error(cpu, addr, len, "ibus read error", etiss::ERROR);
    return RETURNCODE::IBUS_READ_ERROR;
}

etiss::int32 SimpleMemSystem::iwrite(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len)
{
    access_error(cpu, addr, len, "ibus write blocked", etiss::ERROR);
    return RETURNCODE::IBUS_WRITE_ERROR;
}

static void trace(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint32 len, bool isWrite, bool toFile, std::ofstream &file)
{
    uint64 time = 0;
    if (cpu) time = cpu->cpuTime_ps;

    std::stringstream text;
    text << time                                                  // time
         << (isWrite ? ";w;" : ";r;")                             // type
         << std::setw(8) << std::setfill('0') << std::hex << addr // addr
         << ";" << len << std::endl;

    if (toFile)
        file << text.str();
    else
        std::cout << text.str();
}

template <bool write>
etiss::int32 SimpleMemSystem::dbus_access(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len) {
    auto mseg_it = std::find_if(msegs_.begin(), msegs_.end(), find_fitting_mseg(addr, len));

    if (mseg_it != msegs_.end()) {
        auto & mseg = *mseg_it;
        MemSegment::access_t access = write ? MemSegment::WRITE : MemSegment::READ;

        if (!(mseg->mode_ & access)) {
            access_error(cpu, addr, len, std::string("dbus ") + (write ? "write" : "read") + " forbidden", etiss::WARNING);
        }

        size_t offset = addr - mseg->start_addr_;

        void * dest = write ? mseg->mem_ + offset : buf;
        const void * src = write ? buf : mseg->mem_ + offset;

        memcpy(dest, src, len);

        if (print_dbus_access_) trace(cpu, addr, len, write, print_to_file_, trace_file_dbus_);

        return RETURNCODE::NOERROR;
    }

    access_error(cpu, addr, len, std::string("dbus ") + (write ? "write" : "read") + " error", etiss::ERROR);

    return write ? RETURNCODE::DBUS_WRITE_ERROR : RETURNCODE::DBUS_READ_ERROR;
}

etiss::int32 SimpleMemSystem::dread(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len)
{
    return dbus_access<false>(cpu, addr, buf, len);
}

etiss::int32 SimpleMemSystem::dwrite(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len)
{
    return dbus_access<true>(cpu, addr, buf, len);
}

etiss::int32 SimpleMemSystem::dbg_read(etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len)
{
    return dread(nullptr, addr, buf, len);
}

etiss::int32 SimpleMemSystem::dbg_write(etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len)
{
    return dwrite(nullptr, addr, buf, len);
}

extern void global_sync_time(uint64 time_ps);
void SimpleMemSystem::syncTime(ETISS_CPU *cpu)
{
    // std::cout << "CPU time: " << cpu -> cpuTime_ps << "ps" << std::endl;
    // global_sync_time(cpu->cpuTime_ps);
}
