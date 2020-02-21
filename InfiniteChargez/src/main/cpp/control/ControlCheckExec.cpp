#include "Robot.h"
#include "Pair2D.h"
#include "Utilities.h"

#include <algorithm>
#include <iostream>
#include <math.h>

    void Robot::checkAndExec()
    {
        joystickPosition(leInputHandler.getJoystickLeft(), leInputHandler.getJoystickRight());
        //buttonA();
        //buttonB();
        //buttonX();
        //buttonY();
        //bumper();  
    }
    
    void Robot::joystickPosition(utilities::XboxInputHandler::joystick_t &&joystickLeft, utilities::XboxInputHandler::joystick_t &&joystickRight)
    {
        //Compilar arguments and preprocessor macros can be passed to remove unused
        const double JoystickLeftX{leInputHandler.getJoystickLeft().x};
        //Up is negative in Xbox controllers
        const double JoystickLeftY{-leInputHandler.getJoystickLeft().y};

        const double JoystickRightX{joystickLeft.x};
        //Up isnegative in Xbox controllers
        const double JoystickRightY{-joystickLeft.y};
        
        //Squarified Values
        const utilities::Pair2D<double> SquareJoystickLeft{utilities::squarify(JoystickLeftX, JoystickLeftY)};
        const utilities::Pair2D<double> SquareJoystickRight{utilities::squarify(JoystickRightX, JoystickRightY)};

        //std::cout << "X: " << SquareJoystickLeft.x << " Y: " << SquareJoystickLeft.y << '\n';


        //if(tankMode)
        //{
        //driveMotorsRight.Set(JoystickRightY);
        //driveMotorsLeft.Set(JoystickLeftY);
        //}
        //else 
        //{
        driveMotorsRight.Set(std::clamp(SquareJoystickLeft.y + SquareJoystickLeft.x, -1.0, 1.0));
        driveMotorsLeft.Set(-std::clamp(SquareJoystickLeft.y - SquareJoystickLeft.x, -1.0, 1.0));//FIGURE OUT WHY A NEGATIVE IS NEEDED!!!!
        //}
        //    /*driverMain.ArcadeDrive(
        //    leController.GetY(frc::GenericHID::JoystickHand::kLeftHand),
        //    leController.GetX(frc::GenericHID::JoystickHand::kLeftHand));
        //    */
    }