/*
 * RampCalibrate.cpp
 *
 *  Created on: Feb 13, 2018
 *      Author: Team5268
 */

#include <Commands/RampCalibrate.h>

#include "../Robot.h"
#include "../CommandBase.h"

RampCalibrate::RampCalibrate(): frc::Command("RampCalibrate") {
	Requires(&Robot::ramp);
	SetTimeout(5);
	counter = 0;
}

void RampCalibrate::Initialize() {
}

void RampCalibrate::Execute() {
	counter++;

	// Clipped sin wave so it sits at +1 and -1 for a while
	float value = 1.25 * sin(counter/100.0);

	Robot::ramp.UpperOn(value);
	Robot::ramp.LowerOn(value);
	Robot::ramp.IntakeOn(value);
}

bool RampCalibrate::IsFinished() {
	return IsTimedOut();
}

void RampCalibrate::End() {
	Robot::ramp.UpperOff();
	Robot::ramp.LowerOff();
	Robot::ramp.IntakeOff();
	SmartDashboard::PutNumber("UpperUp", 0.0);
}

RampCalibrate::~RampCalibrate() {}

