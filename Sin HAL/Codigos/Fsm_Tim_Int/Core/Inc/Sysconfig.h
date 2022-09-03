/*
 * Sysconfig.h
 *
 *  Created on: 20-04-2022
 *      Author: Cristobal
 */

#ifndef INC_SYSCONFIG_H_
#define INC_SYSCONFIG_H_

#include "main.h"

#define M_PLL 4
#define N_PLL 84
#define P_PLL 0

void Sysconfig(void);

void SysTick_config(uint32_t systick_valor);

void msIncTick(void);

uint32_t msGetTick(void);

void delay_ms(uint32_t ms);

#endif /* INC_SYSCONFIG_H_ */
