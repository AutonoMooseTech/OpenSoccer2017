#include "I2CRemoteControl.h"

I2CRemoteControl::I2CRemoteControl(uint8_t address): address(address) {
 // blah blah
}

void I2CRemoteControl::init() {
	Wire.begin(address);
}

void I2CRemoteControl::onReceive() {
	type = Wire.read();
	mode = Wire.read();
	pin = Wire.read();
	if (mode == 'W') {
		pinMode(pin, OUTPUT);
		output = Wire.read();
		if (type == 'D') {
			digitalWrite(pin, output);
		}
		else {
			analogWrite(pin, output);
		}
	}
}

void I2CRemoteControl::onRequest() {
	pinMode(pin, INPUT);
	if (type == 'D') {
		Wire.write(digitalRead(pin));
	}
	else {
		Wire.write(Phantom::map(analogRead(pin), 0, 1023, 0, 255));
	}
}