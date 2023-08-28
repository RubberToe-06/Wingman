#include "vex.h"
#include "robot-config.h"

float prevHeading;

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

// Used to make the robot drive forwards or backwards
// Can specify direction, how long it drives for, and the velocity
void autonDrive(directionType driveDirection, float timeSeconds, float driveVelocity)
{
  if (driveDirection == forward)
  {
    driveVelocities(driveVelocity);
    driveSpins(fwd,fwd,fwd,fwd);
    wait(timeSeconds, seconds); 
    driveStop();

  }
  else if (driveDirection == reverse)
  {
    driveVelocities(driveVelocity);
    driveSpins(reverse, reverse, reverse, reverse);
    wait(timeSeconds, seconds); 
    driveStop();

  }
  else
  {
    Brain.Screen.print("error: invalid autonomous function argument");
  }
}

// The most complex function in the whole program
// Used to turn the robot clockwise (right) or counterclockwise (left)
// Can specify the direction, how much it turns, and how fast it turns
void autonTurn(turnType turnDirection, float turnAngle, float turnVelocity)
{
  driveModes(hold);

  // Workaround for being unable to convert turnType to bool
  bool boolDirection;

  if (turnDirection == right){
    boolDirection = true;
  }
  else {
    boolDirection = false;
  }


  switch(boolDirection){
    case true:
    prevHeading = InertialSensor.heading(deg);
    driveVelocities(turnVelocity);
    driveSpins(forward, reverse, forward, reverse);

    if (prevHeading + turnAngle < 360){
      waitUntil(InertialSensor.heading(deg) > prevHeading + turnAngle);
      driveStop(); return;
    }
    else{
      waitUntil(InertialSensor.heading(deg) > 1 && InertialSensor.heading(deg) < 90);
      waitUntil(InertialSensor.heading(deg) >= (prevHeading + turnAngle) - 360);
      driveStop(); return;
    }
    

    case false:
    prevHeading = InertialSensor.heading(deg) + 1;
    driveVelocities(turnVelocity);
    driveSpins(reverse, forward, reverse, forward);

    if (prevHeading - turnAngle > 0){
      waitUntil(InertialSensor.heading(deg) <= prevHeading - turnAngle);
      driveStop(); return;
    }
    else {
      waitUntil(InertialSensor.heading(deg) > 350 && InertialSensor.heading(deg) <= 360);
      waitUntil(InertialSensor.heading(deg) <= 360 - (turnAngle - prevHeading));
      driveStop(); return;
    }
  }
}

// Code for autonomous period based off the selection screen
void autonCode(int version){
  switch (version)
  {
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    default:
      break;
    }
}