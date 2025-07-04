/**

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

        This file is part of ETISS tool, see <https://github.com/tum-ei-eda/etiss>.

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

        @brief implementation of etiss/IntegratedLibrary/gdb/GDBConnection.h

        @detail

*/

#include "etiss/IntegratedLibrary/gdb/GDBConnection.h"

#include "etiss/IntegratedLibrary/gdb/Hex.h"
#include "etiss/jit/types.h"
#include <iostream>

#include <chrono>
#include <thread>

using namespace etiss::plugin::gdb;

Connection::Connection() : pending_break_(false), packproc_(*this) {}
Connection::~Connection() {}

PacketProtocol &Connection::getPacketProtocol()
{
    return packproc_;
}

PacketProtocol::PacketProtocol(Connection &connection) : con(connection)
{
    cfg_noack_ = false;
}

size_t PacketProtocol_findUE(std::string &buffer, char c)
{
    size_t cur = buffer.find(c);
    if (cur == 0)
        return cur;
    while (cur != std::string::npos)
    {
        if (buffer[cur - 1] != '}' && (cur <= 1 || buffer[cur - 2] != '}'))
        {
            return cur;
        }
        cur = buffer.find(c, cur);
    }
    return cur;
}
int PacketProtocol_findResponse(std::string &buffer)
{
    size_t pos = 0;
    while (buffer.length() > pos)
    {
        if (buffer[pos] == '+' || buffer[pos] == '-')
        {
            int ret = (int)buffer[pos];
            buffer[pos] = ' ';
            return ret;
        }
        else if (buffer[pos] == '%' || buffer[pos] == '$')
        {
            std::string substr = buffer.substr(pos);
            size_t cpos = PacketProtocol_findUE(substr, '#');
            if (cpos == std::string::npos)
                return 0;
            pos = pos + cpos + 3;
        }
        else if (buffer[pos] != ' ')
        { // previously removed ack
            pos++;
        }
        else
        {
            std::cout << "ERROR: gdb transmission corrupted; aborting" << stream_code_info << std::endl;
            return '+';
        }
    }
    return 0;
}
size_t PacketProtocol_getPacketStart(std::string &buffer)
{
    size_t dol = PacketProtocol_findUE(buffer, '$');
    size_t per = PacketProtocol_findUE(buffer, '%');
    if (dol == std::string::npos && per == std::string::npos)
    {
        return std::string::npos;
    }
    else if (dol == std::string::npos)
    {
        return per;
    }
    else if (per == std::string::npos)
    {
        return dol;
    }
    else
    {
        return dol < per ? dol : per;
    }
}
bool PacketProtocol_startsWith(const std::string &str, const std::string &prefix)
{
    if (prefix.length() > str.length())
        return false;
    return str.substr(0, prefix.length()) == prefix;
}
bool PacketProtocol::available(bool block)
{ // filter function to handle some commands internally
    while (_available(block))
    {
        if (command == "QStartNoAckMode")
        {
            snd("OK", false);
            cfg_noack_ = true;
            command = "";
        }
        else
        {
            return true;
        }
    }
    return false;
}
bool PacketProtocol::_available(bool block)
{
    if (command.length() > 0) // pending command
        return true;
    tryReadPacket();
    if (command.length() > 0) // pending command
        return true;
    do
    {
        if (block || con.available())
        {
            buffer.append(con.rcv());
        }
        tryReadPacket();
        if (command.length() > 0) // pending command
            return true;
    } while (block);
    return false;
}

void PacketProtocol::tryReadPacket()
{
    if (!command.empty())
        return;
    if (con.pendingBREAK())
    {
        command = "W";
        con.clearBREAK();
        return;
    }
    if (buffer.length() > 0 && buffer[0] != '$' && buffer[0] != '%')
    {
        unsigned pos = 0; // may not be 1
        while (buffer.length() > pos && buffer[pos] != '$' && buffer[pos] != '%')
        { // filter non packet symbols (like +,-,SPACE)
            pos++;
        }
        buffer = pos >= buffer.length() ? "" : buffer.substr(pos);
    }
    if (buffer.length() >= 4)
    {
        // find packet data end
        size_t diamond = PacketProtocol_findUE(buffer, '#');
        if (diamond == std::string::npos)
            return;
        // check present packet length
        if (buffer.length() < diamond + 1 + 2)
        {
            return;
        }
        // generate checksum
        std::string tmp = buffer.substr(1, diamond - 1);
        uint8_t chksm = 0;
        for (unsigned i = 0; i < tmp.length(); i++)
        {
            chksm = chksm + (uint8_t)tmp[i];
        }
        uint8_t ochksm = hex::toByte(buffer[diamond + 1], buffer[diamond + 2]);
        // store message type
        command_isnotification = buffer[0] != '$';
        // remove packet from buffer
        buffer = (diamond + 3 >= buffer.length()) ? "" : buffer.substr(diamond + 3);
        // verify packet
        if (chksm != ochksm)
        {
            if (!command_isnotification && !cfg_noack_)
                con.snd("-");
            return;
        }
        else
        {
            if (!command_isnotification && !cfg_noack_)
                con.snd("+");
        }
        if (tmp.find('}') == std::string::npos && tmp.find('*') == std::string::npos)
        { // no escaped characters
            command = tmp;
        }
        else
        { // parse string
            command = tmp;
            tmp = "";
            // expand *
            for (unsigned i = 0; i < command.length(); i++)
            {
                if (i >= 1 && command[i] == '*' && command[i - 1] != '}')
                {
                    if (i + 1 < command.length())
                    {
                        for (int j = 0; j < (int)command[i + 1] - 29; j++)
                        {
                            tmp.push_back(command[i - 1]);
                        }
                    }
                    else
                    {
                        // format error
                    }
                    i++;
                }
                else
                {
                    tmp.push_back(command[i]);
                }
            }
            // translate escaped sequences
            command = "";
            for (unsigned i = 0; i < tmp.length(); i++)
            {
                if (tmp[i] == '}')
                {
                    if (i + 1 < tmp.length())
                    {
                        command.push_back(tmp[++i] ^ 0x20);
                    }
                    else
                    {
                        std::cout << "ERROR: PacketProtocol::available() or its parser functions contain an error"
                                  << stream_code_info << std::endl;
                        command.push_back(tmp[i]); // should not happen
                    }
                }
                else
                {
                    command.push_back(tmp[i]);
                }
            }
        }
    }
}

std::string PacketProtocol::rcv(bool &isnotification)
{
    if (command.length() <= 0)
        available(true);
    std::string ret = command;
    isnotification = command_isnotification;
    command = "";
    return ret;
}
bool PacketProtocol::snd(std::string answer, bool isnotification)
{
    std::string pack = isnotification ? "%" : "$";
    for (unsigned i = 0; i < answer.length(); i++)
    {
        if (answer[i] == '}' || answer[i] == '#' || answer[i] == '$' || answer[i] == '%' || answer[i] == '*')
        {
            pack.push_back('}');
            pack.push_back(answer[i] ^ 0x20);
        }
        else
        {
            pack.push_back(answer[i]);
        }
    }
    pack.push_back('#');
    uint8_t chksm = 0;
    for (unsigned i = 1; i < pack.length() - 1; i++)
    {
        chksm = chksm + (uint8_t)pack[i];
    }
    pack.append(hex::fromByte(chksm));
    con.snd(pack);
    // wait for response
    if (!isnotification && !cfg_noack_)
    {
        while (true)
        {
            if (con.available())
            {
                buffer.append(con.rcv());
            }
            int ack = PacketProtocol_findResponse(buffer);
            if (ack == '+')
            {
                return true;
            }
            else if (ack == '-')
            {
                con.snd(pack);
            }
            else if (ack != 0)
            {
                std::cout << "ERROR: gdp protocol implementation contains an error" << stream_code_info << std::endl;
                return false;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
    return true;
}
bool Connection::isRelyable()
{
    return false;
}
bool Connection::pendingBREAK()
{
    return pending_break_;
}
void Connection::clearBREAK()
{
    pending_break_ = false;
}
