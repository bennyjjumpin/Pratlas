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
    intakeRoller.RestoreFactoryDefaults();
    intakeRoller.SetInverted(false);
    intakeRoller.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    intakeRoller.BurnFlash();
    intakeRollerEncoder.SetPosition(0);
    singulator.RestoreFactoryDefaults();
    singulator.SetInverted(false);
    singulator.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    singulator.BurnFlash();
    singulatorEncoder.SetPosition(0);
}

void Intake::RobotPeriodic()
{
    frc::SmartDashboard::PutNumber("IntakePivotEncoderValue",intakePivotEncoder.GetPosition());
    if (secondary.GetRawButton(1) && intakePivotEncoder.GetPosition() <= 4.571424)
    {
        intakePivot.Set(.4);
        intakeRoller.Set(-.4);
    }
    else if (!secondary.GetRawButton(1) && intakePivotEncoder.GetPosition() >= 0)
    {
        intakePivot.Set(-.4);
        singulatorTimer = 50;
    }
    else 
    {
        intakePivot.Set(0);
    }
    if (intakePivotEncoder.GetPosition() > 1)
    {
        
        singulator.Set(.4);
    }
    else
    {
        intakeRoller.Set(0);
    }
    if (singulatorTimer > 0)
    {
        singulatorTimer--;
        singulator.Set(.4);
    }
    else if (intakePivotEncoder.GetPosition() < 1)
    {
        singulator.Set(0);
    }
}
