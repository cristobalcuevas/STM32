/*
 * main.c
 *
 *  Created on: Apr 20, 2022
 *      Author: Cristobal
 */

#include "main.h"
#include "Sysconfig.h"
#include "GPIO.h"
#include "Int.h"
uint32_t flag = 0;

int main(void)
{
	Sysconfig();
	SysTick_Config(84000);
	//GPIO_Init();
	Int_Init();
	// GPIO_Init_Read(); // CONFIGURA PC13 COMO ENTRADA
	while(1)
	{
		if(flag == 1)
		{
			GPIO_Toggle();
			delay_ms(250);
			flag = 0;
		}
		//GPIO_Write(HIGH);
		//GPIO_Write(LOW);
		//if(GPIO_Read() == LOW){
			//GPIO_Toggle();
			//delay_ms(250);
		//}
	}
	return 0;
}

void EXTI15_10_IRQHandler(void)
{
	// LIMPIAR BANDERA
	NVIC_ClearPendingIRQ(EXTI15_10_IRQn);
	EXTI->PR |= EXTI_PR_PR13;
	flag = 1;
}
