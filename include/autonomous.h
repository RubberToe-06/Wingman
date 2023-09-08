#include "vex.h"
#include "robot-config.h"

float prevHeading;

float wheelCircum = 10;
int degreesToSpin;

// All functions starting with "drive" are shorthands for repitition's sake

// Shorthand for setting drivetrain velocities
// @param number how fast the drivetrain will drive
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
// @param type what type of stopping mode the drivetrain switches to
void driveModes(brakeType type){
  FLM.setStopping(type);
  FRM.setStopping(type);
  BLM.setStopping(type);
  BRM.setStopping(type);
}

// Drives the robot in a straight line during autonomous
// @param driveDirection determines if the robot will drive forwards or backwards
// @param distance tells the robot how far to drive (in inches)
// @param driveVelocity specifies how fast the robot will drive
void autonDrive(directionType driveDirection, float distance, float driveVelocity)
{
  if (driveDirection == forward)
  {
    degreesToSpin = (distance * (1/wheelCircum) * 360);
    driveVelocities(driveVelocity);
    FLM.spinFor(fwd, degreesToSpin, deg, false);
    FRM.spinFor(fwd, degreesToSpin, deg, false);
    BLM.spinFor(fwd, degreesToSpin, deg, false);
    BRM.spinFor(fwd, degreesToSpin, deg, false);
    waitUntil(InertialSensor.acceleration(xaxis) > 3);
    waitUntil(InertialSensor.acceleration(xaxis) < 3);
    driveStop();

  }
  else if (driveDirection == reverse)
  {
    degreesToSpin = (distance * (1/wheelCircum) * 360);
    driveVelocities(driveVelocity);
    FLM.spinFor(reverse, degreesToSpin, deg);
    FRM.spinFor(reverse, degreesToSpin, deg);
    BLM.spinFor(reverse, degreesToSpin, deg);
    BRM.spinFor(reverse, degreesToSpin, deg);
    waitUntil(InertialSensor.acceleration(xaxis) > 3);
    waitUntil(InertialSensor.acceleration(xaxis) < 3);
    driveStop();

  }
  else
  {
    Brain.Screen.print("error: invalid autonomous function argument");
  }
}


// Turns the robot during autonomous
// @param turnDirection specifies wether the robot turns left or right
// @param turnAngle specifies how many degrees the robot will turn
// @param turnVelocity determines how fast the robot will turn
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

// Opens or closes the wings during autonomous
// @param value specifies what value the solenoids will be set to
void autonSetWings(bool value){
  leftWing.set(value);
  rightWing.set(value);
}

// Code for autonomous period based off the selection screen
// @param version which version of the autonomous code the driver selects
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