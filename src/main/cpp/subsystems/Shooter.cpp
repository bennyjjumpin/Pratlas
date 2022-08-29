#include "subsystems/Shooter.h"

void Shooter::RobotInit()
{
    shooterFlywheel.RestoreFactoryDefaults();
    shooterHoodPIDController.SetP(0.16);
    hoodEncoder.SetPosition(0);
    shooterFlywheel.SetInverted(true);
}
// Shooter Up: 0.078
// Shooter Down: 0.968
// ShooterHoodPIDValue: 0.16
void Shooter::RobotPeriodic()
{
     frc::SmartDashboard::PutNumber("shooterHoodPenis", hoodEncoder.GetPosition());
    if(secondary.GetRawButtonPressed(4))
    {
        flywheelToggle = !flywheelToggle;
    }
    if(flywheelToggle == true)
    {
        shooterFlywheel.Set(0.5);
        shooterHoodPIDController.SetReference(-10,rev::CANSparkMax::ControlType::kPosition,0);
    }

    else
    {
        shooterFlywheel.Set(0);
        shooterHoodPIDController.SetReference(0,rev::CANSparkMax::ControlType::kPosition,0);
    }
}