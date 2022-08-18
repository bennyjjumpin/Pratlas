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

rev::CANSparkMax intakeRoller = rev::CANSparkMax(12, rev::CANSparkMax::MotorType::kBrushless);
rev::SparkMaxRelativeEncoder intakeRollerEncoder = intakeRoller.GetEncoder();

rev::CANSparkMax singulator = rev::CANSparkMax(13, rev::CANSparkMax::MotorType::kBrushless);
rev::SparkMaxRelativeEncoder singulatorEncoder = singulator.GetEncoder();

int singulatorTimer = 0;
int intakePower = 1;
};