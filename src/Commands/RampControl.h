#pragma once

#include "../CommandBase.h"

// This class controls all of the motors on the ramp, but not the intake
class RampControl: public CommandBase {
private:
	float oldVal, newVal;
	const float MAX_CHANGE = .01;
public:
	RampControl(float value, int timeout);
	RampControl(float value);
	virtual void Execute();
	virtual void Initialize();
	virtual bool IsFinished();
	virtual void End();
	virtual ~RampControl();
};
