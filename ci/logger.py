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
import logging

def createLogger(name, debug = False):
	logger = logging.getLogger(name)
	logger.setLevel(logging.DEBUG)

	# create file handler which logs even info messages
	infoHandler = logging.FileHandler('tester.log', mode = 'w')
	infoHandler.setLevel(logging.INFO)

	# create console handler with a higher log level to print error on screen
	errorHandler = logging.StreamHandler()
	if debug:
		errorHandler.setLevel(logging.DEBUG)
	else:
		errorHandler.setLevel(logging.INFO)

	# create formatter and add it to the handlers
	formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
	infoHandler.setFormatter(formatter)
	errorHandler.setFormatter(formatter)

	# add the handlers to the logger
	logger.addHandler(infoHandler)
	logger.addHandler(errorHandler)

	return logger

# Unit test
if __name__ == '__main__':
	logger = createLogger("testLogger")
	logger.info("info severity level test")
	logger.warning("warning severity level test")
	logger.error("error severity level test")
