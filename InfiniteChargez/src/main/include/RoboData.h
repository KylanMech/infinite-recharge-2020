#ifndef YEET_DATA_LE_ROBOT_H
#define YEET_DATA_LE_ROBOT_H
#include <adi/ADIS16448_IMU.h>

#include <frc/BuiltInAccelerometer.h>


#include <frc/drive/DifferentialDrive.h>
#include <frc/geometry/Pose2d.h>
class RoboData
{

  using controller_t = frc::XboxController;
  using accelerometer_t = frc::BuiltInAccelerometer;
  using gyroscope_t = frc::ADIS16448_IMU;
public:
    RoboData () {}


    void updatePos(duration_t delta);

  gyroscope_t leGyroscope{};
  accelerometer_t leAccelerometer{};
private:

}
#endif