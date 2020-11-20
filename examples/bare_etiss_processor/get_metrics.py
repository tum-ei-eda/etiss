#!/usr/bin/env python

import sys
import csv
import humanize
import elftools.elf.elffile as elffile
from elftools.elf.constants import SH_FLAGS
from elftools.elf.sections import SymbolTableSection


'''
Script to gather metrics on ROM,RAM,Stack and Heap usage.

To produce the memory trace:
- Compile etissvp_lib with SC_MEM_WRITE_TRACE defined (simple: uncomment at top of mem.cpp)
- Invoke the run.sh script with the "nodmi" option
- A file "pulpino_soc.dmem_memtrace.csv" should have been created

Then run this script:
> ./get_metrics.py ../bin/TARGET_ELF_FILE
'''


RAM_START = 0x100000
RAM_SIZE = 0x200000
STACK_SIZE = 0x4000


class MemRange:
    def __init__(self, name, min, max):
        self.name = name
        self.min = min
        self.max = max
        self.count = 0
        self.low = 0xffffffff
        self.high = 0

    def contains(self, adr):
        return adr >= self.min and adr < self.max

    def trace(self, adr):
        self.low = min(adr, self.low)
        self.high = max(adr, self.high)
        self.count = self.count + 1

    def count(self):
        return self.count

    def usage(self):
        if self.low > self.high:
            return 0
        return self.high - self.low

    def stats(self):
        if self.low > self.high:
            return self.name + "\t[not accessed]"
        return self.name + "\t[" + hex(self.low) + "-" + hex(self.high) + "] \t(" + str(self.count) + " times)"


def parseElf(inFile):
    m = {}
    m["rom_rodata"] = 0
    m["rom_code"] = 0
    m["rom_misc"] = 0
    m["ram_data"] = 0
    m["ram_zdata"] = 0
    heapStart = None

    ignoreSections = ["", ".stack", ".comment", ".riscv.attributes", ".strtab", ".shstrtab"]

    with open(inFile, "rb") as f:
        e = elffile.ELFFile(f)

        for s in e.iter_sections():
            if s.name.startswith(".text"):
                m["rom_code"] += s.data_size
            elif s.name.startswith(".srodata"):
                m["rom_rodata"] += s.data_size
            elif s.name.startswith(".sdata"):
                m["ram_data"] += s.data_size
            elif s.name == ".rodata":
                m["rom_rodata"] += s.data_size
            elif (s.name == ".vectors" or
                s.name == ".init_array"):
                m["rom_misc"] += s.data_size
            elif s.name == ".data":
                m["ram_data"] += s.data_size
            elif s.name == ".bss" or s.name == ".sbss" or s.name == ".shbss":
                m["ram_zdata"] += s.data_size
            elif s.name.startswith(".gcc_except"):
                pass
            elif s.name.startswith(".sdata2"):
                pass
            elif s.name.startswith(".debug_"):
                pass
            elif s.name in ignoreSections:
                pass
            elif isinstance(s, SymbolTableSection):
                for sym in s.iter_symbols():
                    if sym.name == "_heap_start":
                        heapStart = sym["st_value"]
            else:
                print("warning: ignored: " + s.name + " / size: " + str(s.data_size))

    return m, heapStart


def printSz(sz):
    return humanize.naturalsize(sz) + " (" + hex(sz) + ")"


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Too few arguments\nUsage: " + sys.argv[0] + " elfFile [traceFile]")
        exit(1)

    elfFile = sys.argv[1]
    staticSizes, heapStart = parseElf(elfFile)
    if not heapStart:
        raise RuntimeError("did not find heap start")

    heapStart = heapStart - RAM_START
    print("heap starts at: " + hex(heapStart))

    d = MemRange("Data", 0, heapStart)
    h = MemRange("Heap", heapStart, RAM_SIZE - STACK_SIZE)
    s = MemRange("Stack", RAM_SIZE - STACK_SIZE, RAM_SIZE)
    mems = [d, h, s]

    traceFile = sys.argv[2] if len(sys.argv) > 2 else "dBusAccess.csv"
    with open(traceFile) as f:
        reader = csv.reader(f, skipinitialspace=True, delimiter=';')
        for r in reader:
            adr = int(r[2], 16)
            for mem in mems:
                if mem.contains(adr):
                    mem.trace(adr)

    for mem in mems:
        print(mem.stats())

    romsize = sum([staticSizes[k] for k in staticSizes if k.startswith("rom_")])
    ramsize = sum([staticSizes[k] for k in staticSizes if k.startswith("ram_")])
    ramsize += s.usage() + h.usage()

    print("=== Results ===")
    print("ROM usage:        " + printSz(romsize))
    print("  read-only data: " + printSz(staticSizes["rom_rodata"]))
    print("  code:           " + printSz(staticSizes["rom_code"]))
    print("  other required: " + printSz(staticSizes["rom_misc"]))
    print("RAM usage:        " + printSz(ramsize))
    print("  data:           " + printSz(staticSizes["ram_data"]))
    print("  zero-init data: " + printSz(staticSizes["ram_zdata"]))
    print("  stack:          " + printSz(s.usage()))
    print("  heap:           " + printSz(h.usage()))
