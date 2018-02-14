#include <Commands/Intake.h>

#include "../Robot.h"

Intake::Intake(intakeDirection dir, float Value)
	: frc::Command("Intake") {
	Requires(&Robot::ramp);
	SetTimeout(1);
	direction = dir;
	oldVal = 0.0;
	newVal = Value;
}

void Intake::Initialize() {
}

void Intake::Execute() {
	float curVal = newVal;
	if (direction == intakeForward) {
		if (curVal > oldVal + MAX_CHANGE) curVal = oldVal + MAX_CHANGE;
		Robot::ramp.IntakeOn(curVal);
	} else if (direction == intakeReverse) {
		if (curVal < oldVal - MAX_CHANGE) curVal = oldVal - MAX_CHANGE;
		Robot::ramp.IntakeOn(curVal);
	}
	oldVal = curVal;
}

bool Intake::IsFinished() {
	return IsTimedOut();
}

void Intake::End() {
	Robot::ramp.IntakeOff();
	oldVal = 0.0;
}

Intake::~Intake() {}

