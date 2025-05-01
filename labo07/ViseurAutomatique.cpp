#include "ViseurAutomatique.h"

ViseurAutomatique::ViseurAutomatique(int p1, int p2, int p3, int p4, float& distanceRef)
  : _stepper(AccelStepper::HALF4WIRE, p1, p3, p2, p4),
    _distance(distanceRef) {
  _stepper.setMaxSpeed(500.0);
  _stepper.setAcceleration(100.0);
}

ViseurAutomatique::update(){
    switch (_etat) {
    case INACTIF:
   
      break;
    case SUIVI:

      break;
    case REPOS:
    
      break;

  }

}