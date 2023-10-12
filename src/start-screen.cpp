#include "start-screen.hpp"
#include "vex.h"

int auton;

screenButton screenButton::createScreenButton(int xMin, int xMax, int yMin, int yMax) {
    screenButton button;
    button.X_min = xMin;
    button.X_max = xMax;
    button.Y_min = yMin;
    button.Y_max = yMax;
    return button;
}

bool screenButton::X_check() {
    if (Brain.Screen.xPosition() > X_min && Brain.Screen.xPosition() < X_max) {
        return true;
    } else {
        return false;
    }
}

bool screenButton::Y_check() {
    if (Brain.Screen.yPosition() > Y_min && Brain.Screen.yPosition() < Y_max) {
        return true;
    } else {
        return false;
    }
}

bool screenButton::isPressing() {
    if (X_check() && Y_check()) {
        return true;
    } else {
        return false;
    }
}

// Initializes all button objects
screenButton Auton1Button = screenButton::createScreenButton(0, 120, 0, 120);
screenButton Auton2Button = screenButton::createScreenButton(360, 480, 0, 120);
screenButton Auton3Button = screenButton::createScreenButton(0, 120, 120, 240);
screenButton Auton4Button = screenButton::createScreenButton(360, 480, 120, 240);
screenButton Auton5Button = screenButton::createScreenButton(120, 360, 0, 240);


void SelectedLogic(int selectedAuton) {
    auton = selectedAuton;

    switch (selectedAuton) {
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

void StartScreenInit() {
    Brain.Screen.drawImageFromFile("selection-screen.png", 0, 0);
    waitUntil(Brain.Screen.pressing());

    if (Auton1Button.isPressing()) {
        SelectedLogic(1);
    } else if (Auton2Button.isPressing()) {
        SelectedLogic(2);
    } else if (Auton3Button.isPressing()) {
        SelectedLogic(3);
    } else if (Auton4Button.isPressing()) {
        SelectedLogic(4);
    } else if (Auton5Button.isPressing()) {
        SelectedLogic(5);
    }
}
