/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "stm32f4xx_hal.h"

bool SystemClock_Config(void);

void GPIO_Init(void);

bool USART1_UART_Init(void);

//void myprintf(const char *fmt, ...);


#endif /* __MAIN_H */