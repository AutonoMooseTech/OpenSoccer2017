#include "IRArray.h"

IRArray::IRArray(uint8_t pinPower, uint8_t pinLatch, uint8_t pinClock, uint8_t pinData, uint8_t sensorCount):
	pinPower(pinPower),
	pinLatch(pinLatch),
	pinClock(pinClock),
	pinData(pinData),
	sensorCount(sensorCount) {
	// Pin Modes
	pinMode(pinPower, OUTPUT);
	pinMode(pinLatch, OUTPUT);
	pinMode(pinClock, OUTPUT);
	pinMode(pinData, INPUT);
	byteCount = ceil(sensorCount / 8);
}

bool* IRArray::get() {
	digitalWrite(pinLatch, HIGH);
	digitalWrite(pinPower, HIGH);
	delay(1);
	digitalWrite(pinLatch, LOW);

	for (int i = 0; i < byteCount; i++) {
		uint8_t raw = shiftIn(pinData, pinClock, MSBFIRST);
	}
}
