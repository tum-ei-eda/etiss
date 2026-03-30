// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief implements etiss/JIT.h

        @detail

*/
#include "etiss/JIT.h"

using namespace etiss;

JIT::JIT(std::string name) : name_(name) {}

JIT::~JIT() {}

std::string JIT::getName()
{
    return name_;
}
