// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
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
#include "etiss/Format.h"

#define ARMv6M_DEBUG_PRINT 0
#define MAX_MEMSEGS 99

using namespace etiss;
using namespace ELFIO;

std::unordered_map<std::string, uint32_t> map_messageCounter;
uint32_t printMessage(std::string key, std::string message, uint32_t maxCount)
{
    uint32_t count = map_messageCounter[key]++;
    if (count < maxCount) // print only the first X messages of this type
        std::cout << message << "  (" << (count + 1) << "x)" << std::endl;
    return count;
}

MemSegment::MemSegment(etiss::uint64 start_addr, etiss::uint64 size, access_t mode, const std::string name,
                       etiss::uint8 *mem, std::string initString, bool InitEleSet, uint64_t randomRoot)
    : name_(name), start_addr_(start_addr), end_addr_(start_addr + size - 1), size_(size), mode_(mode)
{
    if (mem)
    { // use reserved memory
        mem_ = mem;
    }
    else
    {
        mem_ = new etiss::uint8[size];
        if (InitEleSet)
        {
            memInit(initString, randomRoot);
        }
        else
        {
            etiss::log(etiss::INFO,
                       etiss::fmt::format("The memory segment is allocated uninitialized with length {:d} !", size_));
        }
        self_allocated_ = true;
    }
}

void MemSegment::memInit(std::string initString, uint64_t randomRoot)
{
    if (initString.find("0x") == 0)
    {
        etiss::log(etiss::INFO,
                   etiss::fmt::format("The memory segment is initialized with {:d} elements with value: 0x{:s}", size_,
                                      initString));

        // actual conversion from hex string to corresponding hex val
        initString.erase(initString.begin(), initString.begin() + 2);
        size_t j{ 0 };

        for (etiss::uint64 i = 0; i < size_; ++i)
        {
            std::string hexStr = "";
            if (j != (initString.length() - 1))
            {
                hexStr = initString.substr(j, 2);
            }
            else
            {
                hexStr = initString.substr(j, 1);
            }

            j = (j + 2 <= initString.length() - 1) ? j + 2 : 0;

            try
            {
                uint8_t hexVal = static_cast<uint8_t>(std::stoi(hexStr.c_str(), 0, 16));
                mem_[i] = hexVal;
            }
            catch (std::invalid_argument const &exp)
            {
                std::stringstream memMsg;
                memMsg << "\n Hex Value MemSegment input is erronous (typo?) at " << exp.what();
                etiss::log(etiss::FATALERROR, memMsg.str());
                break;
            }
        }
    }
    else if (initString.find("random") == 0 || initString.find("RANDOM") == 0)
    {
        etiss::log(etiss::INFO,
                   etiss::fmt::format("The memory segment is initialized with {:d} random bytes and root: {:d}", size_,
                                      randomRoot));

        static std::default_random_engine generator{ randomRoot };
        std::uniform_int_distribution<int> random_char_{ 0, 255 };
        for (etiss::uint64 i = 0; i < size_; ++i)
        {
            mem_[i] = random_char_(generator);
        }
    }

    else
    {
        etiss::log(etiss::INFO,
                   etiss::fmt::format("The memory segment is initialized with {:d} elements with the string: {:s}",
                                      size_, initString));

        const char *data = initString.c_str();
        for (etiss::uint64 i = 0; i < size_; ++i)
        {
            mem_[i] = data[i % strlen(data)];
        }
    }
}

void MemSegment::load(const void *data, size_t offset, size_t file_size_bytes)
{
    if (data != nullptr && (offset + file_size_bytes) <= size_)
    {
        memcpy(mem_ + offset, data, file_size_bytes);
    }
}

bool MemSegment::addr_in_range(etiss::uint64 addr) const
{
    return ((addr >= start_addr_ && addr <= end_addr_) ? true : false);
}

bool MemSegment::payload_in_range(etiss::uint64 addr, etiss::uint64 payload_size) const
{
    if (addr_in_range(addr))
    {
        return (((addr + payload_size - 1) <= end_addr_) ? true : false);
    }
    return false;
}

void SimpleMemSystem::init_memory()
{
    load_segments();
    load_elf();
    std::sort(msegs_.begin(), msegs_.end(), [](std::unique_ptr<MemSegment> &a, std::unique_ptr<MemSegment> &b)
              { return a->start_addr_ < b->start_addr_; });
}

void SimpleMemSystem::load_segments()
{
    std::stringstream ss;

    for (int i = 0; i < MAX_MEMSEGS; ++i)
    {
        uint64_t origin =
            etiss::cfg().get<uint64_t>(etiss::fmt::format("simple_mem_system.memseg_origin_{:02d}", i), -1);

        uint64_t length =
            etiss::cfg().get<uint64_t>(etiss::fmt::format("simple_mem_system.memseg_length_{:02d}", i), -1);
        if (length == 0)
        {
            etiss::log(etiss::FATALERROR, "Empty memsegs are not allowed!");
        }

        auto cfgstr = etiss::fmt::format("simple_mem_system.memseg_initelement_{:02d}", i);
        std::string initString = etiss::cfg().get<std::string>(cfgstr, "");
        bool initEleSet = etiss::cfg().isSet(cfgstr);

        uint64_t randomRoot = etiss::cfg().get<uint64_t>(
            etiss::fmt::format("simple_mem_system.memseg_initelement_random_root_{:02d}", i), 0);

        std::string image =
            etiss::cfg().get<std::string>(etiss::fmt::format("simple_mem_system.memseg_image_{:02d}", i), "");

        std::string mode =
            etiss::cfg().get<std::string>(etiss::fmt::format("simple_mem_system.memseg_mode_{:02d}", i), "");

        if (origin != (etiss::uint64)-1 && length != (etiss::uint64)-1)
        {
            configured_address_spaces_[origin] = length;

            int access = MemSegment::UNSET;
            std::string modestr = "";
            if (mode.find('R') != mode.npos)
            {
                access |= MemSegment::READ;
                modestr += "R";
            }
            if (mode.find('W') != mode.npos)
            {
                access |= MemSegment::WRITE;
                modestr += "W";
            }
            if (mode.find('X') != mode.npos)
            {
                access |= MemSegment::EXEC;
                modestr += "X";
            }

            std::string sname =
                etiss::fmt::format("{} - {:s}[{:#016x} - {:#016x}]", i + 1, modestr, origin + length - 1, origin);

            etiss::uint8 *buf = nullptr;
            size_t fsize = 0;

            if (image != "")
            {
                std::ifstream ifs(image, std::ifstream::binary | std::ifstream::ate);
                if (!ifs)
                {
                    etiss::log(etiss::FATALERROR,
                               etiss::fmt::format("Error during read of segment image file {:s}!", image));
                }
                fsize = ifs.tellg();
                ifs.seekg(0, std::ifstream::beg);

                buf = new etiss::uint8[fsize];

                ifs.read((char *)buf, fsize);

                etiss::log(etiss::INFO,
                           etiss::fmt::format(
                               "The memory segment {:d} is initialized with {:d} bytes from input_image!", i, length)

                );
            }

            auto mseg = std::make_unique<MemSegment>(origin, length, static_cast<MemSegment::access_t>(access), sname,
                                                     buf, initString, initEleSet, randomRoot);
            add_memsegment(mseg, buf, fsize);
            delete[] buf;
        }
    }
}

void SimpleMemSystem::load_elf()
{
    if (!etiss::cfg().isSet("vp.elf_file"))
        return;

    std::string elf_file = etiss::cfg().get<std::string>("vp.elf_file", "");

    ELFIO::elfio reader;

    if (!reader.load(elf_file))
    {
        etiss::log(etiss::FATALERROR, "ELF reader could not process file");
    }

    if (etiss::cfg().isSet("arch.cpu"))
    {
        std::stringstream ss;
        ss << "Assuming CPU architecture " << etiss::cfg().get<std::string>("arch.cpu", "")
           << " as set in configuration file. ELF architecture field will be ignored";
        etiss::log(etiss::INFO, ss.str());
    }
    else
    {
        // set architecture automatically
        if (reader.get_machine() == EM_RISCV)
        {
            if ((reader.get_class() == ELFCLASS64))
            {
                etiss::cfg().set<std::string>("arch.cpu", "RV64IMACFD"); // RISCV and OR1K work as well
            }
            else if ((reader.get_class() == ELFCLASS32))
            {
                etiss::cfg().set<std::string>("arch.cpu", "RV32IMACFD");
                // add conditions
            }
            else
            {
                etiss::log(etiss::FATALERROR, "System architecture is neither 64 nor 32 bit!");
            }
        }
        else
        {
            std::stringstream ss;
            ss << "Target architecture with code 0x" << std::hex << std::setw(2) << std::setfill('0')
               << reader.get_machine()
               << " was not automatically recognized, please set the arch.cpu parameter manually!";
            etiss::log(etiss::FATALERROR, ss.str());
        }
        std::stringstream ss;
        ss << "Set ETISS architecture to " << etiss::cfg().get<std::string>("arch.cpu", "")
           << " as specified in ELF-file.";
        etiss::log(etiss::INFO, ss.str());
    }

    for (auto &seg : reader.segments)
    {
        etiss::uint64 start_addr = seg->get_physical_address();
        etiss::uint64 size = seg->get_memory_size();
        if (size == 0)
            continue;
        size_t file_size = seg->get_file_size();
        if (seg->get_type() != PT_LOAD)
            continue;

        int mode = 0;
        std::string modestr = "";
        if (seg->get_flags() & PF_R)
        {
            mode |= MemSegment::READ;
            modestr += "R";
        }
        if (seg->get_flags() & PF_W)
        {
            mode |= MemSegment::WRITE;
            modestr += "W";
        }
        if (seg->get_flags() & PF_X)
        {
            mode |= MemSegment::EXEC;
            modestr += "X";
        }

        std::string sname = etiss::fmt::format("{} - {:s}[{:#016x} - {:#016x}]", seg->get_index(), modestr,
                                               start_addr + size - 1, start_addr);

        auto mseg_it = std::find_if(msegs_.begin(), msegs_.end(), find_fitting_mseg(start_addr, size));

        if (mseg_it != msegs_.end())
        {
            auto &mseg = *mseg_it;

            mseg->name_ = sname;
            mseg->mode_ = static_cast<MemSegment::access_t>(mode);

            mseg->load(seg->get_data(), start_addr - mseg->start_addr_, file_size);

            std::stringstream msg;
            msg << "Initialized the memory segment " << mseg->name_ << " from ELF-file";
            etiss::log(etiss::INFO, msg.str());

            continue;
        }

        std::stringstream msg;
        msg << etiss::fmt::format("Found no matching memory segments at {:#016x}", start_addr);

        if (error_on_seg_mismatch_)
        {
            msg << "! As you turned on error_on_seg_mismatch, ETISS will now terminate.";
            etiss::log(etiss::FATALERROR, msg.str());
        }
        else
        {
            msg << ", creating one. WARNING: the segment will be created with the size information present in the "
                   "ELF-file, the resulting segment may be too small to fit dynamic data (cache, heap)!";
            etiss::log(etiss::WARNING, msg.str());
        }

        auto mseg = std::make_unique<MemSegment>(start_addr, size, static_cast<MemSegment::access_t>(mode), sname);
        add_memsegment(mseg, seg->get_data(), file_size);
    }

    // read start or rather program boot address from ELF
    start_addr_ = reader.get_entry();
}

void SimpleMemSystem::add_memsegment(std::unique_ptr<MemSegment> &mseg, const void *raw_data, size_t file_size_bytes)
{
    std::stringstream msg;
    msg << "New Memory segment added: " << mseg->name_;
    etiss::log(etiss::INFO, msg.str().c_str());

    mseg->load(raw_data, 0, file_size_bytes);

    msegs_.push_back(std::move(mseg));
}

SimpleMemSystem::SimpleMemSystem()
    : print_ibus_access_(etiss::cfg().get<bool>("simple_mem_system.print_ibus_access", false))
    , print_dbus_access_(etiss::cfg().get<bool>("simple_mem_system.print_dbus_access", false))
    , print_dbgbus_access_(etiss::cfg().get<bool>("simple_mem_system.print_dbgbus_access", false))
    , print_to_file_(etiss::cfg().get<bool>("simple_mem_system.print_to_file", false))
    , error_on_seg_mismatch_(etiss::cfg().get<bool>("simple_mem_system.error_on_seg_mismatch", false))
    , message_max_cnt_(etiss::cfg().get<int>("simple_mem_system.message_max_cnt", 100))
{
    if (print_dbus_access_)
    {
        trace_file_dbus_.open(etiss::cfg().get<std::string>("etiss.output_path_prefix", "") + "dBusAccess.csv",
                              std::ios::binary);
    }
}

void access_error(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint32 len, std::string error, etiss::Verbosity verbosity)
{
    uint64 pc = cpu ? cpu->instructionPointer : 0;
    etiss::log(verbosity,
               etiss::fmt::format("{:s}, PC = {:#016x}, address {:#016x}, length {:d}", error, pc, addr, len));
}

etiss::int32 SimpleMemSystem::iread(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint32 len)
{
    auto it = std::find_if(msegs_.begin(), msegs_.end(), find_fitting_mseg(addr, len));
    if (it != msegs_.end())
        return RETURNCODE::NOERROR;

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
    uint64 pc = 0;

    if (cpu)
    {
        time = cpu->cpuTime_ps;
        pc = cpu->instructionPointer;
    }
    auto text = etiss::fmt::format("{:d};{:#08x};{};{:#08x};{:d}", time, pc, (isWrite ? 'w' : 'r'), addr, len);

    if (toFile)
        file << text << std::endl;
    else
        std::cout << text << std::endl;
}

template <bool write>
etiss::int32 SimpleMemSystem::dbus_access(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len)
{
    auto mseg_it = std::find_if(msegs_.begin(), msegs_.end(), find_fitting_mseg(addr, len));

    if (mseg_it != msegs_.end())
    {
        auto &mseg = *mseg_it;
        MemSegment::access_t access = write ? MemSegment::WRITE : MemSegment::READ;

        if (!(mseg->mode_ & access))
        {
            access_error(cpu, addr, len, std::string("dbus ") + (write ? "write" : "read") + " forbidden",
                         etiss::WARNING);
        }

        size_t offset = addr - mseg->start_addr_;

        void *dest = write ? mseg->mem_ + offset : buf;
        const void *src = write ? buf : mseg->mem_ + offset;

        memcpy(dest, src, len);

        if (print_dbus_access_)
            trace(cpu, addr, len, write, print_to_file_, trace_file_dbus_);

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
