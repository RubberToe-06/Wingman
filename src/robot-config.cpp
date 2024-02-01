#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain Brain;

// VEXcode device constructors

//.............................................................
// Controller
controller Controller1 = controller(primary);

// Drivetrain motors
motor FLM = motor(PORT21, ratio18_1, true);
motor FRM = motor(PORT9, ratio18_1, false);
motor BLM = motor(PORT8, ratio18_1, true);
motor BRM = motor(PORT11, ratio18_1, false);

// Inertial sensor
inertial InertialSensor = inertial(PORT20);

// Wing solenoids
digital_out leftWing = digital_out(Brain.ThreeWirePort.A);
digital_out rightWing = digital_out(Brain.ThreeWirePort.B);

// Manipulator motors
motor Intake = motor(PORT6, ratio18_1, false);
motor SideArm = motor(PORT7);
motor Launcher = motor(PORT10, ratio36_1, false);
motor Elevator1 = motor(PORT2, ratio18_1, false);
motor Elevator2 = motor(PORT3, ratio18_1, false);
//.............................................................

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void)
{
  // nothing to initialize
}