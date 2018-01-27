/*
 * Intake.cpp
 *
 *  Created on: Jan 23, 2018
 *      Author: Team5268
 */

#include <Commands/Intake.h>

#include "../Robot.h"

Intake::Intake(intakeDirection dir)
	: frc::Command("Intake") {
	Requires(&Robot::ramp);
	SetTimeout(1);
	direction = dir;
}

void Intake::Initialize() {
	if (direction == intakeForward) {
		Robot::ramp.IntakeOn();
	} else if (direction == intakeReverse) {
		Robot::ramp.IntakeReverse();
	}
}

bool Intake::IsFinished() {
	return IsTimedOut();
}

void Intake::End() {
	Robot::ramp.IntakeOff();
}

Intake::~Intake() {
	// TODO Auto-generated destructor stub
}

