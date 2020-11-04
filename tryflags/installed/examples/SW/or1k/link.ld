MEMORY
{
	vectors : ORIGIN = 0x00000000, LENGTH = 0x00003000
	rom     : ORIGIN = 0x00003000, LENGTH = 0x00080000 - 0x00003000  
    	ram   	: ORIGIN = 0x00080000, LENGTH = 0x00100000 - 0x00080000
}

SECTIONS
{
    . = 0x00000000;
	.vectors :
	{
		_vec_start = .;
		*(.vectors)
		_vec_end = .;
	} > vectors

    . = 0x00003000;
	.text ALIGN(4) :
	{
		*(.text)
	} > rom

	.rodata ALIGN(4) :
	{
		*(.rodata)
		*(.rodata.*)
	} > rom
	
	.init ALIGN(4) :
	{
		*(.init)
	} > rom
	
	.fini ALIGN(4) :
	{
		*(.fini)
	} > rom
	
	.eh_frame ALIGN(4) :
	{
		*(.eh_frame)
	} > rom
	
	

    . = 0x00080000;
    
	.ctors ALIGN(4) :
	{
		*(.ctors)
	} > ram    
	 
	.dtors ALIGN(4) :
	{
		*(.dtors)
	} > ram  
	
	.jcr ALIGN(4) :
	{
		*(.jcr)
	} > ram  

	.data ALIGN(4) :
	{
		_dst_beg = .;
		*(.data)
		_dst_end = .;
	} > ram

	.bss ALIGN(4) :
	{
		__bss_start = .;
		*(.bss)
		__bss_end = .;
		PROVIDE(end = .);
	} > ram
	
	
}
