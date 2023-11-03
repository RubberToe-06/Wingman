#ifndef BUTTON_CONTROLS_H
#define BUTTON_CONTROLS_H

#include "vex.h"
#include "robot-config.h"

extern int flipInt;

// Current mapped button(s): Y
void FlipControls(void);

// Current mapped button(s): L2 + R2
void WingControls(void);

// Current mapped button(s): A
void IntakeControls(void);

// Current mapped button(s): X
void LauncherControls(void);

// Current mapped button(s): <- + ->
void SideArmControls(void);

// Current mapped button(s): ↑ + ↓
void ElevatorControls(void);

// Handles the callback functions for the controller buttons
void handleButtons(void);

#endif