#include "vex.h"
#include "robot-config.h"

int flipInt = 1;

//Flips the robot's controls to make it easier to use front and back manipulators
void YbuttonCode(){
  flipInt *= -1;
}