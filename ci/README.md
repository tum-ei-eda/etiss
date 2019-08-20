# Continuous Integration for ETISS

In the parent directory, `.gitlab-ci.yml` is given to configure CI/CD pipeline for 
the ETISS gitlab repository. Besides, python scripts provided in this directory 
is the tester which undertakes the testing jobs. The python-based tester is 
independent of gitlab CI/CD infrastructure, and could be invoked to conduct test 
with the command:

	$ python3 Tester.py
	
## Tester

The Tester is structured as a light-weight plugin architecture. It will load 
plugins in `./plugins` directory according to given flags and build up customized 
tester. Each plugin is a sub-tester will has specific purpose, for instance testing 
GDB. Above all, the Tester is written in python 3 syntax; be ensured that it is 
executed with **python3**.

### How to use

> NOTE: The working directory has to be `ci`, otherwise plugins cannot be loaded

With aforementioned command, the Tester will load all plugins in `./plugins` 
directory and execute them all. The `-arch` flag is provided to select certain 
architecture to test, while `-to` could be used to set timeout boundary for 
simulation. For example:

	$ python3 Tester.py -arch RISCV -to 42
	
This setting would force the Tester to select **RISCV** architecture relevant 
plugin and filter others out. Simulation time for RISCV architecture is limited 
to **42 seconds**. If it exceeds the timeout boundary, timeout exception will be 
raised.

Meanwhile a `-gdb` flag could use to enable gdb test, like:
	
	$ python3 Tester.py -arch RISCV -gdb
	
Gdb testing makes sense only if architecture simulation is guaranteed. Consequently, 
gdb testing should be conducted after architecture testing succeed and `-gdb` 
flag will disable architecture testing

### How to Add New Features 

It is recommendable to implement new plugin rather than hack `tester.py` when 
adding new features to the Tester. The plugin module should following certain 
interface in order to be successfully plugged in. See scripts in `./plugins` for 
examples. Meanwhile, `pluginInterface.py` provides some simple class interfaces 
used to characterize plugin for specific purpose
