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

from FaultXML import *


fboot = Fault()
fboot.triggers_ = Trigger.timeTrigger("core0",1000000000)
fboot.actions_ = Action.commandAction("core0::OR1KVCPU","boot")



trigger = Trigger.variableValueTrigger("core0::OR1KVCPU","ex_pc",256+16+8)
trigger = Trigger.countTrigger(trigger,3)
fault = Fault()
fault.id_ = 2
fault.name_ = "TEST"
fault.actions_ = Action.bitflipAction("core0::OR1KVCPU","R1",1)
fault.triggers_ = trigger

fdeboot = Fault()
fdeboot.triggers_ = Trigger.timeRelativeTrigger("core0::OR1KVCPU",10000000) #1000 cpu cycles
fdeboot.actions_ = Action.commandAction("core0::OR1KVCPU","deboot")
fedbootact = Action.injectionAction(fdeboot)

fault.actions_.append(fedbootact)


print fault.toXML()



with open("../../../faults.xml","w+") as f:
	f.write("<faults>\n")
	f.write(fboot.toXML(offset="\t",isPartOfList=True))
	f.write("\n")
	f.write(fault.toXML(offset="\t",isPartOfList=True))
	f.write("\n</faults>")


