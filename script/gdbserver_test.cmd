target remote :2001
bt
info registers
break main
break _exit
continue
bt
info registers
continue
bt
info registers
i r x0
i r zero
i r pc