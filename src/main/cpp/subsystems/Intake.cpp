#include <frc/Joystick.h>
#include "Subsystems/Intake.h"
#include <frc/SmartDashboard/SmartDashboard.h>

void Intake::RobotInit()
{
    intakePivot.RestoreFactoryDefaults();
    intakePivot.SetInverted(false);
    intakePivot.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    intakePivot.BurnFlash();
    intakePivotEncoder.SetPosition(0);
}

void Intake::RobotPeriodic()
{
    frc::SmartDashboard::PutNumber("IntakePivotEncoderValue",intakePivotEncoder.GetPosition());
    if (secondary.GetRawButton(1) && intakePivotEncoder.GetPosition() <= 4.571424)
    {
        intakePivot.Set(.4);
    }
    else if (!secondary.GetRawButton(1) && intakePivotEncoder.GetPosition() >= 0)
    {
        intakePivot.Set(-.4);
    }
    else 
    {
        intakePivot.Set(0);
    }
}