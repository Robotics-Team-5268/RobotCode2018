#pragma once

#include <WPIlib.h>
#include <Commands/Subsystem.h>
#include <SpeedController.h>
#include <Talon.h>
#include <ctre/Phoenix.h>
#include "RobotMap.h"
// This is the subsystem for climbing, it extends a pole to deploy the hook and retracts a rope to pull us up.
class Climb: public frc::Subsystem {
private:
	WPI_TalonSRX climbExtendPipe{CLIMB_SPEED_CONTROLLER_EXTEND_CHANNEL};
	WPI_TalonSRX climbRetractRope{CLIMB_SPEED_CONTROLLER_RETRACT_CHANNEL};
public:
	Climb();
	virtual void InitDefaultCommand();
	void Extend(float speed);
	void Retract(float speed);
	void Off();
	virtual ~Climb();
};
