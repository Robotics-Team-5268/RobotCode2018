/*
 * Intake.h
 *
 *  Created on: Jan 23, 2018
 *      Author: Team5268
 */

#include <Commands/Command.h>

class Intake: public frc::Command {
public:
	typedef enum {
		intakeForward,
		intakeReverse
	} intakeDirection;

	Intake(intakeDirection dir);
	virtual void Initialize();
	virtual bool IsFinished();
	virtual void End();
	virtual ~Intake();
private:
	intakeDirection direction;
};
