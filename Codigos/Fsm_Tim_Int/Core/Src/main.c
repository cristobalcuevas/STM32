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
#include "Int.h"

static __IO uint32_t estado = 0;

int main(void)
{
	Sysconfig();
	SysTick_Config(84000);
	GPIO_Init_Read();
	Int_Init();
	//Timer_Periodo_Init(500);
	//Timer_Init_Delay();
	while(1)
	{
		switch(estado)
		{
		case 0:
			GPIO_Toggle();
			delay_ms(100);
			break;
		case 1:
			GPIO_Write(HIGH);
			Timer_Periodo_Init(1000);
			estado = 2;
			break;
		case 2:
			break;
		case 3:
			GPIO_Write(LOW);
			break;
		default:
			GPIO_Write(LOW);
			break;
		}
	}
	return 0;
}
void EXTI15_10_IRQHandler(void)
{
	// LIMPIAR BANDERA
	NVIC_ClearPendingIRQ(EXTI15_10_IRQn);
	EXTI->PR |= EXTI_PR_PR13;
	estado = 1;
}
void TIM2_IRQHandler(void)
{
	NVIC_ClearPendingIRQ(TIM2_IRQn);
	// APAGAR BANDERA
	TIM2->SR &= ~(TIM_SR_UIF);
	if(estado == 2)
	{
		estado = 3;
	}
	else
	{
		estado = 2;
	}
}
