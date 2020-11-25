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
import os
import re
import imp
import logger as lg

logger  = lg.createLogger("loaderLogger", debug = True)

class PluginLoader:

	def __init__(self, pluginsDir, logger = logger ):
		self.__filters = []
		self.__loader = None
		self.__PLUGIN_DIR = pluginsDir
		self.__logger = logger
		self.__pluginModules =  self.getPluginModules(self.__PLUGIN_DIR)

	def getPluginModules(self, pluginsDir):
		pluginModules = []
		possiblePlugins = os.listdir(pluginsDir)
		for i in possiblePlugins:
			location = os.path.join(pluginsDir, i)
			if os.path.isdir(location):
				pluginModules.extend(self.getPluginModules(location))
			elif re.match(r".*\.py$", i):
				moduleName = re.sub(r"\.py$", '', i)
				module = imp.find_module(moduleName, [pluginsDir])
				pluginModules.append({"name": moduleName, "module": module})
				self.__logger.debug("Plugin module {} is found".format(moduleName))
			else:
				self.__logger.debug("Unkown file {} in plugin directory".format(location))
		return pluginModules

	def loadPlugins(self, pluginModule):
		m = imp.load_module(pluginModule.get("name"), *pluginModule.get("module"))
		pis = self.__loader(m)
		for filter in self.__filters:
			if filter:
				filter(pis)
		return pis

	def registerloader(self, loader):
		self.__loader = loader
		self.__logger.info("Plugin loader has been successfully registered")

	def registerFilter(self, *filters):
		for f in filters:
			self.__filters.append(f)

	def load(self):
		plugins = []
		if self.__loader == None:
			self.__logger.critical("No plugin loader is registered. Plugin interface cannot be resolved")
			raise Exception("Plugin loader missing")
		for module in self.__pluginModules:
			pis = self.loadPlugins(module)
			if not pis:
				self.__logger.warning("Plugin loading in module: {} is skipped".format(module["name"]))
			else:
				plugins.extend(pis)
				self.__logger.info("Plugin loading in module: {} is finished".format(module["name"]))
		return plugins


# Unit test
if __name__ == '__main__':
	pl = PuginLoader("./plugins", logger)

	def loader(module):
		plugins = []
		# Return empty plugins list when do not have plugin
		# interface
		try:
			module.countPlugins()
		except Exception as e:
			logger.warning("Module: {} in plugin directory is not a plugin".format(module.__name__))
			return plugins
		for i in range(0, module.countPlugins()):
			pi = module.createPlugin(i)
			plugins.append(pi)
			logger.info("Plugin : {} is loaded".format(pi.namePlugin()) )
		return plugins

	def generateFilter(targetType, filterOut = True):
		def filter(plugins):
			for pi in plugins:
				if filterOut:
					if pi.isThisType(targetType):
						plugins.remove(pi)
				else:
					if not pi.isThisType(targetType):
						plugins.remove(pi)
		return filter

	pl.registerloader(loader)
	pl.registerFilter(generateFilter(pif.OR1KTESTER))
	plugins = pl.load()
	for pi in plugins:
		pi.execute(logger)
