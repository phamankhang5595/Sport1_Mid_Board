#ifndef _SYSTICK_H_
#define _SYSTICK_H_

#include "stm32f10x.h"
/*******************************************************************************
 * Definition
 ******************************************************************************/
#define MAXTICK			0xFFFFFFFF
/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * @brief functions init systick.
 *
 */
void SYSTICK_Init(void);

 /*!
 * @brief functions hander systick.
 *
 */
void SysTick_Handler(void);

/*!
 * @brief functions get tick.
 *
 */
uint32_t SYSTICK_Get_Tick(void);

/*!
 * @brief function to create delay.
 *
 */
void SYSTICK_Delay_ms(uint32_t time_ms);

#endif /*_SYSTICK_H_*/