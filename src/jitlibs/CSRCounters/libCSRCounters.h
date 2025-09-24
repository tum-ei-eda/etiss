// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#ifndef JITLIB_COUNTERS_H
#define JITLIB_COUNTERS_H

#include "etiss/jit/CPU.h"
#include "etiss/jit/System.h"

etiss_uint64 etiss_get_time();

etiss_uint64 etiss_get_cycles(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

etiss_uint64 etiss_get_instret(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

#endif
