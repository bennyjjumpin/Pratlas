#pragma once

#include <frc/Joystick.h>
#include <rev/CANSparkMax.h>

class Drivebase
{
    public:
    void RobotInit();
    void RobotPeriodic();
    void DisabledInit();
    private:
    frc::Joystick Primary{0};
    rev::CANSparkMax dbL = rev::CANSparkMax(1,rev::CANSparkMax::MotorType::kBrushed);
    rev::CANSparkMax dbR = rev::CANSparkMax(3,rev::CANSparkMax::MotorType::kBrushed);
    rev::CANSparkMax dbLF = rev::CANSparkMax(2,rev::CANSparkMax::MotorType::kBrushed);
    rev::CANSparkMax dbRF = rev::CANSparkMax(4,rev::CANSparkMax::MotorType::kBrushed);
};