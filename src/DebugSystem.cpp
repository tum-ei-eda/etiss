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

#include "elfio/elfio.hpp"
#include <memory>

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

etiss::int8 DebugSystem::load_elf(const char* elf_file){
  ELFIO::elfio reader;
   
  if( !reader.load(elf_file) ){
    etiss::log(etiss::ERROR, "ELF reader could not process file\n");
    return (-1);
  }
  //set architecture automatically 
  if  (reader.get_machine() == EM_RISCV)  {
    if ((reader.get_class() == ELFCLASS64))
      etiss::cfg().set<std::string>("CPUArch", "RISCV64");// RISCV and OR1K work as well 
    if ((reader.get_class() == ELFCLASS32))
      etiss::cfg().set<std::string>("CPUArch", "RISCV");
      //add conditions 


  }
  // 
  if (reader.get_machine() == EM_OPENRISC) {
    if ((reader.get_class() == ELFCLASS32))
        etiss::cfg().set<std::string>("CPUArch", "OR1K");
  }
  
  for(auto& seg : reader.segments){
    std::unique_ptr<MemSegment> mseg;
    etiss::uint64 start_addr = seg->get_physical_address();
    etiss::uint64 size = seg->get_memory_size();
    size_t file_size = seg->get_file_size();
    MemSegment::access_t mode = (seg->get_type() & PF_W) ? MemSegment::WRITE : MemSegment::READ;
    std::stringstream sname;
    sname << seg->get_index() << " - " << std::hex << std::setfill ('0') << (mode ==  MemSegment::WRITE  ? "W" : "R" ) << "[0x" << std::setw(sizeof(etiss::uint64)*2) << start_addr + size -1 << " - " << "0x" << std::setw(sizeof(etiss::uint64)*2) << start_addr<< "]";
    
    bool newseg_valid = true;  
    for(const auto& mseg_it : msegs_){
      if( ( start_addr >= mseg_it->start_addr_) and
        ( start_addr <= mseg_it->end_addr_) ){
          std::stringstream msg;
          msg << "Segment " << sname.str() << "already occupied by another segment\n";
          etiss::log(etiss::WARNING, msg.str().c_str());
          newseg_valid = false;
          break;
        }
    }
    if(newseg_valid){
      if ( (start_addr >= rom_start_) and (start_addr < (rom_start_ + rom_size_)) ){
        mseg = make_unique<MemSegment>( start_addr, size, mode, sname.str(), rom_mem_.data() + (start_addr - rom_start_) );
      } else if ( (start_addr >= ram_start_) and (start_addr < (ram_start_ + ram_size_)) ) {
        mseg = make_unique<MemSegment>( start_addr, size, mode, sname.str(), ram_mem_.data() + (start_addr - ram_start_) );
      } else if( rom_size_ == 0 && ram_size_ == 0 ) { // system memory is dynamically allocated during ELF load (self managed by each memory segment)
        mseg = make_unique<MemSegment>( start_addr, size, mode, sname.str() );
      } else {
        break;
      }
      if(mseg and seg->get_data()) {
        add_memsegment(std::move(mseg), seg->get_data(), file_size);
      }
    }
  }
  
  // read start or rather program boot address from ELF
  start_addr_ = reader.get_entry();
  
  return 0;
}

etiss::int8 DebugSystem::add_memsegment(std::unique_ptr<MemSegment> mseg, const void* raw_data, size_t file_size_bytes){
  
  // sorted insert (0 < start_addr_ < ...)
  size_t i_seg = 0;
  for(i_seg = 0; i_seg < msegs_.size(); ++i_seg){
    if( ( mseg->start_addr_ <= msegs_[i_seg]->start_addr_) ){
      break;
    }
  }
  msegs_.insert(msegs_.begin() + i_seg, std::move(mseg));
  
  // init data
  msegs_[i_seg]->load(raw_data, file_size_bytes);

	std::stringstream msg;
	msg << "New Memory segment added: " << msegs_[i_seg]->name_ << std::endl;
	etiss::log(etiss::INFO, msg.str().c_str());

  return 0;
}

DebugSystem::DebugSystem(uint32_t rom_start, uint32_t rom_size, uint32_t ram_start, uint32_t ram_size) : 
    rom_start_(rom_start)
  , ram_start_(ram_start)
  , rom_size_(rom_size)
  , ram_size_(ram_size)
{
    // mem = new etiss::uint8[DEBUGSYSTEM_MEMBLOCKSIZE*2];
    rom_mem_.resize(rom_size, 0);
    ram_mem_.resize(ram_size, 0);
    std::cout<<"Hey I m the wished constructor"<<std::endl;
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


DebugSystem::DebugSystem(void) :
    rom_start_(-1)
  , ram_start_(-1)
  , rom_size_(0)
  , ram_size_(0) 
{
 
  _print_ibus_access = etiss::cfg().get<bool>("DebugSystem::printIbusAccess", false);
  _print_dbus_access = etiss::cfg().get<bool>("DebugSystem::printDbusAccess", false);
  _print_dbgbus_access = etiss::cfg().get<bool>("DebugSystem::printDbgbusAccess", false);
  _print_to_file = etiss::cfg().get<bool>("DebugSystem::printToFile", false);
  message_max_cnt = etiss::cfg().get<int>("DebugSystem::message_max_cnt", 100);

  if (_print_dbus_access)
  {
    trace_file_dbus_.open(etiss::cfg().get<std::string>("ETISS::outputPathPrefix", "") + "dBusAccess.csv", std::ios::binary);
	}
}


etiss::int32 DebugSystem::iread(ETISS_CPU *, etiss::uint64 addr, etiss::uint32 len)
{
  int i_seg = 0;
  int n_segs = msegs_.size();
  for(i_seg = 0; n_segs; ++i_seg){
    if(msegs_[i_seg]->addr_in_range(addr)) break;
  }
  
  if(i_seg < n_segs){
   return RETURNCODE::NOERROR;
  } 
  
  if (addr >= rom_start_ && addr < rom_start_ + rom_mem_.size()) {
    return RETURNCODE::NOERROR;
  }

  std::cout << std::hex << addr << std::dec << std::endl;
  etiss::log(etiss::ERROR, "wrong address issued in DebugSystem::iread\n");
  return RETURNCODE::IBUS_WRITE_ERROR;
}

etiss::int32 DebugSystem::iwrite(ETISS_CPU *, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len)
{
    etiss::log(etiss::VERBOSE, "Blocked instruction write ");
    return RETURNCODE::IBUS_WRITE_ERROR;
}

static void Trace(etiss::uint64 addr, etiss::uint32 len, bool isWrite, bool toFile, std::ofstream &file) {
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
    int i_seg = 0;
    int n_segs = msegs_.size();
    size_t offset = 0;
    for(i_seg = 0; i_seg < n_segs; ++i_seg){
      if(msegs_[i_seg]->addr_in_range(addr)){
        offset = addr - msegs_[i_seg]->start_addr_;
        break;
      }
    }
    
    if (i_seg < n_segs) {
      if ( msegs_[i_seg]->payload_in_range(addr, len) ) {
        memcpy(buf, msegs_[i_seg]->mem_ + offset, len);
        if (_print_dbus_access) {
          Trace(addr, len, false, _print_to_file, trace_file_dbus_);
        }
      } else {
        std::cout << std::hex << addr << std::dec << std::endl;
        std::stringstream msg;
        msg << "length (" << len << ") of databus access out of bounds for DebugSystem::dread at associated segment " 
          <<  msegs_[i_seg]->name_ << "\n";
        etiss::log(etiss::ERROR, msg.str());
        return RETURNCODE::DBUS_READ_ERROR;
      }
    } else { // no segment found, check for "physical" memory
      if (addr >= rom_start_ && addr < rom_start_ + rom_mem_.size()) {
        addr -= rom_start_;
        memcpy(buf, rom_mem_.data() + addr, len);
      } else if (addr >= ram_start_ && addr < ram_start_ + ram_mem_.size()) {
        addr -= ram_start_;
        memcpy(buf, ram_mem_.data() + addr, len);

        if (_print_dbus_access) {
          Trace(addr, len, false, _print_to_file, trace_file_dbus_);
        }
      } else {
        std::cout << std::hex << addr << std::dec << std::endl;
        etiss::log(etiss::ERROR, "wrong address issued in DebugSystem::dread\n");
        return RETURNCODE::DBUS_READ_ERROR;
      }
    }
    
  }
    
    return RETURNCODE::NOERROR;
}

etiss::int32 DebugSystem::dwrite(ETISS_CPU *, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len)
{
  int i_seg = 0;
  int n_segs = msegs_.size();
  size_t offset = 0;
  for(i_seg = 0; i_seg < n_segs; ++i_seg){
    if(msegs_[i_seg]->addr_in_range(addr)){
        offset = addr - msegs_[i_seg]->start_addr_;
      break;
    }
  }
  
  if (i_seg < n_segs) {
    if ( msegs_[i_seg]->payload_in_range(addr, len) ) {
      memcpy(msegs_[i_seg]->mem_ + offset, buf, len);
      if (_print_dbus_access) {
        Trace(addr, len, true, _print_to_file, trace_file_dbus_);
      }
    } else {
      std::cout << std::hex << addr << std::dec << std::endl;
      std::stringstream msg;
      msg << "length (" << len << ") of databus access out of bounds for DebugSystem::dwrite at associated segment " 
        << msegs_[i_seg]->name_ << "\n";
      etiss::log(etiss::ERROR, msg.str());
      return RETURNCODE::DBUS_WRITE_ERROR;
    }
  } else { // no segment found, check for "physical" memory
    if (addr >= ram_start_ && addr < ram_start_ + ram_mem_.size()) {
      addr -= ram_start_;
      memcpy(ram_mem_.data() + addr, buf, len);

      if (_print_dbus_access) {
        Trace(addr, len, true, _print_to_file, trace_file_dbus_);
      }
    } else {
      std::cout << "ram_start: " <<std::hex << ram_start_ << std::dec << std::endl;
      std::cout<< "ram size:" << ram_mem_.size() << std::dec << std::endl;
      std::cout << std::hex << addr << std::dec << std::endl;
      etiss::log(etiss::ERROR, "wrong address issued in DebugSystem::dwrite\n");
      return RETURNCODE::DBUS_READ_ERROR;
    }
  }
    return RETURNCODE::NOERROR;
}

etiss::int32 DebugSystem::dbg_read(etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len)
{

    int i_seg = 0;
    int n_segs = msegs_.size();
    size_t offset = 0;
    for(i_seg = 0; i_seg < n_segs; ++i_seg){
      if(msegs_[i_seg]->addr_in_range(addr)){
        offset = addr - msegs_[i_seg]->start_addr_;
        break;
      }
    }
    
    if (i_seg < n_segs) {
      if ( msegs_[i_seg]->payload_in_range(addr, len) ) {
        memcpy(buf, msegs_[i_seg]->mem_ + offset, len);
      } else {
        std::cout << std::hex << addr << std::dec << std::endl;
        std::stringstream msg;
        msg << "length (" << len << ") of databus access out of bounds for DebugSystem::dbg_read at associated segment " 
          <<  msegs_[i_seg]->name_ << "\n";
        etiss::log(etiss::ERROR, msg.str());
        return RETURNCODE::DBUS_READ_ERROR;
      }
    } else { // no segment found, check for "physical" memory
      if (addr >= rom_start_ && addr < rom_start_ + rom_mem_.size()) {
        addr -= rom_start_;
        memcpy(buf, rom_mem_.data() + addr, len);
      } else if (addr >= ram_start_ && addr < ram_start_ + ram_mem_.size()) {
        addr -= ram_start_;
        memcpy(buf, ram_mem_.data() + addr, len);

      } else {
        std::cout << std::hex << addr << std::dec << std::endl;
        etiss::log(etiss::ERROR, "wrong address issued in DebugSystem::dbg_read\n");
        return RETURNCODE::DBUS_READ_ERROR;
      }
    }
    
    return RETURNCODE::NOERROR;
}

etiss::int32 DebugSystem::dbg_write(etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len)
{
  int i_seg = 0;
  int n_segs = msegs_.size();
  size_t offset = 0;
  for(i_seg = 0; i_seg < n_segs; ++i_seg){
    if(msegs_[i_seg]->addr_in_range(addr)){
        offset = addr - msegs_[i_seg]->start_addr_;
      break;
    }
  }
  
  if (i_seg < n_segs) {
    if ( msegs_[i_seg]->payload_in_range(addr, len) ) {
      memcpy(msegs_[i_seg]->mem_ + offset, buf, len);
    } else {
      std::cout << std::hex << addr << std::dec << std::endl;
      std::stringstream msg;
      msg << "length (" << len << ") of databus access out of bounds for DebugSystem::dbg_write at associated segment " 
        << msegs_[i_seg]->name_ << "\n";
      etiss::log(etiss::ERROR, msg.str());
      return RETURNCODE::DBUS_WRITE_ERROR;
    }
  } else { // no segment found, check for "physical" memory
    if (addr >= ram_start_ && addr < ram_start_ + ram_mem_.size()) {
      addr -= ram_start_;
      memcpy(ram_mem_.data() + addr, buf, len);

    } else {
      std::cout << std::hex << addr << std::dec << std::endl;
      etiss::log(etiss::ERROR, "wrong address issued in DebugSystem::dbg_write\n");
      return RETURNCODE::DBUS_READ_ERROR;
    }
  }
    
    return RETURNCODE::NOERROR;
}

extern void global_sync_time(uint64 time_ps);
void DebugSystem::syncTime(ETISS_CPU *cpu)
{
    // std::cout << "CPU time: " << cpu -> cpuTime_ps << "ps" << std::endl;
    // global_sync_time(cpu->cpuTime_ps);
}

