#include "sysreg.h"

void sysreg_init() {
    *(volatile unsigned*)SYSTEM_CLOCK_GATE_REG |= 1; //enable system clock

    *(volatile unsigned*)SYSTEM_CPU_PER_CONF_REG |= (1 << SYSTEM_PLL_FREQ_SEL); //use PLL_CLK 480Mhz
                    //SYSTEM_CPUPERIO_SEL = 0 to set at 80MHz
                    //DISABLE WAIT MODE FORCE ON

    *(volatile unsigned*)SYSTEM_SYSCLK_CONF_REG |= (1 << SYSTEM_SOC_CLK_SEL);    //use PLL_clock for cpu

    *(volatile unsigned*)SYSTEM_CACHE_CONTROL_REG |= ((1 << SYSTEM_ICACHE_CLK_ON) | (1 << SYSTEM_DCACHE_CLK_ON));
    //enable I cache and D cache clock

    unsigned mask = ((1 << SYSTEM_TIMERS_CLK_EN) | (1 << SYSTEM_LEDC_CLK_EN) | (1 << SYSTEM_TIMERGROUP_CLK_EN));
    *(volatile unsigned*)SYSTEM_PERIP_CLK_EN0_REG |= mask; //enable Timers, LEDC pwm and timergroup0

    *(volatile unsigned*)SYSTEM_PERIP_RST_EN0_REG &= ~mask; //disable reset for timers, ledc pwm and timergroup0
}