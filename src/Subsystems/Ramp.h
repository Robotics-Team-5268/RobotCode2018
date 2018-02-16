#pragma once

#include <WPIlib.h>
#include <Commands/Subsystem.h>
#include <DigitalInput.h>
#include <SpeedController.h>
#include <SpeedControllerGroup.h>
#include "RobotMap.h"

class Ramp: public frc::Subsystem {
private:
	// initializes speed controllers for use in the class
	frc::VictorSP rampUL_SC{RAMP_SPEED_CONTROLLER_UPPER_LEFT_CHANNEL};
	frc::VictorSP rampUR_SC{RAMP_SPEED_CONTROLLER_UPPER_RIGHT_CHANNEL};
	frc::SpeedControllerGroup rampUpper{rampUL_SC, rampUR_SC};

	frc::Spark rampML_SC{RAMP_SPEED_CONTROLLER_MIDDLE_LEFT_CHANNEL};
	frc::Spark rampMR_SC{RAMP_SPEED_CONTROLLER_MIDDLE_RIGHT_CHANNEL};
	frc::Spark rampLL_SC{RAMP_SPEED_CONTROLLER_LOWER_LEFT_CHANNEL};
	frc::Spark rampLR_SC{RAMP_SPEED_CONTROLLER_LOWER_RIGHT_CHANNEL};
	frc::SpeedControllerGroup rampLower{rampML_SC, rampMR_SC, rampLL_SC, rampLR_SC};

	frc::Talon rampIntakeL_SC{RAMP_SPEED_CONTROLLER_INTAKE_LEFT_CHANNEL};
	frc::Talon rampIntakeR_SC{RAMP_SPEED_CONTROLLER_INTAKE_RIGHT_CHANNEL};
	frc::SpeedControllerGroup rampIntake{rampIntakeL_SC, rampIntakeR_SC};
public:
	Ramp();
	virtual void InitDefaultCommand();
	void takeInput();
	double getUpperRampSC();
	double getLowerRampSC();
	double getIntakeRampSC();
	void UpperUp(float Value);
	void UpperDown(float Value);
	void UpperStop();
	void LowerUp(float Value);
	void LowerDown(float Value);
	void LowerStop();
	void IntakeOn(float Value);
	void IntakeOff();
	virtual ~Ramp();
};
