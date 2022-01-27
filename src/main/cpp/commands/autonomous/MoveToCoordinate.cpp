/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "frc2/command/PIDCommand.h"

#include "commands/autonomous/MoveToCoordinate.h"
#include "RobotContainer.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include <memory>
#include <cmath>
#include "subsystems/Drivetrain.h"
#include "Robot.h"
#include <vector>

MoveToCoordinate::MoveToCoordinate(int xDestination, int yDestination, double speed) : baseSpeed(speed) {
  AddRequirements(RobotContainer::drivetrain.get());
  SetName("MoveToCoordinate");
  xFinal = xDestination;
  yFinal = yDestination;
}

// Called when the command is initially scheduled.
void MoveToCoordinate::Initialize() {}

double MoveToCoordinate::Distance(double x1, double x2, double y1, double y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double MoveToCoordinate::Limit(double value, double limit) {
  return std::min(std::max(value, -limit), limit);
}

// Called repeatedly when this Command is scheduled to run
void MoveToCoordinate::Execute() {
  frc2::PIDController turnPID{turnP, turnI, turnD};
  frc2::PIDController drivePID{driveP, driveI, driveD};
}  

// Called once the command ends or is interrupted.
void MoveToCoordinate::End(bool interrupted) {
  RobotContainer::drivetrain->DriveUsingPower(0, 0);
}

// Returns true when the command should end.
bool MoveToCoordinate::IsFinished() {
  if (finishCounter > 30) { return true; }
  else { return false; }
};