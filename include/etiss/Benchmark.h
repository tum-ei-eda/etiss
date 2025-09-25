// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#ifndef ETISS_BENCHMARK_H
#define ETISS_BENCHMARK_H

#include "etiss/Misc.h"

#include <cmath>
#include <ctime>
#include <list>

namespace etiss
{

struct Default_Clock
{
    double operator()() { return (clock() / (double)CLOCKS_PER_SEC) * 1000000000.0; }
};

namespace benchmark
{
double averageTime(const std::list<std::pair<double, double>> &vals);
}

template <typename clock_ = Default_Clock>
class Benchmark : public etiss::ToString
{
  public:
    clock_ clock_inst;
    const std::string name_;
    Benchmark(const std::string &name) : name_(name), state(false) {}
    void start()
    {
#if DEBUG
        if (unlikely(state != false))
            throw "benchmark not stopped before calling start";
#endif
        state = true;
        cur.first = clock_inst();
    }
    void stop(size_t interval_count = 1)
    {
#if DEBUG
        if (unlikely(state != true))
            throw "benchmark not started before calling start";
#endif
        state = false;
        cur.second = clock_inst();
        interval_ns.push_back(cur);
    }
    std::list<std::pair<double, double>> interval_ns;
    std::string toString() const
    {
        std::stringstream ss;
        ss << name_ << " { average=" << etiss::benchmark::averageTime(interval_ns)
           << "ns samples=" << interval_ns.size() << "}";
        return ss.str();
    }

  private:
    std::pair<double, double> cur;
    bool state;

  public:
};

} // namespace etiss

#endif // ETISS_BENCHMARK_H
