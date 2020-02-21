#ifndef YEET_ROBOT_STORAGE_H
#define YEET_ROBOT_STORAGE_H

#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>


class RoboStorage
{
    using tankController_t = ctre::phoenix::motorcontrol::can::WPI_VictorSPX;
    using intakeMotor_t = ctre::phoenix::motorcontrol::can::WPI_VictorSPX;
public:
    RoboStorage() {}
    void setIntakeSpeed()
    {}
    //void raise()
    //void lower()
    //void setAngle();
private:

  static constexpr int portIntakeLeft{5};
  static constexpr int portIntakeRight{6};
  static constexpr int portStorage{7};

  intakeMotor_t intakeMotorLeft{portIntakeLeft};
  intakeMotor_t intakeMotorRight{portIntakeRight};

  tankController_t tankController{portStorage};
};
#endif