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
import argparse
import logger as lg
import pluginInterface as pif
from PluginLoader import PluginLoader
from Color import Color


if __name__ == '__main__':

	parser = argparse.ArgumentParser(description='Testers used to conduct ETISS test, could be \
												done via Continuous Integration or manually ')
	parser.add_argument('-arch', metavar='Architectures', nargs=1, \
						help='Select one architecture to be tested. Available: Or1k, RISCV. \n')#add Armv6M for ARM

	parser.add_argument('-to', metavar='timeout', type=int, nargs=1, \
						help='Set timeout for simulation in seconds. (Default: 55) \n')

	parser.add_argument('-gdb', action='store_const', const = True, default = False,\
						help='Enable GDB-tester-only with this flag set. \n')

	args = parser.parse_args()

	targetArch = None

	if args.arch:
		targetArch = {"Or1k":pif.OR1KTESTER,\
					  "RISCV":pif.RISCVTESTER} [args.arch[0]] #add "Armv6M": pif.ARMV6MTESTER,\ for ARM

	timeout = 55

	if args.to:
		timeout = int(args.to[0])

	disableGDB = True

	if args.gdb:
		disableGDB = False


	SIM_DIR = "../build_dir/installed/examples/bare_etiss_processor/"
	SW_DIR = "../build_dir/installed/examples/SW/"

	PLUGIN_DIR = "./plugins"
	# kwargs is the argument dict which will be passed to all createPlugins() function
	# and specific createPlugins() will pick up arguments in need.
	kwargs = {"Or1kSwDir": SW_DIR + "/or1k",\
			  "Or1kSimDir":SIM_DIR ,\
			  "RiscvSwDir": SW_DIR + "/riscv",\
                          "RiscvSimDir": SIM_DIR ,\
			  # timeout in seconds for simulator, 0 indicates timeout disabled
			  "timeout": timeout
				}# add "Armv6MSwDir": SW_DIR + "/arm",\	"Armv6MSimDir": SIM_DIR ,\ for ARM
	logger  = lg.createLogger("CITesterLogger")
	pl = PluginLoader(PLUGIN_DIR, logger)

	def loader(module):
		"""This functions handles with plugin interface to create plugin"""

		plugins = []
		# Return empty plugins list when do not have plugin
		# interface
		try:
			module.countPlugins()
		except Exception as e:
			logger.warning("Module: {} in plugin directory is not a plugin".format(module.__name__))
			return plugins
		for i in range(0, module.countPlugins()):
			pi = module.createPlugin(i, **kwargs)
			if (pi):
				plugins.append(pi)
				logger.info("Plugin: {} is loaded".format(pi.namePlugin()) )
		return plugins

	def generateFilter(targetType, left = False):
		"""Generate filter function for loaded plugins"""

		def filter(plugins):
			pulginsToRemove = []
			for pi in plugins:
				if left:
					if not pi.isThisType(targetType):
						pulginsToRemove.append(pi)
				else:
					if pi.isThisType(targetType):
						pulginsToRemove.append(pi)
			for pi in pulginsToRemove:
				plugins.remove(pi)
				logger.info("Plugin: {} is filtered out by predefined filter"\
									.format(pi.namePlugin()))
		return filter

	pl.registerloader(loader)

	if targetArch:
		pl.registerFilter(generateFilter(targetArch, True))

	if disableGDB:
		pl.registerFilter(generateFilter(pif.GDBTESTER))
	else:
		pl.registerFilter(generateFilter(pif.GDBTESTER, True))


	plugins = pl.load()

	logger.info(Color.BOLD + Color.BLUE + "\n\n==============     Tester starts     ==============\n" + Color.END)
	for pi in plugins:
		if pi:
			# NOTE: pi has to be explicitly given as first argument!
			pi.execute(pi, logger)
	logger.info(Color.BOLD + Color.BLUE + "\n\n==============     Tester ends with success     ==============\n" +Color.END)
