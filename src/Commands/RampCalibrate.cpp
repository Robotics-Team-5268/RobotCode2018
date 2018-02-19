#include <Commands/RampCalibrate.h>

#include "../Robot.h"
#include "../CommandBase.h"

RampCalibrate::RampCalibrate(): CommandBase("RampCalibrate") {
	SetTimeout(5);
	counter = 0;
}

void RampCalibrate::Initialize() {}

void RampCalibrate::Execute() {
	counter++;

	// Clipped sin wave so it sits at +1 and -1 for a while
	float value = 1.25 * sin(counter/100.0);

	CommandBase::ramp->UpperOn(value);
	CommandBase::ramp->LowerOn(value);
	CommandBase::ramp->IntakeOn(value);
}

bool RampCalibrate::IsFinished() {
	return IsTimedOut();
}

void RampCalibrate::End() {
	CommandBase::ramp->UpperOff();
	CommandBase::ramp->LowerOff();
	CommandBase::ramp->IntakeOff();
}

RampCalibrate::~RampCalibrate() {}
