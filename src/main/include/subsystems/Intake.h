#pragma once
#include <frc/Joystick.h>
#include <rev/CANSparkMax.h>

class Intake
{
public:
void RobotInit();
void RobotPeriodic();
void DisabledInit();
private:
rev::CANSparkMax intakePivot = rev::CANSparkMax(11, rev::CANSparkMax::MotorType::kBrushless);
frc::Joystick secondary{ 1 };
rev::SparkMaxRelativeEncoder intakePivotEncoder = intakePivot.GetEncoder();
};