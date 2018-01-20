#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "PIDController.h"
#include "SpeedController.h"


std::shared_ptr<SpeedController> RobotMap::speedControllerFL;
std::shared_ptr<SpeedController> RobotMap::speedControllerFR;
std::shared_ptr<SpeedController> RobotMap::speedControllerBL;
std::shared_ptr<SpeedController> RobotMap::speedControllerBR;

std::shared_ptr<RobotDrive> RobotMap::driveRobotDrive4;

std::shared_ptr<AnalogGyro> RobotMap::driveGyro;

void RobotMap::init() {// resets all the speed controllers and other hardware components.
    LiveWindow *lw = LiveWindow::GetInstance();

    speedControllerFL.reset(new Talon(DRIVE_SPEED_CONTROLLER_FL_CHANNEL));
    // lw->AddActuator("Drive",  "Speed Controller FL", (TalonSRX&) speedControllerFL);

    speedControllerFR.reset(new Talon(DRIVE_SPEED_CONTROLLER_FR_CHANNEL));
    // lw->AddActuator("Drive", "Speed Controller FR", (TalonSRX&) speedControllerFR);

    speedControllerBL.reset(new Talon(DRIVE_SPEED_CONTROLLER_BL_CHANNEL));
    // lw->AddActuator("Drive", "Speed Controller BL", (TalonSRX&) speedControllerBL);

    speedControllerBR.reset(new Talon(DRIVE_SPEED_CONTROLLER_BR_CHANNEL));
    // lw->AddActuator("Drive", "Speed Controller BR", (TalonSRX&) speedControllerBR);

    driveRobotDrive4.reset(new RobotDrive(speedControllerFL, speedControllerBL,
                 speedControllerFR, speedControllerBR));

    //initializes some settings for robot drive
    driveRobotDrive4->SetSafetyEnabled(false);
    driveRobotDrive4->SetExpiration(0.1);
   	driveRobotDrive4->SetSensitivity(0.5);
   	driveRobotDrive4->SetMaxOutput(1.0);

	speedControllerFL->SetInverted(SCFL_INVERTED);
	speedControllerBL->SetInverted(SCBL_INVERTED);
	speedControllerFR->SetInverted(SCFR_INVERTED);
	speedControllerBR->SetInverted(SCBR_INVERTED);

   	//driveGyro.reset(new ADXRS450_Gyro(SPI::kOnboardCS0));
   	driveGyro.reset(new AnalogGyro(GYRO_ANALOG_PORT));
   	driveGyro->Calibrate();
}

