/******************************************************************************
 * filename    : bsp_clk.c
 * author      : QiDianMaker
 * description : 系统时钟驱动
 * create date : 2020-06-23
 ******************************************************************************/
#include "bsp_clk.h"

/*
 * @brief	使能I.MX6U所有外设时钟
 * @param   无
 * @return  无
 */
void clk_enable(void)
{
	CCM->CCGR0 = 0XFFFFFFFF;
	CCM->CCGR1 = 0XFFFFFFFF;
	CCM->CCGR2 = 0XFFFFFFFF;
	CCM->CCGR3 = 0XFFFFFFFF;
	CCM->CCGR4 = 0XFFFFFFFF;
	CCM->CCGR5 = 0XFFFFFFFF;
	CCM->CCGR6 = 0XFFFFFFFF;
}

