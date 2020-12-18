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

        @date September 2, 2014

        @version 0.1

*/
/**
        @file

        @brief

        @detail




*/

#ifndef ETISS_PLUGIN_ERRORINJECTION_PLUGIN_H_
#define ETISS_PLUGIN_ERRORINJECTION_PLUGIN_H_

#include "etiss/Plugin.h"

#include <list>
#include <string>

namespace etiss
{

namespace plugin
{

namespace errorInjection
{

/**
        @brief Register error injection class. errors may be injected after blocks.
        @detail if needed BlockAccurateHandler::execute may be called from within the cpu thread at any time to apply
   errors
*/
class BlockAccurateHandler : public etiss::CoroutinePlugin
{
  public:
    class Error
    {
      public:
        Error(std::string reg, unsigned errorid, etiss::uint64 time_ps, etiss::uintMax xor_,
              etiss::uintMax and_ = (etiss::uintMax)(etiss::intMax)-1, etiss::uintMax or_ = 0);
        std::string reg;
        unsigned errorid;
        etiss::uint64 time_ps;
        etiss::uintMax xor_;
        etiss::uintMax and_;
        etiss::uintMax or_;
    };

    BlockAccurateHandler();
    ~BlockAccurateHandler();

    /**
            @brief schedule an error
            @param time_ps time of activation in picoseconds
            @param errorid some usedefined id
            @param register a register name that is defined by the used etiss::CPUArch
    */
    void add(etiss::uint64 time_ps, unsigned errorid, std::string register_, etiss::uintMax xor_,
             etiss::uintMax and_ = (etiss::uintMax)(etiss::intMax)-1, etiss::uintMax or_ = 0);

    /**
            @brief call to apply errors
    */
    virtual etiss::int32 execute();

    /**
            @brief reads a file and adds the errors.
            @detail <pre>
                    Syntax:
                            TIME_IN_NANOSECONDS;AFFECTED_BIT[;ERROR_ID]

                    NOTE: 	the ";ERROR_ID" part is optional. No spaces may exist inbetween the values

                    Example:
                            1000;3
                            2000;0;1234

                    above example schedules an error at time:
                            1000 ns: bit number 3 will be flipped e.g. @999ns: 0x00000000 @1001ns: 0x00000008
                            2000 ns: bit number 0 will be flipped e.g. @1999ns: 0x00000008 @2100ns: 0x00000009

                    NOTE: 	due to the infrequent execution of this plugin (usually only after a block)
                            there may be a large delay between scheduled time and application of the error

                    </pre>
    */
    void parseFile(std::string filename, std::string reg);

    virtual std::string _getPluginName() const;

    virtual void init(ETISS_CPU *cpu, ETISS_System *system, CPUArch *arch);
    virtual void cleanup();

  private:
    ETISS_CPU *cpu;
    ETISS_System *system;
    CPUArch *arch;
    std::list<Error> errors_;
    etiss::uint64 last_time_ps;
    etiss::uint64 next_time_ps;
};

} // namespace errorInjection

} // namespace plugin

} // namespace etiss

#endif
