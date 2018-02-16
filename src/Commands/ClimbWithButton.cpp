#include <Commands/ClimbWithButton.h>
#include "../Robot.h"

ClimbWithButton::ClimbWithButton(climbDirection dir, float speedIn): CommandBase()
	, speed(speedIn) {
	Command::Requires(climb.get());
	//SetTimeout(1);
	direction = dir;
}

void ClimbWithButton::Initialize() {
}

void ClimbWithButton::Execute() {
	if (direction == climbExtend) {
		climb->Extend(direction);
	} else {
		climb->Retract(direction);
	}
}

bool ClimbWithButton::IsFinished() {
	//return IsTimedOut();
	return (!CommandBase::oi->getDriverButtonPressed2(1) && !CommandBase::oi->getDriverButtonPressed2(2));
}

void ClimbWithButton::End() {
	CommandBase::climb->Off();
}

ClimbWithButton::~ClimbWithButton() {}

