/******************************************************************************
 * filename    : bsp_exit.h
 * author      : QiDianMaker
 * description : 外部中断驱动头文件 
 * create date : 2020-06-24
 ******************************************************************************/

#ifndef __BSP_EXIT_H
#define __BSP_EXIT_H

#include "imx6ul.h"

/* 函数声明 */
void exit_init(void);						/* 中断初始化 */
void gpio1_io18_irqhandler(void); 			/* 中断处理函数 */

#endif /* !__BSP_EXIT_H */
