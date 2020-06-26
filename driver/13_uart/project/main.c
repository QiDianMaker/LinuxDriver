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


int main(void)
{
	unsigned char a = 0;
	unsigned char state = OFF;
	
	int_init();         /* 初始化中断，一定要先调用 */
	imx6u_clkinit();	/* 初始化系统时钟 */
	delay_init();
	clk_enable();
	led_init();			/* 初始化 led */
	beep_init();		/* 初始化 beep */
	uart_init();		
	
	while (1)			
	{	
		puts("请输入一个字符：");
		a = getc();
		putc(a);
		puts("\r\n");

		/* 显示输入的字符 */
		puts("您输入的字符为：");
		putc(a);
		puts("\r\n\r\n");

		state = !state;
		led_switch(LED0, state);		
	}

    return 0;
}

