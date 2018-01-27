/*
 * Intake.h
 *
 *  Created on: Jan 23, 2018
 *      Author: Team5268
 */

#include <Commands/Command.h>

class Intake: public frc::Command {
private:
	float oldVal, newVal = .25;
	const float MAX_CHANGE = .01;
public:
	typedef enum {
		intakeForward,
		intakeReverse
	} intakeDirection;

	Intake(intakeDirection dir, float Value);
	virtual void Execute();
	virtual void Initialize();
	virtual bool IsFinished();
	virtual void End();
	virtual ~Intake();
private:
	intakeDirection direction;
};
