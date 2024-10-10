/*
 * motor.c
 * Author: Muhammed Ayman
 * Module: DC Motor
 */

#include "motor.h"

/*******************************************************************************
 *                      	Functions Definitions                              *
 *******************************************************************************/

/*
 * Function to initialize DC motor.
 */
void DcMotor_Init(void)
{
	/*
	 * Setup pin direction for INT1 & INT2 as output.
	 * Setup pin direction for Enable as output.
	 * */
	GPIO_setupPinDirection(PORT_CONNECTION, PIN_INT1, PIN_OUTPUT);
	GPIO_setupPinDirection(PORT_CONNECTION, PIN_INT2, PIN_OUTPUT);
	GPIO_setupPinDirection(ENABLE_PORT_CONNECTION, ENABLE_PIN, PIN_OUTPUT);

	/* Stop the motor at the beginning. */
	GPIO_writePin(PORT_CONNECTION, PIN_INT1, LOGIC_LOW);
	GPIO_writePin(PORT_CONNECTION, PIN_INT2, LOGIC_LOW);
}

/*
 * Function to rotate the motor.
 * Rotate in CW or CCW or STOP the motor.
 * Control the motor speed using PWM.
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed)
{
#ifdef MOTOR_MODE_PWM
	PWM_Timer0_Start(speed);
#endif

	switch (state)
	{
	case STOP:
		GPIO_writePin(PORT_CONNECTION, PIN_INT1, LOGIC_LOW);
		GPIO_writePin(PORT_CONNECTION, PIN_INT2, LOGIC_LOW);
		break;

	case CW:
		GPIO_writePin(PORT_CONNECTION, PIN_INT1, LOGIC_HIGH);
		GPIO_writePin(PORT_CONNECTION, PIN_INT2, LOGIC_LOW);
		break;
	case CCW:
		GPIO_writePin(PORT_CONNECTION, PIN_INT1, LOGIC_LOW);
		GPIO_writePin(PORT_CONNECTION, PIN_INT2, LOGIC_HIGH);
		break;
	}
}
