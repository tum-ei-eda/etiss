#include <cstdint>
#include "CPU.h"
extern "C"
{
    uint32_t handleResources(uint32_t *resource_time, uint32_t **resources, uint32_t num_stages,
                             uint32_t *num_resources, ETISS_CPU *cpu)
    {
        for (int i = 0; i < num_stages; i++)
        {
            int max = 0;
            for (int j = 0; j < num_resources[i]; j++)
            { // set "in use" metric
                cpu->resourceUsages[resources[i][j]] += resource_time[resources[i][j]];
            }
            for (int j = 0; j < num_resources[i]; j++)
            { // find max in this stage
                if (cpu->cycles[resources[i][j]] > max)
                {
                    max = cpu->cycles[resources[i][j]];
                }
            }

            if (!(i == 0))
            { // find max in stage before this stage
                for (int j = 0; j < num_resources[i - 1]; j++)
                {
                    if (cpu->cycles[resources[i - 1][j]] > max)
                    {
                        max = cpu->cycles[resources[i - 1][j]];
                    }
                }
            }
            int max_stagetime = 0;
            for (int j = 0; j < num_resources[i]; j++)
            { // find max time in stage
                if (resource_time[resources[i][j] > max_stagetime])
                {
                    max_stagetime = resource_time[resources[i][j]];
                }
            }

            for (int j = 0; j < num_resources[i]; j++)
            { // set new values
                cpu->cycles[resources[i][j]] = max + max_stagetime;
            }
        }
        return 0;
    }
}
