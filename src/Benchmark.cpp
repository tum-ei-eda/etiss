/*

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

        This file is part of ETISS tool, see <https://github.com/tum-ei-eda/etiss>.

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

#include "etiss/Benchmark.h"

namespace etiss
{

namespace benchmark
{

double averageTime(const std::list<std::pair<double, double>> &vals)
{

    if (vals.empty())
        return NAN; /// TODO replace with propper Nan

    std::vector<std::pair<double, unsigned>> *vec1 = new std::vector<std::pair<double, unsigned>>();
    std::vector<std::pair<double, unsigned>> *vec2 = new std::vector<std::pair<double, unsigned>>();
    vec1->reserve(vals.size() / 4 + 1);
    vec2->reserve(vals.size() / 4 + 1);

    unsigned count = 0;
    double sum = 0;
    for (auto iter = vals.begin(); iter != vals.end(); iter++)
    { // first sum
        if (count == 16)
        {
            vec1->push_back(std::make_pair(sum, count));
            count = 0;
            sum = 0;
        }
        sum = sum + (iter->second - iter->first);
        count++;
    }
    if (count > 0) // store final incomplete sum
        vec1->push_back(std::make_pair(sum, count));

    while (vec1->size() > 1)
    {
        sum = 0;
        count = 0;
        unsigned steps = 0;
        size_t iter = 0;
        while (iter < vec1->size())
        {
            if (steps == 16)
            {
                vec2->push_back(std::make_pair(sum, count));
                count = 0;
                sum = 0;
                steps = 0;
            }
            auto p = (*vec1)[iter++];
            sum += p.first;
            count += p.second;
            steps++;
        }
        if (count > 0) // store final incomplete sum
            vec2->push_back(std::make_pair(sum, count));
        std::swap(vec1, vec2);
        vec2->clear();
    }
#if DEBUG
    if (vec1->empty())
        throw "error";
#endif

    return vec1->front().first / vec1->front().second;
}

} // namespace benchmark

} // namespace etiss
