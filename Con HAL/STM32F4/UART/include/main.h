/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
/* Includes ------------------------------------------------------------------*/
#include <stdbool.h> // true or false
#include <string.h> // strlen
#include <stdarg.h> // va_list, va_star, va_end
#include <stdio.h> // vsnprintf
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_uart.h"

bool SystemClock_Config(void);
void GPIO_Init(void);
bool USART1_UART_Init(void);

// void myprintf(const char *fmt, ...);

#endif /* __MAIN_H */