#include <Commands/Intake.h>
#include "../Robot.h"
#include "../CommandBase.h"

Intake::Intake(float value) : CommandBase("Intake") {
	//Requires(&Robot::ramp);
	oldVal = 0.0;
	newVal = value;
}

void Intake::Initialize() {}

void Intake::Execute() {
	float curVal = newVal;

	if (curVal > oldVal + MAX_CHANGE) curVal = oldVal + MAX_CHANGE;
	if (curVal < oldVal - MAX_CHANGE) curVal = oldVal - MAX_CHANGE;

	ramp->IntakeOn(curVal);

	oldVal = curVal;
}

bool Intake::IsFinished() {
	return false;
}

void Intake::End() {
	ramp->IntakeOff();
	oldVal = 0.0;
}

Intake::~Intake() {}
