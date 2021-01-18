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

        @date July 28, 2014

        @version 0.1

*/
/**
        @file

        @brief simple test system implementation

*/

#ifndef ETISS_INCLUDE_DEBUGSYSTEM_H_
#define ETISS_INCLUDE_DEBUGSYSTEM_H_
#include "etiss/System.h"
#include <fstream>

#include <cstring>
#include <iostream>
#include <memory>

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

namespace etiss
{
  
  class MemSegment
  {
    bool self_allocated_{false};

    public:
    typedef enum ACCESS{
      READ,
      WRITE,
    } access_t;

    //std::vector<etiss::uint8> mem_;
    etiss::uint8* mem_;
    
    const std::string name_;
    const etiss::uint64 start_addr_;
    const etiss::uint64 end_addr_;
    const etiss::uint64 size_;
    const access_t mode_;

    MemSegment(etiss::uint64 start_addr, etiss::uint64 size, access_t mode, const std::string name, etiss::uint8* mem = nullptr) :
        name_(name)
      , start_addr_(start_addr)
      , end_addr_(start_addr + size -1)
      , size_(size)
      , mode_(mode) {
      if(mem){ // use reserved memory
        mem_ = mem;
      } else {
        mem_ = new etiss::uint8[size];
        self_allocated_ = true;  
      }
    }
    
    virtual ~MemSegment(void){
      delete[] mem_;
    }
    
    void load(const void* data, size_t file_size_bytes){
      if(data != nullptr and file_size_bytes <= size_){
        memcpy(mem_, data, file_size_bytes);
      }
    }
    
    inline bool addr_in_range(etiss::uint64 addr) const {
      return ( (addr >= start_addr_ and addr <= end_addr_) ? true : false);
    }
    
    inline bool payload_in_range(etiss::uint64 addr, etiss::uint64 payload_size) const {
      if(addr_in_range(addr)){
        return ( ((addr+payload_size - 1) <= end_addr_) ? true : false);
      }
      return false;
    }
    
  };
  
  
/**
        @brief simple etiss:System implementation for testing
*/
class DebugSystem : public System
{
  public:

    DebugSystem(uint32_t rom_start, uint32_t rom_size, uint32_t ram_start, uint32_t ram_size);
    DebugSystem(void);

    virtual ~DebugSystem(void){
      for(auto& mseg: msegs_) mseg.reset();
    }
    // memory access
    etiss::int32 iread(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint32 len);
    etiss::int32 iwrite(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len);
    etiss::int32 dread(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len);
    etiss::int32 dwrite(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len);
    etiss::int32 dbg_read(etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len);
    etiss::int32 dbg_write(etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len);
    // sync time
    void syncTime(ETISS_CPU *cpu);
    /**
            @brief loads a binary image from a file to the given address
    */
    // bool load(etiss::uint64 addr,const char * file);
    // bool loadRom(const char *file);
    // bool loadRam(const char *file);
    // void swapEndian(unsigned align = 4);
    
    etiss::int8 load_elf(const char* file);
    etiss::uint64 get_startaddr(void){return (start_addr_);}
    etiss::int8 add_memsegment(std::unique_ptr<MemSegment> mseg, const void* raw_data, size_t file_size_bytes);
  private:
    
    std::vector<std::unique_ptr<MemSegment>> msegs_{};
    
    etiss::uint64 start_addr_{0};
    
    // etiss::uint8 * rom_mem;
    // etiss::uint8 * ram_mem;
    
    std::vector<uint8> ram_mem_{};
    std::vector<uint8> rom_mem_{};
    
    const etiss::uint64 rom_start_;
    const etiss::uint64 ram_start_;
    const etiss::uint64 rom_size_;
    const etiss::uint64 ram_size_;
    
    bool _print_ibus_access;
    bool _print_dbus_access;
    bool _print_dbgbus_access;
    bool _print_to_file;
    
    int message_max_cnt;

    std::ofstream trace_file_dbus_;
};

} // namespace etiss

#endif
