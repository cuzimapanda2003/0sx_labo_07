#include "ViseurAutomatique.h"

ViseurAutomatique::ViseurAutomatique(int p1, int p2, int p3, int p4, float& distanceRef)
  : _stepper(AccelStepper::HALF4WIRE, p1, p3, p2, p4),
    _distance(distanceRef) {
  _stepper.setMaxSpeed(500.0);
  _stepper.setAcceleration(100.0);
}

void ViseurAutomatique::update() {
  unsigned long currentTime = millis();
  switch (_etat) {
    case INACTIF:
      _inactifState(currentTime);
      break;
    case SUIVI:
      _suiviState(currentTime);
      break;
    case REPOS:
      _reposState(currentTime);
      break;
  }
  _stepper.run();
}

void ViseurAutomatique::setAngleMin(float angle) {
  _angleMin = angle;
}

void ViseurAutomatique::setAngleMax(float angle) {
  _angleMax = angle;
}

void ViseurAutomatique::setPasParTour(int steps) {
  _stepsPerRev = steps;
}

void ViseurAutomatique::setDistanceMinSuivi(float distanceMin) {
  _distanceMinSuivi = distanceMin;
}

void ViseurAutomatique::setDistanceMaxSuivi(float distanceMax) {
  _distanceMaxSuivi = distanceMax;
}
float ViseurAutomatique::getAngle() const {
  return (_stepper.currentPosition() * 360.0) / _stepsPerRev;
}

void ViseurAutomatique::activer() {
  _etat = REPOS;
}

void ViseurAutomatique::desactiver() {
  _etat = INACTIF;
}

const char* ViseurAutomatique::getEtatTexte() const {
  switch (_etat) {
    case INACTIF: return "INACTIF";
    case SUIVI: return "SUIVI";
    case REPOS: return "REPOS";
    default: return "INCONNU";
  }
}


void ViseurAutomatique::_inactifState(unsigned long cT) {
  _stepper.disableOutputs();
}

void ViseurAutomatique::_suiviState(unsigned long cT) {
  if (_distance < _distanceMinSuivi || _distance > _distanceMaxSuivi) {
    _etat = REPOS;
    return;
  }
  float ratio = (_distance - _distanceMinSuivi) / (_distanceMaxSuivi - _distanceMinSuivi);
  float angle = _angleMin + (_angleMax - _angleMin) * (1.0 - ratio); 
  long steps = _angleEnSteps(angle);
  _stepper.moveTo(steps);
}

void ViseurAutomatique::_reposState(unsigned long cT) {
  if (_distance >= _distanceMinSuivi && _distance <= _distanceMaxSuivi) {
    _etat = SUIVI;
  }
}


long ViseurAutomatique::_angleEnSteps(float angle) const {
  return (long)(_stepsPerRev * angle / 360.0);
}