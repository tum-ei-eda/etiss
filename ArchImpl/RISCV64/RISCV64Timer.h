/*

        @copyright

        <pre>

        Copyright 2018 Chair of Electronic Design Automation, TUM

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

        @version 0.1

*/

#ifndef ETISS_RISCV64Arch_RISCV64TIMER_H_
#define ETISS_RISCV64Arch_RISCV64TIMER_H_

#include "Encoding.h"
#include "RISCV64.h"
#include "etiss/CPUArch.h"

#define TIMER_BASE_ADDR 0x11000000
#define MTIME_ADDR TIMER_BASE_ADDR + 0xbff8
#define MTIMECMP_ADDR TIMER_BASE_ADDR + 0x4000

class RISCV64Timer;

struct RISCV64TimerSystem
{

    struct ETISS_System sys;

    RISCV64Timer *this_;

    ETISS_System *orig;
};

class RISCV64Timer : public etiss::CoroutinePlugin, public etiss::SystemWrapperPlugin
{
  public:
    RISCV64Timer();

    virtual ~RISCV64Timer() {}

    void init(ETISS_CPU *cpu, ETISS_System *system, etiss::CPUArch *arch) { riscv64cpu = (RISCV64 *)cpu; }

    etiss::int32 execute();

    ETISS_System *wrap(ETISS_CPU *cpu, ETISS_System *system);

    ETISS_System *unwrap(ETISS_CPU *cpu, ETISS_System *system);

    etiss::uint64 mtime_;
    etiss::uint64 mtimecmp_;
    char mtimecmp_buf_[8];

  protected:
    virtual std::string _getPluginName() const { return std::string("RISCV-V Timer"); }

  private:
    RISCV64 *riscv64cpu;

    bool timer_enabled_;
    bool mtimecmp_overflow_clear_;
    bool mtimecmp_overflow_;
    bool mtime_overflow_;
};

#endif
