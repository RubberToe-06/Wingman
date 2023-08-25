using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor FLM;
extern motor FRM;
extern motor BLM;
extern motor BRM;
extern inertial InertialSensor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );