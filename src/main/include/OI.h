#include <frc/XboxController.h>

class OI {
 public:
    OI();
    void InitControllers();
    std::pair<double, double> GetDriveControls();

    static std::shared_ptr<frc::XboxController> driverController;
    const static auto leftHand = frc::XboxController::JoystickHand::kLeftHand;
    const static auto rightHand = frc::XboxController::JoystickHand::kRightHand;
 private:
    double speed;
    double rotation;
};