#include <Commands/RampUp.h>

#include "../Robot.h"
#include "../CommandBase.h"

RampUp::RampUp()
	: frc::Command("RampUp") {
	Requires(&Robot::ramp);
	//SetTimeout(3);
	oldVal = 0.0;
	newVal = SPEED;//used to be Value
}

RampUp::RampUp(float Value)
	: frc::Command("RampUp") {
	Requires(&Robot::ramp);
	//SetTimeout(3);
	oldVal = 0.0;
	newVal = Value;//used to be Value
}

void RampUp::Initialize() {
}

void RampUp::Execute() {
	float curVal = newVal;
	if (curVal > oldVal + MAX_CHANGE) curVal = oldVal + MAX_CHANGE;
	Robot::ramp.UpperOn(curVal);
	Robot::ramp.LowerOn(curVal);
	Robot::ramp.IntakeOn(curVal);
	oldVal = curVal;
}

bool RampUp::IsFinished() {
	return !CommandBase::oi->getDriverButtonPressed(1);
	//return IsTimedOut();
}

void RampUp::End() {
	Robot::ramp.UpperOff();
	Robot::ramp.LowerOff();
	Robot::ramp.IntakeOff();
	SmartDashboard::PutNumber("UpperUp", 0.0);
	oldVal = 0.0;
}

RampUp::~RampUp() {

}
