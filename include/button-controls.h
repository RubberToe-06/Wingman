#include "vex.h"
#include "robot-config.h"

int flipInt = 1;

//Flips the robot's controls to make it easier to use front and back manipulators
void FlipControls(){
  flipInt *= -1;
}

// Toggles the wings on the sides of the robot
void WingControls(void){
  waitUntil(Controller1.ButtonL2.pressing() && Controller1.ButtonR2.pressing());

  if (leftWing.value()){
    leftWing.set(false);
    rightWing.set(false);
  }
  else{
    leftWing.set(true);
    rightWing.set(true);
  }
}

// Toggles the intake motor forwards or reverse
void IntakeControls(void){
  Intake.setVelocity(100, pct);
  Intake.spin(forward);
  waitUntil(!Controller1.ButtonA.pressing());
  waitUntil(Controller1.ButtonA.pressing() || Controller1.ButtonB.pressing());
  if (Controller1.ButtonA.pressing()){
    Intake.stop();
  }
  else{
    Intake.setVelocity(100, pct);
    Intake.spin(reverse);
    waitUntil(!Controller1.ButtonB.pressing());
    waitUntil(Controller1.ButtonB.pressing() || Controller1.ButtonA.pressing());
    if (Controller1.ButtonB.pressing()){
      Intake.stop();
    }
    else{
      IntakeControls();
    }
  }
}

void RevIntakeControls(void){
  Intake.setVelocity(100, pct);
  Intake.spin(reverse);
  waitUntil(!Controller1.ButtonB.pressing());
  waitUntil(Controller1.ButtonB.pressing() || Controller1.ButtonA.pressing());
  if (Controller1.ButtonB.pressing()){
    Intake.stop();
  }
  else{
    IntakeControls();
  }
}

void handleButtons(){
  // Controls the robot orientation
  Controller1.ButtonY.pressed(FlipControls);

  // Controls the push wings
  Controller1.ButtonL2.pressed(WingControls);
  Controller1.ButtonR2.pressed(WingControls);

  // Toggles the intake motor
  Controller1.ButtonA.pressed(IntakeControls);
  Controller1.ButtonB.pressed(IntakeControls);
}