// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief

        @detail




*/

#ifndef ETISS_INCLUDE_GDB_UNIXTCPGDBCONNECTION_H_
#define ETISS_INCLUDE_GDB_UNIXTCPGDBCONNECTION_H_
#include "etiss/config.h"

#if ETISS_USE_POSIX_SOCKET

#include "etiss/IntegratedLibrary/gdb/GDBConnection.h"
#include "etiss/jit/types.h"

namespace etiss
{

namespace plugin
{

namespace gdb
{

/**
        @brief implementation of TCP socket + server socket for gdb communication
*/
class UnixTCPGDBConnection : public Connection
{
  public:
    UnixTCPGDBConnection(unsigned port = 2222);
    virtual ~UnixTCPGDBConnection();
    virtual bool available();
    bool _available(bool block);
    virtual std::string rcv();
    virtual bool snd(std::string answer);

  private:
    int socket_;
    bool valid_;
    int active_;
    bool active_valid_;
    etiss::uint8 buffer_[1024];
    unsigned buffer_pos_;
};

} // namespace gdb

} // namespace plugin

} // namespace etiss

#endif // ETISS_USE_POSIX_SOCKET

#endif
