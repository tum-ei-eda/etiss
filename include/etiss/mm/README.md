# Memory Management Unit
Memory management unit is the essential part to translate virtual memory address to physical memory address and perform memory protection.  In modern operating systems except for some Real-time Operating Systems (RTOS), the MMU support is inseparable. For example, the `Linux` kernel lives in the virtual address space after ~2000 cycles. It is quite early in terms of the kernel execution. Meanwhile, ETISS is designed to be an Instruction Set Simulation framework, so that the MMU implementation should follow the philosophy as well, to be extendable for other architectures. 

## Page Table Entry (PTE)
The Page Table Entry (PTE) format is architecture-dependent which specifies the bit field for protection flags and the Physical Page Number. During memory protection check and page table walking, these bit fields will be frequently checked, read or written. In order to mitigate bit manipulation for PTE, a ***PTEFormatBuilder*** and a ***PTEFormat*** singleton class are integrated into ETISS. With simple syntax, PTE format could be easily modeled and every PTE can be manipulated with the bit field name specified by the builder.  A brief example is given in the following.

```cpp
// Bit field for Page Table Entry (PTE)
PTEFormatBuilder::Instance().AddPPNBitField(53,10).AddFlag("D",7).
							AddFlag("A",6).AddFlag("G",5).AddFlag("U",4).
							AddFlag("X",3).AddFlag("W",2).AddFlag("R",1).
							AddFlag("V",0).AddFlag("MODE",63,60).
							AddFlag("ASID",59,44);
```

##Translation Lookaside Table (TLB)
The MMU would typically introduce overhead for the memory access because it accommodates in the middle way between the core and caches. Thanks to the locality property of the memory access, we could add a Translation Lookaside Buffer (TLB) in MMU to expedite **virtual to physical address translation**. The MMU translation would look up TLB at first to find whether virtual to physical address mapping is cached in TLB. If so the protection flags are checked to validate the memory access. Afterward, the `Physical Page Number (PPN)` will be extracted from the found PTE and added by page offset to obtain the physical address.  When the mapping is not located in TLB, page talk walking functionalities will be invoked to perform actual translation and then cache the mapping into TLB. 

## Fault handling in the MMU
Considering that complex MMUs are probably designed in the future, the MMU has implemented a light-weight `fault handler system`. If an unexpected issue happens in the PTE manipulation or in the TLB operation, an MMU specific fault will be thrown until the MMU catch the fault and try to handle it. When the MMU does not handle it, it will further throw out the ETISS-specific fault to the simulator. This design is useful since it leaves an interface to configure MMU with the various feature. 

## Future work
In most design, the cache is located after the MMU (physically tagged physically indexed) or in parallel with the MMU (physically tagged virtually indexed). In ETISS, data access is not cached, so it would not burden the MMU at all. However,  ETISS caches instructions to speed up the simulation. The best attempt is to make ETISS instruction cache as widely adopted **physically addressed cache**. Nevertheless, since ETISS caches the compiled binary code as shared libraries, and uses both physical address and current pc, it is impossible to use the cache merely with the physical address. The most straightforward solution is to disable cache at all, which will introduce significant penalty while every instruction has to be repeatedly  translated and compiled by `Just-In-Time (JIT)` compiler. Redesigning the instruction cache means to modify the whole `Dynamic Binary Translation (DBT)` infrastructure in ETISS, which is quite risky when designing the MMU.  An alternative is to introduce the rarely used **virtually addressed cache**. Since only the instructions are cached, and we are targeting to run a single kernel process, it could be a temporary workaround. However, it should be upgraded to **physically addressed cache** to run a full kernel stack.