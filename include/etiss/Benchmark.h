/*

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

        This file is part of ETISS tool, see <https://gitlab.lrz.de/de-tum-ei-eda-open/etiss>.

        The initial version of this software has been created with the funding support by the German Federal
        Ministry of Education and Research (BMBF) in the project EffektiV under grant 01IS13022.

        Redistribution and use in source and binary forms, with or without modification, are permitted
        provided that the following conditions are met:

        1. Redistributions of source code must retain the above copyright notice, this list of conditions and
        the following disclaimer.

        2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions
        and the following disclaimer in the documentation and/or other materials provided with the distribution.

        3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse
        or promote products derived from this software without specific prior written permission.

        THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
        WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
        PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
        DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
        PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
        HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
        NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
        POSSIBILITY OF SUCH DAMAGE.

        </pre>

        @author Chair of Electronic Design Automation, TUM

        @version 0.1

*/

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
