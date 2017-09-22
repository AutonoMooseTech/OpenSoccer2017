#include "Robot.h"

const float whiteValue = 0.15;
const float blackValue = 0.08;

Robot::Robot():
	RobotBase(),
	ultraLeft(4, 5),
	ultraRight(A0, 13),
	ultraBack(12, 11),
	lightLeft(A1),
	lightRight(A2),
	gyro(0x68),
	ir(10, A4, A3, A5),
	pixy(0x54),
	//encoderA(11, 12),
	//encoderB(A0, 13),
	//encoderC(6, 7),
	//encoderD(8, 9),
	motorA(0x08, 6, 10, 11),
	motorB(0x08, 5, 8, 7),
	motorC(0x08, 9, 14, 15),
	motorD(0x08, 3, 2, 4),
	omni(motorA, motorB, motorC, motorD),
	kicker(6),
	ledEnable(0),
	ledSide(1),
	ledPixyEnable(2),
	switchEnable(3),
	switchSide(4),
	switchPixyEnable(5)
	{
	motorA.setMax(140);
	motorB.setMax(140);
	motorC.setMax(140);
	motorD.setMax(140);
	kicker.setDuration(150);
}

void Robot::setup() {
	switchEnable.setPullup(true);
	switchSide.setPullup(true);
	switchPixyEnable.setPullup(true);
	gyro.init();
	gyro.reset();
	pixy.init();
}

float gyroValue = 0;

void Robot::loop() {
	setState(state_t(switchEnable.get()));
	ledSide.set(switchSide.get());
	ledPixyEnable.set(switchPixyEnable.get());
}

void Robot::disabledSetup() {
	ledEnable.set(LOW);
	motorA.disable();
	motorB.disable();
	motorC.disable();
	motorD.disable();
	kicker.forceOff();
	pixy.setLED(0, 0, 0);
}

void Robot::disabledLoop() {
	motorA.disable();
	motorB.disable();
	motorC.disable();
	motorD.disable();
}

void Robot::enabledSetup() {
	ledEnable.set(HIGH);
	gyro.reset();
	//pixy.setLED(255, 225, 0);
}

void Robot::enabledLoop() {
	float angle;
	int irBest = ir.getBest();
	if (irBest == 7 or irBest == 8) {
		angle = 0;
	}
	else angle = (irBest - 7.5) * 22.5 * 1.4; // old: angle = (((irBest - 0.5) * 22.5) - 180) * 1.8;
	
	// Constraints (line detection)
	float leftConstrain = lightLeft.get() > (whiteValue + blackValue) / 2 ? 5 : -270;
	float rightConstrain = lightRight.get() > (whiteValue + blackValue) / 2 / 2 ? -5 : 270;
	//angle = Phantom::constrain(angle, leftConstrain, rightConstrain);
	// Rotation
	float rotation;

	gyro.update(); // Refresh
	rotation = gyro.getZ() / 45;

	if (switchPixyEnable.get()) { // Pixy centering
		uint16_t blocks = pixy.getBlocks();
		for (uint16_t i = 0; i < blocks; i++) {
			if (pixy.blocks[i].signature = switchSide.get() + 1) {
				float x = pixy.blocks[i].x;
				float width = pixy.blocks[i].width;
				rotation = x + (width / 2);
				rotation -= (PIXY_MAX_X/2);
				rotation /= -PIXY_MAX_X;
			}
		}
	}
	// Set Drive
	omni.set(angle, 0.6, rotation);
	SerialUSB.println(angle);

	// Kicker
	if (switchPixyEnable.get()) {
		uint16_t blocks = pixy.getBlocks();
		for (uint16_t i = 0; i < blocks; i++) {
			if (pixy.blocks[i].signature = switchSide.get() + 1) {
				if (pixy.blocks[i].width > 250) { kicker.trigger(); }
			}
		}
	}
}