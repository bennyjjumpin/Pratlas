#include "subsystems/Climb.h"
void Climb::RobotPeriodic()
{
   //climbElevator.Set(secondary.GetRawAxis(1) * 0.5);
   //climbPivot.Set(secondary.GetRawAxis(5) * 0.75); // Sets the motor speed to the axis value from 0-1 multiplied by a value to make it slower.
}

void Climb::RobotInit()
{
   climbElevator.RestoreFactoryDefaults();
   climbPivot.RestoreFactoryDefaults();
}