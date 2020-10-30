SECTIONS
{
  . = 0x0;
  .text : { *(.text) }
  . = 0x1000000;
  .data : { *(.data) }
  .bss : { *(.bss) }
}
