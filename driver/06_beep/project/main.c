/******************************************************************************
 * filename    : main.c
 * author      : QiDianMaker
 * description : I.MX6U 开发板裸机实验 5 
 *               BSP 形式的 LED 驱动
 * create date : 2020-06-23
 ******************************************************************************/

#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"


int main(void)
{
    clk_enable();
    led_init();
    beep_init();

    while (1) 
    {
        led_switch(LED0, ON);
        beep_switch(ON);
        delay_ms(500);

        led_switch(LED0, OFF);
        beep_switch(OFF);
        delay_ms(500);
    }

    return 0;
}

