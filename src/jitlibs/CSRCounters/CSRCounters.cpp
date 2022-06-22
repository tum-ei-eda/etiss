#include <cstdint>
#include "etiss/CPUArch.h"
#include "etiss/jit/CPU.h"
#include "etiss/CPUCore.h"
#include "etiss/ETISS.h"
#include <chrono>

using namespace etiss;

extern "C"
{

    uint64 etiss_get_cycles(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
    {
        return cpu->cpuTime_ps / cpu->cpuCycleTime_ps;
    }

    uint64 etiss_get_time()
    {
        auto steady_now = std::chrono::system_clock::now().time_since_epoch();
        auto us = std::chrono::duration_cast<std::chrono::microseconds>(steady_now);
        return (uint64)us.count();
    }


    uint64 etiss_get_instret(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers)
    {
        return cpu->cpuTime_ps / cpu->cpuCycleTime_ps;
    }

}
