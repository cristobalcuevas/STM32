/*
 * main.c
 *
 *  Created on: Apr 20, 2022
 *      Author: Cristobal
 */

#include "main.h"
#include "Sysconfig.h"
#include "GPIO.h"
#include "Timer.h"

int main(void){
	Sysconfig();
	SysTick_Config(84000);
	GPIO_Init_Read();
	Timer_Init_Delay();
	while(1){
			GPIO_Toggle();
			Timer_delay(250); // USAR TIMER
	}
	return 0;
}
