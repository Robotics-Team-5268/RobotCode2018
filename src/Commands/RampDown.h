
#ifndef SRC_COMMANDS_RAMPDOWN_H_
#define SRC_COMMANDS_RAMPDOWN_H_

#include <Commands/Command.h>
// This controls the bottom 4 wheels on the ramp.
class RampDown: public frc::Command {
private:
	float oldVal, newVal;
	const float MAX_CHANGE = 0.01;
	const float SPEED = 0.5; // arbitrary number, please change me
public:
	RampDown();
	RampDown(float Value);
	virtual void Execute();
	virtual void Initialize();
	virtual bool IsFinished();
	virtual void End();
	virtual ~RampDown();
};

#endif /* SRC_COMMANDS_RAMPDOWN_H_ */
