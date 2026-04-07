#include "interrupt.h"

void interrupt_init() {
    *(volatile unsigned*)INTERRUPT_CORE0_CLOCK_GATE_REG = 1; //enable clock for interrupt
    
    *(volatile unsigned*)INTERRUPT_CORE0_GPIO_INTERRUPT_PRO_MAP_REG = 1;    //gpio is interrupt 1 id
    *(volatile unsigned*)INTERRUPT_CORE0_TG_T0_INT_MAP_REG = 2;             //timergroup is interrupt 2 id
    //*(volatile unsigned*)INTERRUPT_CORE0_TG_WDT_INT_MAP_REG = 3;            //timergroup watchdog is interrupt 3 id

    *(volatile unsigned*)INTERRUPT_CORE0_CPU_INT_TYPE_REG = 0; //timer is edge trigger, gpio in level trigger with 0 

    *(volatile unsigned*)INTERRUPT_CORE0_CPU_INT_PRI_n_REG(1) = 15;
    *(volatile unsigned*)INTERRUPT_CORE0_CPU_INT_PRI_n_REG(2) = 14;
    
    *(volatile unsigned*)INTERRUPT_CORE0_CPU_INT_THRESH_REG = 5;

    *(volatile unsigned*)INTERRUPT_CORE0_CPU_INT_ENABLE_REG = (1 << 1) | (1 << 2); //enable interrupt from gpio and timergroup


}

void handler_interrupt(unsigned int mcause) {
    if ((mcause & (1 << 31)) == 0)  //no gestion of exception
        return;
    
    switch (mcause & 31) {  //interrupt type
        case 1: break;
        case 2: break;
        case 3: break;
        case 4: break;
        case 5: break;
        case 6: break;
        case 7: break;
        case 8: break;
        case 9: break;
        case 10: break;
        case 11: break;
        case 12: break;
        case 13: break;
        case 14: break;
        case 15: break;
        case 16: break;
        case 17: break;
        case 18: break;
        case 19: break;
        case 20: break;
        case 21: break;
        case 22: break;
        case 23: break;
        case 24: break;
        case 25: break;
        case 26: break;
        case 27: break;
        case 28: break;
        case 29: break;
        case 30: break;
        case 31: break;
        default : break;
    }
    
    return;
}