#include "IRArray.h"

IR::IR(uint8_t powerPin, uint8_t clockPin, uint8_t latchPin, uint8_t _dataPin): _powerPin(powerPin), _clockPin(clockPin), _latchPin(latchPin), _dataPin(_dataPin) {
  _byteCount = 2;

  pinMode(_latchPin, OUTPUT);
  pinMode(_clockPin, OUTPUT);
  pinMode(_dataPin, INPUT);
  pinMode(_powerPin, OUTPUT);
}

IR::~IR() { /* NOTHING TO DECONSTRUCT */ }

float IR::getBest() {
  float avg = 0;
  refresh();
  avg += _best;
  refresh();
  avg += _best;
  refresh();
  avg += _best;
  avg /= 3;
  return avg;

}

void IR::refresh() {
  digitalWrite(_powerPin, LOW);
  delay(5);
  digitalWrite(_powerPin, HIGH);

  for (int i = 0; i < IR_SENSOR_COUNT; i++) {
    _dataArray[i] = 0;
  }

  for (int i = 0; i < _maxPulseLength; i++) {
    // pulse the latch to load the data
    digitalWrite(_clockPin, HIGH);
    digitalWrite(_latchPin, LOW);
    digitalWrite(_latchPin, HIGH);

    // Shift Data In
    _rawDataArray[1] = shiftIn(_dataPin, _clockPin, MSBFIRST);
    _rawDataArray[0] = shiftIn(_dataPin, _clockPin, MSBFIRST);

    // print pin data to serial monitor
    for (int b = 0; b < 8; b++) {
      _dataArray[b] += !bitRead(_rawDataArray[0], b);
    }
    for (int b = 0; b < 8; b++) {
      _dataArray[b+8] += !bitRead(_rawDataArray[1], b);
    }
  }

  _best = 0; // Reset Best

  for (int i = 0; i < IR_SENSOR_COUNT; i++) {
    if (_dataArray[i] > _dataArray[_best] and !(_dataArray[i] == _maxPulseLength) and _dataArray[i] > 25) {
      _best = i;
      
    }
    //SerialUSB.print(_dataArray[i]);
    //SerialUSB.print(", ");
  };
  //SerialUSB.println();
}