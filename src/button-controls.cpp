#include "vex.h"
#include "button-controls.hpp"

int flipInt = 1;

// Flips the robot's controls to make it easier to use front and back manipulators
void FlipControls()
{
  flipInt *= -1;
  Controller1.rumble(".");
}

// Code for the side wings
void WingControls(void)
{
  if (Controller1.ButtonL2.pressing())
  {
    if (leftWing.value())
    {
      leftWing.set(false);
    }
    else
    {
      leftWing.set(true);
    }
  }
  if (Controller1.ButtonR2.pressing())
  {
    if (rightWing.value())
    {
      rightWing.set(false);
    }
    else
    {
      rightWing.set(true);
    }
  }
}

// Code for the triball intake
void IntakeControls()
{
  Intake.setStopping(hold);
  Intake.setVelocity(100, pct);
  if (Controller1.ButtonA.pressing())
  {
    Intake.spin(forward);
    waitUntil(!Controller1.ButtonA.pressing());
    waitUntil((Controller1.ButtonA.pressing() || Controller1.ButtonB.pressing()) || Intake.torque(Nm) > 90);
    if (Controller1.ButtonB.pressing())
    {
      IntakeControls();
    }
    else
    {
      Intake.stop();
    }
  }
  else if (Controller1.ButtonB.pressing())
  {
    Intake.spin(reverse);
    waitUntil(!Controller1.ButtonB.pressing());
    waitUntil((Controller1.ButtonB.pressing() || Controller1.ButtonA.pressing()) || Intake.torque(Nm) > 90);
    if (Controller1.ButtonA.pressing())
    {
      IntakeControls();
    }
    else
    {
      Intake.stop();
    }
  }
}

// Code for the AWP arm
void SideArmControls(void)
{
  SideArm.setStopping(hold);
  if (Controller1.ButtonRight.pressing())
  {
    SideArm.setVelocity(100, pct);
    SideArm.spinFor(90, deg);
    SideArm.stop();
    waitUntil(Controller1.ButtonLeft.pressing());
    SideArmControls();
  }
  else
  {
    SideArm.setVelocity(50, pct);
    SideArm.spinFor(-90, deg);
    SideArm.stop();
    waitUntil(Controller1.ButtonRight.pressing());
    SideArmControls();
  }
}

// Code for the triball launcher
void LauncherControls(void)
{
  Launcher.setStopping(coast);
  Launcher.setVelocity(100, pct);
  Launcher.spin(reverse);
  waitUntil(!Controller1.ButtonX.pressing());
  waitUntil(Controller1.ButtonX.pressing());
  Launcher.stop();
}

// Code for the elevation/blocker
void ElevatorControls()
{
  Elevator1.setStopping(hold);
  Elevator2.setStopping(hold);
  if (Controller1.ButtonUp.pressing())
  {
    Elevator1.spin(reverse, 10, volt);
    Elevator2.spin(forward, 10, volt);
    waitUntil(!Controller1.ButtonUp.pressing());
    Elevator1.stop();
    Elevator2.stop();
  }
  if (Controller1.ButtonDown.pressing())
  {
    Elevator1.spin(forward, 10, volt);
    Elevator2.spin(reverse, 10, volt);
    waitUntil(!Controller1.ButtonDown.pressing());
    Elevator1.stop();
    Elevator2.stop();
  }
}

// Code that helps Ian not be dumb and elevate properly
void IanProof()
{
  SideArm.spin(fwd, 12, volt);
}

// Handles the callback functions for the controller buttons
void handleButtons(void)
{
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

  // Controls the Elevation/Blocker arms
  Controller1.ButtonUp.pressed(ElevatorControls);
  Controller1.ButtonDown.pressed(ElevatorControls);

  // Controls the Side Arm
  Controller1.ButtonRight.pressed(SideArmControls);
  Controller1.ButtonLeft.pressed(SideArmControls);

  Controller1.ButtonR1.pressed(IanProof);
}