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

    void CheckExec();

    void recordActionsExec(utilities::XboxInputHandler &leInputHandler, duration_t delta);

private:
    void recordActionsExec(utilities::XboxInputHandler &leInputHandler, duration_t delta, std::ofstream &recordBuffer);
    void joystickPosition(utilities::XboxInputHandler::joystick_t &&joystickLeft, utilities::XboxInputHandler::joystick_t &&joystickRight);
    void buttonA();
    void buttonB();
    void buttonX();
    void buttonY();
    void bumper();

    Robot *m_robo;
};
#endif