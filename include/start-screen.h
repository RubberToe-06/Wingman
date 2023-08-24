#include "vex.h"
#include "robot-config.h"

int auton;

void selectedLogic(int selectedAuton){

    auton = selectedAuton;

    switch (selectedAuton)
    {
    case 1:
        Brain.Screen.clearScreen();
        Brain.Screen.drawImageFromFile("auton1-selected.png", 0, 0);
        wait(1.5, sec);
        Brain.Screen.clearScreen();
        Brain.Screen.drawImageFromFile("wingman-blue.png");
        break;
    case 2:
        Brain.Screen.clearScreen();
        Brain.Screen.drawImageFromFile("auton2-selected.png", 0, 0);
        wait(1.5, sec);
        Brain.Screen.clearScreen();
        Brain.Screen.drawImageFromFile("wingman-red.png");
        break;
    case 3:
        Brain.Screen.clearScreen();
        Brain.Screen.drawImageFromFile("auton3-selected.png", 0, 0);
        wait(1.5, sec);
        Brain.Screen.clearScreen();
        Brain.Screen.drawImageFromFile("wingman-blue.png");
        break;
    case 4:
        Brain.Screen.clearScreen();
        Brain.Screen.drawImageFromFile("auton4-selected.png", 0, 0);
        wait(1.5, sec);
        Brain.Screen.clearScreen();
        Brain.Screen.drawImageFromFile("wingman-red.png");
        break;
    case 5:
        Brain.Screen.clearScreen();
        Brain.Screen.drawImageFromFile("skills-auton-selected.png", 0, 0);
        wait(1.5, sec);
        Brain.Screen.clearScreen();
        Brain.Screen.drawImageFromFile("wingman-blue.png");
        break;
    default:
        break;
    }

}

// Initializes the start screen for the autonomous selection (WIP)
void startScreenInit(){
    Brain.Screen.drawImageFromFile("selection-screen.png", 0, 0);
    waitUntil(Brain.Screen.pressing());

    if (Brain.Screen.xPosition() < 120 && Brain.Screen.yPosition() < 120){
        selectedLogic(1);
    }
    else if (Brain.Screen.xPosition() < 120 && Brain.Screen.yPosition() > 120){
        selectedLogic(2);
    }
    else if (Brain.Screen.xPosition() > 360 && Brain.Screen.yPosition() < 120){
        selectedLogic(3);
    }
    else if (Brain.Screen.xPosition() > 360 && Brain.Screen.yPosition() > 120){
        selectedLogic(4);
    }
    else if (Brain.Screen.xPosition() > 120 && Brain.Screen.xPosition() < 360){
        selectedLogic(5);
    }
}