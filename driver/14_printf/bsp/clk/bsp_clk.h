/******************************************************************************
 * filename    : bsp_clk.h
 * author      : QiDianMaker
 * description : 系统时钟驱动头文件
 * create date : 2020-06-23
 ******************************************************************************/

#ifndef __BSP_CLK_H
#define __BSP_CLK_H

#include "imx6ul.h"

/* 函数声明 */
void clk_enable(void);
void imx6u_clkinit(void);

#endif /* !__BSP_CLK_H */
