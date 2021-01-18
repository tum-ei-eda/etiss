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

        @date September 2, 2014

        @version 0.1

*/
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
        unsigned a1 = (addr)&0xFFFF;
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

    virtual ~Server();

    virtual etiss::int32 preInstructionCallback();

    virtual etiss::int32 preMemoryAccessCallback(etiss::uint64 addr, etiss::uint32 len, bool data, bool read);

    virtual etiss::int32 execute(); // called before block execution, check for BREAK command

    virtual void process(etiss::CodeBlock &block, unsigned index); // add instruction breakpoint check

    virtual void finalizeInstrSet(etiss::instr::ModedInstructionSet &) const;

    virtual void finalizeCodeBlock(etiss::CodeBlock &) const;

    /**

            @see GDBSystemWrapper.cpp
    */
    virtual ETISS_System *wrap(ETISS_CPU *cpu, ETISS_System *system); // wrap for memory breakpoints
    /**

            @see GDBSystemWrapper.cpp
    */
    virtual ETISS_System *unwrap(ETISS_CPU *cpu, ETISS_System *system); // undo wrapping

    virtual void *getPluginHandle(); // handle is pointer to this object

    virtual void init(ETISS_CPU *cpu, ETISS_System *system, CPUArch *arch);

    virtual void cleanup();

  protected:
    virtual void handlePacket(bool block);
    virtual std::string _getPluginName() const;

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
