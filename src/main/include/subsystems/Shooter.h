#pragma once

#include <rev/CANSparkMax.h>
#include <rev/SparkMaxRelativeEncoder.h>
#include <frc/Joystick.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/DigitalInput.h>
#include <frc/DutyCycle.h>
#include <frc/DigitalSource.h>

class Shooter
{
    public:
    void RobotInit();
    void RobotPeriodic();
    bool shooterReady;
    void ShootSetPoint(double HoodPos, double WheelVel, double LipRollerVel);
    private:
    frc::Joystick secondary{1};
    rev::CANSparkMax shooterFlywheel = rev::CANSparkMax(31, rev::CANSparkMax::MotorType::kBrushless);
    rev::CANSparkMax shooterLipRoller = rev::CANSparkMax(32, rev::CANSparkMax::MotorType::kBrushless);
    rev::CANSparkMax shooterHood = rev::CANSparkMax(33, rev::CANSparkMax::MotorType::kBrushless);
    frc::DigitalInput absoluteEncoderDigitalInput{1};
    frc::DutyCycle shooterHoodAbsoluteEncoder = frc::DutyCycle{absoluteEncoderDigitalInput};
    bool flywheelToggle;
    rev::SparkMaxPIDController shooterHoodPIDController = shooterHood.GetPIDController();
    rev::SparkMaxRelativeEncoder hoodEncoder = shooterHood.GetEncoder();
    rev::SparkMaxPIDController flywheelPIDController = shooterFlywheel.GetPIDController();
    rev::SparkMaxRelativeEncoder flywheelEncoder = shooterFlywheel.GetEncoder();
};
