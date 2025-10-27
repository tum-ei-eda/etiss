// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#if __cplusplus >= 202002L // in case of c++20 present we can use std::format etc.
#include <format>
namespace etiss
{
namespace fmt
{
using std::basic_format_args;
using std::format;
using std::format_args;
using std::format_to;
using std::format_to_n;
using std::formatted_size;
using std::make_format_args;
using std::vformat;
using std::vformat_to;
} // namespace fmt
} // namespace etiss
#else // in case < c++20 use fmtlib provide fmtlib
#include <fmt/core.h>
namespace etiss
{
namespace fmt
{
using ::fmt::basic_format_args;
using ::fmt::format;
using ::fmt::format_args;
using ::fmt::format_to;
using ::fmt::format_to_n;
using ::fmt::formatted_size;
using ::fmt::make_format_args;
using ::fmt::vformat;
using ::fmt::vformat_to;
} // namespace fmt
} // namespace etiss
#endif