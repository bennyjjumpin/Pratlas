#include "subsystems/Shooter.h"

void Shooter::ShootSetPoint(double HoodPos, double WheelVel, double LipRollerVel)
{
    flywheelPIDController.SetReference(WheelVel,rev::CANSparkMax::ControlType::kVelocity,0);
    shooterHoodPIDController.SetReference(HoodPos,rev::CANSparkMax::ControlType::kPosition,0); // Sets the shooter hood to a certain position when the flywheel is toggled.
    shooterLipRoller.Set(LipRollerVel);

    if (flywheelEncoder.GetVelocity() >= WheelVel && hoodEncoder.GetPosition() <= (HoodPos + 0.2))
    {
        shooterReady = true;
    }
    else
    {
        shooterReady = false;
    }
}

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
    // else
    // {
    //     shooterReady = false;
    // }
    frc::SmartDashboard::PutNumber("flywheelVelocity", flywheelEncoder.GetVelocity());
    frc::SmartDashboard::PutNumber("hoodEncoder", hoodEncoder.GetPosition());


    frc::SmartDashboard::PutBoolean("AJKHDKAJSD", secondary.GetRawButton(5) /*shift*/ && secondary.GetRawButton(2));
    if (secondary.GetRawButton(5) /*shift*/ && secondary.GetRawButton(2) /*button 1*/)
    {
        ShootSetPoint(-16, 1800, -0.2);
    }
    else if (secondary.GetRawButton(5) /*shift*/ && secondary.GetRawButton(1) /*button 2*/)
    {
        ShootSetPoint(0, 1700, -0.2);
    }
    else if (secondary.GetRawButton(5) /*shift*/ && secondary.GetRawButton(3) /*button 3*/)
    {
        ShootSetPoint(-18, 3000, -0.2);
    }
    else
    {
        shooterFlywheel.Set(0);
        shooterHoodPIDController.SetReference(0,rev::CANSparkMax::ControlType::kPosition,0);
        shooterLipRoller.Set(0);
        shooterReady = false;
    }
}