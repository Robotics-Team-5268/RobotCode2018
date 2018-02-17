#pragma once

#include <WPIlib.h>
#include <Commands/Subsystem.h>
#include <DigitalInput.h>
#include <SpeedController.h>
#include <SpeedControllerGroup.h>
#include <ctre/Phoenix.h>
#include "RobotMap.h"
// This subsystem uses the commands that start with ramp and intake to move the box up and down the ramp
class Ramp: public frc::Subsystem {
private:
	// initializes speed controllers for use in the class
	frc::VictorSP rampUL_SC{RAMP_SPEED_CONTROLLER_UPPER_LEFT_CHANNEL};
	frc::VictorSP rampUR_SC{RAMP_SPEED_CONTROLLER_UPPER_RIGHT_CHANNEL};
	frc::SpeedControllerGroup rampUpper{rampUL_SC, rampUR_SC};// This is the top 2 wheels on the ramp.

	frc::Spark rampML_SC{RAMP_SPEED_CONTROLLER_MIDDLE_LEFT_CHANNEL};
	frc::Spark rampMR_SC{RAMP_SPEED_CONTROLLER_MIDDLE_RIGHT_CHANNEL};
	frc::Spark rampLL_SC{RAMP_SPEED_CONTROLLER_LOWER_LEFT_CHANNEL};
	frc::Spark rampLR_SC{RAMP_SPEED_CONTROLLER_LOWER_RIGHT_CHANNEL};
	frc::SpeedControllerGroup rampLower{rampML_SC, rampMR_SC, rampLL_SC, rampLR_SC};// This is the bottom 4 wheels on the ramp.

	WPI_TalonSRX rampIntakeL_SC{RAMP_SPEED_CONTROLLER_INTAKE_LEFT_CHANNEL};
	WPI_TalonSRX rampIntakeR_SC{RAMP_SPEED_CONTROLLER_INTAKE_RIGHT_CHANNEL};
	frc::SpeedControllerGroup rampIntake{rampIntakeL_SC, rampIntakeR_SC};// This is the 2 intake wheels.
public:
	Ramp();
	virtual void InitDefaultCommand();
	void takeInput();
	double getUpperRampSC();
	double getLowerRampSC();
	double getIntakeRampSC();
	void UpperOn(float Value);// If you want this to go backward, set this negative.
	void UpperOff();
	void LowerOn(float Value);// If you want this to go backward, set this negative.
	void LowerOff();
	void IntakeOn(float Value);// If you want this to go backward, set this negative.
	void IntakeOff();
	virtual ~Ramp();
};
