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

        @author Chair of Electronic Design Automation, TUM

        @date November 16, 2021

        @version 0.1

*/
/**
        @file

        @brief implementation of etiss/IntegratedLibrary/fault/MemoryManipulationSystem.h

        @detail

*/

#include "etiss/IntegratedLibrary/fault/MemoryManipulationSystem.h"
#include "etiss/Misc.h"
#include "elfio/elfio.hpp"
#include <memory>

using namespace etiss;
 
std::shared_ptr<VirtualStruct> MemoryManipulationSystem::getStruct(void)
{
    if(!vsystem_)
    {
        vsystem_ = etiss::VirtualStruct::allocate(this, [](etiss::VirtualStruct::Field *f) { delete f; });

    }
    return vsystem_;
}

void MemoryManipulationSystem::init_manipulation(std::shared_ptr<etiss::VirtualStructSupport> vs_parent)
{
    auto mount_successful =  vs_parent->getStruct()->mountStruct(this->getName(), this->getStruct());

    if(!mount_successful)
    {
        etiss::log(etiss::FATALERROR, std::string("Failed to mount ") + this->getName() + std::string("'s VirtualStruct to ") + vs_parent->getName());
    }
    else
    {   
        uint8_t arch_width = 0;
        
        if (etiss::cfg().isSet("arch.cpu")) {
            std::stringstream ss;
            auto cpu_arch_str = etiss::cfg().get<std::string>("arch.cpu", "");
            arch_width = cpu_arch_str == "RISCV64" ? 64 : 32;
        } else {
            // get architecture automatically
            std::string elf_file = etiss::cfg().get<std::string>("vp.elf_file", "");
            ELFIO::elfio reader;
            if (!reader.load(elf_file))
            {
                etiss::log(etiss::FATALERROR, "ELF reader could not process file");
            }
            arch_width = reader.get_class() == ELFCLASS64 ? 64 : 32;
        }
        
        etiss::log(etiss::VERBOSE, std::string("Mounted ") + this->getName() + std::string("'s VirtualStruct to CPUCore ") + vs_parent->getName());
        
        if (!etiss::cfg().isSet("vp.elf_file")) 
        {
            etiss::log(etiss::FATALERROR, std::string("MemoryManipulationSystem::initialize_virtualstruct: Requires \"vp.elf_file\" config to retrieve architecture bit-width."));
        }

        std::string elf_file = etiss::cfg().get<std::string>("vp.elf_file", "");

        ELFIO::elfio reader;

        if (!reader.load(elf_file))
        {
            etiss::log(etiss::FATALERROR, "ELF reader could not process file");
        }

        if (arch_width == 32)
        {
            auto read = [this](size_t address, etiss::int32& return_code) {
              etiss::uint32 x;
              return_code = dbus_access<false>(nullptr, static_cast<etiss::uint64>(address), reinterpret_cast<etiss::uint8 *>(&x), sizeof(x));
              return x;
            };
            auto write = [this](size_t address, etiss::uint32 word, etiss::int32& return_code) {
              return_code = dbus_access<true>(nullptr, static_cast<etiss::uint64>(address), reinterpret_cast<etiss::uint8 *>(&word), sizeof(word));
            };
            mem_manipulator_ = std::make_unique<MemoryWordManipulator<etiss::uint32>>(read, write);
        }
        else if (arch_width == 64)
        {
            auto read = [this](size_t address, etiss::int32& return_code) {
              etiss::uint64 x;
              return_code = dbus_access<false>(nullptr, static_cast<etiss::uint64>(address), reinterpret_cast<etiss::uint8 *>(&x), sizeof(x));
              return x;
            };
            auto write = [this](size_t address, etiss::uint64 word, etiss::int32& return_code) {
              return_code = dbus_access<true>(nullptr, static_cast<etiss::uint64>(address), reinterpret_cast<etiss::uint8 *>(&word), sizeof(word));
            };
            mem_manipulator_ = std::make_unique<MemoryWordManipulator<etiss::uint64>>(read, write);
        }
        else
        {
            etiss::log(etiss::FATALERROR, std::string("Failed to initiliaze MemStack: Architecture bit width not set."));
        }

        getStruct()->applyCustomAction =  [this](const etiss::fault::Fault &fault, const etiss::fault::Action &action, std::string &errormsg) {
            auto cmd = action.getCommand();

            size_t pos = 0;
            std::vector<std::string> split_cmd;
            while ((pos = cmd.find(" ")) != std::string::npos) {
                split_cmd.push_back(cmd.substr(0, pos));
                cmd.erase(0, pos + 1);
            }
            split_cmd.push_back(cmd);
            if (split_cmd.size() > 1)
            {
                std::stringstream ss;
                etiss::uint64 dst_address;
                ss << std::hex << split_cmd[1];
                ss >> dst_address;
                etiss::int32 return_code;
                
                MemoryWordManipulatorBase::mem_manip_cmd_t mem_manip_cmd(split_cmd[0]);
                switch(mem_manip_cmd)
                {
                    case MemoryWordManipulatorBase::MemManipCmd::PUSH:
                        return_code = mem_manipulator_->push(dst_address);
                        break;
                    case MemoryWordManipulatorBase::MemManipCmd::POP:
                        return_code = mem_manipulator_->pop(dst_address);
                        break;
                    case MemoryWordManipulatorBase::MemManipCmd::RMW:
                    {
                        etiss::uint64 val;
                        std::stringstream ssval;
                        ssval << std::hex << split_cmd[3];
                        ssval >> val;
                        return_code = mem_manipulator_->rmw(dst_address, MemoryWordManipulatorBase::MemOp(split_cmd[2]), val);
                        break;
                    }
                    case MemoryWordManipulatorBase::MemManipCmd::RRMW:
                    {
                        etiss::uint64 src2_addr;
                        std::stringstream ssval;
                        ssval << std::hex << split_cmd[3];
                        ssval >> src2_addr;
                        return_code = mem_manipulator_->rrmw(dst_address, MemoryWordManipulatorBase::MemOp(split_cmd[2]), src2_addr);
                        break;
                    }
                    default: /* UNDEF */
                        etiss::log(etiss::FATALERROR, std::string("MemoryManipulationSystem/VirtualStruct/applyCustomAction: \'") 
                            + action.getCommand() + std::string("\' unrecognized Action. Invalid memory manipulation command: ") 
                            + split_cmd[0] );
                        return false;
                }
                
                if (return_code != etiss::RETURNCODE::NOERROR)
                {
                    etiss::log(etiss::FATALERROR, std::string("MemoryManipulationSystem/VirtualStruct/applyCustomAction: \'") + action.getCommand() + std::string("\' memory access error") );
                    return false;
                }

                return true;
            }

            etiss::log(etiss::FATALERROR, std::string("MemoryManipulationSystem/VirtualStruct/applyCustomAction: \'") + action.getCommand() + std::string("\' unrecognized Action") );
            return false;
        };
    }
}

MemoryManipulationSystem::MemoryManipulationSystem(const std::string& name)
  : SimpleMemSystem()
  , name_(name)
  , vsystem_()
  , mem_manipulator_()
{

}

/* MemoryWordManipulatorBase implementation */

template<>
etiss::MemoryWordManipulatorBase::mem_op_t::map_t etiss::MemoryWordManipulatorBase::mem_op_t::TABLE = {  
      {MemoryWordManipulatorBase::MemOpType::COPY, "COPY"}
    , {MemoryWordManipulatorBase::MemOpType::AND, "OR"}
    , {MemoryWordManipulatorBase::MemOpType::OR, "OR"}
    , {MemoryWordManipulatorBase::MemOpType::XOR, "XOR"}
    , {MemoryWordManipulatorBase::MemOpType::NAND, "NAND"}
    , {MemoryWordManipulatorBase::MemOpType::NOR, "NOR"}
    , {MemoryWordManipulatorBase::MemOpType::UNDEF, "UNDEF"}
};


MemoryWordManipulatorBase::MemOp::MemOp(const std::string& memop_str)
  : mem_op_t(memop_str)
{
  if(*this == MemOpType::UNDEF)
      etiss::log(etiss::FATALERROR, std::string("MemoryManipulationSystem/MemFaulter: Unrecognized op code: ") + memop_str );
}

template<>
etiss::MemoryWordManipulatorBase::mem_manip_cmd_t::map_t etiss::MemoryWordManipulatorBase::mem_manip_cmd_t::TABLE = {  
      {MemoryWordManipulatorBase::MemManipCmd::PUSH, "push"}
    , {MemoryWordManipulatorBase::MemManipCmd::POP, "pop"}
    , {MemoryWordManipulatorBase::MemManipCmd::RMW, "rmw"}
    , {MemoryWordManipulatorBase::MemManipCmd::RRMW, "rrmw"}
    , {MemoryWordManipulatorBase::MemManipCmd::UNDEF, "UNDEF"}
};
