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

	@date December 16, 2014

	@version 0.4

*/
/**
	@file config.h

	@brief contains defines to configure ETISS. this file is generated from config.h.in and may not be modified manually. if changes are needed apply them to config.h.in

	@detail

*/
/**
	@file config.h.in

	@brief template of config.h for autoconf. run ./configure in the ETISS root folder to regenerate config.h if changes have been made

	@detail

*/
#ifndef ETISS_CONFIG_H_
#define ETISS_CONFIG_H_

#define ETISS_VERSION_MAJOR 0
#define ETISS_VERSION_MINOR 8
#define ETISS_VERSION_PATCH 0

#define ETISS_VERSION_FULL "0.8.0"

#define ETISS_VERSION_INTERFACE "0.8"


#define ETISS_USE_PYTHON 0

#define ETISS_USE_DLSYM 1

#define ETISS_USE_DLADDR 1

#define ETISS_USE_GETPROC 0

#define ETISS_USE_LINUX_MKDIR ETISS_USE_DLSYM //TODO propper mkdir checks

#define ETISS_USE_DLSYM_DEEPBIND 1

#define ETISS_USE_POSIX_SOCKET 1

#define ETISS_INSTALL_DIR "/home/anoushka/workspace/etiss/trial7/installed"

#define ETISS_USE_CONSTEXPR 1

#if ETISS_USE_CONSTEXPR
#define CONSTEXPR constexpr
#else
#define CONSTEXPR inline
#endif

#define ETISS_LITTLE_ENDIAN 0x00000001
#define ETISS_BIG_ENDIAN 0x01000000
#define ETISS_UNKNOWN_ENDIAN 0xFFFFFFFF

#define ETISS_ENDIANNESS ETISS_LITTLE_ENDIAN

#define ETISS_USE_BYTESWAP_H 1

#endif //ETISS_CONFIG_H_
