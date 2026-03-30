// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

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
