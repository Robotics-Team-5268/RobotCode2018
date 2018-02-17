#include "Commands/RampDown.h"
#include "../Robot.h"

RampDown::RampDown()
	: frc::Command("RampUp") {
	Requires(&Robot::ramp);
	SetTimeout(3);
	oldVal = 0.0;
	newVal = SPEED; //used to be Value
}

RampDown::RampDown(float Value)
	: frc::Command("RampUp") {
	Requires(&Robot::ramp);
	SetTimeout(3);
	oldVal = 0.0;
	newVal = Value; //used to be Value
}

void RampDown::Initialize() {
}

void RampDown::Execute() {
	float curVal = newVal;
	if (curVal < oldVal - MAX_CHANGE) curVal = oldVal - MAX_CHANGE;
	Robot::ramp.UpperOn(curVal);
	Robot::ramp.LowerOn(curVal);
	Robot::ramp.IntakeOn(curVal);
	oldVal = curVal;
}

bool RampDown::IsFinished() {
	return IsTimedOut();
}

void RampDown::End() {
	Robot::ramp.UpperOff();
	Robot::ramp.LowerOff();
	Robot::ramp.IntakeOff();
	oldVal = 0.0;
}

RampDown::~RampDown() {

}
