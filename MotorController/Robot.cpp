#include "Robot.h"

Robot::Robot():
	RobotBase(),
	motorA(MOTOR_FR_PWM, MOTOR_FR_A, MOTOR_FR_B),
	motorB(MOTOR_BR_PWM, MOTOR_BR_A, MOTOR_BR_B),
	motorC(MOTOR_BL_PWM, MOTOR_BL_A, MOTOR_BL_B),
	motorD(MOTOR_FL_PWM, MOTOR_FL_A, MOTOR_FL_B),
	omni(motorA, motorB, motorC, motorD),
	i2cTimeout(100)
	{
  	motorA.setMax(140);
	motorB.setMax(140);
	motorC.setMax(140);
	motorD.setMax(140);

	i2cTimeout.addInstance({motorA, motorB, motorC, motorD});
}

void Robot::setup() {
}

void Robot::loop() {
	i2cTimeout.check();
}

void Robot::disabledSetup() {
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
