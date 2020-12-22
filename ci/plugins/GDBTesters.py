#!/usr/bin/python3
#
#	Copyright 2018 Infineon Technologies AG
#
#	This file is part of ETISS tool, see <https://github.com/tum-ei-eda/etiss>
#
#	The initial version of this software has been created with the funding support by the German Federal
#	Ministry of Education and Research(BMBF) in the project EffektiV under grant 01IS13022.
#
#	Redistribution and use in source and binary forms, with or without modification, are permitted
#	provided that the following conditions are met:
#
#	1. Redistributions of source code must retain the above copyright notice, this list of conditions and
#	the following disclaimer.
#
# 	2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions
#	and the following disclaimer in the documentation and / or other materials provided with the distribution.
#
# 	3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse
# 	or promote products derived from this software without specific prior written permission.
#
#	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
#	WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
#	PARTICULAR PURPOSE ARE DISCLAIMED.IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
#	DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES(INCLUDING, BUT NOT LIMITED TO,
#	PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
#	HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT(INCLUDING
#	NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
#	POSSIBILITY OF SUCH DAMAGE.
#
#
#	Author: Chair of Electronic Design Automation, TUM
#
#	Version 0.1
#
import os, sys
sys.path.append(os.path.dirname(os.path.abspath(__file__)))
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

import logger as lg
import pluginInterface as pif
from Color import Color

class Or1kGDBTester (pif.Or1kTester, pif.GDBTester):

	def __init__(self, name):
		# Diamond problem is automatically solved by python
		super().__init__(name)

#class Armv6MGDBTester (pif.Armv6MTester, pif.GDBTester):
#
#	def __init__(self, name):
#		super().__init__(name)

class RiscvGDBTester (pif.RiscvTester, pif.GDBTester):

	def __init__(self, name):
		super().__init__(name)


def countPlugins():
	return 3

def createPlugin(index, **kwargs):
	if index == 0:
		tester = Or1kGDBTester("Or1kArchGDBTester")
		# tester.swDir = kwargs["Or1kSwDir"]
		# tester.simDir = kwargs["Or1kSimDir"]
		tester.execute = testOr1kArchGDB
		return tester

	elif index == 1:
		tester = RiscvGDBTester("RiscvArchGDBTester")
		# tester.swDir = kwargs["RiscvSwDir"]
		# tester.simDir = kwargs["RiscvSimDir"]
		tester.execute = testRiscvArchGDB
		return tester

	elif index == 2:
		# Add Armv6M GDB here
		return None
	else:
		return None


def testOr1kArchGDB(self, logger):
	logger.info(Color.BOLD + Color.RED +"\n\nGDB tester for Or1k architecure not implemented yet\n"\
			 + Color.END)

def testRiscvArchGDB(self, logger):
	logger.info(Color.BOLD + Color.RED +"\n\nGDB tester for RISCV architecure not implemented yet\n"\
			 + Color.END)

# Unit test
if __name__ == '__main__':
	logger = lg.createLogger("GDBTesterLogger", debug = True)
	testers  = []
	for i in range(0, countPlugins()):
		testers.append(createPlugin(i))
	for t in testers:
		if t:
			print(t.namePlugin())
			print (t.nameArch())
