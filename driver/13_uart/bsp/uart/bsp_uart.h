/******************************************************************************
 * filename    : bsp_uart.h
 * author      : QiDianMaker
 * description : 串口驱动文件头文件
 * create date : 2020-06-26
 ******************************************************************************/

#ifndef __BSP_UART_H
#define __BSP_UART_H

#include "imx6ul.h"

/* 函数声明 */
void uart_init(void);
void uart_io_init(void);
void uart_disable(UART_Type *base);
void uart_enable(UART_Type *base);
void uart_softreset(UART_Type *base);
void uart_setbaudrate(UART_Type *base, unsigned int baudrate, unsigned int srcclock_hz);
void putc(unsigned char c);
void puts(char *str);
unsigned char getc(void);
void raise(int sig_nr);


#endif
