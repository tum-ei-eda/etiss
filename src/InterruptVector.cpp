// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief implements etiss/InterruptVector.h

        @detail

*/
#include "etiss/InterruptVector.h"
#include <iostream>

using namespace etiss;

InterruptVector::~InterruptVector() {}

bool InterruptVector::isActive() const
{
    for (unsigned i = 0; i < width(); i++)
    {
        if (getBit(i))
            return true;
    }
    return false;
}
void InterruptVector::clear()
{
    for (unsigned i = 0; i < width(); i++)
    {
        setBit(i, false);
    }
}
