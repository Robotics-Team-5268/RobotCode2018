#pragma once

#include "../CommandBase.h"
#include <Commands/Command.h>

// This class controls the motors on the intake arms.
class Intake: public CommandBase {
private:
	float oldVal, newVal;
	const float MAX_CHANGE = 2.0;
public:
	Intake(float value);
	virtual void Execute();
	virtual void Initialize();
	virtual bool IsFinished();
	virtual void End();
	virtual ~Intake();
};
