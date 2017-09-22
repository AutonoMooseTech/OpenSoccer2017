#include "I2CRemoteControl.h"

I2CRemoteControl ctrl(0x08);
	
void setup() {
	TCCR0B = TCCR0B & B11111000 | B00000001;
	TCCR1B = TCCR1B & B11111000 | B00000001;
	TCCR2B = TCCR2B & B11111000 | B00000001;
	// I2C
	ctrl.init();
	// Serial
	//Serial.begin(57600);
	Wire.onReceive(wireReceive);
	Wire.onRequest(wireRequest);
}

void loop() {
}

void wireReceive(uint8_t byteCount) {
	ctrl.onReceive();
}

void wireRequest() {
	ctrl.onRequest();
}
