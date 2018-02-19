#pragma once

#include "CommandBase.h"

// We use this class to calibrate the motors on the ramp instead of having to use a controller
class RampCalibrate: public CommandBase {
private:
	int counter;
public:
	RampCalibrate();
	virtual void Execute();
	virtual void Initialize();
	virtual bool IsFinished();
	virtual void End();
	virtual ~RampCalibrate();
};
