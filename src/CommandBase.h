#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h"
#include "OI.h"
#include "WPILib.h"
#include "Subsystems/Drive.h"
#include "Subsystems/Ramp.h"

// this class controls how the command system works.
class CommandBase: public Command
{
public:
	CommandBase(const std::string &name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static std::unique_ptr<OI> oi;
	static std::unique_ptr<Drive> drive;
	static std::unique_ptr<Ramp> ramp;

};

#endif /* SRC_COMMANDBASE_H_ */
