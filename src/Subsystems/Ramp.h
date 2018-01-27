/*
 * Ramp.h
 *
 *  Created on: Jan 22, 2018
 *      Author: Team5268
 */

#ifndef SRC_SUBSYSTEMS_RAMP_H_
#define SRC_SUBSYSTEMS_RAMP_H_

#include <WPIlib.h>
#include <Commands/Subsystem.h>
#include <DigitalInput.h>
#include "RobotMap.h"

class Ramp: public frc::Subsystem {
private:
	// initializes speed controllers for use in the class
	frc::Talon upperRampSC{RAMP_SPEED_CONTROLLER_UPPER_CHANNEL};
	frc::Talon lowerRampSC{RAMP_SPEED_CONTROLLER_LOWER_CHANNEL};
	frc::Talon intakeRampSC{RAMP_SPEED_CONTROLLER_INTAKE_CHANNEL};
public:
	Ramp();
	virtual void InitDefaultCommand();
	double getUpperRampSC();
	double getLowerRampSC();
	double getIntakeRampSC();
	void UpperUp();
	void UpperDown();
	void UpperStop();
	void LowerUp();
	void LowerDown();
	void LowerStop();
	void IntakeOn();
	void IntakeReverse();
	void IntakeOff();
	virtual ~Ramp();
};

#endif /* SRC_SUBSYSTEMS_RAMP_H_ */
