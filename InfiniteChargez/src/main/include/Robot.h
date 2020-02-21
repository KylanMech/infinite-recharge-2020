/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#ifndef YEET_LE_MOST_AMAZING_ROBOT_IN_THE_WORLD
#define YEET_LE_MOST_AMAZING_ROBOT_IN_THE_WORLD
#pragma once

#include "RoboDrive.h"
#include "RoboHook.h"
#include "RoboStorage.h"
#include "HandlesChecksAndExecs.h"
#include "InputRecordAndPlay.h"
#include "Pair2D.h"
#include "XboxInputHandler.h"

#include <adi/ADIS16448_IMU.h>

#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>

#include <frc/BuiltInAccelerometer.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/geometry/Pose2d.h>
#include <frc/geometry/Rotation2d.h>
#include <frc/Joystick.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/TimedRobot.h>
#include <frc/XboxController.h>

#include <fstream>
#include <string>

class Robot : public frc::TimedRobot, public utilities::HandlesChecksAndExecs
{
private:
  const std::string inputRecordFileName{"/home/lvuser/InputRecord.rcd"};
  const std::string recordBufferName{"/home/lvuser/InputRecordBuffer.rcd"};
  std::ofstream m_recordFile{};
  std::ifstream m_recordReadFile{};
  bool tankMode{false};
  //Configuration constants will go here until a configuration system can be set up

  using joystick_t = frc::Joystick;

  using gyroscope_t = frc::ADIS16448_IMU;

  using controller_t = frc::XboxController;
  //Automation Type Aliases
  using accelerometer_t = frc::BuiltInAccelerometer;

  //Chrono Alisases
  using clock_t = std::chrono::steady_clock;
  using timePoint_t = std::chrono::time_point<clock_t>;
  using duration_t = std::chrono::duration<double>;

  using driver_t = frc::DifferentialDrive;
  using handler_t = utilities::XboxInputHandler;

private:
  static constexpr double rotationMultiplier{1};

  /*The input is raised to a power to enable more
    time on the lower curves
    */

  //Must be odd for the moment or else the robo cannot move backwards.

  //Automation Con
  //Ports for Motors and Controllers
private:
  static constexpr int controllerPort{0};
  static constexpr int leJoystickLeftPort{0};


public:
  Robot();
  void checkAndExec();
  void OdometryTests();
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;

  handler_t &getInputHandler() { return leInputHandler; }

private:
  bool isRecording{false}; //Really hacky, will remain until the deeper WPLIB api documentation can be discovered *Indiana Jones Music*
  bool recordingEnabled{true};
  long double meanDelta{0};

public:
  void TestPeriodic() override;

private:
  //RobotDataPoints

  frc::Pose2d leRobotPosition{};

  controller_t leController{controllerPort}; //Of epic dankness
  joystick_t leJoystickLeft{leJoystickLeftPort};
  handler_t leInputHandler{};
  //Declare Motors
  RoboDrive leRoboDrive{};
  RoboHook leHook{};
  RoboStorage leStorage{};
  //Non-motor components
  gyroscope_t leGyroscope{};
  accelerometer_t leAccelerometer{};
  //Recording Utilities
  utilities::InputRecordAndPlay m_leRecordScribe{};
  //Recording Utilities
  void recordActionsExec(utilities::XboxInputHandler &leInputHandler);

  //Input checking funcitons
  void recordActionsExec(utilities::XboxInputHandler &leInputHandler, duration_t delta, std::ofstream &recordBuffer);
  void joystickPosition(utilities::XboxInputHandler::joystick_t &&joystickLeft, utilities::XboxInputHandler::joystick_t &&joystickRight);
  void buttonA();
  void buttonB();
  void buttonX();
  void buttonY();
  void bumper();
  void intakeStop();
  void updatePos(duration_t delta);
  //Control handling nested class
  //Declare Controllers
  //Declare Time Variables
  timePoint_t lastSnapshot;
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Yeeter McYeeterson";
  const std::string kAutoNameCustom = "Yeeter McYeeterson";
  std::string m_autoSelected;
};

#endif