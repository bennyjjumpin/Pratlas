#include <frc/Joystick.h>
#include "Subsystems/Intake.h"
#include <frc/SmartDashboard/SmartDashboard.h>

void Intake::RobotInit()
{
    intakePivot.RestoreFactoryDefaults();
    intakePivot.SetInverted(false);
    intakePivot.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    pivotPIDController.SetP(0.15,0);
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
    
    //pivotPIDController.SetReference(5.5,rev::CANSparkMax::ControlType::kPosition,0);
}

void Intake::RobotPeriodic()
{
    if (zeroed)
    {
        frc::SmartDashboard::PutNumber("intakePivotPosition", intakePivotEncoder.GetPosition());
        if (singulatorTimer > 0) // Makes the singulator run a little after the intake is deactivated.
        {
            singulatorTimer--;
            singulator.Set(0.4);
        }
        else
        {
            singulator.Set(0);
        }
        if (secondary.GetRawAxis(3) > 0.1 && !secondary.GetRawButton(5)) // if button 1 is pressed it will activate all necessary motors for the intake.
        {
            pivotPIDController.SetReference(5.5,rev::CANSparkMax::ControlType::kPosition,0);
            intakeRoller.Set(-0.5);
        }
        else if (secondary.GetRawButton(1) && !secondary.GetRawButton(5)) // if button 2 is pressed it will activate all necessary motors for the outtake.
        {
            pivotPIDController.SetReference(5.5,rev::CANSparkMax::ControlType::kPosition,0);
            intakeRoller.Set(0.5);
            singulator.Set(-0.6);
        }
        else if (!(secondary.GetRawAxis(3) > 0.1 || secondary.GetRawButton(1)) && intakePivotEncoder.GetPosition() >= 0 && !secondary.GetRawButton(5))
        {

            pivotPIDController.SetReference(0,rev::CANSparkMax::ControlType::kPosition,0);
            intakeRoller.Set(0);
            if (intakePivotEncoder.GetPosition() >= 2)
            {
                singulatorTimer = 50; 
            }
        }
        else
        {
            pivotPIDController.SetReference(0,rev::CANSparkMax::ControlType::kPosition,0);
            intakeRoller.Set(0);
        }
        
        if (intakePivotEncoder.GetPosition() > 1)
        {
            singulator.Set(intakePower * .4);
        }
        
        
    }
    else if (intakePivotAbsoluteEncoder.GetOutput() < 0.615 && !zeroed)
    {
        intakePivot.Set(-.4);
    }
    else 
    {
        zeroed = true;
        intakePivot.Set(0);
        intakePivotEncoder.SetPosition(0);
    }
    frc::SmartDashboard::PutNumber("Intake Power", intakePivot.Get());
    frc::SmartDashboard::PutBoolean("zeroed", zeroed);
}

