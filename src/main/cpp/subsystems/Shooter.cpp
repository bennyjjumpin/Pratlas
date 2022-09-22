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
    // FLY WHEEL INITIALIZATION
    shooterFlywheel.RestoreFactoryDefaults();
    shooterFlywheel.SetInverted(true);
    shooterFlywheel.EnableVoltageCompensation(10.5);

    flywheelPIDController.SetP(0.00045);
    flywheelPIDController.SetD(0.01);
    flywheelPIDController.SetFF(0.00023);
    
    hoodEncoder.SetPosition(0);
    
    shooterHoodPIDController.SetP(0.16);

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


    frc::SmartDashboard::PutBoolean("goodVariableName", secondary.GetRawButton(5) /*shift*/ && secondary.GetRawButton(2));
    if (secondary.GetRawButton(5) /*shift*/ && secondary.GetRawButtonPressed(2) /*button 2*/)
    {
        //ShootSetPoint(-14, 1850, -0.2); //Wall
         if (shooterState == WALLSHOT)
        {
            shooterState = IDLEMODE;
        }
        else
        {
            shooterState = WALLSHOT;
        }
    }
    if (secondary.GetRawButton(5) /*shift*/ && secondary.GetRawButtonPressed(1) /*button 1*/)
    {
        //ShootSetPoint(0, 1600, -0.2); //Fender
         if (shooterState == FENDERSHOT)
        {
            shooterState = IDLEMODE;
        }
        else
        {
            shooterState = FENDERSHOT;
        }
    }
    if (secondary.GetRawButton(5) /*shift*/ && secondary.GetRawButtonPressed(3) /*button 3*/)
    {
        //ShootSetPoint(-17.5, 1950, -0.3); //Launch Pad
        if (shooterState == LAUNCHPADSHOT)
        {
            shooterState = IDLEMODE;
        }
        else
        {
            shooterState = LAUNCHPADSHOT;
        }
    }
    if(secondary.GetRawButton(4) && !secondary.GetRawButton(5) && shooterState != IDLEMODE)
    {
        if(shooterState == LAUNCHPADSHOT)
        {
            ShootSetPoint(-17.5, 1800, 0.8); //Launch Pad
        }
        else if (shooterState == FENDERSHOT)
        {
            ShootSetPoint(0, 1600, 0.2); //Fender
        }
        else if (shooterState == WALLSHOT)
        {
            ShootSetPoint(-14, 1500, 0.5); //Wall
        }
    }
    else
    {
        shooterFlywheel.Set(0);
        shooterHoodPIDController.SetReference(0,rev::CANSparkMax::ControlType::kPosition,0);
        shooterLipRoller.Set(0);
        shooterReady = false;
    }
    
}