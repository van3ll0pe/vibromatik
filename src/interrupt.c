#include "interrupt.h"


ptf interrupt_handler_vector[32] = {0x0};


void interrupt_enable() {
    *(volatile unsigned*)INTERRUPT_CORE0_CLOCK_GATE_REG = 1; //enable clock for interrupt
    
    /* TO DO INDIVIDUALLY IN EACH INIT OF MODULE GPIO AND TIMERGROUP
    *(volatile unsigned*)INTERRUPT_CORE0_GPIO_INTERRUPT_PRO_MAP_REG = 1;    //gpio is interrupt 1 id
    *(volatile unsigned*)INTERRUPT_CORE0_TG_T0_INT_MAP_REG = 2;             //timergroup is interrupt 2 id
    //*(volatile unsigned*)INTERRUPT_CORE0_TG_WDT_INT_MAP_REG = 3;            //timergroup watchdog is interrupt 3 id

    *(volatile unsigned*)INTERRUPT_CORE0_CPU_INT_TYPE_REG = 0; //timer is edge trigger, gpio in level trigger with 0 

    *(volatile unsigned*)INTERRUPT_CORE0_CPU_INT_PRI_n_REG(1) = 15;
    *(volatile unsigned*)INTERRUPT_CORE0_CPU_INT_PRI_n_REG(2) = 14;
    
    *(volatile unsigned*)INTERRUPT_CORE0_CPU_INT_THRESH_REG = 5;

    *(volatile unsigned*)INTERRUPT_CORE0_CPU_INT_ENABLE_REG = (1 << 1) | (1 << 2); //enable interrupt from gpio and timergroup
    */

}

void handler_interrupt(unsigned int mcause) {
    if ((mcause & (1 << 31)) == 0)  //no gestion of exception
        return;
    
    unsigned id = mcause & 31;  //interrupt type
    if (id == 0) //invalid id interrupt
        return;

    if (interrupt_handler_vector[id])
        interrupt_handler_vector[id]();
    
    return;
}