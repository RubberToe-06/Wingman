#include "vex.h"
#include "robot-config.h"

int flipInt = 1;

//Flips the robot's controls to make it easier to use front and back manipulators
void YbuttonCode(){
  flipInt *= -1;
}

// Toggles the wings on the sides of the robot
void AbuttonCode(){
  if (leftWing.value()){
    leftWing.set(false);
    rightWing.set(false);
  }
  else{
    leftWing.set(true);
    rightWing.set(true);
  }
}

void handleButtons(){
  // Controls the robot orientation
  Controller1.ButtonY.pressed(YbuttonCode);

  // Controls the push wings
  Controller1.ButtonA.pressed(AbuttonCode);
}