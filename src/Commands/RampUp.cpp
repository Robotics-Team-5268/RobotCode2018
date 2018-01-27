/*
 * RampUp.cpp
 *
 *  Created on: Jan 22, 2018
 *      Author: Team5268
 */

#include <Commands/RampUp.h>

#include "../Robot.h"
#include "../CommandBase.h"

RampUp::RampUp(float Value)
	: frc::Command("RampUp") {
	Requires(&Robot::ramp);
	//SetTimeout(3);
	oldVal = 0.0;
	newVal = Value;
}

void RampUp::Initialize() {
}

void RampUp::Execute() {
	float curVal = newVal;
	if (curVal > oldVal + MAX_CHANGE) curVal = oldVal + MAX_CHANGE;
	Robot::ramp.UpperUp(curVal);
	Robot::ramp.LowerUp(curVal);
	Robot::ramp.IntakeOn(curVal);
	oldVal = curVal;
}

bool RampUp::IsFinished() {
	return !CommandBase::oi->getDriverButtonPressed(1);
	//return IsTimedOut();
}

void RampUp::End() {
	Robot::ramp.UpperStop();
	Robot::ramp.LowerStop();
	Robot::ramp.IntakeOff();
	SmartDashboard::PutNumber("UpperUp", 0.0);
	oldVal = 0.0;
}

RampUp::~RampUp() {

}
