#ifndef YEET_ROBOT_CHECK_EXEC_H
#define YEET_ROBOT_CHECK_EXEC_H
#include "Robot.h"

class RoboCheckExec
{
public:
    RoboCheckExec(Robot *robo):
        m_robo{robo} 
        {}
    
    void CheckExec();

private:
    Robot *m_robo;

};
#endif