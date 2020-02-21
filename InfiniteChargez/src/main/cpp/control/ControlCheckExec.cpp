#include "RoboCheckExec.h"
#include "Pair2D.h"
#include "Utilities.h"

#include <algorithm>
#include <iostream>
#include <math.h>

    void RoboCheckExec::check(duration_t delta)
    {
        checkExec();
        recordActionsExec(m_robo->leInputHandler, delta);

    }

    void RoboCheckExec::checkExec()
    {
        joystickPosition(m_robo->leInputHandler.getJoystickLeft(), m_robo->leInputHandler.getJoystickRight());
        //buttonA();
        //buttonB();
        //buttonX();
        //buttonY();
        //bumper();  
    }
    
    void RoboCheckExec::joystickPosition(utilities::XboxInputHandler::joystick_t &&joystickLeft, utilities::XboxInputHandler::joystick_t &&joystickRight)
    {
        //Compilar arguments and preprocessor macros can be passed to remove unused
        //const double JoystickLeftX{leInputHandler.getJoystickLeft().x};
        //Up is negative in Xbox controllers
        //const double JoystickLeftY{-leInputHandler.getJoystickLeft().y};

        //const double JoystickRightX{joystickLeft.x};
        //Up isnegative in Xbox controllers
        //const double JoystickRightY{-joystickLeft.y};
        
        //Squarified Values
        //const utilities::Pair2D<double> SquareJoystickLeft{utilities::squarify(JoystickLeftX, JoystickLeftY)};
        //const utilities::Pair2D<double> SquareJoystickRight{utilities::squarify(JoystickRightX, JoystickRightY)};

        m_robo->leRoboDrive.setMovementMap(m_robo->leInputHandler.getJoystickLeft());

    }