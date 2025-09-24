// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief

        @detail




*/
#ifndef ETISS_INCLUDE_GDB_GDBSERVER_H_
#define ETISS_INCLUDE_GDB_GDBSERVER_H_

#include "etiss/CPUArch.h"
#include "etiss/IntegratedLibrary/gdb/GDBConnection.h"
#include "etiss/jit/CPU.h"
#include "etiss/jit/System.h"

#include "etiss/Plugin.h"

#include <memory>

namespace etiss
{

namespace plugin
{

namespace gdb
{

/**
        @brief structure to store breakpoints
*/
class BreakpointDB
{
  public:
    enum BPType
    {
        BPTYPE_BREAK_MEM = 1,
        BPTYPE_BREAK_HW = 2,
        BPTYPE_WATCH_WRITE = 4,
        BPTYPE_WATCH_READ = 8
    };

  public:
    BreakpointDB();
    inline bool isEmpty() { return instrbrkpt_ == 0; }
    inline etiss::uint32 get(etiss::uint64 addr)
    {
        if (unlikely(instrbrkpt_ == 0))
            return 0;
        unsigned a1 = (addr) & 0xFFFF;
        if (unlikely(instrbrkpt_[a1] != 0))
        {
            unsigned a2 = (addr >> 16) & 0xFFFF;
            if (unlikely(instrbrkpt_[a1][a2] != 0))
            {
                unsigned a3 = (addr >> 32) & 0xFFFF;
                if (unlikely(instrbrkpt_[a1][a2][a3] != 0))
                {
                    unsigned a4 = (addr >> 48) & 0xFFFF;
                    std::cout << "Breakpoint hit: " << std::hex << (addr << 2) << std::dec << std::endl;
                    return instrbrkpt_[a1][a2][a3][a4];
                }
            }
        }
        return 0;
    }
    void set(etiss::uint64 addr, etiss::uint32 val);

  private:
    etiss::uint32 ***
        *instrbrkpt_; ///< important: index maps are reversed to instruction pointer e.g pointer(0x0102030405060708)
                      ///< [POINTER != ADDRESS] -> instrbrkpt_[0x0708][0x0506][0x0304][0x0201]
};

/**
        @brief gdb server implementation that is used as a plugin in etiss
*/
class Server : public etiss::CoroutinePlugin, public etiss::TranslationPlugin, public etiss::SystemWrapperPlugin
{
  public:
    Server(etiss::plugin::gdb::PacketProtocol &pp);

    // Plugin
    void init(ETISS_CPU *cpu, ETISS_System *system, CPUArch *arch) override;
    void cleanup() override;

    // Coroutine
    etiss::int32 execute() override; // called before block execution, check for BREAK command

    // Translation
    void finalizeInstrSet(etiss::instr::ModedInstructionSet &) const override;
    void finalizeCodeBlock(etiss::CodeBlock &) const override;
    void *getPluginHandle() override; // handle is pointer to this object

    /// SystemWrapper, @see GDBSystemWrapper.cpp
    ETISS_System *wrap(ETISS_CPU *cpu, ETISS_System *system) override;   // wrap for memory breakpoints
    ETISS_System *unwrap(ETISS_CPU *cpu, ETISS_System *system) override; // undo wrapping

    etiss::int32 preInstructionCallback();
    void preDReadCallback(etiss::uint64 addr);
    void preDWriteCallback(etiss::uint64 addr);
    etiss::int32 postMemAccessCallback(etiss::int32 exception);

  protected:
    // Plugin
    std::string _getPluginName() const override;

    void handlePacket(bool block);

  protected:
    etiss::plugin::gdb::PacketProtocol &con_;
    CPUArch *arch_;
    ETISS_CPU *cpu_;
    ETISS_System *system_;
    ETISS_System *unwrappedSys_;
    bool status_paused_;
    bool gdb_status_paused_;
    unsigned status_step_;
    bool status_pending_jump_;
    bool status_pending_kill_;
    etiss::uint64 status_jumpaddr_;
    BreakpointDB breakpoints_;
    BreakpointDB watchpoints_;
    unsigned execute_skip_count;
    unsigned execute_skip_index;
    unsigned minimal_pc_alignment;

  private:
    std::shared_ptr<Connection> cinst_;

  public:
    static Server *createTCPServer(std::map<std::string, std::string> options);
    static Server *createTCPServer(int port);
};
} // namespace gdb

} // namespace plugin

} // namespace etiss

#endif
