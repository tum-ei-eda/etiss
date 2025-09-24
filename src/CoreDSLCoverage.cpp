// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#include <cstdarg>
#include <map>

#include "etiss/CoreDSLCoverage.h"
#include "etiss/jit/Coverage.h"

void vetiss_coverage_count(int count, va_list args);

#ifdef ETISS_USE_COREDSL_COVERAGE
extern "C" {
	void etiss_coverage_count(int count, ...) {
		std::va_list args;
		va_start(args, count);
		vetiss_coverage_count(count, args);
		va_end(args);
	}
}
#endif

std::map<int, int> coverage_map;

void vetiss_coverage_count(int count, va_list args) {
	for (int i = 0; i < count; i++) {
		coverage_map[va_arg(args, int)]++;
	}
}
