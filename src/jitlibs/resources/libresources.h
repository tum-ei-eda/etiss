// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#ifndef JITLIB_RESOURCES_H
#define JITLIB_RESOURCES_H

#include <stdint.h>

struct ETISS_CPU;

/*header file for the static library "resources"*/
uint32_t handleResources(uint32_t *resource_time,
						 uint32_t (*resources)[ETISS_MAX_RESOURCES],
						 uint32_t num_stages, uint32_t *num_resources,
                         ETISS_CPU *cpu);

#endif
