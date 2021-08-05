#ifndef JITLIB_RESOURCES_H
#define JITLIB_RESOURCES_H

#include <stdint.h>

struct ETISS_CPU;

/*header file for the static library "resources"*/
uint32_t handleResources(uint32_t *resource_time,
						 uint32_t (*resources)[2],
						 uint32_t num_stages, uint32_t *num_resources,
                         ETISS_CPU *cpu);

#endif
