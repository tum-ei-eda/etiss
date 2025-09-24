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

#ifndef ETISS_INCLUDE_GDB_GDBCONNECTION_H_
#define ETISS_INCLUDE_GDB_GDBCONNECTION_H_

#include <string>

namespace etiss
{

namespace plugin
{

namespace gdb
{

class Connection;

/**
        @brief implements gdb's packet protocol
*/
class PacketProtocol
{
    friend class Connection;

  private:
    PacketProtocol(Connection &connection);

  public:
    virtual bool available(bool block = false);
    virtual std::string rcv(bool &isnotification);
    virtual bool snd(std::string answer, bool isnotification);

  private:
    virtual bool _available(bool block);
    virtual void tryReadPacket();
    std::string buffer;
    std::string command;
    bool command_isnotification;
    Connection &con;
    bool cfg_noack_;
};

/**
        @brief interface for gdb connections. implemented by UnixTCPGDBConnection.h . use PacketProtocol
   (Connection::getPacketProtocol) for communication with gdb
*/
class Connection
{
    friend class PacketProtocol;

  public:
    Connection();
    virtual ~Connection();
    virtual bool available() = 0;
    virtual std::string rcv() = 0;
    virtual bool snd(std::string answer) = 0;
    virtual PacketProtocol &getPacketProtocol();
    virtual bool isRelyable();
    virtual bool pendingBREAK();
    virtual void clearBREAK();

  protected:
    bool pending_break_;

  private:
    PacketProtocol packproc_;
};

} // namespace gdb

} // namespace plugin

} // namespace etiss

#endif
