#include <subsystems/Indexer.h>
#include <frc/smartDashboard/smartDashboard.h>

void Indexer::RobotPeriodic()
{
    frc::SmartDashboard::PutBoolean("Top", topBeamBreak.Get());
    frc::SmartDashboard::PutBoolean("Mid", midBeamBreak.Get());
    if(secondary.GetRawButton(1))
    {
        if(midBeamBreak.Get() == false && topBeamBreak.Get() == false)
        {
            indexerZone1.Set(0);
        }
        else
        {
            indexerZone1.Set(0.5);
        }
        
        if(topBeamBreak.Get() == false)
        {
            indexerZone2.Set(0);
        }
        else
        {
            indexerZone2.Set(-0.3);
        }
    }
    else if(secondary.GetRawButton(2))
    {
        indexerZone1.Set(-0.369);
        indexerZone2.Set(0.3);
    }
    else
    {
        indexerZone1.Set(0);
        indexerZone2.Set(0);
    }
}

