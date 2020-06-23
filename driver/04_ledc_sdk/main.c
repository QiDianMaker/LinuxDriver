/******************************************************************************
 * filename    : main.c
 * author      : QiDianMaker
 * description : I.MX6U 开发板裸机实验 4 
 *               使用 NXP 提供的 I.MX6ULL 官方 IAR SDK 包开发
 * create date : 2020-06-23
 ******************************************************************************/

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"

static void clk_enable(void);
static void led_init(void);
static void led_on(void);
static void led_off(void);
static void delay_short(volatile unsigned int n);
static void delay_ms(volatile unsigned int ms);

int main(void)
{
    clk_enable();
    led_init();

    while (1) 
    {
        led_on();
        delay_ms(500);

        led_off();
        delay_ms(500);
    }
    
    return 0;
}

/*
 * @brief  使能 I.MX6U 的所有外设时钟
 * @param  无
 * @return 无
 */

static void clk_enable(void)
{
    CCM->CCGR0 = 0xffffffff;
    CCM->CCGR1 = 0xffffffff;
    CCM->CCGR2 = 0xffffffff;
    CCM->CCGR3 = 0xffffffff;
    CCM->CCGR4 = 0xffffffff;
    CCM->CCGR5 = 0xffffffff;
    CCM->CCGR6 = 0xffffffff;
}

/*
 * @brief  初始化 LED0 对应的 GPIO
 * @param  无
 * @return 无
 */
static void led_init(void)
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
 * @brief  打开 LED 灯
 * @param  无
 * @return 无
 */
static void led_on(void)
{
    GPIO1->DR &= ~(1 << 3);
}

/*
 * @brief  关闭 LED 灯
 * @param  无
 * @return 无
 */
static void led_off(void)
{
    GPIO1->DR |= (1 << 3);
}

/*
 * @brief  短时间延时函数
 * @param  n 空操作的次数
 * @return 无
 */
static void delay_short(volatile unsigned int n)
{
    while (n--) ;
}

/*
 * @brief  毫秒延时函数
 * @param  ms 要延时的毫秒数
 * @return 无
 */
static void delay_ms(volatile unsigned int ms)
{
    while (ms--) 
        delay_short(0x7ff);
}
