# Description

The purpose of this script is to extract selected information regarding a selected subprogram from DWARF debugging information.  


The goal is to extract the following:  
- subprogram: name, type
  - local variables: name, type
  - global variables (static, eternal): name, type
  - parameters: name, type


The script is based on `dwarf_die_tree.py` example in the pyelftools remote repository: https://github.com/eliben/pyelftools
