
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// FLM                  motor         6
// FRM                  motor         20
// BLM                  motor         4
// BRM                  motor         8
// Intake               motor         10
// SideArm              motor         19
// Launcher             motor         9
// Elevator1            motor         1
// Elevator2            motor         7
// InertialSensor       inertial      5
// leftWing             digital_out   A
// rightWing            digital_out   B
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "robot-config.h"
#include "autonomous.hpp"
#include "button-controls.hpp"
#include "start-screen.hpp"

using namespace vex;

// A global instance of competition
competition Competition;

void pre_auton(void)
{
  // Initializing Robot Configuration and Autonomous Selection Screen
  vexcodeInit();
  StartScreenInit();
}

void autonomous(void)
{
  // ..........................................................................
  autonCode(auton);
  // ..........................................................................
}

void usercontrol(void)
{
  while (1)
  {
    // ........................................................................
    FLM.setVelocity((Controller1.Axis3.position() * flipInt + Controller1.Axis1.position()), percent);
    FRM.setVelocity((Controller1.Axis3.position() * flipInt - Controller1.Axis1.position()), percent);
    BLM.setVelocity((Controller1.Axis3.position() * flipInt + Controller1.Axis1.position()), percent);
    BRM.setVelocity((Controller1.Axis3.position() * flipInt - Controller1.Axis1.position()), percent);
    FLM.spin(forward);
    FRM.spin(forward);
    BLM.spin(forward);
    BRM.spin(forward);
    // ........................................................................

    wait(20, msec);
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main()
{
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  handleButtons();

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true)
  {
    wait(100, msec);
  }
}
