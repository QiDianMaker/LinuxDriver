/******************************************************************************
 * filename    : bsp_beep.h
 * author      : QiDianMaker
 * description : 蜂鸣器驱动头文件
 * create date : 2020-06-23
 ******************************************************************************/

#ifndef __BSP_BEEP_H
#define __BSP_BEEP_H

#include "imx6ul.h"

/* 函数声明 */
void beep_init(void);
void beep_switch(int status);

#endif /* !__BSP_BEEP_H */

