using namespace vex;

extern brain Brain;

// VEXcode devices

// Controller used for controling the robot
extern controller Controller1;

// Drivetrain motors used to move the robot around the field
extern motor FLM;
extern motor FRM;
extern motor BLM;
extern motor BRM;

// Inertial sensor used to get the orientation of the robot
extern inertial InertialSensor;

// Solenoids used to control the pushing wings
extern digital_out leftWing;
extern digital_out rightWing;

// Motor for the Triball intake
extern motor Intake;

// Motor for the AWP arm
extern motor SideArm;

// Motor for the Triball launcher
extern motor Launcher;

// Motors for the elevator/blocker
extern motor Elevator1;
extern motor Elevator2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);