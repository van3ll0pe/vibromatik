#include "interrupt.h"

.section .text

.globl _start
_start:
    la sp, _stack
    call bss_init
    call trap_init

    call main
start_loop: j start_loop #security loop


.globl bss_init
bss_init:
    la t0, _bss_start
    la t1, _bss_end
1:
    bgeu t0, t1, bss_init_end
    sw x0, (t0)
    addi t0, t0, 4
    j 1b
bss_init_end:
    ret
