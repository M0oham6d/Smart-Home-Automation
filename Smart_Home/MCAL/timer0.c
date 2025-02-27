/*
 * timer0.c
 * Author: Muhammed Ayman
 * Module: Timer0
 */

#include "timer0.h"

/*******************************************************************************
 *                      	Functions Definitions                              *
 *******************************************************************************/

/*
 * Function to initialize Timer0 with Fast PWM mode.
 */
#if (TIMER0_MODE == PWM)
void PWM_Timer0_Start(uint8 duty_cycle)
{
	TCNT0 = 0; 							/* Set Timer Initial value. */

	OCR0  = (duty_cycle * 255) / 100; 	/* Set Compare Value. */

	DDRB  = DDRB | (1<<PB3); 			/* set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC. */

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/1024 CS00=1 CS00=0 CS02=1
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00) | (1<<CS02);
}

#endif
