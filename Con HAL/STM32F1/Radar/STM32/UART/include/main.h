#ifndef __MAIN_H_
#define __MAIN_H_

#include <stdbool.h> // true or false
#include <string.h>  // strlen
#include <stdarg.h>  // va_list, va_star, va_end
#include <stdio.h>   // vsnprintf
#include "stm32f1xx.h"
#include "stm32f1xx_hal.h"

bool SystemClock_Config(void);
bool USART1_UART_Init(void);
void GPIO_Init(void);
void myprintf(const char *format, ...);

#endif /* __MAIN_H */