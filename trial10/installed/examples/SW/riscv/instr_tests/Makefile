BINUTILSPREFIX?=/usr/local/research/projects/SystemDesign/tools/riscv/riscv32-unknown-elf/bin/riscv32-unknown-elf-
ASSEMBLYFILES=$(wildcard *.S)
ALLTARGETS=$(ASSEMBLYFILES:.S=.bin)
ALLSPP=$(ASSEMBLYFILES:.S=.Spp)
ALLELF=$(ASSEMBLYFILES:.S=.elf)

BUILD_DIR = ./build
OBJECT_DIR = ./obj

all: mkdirs $(ALLTARGETS) moveAll
	@echo 'success'

all_spp: $(ALLSPP)
	@echo 'success'

all_elf: $(ALLELF)
	@echo 'success'

mkdirs:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(OBJECT_DIR)


%.bin: %.elf
	$(BINUTILSPREFIX)objcopy -O binary $< $@

%.elf: %.o
	$(BINUTILSPREFIX)ld -Ttarget.ld -o $@ $<

%.o: %.Spp
	$(BINUTILSPREFIX)as -o$@ $<

%.Spp: %.S
	cpp -o $@ $<

moveAll:
	mv *.o ${OBJECT_DIR}
	mv *.Spp ${OBJECT_DIR}
	mv *.elf ${OBJECT_DIR}
	mv *.bin ${BUILD_DIR}

clean:
	rm -rf ${OBJECT_DIR}/*.o
	rm -rf ${OBJECT_DIR}/*.Spp
	rm -rf ${OBJECT_DIR}/*.elf
	rm -rf ${OBJECT_DIR}/*.bin

.SUFFIXES:

