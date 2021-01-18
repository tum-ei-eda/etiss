#!/usr/bin/python3
#
#	Copyright 2018 Infineon Technologies AG
#
#	This file is part of ETISS tool, see <https://gitlab.lrz.de/de-tum-ei-eda-open/etiss>
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

import re
import shutil
from threading import Timer
from contextlib import contextmanager
import shlex, subprocess
from Color import Color

SW_REGEX = re.compile(r"\s*sw_binary\s*=\s*../SW/[\w\d]+/build/code.bin")
ARCH_REGEX = re.compile(r"\s*CPUArch\s*=\s*[\w\d]+")
JIT_REGEX = re.compile(r"\s*type\s*=\s*[w]+")


@contextmanager
def cd(newDir):
	""" Change to directory newDir

		It is implemented as a context manager to make sure to come back original
		working directory after task finished

		Args:
			newDir: target directory
	"""

	prevDir = os.getcwd()
	os.chdir(os.path.expanduser(newDir))
	try:
		yield
	finally:
		os.chdir(prevDir)


def testArchitecure(self, logger):
	""" Test given architecure such as Armv6M, Or1k

		It will compile software, build simulator and run simulation according to
		specific tester it being ported into.

		Args:
			logger: A pre-configured logger should be given to generate desired log
					file
	"""

	ERRCODE_TIMEOUT = -9

	# Execute shell command lines interactively with output and error msg.
	def interactiveExec (cmd, timeOut = 0):
		if timeOut:
			to = timeOut
		else:
			to = None
		try:
			p = subprocess.Popen(cmd, shell = True, stdout=subprocess.PIPE, \
				stderr=subprocess.PIPE )
			out, err = p.communicate(timeout = to)
		except subprocess.TimeoutExpired as e:
			logger.error("Command {} timed out after {} seconds".format(cmd, to))
			return  ERRCODE_TIMEOUT
		else:
			errcode = p.returncode
		if errcode:
			logger.error(err.decode('utf-8').strip())
			logger.info(out.decode('utf-8').strip())
		return errcode


	# Compiling  software
	with cd (self.swDir):
		logger.info("Enter the directory: {}".format(os.path.abspath(self.swDir)))
		if interactiveExec(['make']):
			logger.critical("{} Software compilation fails".format(self.nameArch()))
			raise Exception("{} Software compilation fails".format(self.nameArch()))
		logger.info("{} Software has been compiled into binary code".format(self.nameArch()))

	# Build  simulator
	with cd (self.simDir):
		logger.info("Enter the directory: {}".format(os.path.abspath(self.simDir)))
		subprocess.call("mkdir -p ./build", shell = True)
		with cd("build"):
			if interactiveExec("cmake -DCMAKE_BUILD_TYPE=Debug .. ")\
			 or interactiveExec("make"):
				logger.critical("Fail to build {} simulator".format(self.nameArch()))
				raise Exception("Fail to build {} simulator".format(self.nameArch()))
			logger.info("{} simulator has been successfully built".format(self.nameArch()))

		# Run simulator
		errcode = interactiveExec(["./run.sh"], self.timeout)
		if errcode == ERRCODE_TIMEOUT:
			logger.critical("Fail to complete {} simulation due to time out".format(self.nameArch()))
			raise Exception("Fail to complete {} simulation due to time out".format(self.nameArch()))
		elif errcode:
			logger.critical("Fail to run {} simulation".format(self.nameArch()))
			raise Exception("Fail to run {} simulation".format(self.nameArch()))
		logger.info("{} simulation has been successfully completed".format(self.nameArch()))


def testOr1k(self, logger):
	""" Configure the simulatior config file and run  Or1k simulation"""

	with cd (self.simDir):
		with open("ETISS.ini") as fin, open("ETISS.temp", 'w') as fout:
			logger.info("Enter the directory: {}".format(os.path.abspath(self.simDir)))
			for line in fin:
				newLine = line
				if SW_REGEX.match(line):
					newLine = re.sub(SW_REGEX, "  sw_binary=../SW/or1k/build/code.bin" ,line)
				elif ARCH_REGEX.match(line):
					newLine = re.sub(ARCH_REGEX, "  CPUArch=or1k" ,line)
				fout.write(newLine)
		shutil.move("ETISS.temp", "ETISS.ini")
	logger.info("{} architecture simulator has been correctly configured".format(self.nameArch()))
	testArchitecure(self, logger)


#def testArmv6M(self, logger):
#	""" Configure the simulatior config file and run  Armv6M simulation"""
#
#	with cd (self.simDir):
#		logger.info("Enter the directory: {}".format(os.path.abspath(self.simDir)))
#		with open("ETISS.ini") as fin, open("ETISS.temp", 'w') as fout:
#			for line in fin:
#				newLine = line
#				if SW_REGEX.match(line):
#					newLine = re.sub(SW_REGEX, "  sw_binary=../SW/arm/build/code.bin" ,line)
#				elif ARCH_REGEX.match(line):
#					newLine = re.sub(ARCH_REGEX, "  CPUArch=ARMv6M" ,line)
#				fout.write(newLine)
#		shutil.move("ETISS.temp", "ETISS.ini")
#	logger.info("{} architecture simulator has been correctly configured".format(self.nameArch()))
#	testArchitecure(self, logger)

def testRiscv(self, logger):
	""" Configure the simulatior config file and run  Armv6M simulation"""

	with cd (self.simDir):
		with open("ETISS.ini") as fin, open("ETISS.temp", 'w') as fout:
			logger.info("Enter the directory: {}".format(os.path.abspath(self.simDir)))
			for line in fin:
				newLine = line
				if SW_REGEX.match(line):
					newLine = re.sub(SW_REGEX, "  sw_binary=../SW/riscv/build/code.bin" ,line)
				elif ARCH_REGEX.match(line):
					newLine = re.sub(ARCH_REGEX, "  CPUArch=RISCV" ,line)
				fout.write(newLine)
		shutil.move("ETISS.temp", "ETISS.ini")
	logger.info("{} architecture simulator has been correctly configured".format(self.nameArch()))
	testArchitecure(self, logger)


def generateJITScript (JIT, archTestScript):
	testArch = archTestScript
	def testJIT(self, logger):
		with cd(self.simDir):
			logger.info("Enter the directory: {}".format(os.path.abspath(self.simDir)))
			with open("ETISS.ini") as fin, open("ETISS.temp", 'w') as fout:
				for line in fin:
					newLine = line
					if JIT_REGEX.match(line):
						newLine = re.sub(JIT_REGEX, "  type="+JIT ,line)
					fout.write(newLine)
			shutil.move("ETISS.temp", "ETISS.ini")
		logger.info(Color.BOLD + Color.YELLOW +"\n\n*** Switch to {} with {} architecture ***\n"\
			.format(JIT, self.nameArch()) + Color.END)
		testArch(self, logger)
	return testJIT

def generateFilter(targetType, left = False):
	"""Generate filter function for loaded plugins"""

	def filter(plugins):
		for pi in plugins:
			if left:
				if not pi.isThisType(targetType):
					plugins.remove(pi)
					logger.info("Plugin: {} is filtered out by predefined filter"\
								.format(pi.namePlugin()))
			else:
				if pi.isThisType(targetType):
					plugins.remove(pi)
					logger.info("Plugin: {} is filtered out by predefined filter"\
								.format(pi.namePlugin()))
	return filter
