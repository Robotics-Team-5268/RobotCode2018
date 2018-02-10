#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "PIDController.h"
#include "SpeedController.h"

// for ramp motors, These are actually PWM's, not Speed Controllers
std::shared_ptr<SpeedController> RobotMap::upperRampSC;
std::shared_ptr<SpeedController> RobotMap::lowerRampSC;
std::shared_ptr<SpeedController> RobotMap::intakeRampSC;

std::shared_ptr<AnalogGyro> RobotMap::driveGyro;


void RobotMap::init() {// resets all the speed controllers and other hardware components.

    upperRampSC.reset(new Talon(RAMP_SPEED_CONTROLLER_UPPER_CHANNEL));
	lowerRampSC.reset(new Talon(RAMP_SPEED_CONTROLLER_LOWER_CHANNEL));
    intakeRampSC.reset(new Talon(RAMP_SPEED_CONTROLLER_INTAKE_CHANNEL));

   	//driveGyro.reset(new ADXRS450_Gyro(SPI::kOnboardCS0));
   	driveGyro.reset(new AnalogGyro(GYRO_ANALOG_PORT));
   	driveGyro->Calibrate();
}

