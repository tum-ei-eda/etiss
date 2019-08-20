/**

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

        This file is part of ETISS tool, see <https://gitlab.lrz.de/de-tum-ei-eda-open/etiss>.

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

        @author Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM

        @date July 29, 2014

        @version 0.1

*/
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
