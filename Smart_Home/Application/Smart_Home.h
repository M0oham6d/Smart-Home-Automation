/*
 * Smart_Home.h
 * Author: Muhammed Ayman
 * Application: Smart Home
 */

#ifndef APPLICATION_SMART_HOME_H_
#define APPLICATION_SMART_HOME_H_

#include "../HAL/flame_sensor.h"
#include "../HAL/buzzer.h"
#include "../HAL/lcd.h"
#include "../HAL/ldr_sensor.h"
#include "../HAL/leds.h"
#include "../HAL/lm35_sensor.h"
#include "../HAL/motor.h"

/*******************************************************************************
 *                      	Functions Prototypes                               *
 *******************************************************************************/

/*
 * Function to measure temperature and set up the motor speed according to temperature.
 * If temperature < 25	--> STOP MOTOR.
 * Else if temperature >= 25 && temperature < 30	--> Start MOTOR	with minimum speed.
 * Else if temperature >= 30 && temperature < 35	--> Start MOTOR	with second speed.
 * Else if temperature >= 35 && temperature < 40	--> Start MOTOR	with third speed.
 * Else if temperature > 40 --> Start MOTOR with MAX speed.
 */
void moving_motor_according_to_temp_and_display_res(void);

/*
 * Function to turn on leds in dark spaces using LDR sensor.
 * If light intensity < 15 --> Turn on all LEDs.
 * Else if light intensity >= 15 && < 50 --> Turn on 2 LEDs only.
 * Else if light intensity >= 50 && < 70 --> Turn on 1 LEDs only.
 * Else if light intensity >= 70 --> Turn off all LEDs.
 */
void automatic_light(void);

/*
 * Function to make alert if there is a fire.
 * If flame sensor detects fire, buzzer will turn on and display alert on LCD and stop all application.
 * else, buzzer is off the the system does the normal operation
 */
void fire_allert(void);

#endif /* APPLICATION_SMART_HOME_H_ */
