#pragma once

#include <WPIlib.h>
#include <Commands/Subsystem.h>
#include <SpeedController.h>
#include <Talon.h>
#include "RobotMap.h"

class Climb: public frc::Subsystem {
private:
	frc::PWMTalonSRX climbExtendPipe{CLIMB_SPEED_CONTROLLER_EXTEND_CHANNEL};
	frc::PWMTalonSRX climbRetractRope{CLIMB_SPEED_CONTROLLER_RETRACT_CHANNEL};
public:
	Climb();
	virtual void InitDefaultCommand();
	void Extend(float speed);
	void Retract(float speed);
	void Off();
	virtual ~Climb();
};
