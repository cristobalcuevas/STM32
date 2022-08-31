/*
 * Timer.c
 *
 *  Created on: Apr 27, 2022
 *      Author: Cristobal
 */

#include "Timer.h"

void Timer_Init_Delay(void)
{
	// HABILITAR CLOCK TIMER 2
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	// ASCENDENTE
	TIM2->CR1 &= ~(TIM_CR1_DIR);
	// MODO UNICO PULSO
	TIM2->CR1 |= TIM_CR1_OPM;
	// MODO RESET
	TIM2->CR2 &= ~(TIM_CR2_MMS);
	// PRESCALER
	TIM2->PSC = 0;
	// REGISTRO VALOR AUTOGUARDADO
	TIM2->ARR = 8399;
}
void Timer_delay(uint32_t delay)
{
	// PRESCALER
	TIM2->PSC = (delay*10)-1; // 1000 * 0.1ms = 100 ms
	// HABILITAR CONTADOR
	TIM2->CR1 |= TIM_CR1_CEN;
	// ESPERAR EVENTO
	while((TIM2->SR & TIM_SR_UIF) == 0);
	// APAGAR BANDERA
	TIM2->SR &= ~(TIM_SR_UIF);
}

