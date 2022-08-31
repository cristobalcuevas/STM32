/*
 * GPIO.h
 *
 *  Created on: 14-04-2022
 *      Author: Cristobal
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "main.h"

typedef enum{
	LOW, // 0
	HIGH // 1
}GPIO_State;

void GPIO_Init(void);

void GPIO_Write(GPIO_State state);

void GPIO_Toogle(void);

#endif /* INC_GPIO_H_ */
