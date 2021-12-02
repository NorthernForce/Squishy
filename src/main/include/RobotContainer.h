// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include "OI.h"
#include "subsystems/Drivetrain.h"

/**
 * This class is wherelear
 *  the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();
  void InitAutonomousCommands();
  static std::shared_ptr<OI> oi;
  static std::shared_ptr<Drivetrain> drivetrain;

 private:
  void InitSubsystems();
  void InitDefaultCommands();
};
