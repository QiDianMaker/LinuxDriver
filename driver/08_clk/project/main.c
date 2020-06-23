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
#include "bsp_key.h"


int main(void)
{
    int i = 0;
	int keyvalue = 0;
	unsigned char led_state = OFF;
	unsigned char beep_state = OFF;
	
	imx6u_clkinit();	/* 初始化系统时钟 */
	led_init();			/* 初始化 led */
	beep_init();		/* 初始化 beep */
	key_init();			/* 初始化 key */

	while (1)			
	{	
		keyvalue = key_getvalue();
		if (keyvalue)
		{
			switch (keyvalue)
			{
			case KEY0_VALUE:
				beep_state = !beep_state;
				beep_switch(beep_state);
				break;
			}
		}

		i++;
		if (i == 50)
		{
			i = 0;
			led_state = !led_state;
			led_switch(LED0, led_state);
		}
		delay_ms(10);
	}

    return 0;
}

