#pragma once

#include <rev/CANSparkMax.h>
#include <frc/DigitalInput.h>
#include <frc/Joystick.h>

class Indexer
{
    public:
    void RobotPeriodic(bool shooterReady);
    void RobotInit();
    
    private:
    rev::CANSparkMax indexerZone1 = rev::CANSparkMax(21, rev::CANSparkMax::MotorType::kBrushless);
    rev::CANSparkMax indexerZone2 = rev::CANSparkMax(22, rev::CANSparkMax::MotorType::kBrushless);
    frc::DigitalInput midBeamBreak{9};
    frc::DigitalInput topBeamBreak{5};
    frc::Joystick secondary{1};

    int indexerTimer = 0;
};