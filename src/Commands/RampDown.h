/*
 * RampDown.h
 *
 *  Created on: Jan 22, 2018
 *      Author: Team5268
 */

#ifndef SRC_COMMANDS_RAMPDOWN_H_
#define SRC_COMMANDS_RAMPDOWN_H_

#include <Commands/Command.h>

class RampDown: public frc::Command {
public:
	RampDown();
	virtual void Initialize();
	virtual bool IsFinished();
	virtual void End();
	virtual ~RampDown();
};

#endif /* SRC_COMMANDS_RAMPDOWN_H_ */
