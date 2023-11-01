#ifndef START_SCREEN_H
#define START_SCREEN_H

#include "vex.h"
#include "robot-config.h"
#include <vector>

extern int auton;

class screenButton
{
public:
    int X_min;
    int X_max;
    int Y_min;
    int Y_max;

    static screenButton createScreenButton(int xMin, int xMax, int yMin, int yMax);

    bool isPressing();

private:
    bool X_check();
    bool Y_check();
};

void SelectedLogic(int selectedAuton);
void StartScreenInit();

#endif
