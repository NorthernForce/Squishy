// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/RunMotor.h"
#include "RobotContainer.h"

RunMotor::RunMotor() {
  AddRequirements(RobotContainer::drivetrain.get());
}

// Called when the command is initially scheduled.
void RunMotor::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void RunMotor::Execute() {
    RobotContainer::drivetrain->DriveUsingPower(0.5, 0);
}

// Called once the command ends or is interrupted.
void RunMotor::End(bool interrupted) {
    RobotContainer::drivetrain->DriveUsingPower(0, 0);
}

// Returns true when the command should end.
bool RunMotor::IsFinished() {
  return false;
}
