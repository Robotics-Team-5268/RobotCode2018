#pragma once

#include "../CommandBase.h"
#include "WPILib.h"
#include "Robot.h"

class LEDToggle: public CommandBase {
public:
	LEDToggle();
	LEDToggle(int x);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	int relayNum;
};
