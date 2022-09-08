/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
/* Includes ------------------------------------------------------------------*/
#include <string.h> // strlen
#include <stdarg.h> // va_list, va_star, va_end
#include <stdio.h> // vsnprintf
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"


void SystemClock_Config(void);
void GPIO_Init(void);
void USART1_UART_Init(void);
void myprintf(const char *format, ...);

#endif /* __MAIN_H */