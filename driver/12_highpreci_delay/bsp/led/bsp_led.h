/******************************************************************************
 * filename    : bsp_led.h
 * author      : QiDianMaker
 * description : LED 驱动头文件
 * create date : 2020-06-23
 ******************************************************************************/

#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "imx6ul.h"

#define LED0	0

/* 函数声明 */
void led_init(void);
void led_switch(int led, int status);

#endif /* !__BSP_LED_H */

