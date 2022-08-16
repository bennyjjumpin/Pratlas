#include <subsystems/Indexer.h>
#include <frc/smartDashboard/smartDashboard.h>

void Indexer::RobotPeriodic()
{
    frc::SmartDashboard::PutBoolean("Top", topBeamBreak.Get());
    frc::SmartDashboard::PutBoolean("Mid", midBeamBreak.Get());

    if(midBeamBreak.Get() == false && topBeamBreak.Get() == false)
    {
        indexerZone1.Set(0);
    }
    else
    {
        indexerZone1.Set(0.2);
    }
    if(topBeamBreak.Get() == false)
    {
        indexerZone2.Set(0);
    }
    else
    {
        indexerZone2.Set(-0.2);
    }
}

