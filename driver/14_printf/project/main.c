/******************************************************************************
 * filename    : main.c
 * author      : QiDianMaker
 * description : I.MX6U 开发板裸机实验 13
 *               串口通信实验
 * create date : 2020-06-23
 ******************************************************************************/

#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_key.h"
#include "bsp_int.h"
#include "bsp_uart.h"
#include "stdio.h"


int main(void)
{
	unsigned char state = OFF;
	int a, b;

	int_init();         /* 初始化中断，一定要先调用 */
	imx6u_clkinit();	/* 初始化系统时钟 */
	delay_init();
	clk_enable();
	led_init();			/* 初始化 led */
	beep_init();		/* 初始化 beep */
	uart_init();		
	
	while (1)			
	{	
		printf("请输入两个整数，用空格隔开：");
		scanf("%d %d", &a, &b);

		printf("\r\n%d + %d = %d\r\n\r\n", a, b, a + b);

		state = !state;
		led_switch(LED0, state);		
	}

    return 0;
}

