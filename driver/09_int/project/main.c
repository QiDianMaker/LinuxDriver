/******************************************************************************
 * filename    : main.c
 * author      : QiDianMaker
 * description : I.MX6U 开发板裸机实验 9 
 *               中断实验
 * create date : 2020-06-23
 ******************************************************************************/

#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_key.h"
#include "bsp_int.h"
#include "bsp_exit.h"


int main(void)
{
	unsigned char state = OFF;
	
	int_init();         /* 初始化中断，一定要先调用 */
	imx6u_clkinit();	/* 初始化系统时钟 */
	clk_enable();
	led_init();			/* 初始化 led */
	beep_init();		/* 初始化 beep */
	key_init();			/* 初始化 key */
	exit_init();

	while (1)			
	{			
		state = !state;
		led_switch(LED0, state);
		delay_ms(500);
	}

    return 0;
}

