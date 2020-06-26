/******************************************************************************
 * filename    : bsp_epittimer.h
 * author      : QiDianMaker
 * description : EPIT 定时器驱动头文件 
 * create date : 2020-06-24
 ******************************************************************************/

#ifndef __BSP_EPITTIMER_H
#define __BSP_EPITTIMER_H

#include "imx6ul.h"

/* 函数声明 */
void epit1_init(unsigned int frac, unsigned int value);						
void epit1_irqhandler(void); 			

#endif /* !__BSP_EPITTIMER_H */
