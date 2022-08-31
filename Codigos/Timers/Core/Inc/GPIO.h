/*
 * GPIO.h
 *
 *  Created on: 20-04-2022
 *      Author: Cristobal
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "main.h"

typedef enum{
	LOW, // 0
	HIGH // 1
}GPIO_State;


GPIO_State GPIO_Read(void);

void GPIO_Init_Read(void);

void GPIO_Write(GPIO_State state);

void GPIO_Toggle(void);

#endif /* INC_GPIO_H_ */
