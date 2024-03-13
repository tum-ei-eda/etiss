#include <cstdarg>
#include <map>

#include "etiss/CoreDSLCoverage.h"
#include "etiss/jit/Coverage.h"

void vetiss_coverage_count(int count, va_list args);

extern "C" {
	void etiss_coverage_count(int count, ...) {
		std::va_list args;
		va_start(args, count);
		vetiss_coverage_count(count, args);
		va_end(args);
	}
}

std::map<int, int> coverage_map;

void vetiss_coverage_count(int count, va_list args) {
	for (int i = 0; i < count; i++) {
		coverage_map[va_arg(args, int)]++;
	}
}
