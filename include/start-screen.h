#include "vex.h"
#include "robot-config.h"

// Initializes the start screen for the autonomous selection (WIP)
void startScreenInit(){
    Brain.Screen.drawImageFromFile("wingmanlogo.png", 0, 0);
}