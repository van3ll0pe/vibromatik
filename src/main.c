#include "interrupt.h"
#include "sysreg.h"

void setup() {
    sysreg_setup();
    interrupt_setup();
}

int main() {
    disable_global_interrupt();
    setup();
    //init_timergroup0();
    //init_gpio();
    //init_ledc();
    enable_global_interrupt();

    while (1) {
        __asm__ __volatile__ ("wfi");
    }
    
    return 0;
}