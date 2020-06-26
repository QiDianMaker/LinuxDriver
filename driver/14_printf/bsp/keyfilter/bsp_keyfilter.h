/******************************************************************************
 * filename    : bsp_keyfilter.h
 * author      : QiDianMaker
 * description : 定时器按键消抖驱动头文件
 * create date : 2020-06-25
 ******************************************************************************/

#ifndef __BSP_KEYFILTER_H
#define __BSP_KEYFILTER_H

/* 函数声明 */
void filterkey_init(void);
void filtertimer_init(unsigned int value);
void filtertimer_stop(void);
void filtertimer_restart(unsigned int value);
void filtertimer_irqhandler(void);
void gpio1_16_31_irqhandler(void);


#endif /* ！__BSP_KEYFILTER_H */