#include "RobotMap.h"
#include "Robot.h"

using namespace Phantom;

Robot robot;
	
void setup() {
	TCCR0B = TCCR0B & B11111000 | B00000010;
	TCCR1B = TCCR1B & B11111000 | B00000010;
	TCCR2B = TCCR2B & B11111000 | B00000010;
	// I2C
	Wire.begin(8);
	Wire.onReceive(wireReceive);
	// Serial
	Serial.begin(57600);

	robot.setup();
}

void loop() {
	robot.loop();
	robot.update();
}

byte wireBytes[8] = {};

/*
E: Enable
D: Disable
o: Omni Drive (direction, speed);
*/

void wireReceive(uint8_t byteCount) {
	for (uint8_t i = 0; i < byteCount; i++) {
		wireBytes[i] = char(Wire.read());
	}

	switch(wireBytes[0]) {
		case 'E': robot.enable(); break;
		case 'D': robot.disable(); break;
		case 'O': 
			robot.omni.set(map(wireBytes[1], 0, 255, 0, 360),
				map(wireBytes[2], 0, 255, -1.0f, 1.0f));
			robot.i2cTimeout.pat();
			break;
	}
}
