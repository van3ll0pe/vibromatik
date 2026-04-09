#include "pwm.h"
#include "sysreg.h"

void ledc_enable() {
    *(volatile unsigned*)SYSTEM_PERIP_CLK_EN0_REG |= (1 << SYSTEM_LEDC_CLK_EN);
    *(volatile unsigned*)SYSTEM_PERIP_RST_EN0_REG &= ~(1 << SYSTEM_LEDC_CLK_EN);
}