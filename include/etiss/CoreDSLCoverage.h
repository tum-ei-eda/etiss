#ifndef JITLIB_COVERAGE_H
#define JITLIB_COVERAGE_H

#include <map>

extern "C" {
void etiss_coverage_count(int count, ...);
}

extern std::map<int, int> coverage_map;

#endif