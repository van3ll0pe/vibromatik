#include "interrupt.h"

.section .text

.macro trap_context_entry
    addi sp, sp, -124
    sw ra, 0(sp)
    sw t0, 4(sp)
    sw t1, 8(sp)
    sw t2, 12(sp)
    sw s0, 16(sp)
    sw s1, 20(sp)
    sw a0, 24(sp)
    sw a1, 28(sp)
    sw a2, 32(sp)
    sw a3, 36(sp)
    sw a4, 40(sp)
    sw a5, 44(sp)
    sw a6, 48(sp)
    sw a7, 52(sp)
    sw s2, 56(sp)
    sw s3, 60(sp)
    sw s4, 64(sp)
    sw s5, 68(sp)
    sw s6, 72(sp)
    sw s7, 76(sp)
    sw s8, 80(sp)
    sw s9, 84(sp)
    sw s10, 88(sp)
    sw s11, 92(sp)
    sw t3, 96(sp)
    sw t4, 100(sp)
    sw t5, 104(sp)
    sw t6, 108(sp)
    csrrs t0, mepc, x0  #save mpec if exception while interrupt handler
    sw t0, 112(sp)
    csrrs t0, mstatus, x0
    sw t0, 116(sp)
    csrrs t0, mcause, x0
    sw t0, 120(sp)
.endm

.macro trap_context_exit
    lw t0, 120(sp)
    csrrw x0, mcause, t0
    lw t0, 116(sp)
    csrrw x0, mstatus, t0
    lw t0, 112(sp) #restore mpec if exception while interrupt handler
    csrrw x0, mepc, t0
    lw t6, 108(sp)
    lw t5, 104(sp)
    lw t4, 100(sp)
    lw t3, 96(sp)
    lw s11, 92(sp)
    lw s10, 88(sp)
    lw s9, 84(sp)
    lw s8, 80(sp)
    lw s7, 76(sp)
    lw s6, 72(sp)
    lw s5, 68(sp)
    lw s4, 64(sp)
    lw s3, 60(sp)
    lw s2, 56(sp)
    lw a7, 52(sp)
    lw a6, 48(sp)
    lw a5, 44(sp)
    lw a4, 40(sp)
    lw a3, 36(sp)
    lw a2, 32(sp)
    lw a1, 28(sp)
    lw a0, 24(sp)
    lw s1, 20(sp)
    lw s0, 16(sp)
    lw t2, 12(sp)
    lw t1, 8(sp)
    lw t0, 4(sp)
    lw ra, 0(sp)
    addi sp, sp, 124
    mret
.endm

.globl enable_global_interrupt
enable_global_interrupt:
    csrrsi x0, mstatus, 8
    ret

.globl disable_global_interrupt
disable_global_interrupt:
    csrrci x0, mstatus, 8
    ret 

.globl trap_init
trap_init:
    la t0, vector_trap
    csrrw x0, mtvec, t0 #mtvec is set to vector_trap
    ret

call_handler_interrupt:
    trap_context_entry
    lw a0, 120(sp)          #put mcause in argument of handler_interrupt
    call handler_interrupt
    trap_context_exit

.align 256
vector_trap:
j call_handler_interrupt # interrupt 0
j call_handler_interrupt # interrupt 1
j call_handler_interrupt # interrupt 2
j call_handler_interrupt # interrupt 3
j call_handler_interrupt # interrupt 4
j call_handler_interrupt # interrupt 5
j call_handler_interrupt # interrupt 6
j call_handler_interrupt # interrupt 7
j call_handler_interrupt # interrupt 8
j call_handler_interrupt # interrupt 9
j call_handler_interrupt # interrupt 10
j call_handler_interrupt # interrupt 11
j call_handler_interrupt # interrupt 12
j call_handler_interrupt # interrupt 13
j call_handler_interrupt # interrupt 14
j call_handler_interrupt # interrupt 15
j call_handler_interrupt # interrupt 16
j call_handler_interrupt # interrupt 17
j call_handler_interrupt # interrupt 18
j call_handler_interrupt # interrupt 19
j call_handler_interrupt # interrupt 20
j call_handler_interrupt # interrupt 21
j call_handler_interrupt # interrupt 22
j call_handler_interrupt # interrupt 23
j call_handler_interrupt # interrupt 24
j call_handler_interrupt # interrupt 25
j call_handler_interrupt # interrupt 26
j call_handler_interrupt # interrupt 27
j call_handler_interrupt # interrupt 28
j call_handler_interrupt # interrupt 29
j call_handler_interrupt # interrupt 30
j call_handler_interrupt # interrupt 31