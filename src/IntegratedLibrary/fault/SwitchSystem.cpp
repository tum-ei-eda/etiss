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

#include "etiss/IntegratedLibrary/fault/SwitchSystem.h"

using namespace etiss::plugin::fault;

int32_t SwitchSystem::iread(uint64_t &time_ps, uint64_t addr, uint8_t *buf, uint32_t len)
{
    if (false)
    {
    }
    else
    {
        uint64_t time = plugin_cpu_->cpuTime_ps;
        int32_t exep = plugin_system_->iread(plugin_system_, plugin_cpu_, addr, len); // get iread time
        time_ps += plugin_cpu_->cpuTime_ps - time;
        if (exep != etiss::RETURNCODE::NOERROR)
            return exep;
        time = plugin_cpu_->cpuTime_ps;
        exep = plugin_system_->dbg_read(plugin_system_, addr, buf, len); // read data
        time_ps += plugin_cpu_->cpuTime_ps - time;
        return exep;
    }
}
int32_t SwitchSystem::iwrite(uint64_t &time_ps, uint64_t addr, uint8_t *buf, uint32_t len)
{
    if (false)
    {
    }
    else
    {
        uint64_t time = plugin_cpu_->cpuTime_ps;
        int32_t exep = plugin_system_->iwrite(plugin_system_, plugin_cpu_, addr, buf, len); // write data
        time_ps += plugin_cpu_->cpuTime_ps - time;
        return exep;
    }
}
int32_t SwitchSystem::dread(uint64_t &time_ps, uint64_t addr, uint8_t *buf, uint32_t len)
{
    if (false)
    {
    }
    else
    {
        uint64_t time = plugin_cpu_->cpuTime_ps;
        int32_t exep = plugin_system_->dread(plugin_system_, plugin_cpu_, addr, buf, len); // write data
        time_ps += plugin_cpu_->cpuTime_ps - time;
        return exep;
    }
}
int32_t SwitchSystem::dwrite(uint64_t &time_ps, uint64_t addr, uint8_t *buf, uint32_t len)
{
    if (false)
    {
    }
    else
    {
        uint64_t time = plugin_cpu_->cpuTime_ps;
        int32_t exep = plugin_system_->dwrite(plugin_system_, plugin_cpu_, addr, buf, len); // write data
        time_ps += plugin_cpu_->cpuTime_ps - time;
        return exep;
    }
}
