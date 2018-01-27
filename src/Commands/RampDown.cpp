/*
 * RampDown.cpp
 *
 *  Created on: Jan 22, 2018
 *      Author: Team5268
 */

#include "Commands/RampDown.h"
#include "../Robot.h"

RampDown::RampDown(float Value)
	: frc::Command("RampUp") {
	Requires(&Robot::ramp);
	SetTimeout(3);
	oldVal = 0.0;
	newVal = Value;
}

void RampDown::Initialize() {
}

void RampDown::Execute() {
	float curVal = newVal;
	if (curVal < oldVal - MAX_CHANGE) curVal = oldVal - MAX_CHANGE;
	Robot::ramp.UpperDown(curVal);
	Robot::ramp.LowerDown(curVal);
	Robot::ramp.IntakeOn(curVal);
	oldVal = curVal;
}

bool RampDown::IsFinished() {
	return IsTimedOut();
}

void RampDown::End() {
	Robot::ramp.UpperStop();
	Robot::ramp.LowerStop();
	Robot::ramp.IntakeOff();
	oldVal = 0.0;
}

RampDown::~RampDown() {

}
