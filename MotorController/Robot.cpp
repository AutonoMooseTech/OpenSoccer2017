#include "Robot.h"

Robot::Robot():
	RobotBase(),
	motorA(MOTOR_FR_PWM, MOTOR_FR_A, MOTOR_FR_B),
	motorB(MOTOR_BR_PWM, MOTOR_BR_A, MOTOR_BR_B),
	motorC(MOTOR_BL_PWM, MOTOR_BL_A, MOTOR_BL_B),
	motorD(MOTOR_FL_PWM, MOTOR_FL_A, MOTOR_FL_B),
	omni(motorA, motorB, motorC, motorD)
	{
  
}

void Robot::setup() {
	// Max Motor Voltage of ~6V
	motorA.setMax(127);
	motorB.setMax(127);
	motorC.setMax(127);
	motorD.setMax(127);
}

void Robot::loop() {
	omni.set(0, -0.0f);
}

void Robot::disabledSetup() {
	omni.set(0, 0);
	motorA.disable();
	motorB.disable();
	motorC.disable();
	motorD.disable();
}

void Robot::disabledLoop() {
}

void Robot::enabledSetup() {

}

void Robot::enabledLoop() {

}
