#include "subsystems/Drivebase.h"

void Drivebase::RobotInit()
{
    dbL.RestoreFactoryDefaults();
    dbR.RestoreFactoryDefaults();
    dbLF.RestoreFactoryDefaults();
    dbRF.RestoreFactoryDefaults();

    dbLF.Follow(dbL);
    dbRF.Follow(dbR);

    dbL.SetInverted(false);
    dbLF.SetInverted(false);
    dbR.SetInverted(true);
    dbRF.SetInverted(true);
   
    dbR.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    dbL.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    dbLF.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    dbRF.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);

    dbL.BurnFlash();
    dbR.BurnFlash();
    dbLF.BurnFlash();
    dbRF.BurnFlash();


}

void Drivebase::RobotPeriodic()
{
    if(abs(Primary.GetRawAxis(1)) >= 0.08)
    {
         dbL.Set(Primary.GetRawAxis(1) * 0.5);
    }
    else
    {
        dbL.Set(0);
        if(abs(Primary.GetRawAxis(5)) >= 0.08)
        {
           dbR.Set(Primary.GetRawAxis(5) * 0.5); 
        }
        else
        {
            dbR.Set(0);
        }
    }
}

void Drivebase::DisabledInit()
{
    dbR.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    dbL.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    dbLF.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    dbRF.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);

    dbL.BurnFlash();
    dbR.BurnFlash();
    dbLF.BurnFlash();
    dbRF.BurnFlash();
}
