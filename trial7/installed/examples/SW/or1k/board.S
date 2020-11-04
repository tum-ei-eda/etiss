.global _or1k_board_mem_base
.global _or1k_board_mem_size
.global _or1k_board_clk_freq 

_or1k_board_mem_base:	.long	0x080000
_or1k_board_mem_size:	.long	0x080000

_or1k_board_clk_freq:	.long	100000000 

/* Peripheral information - Set base to 0 if not present*/
.global _or1k_board_uart_base
.global _or1k_board_uart_baud
.global _or1k_board_uart_IRQ
	
_or1k_board_uart_base:	.long	0x00000000
_or1k_board_uart_baud:	.long	115200
_or1k_board_uart_IRQ:	.long	2

.weak _board_exit
.global _exit
_exit:
_board_exit:
       	l.j _board_exit
       	l.nop 0x01
