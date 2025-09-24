// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#ifndef __COVERAGE_H__
#define __COVERAGE_H__

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef ETISS_USE_COREDSL_COVERAGE
void etiss_coverage_count(int count, ...);
#else
#define etiss_coverage_count(...)
#endif

#ifdef __cplusplus
}
#endif

#endif
