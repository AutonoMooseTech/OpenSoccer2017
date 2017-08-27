#include "SenseLightViaI2C.h"

SenseLightViaI2C::SenseLightViaI2C(uint8_t address, uint8_t id): address(address), id(id) {
	Wire.begin();
}

float SenseLightViaI2C::get() {
	Wire.beginTransmission(address);
	Wire.write("R");
	Wire.write(id);
	Wire.endTransmission();

	delay(1);

	while(Wire.available()) {
		reading = Phantom::map(Wire.read(), 0, 255, 0.0f, 1.0f);
	}

	return reading;
}
