#!python3
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

#ARMV6MTESTER = 1
OR1KTESTER = 2
RISCVTESTER = 3
GDBTESTER = 4
OVERALLTESTER = 5

class Plugin:

	def __init__(self, name):
		self.__name = name
		self.__type = []

	def isPlugin(self):
		return True;

	def namePlugin(self):
		return self.__name

	def addPluginType(self, pluginType):
		self.__type.append(pluginType)

	def isThisType (self, pluginType):
		for t in self.__type:
			if pluginType == t:
				return True
		return False

	def execute(self, logger):
		pass


#class Armv6MTester(Plugin):
#
#	def __init__(self, name):
#		super().__init__(name)
#		self.__archName = "Armv6M"
#		self. addPluginType(ARMV6MTESTER)
#
#	def nameArch(self):
#		return self.__archName

class Or1kTester(Plugin):

	def __init__(self, name):
		super().__init__(name)
		self.__archName = "Or1k"
		self. addPluginType(OR1KTESTER)

	def nameArch(self):
		return self.__archName

class RiscvTester(Plugin):

	def __init__(self, name):
		super().__init__(name)
		self.__archName = "RISCV"
		self. addPluginType(RISCVTESTER)

	def nameArch(self):
		return self.__archName

class GDBTester(Plugin):

	def __init__(self, name):
		super().__init__(name)
		self. addPluginType(GDBTESTER)


class OverallTester(Plugin):

	def __init__(self, name):
		super().__init__(name)
		self. addPluginType(OVERALLTESTER)
