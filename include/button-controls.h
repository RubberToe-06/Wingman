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

void LauncherControls(void){
  Launcher1.setVelocity(100, pct);
  Launcher2.setVelocity(100, pct);
  Launcher1.spin(forward);
  Launcher2.spin(forward);
  waitUntil(!Controller1.ButtonX.pressing());
  waitUntil(Controller1.ButtonX.pressing());
  Launcher1.stop();
  Launcher2.stop();
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

  // Toggles the Triball launcher
  Controller1.ButtonX.pressed(LauncherControls);
}