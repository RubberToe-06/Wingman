#include "vex.h"
#include "autonomous.hpp"

// Defining used variables
float prevHeading;
const float wheelCircum = 10;
int degreesToSpin;

// Shorthand for setting drivetrain velocities
// @param number how fast the drivetrain will drive
void driveVelocities(float number)
{
  FLM.setVelocity(number, pct);
  FRM.setVelocity(number, pct);
  BLM.setVelocity(number, pct);
  BRM.setVelocity(number, pct);
}

// Shorthand for stopping the drivetrain
void driveStop()
{
  FLM.stop();
  FRM.stop();
  BLM.stop();
  BRM.stop();
}

// Shorthand for activating the drivetrain motors all at once
void driveSpins(directionType FLMr, directionType FRMr, directionType BLMr, directionType BRMr)
{
  FLM.spin(FLMr);
  FRM.spin(FRMr);
  BLM.spin(BLMr);
  BRM.spin(BRMr);
}

// Shorthand for setting a drivetrain stopping mode
// @param type what type of stopping mode the drivetrain switches to
void driveModes(brakeType type)
{
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
    degreesToSpin = (distance * (1 / wheelCircum) * 360);
    driveVelocities(driveVelocity);
    FLM.spinFor(fwd, degreesToSpin, deg, false);
    FRM.spinFor(fwd, degreesToSpin, deg, false);
    BLM.spinFor(fwd, degreesToSpin, deg, false);
    BRM.spinFor(fwd, degreesToSpin, deg, true);
  }
  else if (driveDirection == reverse)
  {
    degreesToSpin = (distance * (1 / wheelCircum) * 360);
    driveVelocities(driveVelocity);
    FLM.spinFor(reverse, degreesToSpin, deg, false);
    FRM.spinFor(reverse, degreesToSpin, deg, false);
    BLM.spinFor(reverse, degreesToSpin, deg, false);
    BRM.spinFor(reverse, degreesToSpin, deg, true);
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

  if (turnDirection == right)
  {
    boolDirection = true;
  }
  else
  {
    boolDirection = false;
  }

  switch (boolDirection)
  {
  case true:
    prevHeading = InertialSensor.heading(deg);
    driveVelocities(turnVelocity);
    driveSpins(forward, reverse, forward, reverse);
    wait(0.2, sec);
    if (prevHeading + turnAngle < 360)
    {
      waitUntil(InertialSensor.heading(deg) > prevHeading + turnAngle);
      driveStop();
      return;
    }
    else
    {
      waitUntil(InertialSensor.heading(deg) > 1 && InertialSensor.heading(deg) < 90);
      waitUntil(InertialSensor.heading(deg) >= (prevHeading + turnAngle) - 360);
      driveStop();
      return;
    }

  case false:
    prevHeading = InertialSensor.heading(deg);
    driveVelocities(turnVelocity);
    driveSpins(reverse, forward, reverse, forward);
    wait(0.2, sec);
    if (prevHeading - turnAngle > 0)
    {
      waitUntil(InertialSensor.heading(deg) <= prevHeading - turnAngle);
      driveStop();
      return;
    }
    else
    {
      waitUntil(InertialSensor.heading(deg) > 350 && InertialSensor.heading(deg) <= 360);
      waitUntil(InertialSensor.heading(deg) <= 360 - (turnAngle - prevHeading));
      driveStop();
      return;
    }
  }
}

// Opens or closes the wings during autonomous
// @param value specifies what value the solenoids will be set to
void autonSetWings(bool value)
{
  leftWing.set(value);
  rightWing.set(value);
}

// Raises or lowers the arm by 90 degrees
// @param value specifies what the value of the arm is set to (true => down, false => up)
void autonSetArm(bool value)
{
  SideArm.setVelocity(100, pct);
  if (value)
  {
    SideArm.spinFor(-90, deg);
    return;
  }
  SideArm.spinFor(90, deg);
}

// AUTONOMOUS ROUTINES

//........................................................................................

// Autonomous routine for playing on the offensive side
void OffensiveAutonCode()
{
  Intake.setStopping(hold);
  SideArm.setStopping(hold);
  autonDrive(forward, 53, 45);
  autonTurn(right, 86, 25);
  Intake.spin(reverse, 100, pct);
  autonDrive(forward, 11, 50);
  wait(0.5, sec);
  Intake.stop();
  autonDrive(reverse, 12, 50);
  autonTurn(left, 120, 30);
  Intake.spin(forward, 100, pct);
  autonDrive(forward, 8, 50);
  autonTurn(right, 120, 50);
  autonDrive(forward, 12, 50);
  Intake.spin(reverse, 100, pct);
  autonDrive(forward, 6, 50);
  autonDrive(reverse, 6, 50);
  autonDrive(forward, 6, 50);
  autonDrive(reverse, 6, 50);
}

// Autonomous routine for playing on the defensive side
void DefensiveAutonCode()
{
  SideArm.spin(reverse);
  Intake.spin(reverse);
  wait(0.5, sec);
  Elevator1.spin(reverse, 12, volt);
  Elevator2.spin(forward, 12, volt);
  autonTurn(left, 90, 50);
  SideArm.stop();
  Intake.stop();
  SideArm.spinFor(90, deg);
  autonTurn(right, 55, 50);
  autonDrive(reverse, 24, 50);
  autonTurn(left, 3, 25);
  autonDrive(reverse, 16, 25);
  wait(2, sec);
  Elevator1.stop();
  Elevator2.stop();
}

// Autonomous routine for the Programming Skills Challenge
void SkillsAutonCode()
{
  autonDrive(forward, 24, 50);
  autonTurn(right, 40, 25);
  autonDrive(reverse, 27, 50);
  Launcher.spinFor(45, turns);
}
//........................................................................................

// Code for autonomous period based off the selection screen
// @param version which version of the autonomous code the driver selects
void autonCode(int version)
{
  switch (version)
  {
  case 1:
    OffensiveAutonCode();
    break;
  case 2:
    DefensiveAutonCode();
    break;
  case 3:
    DefensiveAutonCode();
    break;
  case 4:
    OffensiveAutonCode();
    break;
  case 5:
    SkillsAutonCode();
    break;
  default:
    break;
  }
}
