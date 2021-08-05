#include <cstdint>
#include "etiss/jit/CPU.h"

extern "C"
{
    uint32_t handleResources(uint32_t *resource_time, 
							 uint32_t (*resources)[2],
							 uint32_t num_stages,
                             uint32_t *num_resources, ETISS_CPU *cpu)
    {
        for (uint32_t i = 0; i < num_stages; i++)
        {
            etiss_uint64 max = 0;
            for (uint32_t j = 0; j < num_resources[i]; j++)
            { // set "in use" metric
                cpu->resourceUsages[resources[i][j]] += resource_time[resources[i][j]];
            }
            for (uint32_t j = 0; j < num_resources[i]; j++)
            { // find max in this stage
                if (cpu->cycles[resources[i][j]] > max)
                {
                    max = cpu->cycles[resources[i][j]];
                }
            }

            if (!(i == 0))
            { // find max in stage before this stage
                for (uint32_t j = 0; j < num_resources[i - 1]; j++)
                {
                    if (cpu->cycles[resources[i - 1][j]] > max)
                    {
                        max = cpu->cycles[resources[i - 1][j]];
                    }
                }
            }
            uint32_t max_stagetime = 0;
            for (uint32_t j = 0; j < num_resources[i]; j++)
            { // find max time in stage
                if (resource_time[resources[i][j] > max_stagetime])
                {
                    max_stagetime = resource_time[resources[i][j]];
                }
            }

            for (uint32_t j = 0; j < num_resources[i]; j++)
            { // set new values
                cpu->cycles[resources[i][j]] = max + max_stagetime;
            }
        }
        return 0;
    }
}
