#include "subsystems/Shooter.h"

void Shooter::RobotInit()
{
    shooterFlywheel.RestoreFactoryDefaults();
    shooterHoodPIDController.SetP(0.16);
    hoodEncoder.SetPosition(0);
    shooterFlywheel.SetInverted(true);
    flywheelPIDController.SetP(0.00045);
    flywheelPIDController.SetD(0.01);
    flywheelPIDController.SetFF(0.00023);
}
// Shooter Up: 0.078
// Shooter Down: 0.968
// ShooterHoodPIDValue: 0.16
void Shooter::RobotPeriodic()
{
    if(secondary.GetRawButton(4))
    {
        flywheelPIDController.SetReference(1000,rev::CANSparkMax::ControlType::kVelocity,0);
        shooterHoodPIDController.SetReference(-10,rev::CANSparkMax::ControlType::kPosition,0); // Sets the shooter hood to a certain position when the flywheel is toggled.
        if (flywheelEncoder.GetVelocity() >= 1000 && hoodEncoder.GetPosition() <= -9.8)
        {
            shooterReady = true;
        }
        else
        {
            shooterReady = false;
        }
    }
    else
    {
        shooterFlywheel.Set(0);
        shooterHoodPIDController.SetReference(0,rev::CANSparkMax::ControlType::kPosition,0);
    }
}