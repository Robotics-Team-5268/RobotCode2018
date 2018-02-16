#ifndef SRC_COMMANDS_RAMPCALIBRATE_H_
#define SRC_COMMANDS_RAMPCALIBRATE_H_

#include <Commands/Command.h>

class RampCalibrate: public frc::Command {
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

#endif /* SRC_COMMANDS_RAMPCALIBRATE_H_ */
