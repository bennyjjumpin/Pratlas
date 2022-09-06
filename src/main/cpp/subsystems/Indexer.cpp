#include <subsystems/Indexer.h>
#include <frc/smartDashboard/smartDashboard.h>

void Indexer::RobotInit()
{
    indexerZone2.RestoreFactoryDefaults();
    indexerZone2.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
    indexerZone2.SetInverted(true); // Makes the beam break value default to false.
    indexerZone2.BurnFlash();
}

void Indexer::RobotPeriodic(bool shooterReady)
{
    frc::SmartDashboard::PutBoolean("Top", topBeamBreak.Get()); // Adds the boolean values to smart dashboard.
    frc::SmartDashboard::PutBoolean("Mid", midBeamBreak.Get());
    frc::SmartDashboard::PutBoolean("shooterReady", shooterReady);
    if(secondary.GetRawButton(1))
    {
        if(midBeamBreak.Get() == false && topBeamBreak.Get() == false) //When pressing intake button, it sets the indexer zone 1 motor until one of the beam breaks is set to true.
        {
            indexerZone1.Set(0);
        }
        else
        {
            indexerZone1.Set(0.5);
        }
        
        if(topBeamBreak.Get() == false) // Sets indexer zone 2 motor only when the top beam break is false.
        {
            indexerZone2.Set(0);
        }
        else
        {
            indexerZone2.Set(0.3);
        }
    }
    else if(secondary.GetRawButton(2)) // Sets both indexer zones to outake when button 2 is pressed.
    {
        indexerZone1.Set(-0.369);
        indexerZone2.Set(-0.3);
    }
    else
    {
        indexerZone1.Set(0);
        indexerZone2.Set(0);
    }
    if(topBeamBreak.Get() == true && midBeamBreak.Get() == false)
    {
        indexerZone1.Set(0.5);
        indexerZone2.Set(0.3);
    }
    if(shooterReady == true)
    {
        indexerZone2.Set(0.5);
    }




}

