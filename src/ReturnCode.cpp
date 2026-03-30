// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief implements etiss/ReturnCode.h

        @detail

*/
// special define to generate registration functionality of error codes for the
// maps provided in this file
#define ETISS_RETURNCODE_REGISTRATION_BODY
#include "etiss/jit/ReturnCode.h"

std::map<etiss::int32, const char *> &etiss::RETURNCODE::getErrorMessages()
{
    static std::map<etiss::int32, const char *> map;
    return map;
}

std::map<etiss::int32, const char *> &etiss::RETURNCODE::getErrorNames()
{
    static std::map<etiss::int32, const char *> map;
    return map;
}

int32_t etiss::RETURNCODE::setTemporary(const std::string &msg)
{
    static std::mutex mu;
    static std::string msgs[ETISS_RETURNCODE_TEMPORARY_COUNT];
    static int32_t pos = 0;
    std::lock_guard<std::mutex> lock(mu);
    int32_t ret = pos;
    pos = (pos + 1) % ETISS_RETURNCODE_TEMPORARY_COUNT;
    msgs[ret] = msg;
    return ret;
}

int32_t etiss_returncode_setTemporary(const char *msg)
{
    return etiss::RETURNCODE::setTemporary(std::string(msg));
}
