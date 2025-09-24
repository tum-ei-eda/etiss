// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

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
