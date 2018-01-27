/*
 * RampUp.h
 *
 *  Created on: Jan 22, 2018
 *      Author: Team5268
 */

#ifndef SRC_COMMANDS_RAMPUP_H_
#define SRC_COMMANDS_RAMPUP_H_

#include <Commands/Command.h>

class RampUp: public frc::Command {
private:
	float oldVal, newVal;
	const float MAX_CHANGE = .01;
public:
	RampUp(float Value);
	virtual void Execute();
	virtual void Initialize();
	virtual bool IsFinished();
	virtual void End();
	virtual ~RampUp();
};

#endif /* SRC_COMMANDS_RAMPUP_H_ */