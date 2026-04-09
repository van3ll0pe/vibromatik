#include "interrupt.h"
#include "sysreg.h"

void timergroup0_enable() {
    *(volatile unsigned*)SYSTEM_PERIP_CLK_EN0_REG |= (1 << SYSTEM_TIMERGROUP_CLK_EN);
    *(volatile unsigned*)SYSTEM_PERIP_RST_EN0_REG &= ~(1 << SYSTEM_TIMERGROUP_CLK_EN); 
}

void timergroup1_enable() {
*(volatile unsigned*)SYSTEM_PERIP_CLK_EN0_REG |= (1 << SYSTEM_TIMERGROUP1_CLK_EN);
*(volatile unsigned*)SYSTEM_PERIP_RST_EN0_REG &= ~(1 << SYSTEM_TIMERGROUP1_CLK_EN);
}
 
void timergroup0_disable() {
    *(volatile unsigned*)SYSTEM_PERIP_CLK_EN0_REG &= ~(1 << SYSTEM_TIMERGROUP_CLK_EN);
    *(volatile unsigned*)SYSTEM_PERIP_RST_EN0_REG |= (1 << SYSTEM_TIMERGROUP_CLK_EN); 
}

void timergroup1_disable() {
    *(volatile unsigned*)SYSTEM_PERIP_CLK_EN0_REG &= ~(1 << SYSTEM_TIMERGROUP1_CLK_EN);
    *(volatile unsigned*)SYSTEM_PERIP_RST_EN0_REG |= (1 << SYSTEM_TIMERGROUP1_CLK_EN);
}

