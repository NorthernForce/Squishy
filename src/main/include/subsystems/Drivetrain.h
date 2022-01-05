// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <frc/drive/DifferentialDrive.h>

class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();
  void Periodic() override;
  void Drive(double speed, double rotation);
  void DriveUsingPower(double leftSpeed, double rightSpeed);

  static std::shared_ptr<frc::DifferentialDrive> robotDrive;
  
 private:
  std::shared_ptr<rev::CANSparkMax> leftPrimarySpark;
  std::shared_ptr<rev::CANSparkMax> rightPrimarySpark;
  
  std::shared_ptr<rev::CANSparkMax> leftFollowerSpark1;
  std::shared_ptr<rev::CANSparkMax> rightFollowerSpark1;

  // currently unused
  int currentLimit = 60;
  int secondaryCurrentLimit = 80;
  double rampRate = 0.2;
};
