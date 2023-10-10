#ifndef BUTTON_CONTROLS_H
#define BUTTON_CONTROLS_H

#include "vex.h"
#include "robot-config.h"

extern int flipInteger;

// Current mapped button(s): Y
void FlipControls(void);

// Current mapped button(s): L1 + L2
void WingControls(void);

// Current mapped button(s): A
void IntakeControls(void);

// Current mapped button(s): X
void LauncherControls(void);


// Handles the callback functions for the controller buttons
void handleButtons(void);


#endif