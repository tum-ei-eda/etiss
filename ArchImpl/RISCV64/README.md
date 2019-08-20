# 32-bit/64-bit RISC-V architecture

The 32-bit/64-bit RISC-V architecture is generated from a `code generation flow` based on **M2isar** metamodel. Currently, 32-bit architecture is featured with M, C, A extension, while 64-bit architecture with M, A extension. Both are capable of exception/interrupt handling. Detailed features are listed in the following.

|                             |32-bit Architecture | 64-bit Architecture
|-----------------------------|---------------------------|-----------------------------|
Machined/Supervisor/User mode	| 	√	                      |√                           |
Compressed instruction extension	| √                       |                           |
Multiplication and Division extension |	√                  |√                           |
Atomic instruction extension   |√                          |√                          | 
Exception/Interrupt handling|	√                            | √                          | 
Exception/Interrupt delegation|√                          | √                          |
Memory protection	|                          | √                          | 
Virtual memory translation	|                          | √                          | 
GDB support|√                          |            
SytemC/TLB2.0 Library support|√                          |        |
Variable-length instruction| √                          | √                          | 
		
## Sv39 virtual memory system for 64-bit architecture
 A hardware `page table walker` is defined in the RISC-V privileged manual.There are three page-based virtual memory systems available for RISC-V: Sv32 for 32-bit architecture while Sv39 and Sv48 for 64-bit. RISC-V adopts widely accepted 4KiB as the page size for all three systems while the super pages are supported in parallel for the large page translation. As 64-bit architecture is adopted to support Linux, the Sv39 virtual memory system is selected to implement for 64-bit architecture.
 
## Manual modification & optimization
The generated architecture model accommodates the basic computational and control instructions. However, some ETISS-specific functionalities should be added manually.

### Modification

- The functions in header file `RISCVArchSpecificImp.h` should be implemented manually if in need, such as exception handling, variable-length instruction, etc.

- System call and software interrupt that change the control flow should return ETISS-specific exception in architecture model

- Memory Management Unit (MMU) should be implemented manually

- SATP csr write should notify MMU explicitly

- GDBCore should be manually modified, if it is supposed to add GDB support

### Optimization

- Only jumps need return at the end of behavior model. The `code generation flow` adds redundant return for each instruction for integrity, which could be eliminate to optimize non-jump instructions.

- Behavior model for each instruction could be tuned manually to improve performance 
