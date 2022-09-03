#ifndef _MAIN_H_
#define _MAIN_H_

#include"stm32f1xx.h"

void SystemClock_Config(void);
void Uart_Init(void);
void Gpio_Init(void);
void myprintf(const char *fmt, ...);

#endif