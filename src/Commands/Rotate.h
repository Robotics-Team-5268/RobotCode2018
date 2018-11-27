
#ifndef ROTATE_H
#define ROTATE_H

#include "../CommandBase.h"
#include "Commands/Subsystem.h"
#include "../Robot.h"
// This is a pid to rotate our robot a certain number of degrees
class Rotate: public CommandBase {
public:
	Rotate( float amount );

	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	float degrees;
	float gyroAngle;

	PIDController* pid;
private:

};
class RotatePIDOutput: public PIDOutput
	{
		virtual ~RotatePIDOutput();
		void PIDWrite(double a);
	};
#endif
