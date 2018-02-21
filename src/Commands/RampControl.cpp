#include <Commands/RampControl.h>
#include "../Robot.h"
#include "../CommandBase.h"

// Used during autonomous
RampControl::RampControl(float value, int timeout) : CommandBase("RampControl") {
	SetTimeout(timeout);
	oldVal = 0.0;
	newVal = value;
}

// Used with driver input during teleop
RampControl::RampControl(float value) : CommandBase("RampControl") {
	SetTimeout(999);
	oldVal = 0.0;
	newVal = value;
}

void RampControl::Initialize() {}

void RampControl::Execute() {
	float curVal = newVal;

	if (curVal > oldVal + MAX_CHANGE) curVal = oldVal + MAX_CHANGE;
	if (curVal < oldVal - MAX_CHANGE) curVal = oldVal - MAX_CHANGE;

	ramp->UpperOn(curVal); // Upper 2 wheels on ramp
	ramp->LowerOn(curVal); // Lower 4 wheels on ramp
	oldVal = curVal;
}

bool RampControl::IsFinished() {
	return IsTimedOut();
}

void RampControl::End() {
	ramp->UpperOff();
	ramp->LowerOff();
	oldVal = 0.0;
}

RampControl::~RampControl() {}
