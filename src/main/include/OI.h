#include <frc/XboxController.h>
#include <frc2/command/button/Button.h>

class OI {
 public:
    OI();
    void InitControllers();
    void MapControllerButtons();
    std::pair<double, double> GetDriveControls();
    frc2::Button SimpleButton(std::shared_ptr<frc::GenericHID> controller, uint8_t btn);

    static std::shared_ptr<frc::XboxController> driverController;
    const static auto leftHand = frc::XboxController::JoystickHand::kLeftHand;
    const static auto rightHand = frc::XboxController::JoystickHand::kRightHand;

    enum Xbox { 
        A_button     = 1,
        B_button     = 2, 
        X_button     = 3, 
        Y_button     = 4, 
        lt_bumper    = 5,
        rt_bumper    = 6,  
        menu_button  = 7, 
        view_button  = 8,
        lt_stick     = 9,
        rt_stick     = 10
    };

    enum XboxAxis {
        lt_X,
        lt_Y,
        lt_trigger,
        rt_trigger,
        rt_X,
        rt_Y
    };
 private:
    double speed;
    double rotation;
};