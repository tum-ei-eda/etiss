// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief implementation of etiss/IntegratedLibrary/gdb/UnixTCPGDBConnection.h

        @detail

*/

#include "etiss/IntegratedLibrary/gdb/UnixTCPGDBConnection.h"

#if ETISS_USE_POSIX_SOCKET

#include <iostream>

#include <errno.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef SOCK_NONBLOCK
#include <fcntl.h>
#define SOCK_NONBLOCK O_NONBLOCK
#endif

using namespace etiss::plugin::gdb;

UnixTCPGDBConnection::UnixTCPGDBConnection(unsigned port)
{
    valid_ = true;
    buffer_pos_ = 0;
    socket_ = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
    active_valid_ = false;
    // check socket
    if (socket_ < 0)
    {
        valid_ = false;
        std::cout << "ERROR: failed to create TCP socket (ipv4)" << std::endl;
        std::cout << "\t" << strerror(errno) << std::endl;
    }
    // configure socket
    int flag = 1;
    setsockopt(socket_, IPPROTO_TCP, TCP_NODELAY, (char *)&flag, sizeof(int)); // disable nagle
    flag = 1;
    setsockopt(socket_, SOL_SOCKET, SO_REUSEADDR, (char *)&flag,
               sizeof(int)); // allow to use port immediatly after this program finished
    // bind socket
    if (valid_)
    {
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = INADDR_ANY;
        addr.sin_port = htons(port);
        if (bind(socket_, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        {
            valid_ = false;
            std::cout << "ERROR: failed to bind TCP socket (ipv4) to port " << port << std::endl;
            std::cout << "\t" << strerror(errno) << std::endl;
        }
    }
    // make passive
    if (valid_)
    {
        listen(socket_, 1);
    }
}
UnixTCPGDBConnection::~UnixTCPGDBConnection()
{
    if (valid_)
        close(socket_);
    if (active_valid_)
        close(active_);
}
bool UnixTCPGDBConnection::available()
{
    return _available(false);
}
bool UnixTCPGDBConnection::_available(bool block)
{
    if (buffer_pos_ > 0)
        return true;
    if (!valid_ && !active_valid_)
        return false;
    // accept new socket
    if (!active_valid_ && valid_)
    {
        int cur = accept(socket_, 0, 0);
        if (cur >= 0)
        {
            active_ = cur;
            active_valid_ = true;
            // configure socket
            int flag = 1;
            setsockopt(cur, IPPROTO_TCP, TCP_NODELAY, (char *)&flag, sizeof(int));
        }
    }
    if (active_valid_)
    {
        if (valid_)
        {
            int deny = accept(socket_, 0, 0);
            if (deny >= 0)
            {
                close(deny);
            }
        }
        ssize_t len = recv(active_, (void *)(buffer_ + buffer_pos_), 1024 - buffer_pos_, block ? 0 : MSG_DONTWAIT);
        if (len > 0)
        {
            for (unsigned i = buffer_pos_; i < (unsigned)(buffer_pos_ + len); i++)
            {
                if (buffer_[i] == 243 || buffer_[i] == 3)
                { // BREAK character // NOTE: usually ctrl-C is sent
                    for (int j = i + 1; j < buffer_pos_ + len; j++)
                    {
                        buffer_[j - 1] = buffer_[j];
                    }
                    len -= 1;
                    pending_break_ = true;
                    // no "break;" in case multiple brk chars have been sent
                }
            }
            buffer_pos_ += len;
        }
        else if (len == 0)
        { // eof
            close(active_);
            active_valid_ = false;
        }
        else if (errno != EAGAIN && errno != EWOULDBLOCK)
        {
            std::cout << "ERROR: gdb socket failed" << std::endl;
            std::cout << "\t" << strerror(errno) << std::endl;
            close(active_);
            active_valid_ = false;
        }
    }
    return buffer_pos_ > 0;
}
std::string UnixTCPGDBConnection::rcv()
{
    if (buffer_pos_ == 0)
        _available(true);
    std::string ret;
    if (buffer_pos_ > 0)
    {
        for (unsigned i = 0; i < buffer_pos_; i++)
        {
            ret.push_back((char)buffer_[i]);
        }
        buffer_pos_ = 0;
    }
    // if (ret.length()>0)
    //	std::cout << "\""<< ret<<  "\""<<  std::endl;
    return ret;
}
bool UnixTCPGDBConnection::snd(std::string answer)
{
    if (active_valid_)
    {
        unsigned pos = 0;
        // std::cout << "\""<< answer<<  "\""<<  std::endl;
        while (pos < answer.length())
        {
            ssize_t len = write(active_, answer.c_str() + pos, answer.length() - pos);
            if (len < 0)
            {
                if (len != EAGAIN && len != EWOULDBLOCK)
                {
                    close(active_);
                    active_valid_ = false;
                    return false;
                }
            }
            else
            {
                pos += len;
            }
        }
        return true;
    }
    else
    {
        available();
        return false;
    }
}

#endif // ETISS_USE_POSIX_SOCKET
