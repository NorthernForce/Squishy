#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/Command.h>
#include "Constants.h"

#include "commands/DriveWithJoystick.h"

std::shared_ptr<frc::XboxController> OI::driverController;

OI::OI() {
    InitControllers();
}

void OI::InitControllers() {
    driverController = std::make_shared<frc::XboxController>(Constants::driverController_id);
}

std::pair<double, double> OI::GetDriveControls() {
    speed = driverController->GetY(frc::XboxController::JoystickHand::kLeftHand);
    rotation = driverController->GetX(frc::XboxController::JoystickHand::kRightHand) *-1;
    return std::make_pair(speed, rotation);
}