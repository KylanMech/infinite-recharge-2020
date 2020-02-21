#ifndef YEET_ROBOT_CHECK_EXEC_H
#define YEET_ROBOT_CHECK_EXEC_H
#include "Robot.h"

class RoboCheckExec
{
    using duration_t = Robot::duration_t;

public:
    RoboCheckExec(Robot *robo) : m_robo{robo}
    {
    }

    void checkExec();
    void check();

    void recordActionsExec(utilities::XboxInputHandler &leInputHandler, duration_t delta);

private:
    void recordActionsExec(utilities::XboxInputHandler &leInputHandler, duration_t delta);
  bool isRecording{false}; //Really hacky, will remain until the deeper WPLIB api documentation can be discovered *Indiana Jones Music*
  bool recordingEnabled{true};
  long double meanDelta{0};

    void joystickPosition(utilities::XboxInputHandler::joystick_t &&joystickLeft, utilities::XboxInputHandler::joystick_t &&joystickRight);
    void buttonA();
    void buttonB();
    void buttonX();
    void buttonY();
    void bumper();

    Robot *m_robo;
};
#endif