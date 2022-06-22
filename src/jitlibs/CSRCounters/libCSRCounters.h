#ifndef JITLIB_COUNTERS_H
#define JITLIB_COUNTERS_H

#include "etiss/jit/CPU.h"
#include "etiss/jit/System.h"

etiss_uint64 etiss_get_time();

etiss_uint64 etiss_get_cycles(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

etiss_uint64 etiss_get_instret(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

#endif
