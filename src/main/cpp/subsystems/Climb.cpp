#include "subsystems/Climb.h"
void Climb::RobotPeriodic()
{
   climbElevator.Set(secondary.GetRawAxis(1) * 0.5);
   climbPivot.Set(secondary.GetRawAxis(5) * 0.75);
}

void Climb::RobotInit()
{
   climbElevator.RestoreFactoryDefaults();
   climbPivot.RestoreFactoryDefaults();
}