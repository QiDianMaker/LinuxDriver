/******************************************************************************
 * filename    : bsp_gpio.h
 * author      : QiDianMaker
 * description : GPIO 驱动头文件
 * create date : 2020-06-23
 ******************************************************************************/

#ifndef __BSP_GPIO_H
#define __BSP_GPIO_H

#include "imx6ul.h"


/* 枚举类型和结构体定义 */
typedef enum _gpio_pin_direction
{
    kGPIO_DigitalInput  = 0U,  		/* 输入 */
    kGPIO_DigitalOutput = 1U, 		/* 输出 */
} gpio_pin_direction_t;
	

typedef struct _gpio_pin_config
{
    gpio_pin_direction_t direction; /* GPIO 方向：输入还是输出 */
    uint8_t outputLogic;            /* 如果是输出的话，默认输出电平 */
} gpio_pin_config_t;


/* 函数声明 */
void gpio_init(GPIO_Type *base, int pin, gpio_pin_config_t *config);
int gpio_pinread(GPIO_Type *base, int pin);
void gpio_pinwrite(GPIO_Type *base, int pin, int value);

#endif /* !__BSP_GPIO_H */