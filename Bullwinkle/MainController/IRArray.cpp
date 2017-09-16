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

uint16_t* IRArray::get() {
	digitalWrite(pinLatch, HIGH);
	
	digitalWrite(pinPower, LOW);
	delay(2);
	digitalWrite(pinPower, HIGH);

	uint16_t dataArray[sensorCount];

	digitalWrite(pinLatch, LOW);

	for (uint16_t i = 0; i < resolution; i++) {
		for (uint8_t d = 0; d < byteCount; d++) {
			uint8_t raw = shiftIn(pinData, pinClock, MSBFIRST);
			for (uint8_t b = 0; b < 8; b++) {
				dataArray[d+b] += Phantom::getBit(raw, b);
			}
		}
	}
	return dataArray;
}

uint8_t IRArray::getBest() {
	uint16_t* data = get();
	uint8_t best;
	for (uint8_t i = 0; i < sensorCount; i++) {
		if (data[i] > data[best]) { best = i; }
	}
	return best;
}
