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

import pprint

class Trigger(object):
	__isfrozen = False
	def __setattr__(self, key, value):
		if self.__isfrozen and key == '_type':
			raise Exception( "cannot change type of Trigger")
		if self.__isfrozen and not hasattr(self, key):
			raise TypeError( "no such field: %r" % key )
		object.__setattr__(self, key, value)

	def __init__(self,type_,time_ps=None,trigger=None,count=None,injector=None,field=None,value=None):
		self._type = type_
		if self._type == "TIME":
			self._injector = str(injector)
			self._time_ps = long(time_ps)
		elif self._type == "VARIABLEVALUE":
			self._injector = str(injector)
			self._field = str(field)
			self._value = long(value)
		elif self._type == "META_COUNTER":
			if not isinstance(trigger,Trigger):
				raise TypeError("trigger must be of type Trigger")
			self._sub = trigger
			self._count = long(count)
		elif self._type == "TIMERELATIVE":
			self._injector = str(injector)
			self._time_ps = long(time_ps)
		elif self._type == "NOP":
			pass
		else:
			raise Exception("invalid Trigger object. use static constructor methods to creat a valid trigger")
		self.__isfrozen = True

	def _get_type(self):
		return self._type

	type_ = property(_get_type)

	@staticmethod
	def nopTrigger():
		return Trigger(type_="NOP")

	@staticmethod
	def timeTrigger(injector_,time_ps_):
		return Trigger(type_="TIME",injector=injector_,time_ps=time_ps_)
	@staticmethod
	def timeRelativeTrigger(injector_,time_ps_):
		return Trigger(type_="TIMERELATIVE",injector=injector_,time_ps=time_ps_)

	@staticmethod
	def variableValueTrigger(injector_,field_,value_):
		return Trigger(type_="VARIABLEVALUE",injector=injector_,field=field_,value=value_)

	@staticmethod
	def countTrigger(trigger_,count_):
		return Trigger(type_="META_COUNTER",trigger=trigger_,count=count_)

	def toXML(self,offset="\t"):
		ret = offset + "<trigger type=\"" + self._type + "\">\n"
		if self._type == "META_COUNTER":
			ret += offset + "\t" + "<count>" + str(self._count) + "</count>\n"
			ret += self._sub.toXML(offset+"\t") + "\n"
		elif self._type == "VARIABLEVALUE":
			ret += offset + "\t" + "<injector>"+ self._injector+"</injector>\n"
			ret += offset + "\t" + "<field>"+ self._field+"</field>\n"
			ret += offset + "\t" + "<value>"+ str(self._value)+"</value>\n"
		elif self._type == "TIME":
			ret += offset + "\t" + "<injector>"+ self._injector+"</injector>\n"
			ret += offset + "\t" + "<time_ps>"+ str(self._time_ps)+"</time_ps>\n"
		elif self._type == "TIMERELATIVE":
			ret += offset + "\t" + "<injector>"+ self._injector+"</injector>\n"
			ret += offset + "\t" + "<time_ps>"+ str(self._time_ps)+"</time_ps>\n"
		elif self._type == "NOP":
			pass
		else:
			raise Exception("invalid Trigger object. use static constructor methods to creat a valid trigger")
		ret += offset + "</trigger>"

		return ret


class Action(object):
	__isfrozen = False
	def __setattr__(self, key, value):
		if self.__isfrozen and not hasattr(self, key):
			raise TypeError( "no such field: %r" % key )
		object.__setattr__(self, key, value)

	def __init__(self,type_,injector=None,field=None,bit=None,idd=None,command=None,fault=None):
		if not isinstance(type_,basestring):
			raise TypeError("action type must be a string")
		if idd is not None:
			if not isinstance(id_,( int, long ) ):
				raise TypeError("action id must be int")
		self._type = type_
		self._name = None
		self._id = idd
		if self._type == "NOP":
			pass
		elif self._type == "BITFLIP":
			self._injector = str(injector)
			self._field = str(field)
			self._bit = int(bit)
		elif self._type == "COMMAND":
			self._injector = str(injector)
			self._command = command
		elif self._type == "INJECTION":
			if not isinstance(fault,Fault):
				raise TypeError("action of type INJECTION needs a fault object")
			self._fault = fault
		else:
			raise Exception("unknown type. use static methods to construct a valid action.")
		self.__isfrozen = True


	def _get_id(self):
		return self._id
	def _set_id(self, value):
		if not isinstance(value, int):
			raise TypeError("id must be set to an integer")
		self._id = value
	id_ = property(_get_id, _set_id)

	def _get_name(self):
		return self._name
	def _set_name(self, value):
		if value is not None:
			str(value)
		self._name = value
	name_ = property(_get_name, _set_name)

	def _get_type(self):
		return self._type
	def _set_type(self,val):
		raise Exception("type cannot be changed")
	type_ = property(_get_type, _set_type)

	def _get_target(self):
		return self._target
	def _set_target(self,value):
		if not isinstance(value, Target):
			raise TypeError("target can only be set to a valid Target object")
		self._target = value
	target_ = property(_get_target,_set_target)

	@staticmethod
	def nopAction():
		return Action(type_="NOP")

	@staticmethod
	def bitflipAction(injector_,field_,bit_):
		return Action(type_="BITFLIP",injector=injector_,field=field_,bit=bit_)

	@staticmethod
	def commandAction(injector_,command_):
		return Action(type_="COMMAND",injector=injector_,command=command_)

	@staticmethod
	def injectionAction(fault_):
		return Action(type_="INJECTION",fault=fault_)

	def toXML(self,offset = "\t"):
		ret = offset + '<action'
		if self.id_ is not None:
			ret += ' id=\"' + str(self.id_) + "\""
		if self.name_ is not None:
			ret += ' name=\"' + str(self.name_) + '\"'
		ret += ' type=\"' + str(self.type_) + '\"'

		ret += '>\n'
		if self._type == "NOP":
			pass
		elif self._type == "BITFLIP":
			ret += offset + "\t<injector>"+self._injector+"</injector>\n"
			ret += offset + "\t<field>"+self._field+"</field>\n"
			ret += offset + "\t<bit>"+str(self._bit)+"</bit>\n"
		elif self._type == "COMMAND":
			ret += offset + "\t<injector>"+self._injector+"</injector>\n"
			ret += offset + "\t<command>"+self._command+"</command>\n"
		elif self._type == "INJECTION":
			ret += self._fault.toXML(offset+"\t",isPartOfList=True) + "\n"
		else:
			raise Exception("cannot convert unknown action type to XML")
		ret += offset +'</action>'
		return ret




class Fault(object):
	__isfrozen = False
	def __setattr__(self, key, value):
		if self.__isfrozen and not hasattr(self, key):
			raise TypeError( "no such field: %r" % key )
		object.__setattr__(self, key, value)

	def __init__(self):
		self._id = None
		self._name = None
		self._actions = []
		self._triggers = []
		self.__isfrozen = True

	def __repr__(self):
		return self.toXML()


	def _get_id(self):
		return self._id
	def _set_id(self, value):
		if not isinstance(value, int):
			raise TypeError("id must be set to an integer")
		self._id = value
	id_ = property(_get_id, _set_id)

	def _get_name(self):
		return self._name
	def _set_name(self, value):
		if value is not None:
			str(value)
		self._name = value
	name_ = property(_get_name, _set_name)

	def _get_actions(self):
		return self._actions
	def _set_actions(self,value):
		self._actions = None
		if value is not None:
			if isinstance(value,Action):
				self._actions = [value]
			else:
				self._actions = []
				for v in value:
					if not isinstance(value,Action):
						raise TypeError("only objects of type Action can be passed")
					else:
						self._actions.append(v)
		else:
			self._actions = []

	actions_ = property(_get_actions,_set_actions)

	def _get_triggers(self):
		return self._triggers
	def _set_triggers(self,value):
		self._triggers = None
		if value is not None:
			if isinstance(value,Trigger):
				self._triggers = [value]
			else:
				self._triggers = []
				for v in value:
					if not isinstance(value,Trigger):
						raise TypeError("only objects of type Trigger can be passed")
					else:
						self._triggers.append(v)
		else:
			self._triggers = []


	triggers_ = property(_get_triggers,_set_triggers)

	def toXML(self,offset = "",isPartOfList=False):
		ret = ""
		ooffset = offset
		if not isPartOfList:
			ret += offset + "<faults>\n"
			offset += "\t"
		ret += offset + "<fault"
		if self.id_ is not None:
			ret += offset + " id=\""+str(self.id_)+"\""
		if self.name_ is not None:
			ret += " name=\"" + str(self.name_) + "\""
		ret += ">\n"
		ret += offset+"\t<triggers>\n"
		for trig in self.triggers_:
			ret += trig.toXML(offset+"\t\t") + "\n"
		ret += offset+"\t</triggers>\n"
		ret += offset+"\t<actions>\n"
		for act in self.actions_:
			ret += act.toXML(offset+"\t\t") + "\n"
		ret += offset+"\t</actions>\n"
		ret += offset + "</fault>"
		if not isPartOfList:
			ret += ooffset + "\n</faults>"
		return ret



