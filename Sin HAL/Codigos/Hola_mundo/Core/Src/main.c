/*
 * main.c
 *
 *  Created on: Apr 13, 2022
 *      Author: Cristobal
 */

#include "main.h"
#include "Sysconfig.h"
#include "GPIO.h"

int main(void){
	Sysconfig();
	GPIO_Init();
	while(1){
		//GPIO_Write(HIGH);
		//GPIO_Write(LOW);
		GPIO_Toogle();
	}
	return 0;
}
