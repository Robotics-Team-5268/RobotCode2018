/*
 * RampUp.cpp
 *
 *  Created on: Jan 22, 2018
 *      Author: Team5268
 */

#include <Commands/RampUp.h>

#include "../Robot.h"

RampUp::RampUp()
	: frc::Command("RampUp") {
	Requires(&Robot::ramp);
	SetTimeout(3);
}

void RampUp::Initialize() {
	Robot::ramp.UpperUp();
	Robot::ramp.LowerUp();
	Robot::ramp.IntakeOn();
}

bool RampUp::IsFinished() {
	return IsTimedOut();
}

void RampUp::End() {
	Robot::ramp.UpperStop();
	Robot::ramp.LowerStop();
	Robot::ramp.IntakeOff();
	SmartDashboard::PutNumber("UpperUp", 0.0);
}

RampUp::~RampUp() {

}
