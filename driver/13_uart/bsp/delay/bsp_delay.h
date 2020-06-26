/******************************************************************************
 * filename    : bsp_delay.h
 * author      : QiDianMaker
 * description : 延时头文件
 * create date : 2020-06-23
 ******************************************************************************/
#ifndef __BSP_DELAY_H
#define __BSP_DELAY_H

#include "imx6ul.h"

/* 函数声明 */
void delay_init(void);
void delayus(unsigned int usdelay);
void delayms(unsigned int msdelay);
void delay(volatile unsigned int ms);
void gpt1_irqhandler(void);

#endif /* !__BSP_DELAY_H */

