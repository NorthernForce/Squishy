/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <memory>

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */

class Coordinate {
  Coordinate(double x=0, double y=0) : x(x), y(y) {}
  double x=0;
  double y=0;
};

class MoveToCoordinate
    : public frc2::CommandHelper<frc2::CommandBase, MoveToCoordinate> {
 public:
  MoveToCoordinate(int xDestination, int yDestination, double speed=0.3);

  void Initialize() override;

  // double RemoveJumps(double angToFinalWithJumps);

  double Distance(double x1, double x2, double y1, double y2);

  double Limit(double value, double limit=0.5);

  bool HasOscillated();

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  int xFinal;
  int yFinal;
  const double baseSpeed;

  const double turnP = 0;
  const double turnI = 0;
  const double turnD = 0;
  const double driveP = 0;
  const double driveI = 0;
  const double driveD = 0;

  double distance;

  double turnSpeed;
  double driveSpeed;

  int finishCounter = 0;
};
