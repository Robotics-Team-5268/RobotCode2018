/*
 * RampDown.cpp
 *
 *  Created on: Jan 22, 2018
 *      Author: Team5268
 */

#include "Commands/RampDown.h"
#include "../Robot.h"

RampDown::RampDown()
	: frc::Command("RampUp") {
	Requires(&Robot::ramp);
	SetTimeout(3);
}

void RampDown::Initialize() {
	Robot::ramp.UpperDown();
	Robot::ramp.LowerDown();
	Robot::ramp.IntakeReverse();
}

bool RampDown::IsFinished() {
	return IsTimedOut();
}

void RampDown::End() {
	Robot::ramp.UpperStop();
	Robot::ramp.LowerStop();
	Robot::ramp.IntakeOff();
}

RampDown::~RampDown() {

}
