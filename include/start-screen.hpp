#include "vex.h"
#include "robot-config.h"
#include <vector>

int auton;

// Class for all buttons on the Bain UI
class screenButton {
public:
    int X_min;
    int X_max;
    int Y_min;
    int Y_max;

    static screenButton createScreenButton(int xMin, int xMax, int yMin, int yMax) {
        screenButton button;
        button.X_min = xMin;
        button.X_max = xMax;
        button.Y_min = yMin;
        button.Y_max = yMax;
        return button;
    }

private:
    bool X_check() {
        if (Brain.Screen.xPosition() > X_min && Brain.Screen.xPosition() < X_max) {
            return true;
        }
        else {
            return false;
        }
    }

    bool Y_check() {
        if (Brain.Screen.yPosition() > Y_min && Brain.Screen.yPosition() < Y_max) {
            return true;
        }
        else {
            return false;
        }
    }

public:
    bool isPressing() {
        if (X_check() && Y_check()) {
            return true;
        }
        else {
            return false;
        }
    }
};

// Initializes all button objects
screenButton auton1Button = screenButton::createScreenButton(0, 120, 0, 120);
screenButton auton2Button = screenButton::createScreenButton(360, 480, 0, 120);
screenButton auton3Button = screenButton::createScreenButton(0, 120, 120, 240);
screenButton auton4Button = screenButton::createScreenButton(360, 480, 120, 240);
screenButton auton5Button = screenButton::createScreenButton(120, 360, 0, 240);

// Handles the screen printing logic for every possible selection
// @param selectedAuton which auton the driver selected
void selectedLogic(int selectedAuton){

    auton = selectedAuton;

    switch (selectedAuton)
    {
    case 1:
        Brain.Screen.drawImageFromFile("auton1-selected.png", 0, 0);
        wait(1, sec);
        Brain.Screen.drawImageFromFile("wingman-blue.png", 0, 0);
        break;
    case 2:
        Brain.Screen.drawImageFromFile("auton2-selected.png", 0, 0);
        wait(1, sec);
        Brain.Screen.drawImageFromFile("wingman-blue.png", 0, 0);
        break;
    case 3:
        Brain.Screen.drawImageFromFile("auton3-selected.png", 0, 0);
        wait(1, sec);
        Brain.Screen.drawImageFromFile("wingman-red.png", 0, 0);
        break;
    case 4:
        Brain.Screen.drawImageFromFile("auton4-selected.png", 0, 0);
        wait(1, sec);
        Brain.Screen.drawImageFromFile("wingman-red.png", 0, 0);
        break;
    case 5:
        Brain.Screen.drawImageFromFile("skills-auton-selected.png", 0, 0);
        wait(1, sec);
        Brain.Screen.drawImageFromFile("wingman-purple.png", 0, 0);
        break;
    default:
        break;
    }

}

// Initializes the start screen for the autonomous selection
void startScreenInit(){
    Brain.Screen.drawImageFromFile("selection-screen.png", 0, 0);
    waitUntil(Brain.Screen.pressing());

    if (auton1Button.isPressing()){
        selectedLogic(1);
    }
    else if (auton2Button.isPressing()){
        selectedLogic(3);
    }
    else if (auton3Button.isPressing()){
        selectedLogic(2);
    }
    else if (auton4Button.isPressing()){
        selectedLogic(4);
    }
    else if (auton4Button.isPressing()){
        selectedLogic(5);
    }
}