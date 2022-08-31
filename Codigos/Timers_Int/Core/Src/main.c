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

int main(void)
{
	Sysconfig();
	SysTick_Config(84000);
	GPIO_Init_Read();
	// INTERRUPCION A LOS 500 MS
	Timer_Periodo_Init(500);
	return 0;
}
// QUE HACER CUANDO SE GENERA LA INTERRUPCION
void TIM2_IRQHandler(void)
{
	GPIO_Toggle();
	NVIC_ClearPendingIRQ(TIM2_IRQn);
	// APAGAR BANDERA
	TIM2->SR &= ~(TIM_SR_UIF);
}
