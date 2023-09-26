#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor FLM = motor(PORT10, ratio18_1, true);
motor FRM = motor(PORT20, ratio18_1, false);
motor BLM = motor(PORT9, ratio18_1, true);
motor BRM = motor(PORT19, ratio18_1, false);
inertial InertialSensor = inertial(PORT18);
digital_out leftWing = digital_out(Brain.ThreeWirePort.A);
digital_out rightWing = digital_out(Brain.ThreeWirePort.B);
motor Intake = motor(PORT17, ratio18_1, false);
motor Launcher = motor(PORT1, ratio36_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}