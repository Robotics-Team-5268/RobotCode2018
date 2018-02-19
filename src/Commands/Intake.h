#pragma once

#include "../CommandBase.h"
#include <Commands/Command.h>

// This class controls the motors on the intake arms.
class Intake: public CommandBase {
private:
	float oldVal, newVal = .25;
	const float MAX_CHANGE = .01;
public:
	Intake(float value);
	virtual void Execute();
	virtual void Initialize();
	virtual bool IsFinished();
	virtual void End();
	virtual ~Intake();
};
