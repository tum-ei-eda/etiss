#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include "csr.h"

int main()
{
    printf("hello world!\n");
    for (int i = 0; i < 5; ++i) {
        uint64_t cycle = rdcycle64();
        uint64_t time = rdtime64();
        uint64_t instret = rdinstret64();

        uint32_t cycle_l = cycle;
        uint32_t cycle_h = cycle >> 32;

        uint32_t time_l = time;
        uint32_t time_h = time >> 32;

        uint32_t instret_l = instret;
        uint32_t instret_h = instret >> 32;

        printf("cycle_l: %u, cycle_h: %u\n", cycle_l, cycle_h);
        printf("time_l: %u, time_h: %u\n", time_l, time_h);
        printf("instret_l: %u, instret_h: %u\n", instret_l, instret_h);

        printf("cycle: %lu\n", cycle);
        printf("time: %lu\n", time);
        printf("instret: %lu\n", instret);

        printf("---\n");
    }

    uint64_t time_now = rdtime64() / 1000000;
    struct tm* timeinfo;

    timeinfo = gmtime(&time_now);

    printf("current time: %s\n", asctime(timeinfo));
}
