#ifndef YEET_ROBOT_DRIVE_MOTORZ_H
#define YEET_ROBOT_DRIVE_MOTORZ_H
#include "Pair2D.h"

#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>

#include <frc/SpeedControllerGroup.h>
class RoboDrive
{
    using driveMotor_t = ctre::phoenix::motorcontrol::can::WPI_VictorSPX;

public:
    RoboDrive() :
    {
    }

    void setMovementMap(utilities::Pair2D<double> &movementMap);
    //void setForwardMovement(double forwards);
    //void setRotationMovement(double clockwise);
private:
    frc::SpeedControllerGroup driveMotorsLeft{driveMotorFrontLeft, driveMotorBackLeft};
    frc::SpeedControllerGroup driveMotorsRight{driveMotorFrontRight, driveMotorBackRight};

    static constexpr int portDriveFrontLeft{1};
    static constexpr int portDriveFrontRight{3};
    static constexpr int portDriveBackLeft{2};
    static constexpr int portDriveBackRight{4};

    driveMotor_t driveMotorFrontLeft{portDriveFrontLeft};
    driveMotor_t driveMotorFrontRight{portDriveFrontRight};
    driveMotor_t driveMotorBackLeft{portDriveBackLeft};
    driveMotor_t driveMotorBackRight{portDriveBackRight};
};
#endif