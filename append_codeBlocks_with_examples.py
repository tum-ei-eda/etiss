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

import sys
import os
import xml.etree.ElementTree as ET

# check param for file
if len(sys.argv) != 2:
    print 'usage: python append_codeblocks_with_examples.py <cb_file>'
    sys.exit()

cb_file = sys.argv[1]
if not os.path.exists(cb_file):
    print 'File does not excist!'
    sys.exit()

# xml string for target fault_injection
fault_injection = ET.fromstring(
'			<Target title="fault_injection">\n\
				<Option output="installed/examples/fault_injection_new/vp/build_dir/main" prefix_auto="0" extension_auto="0" />\n\
				<Option working_dir="installed/examples/fault_injection_new/vp" />\n\
				<Option object_output="installed/examples/fault_injection_new/vp/build_dir" />\n\
				<Option type="1" />\n\
				<Option compiler="gcc" />\n\
				<Option parameters="  -iini/ETISS.ini -iini/OR1KVCPU.ini -iini/faultInjection.ini -ofaultInjection::sw_binary ../../SW/or1k/build/code.bin" />\n\
				<Compiler>\n\
					<Add option="-DETISS_DEBUG=0" />\n\
					<Add option="-DSC_INCLUDE_DYNAMIC_PROCESSES" />\n\
				</Compiler>\n\
				<ExtraCommands>\n\
					<Add before="make install" />\n\
					<Add before="make install" />\n\
					<Add before="cd installed/examples/SW/arm; make" />\n\
					<Add before="cd installed/examples/SW/or1k; make" />\n\
					<Add before="cd installed/examples/fault_injection_new/vp; make" />\n\
				</ExtraCommands>\n\
				<MakeCommands>\n\
					<Build command="make -C &quot;installed/examples/fault_injection_new/vp/build_dir/&quot; main" />\n\
					<CompileFile command="make -C &quot;installed/examples/fault_injection_new/vp/build_dir/&quot;  VERBOSE=1 &quot;$file&quot;" />\n\
					<Clean command="make -C &quot;installed/examples/fault_injection_new/vp/build_dir/&quot;  VERBOSE=1 clean" />\n\
					<AskRebuildNeeded command="make -q -C &quot;installed/examples/fault_injection_new/vp/build_dir/&quot; main" />\n\
					<SilentBuild command="make -C &quot;installed/examples/fault_injection_new/vp/build_dir&quot; main &gt; $(CMD_NULL)" />\n\
				</MakeCommands>\n\
			</Target>\n')

# xml string for target fault_injection
fault_injection_DualCPU = ET.fromstring(
'			<Target title="fault_injection_DualCPU">\n\
				<Option output="installed/examples/fault_injection_new/vp/build_dir/mainDualCPU" prefix_auto="0" extension_auto="0" />\n\
				<Option working_dir="installed/examples/fault_injection_new/vp" />\n\
				<Option object_output="installed/examples/fault_injection_new/vp/build_dir" />\n\
				<Option type="1" />\n\
				<Option compiler="gcc" />\n\
				<Option parameters="  -iini/ETISS.ini -iini/OR1KVCPU.ini -iini/faultInjection.ini -ofaultInjection::sw_binary ../../SW/or1k/build/code.bin" />\n\
				<Compiler>\n\
					<Add option="-DETISS_DEBUG=0" />\n\
					<Add option="-DSC_INCLUDE_DYNAMIC_PROCESSES" />\n\
				</Compiler>\n\
				<ExtraCommands>\n\
					<Add before="make install" />\n\
					<Add before="make install" />\n\
					<Add before="cd installed/examples/SW/arm; make" />\n\
					<Add before="cd installed/examples/SW/or1k; make" />\n\
					<Add before="cd installed/examples/fault_injection_new/vp; make" />\n\
				</ExtraCommands>\n\
				<MakeCommands>\n\
					<Build command="make -C &quot;installed/examples/fault_injection_new/vp/build_dir/&quot; mainDualCPU" />\n\
					<CompileFile command="make -C &quot;installed/examples/fault_injection_new/vp/build_dir/&quot;  VERBOSE=1 &quot;$file&quot;" />\n\
					<Clean command="make -C &quot;installed/examples/fault_injection_new/vp/build_dir/&quot;  VERBOSE=1 clean" />\n\
					<AskRebuildNeeded command="make -q -C &quot;installed/examples/fault_injection_new/vp/build_dir/&quot; mainDualCPU" />\n\
					<SilentBuild command="make -C &quot;installed/examples/fault_injection_new/vp/build_dir/&quot; mainDualCPU &gt; $(CMD_NULL)" />\n\
				</MakeCommands>\n\
			</Target>\n')

# xml string for target bare_etiss_processor
bare_etiss_processor = ET.fromstring(
'			<Target title="bare_etiss_processor">\n\
				<Option output="installed/examples/bare_etiss_processor/build/main" prefix_auto="0" extension_auto="0" />\n\
				<Option working_dir="installed/examples/bare_etiss_processor" />\n\
				<Option object_output="installed/examples/bare_etiss_processor/build/" />\n\
				<Option type="1" />\n\
				<Option compiler="gcc" />\n\
				<Option parameters="  -iETISS.ini " />\n\
				<Compiler>\n\
					<Add option="-DETISS_DEBUG=0" />\n\
					<Add option="-DSC_INCLUDE_DYNAMIC_PROCESSES" />\n\
				</Compiler>\n\
				<ExtraCommands>\n\
					<Add before="make install" />\n\
					<Add before="make install" />\n\
					<Add before="cd installed/examples/SW/arm; make" />\n\
					<Add before="cd installed/examples/SW/or1k; make" />\n\
					<Add before="cd installed/examples/bare_etiss_processor/build; cmake -DCMAKE_BUILD_TYPE=Debug .." />\n\
				</ExtraCommands>\n\
				<MakeCommands>\n\
					<Build command="make -C &quot;installed/examples/bare_etiss_processor/build/&quot; ./main" />\n\
					<CompileFile command="make -C &quot;installed/examples/bare_etiss_processor/&quot;  VERBOSE=1 &quot;$file&quot;" />\n\
					<Clean command="make -C &quot;installed/examples/bare_etiss_processor/&quot;  VERBOSE=1 clean" />\n\
					<AskRebuildNeeded command="make -q -C &quot;installed/examples/bare_etiss_processor/build/&quot; ./main" />\n\
					<SilentBuild command="make -C &quot;installed/examples/bare_etiss_processor/build/&quot; ./main &gt; $(CMD_NULL)" />\n\
				</MakeCommands>\n\
			</Target>\n')



# xml string for files in example fault_injection_new
AddPcTraceLoggerPlugin = ET.fromstring(
'		<Unit filename="../examples/fault_injection_new/vp/ProjectSpecificPlugins/AddPcTraceLoggerPlugin.h">\n\
			<Option target="fault_injection" />\n\
		</Unit>\n')
BootAndInjectionCallbackPlugin = ET.fromstring(
'		<Unit filename="../examples/fault_injection_new/vp/ProjectSpecificPlugins/BootAndInjectionCallbackPlugin.h">\n\
			<Option target="fault_injection" />\n\
		</Unit>')
ExitOnInfloopPlugin = ET.fromstring(
'		<Unit filename="../examples/fault_injection_new/vp/ProjectSpecificPlugins/ExitOnInfloopPlugin.h">\n\
			<Option target="fault_injection" />\n\
		</Unit>')
SynchronizeCPUs_h = ET.fromstring(
'		<Unit filename="./examples/fault_injection_new/vp/ProjectSpecificPlugins/SynchronizeCPUs.h">\n\
			<Option target="fault_injection_DualCPU" />\n\
		</Unit>')
SynchronizeCPUs_cpp = ET.fromstring(
'		<Unit filename="./examples/fault_injection_new/vp/ProjectSpecificPlugins/SynchronizeCPUs.cpp">\n\
			<Option target="fault_injection_DualCPU" />\n\
		</Unit>')
InstructionCounterPlugin = ET.fromstring(
'		<Unit filename="../examples/fault_injection_new/vp/ProjectSpecificPlugins/InstructionCounterPlugin.h">\n\
			<Option target="fault_injection" />\n\
		</Unit>')
fault_injection_new_main = ET.fromstring(
'		<Unit filename="../examples/fault_injection_new/vp/main.cpp">\n\
			<Option target="fault_injection" />\n\
		</Unit>')
fault_injection_DualCPU_main = ET.fromstring(
'		<Unit filename="../examples/fault_injection_new/vp/mainDualCPU.cpp">\n\
			<Option target="fault_injection_DualCPU" />\n\
		</Unit>')



# xml string for files in example bare_etiss_processor
bare_etiss_processor_main = ET.fromstring(
'		<Unit filename="../examples/bare_etiss_processor/main.cpp">\n\
			<Option target="fault_injection" />\n\
		</Unit>')



# Open original file
cb_tree = ET.parse(cb_file)
cb_root = cb_tree.getroot()

# add example build target fault_injection_new
build = cb_root.find('Project').find('Build')
found = False
for target in build.findall("Target[@title='fault_injection']"):
    print 'Target fault_injection already excists!'
    found = True
if (not found):
    print 'Added target fault_injection.'
    build.append(fault_injection)

# add example build target fault_injection_new
found = False
for target in build.findall("Target[@title='fault_injection_DualCPU']"):
    print 'Target fault_injection_DualCPU already excists!'
    found = True
if (not found):
    print 'Added target fault_injection_DualCPU.'
    build.append(fault_injection_DualCPU)

# add example build target bare_etiss_processor
found = False
for target in build.findall("Target[@title='bare_etiss_processor']"):
    print 'Target bare_etiss_processor already excists!'
    found = True
if (not found):
    print 'Added target bare_etiss_processor.'
    build.append(bare_etiss_processor)



# add files of example fault_injection_new to project
project = cb_root.find('Project')
found = False
for unit in project.findall("Unit[@filename='../examples/fault_injection_new/vp/ProjectSpecificPlugins/AddPcTraceLoggerPlugin.h']"):
    print 'Unit AddPcTraceLoggerPlugin.h already excists!'
    found = True
if (not found):
    print 'Added file AddPcTraceLoggerPlugin.h.'
    project.append(AddPcTraceLoggerPlugin)
found = False
for unit in project.findall("Unit[@filename='../examples/fault_injection_new/vp/ProjectSpecificPlugins/BootAndInjectionCallbackPlugin.h']"):
    print 'Unit BootAndInjectionCallbackPlugin.h already excists!'
    found = True
if (not found):
    print 'Added file BootAndInjectionCallbackPlugin.h.'
    project.append(BootAndInjectionCallbackPlugin)
found = False
for unit in project.findall("Unit[@filename='../examples/fault_injection_new/vp/ProjectSpecificPlugins/ExitOnInfloopPlugin.h']"):
    print 'Unit ExitOnInfloopPlugin.h already excists!'
    found = True
if (not found):
    print 'Added file ExitOnInfloopPlugin.h.'
    project.append(ExitOnInfloopPlugin)
found = False
for unit in project.findall("Unit[@filename='../examples/fault_injection_new/vp/ProjectSpecificPlugins/SynchronizeCPUs.h']"):
    print 'Unit SynchronizeCPUs.h already excists!'
    found = True
if (not found):
    print 'Added file SynchronizeCPUs.h.'
    project.append(SynchronizeCPUs_h)
found = False
for unit in project.findall("Unit[@filename='../examples/fault_injection_new/vp/ProjectSpecificPlugins/SynchronizeCPUs.cpp']"):
    print 'Unit SynchronizeCPUs.cpp already excists!'
    found = True
if (not found):
    print 'Added file SynchronizeCPUs.h.'
    project.append(SynchronizeCPUs_cpp)
found = False
for unit in project.findall("Unit[@filename='../examples/fault_injection_new/vp/ProjectSpecificPlugins/InstructionCounterPlugin.h']"):
    print 'Unit InstructionCounterPlugin.h already excists!'
    found = True
if (not found):
    print 'Added file InstructionCounterPlugin.h.'
    project.append(InstructionCounterPlugin)
found = False
for unit in project.findall("Unit[@filename='../examples/fault_injection_new/vp/main.cpp']"):
    print 'Unit fault_injection_new/vp/main.cpp already excists!'
    found = True
if (not found):
    print 'Added file main.cpp.'
    project.append(fault_injection_new_main)
    project.append(InstructionCounterPlugin)
found = False
for unit in project.findall("Unit[@filename='../examples/fault_injection_new/vp/mainDualCPU.cpp']"):
    print 'Unit fault_injection_new/vp/mainDualCPU.cpp already excists!'
    found = True
if (not found):
    print 'Added file mainDualCPU.cpp.'
    project.append(fault_injection_DualCPU_main)



# add files of example fault_injection_new to project
found = False
for unit in project.findall("Unit[@filename='../examples/bare_etiss_processor/main.cpp']"):
    print 'Unit bare_etiss_processor/main.cpp already excists!'
    found = True
if (not found):
    project.append(bare_etiss_processor_main)



# Write back to file
#et.write('file.xml')
cb_tree.write(cb_file)
