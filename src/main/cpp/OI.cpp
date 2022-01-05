#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/Command.h>
#include "Constants.h"

#include "commands/DriveWithJoystick.h"
#include "commands/RunMotor.h"

std::shared_ptr<frc::XboxController> OI::driverController;

OI::OI() {
    InitControllers();
    MapControllerButtons();
}

void OI::InitControllers() {
    driverController = std::make_shared<frc::XboxController>(Constants::driverController_id);
}

void OI::MapControllerButtons() {
    SimpleButton(driverController, Xbox::A_button).WhileHeld(new RunMotor);
}

frc2::Button OI::SimpleButton(std::shared_ptr<frc::GenericHID> controller, uint8_t btn) {
  return frc2::Button([this, controller, btn] { return controller->GetRawButton(btn); });
}

std::pair<double, double> OI::GetDriveControls() {
    speed = driverController->GetY(frc::XboxController::JoystickHand::kLeftHand);
    rotation = driverController->GetX(frc::XboxController::JoystickHand::kRightHand) *-1;
    return std::make_pair(speed, rotation);
}