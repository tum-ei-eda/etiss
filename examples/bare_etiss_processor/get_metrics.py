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
        return self.high - self.low

    def stats(self):
        if self.low > self.high:
            return self.name + "\t[not accessed]"
        return self.name + "\t[" + hex(self.low) + "-" + hex(self.high) + "] \t(" + str(self.count) + " times)"


def parseElf(inFile):
    m = {}
    m["romsize"] = 0
    m["ramsize"] = 0
    romsections = [".rodata", ".vectors"]
    ramsections = [".data", ".bss", ".init_array", ".shbss", ".sbss"]
    heapStart = None

    with open(inFile, "rb") as f:
        e = elffile.ELFFile(f)

        for s in e.iter_sections():
            if s.name.startswith(".text"):
                m["romsize"] += s.data_size
            elif s.name.startswith(".srodata"):
                m["romsize"] += s.data_size
            elif s.name.startswith(".sdata"):
                m["ramsize"] += s.data_size
            elif any(n in s.name for n in romsections):
                m["romsize"] += s.data_size
            elif any(n in s.name for n in ramsections):
                m["ramsize"] += s.data_size
            elif s.name.startswith(".gcc_except"):
                pass
            elif s.name.startswith(".sdata2"):
                pass
            elif isinstance(s, SymbolTableSection):
                for sym in s.iter_symbols():
                    if sym.name == "_heap_start":
                        heapStart = sym["st_value"]
            else:
                print("ignored: " + s.name)

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

    print("=== Results ===")
    print("ROM usage:     " + printSz(staticSizes["romsize"]))
    print("RAM usage:     " + printSz(staticSizes["ramsize"]))
    print("Stack usage:   " + printSz(s.usage()))
    print("Heap usage:    " + printSz(h.usage()))
