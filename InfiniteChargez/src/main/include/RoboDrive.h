#ifndef YEET_ROBOT_DRIVE_MOTORZ_H
#define YEET_ROBOT_DRIVE_MOTORZ_H
#include "Pair2D.h"

#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>

#include <frc/SpeedControllerGroup.h>

#include <algorithm>
class RoboDrive
{
    using driveMotor_t = ctre::phoenix::motorcontrol::can::WPI_VictorSPX;

public:
    RoboDrive()
    {
    }

    void setMovementMap(utilities::Pair2D<double> &&movementMap)
    {

        m_rightMotors.Set(std::clamp(movementMap.y - movementMap.x, -1.0, 1.0));
        m_leftMotors.Set(std::clamp(movementMap.y + movementMap.x, -1.0, 1.0));//FIGURE OUT WHY A NEGATIVE IS NEEDED!!!!
    };
    //void setForwardMovement(double forwards);
    //void setRotationMovement(double clockwise);
private:
    frc::SpeedControllerGroup m_leftMotors{driveMotorFrontLeft, driveMotorBackLeft};
    frc::SpeedControllerGroup m_rightMotors{driveMotorFrontRight, driveMotorBackRight};

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