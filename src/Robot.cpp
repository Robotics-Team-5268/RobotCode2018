#include "Robot.h"
#include "RobotMap.h"

#include <Commands/Scheduler.h>
#include <SmartDashboard/SmartDashboard.h>

	void Robot::RobotInit(){// initializes the main things needed for the robot to run.
		// runs when the robot starts.
		RobotMap::init();
		CommandBase::init();

		CommandBase::drive->safetyOff();
	}

	void Robot::DisabledInit() {}

	void Robot::DisabledPeriodic() {
		frc::Scheduler::GetInstance()->Run();
	}

	void Robot::AutonomousInit() {// runs when the autonomous portion of the game starts.
		RobotMap::driveGyro->Reset();
	}

	void Robot::AutonomousPeriodic() {// continuously runs during autonomous portion of the game.
		frc::Scheduler::GetInstance()->Run();
	}

	void Robot::TeleopInit() {// runs when the teleop portion of the game starts.
		//CommandBase::drive->getGyro()->Reset();
	}

	void Robot::TeleopPeriodic() { //continuously runs during teleop portion of the game.
		frc::Scheduler::GetInstance()->Run();
	}

	void Robot::TestPeriodic() {}

START_ROBOT_CLASS(Robot)
