/******************************************************************************
 * filename    : bsp_delay.c
 * author      : QiDianMaker
 * description : 延时驱动
 * create date : 2020-06-23
 ******************************************************************************/

#include "bsp_delay.h"

static void delay_short(volatile unsigned int n);

/*
 * @brief  毫秒延时函数
 * @param  ms 要延时的毫秒数
 * @return 无
 */
void delay_ms(volatile unsigned int ms)
{
    while (ms--) 
        delay_short(0x7ff);
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