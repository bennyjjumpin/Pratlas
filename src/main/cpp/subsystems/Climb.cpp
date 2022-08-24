#include "subsystems/Climb.h"
void Climb::RobotPeriodic()
{
   climbElevator.Set(secondary.GetRawAxis(1) * 0.3);
   climbPivot.Set(secondary.GetRawAxis(5) * 0.3);
}