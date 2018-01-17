#pragma once

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include "CommandBase.h"
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <IterativeRobot.h>
// this is the base class for everything the robot does. It goes through all the stages of the game.
// if you are looking for the "start" of the code, this would be it.
class Robot : public IterativeRobot {
public:

private:
	virtual void RobotInit() override;
	virtual void DisabledInit() override;
	virtual void DisabledPeriodic() override;
	virtual void AutonomousInit() override;
	virtual void AutonomousPeriodic() override;
	virtual void TeleopInit() override;
	virtual void TeleopPeriodic() override;
	virtual void TestPeriodic() override;
};



#endif /* SRC_ROBOT_H_ */
