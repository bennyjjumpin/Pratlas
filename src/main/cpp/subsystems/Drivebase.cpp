#include "subsystems/Drivebase.h"

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
    /*if(abs(Primary.GetRawAxis(1)) >= 0.02)
    {
         dbL.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, Primary.GetRawAxis(1) * 0.35);
    }
    else
    {
        dbL.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
        
    }
    if(abs(Primary.GetRawAxis(5)) >= 0.02)
        {
           dbR.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, Primary.GetRawAxis(5) * 0.35);
        }
        else
        {
            dbR.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0);
        }*/
    dbL.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, Primary.GetRawAxis(1));
    dbR.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, Primary.GetRawAxis(5)); // The speed is set to the axis value from 0-1 but multiplied by 0.35.
}
