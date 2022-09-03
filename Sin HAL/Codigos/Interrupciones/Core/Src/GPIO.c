/*
 * GPIO.c
 *
 *  Created on: 20-04-2022
 *      Author: Cristobal
 */

#include "GPIO.h"

void GPIO_Init_Read(void){
	// PULSADOR -> RC13
	RCC->AHB1ENR	|= RCC_AHB1ENR_GPIOCEN; // HABILITA CLOCK PUERTO C
	GPIOC->MODER	&= ~(GPIO_MODER_MODE13); // CLEAR
	GPIOC->OTYPER	&= ~(GPIO_OTYPER_OT13); // SALIDA PUSH PULL
	GPIOC->OSPEEDR	&= ~(GPIO_OSPEEDR_OSPEED13); // VELOCIDAD DE CONMUTACION BAJA
	GPIOC->PUPDR	&= ~(GPIO_PUPDR_PUPD13); // CLEAR
	GPIOC->PUPDR	|= ~(GPIO_PUPDR_PUPD13_0); // HABILITAR PULL UP PARA TENER SIEMPRE 1 LOGICO
}

GPIO_State GPIO_Read(void){
	if(GPIOC->IDR & GPIO_IDR_ID13){
		return HIGH;
	}
	else{
		return LOW;
	}
}

void GPIO_Write(GPIO_State state){
	if(state == HIGH){
		GPIOA->ODR |= GPIO_ODR_OD5;
	}
	else{
		GPIOA->ODR &= ~(GPIO_ODR_OD5);
	}
}

void GPIO_Toggle(void){
	GPIOA->ODR ^= GPIO_ODR_OD5;
}
