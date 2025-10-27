// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief implementation of etiss/IntegratedLibrary/fault/MemoryManipulationSystem.h

        @detail

*/

#include "etiss/IntegratedLibrary/fault/MemoryManipulationSystem.h"
#include "etiss/Misc.h"
#include "elfio/elfio.hpp"
#include <memory>
#include <algorithm>

using namespace etiss;
using namespace ELFIO;

std::shared_ptr<VirtualStruct> MemoryManipulationSystem::getStruct(void)
{
    if (!vsystem_)
    {
        vsystem_ = etiss::VirtualStruct::allocate(this, [](etiss::VirtualStruct::Field *f) { delete f; });
    }
    return vsystem_;
}

void MemoryManipulationSystem::init_manipulation(std::shared_ptr<etiss::VirtualStructSupport> vs_parent)
{
    auto mount_successful = vs_parent->getStruct()->mountStruct(this->getName(), this->getStruct());

    if (!mount_successful)
    {
        etiss::log(etiss::FATALERROR, std::string("Failed to mount ") + this->getName() +
                                          std::string("'s VirtualStruct to ") + vs_parent->getName());
    }
    else
    {
        uint8_t arch_width = 0;

        if (etiss::cfg().isSet("arch.cpu"))
        {
            auto cpu_arch_str = etiss::cfg().get<std::string>("arch.cpu", "");
            arch_width = cpu_arch_str == "RISCV64" ? 64 : 32;
        }
        else
        {
            // get architecture automatically
            std::string elf_file = etiss::cfg().get<std::string>("vp.elf_file", "");
            ELFIO::elfio reader;
            if (!reader.load(elf_file))
            {
                etiss::log(etiss::FATALERROR, "ELF reader could not process file");
            }
            arch_width = reader.get_class() == ELFCLASS64 ? 64 : 32;
        }

        etiss::log(etiss::VERBOSE, std::string("Mounted ") + this->getName() +
                                       std::string("'s VirtualStruct to CPUCore ") + vs_parent->getName());

        if (!etiss::cfg().isSet("vp.elf_file"))
        {
            etiss::log(etiss::FATALERROR, std::string("MemoryManipulationSystem::initialize_virtualstruct: Requires "
                                                      "\"vp.elf_file\" config to retrieve architecture bit-width."));
        }

        std::string elf_file = etiss::cfg().get<std::string>("vp.elf_file", "");

        ELFIO::elfio reader;

        if (!reader.load(elf_file))
        {
            etiss::log(etiss::FATALERROR, "ELF reader could not process file");
        }

        if (arch_width == 32)
        {
            auto read = [this](size_t address, etiss::int32 &return_code)
            {
                etiss::uint32 x;
                return_code = dbus_access<false>(nullptr, static_cast<etiss::uint64>(address),
                                                 reinterpret_cast<etiss::uint8 *>(&x), sizeof(x));
                return x;
            };
            auto write = [this](size_t address, etiss::uint32 word, etiss::int32 &return_code)
            {
                return_code = dbus_access<true>(nullptr, static_cast<etiss::uint64>(address),
                                                reinterpret_cast<etiss::uint8 *>(&word), sizeof(word));
            };
            mem_manipulator_ = std::make_unique<MemoryWordManipulator<etiss::uint32>>(read, write);
        }
        else if (arch_width == 64)
        {
            auto read = [this](size_t address, etiss::int32 &return_code)
            {
                etiss::uint64 x;
                return_code = dbus_access<false>(nullptr, static_cast<etiss::uint64>(address),
                                                 reinterpret_cast<etiss::uint8 *>(&x), sizeof(x));
                return x;
            };
            auto write = [this](size_t address, etiss::uint64 word, etiss::int32 &return_code)
            {
                return_code = dbus_access<true>(nullptr, static_cast<etiss::uint64>(address),
                                                reinterpret_cast<etiss::uint8 *>(&word), sizeof(word));
            };
            mem_manipulator_ = std::make_unique<MemoryWordManipulator<etiss::uint64>>(read, write);
        }
        else
        {
            etiss::log(etiss::FATALERROR,
                       std::string("Failed to initiliaze MemStack: Architecture bit width not set."));
        }

        getStruct()->applyCustomAction =
            [this](const etiss::fault::Fault &fault, const etiss::fault::Action &action, std::string &errormsg)
        {
            auto cmd = action.getCommand();

            size_t pos = 0;
            std::vector<std::string> split_cmd;
            while ((pos = cmd.find(" ")) != std::string::npos)
            {
                split_cmd.push_back(cmd.substr(0, pos));
                cmd.erase(0, pos + 1);
            }
            split_cmd.push_back(cmd);
            if (split_cmd.size() > 1)
            {
                etiss::uint64 dst_address;
                etiss::int32 return_code;
                dst_address = std::stoll(split_cmd[1], nullptr, 16);

                std::transform(split_cmd[0].begin(), split_cmd[0].end(), split_cmd[0].begin(), ::toupper);
                auto mem_manip_cmd = MemoryWordManipulatorBase::mem_manip_cmd_t::_from_string("UNDEF");
                if (auto maybe = MemoryWordManipulatorBase::mem_manip_cmd_t::_from_string_nothrow(split_cmd[0].c_str()))
                {
                    mem_manip_cmd = MemoryWordManipulatorBase::mem_manip_cmd_t::_from_integral(maybe);
                }

                switch (mem_manip_cmd)
                {
                case MemoryWordManipulatorBase::mem_manip_cmd_t::PUSH:
                    return_code = mem_manipulator_->push(dst_address);
                    break;
                case MemoryWordManipulatorBase::mem_manip_cmd_t::POP:
                    return_code = mem_manipulator_->pop(dst_address);
                    break;
                case MemoryWordManipulatorBase::mem_manip_cmd_t::RMW:
                {
                    etiss::uint64 val;
                    val = std::stoll(split_cmd[3], nullptr, 16);
                    return_code =
                        mem_manipulator_->rmw(dst_address, MemoryWordManipulatorBase::MemOp(split_cmd[2]), val);
                    break;
                }
                case MemoryWordManipulatorBase::mem_manip_cmd_t::RRMW:
                {
                    etiss::uint64 src2_addr;
                    src2_addr = std::stoll(split_cmd[3], nullptr, 16);
                    return_code =
                        mem_manipulator_->rrmw(dst_address, MemoryWordManipulatorBase::MemOp(split_cmd[2]), src2_addr);
                    break;
                }
                default: /* UNDEF */
                    etiss::log(etiss::FATALERROR,
                               std::string("MemoryManipulationSystem/VirtualStruct/applyCustomAction: \'") +
                                   action.getCommand() +
                                   std::string("\' unrecognized Action. Invalid memory manipulation command: ") +
                                   split_cmd[0]);
                    return false;
                }

                if (return_code != etiss::RETURNCODE::NOERROR)
                {
                    etiss::log(etiss::FATALERROR,
                               std::string("MemoryManipulationSystem/VirtualStruct/applyCustomAction: \'") +
                                   action.getCommand() + std::string("\' memory access error"));
                    return false;
                }

                return true;
            }

            etiss::log(etiss::FATALERROR, std::string("MemoryManipulationSystem/VirtualStruct/applyCustomAction: \'") +
                                              action.getCommand() + std::string("\' unrecognized Action"));
            return false;
        };
    }
}

MemoryManipulationSystem::MemoryManipulationSystem(const std::string &name)
    : SimpleMemSystem(), name_(name), vsystem_(), mem_manipulator_()
{
}
