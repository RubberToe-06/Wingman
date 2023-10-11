#include "vex.h"
#include "button-controls.hpp"

int flipInt = 1;

//Flips the robot's controls to make it easier to use front and back manipulators
void FlipControls(){  
  flipInt *= -1;
  Controller1.rumble(".");
}

// Toggles the wings on the sides of the robot
void WingControls(void){
  if (Controller1.ButtonL2.pressing()){
    if (leftWing.value()){
      leftWing.set(false);
    }
    else {
      leftWing.set(true);
    }
  }
  if (Controller1.ButtonR2.pressing()){
    if (rightWing.value()){
      rightWing.set(false);
    }
    else {
      rightWing.set(true);
    }
  }
}

// Toggles the intake motor forwards or reverse
void IntakeControls(){
  Intake.setStopping(hold);
  Intake.setVelocity(100, pct);
  if (Controller1.ButtonA.pressing()){
    Intake.spin(forward);
    waitUntil(!Controller1.ButtonA.pressing());
    waitUntil((Controller1.ButtonA.pressing() || Controller1.ButtonB.pressing()) || Intake.torque(Nm) > 90);
    if (Controller1.ButtonB.pressing()){
      IntakeControls();
    }
    else{
      Intake.stop();
    }
  }
  else if (Controller1.ButtonB.pressing()){
    Intake.spin(reverse);
    waitUntil(!Controller1.ButtonB.pressing());
    waitUntil((Controller1.ButtonB.pressing() || Controller1.ButtonA.pressing()) || Intake.torque(Nm) > 90);
    if (Controller1.ButtonA.pressing()){
      IntakeControls();
    }
    else{
      Intake.stop();
    }
  }
}

// Controls the triball launcher
void LauncherControls(void){
  Launcher.setVelocity(45, pct);
  Launcher.spin(forward);
  waitUntil(!Controller1.ButtonX.pressing());
  waitUntil(Controller1.ButtonX.pressing());
  Launcher.stop();
}

// Handles the callback functions for the controller buttons
void handleButtons(void){
  // Controls the robot orientation
  Controller1.ButtonY.pressed(FlipControls);

  // Controls the push wings
  Controller1.ButtonL2.pressed(WingControls);
  Controller1.ButtonR2.pressed(WingControls);

  // Toggles the intake motor
  Controller1.ButtonA.pressed(IntakeControls);
  Controller1.ButtonB.pressed(IntakeControls);

  // Toggles the Triball launcher
  Controller1.ButtonX.pressed(LauncherControls);
}