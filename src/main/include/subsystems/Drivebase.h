#pragma once

#include <frc/Joystick.h>
#include <rev/CANSparkMax.h>
#include <ctre/Phoenix.h>

class Drivebase
{
    public:
    void RobotInit();
    void RobotPeriodic();
    void DisabledInit();
    private:
    frc::Joystick Primary{1};
    ctre::phoenix::motorcontrol::can::TalonFX dbL{1};
    ctre::phoenix::motorcontrol::can::TalonFX dbLF{2};
    ctre::phoenix::motorcontrol::can::TalonFX dbR{4};
    ctre::phoenix::motorcontrol::can::TalonFX dbRF{5};
    bool Axis1Deadzone;
    bool Axis5Deadzone;
};