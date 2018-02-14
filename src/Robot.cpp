#include "Robot.h"
#include "RobotMap.h"
#include <Commands/Scheduler.h>
#include <REVDigitBoard.h>
#include <SmartDashboard/SmartDashboard.h>
#include <RobotController.h>

std::unique_ptr<Autonomous> Robot::autonomousCommand;

AutonomousChooser Robot::AutoChooser;
Ramp Robot::ramp;

	void Robot::RobotInit(){// initializes the main things needed for the robot to run.
		// runs when the robot starts.
		CommandBase::init();

		CommandBase::drive->safetyOff();
/*
		autonomousChooser.reset(new SendableChooser<int*>());
		autonomousChooser->AddDefault("Right", new int(1));
		autonomousChooser->AddObject("Center", new int(2));
		autonomousChooser->AddObject("Left", new int(3));
		SmartDashboard::PutData("Autonomous", autonomousChooser.get());
*/

	}

	void Robot::DisabledInit() {}

	void Robot::DisabledPeriodic() {
		frc::Scheduler::GetInstance()->Run();
	}

	void Robot::AutonomousInit() {// runs when the autonomous portion of the game starts.
		//int* selection = autonomousChooser->GetSelected();
		autonomousCommand.reset(new Autonomous(AutoChooser.AutonomousSelection()));
		autonomousCommand->Start();
	}

	void Robot::AutonomousPeriodic() {// continuously runs during autonomous portion of the game.
		frc::Scheduler::GetInstance()->Run();
		AddSmartDashboardItems();
	}

	void Robot::TeleopInit() {// runs when the teleop portion of the game starts.
		CommandBase::drive->resetGyro();
	}

	void Robot::TeleopPeriodic() { //continuously runs during teleop portion of the game.
		frc::Scheduler::GetInstance()->Run();
		AddSmartDashboardItems();
	}

	void Robot::TestPeriodic() {}

	void Robot::AddSmartDashboardItems() {
		SmartDashboard::PutNumber("Gyro Angle", CommandBase::drive->getGyroAngle());
		SmartDashboard::PutNumber("Joystick X", CommandBase::oi->getDriverJoystick()->GetX());
		SmartDashboard::PutNumber("Joystick Y", CommandBase::oi->getDriverJoystick()->GetY());
		SmartDashboard::PutNumber("Left Trigger", CommandBase::oi->getDriverJoystick()->GetRawAxis(LEFT_TRIGGER));
		SmartDashboard::PutNumber("Right Trigger", CommandBase::oi->getDriverJoystick()->GetRawAxis(RIGHT_TRIGGER));
		SmartDashboard::PutNumber("upperRampSC", ramp.getUpperRampSC());
		SmartDashboard::PutNumber("lowerRampSC", ramp.getLowerRampSC());
		SmartDashboard::PutNumber("intakeRampSC", ramp.getIntakeRampSC());
	}

START_ROBOT_CLASS(Robot)
