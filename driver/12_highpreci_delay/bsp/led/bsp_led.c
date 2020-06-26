/******************************************************************************
 * filename    : bsp_led.c
 * author      : QiDianMaker
 * description : LED 驱动
 * create date : 2020-06-23
 ******************************************************************************/

#include "bsp_led.h"

/*
 * @brief  初始化 LED0 对应的 GPIO
 * @param  无
 * @return 无
 */
void led_init(void)
{
    /* 1、设置 GPIO1_IO03 复用为 GPIO1_IO03 */
	IOMUXC_SetPinMux(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0);

	/* 2、配置 GPIO1_IO03 的IO属性	
     *bit [16]   : 0 HYS 关闭
	 *bit [15:14]: 00 默认下拉
     *bit [13]   : 0 kepper 功能
     *bit [12]   : 1 pull/keeper 使能
     *bit [11]   : 0 关闭开路输出
     *bit [7:6]  : 10 速度 100Mhz
     *bit [5:3]  : 110 R0/6 驱动能力
     *bit [0]    : 0 低转换率
     */
    IOMUXC_SetPinConfig(IOMUXC_GPIO1_IO03_GPIO1_IO03, 0x10b0);

	/* 3、设置 GPIO1_IO03 为输出 */
    GPIO1->GDIR |= (1 << 3);

    /* 4、设置 GPIO1_IO03 输出低电平，点亮 LED0 */
    GPIO1->DR &= ~(1 << 3);
}



/*
 * @brief   LED控制函数，控制LED打开还是关闭
 * @param   led	  要控制的LED灯编号
 * @param   status 0，关闭 LED0;1 打开 LED0
 * @return  无
 */
void led_switch(int led, int status)
{	
	switch (led)
	{
	case LED0:
		if(status == ON)
			GPIO1->DR &= ~(1<<3);	/* 打开LED0 */
		else if(status == OFF)
			GPIO1->DR |= (1<<3);	/* 关闭LED0 */
		break;
	}
}
