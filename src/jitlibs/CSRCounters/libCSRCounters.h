#ifndef JITLIB_RESOURCES_H
#define JITLIB_RESOURCES_H

#include <stdint.h>
#include "etiss/CPUArch.h"
#include "etiss/jit/CPU.h"
#include "etiss/CPUCore.h"
#include "etiss/ETISS.h"

using namespace etiss;
struct ETISS_CPU;

/*header file for the static library "resources"*/
uint64 etiss_get_time();

uint64 etiss_get_cycles(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

uint64 etiss_get_instret(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

#endif
