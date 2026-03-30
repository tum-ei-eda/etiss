# SPDX-License-Identifier: BSD-3-Clause
#
# This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
# compliance with the License. You should have received a copy of the license along with this project. If not, see the
# LICENSE file.

EXTTARGETS+=build/UnixTCPGDBConnection.o
EXTOBJECTS+=build/UnixTCPGDBConnection.o

build/UnixTCPGDBConnection.o: src/gdb/UnixTCPGDBConnection.cpp
	$(CC) $(CFLAGS) src/gdb/UnixTCPGDBConnection.cpp -o build/UnixTCPGDBConnection.o
