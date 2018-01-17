#include "CommandBase.h"
#include "Commands/Scheduler.h"
#include "OI.h"

// Initialize a single static instance of all of your subsystems to NULL
std::unique_ptr<OI> CommandBase::oi;
std::unique_ptr<Drive> CommandBase::drive;


CommandBase::CommandBase(const std::string &name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	drive.reset(new Drive());
	// Keep at the end
	oi.reset(new OI());
}





