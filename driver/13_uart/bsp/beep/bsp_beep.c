/******************************************************************************
 * filename    : bsp_beep.c
 * author      : QiDianMaker
 * description : 蜂鸣器驱动
 * create date : 2020-06-23
 ******************************************************************************/

#include "bsp_beep.h"

/*
 * @brief  初始化蜂鸣器对应的 GPIO
 * @param  无
 * @return 无
 */
void beep_init(void)
{
    /* 1、设置 GPIO5_IO01 复用为 GPIO */
	IOMUXC_SetPinMux(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01, 0);

	/* 2、配置 GPIO5_IO03 的IO属性 */
    IOMUXC_SetPinConfig(IOMUXC_SNVS_SNVS_TAMPER1_GPIO5_IO01, 0x10b0);

	/* 3、设置 GPIO5_IO01 为输出 */
    GPIO5->GDIR |= (1 << 1);

    /* 4、设置 GPIO5_IO01 输出高电平，关闭蜂鸣器 */
    GPIO5->DR |= (1 << 1);
}



/*
 * @brief   蜂鸣器控制函数，控制蜂鸣器打开还是关闭
 * @param   status 0，关闭;1 打开
 * @return  无
 */
void beep_switch(int status)
{	
	if(status == ON)
		GPIO5->DR &= ~(1 << 1);	
	else if(status == OFF)
		GPIO5->DR |= (1 << 1);
}
