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

#include <iomanip>
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

#include <chrono>


namespace {

void logBytes(const char *prefix, const unsigned char *data, size_t len)
{
    static auto start = std::chrono::steady_clock::now();

    auto us = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now() - start
    ).count();

    std::cerr << "[" << us << " us] ";
    std::cerr << prefix << " (" << len << " bytes): ";

    for (size_t i = 0; i < len; ++i)
    {
        const unsigned char c = data[i];

        if (c >= 0x20 && c <= 0x7e)
        {
            std::cerr << static_cast<char>(c);
        }
        else
        {
            std::cerr << "\\x"
                      << std::hex << std::setw(2) << std::setfill('0')
                      << static_cast<unsigned>(c)
                      << std::dec << std::setfill(' ');
        }
    }

    std::cerr << std::endl;
}

} // namespace

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
        abort();  // TODO: expose ignore option, propagate to main sim loop
    }

    // configure socket
    int flag = 1;
    setsockopt(socket_, IPPROTO_TCP, TCP_NODELAY, (char *)&flag, sizeof(int));

    flag = 1;
    setsockopt(socket_, SOL_SOCKET, SO_REUSEADDR, (char *)&flag, sizeof(int));

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
            std::cout << "ERROR: failed to bind TCP socket (ipv4) to port "
                      << port << std::endl;
            std::cout << "\t" << strerror(errno) << std::endl;
            abort();  // TODO: expose ignore option, propagate to main sim loop
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

            std::cerr << "GDB TCP: accepted connection fd="
                      << active_ << std::endl;

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
                std::cerr << "GDB TCP: rejecting additional connection fd="
                          << deny << std::endl;
                close(deny);
            }
        }

        ssize_t len = recv(active_,
                           (void *)(buffer_ + buffer_pos_),
                           1024 - buffer_pos_,
                           block ? 0 : MSG_DONTWAIT);

        if (len > 0)
        {
            // Log exactly what recv() returned, before modifying the buffer.
            logBytes("GDB RAW RX",
                     reinterpret_cast<const unsigned char *>(buffer_ + buffer_pos_),
                     static_cast<size_t>(len));

            for (unsigned i = buffer_pos_;
                 i < static_cast<unsigned>(buffer_pos_ + len);
                 i++)
            {
                if (buffer_[i] == 243 || buffer_[i] == 3)
                {
                    // BREAK character / Ctrl-C
                    for (int j = i + 1; j < buffer_pos_ + len; j++)
                    {
                        buffer_[j - 1] = buffer_[j];
                    }

                    len -= 1;
                    pending_break_ = true;

                    std::cerr << "GDB TCP: received BREAK character"
                              << std::endl;

                    // Re-check the byte that moved into the current position.
                    --i;
                }
            }

            buffer_pos_ += len;
        }
        else if (len == 0)
        {
            std::cerr << "GDB TCP: peer closed connection fd="
                      << active_ << std::endl;

            close(active_);
            active_valid_ = false;
        }
        else if (errno != EAGAIN && errno != EWOULDBLOCK)
        {
            std::cout << "ERROR: gdb socket failed" << std::endl;
            std::cout << "\t" << strerror(errno) << std::endl;

            std::cerr << "GDB TCP: recv failed fd=" << active_
                      << " errno=" << errno
                      << " (" << strerror(errno) << ")"
                      << std::endl;

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

    if (!ret.empty())
    {
        logBytes("GDB RCV RETURN",
                 reinterpret_cast<const unsigned char *>(ret.data()),
                 ret.size());
    }

    return ret;
}

bool UnixTCPGDBConnection::snd(std::string answer)
{
    if (active_valid_)
    {
        logBytes("GDB RAW TX",
                 reinterpret_cast<const unsigned char *>(answer.data()),
                 answer.size());

        unsigned pos = 0;

        while (pos < answer.length())
        {
            ssize_t len =
                write(active_, answer.c_str() + pos, answer.length() - pos);

            if (len < 0)
            {
                if (errno == EINTR)
                {
                    continue;
                }

                if (errno == EAGAIN || errno == EWOULDBLOCK)
                {
                    continue;
                }

                std::cerr << "GDB TCP: write failed fd=" << active_
                          << " errno=" << errno
                          << " (" << strerror(errno) << ")"
                          << std::endl;

                close(active_);
                active_valid_ = false;
                return false;
            }
            else if (len == 0)
            {
                std::cerr << "GDB TCP: write returned 0 fd="
                          << active_ << std::endl;
                return false;
            }
            else
            {
                if (static_cast<size_t>(len) != answer.length() - pos)
                {
                    std::cerr << "GDB TCP: partial write "
                              << len << "/" << (answer.length() - pos)
                              << " bytes" << std::endl;
                }

                pos += static_cast<unsigned>(len);
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
