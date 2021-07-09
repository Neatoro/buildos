.include "multiboot.s"

.section .stack
.align 16
stack_bottom:
.skip 16384
stack_top:

.section .text
.global _start
.type _start, @function
_start:
    mov $stack_top, %esp

    cli
1:  hlt
    jmp 1b
