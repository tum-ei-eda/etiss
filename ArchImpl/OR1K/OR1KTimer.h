/*

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

        @author Chair of Electronic Design Automation, TUM

        @version 0.1

*/

#include "OR1KArch.h"

// ETISS_PLUGIN_EXPORT, that is, __attribute__((visibility("default"))), is
// needed by OR1KVCPU when it needs the type information of the timer plugin
class ETISS_PLUGIN_EXPORT OR1KTimer : public etiss::CoroutinePlugin, public etiss::RegisterDevicePlugin
{
  public:
    OR1KTimer();
    virtual ~OR1KTimer();
    virtual etiss::int32 execute();
    virtual void changedRegister(const char *name);

  protected:
    virtual std::string _getPluginName() const;

  private:
    enum Modes
    {
        TIMER_DISABLED,
        TIMER_AUTORESTART,
        TIMER_ONESHOT,
        TIMER_CONTINUOUS
    };

    // internal registers of the timer

    // Instead of TTMR_TP and TTCR, we use two internal state variables:
    // All the functionality of the Timer is in functions which translate
    // from the external (TTMR, TTCR) to the internal (the following vars) state.
    int64_t last_time_0_ps_ = 0; // the last time TTCR was 0
                                 // instead of TTCR; can be negativ if the sw
                                 // sets TTCR to a high value in the beginning
                                 // It is used to calculate TTCR;
                                 // next_timer_match is not enough to calculate
                                 // the first 4 bits of TTCR

    int64_t next_timer_match_ps_ = 0; // instead of TTMR_TP; needs to be updated
                                      // after each timer_match

    // mode: use TTMR
    // IE: use TTMR
    // IP: use TTMR

    // end internal registers

    // convert external state (TTCR, TTMR) to internal state (last_time_0_ps_,
    // next_timer_match_ps_)
    // It requires that TTCR and TTMR are up to date with the current cpu time.
    // calculate last_time_0_ps_ and next_timer_match_ps_.
    inline void regs_to_internal_state()
    {
        bool stop =
            (getMode() == TIMER_DISABLED) || ((getMode() == TIMER_ONESHOT) && (getTTCR_28Bit() == getTTMR_TP()));

        if (!stop)
        {
            last_time_0_ps_ = plugin_cpu_->cpuTime_ps - getTTCR() * plugin_cpu_->cpuCycleTime_ps;

            // calculate next_timer_match_ps_
            // Make sure TP is bigger than TTCR; I don't like negative numbers
            uint32_t ticks_to_match = ((getTTMR_TP() + 0x10000000) - getTTCR_28Bit()) & 0x0FFFFFFF;
            if (ticks_to_match == 0)
                ticks_to_match = 0x10000000;
            next_timer_match_ps_ = plugin_cpu_->cpuTime_ps + plugin_cpu_->cpuCycleTime_ps * ticks_to_match;
        }
    }

    // it returns true if the internal state has to be updated afterwards
    // in order to calculate the next match time
    // e.g. if the TTCR was changed and not only increased.
    // This is only an optimization, regs_to_internal_state() can always be
    // called when the registers are up-to-date with the current cpu time.
    inline bool internal_state_to_TTCR()
    {
        if (getMode() != TIMER_DISABLED) // don't change TTCR if timer is disabled
        {
            // Do we need to change the TTCR?
            if ((int64_t)plugin_cpu_->cpuTime_ps >= next_timer_match_ps_) // timer match
            {
                switch (getMode())
                {
                case TIMER_DISABLED: // avoid compiler warning "TIMER_DISABLED
                    return false;    // not handled in switch"
                case TIMER_AUTORESTART:
                    *((OR1K *)plugin_cpu_)->TTCR =
                        static_cast<etiss_uint32>((plugin_cpu_->cpuTime_ps - next_timer_match_ps_) / plugin_cpu_->cpuCycleTime_ps);
                    return true;
                case TIMER_ONESHOT: // change TTCR to meet the exact value: like in hardware
                    *((OR1K *)plugin_cpu_)->TTCR = (getTTCR() & 0xf0000000) | getTTMR_TP();
                    return false;
                case TIMER_CONTINUOUS: // just continue counting
                    *((OR1K *)plugin_cpu_)->TTCR =
                        (uint32_t)((plugin_cpu_->cpuTime_ps - last_time_0_ps_) / plugin_cpu_->cpuCycleTime_ps);
                    return true; // we need to calculate the next firing point
                }
            }
            else // no timer match, just counting auto-restart, one-shot or continuous
            {
                *((OR1K *)plugin_cpu_)->TTCR =
                    (uint32_t)((plugin_cpu_->cpuTime_ps - last_time_0_ps_) / plugin_cpu_->cpuCycleTime_ps);
                return false;
            }
        }
        return false;
    }

    // returns TTMR_IP
    inline bool internal_state_to_TTMR_IP()
    {
        etiss::uint32 &TTMR = *((OR1K *)plugin_cpu_)->TTMR;

        bool match;
        if (getMode() == TIMER_DISABLED)
            match = getTTCR_28Bit() == getTTMR_TP(); // use external match in disabled case
        else                                         // in one-shot, we continuously fire interrupts after the match
            match = (int64_t)plugin_cpu_->cpuTime_ps >= next_timer_match_ps_;

        // write interrupt
        if (getTTMR_IE() && match)
        {
            TTMR = TTMR | 0x10000000U;
        }
        return TTMR & 0x10000000U;
    }

    // simple getter helpers
    inline Modes getMode() { return Modes(*(((OR1K *)plugin_cpu_)->TTMR) >> 30); }

    inline etiss::uint32 getTTCR() { return *((OR1K *)plugin_cpu_)->TTCR; }

    inline etiss::uint32 getTTCR_28Bit() { return *((OR1K *)plugin_cpu_)->TTCR & 0x0FFFFFFF; }

    inline etiss::uint32 getTTMR_TP() { return *((OR1K *)plugin_cpu_)->TTMR & 0x0FFFFFFF; }

    inline bool getTTMR_IE() { return (*((OR1K *)plugin_cpu_)->TTMR & 0x20000000U) ? true : false; }
};

/*
The timer in hardware has no additional state register, TTCR and TTMR are
enough.

It has three important internal wires:
match
restart (match and auto-restart mode)
stop (do not increase counter: match and one-shot, disabled mode)

In software, the implementation is much more complicated, as we don't update
the timer every cycle but only once in a while. Therefore, we have to remember
when it was last updated.
We could use the variable timer_last_TTCR_update_ps_ for that purpose.
In the older timer implementation, the variable _timer_last_ps saved the time
of the last time the timer was 0. Is this better? It could be problematic if
the software sets TTCR to a big value in the beginning, as then _timer_last_ps
would be negative.
It should not matter which of the two is used, as long as it's always updated
together with TTCR.

What about saving the time of the next timer match? No risc of overflows
while doing comparisons for calculating timer_match!
Drawback: It's not possible to calculate the first 4 bits of TTCR from that.
For that reason, we also need the time when it last was 0.
But we no longer need to consider TTMR_TP, except for checking whether the timer
has been stopped in one-shot mode. => That's how we do it.

The hardware model shows that it's always possible to tell from TTCR and TTMR
whether the timer is currently counting or not. Only if it is counting,
the value of the helper variables should be important; if it is not counting,
they should be ignored. Thus, we only have to make sure that they are always
updated when TTCR or TTMR are changed.

To be compatible with the hardware model (especially while debooting OR1KVCPU,
that is, switching from a verilog-based RTL model back to ETISS), we should
be able to deduct the complete state of the timer just from TTCR and TTMR.
This is not completely possible; we need the debooting time as third input.




*/
