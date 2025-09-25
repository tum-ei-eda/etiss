// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief provides a fast memory implementation for ETISS

*/

#include "etiss/jit/System.h"
#include <memory>

namespace etiss
{

/**
        creates a very fast ETISS_System structure.
        segmentation faults are possible if the read access happens outside of the range 0 to size-1.
        writing to areas that have been translated results in undefined behaviour.
        instruction write access return etiss::RETURNCODE::IBUS_WRITE_ERROR.
        time synchronization is disabled but may be changed if a custom handle is not required;
*/
std::shared_ptr<ETISS_System> createFastMemory(size_t size);

} // namespace etiss
