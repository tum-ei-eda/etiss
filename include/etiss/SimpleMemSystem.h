// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief simple test system implementation

*/

#ifndef ETISS_INCLUDE_SimpleMemSystem_H_
#define ETISS_INCLUDE_SimpleMemSystem_H_
#include "etiss/System.h"
#include "etiss/make_unique.h"
#include <fstream>
#include <random>

#include <cstring>
#include <iostream>
#include <memory>
#include <map>

namespace etiss
{

class MemSegment
{
    bool self_allocated_{ false };

  public:
    enum access_t
    {
        UNSET = 0,
        READ = 1,
        WRITE = 2,
        EXEC = 4
    };
    /*
    typedef enum ACCESS
    {
        READ,
        WRITE,
    } access_t;
    */
    etiss::uint8 *mem_;

    std::string name_;
    const etiss::uint64 start_addr_;
    const etiss::uint64 end_addr_;
    const etiss::uint64 size_;
    access_t mode_;

    /// @brief Constructor of Memory Segment
    /// @param start_addr Start address of segment
    /// @param size Size in bytes
    /// @param mode Access Mode (R/W/X)
    /// @param name Segment name
    /// @param mem Pre-allocated Memory (not overwritten with initString)
    /// @param initString String for initialization with imple_mem_system.memseg_initelement_ value: hex_string with
    /// 0x... / string /random options
    /// @param InitEleSet Should self allocated MemSegment be initialized?
    /// @param randomRoot If initString==Random use this value as generator root
    MemSegment(etiss::uint64 start_addr, etiss::uint64 size, access_t mode, const std::string name,
               etiss::uint8 *mem = nullptr, std::string initString = "", bool InitEleSet = false,
               uint64_t randomRoot = 0);

    // Can be overwritten afterwards with load_elf
    void memInit(std::string initString, uint64_t randomRoot = 0);

    virtual ~MemSegment(void)
    {
        if (self_allocated_ == true)
            delete[] mem_;
    }

    void load(const void *data, size_t offset, size_t file_size_bytes);

    bool addr_in_range(etiss::uint64 addr) const;

    bool payload_in_range(etiss::uint64 addr, etiss::uint64 payload_size) const;
};

/**
        @brief simple etiss:System implementation for testing
*/
class SimpleMemSystem : public System
{
  public:
    SimpleMemSystem(void);

    virtual ~SimpleMemSystem(void)
    {
        for (auto &mseg : msegs_)
            mseg.reset();
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

    void init_memory();
    void load_elf();
    void load_segments(void);
    etiss::uint64 get_startaddr(void) { return (start_addr_); }
    void add_memsegment(std::unique_ptr<MemSegment> &mseg, const void *raw_data, size_t file_size_bytes);

  protected:
    template <bool write>
    etiss::int32 dbus_access(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len);

  private:
    std::vector<std::unique_ptr<MemSegment>> msegs_{};

    etiss::uint64 start_addr_{ 0 };

    struct find_fitting_mseg
    {
        find_fitting_mseg(uint64 addr, uint64 size) : addr(addr), size(size) {}
        bool operator()(const std::unique_ptr<MemSegment> &mseg) { return mseg->payload_in_range(addr, size); }

      private:
        uint64 addr, size;
    };

    bool print_ibus_access_;
    bool print_dbus_access_;
    bool print_dbgbus_access_;
    bool print_to_file_;

    bool error_on_seg_mismatch_;

    int message_max_cnt_;

    std::ofstream trace_file_dbus_;

    std::map<etiss::uint64, etiss::uint64> configured_address_spaces_;
};

} // namespace etiss

void access_error(ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint32 len, std::string error, etiss::Verbosity verbosity);
#endif
