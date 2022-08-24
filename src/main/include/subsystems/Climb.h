#pragma once

#include <rev/CANSparkMax.h>
#include <frc/Joystick.h>

class Climb
{
    public:
    void RobotInit();
    void RobotPeriodic();
    private:
    rev::CANSparkMax climbElevator = rev::CANSparkMax(41, rev::CANSparkMax::MotorType::kBrushless);
    rev::CANSparkMax climbPivot = rev::CANSparkMax(43, rev::CANSparkMax::MotorType::kBrushless);
    frc::Joystick secondary{1};
};