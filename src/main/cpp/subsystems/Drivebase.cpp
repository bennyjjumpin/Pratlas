#include "subsystems/Drivebase.h"
#include <frc/SmartDashboard/SmartDashboard.h>

void Drivebase::RobotInit()
{
  dbL.ConfigFactoryDefault();
    dbLF.ConfigFactoryDefault();
    dbR.ConfigFactoryDefault();
    dbRF.ConfigFactoryDefault();
    
    dbRF.Follow(dbR);
    dbLF.Follow(dbL);

    dbL.SetInverted(false);
    dbLF.SetInverted(false);
    dbR.SetInverted(true); // These motors are set inverted so that the numbers are postive to move the robot forward for all motors.
    dbRF.SetInverted(true);

    dbL.SetNeutralMode(ctre::phoenix::motorcontrol::Brake);
    dbLF.SetNeutralMode(ctre::phoenix::motorcontrol::Brake);
    dbR.SetNeutralMode(ctre::phoenix::motorcontrol::Brake);
    dbRF.SetNeutralMode(ctre::phoenix::motorcontrol::Brake); // Sets the motors to brake mode while the robot is in neutral


}

void Drivebase::RobotPeriodic()
{
    frc::SmartDashboard::PutBoolean("Axis1Greaterthan0.08", Axis1Deadzone);
    frc::SmartDashboard::PutBoolean("Axis5Greaterthan0.08", Axis5Deadzone);
    if (Primary.GetRawAxis(1) > 0.08 || Primary.GetRawAxis(1) < -0.08)
    {
        dbL.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, Primary.GetRawAxis(1) * 0.75);
        Axis1Deadzone = true;
    }
    else
    {
        Axis1Deadzone = false;
        dbL.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
    }
    if (Primary.GetRawAxis(5) > 0.08 || Primary.GetRawAxis(5) < -0.08)
    {
        dbR.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, Primary.GetRawAxis(5) * 0.75);
        Axis5Deadzone = true;
    }
    else
    {
        dbR.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
        Axis5Deadzone = false;
    } 

   // dbL.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, Primary.GetRawAxis(1));
   // dbR.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, Primary.GetRawAxis(5)); // The speed is set to the axis value from 0-1 but multiplied by 0.35.
}
