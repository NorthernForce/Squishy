// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drivetrain.h"
#include "Constants.h"

std::shared_ptr<frc::DifferentialDrive> Drivetrain::robotDrive;

Drivetrain::Drivetrain() {
    leftPrimarySpark.reset(new rev::CANSparkMax(Constants::MotorIDs::driveLeftPrimary, rev::CANSparkMax::MotorType::kBrushless));
    leftFollowerSpark1 = std::make_shared<rev::CANSparkMax>(Constants::MotorIDs::driveLeftFollower1, rev::CANSparkMax::MotorType::kBrushless);
    rightPrimarySpark.reset(new rev::CANSparkMax(Constants::MotorIDs::driveRightPrimary, rev::CANSparkMax::MotorType::kBrushless));
    rightFollowerSpark1 = std::make_shared<rev::CANSparkMax>(Constants::MotorIDs::driveRightFollower1, rev::CANSparkMax::MotorType::kBrushless);

    //leftPrimarySpark->SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    //leftFollowerSpark1->SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
    //leftFollowerSpark1->Follow(*leftPrimarySpark, true);
    // rightFollowerSpark1->Follow(*rightPrimarySpark, true);

    robotDrive = std::make_shared<frc::DifferentialDrive>(*leftPrimarySpark, *rightPrimarySpark);
}

void Drivetrain::Drive(double speed, double rotation) {
    robotDrive->ArcadeDrive(speed, rotation * 0.85);
}

void Drivetrain::DriveUsingPower(double leftSpeed, double rightSpeed) {
    leftPrimarySpark->Set(leftSpeed);
    rightPrimarySpark->Set(rightSpeed);
}

// This method will be called once per scheduler run
void Drivetrain::Periodic() {}
