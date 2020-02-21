#ifndef YEET_ROBOT_HOOK_H
#define YEET_ROBOT_HOOK_H
#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>


class RoboHook
{

  using driveMotor_t = ctre::phoenix::motorcontrol::can::WPI_VictorSPX;
public:
    RoboHook() {}

    //setHookHeight
    //hookUp
    //hookDown
private:


  static constexpr int portHook{8};

  hookMotor_t hookMotor{portHook};
}

#endif