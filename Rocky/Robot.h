#ifndef ROBOT_H
#define ROBOT_H

#include <Phantom.h>
#include <Arduino.h>
#include <RobotBase.h>

#include <Wire.h>
#include <Ultrasonic.h>
#include <NXTLightSensor.h>
#include <MPU9250Gyro.h>
#include <OmniDrive.h>
#include "I2CMotor.h"
#include "IRArray.h"
#include <PixyI2C.h>
#include <DigitalOutput.h>
#include <DigitalInput.h>

class Robot:
	public Phantom::RobotBase {
public:
	// Sensors
	Phantom::Ultrasonic ultraLeft;
	Phantom::Ultrasonic ultraRight;
	Phantom::Ultrasonic ultraBack;
	Phantom::NXTLightSensor lightLeft;
	Phantom::NXTLightSensor lightRight;
	Phantom::MPU9250Gyro gyro;
	IR ir;
	PixyI2C pixy;

	// Motors
	I2CMotor motorA;
	I2CMotor motorB;
	I2CMotor motorC;
	I2CMotor motorD;
	Phantom::OmniDrive omni;

	// Other
	Phantom::DigitalOutput ledEnable;
	Phantom::DigitalOutput ledSide;
	Phantom::DigitalOutput ledPixyEnable;
	Phantom::DigitalInput switchEnable;
	Phantom::DigitalInput switchSide;
	Phantom::DigitalInput switchPixyEnable;

	Robot();

	void setup();
	void loop();
	void disabledSetup();
	void disabledLoop();
	void enabledSetup();
	void enabledLoop();
private:
};

#endif
