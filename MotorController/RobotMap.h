// Robot Map

#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include <Arduino.h>
#include <Phantom.h>

// Power/Drive Train (w/ wire color)

const uint8_t MOTOR_FR_PWM 	= 6; 	// Yellow
const uint8_t MOTOR_FR_A	= 10; 	// Green
const uint8_t MOTOR_FR_B	= 11; 	// Blue

const uint8_t MOTOR_BR_PWM 	= 5; 	// Orange
const uint8_t MOTOR_BR_A	= 8; 	// Grey
const uint8_t MOTOR_BR_B	= 7; 	// White

const uint8_t MOTOR_BL_PWM 	= 9; 	// Yellow
const uint8_t MOTOR_BL_A	= A0; 	// Grey
const uint8_t MOTOR_BL_B	= A1; 	// White

const uint8_t MOTOR_FL_PWM= 3;  // Orange
const uint8_t MOTOR_FL_A  = 2;  // Green
const uint8_t MOTOR_FL_B  = 4;  // Blue

#endif
