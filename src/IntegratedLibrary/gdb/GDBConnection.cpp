// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
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
            if (!command_isnotification)
                con.snd("-");
            return;
        }
        else
        {
            if (!command_isnotification)
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
