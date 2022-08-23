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
    dbR.SetInverted(true);
    dbRF.SetInverted(true);

    dbL.SetNeutralMode(ctre::phoenix::motorcontrol::Coast);
    dbLF.SetNeutralMode(ctre::phoenix::motorcontrol::Coast);
    dbR.SetNeutralMode(ctre::phoenix::motorcontrol::Coast);
    dbRF.SetNeutralMode(ctre::phoenix::motorcontrol::Coast);


}

/*void Drivebase::RobotPeriodic()
{
    if(abs(Primary.GetRawAxis(1)) >= 0.02)
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
        }
}*/
