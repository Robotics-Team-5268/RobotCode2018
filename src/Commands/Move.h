
#ifndef MOVE_H
#define MOVE_H

#include "../CommandBase.h"
#include "Commands/Subsystem.h"
#include "../Robot.h"
// this is a PID to move forward for a specified time at a specified speed
// it uses the gyro to make sure it goes straight
class Move: public CommandBase {
public:
	Move( float tm, float spd );

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	float seconds;
	float speed;
	std::shared_ptr<Timer> timer;
	PIDController* pid;
private:

};
class MovePIDOutput: public PIDOutput
{
public:
	MovePIDOutput(double sp);
	virtual ~MovePIDOutput();
	void PIDWrite(double a);

	float speed;
};
#endif
