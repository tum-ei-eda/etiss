# Bare-Metal Simulation

This folder contains a basic example project that uses ETISS.

The corresponding target software must firstly be build for the core. These
can be found in SW subdirectory of the `examples` directory. When simulation
running, the ETISS will translate compiled binary code into host executable
code and simulate the behavior of target bare-metal core.

## Getting Started

Check the file `./ETISS.ini` to select desired architecture and plug-in
to simulate. Target software path should be explicitly given for
**sw_binary**. Also, other configuration options of ETISS are available
in this file (e.g. logger severity level).

Check README in `../SW` to assure all prerequisites are fullfilled (e.g.
setting up path to toolchain, getting required libraries, ...). You also
find the detailed instructrions to compile SW in respective directories

After checking all prerequisites, execute the following commands to build
the example software:

	$ cd ../SW/<or1k>|<riscv>/
	$ mkdir build && cd build
	$ cmake ..

### LINUX SYSTEM

	$ make

After SW compilation, we can build and run the simulation with the following script:

	$ ./run_helper.sh path/to/target/binary


  > NOTE: This script simply adds environment variables and starts the main executable
  with ETISS.ini as parameter.

### WINDOWS SYSTEM

	$ cmake --build . --config $BUILD_TYPE

Set the PATH variable to include files in the build/installed/lib/ folder and then run the program by passing required architecture, jit and plugins. An example is shown here. Please use --help to display all configurations supported.

	$ $Env:Path="X:/path/to/lib;"+$Env:Path
	$ cd build/$BUILD_TYPE

  > NOTE: $BUILD_TYPE is either Release or Debug depending on how it was compiled.)

	$ main --vp.elf_file=X:/path/to/build/installed/examples/SW/riscv/build/riscv_example --arch.cpu=RV32IMACFD --jit.type=TCCJIT --etiss.loglevel=4 -pLogger

## Debugging

### Debug ETISS

	./run_helper.sh ELFFILE gdb

### Debug target software
A **gdbserver** is integrated in ETISS, and it could be used to debug target
core when it runs target SW. The gdbserver could be enabled by configure
options in `./ETISS.ini` with this configuration:

	[Plugin gdbserver];
		plugin.gdbserver.port=<port_number_you_defined>
		minPcAlign=<minimal_instruction_bits_alignment>

The gdbserver surveilles undelying target SW, send/recieve commands
to/from target core. The ETISS simulation will be suspended at the
beginning of target SW, waiting for incoming command, if **gdbserver**
is enabled.

#### Use gdbserver

Short version:

	./run_helper.sh ELFFILE tgdb

Requires KDE "Konsole", but add option "noattach" to attach to the gdbserver manually (see below).

Long version:

Run the ETISS (main) using aformentioned script, then invoke corresponding
gdb in a new terminal. E.g. or1k-elf-gdb for or1k core. **Do not use system
default gdb directly for target core.** The target SW executable should be
given as an argument or given after entering gdb and using file command.
The executable is used to load symbol table. For example:

	$ <target_toolchain>-elf-gdb <SW_directory>/<target_SW>.elf

alternative:

	$ <target_toolchain>-elf-gdb
	$ (gdb) file <SW_directory>/<target_SW>.elf

Then you should connect gdb to gdbserver inside ETISS

	$ (gdb) target remote :<port_number_you_defined>  //local computer

or:

	$ (gdb) target remote <host_ip>:<port_number_you_defined>  // connect through internet to remote computer

As connection between gdb and gdbserver is established, standard gdb command
could be used to debug target SW.

  > RSP protocal commands (internal gdb commands) such as 'g', 'G'
  for read/write all registers, are invisible for gdb user. These commands
  cannot be recognized by gdb.

#### Using an IDE for debugging

As long as the IDE supports remote debugging with GDB, it will be able to connect to the GDBServer of ETISS.

##### Eclipse

For example use the following steps to debug with Eclipse (https://stackoverflow.com/a/45608937):

Setup:

- Get "Eclipse IDE for C/C++ Developers"
- Open Eclipse
- Menu: Run -> Debug Configurations...
- Select: C/C++ Remote Application
- Press "New Configuration" button on top
- At the bottom click on "Select other..."
- Check: Use configuration specific settings
- Select: GDB (DSF) Manual Remote Debugging Launcher
- Main tab: Enter C/C++ Application path
- Debugger tab -> Main sub-tab: Enter toolchain GDB path into "GDB debugger"
- Debugger tab -> Connection sub-tab: TCP, localhost, 2222
- Click Apply, Close

Usage:

- Run ETISS with GDBServer enabled
- Menu: Run -> Debug

##### Visual Studio Code

Create a new debugging configuration for your project by going to the debug side-view on the left. Click on the drop-down, select "Add Config (your project name)", select environment "C++ (GDB/LLDB)". Adjust the file that opens like the following:

	{
		// Use IntelliSense to learn about possible attributes.
		// Hover to view descriptions of existing attributes.
		// For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
		"version": "0.2.0",
		"configurations": [
			{
				"name": "ETISS Debug",
				"type": "cppdbg",
				"request": "launch",
				"program": "${workspaceFolder}/target_sw/bin/target_binary.elf",
				"miDebuggerServerAddress": "localhost:2222",
				"args": [],
				"stopAtEntry": false,
				"cwd": "${workspaceFolder}",
				"environment": [],
				"externalConsole": false,
				"MIMode": "gdb",
				"setupCommands": [
					{
						"description": "Enable pretty-printing for gdb",
						"text": "-enable-pretty-printing",
						"ignoreFailures": true
					}
				],
				"miDebuggerPath": "/usr/local/research/projects/SystemDesign/tools/riscv/current/bin/riscv32-unknown-elf-gdb"
			}
		]
	}

## Snapshot

The output during execution should look similar to this:

### GDB output in terminal
When utilizing **gdbserver** to debug target software.

![](gdbSnapshot.png "GDB output in terminal")

### ETISS output in terminal

![](etissSnapshot.png "ETISS output in terminal")

## Fault Injection Demo

Usage:

- ./run_helper.sh ELFFILE --faults.xml=/path/to/faults.xml

`faults.xml` Example and explanations:

```xml
<faults> <!--a faults.xml root-->
	<definitions> <!--faults are defined here and can be referenced with a <fault_ref> node-->
		<fault name="meta"> <!--a <fault> has <triggers> and <actions>-->
			<triggers>
				<trigger type="META_COUNTER"> <!--a <trigger> must have a type of {META_COUNTER, VARIABLEVALUE, TIME, TIMERELATIVE, ASAP, NOP}-->
					<count>1</count> <!--the META_COUNTER here will trigger once its subtrigger fired <count> times-->
					<trigger type="VARIABLEVALUE"> <!--a <trigger> can have a sub <trigger>, awesome!-->
						<injector>core%i%</injector> <!--the trigger type VARIABLEVALUE needs an <injector> that supplies the triggerable object, bare_etiss_processor constructs "core0" ETISS-FI will replace %i% to the core id "0" by default-->
						<field>instructionPointer</field> <!--the <field> of "core%i%" should be listened for, here, the instruction pointer-->
						<value>b0</value> <!--the <value> that <field>'s value will be compared to as a hexadecimal-->
					</trigger>
				</trigger>
			</triggers>
			<actions>
				<action type="COMMAND"> <!--an <action> must have a type of {BITFLIP, MASK, COMMAND, NOP, INJECTION, EJECTION, EVENT}, here, COMMAND-->
					<injector>core%i%</injector> <!--an <action> can have a different <injector> than its <trigger>s, which means, you could trigger on one Injector and inject into another-->
					<command>some string</command> <!--the COMMAND type is a custom string encoded action the <injector> has to implement, by default no custom actions are supported. Set VirtualStructs::applyCustomAction member to a std::function of your choice and handle the passed string-->
				</action>
				<action type="BITFLIP"> <!--why not have more than one <action>: Here, an additional "BITFLIP"-->
					<injector>core%i%</injector> <!--again we need an <injector>-->
					<field>R1</field> <!--BITFLIP and MASK takes a <field>, here R1 aka X1 in RISC-V, with the CPUCore all ISA-GPRs and the instructionPointer are <fields>-->
					<bit>1</bit> <!--the target <bit> number-->
				</action>
				<action type="INJECTION"> <!--now, we inject a new fault as our action.-->
						<fault_ref name="injected_fault"></fault_ref> <!--INJECTION and EJECTION <actions> take a <fault>'s name as the fault reference-->
				</action>
				<action type="INJECTION"> <!--now, we inject another fault that will be responsible for removing the "injected_fault" as our action.-->
						<fault_ref name="injected_fault_remove"></fault_ref> <!--"injected_fault_remove" will remove "injected_fault"-->
				</action>
			</actions>
		</fault>
		<fault name="injected_fault_remove"> <!-- here, we define the previously referenced (<fault_ref>) fault "injected_fault_remove"-->
			<triggers>
				<trigger type="META_COUNTER">
					<count>10</count>
					<trigger type="ASAP"> <!-- the "as soon as possible" <trigger> type ASAP does exactly this, it fires immediately the next time its <injector> checks all its <trigger>s-->
						<injector>core%i%</injector>
					</trigger>
				</trigger>
			</triggers>
			<actions>
					<action type="EJECTION"> <!-- the remover <action> is EJECTION, which is the antonym to the INJECTION type. Once applied all the referenced <fault>'s <trigger>s are deactivated-->
						<fault_ref name="injected_fault"></fault_ref> <!-- the fault "injected_fault" is virtually removed (because its <trigger>s are deactivated)-->
					</action>
			</actions>
		</fault>
		<fault name="injected_fault"> <!-- "injected_fault_remove" already referenced "injected_fault", although the latter was not yet defined in the XML, this is allowed.-->
			<triggers>
				<trigger type="ASAP"> <!--ASAP can also be used to model permanent faults, because ASAP holds true until the fault is EJECTED. In our case, it is a semi-permanent fault as "injected_fault_remove" ejects "injected_fault" after 10 callbacks to core%i%'s injector'-->
					<injector>core%i%</injector>
				</trigger>
			</triggers>
			<actions>
				<action type="MASK"> <!--MASK action is similar to BITFLIP as it takes a <field> as target, however, the manipulation is equal to "<field> = <field> <op> <value>" in C primitive.-->
					<injector>core%i%</injector>
					<field>R2</field>
					<op>OR</op> <!-- the MASK operation can be either of {AND, OR, XOR, NAND, NOR}, e.g. use AND to reset a <field>'s bits, OR to set, XOR to flip, .. etc.-->
					<value>0x55555555</value> <!--specify the mask <value> as hexadecimal-->
				</action>
			</actions>
		</fault>
	</definitions>
	<initial> <!--these are the initial <fault>s that are added to the simulation on start. "meta" is the only one here, but it adds additional faults during the simulation.-->
		<fault_ref name="meta"></fault_ref> <!-- like the INJECTION <action>, <initial> only takes <fault_ref>-->
	</initial>
</faults>

```
