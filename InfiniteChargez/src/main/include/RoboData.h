#ifndef YEET_DATA_LE_ROBOT_H
#define YEET_DATA_LE_ROBOT_H
#include <adi/ADIS16448_IMU.h>

#include <frc/BuiltInAccelerometer.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/geometry/Pose2d.h>

#include <chrono>
class RoboData
{

    using duration_t = std::chrono::duration<double>;
    using accelerometer_t = frc::BuiltInAccelerometer;
    using gyroscope_t = frc::ADIS16448_IMU;

public:
    RoboData() : leAccelerometer{frc::BuiltInAccelerometer::kRange_8G} {}

    void updatePos(duration_t delta);

    gyroscope_t leGyroscope{};
    accelerometer_t leAccelerometer{};

private:
    frc::Pose2d leRobotPosition;
};
#endif