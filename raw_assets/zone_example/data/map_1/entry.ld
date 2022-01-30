ENTRY_POINT = 0x80800000;
SECTIONS
{
. = 0x02000000;
.data : { *(.data) }
.text : { *(.text) }
.bss : { *(.bss) }
}