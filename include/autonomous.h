#include "vex.h"
#include "robot-config.h"

// All functions starting with "drive" are shorthands for repitition's sake

// Shorthand for setting drivetrain velocities
void driveVelocities(float number){
  FLM.setVelocity(number, pct);
  FRM.setVelocity(number, pct);
  BLM.setVelocity(number, pct);
  BRM.setVelocity(number, pct);
}

// Shorthand for stopping the drivetrain
void driveStop(){
  FLM.stop();
  FRM.stop();
  BLM.stop();
  BRM.stop();
}

// Shorthand for activating the drivetrain
void driveSpins(directionType FLMr, directionType FRMr, directionType BLMr, directionType BRMr){
  FLM.spin(FLMr);
  FRM.spin(FRMr);
  BLM.spin(BLMr);
  BRM.spin(BRMr);
}

// Shorthand for setting a drivetrain stopping mode
void driveModes(brakeType type){
  FLM.setStopping(type);
  FRM.setStopping(type);
  BLM.setStopping(type);
  BRM.setStopping(type);
}

// Code for autonomous period (WIP)
void auton(int version){
    switch (version)
    {
      case: 1
        break;
      case: 2
        break;
      case: 3
        break;
      case: 4
        break;
      default:
        break;
    }
}