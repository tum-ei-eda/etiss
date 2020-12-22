/*

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

        @version 0.1

*/

#include "OR1KTimer.h"

OR1KTimer::OR1KTimer() {}

OR1KTimer::~OR1KTimer() {}

etiss::int32 OR1KTimer::execute()
{
    // when this function is called, TTCR is not up to date.
    // Therefore we update it according to the internal state registers
    // last_time_0_ps_ and next_timer_match_ps_.
    bool need_internal_update = internal_state_to_TTCR();

    // We also use the internal registers to determine whether an interrupt
    // must be sent, as this is much easier than using TTCR and TTMPR (we just
    // use plugin_cpu_->cpuTime_ps >= next_timer_match_ps_ as the criterion;
    // with TTCR the problem is that we might jump over the match value if it's
    // not at the end of a basic block)
    bool interrupt = internal_state_to_TTMR_IP();

    // In case of a timer match, the internal variables last_time_0_ps_ and
    // next_timer_match_ps_ are no longer up-to-date. As TTCR and TTMR are now
    // set and up-to-date, we use those to calculate the new internal values.
    // The "if" is just a speed optimization, it would always be possible to call
    // regs_to_internal_state if the registers are up-to-date with the cpu time.
    if (need_internal_update)
        regs_to_internal_state();

    // The implementation is level-triggered: As long as TTMR_IP (interrupt
    // pending) is set, we return OR1K_TICKTIMEREXCEPTION, which can be
    // evaluated by ETISS if interrupts are enabled.
    // To implement edge-triggered behaviour, save the old value of the
    // interrupt-pending flag at the beginning of this function and
    // return OR1K_TICKTIMEREXCEPTION only if TTMR_IP was not set before and is
    // set now.
    if (interrupt)
        return OR1K_TICKTIMEREXCEPTION;
    else
        return etiss::RETURNCODE::NOERROR;
}

void OR1KTimer::changedRegister(const char *name)
{

    // etiss::log(etiss::INFO,"changeRegister called ",name);
    // printf("changeRegister called, Name \"%s\", time %ldns \n",  name, plugin_cpu_->cpuTime_ps / 1000);

    if (!name)
        return;

    //
    if (strncmp(name, "SPR[10]", 6) == 0) // one of the timer registers changed?
    {
        regs_to_internal_state();
    }
}

std::string OR1KTimer::_getPluginName() const
{
    return "OR1KTimer";
}

/*
        std::stringstream ss;
        ss << "Timer match, set to " << getTTCR() << " at CPU time "
           << plugin_cpu_->cpuTime_ps / 1000 << " ns" << std::endl;
        etiss::log(etiss::INFO, ss.str());
*/
