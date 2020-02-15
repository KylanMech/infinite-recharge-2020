#include "XboxInputHandler.h"
#include "Utilities.h"

#include <string>
#include <frc/XboxController.h>
namespace utilities
{
    void XboxInputHandler::operator=(frc::XboxController &XBoxController)
    {
        joystick_t joystickLeft{XBoxController.GetX(frc::GenericHID::JoystickHand::kLeftHand), 
            XBoxController.GetY(frc::GenericHID::kLeftHand)};
        
        joystick_t joystickRight{XBoxController.GetX(frc::GenericHID::JoystickHand::kRightHand), 
            XBoxController.GetY(frc::GenericHID::kRightHand)};
        //Joystick
        setJoystickLeft(joystickLeft);

        setJoystickRight(joystickRight);
        
        //Button Functions
        //Button A
        setButtonAState(XBoxController.GetAButton());
        setButtonAPressed(XBoxController.GetAButtonPressed());
        setButtonAReleased(XBoxController.GetAButtonReleased());
        //Button B
        setButtonBState(XBoxController.GetBButton());
        setButtonBPressed(XBoxController.GetBButtonPressed());
        setButtonBReleased(XBoxController.GetBButtonReleased());
        //Button X
        setButtonXState(XBoxController.GetXButton());
        setButtonXPressed(XBoxController.GetXButtonPressed());
        setButtonXReleased(XBoxController.GetXButtonReleased());
        //Button Y
        setButtonYState(XBoxController.GetYButton());
        setButtonYPressed(XBoxController.GetYButtonPressed());
        setButtonYReleased(XBoxController.GetYButtonReleased());

        //Triggers
        //Triger Left
        setTriggerLeft(XBoxController.GetTriggerAxis(frc::GenericHID::kLeftHand));
        //Trigger Right
        setTriggerRight(XBoxController.GetTriggerAxis(frc::GenericHID::kRightHand));

        //Bumper
        //Bumper Left
        setBumperLeftState(XBoxController.GetBumper(frc::GenericHID::kLeftHand));
        setBumperLeftPressed(XBoxController.GetBumperPressed(frc::GenericHID::kLeftHand));
        setBumperLeftReleased(XBoxController.GetBumperReleased(frc::GenericHID::kLeftHand));
        //Bumper Right
        setBumperRightState(XBoxController.GetBumper(frc::GenericHID::kRightHand));
        setBumperRightPressed(XBoxController.GetBumperPressed(frc::GenericHID::kRightHand));
        setBumperRightReleased(XBoxController.GetBumperReleased(frc::GenericHID::kRightHand));

        //Stick Buttons
        //Left Stick Button
        setButtonLeftStickState(XBoxController.GetStickButton(frc::GenericHID::kLeftHand));
        setButtonLeftStickPressed(XBoxController.GetStickButtonPressed(frc::GenericHID::kLeftHand));
        setButtonLeftStickReleased(XBoxController.GetStickButtonReleased(frc::GenericHID::kLeftHand));
        //Right Stick Button
        setButtonRightStickState(XBoxController.GetStickButton(frc::GenericHID::kRightHand));
        setButtonRightStickPressed(XBoxController.GetStickButtonPressed(frc::GenericHID::kRightHand));
        setButtonRightStickReleased(XBoxController.GetStickButtonReleased(frc::GenericHID::kRightHand));

        //Back and Start button
        //Back Button
        setButtonBackState(XBoxController.GetBackButton());
        setButtonBackPressed(XBoxController.GetBackButtonPressed());
        setButtonBackReleased(XBoxController.GetBackButtonReleased());
        //Start Button
        setButtonStartState(XBoxController.GetStartButton());
        setButtonStartPressed(XBoxController.GetStartButtonPressed());
        setButtonStartReleased(XBoxController.GetStartButtonReleased());
    }

    XboxInputHandler::snapshot_t XboxInputHandler::getSnapshot()
    {
        constexpr char pad{' '};
        snapshot_t snapshot{""};
        //Joystick
        //Left Joystick
        snapshot += std::to_string(getJoystickLeft().x) + pad;
        snapshot += std::to_string(getJoystickLeft().y) + pad;

        //Left Joystick

        snapshot += std::to_string(getJoystickRight().x) + pad;
        snapshot += std::to_string(getJoystickRight().y) + pad;

        //Button Functions
        //Button A
        snapshot += std::to_string(getButtonAState()) + pad;
        snapshot += std::to_string(getButtonAPressed()) + pad;
        snapshot += std::to_string(getButtonAReleased()) + pad;
        //Button B
        snapshot += std::to_string(getButtonBState()) + pad;
        snapshot += std::to_string(getButtonBPressed()) + pad;
        snapshot += std::to_string(getButtonBReleased()) + pad;
        //Button X
        snapshot += std::to_string(getButtonXState()) + pad;
        snapshot += std::to_string(getButtonXPressed()) + pad;
        snapshot += std::to_string(getButtonXReleased()) + pad;
        //Button Y
        snapshot += std::to_string(getButtonYState()) + pad;
        snapshot += std::to_string(getButtonYPressed()) + pad;
        snapshot += std::to_string(getButtonYReleased()) + pad;

        //Triggers
        //Triger Left
        snapshot += std::to_string(getTriggerLeft()) + pad;
        //Trigger Right
        snapshot += std::to_string(getTriggerRight()) + pad;

        //Bumper
        //Bumper Left
        snapshot += std::to_string(getBumperLeftState()) + pad;
        snapshot += std::to_string(getBumperLeftPressed()) + pad;
        snapshot += std::to_string(getBumperLeftReleased()) + pad;
        //Bumper Right
        snapshot += std::to_string(getBumperRightState()) + pad;
        snapshot += std::to_string(getBumperRightPressed()) + pad;
        snapshot += std::to_string(getBumperRightReleased()) + pad;

        //Stick Buttons
        //Left Stick Button
       snapshot += std::to_string(getButtonLeftStickState()) + pad;
       snapshot += std::to_string(getButtonLeftStickPressed()) + pad;
       snapshot += std::to_string(getButtonLeftStickReleased()) + pad;

        //Right Stick Button
        snapshot += std::to_string(getButtonRightStickState()) + pad;
        snapshot += std::to_string(getButtonRightStickPressed()) + pad;
        snapshot += std::to_string(getButtonRightStickReleased()) + pad;

        //Back and Start button
        //Start Button
        snapshot += std::to_string(getButtonStartState()) + pad;
        snapshot += std::to_string(getButtonStartPressed()) + pad;
        snapshot += std::to_string(getButtonStartReleased()) + pad;
        //Back Button
        snapshot += std::to_string(getButtonBackState()) + pad;
        snapshot += std::to_string(getButtonBackPressed()) + pad;
        snapshot += std::to_string(getButtonBackReleased()) + pad;
        return snapshot;
    }

    void XboxInputHandler::operator=(snapshot_t &snapshot)
    {
        std::size_t i{0};
        //Joystick
        joystick_t joystickLeft{utilities::parseSSV<double>(snapshot, i), utilities::parseSSV<double>(snapshot, i)};
        joystick_t joystickRight{utilities::parseSSV<double>(snapshot, i), utilities::parseSSV<double>(snapshot, i)};
        //std::cout << getJoystickLeft().y;

        setJoystickLeft(joystickLeft);

        setJoystickRight(joystickRight);
        
        //Button Functions
        //Button A
        setButtonAState(std::stoi(snapshot, &i));
        setButtonAPressed(std::stoi(snapshot, &i));
        setButtonAReleased(std::stoi(snapshot, &i));
        //Button B
        setButtonBState(std::stoi(snapshot, &i));
        setButtonBPressed(std::stoi(snapshot, &i));
        setButtonBReleased(std::stoi(snapshot, &i));
        //Button X
        setButtonXState(std::stoi(snapshot, &i));
        setButtonXPressed(std::stoi(snapshot, &i));
        setButtonXReleased(std::stoi(snapshot, &i));
        //Button Y
        setButtonYState(std::stoi(snapshot, &i));
        setButtonYPressed(std::stoi(snapshot, &i));
        setButtonYReleased(std::stoi(snapshot, &i));

        //Triggers
        //Triger Left
        setTriggerLeft(std::stod(snapshot, &i));
        //Trigger Right
        setTriggerRight(std::stod(snapshot, &i));

        //Bumper
        //Bumper Left
        setBumperLeftState(std::stoi(snapshot, &i));
        setBumperLeftPressed(std::stoi(snapshot, &i));
        setBumperLeftReleased(std::stoi(snapshot, &i));
        //Bumper Right
        setBumperRightState(std::stoi(snapshot, &i));
        setBumperRightPressed(std::stoi(snapshot, &i));
        setBumperRightReleased(std::stoi(snapshot, &i));

        //Stick Buttons
        //Left Stick Button
        setButtonLeftStickState(std::stoi(snapshot, &i));
        setButtonLeftStickPressed(std::stoi(snapshot, &i));
        setButtonLeftStickReleased(std::stoi(snapshot, &i));
        //Right Stick Button
        setButtonRightStickState(std::stoi(snapshot, &i));
        setButtonRightStickPressed(std::stoi(snapshot, &i));
        setButtonRightStickReleased(std::stoi(snapshot, &i));

        //Back and Start button
        //Start Button
        setButtonStartState(std::stoi(snapshot, &i));
        setButtonStartPressed(std::stoi(snapshot, &i));
        setButtonStartReleased(std::stoi(snapshot, &i));
        //Back Button
        setButtonBackState(std::stoi(snapshot, &i));
        setButtonBackPressed(std::stoi(snapshot, &i));
        setButtonBackReleased(std::stoi(snapshot, &i));
    }
}
