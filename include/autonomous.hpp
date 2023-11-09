#ifndef AUTONOMOUS_H
#define AUTONOMOUS_H

#include "vex.h"
#include "robot-config.h"

extern float prevHeading;
extern const float wheelCircum;
extern int degreesToSpin;

// Drivetrain configuration functions

void driveVelocities(float number);
void driveStop();
void driveSpins(directionType FLMr, directionType FRMr, directionType BLMr, directionType BRMr);
void driveModes(brakeType type);

// Autonomous control functions

void autonDrive(directionType driveDirection, float distance, float driveVelocity);
void autonTurn(turnType turnDirection, float turnAngle, float turnVelocity);
void autonSetWings(bool value);
void autonSetArm(bool value);

// Autonomous routines
void OffensiveAutonCode();
void DefensiveAutonCode();
void SkillsAutonCode();

void autonCode(int version);

#endif