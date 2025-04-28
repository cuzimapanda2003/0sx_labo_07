#include "Alarm.h"

Alarm::Alarm(int rPin, int gPin, int bPin, int buzzerPin, float* distancePtr)
  : _rPin(rpin), _gPin(gPin), _bPin(bPin), _buzzerPin(buzzerPin), _distance(distancePtr) {
  pinMode(_rPin, OUTPUT);
  pinMode(_gPin, OUTPUT);
  pinMode(_bPin, OUTPUT);
  pinMode(_buzzerPin, OUTPUT);
  _turnOff();
}
