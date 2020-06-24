/******************************************************************************
 * filename    : bsp_gpio.c
 * author      : QiDianMaker
 * description : GPIO 驱动
 * create date : 2020-06-23
 ******************************************************************************/

#include "bsp_gpio.h"

/*
 * @brief   GPIO 初始化。
 * @param   base 要初始化的 GPIO 组。
 * @param   pin	 要初始化 GPIO 在组内的编号。
 * @param   config	GPIO 配置结构体。
 * @return 	无
 */
void gpio_init(GPIO_Type *base, int pin, gpio_pin_config_t *config)
{
	base->IMR &= ~(1U << pin);
	
	if(config->direction == kGPIO_DigitalInput) /* GPIO作为输入 */
	{
		base->GDIR &= ~( 1 << pin);
	}
	else										/* 输出 */
	{
		base->GDIR |= 1 << pin;
		gpio_pinwrite(base,pin, config->outputLogic);	/* 设置默认输出电平 */
	}
	gpio_intconfig(base, pin, config->interruptMode);	/* 中断功能配置 */
}

/*
 * @brief  读取指定 GPIO 的电平值 。
 * @param  base 要读取的 GPIO 组。
 * @param  pin	要读取的 GPIO 脚号。
 * @return 无
 */
 int gpio_pinread(GPIO_Type *base, int pin)
 {
	 return (((base->DR) >> pin) & 0x1);
 }

/*
 * @brief  指定 GPIO 输出高或者低电平 。
 * @param  base	 要输出的的 GPIO 组。
 * @param  pin	 要输出的 GPIO 脚号。
 * @param  value 要输出的电平，1 输出高电平， 0 输出低低电平
 * @return 无
 */
void gpio_pinwrite(GPIO_Type *base, int pin, int value)
{
	 if (value == 0U)
	 {
		 base->DR &= ~(1U << pin); /* 输出低电平 */
	 }
	 else
	 {
		 base->DR |= (1U << pin); /* 输出高电平 */
	 }
}

/*
 * @brief   设置 GPIO 的中断配置功能
 * @param   base 	要配置的 IO 所在的 GPIO 组。
 * @param   pin  	要配置的 GPIO 脚号。
 * @param   pinInterruptMode 中断模式，参考枚举类型 gpio_interrupt_mode_t
 * @return	无
 */
void gpio_intconfig(GPIO_Type* base, unsigned int pin, gpio_interrupt_mode_t pin_int_mode)
{
	volatile uint32_t *icr;
	uint32_t icrShift;

	icrShift = pin;
	
	base->EDGE_SEL &= ~(1U << pin);

	if(pin < 16) 	/* 低16位 */
	{
		icr = &(base->ICR1);
	}
	else			/* 高16位 */
	{
		icr = &(base->ICR2);
		icrShift -= 16;
	}
	switch(pin_int_mode)
	{
		case(kGPIO_IntLowLevel):
			*icr &= ~(3U << (2 * icrShift));
			break;
		case(kGPIO_IntHighLevel):
			*icr = (*icr & (~(3U << (2 * icrShift)))) | (1U << (2 * icrShift));
			break;
		case(kGPIO_IntRisingEdge):
			*icr = (*icr & (~(3U << (2 * icrShift)))) | (2U << (2 * icrShift));
			break;
		case(kGPIO_IntFallingEdge):
			*icr |= (3U << (2 * icrShift));
			break;
		case(kGPIO_IntRisingOrFallingEdge):
			base->EDGE_SEL |= (1U << pin);
			break;
		default:
			break;
	}
}


/*
 * @brief  	使能 GPIO 的中断功能
 * @param   base 要使能的 IO 所在的 GPIO 组。
 * @param   pin  要使能的 GPIO 在组内的编号。
 * @return	无
 */
void gpio_enableint(GPIO_Type* base, unsigned int pin)
{ 
    base->IMR |= (1 << pin);
}

/*
 * @brief  	禁止 GPIO 的中断功能
 * @param   base 要禁止的 IO 所在的 GPIO 组。
 * @param   pin  要禁止的 GPIO 在组内的编号。
 * @return	无
 */
void gpio_disableint(GPIO_Type* base, unsigned int pin)
{ 
    base->IMR &= ~(1 << pin);
}

/*
 * @brief  	清除中断标志位(写1清除)
 * @param   base 要清除的 IO 所在的 GPIO 组。
 * @param   pin  要清除的 GPIO 掩码。
 * @return	无
 */
void gpio_clearintflags(GPIO_Type* base, unsigned int pin)
{
    base->ISR |= (1 << pin);
}
