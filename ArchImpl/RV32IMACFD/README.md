## Debug ETISS 
1. Modify run_helper.sh
 
in `if USE_GDB` (line 111) do    

`gdbserver localhost:2000 ${VP_EXE} ${ARGS}`
    
2. Terminal 1 (from target, fivp-sdk in this case)
 
`$ cd build`
  
`$ ./../../etiss/build_dir/bin/run_helper.sh <path_to_target_executable>`
  
3. Terminal 2 start gdb session

`$ gdb -tui -ex "tar rem :2000" ../etiss/build_dir/bin/bare_etiss_processor`
  
## Debug Target
1. Modify run_helper.sh
 
in `if USE_GDB` (line 111) do
  
`gdb --tui --args ${VP_EXE} ${ARGS}`
 
2. Terminal 1 (from target, fivp-sdk in this case)
 
`$ cd build`
    
`$ ./../../etiss/build_dir/bin/run_helper.sh <path_to_target_executable> tgdb noattach`
    
3. Terminal 2 Start gdb session 
 
`$ cd build`
  
`$ <path_to_riscv32-unknown-elf-gdb> <path_to_target_executable> -ex "tar rem :2222" -tui`
  
`path_to_riscv32-unknown-elf-gdb` could be something like `/usr/local/research/projects/SystemDesign/tools/riscv/gcc/no-multilib/rv32gc_zve32x_ilp32d/bin/riscv32-unknown-elf-gdb`
 
 
  
