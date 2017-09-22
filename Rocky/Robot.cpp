#include "Robot.h"

float whiteValue = 0;
float blackValue = 0;

Robot::Robot():
	RobotBase(),
	ultraLeft(4, 5),
	ultraRight(A2, A1),
	ultraBack(0, 0),
	lightLeft(A0),
	lightRight(A1),
	gyro(0x68),
	ir(10, A4, A3, A5),
	pixy(0x54),
	motorA(0x08, 11, 13, 12),
	motorB(0x08, 5, 10, 9),
	motorC(0x08, 6, 7, 8),
	motorD(0x08, 3, 4, 2),
	omni(motorA, motorB, motorC, motorD),
	ledEnable(0),
	ledSide(1),
	ledPixyEnable(2),
	switchEnable(3),
	switchSide(4),
	switchPixyEnable(5)
	{
	motorA.setMax(180);
	motorB.setMax(140);
	motorC.setMax(180);
	motorD.setMax(140);
}

void Robot::setup() {
	switchEnable.setPullup(true);
	switchSide.setPullup(true);
	switchPixyEnable.setPullup(true);
	gyro.init();
	gyro.reset();
	pixy.init();
}

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
}

float i;

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
	omni.set(angle, 0.4, rotation);
	SerialUSB.println(angle);
}