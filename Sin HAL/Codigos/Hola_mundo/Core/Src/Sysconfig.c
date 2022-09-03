/*
 * Sysconfig.c
 *
 *  Created on: 13-04-2022
 *      Author: Cristobal
 */

#include "Sysconfig.h"

void Sysconfig(void){
	// M N P
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLM); // MACROS PARA LLENAR CON 1 PERO AL NEGAR PASA A 0 COMO UN CLEAR
	RCC->PLLCFGR |= N_PLL<<6; // COLOCOCAR EL VALOR 84 EN EL REGISTRO PLLCFGR SUMANDO EN LA POSICION 6
	RCC->PLLCFGR |= P_PLL<<16;
	RCC->PLLCFGR |= M_PLL<<0;
	//HSE
	RCC->CR |= RCC_CR_HSEON; //HABILITA EL OSCILADOR HSE CLOCK EXTERNO 8MHz
	while((RCC->CR & RCC_CR_HSERDY) == 0); // VERIFICA QUE EL OSCILADOR HSE ESTE INICIALIZADO

	// PLL
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSE; // LE DECIMOS AL PLL QUE USAREMOS LA FUENTE EXTERNA HSE
	RCC->CR |= RCC_CR_PLLON; //HABILITA PLL
	while((RCC->CR & RCC_CR_PLLRDY) == 0); // VERIFICA QUE EL PLL ESTE INICIALIZADO

	// PREFETCH
	FLASH->ACR &= ~(FLASH_ACR_LATENCY); // DEJA EN CERO EL REGISTRO, ES COMO UN CLEAR
	FLASH->ACR |= FLASH_ACR_PRFTEN; // HABILITA EL PREFETCH
	FLASH->ACR |= FLASH_ACR_LATENCY_2WS; // FIJA LA LATENCIA EN 2 ESTADOS

	// RELOJ DE SISTEMA
	RCC->CFGR &= ~(RCC_CFGR_SW); // LIMPIAR REGISTRO
	RCC->CFGR |= RCC_CFGR_SW_PLL; // USAR COMO RELOJ DE SISTEMA EL PLL O USAR RCC_CFGR_SWS_1
	while((RCC->CFGR & RCC_CFGR_SWS) == 0); // VERIFICAR ESTADO DEL RELOJ

	// AHB
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1; // SE DIVIVDE EN 1, TAMBIEN SE USA &= ~(RCC_CFGR_HPRE)

	// APB1
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2; // SE DIVIDE EN 2, TAMBIEN SE USA RCC_CFGR_PPRE1_2

	// APB2
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1; // SE DIVIDE EN 1, TAMBIEN SE USA &= ~(RCC_CFGR_PPRE2)













}