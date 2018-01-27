#include "Robot.h"
#include "RobotMap.h"
#include "RevRoboticsDigitBoard.h"

#include <Commands/Scheduler.h>
#include <SmartDashboard/SmartDashboard.h>

std::unique_ptr<Autonomous> Robot::autonomousCommand;

Ramp Robot::ramp;

	void Robot::RobotInit(){// initializes the main things needed for the robot to run.
		// runs when the robot starts.
		RobotMap::init();
		CommandBase::init();

		CommandBase::drive->safetyOff();

		autonomousChooser.reset(new SendableChooser<int*>());
		autonomousChooser->AddDefault("Right", new int(1));
		autonomousChooser->AddObject("Center", new int(2));
		autonomousChooser->AddObject("Left", new int(3));
		SmartDashboard::PutData("Autonomous", autonomousChooser.get());


	}

	void Robot::DisabledInit() {}

	void Robot::DisabledPeriodic() {
		frc::Scheduler::GetInstance()->Run();
	}

	void Robot::AutonomousInit() {// runs when the autonomous portion of the game starts.
		RobotMap::driveGyro->Reset();
		int* selection = autonomousChooser->GetSelected();
		autonomousCommand.reset(new Autonomous(*selection));
		autonomousCommand->Start();
	}

	void Robot::AutonomousPeriodic() {// continuously runs during autonomous portion of the game.
		frc::Scheduler::GetInstance()->Run();
		AddSmartDashboardItems();
	}

	void Robot::TeleopInit() {// runs when the teleop portion of the game starts.
		CommandBase::drive->getGyro()->Reset();

		REVDigitBoard digitBoard;
		digitBoard.display("Plus");
		//SmartDashboard::PutNumber("Digit Board Test A Button", digitBoard.getButtonA());
		//SmartDashboard::PutNumber("Digit Board Test B Button", digitBoard.getButtonB());
		//SmartDashboard::PutNumber("Digit Board Test Pot", digitBoard.getPot());
	}

	void Robot::TeleopPeriodic() { //continuously runs during teleop portion of the game.
		frc::Scheduler::GetInstance()->Run();
		AddSmartDashboardItems();

	}

	void Robot::TestPeriodic() {}

	void Robot::AddSmartDashboardItems() {
		SmartDashboard::PutNumber("Speed Controller 1", RobotMap::speedControllerFL->Get());
		SmartDashboard::PutNumber("Speed Controller 2", RobotMap::speedControllerFR->Get());
		SmartDashboard::PutNumber("Speed Controller 3", RobotMap::speedControllerBL->Get());
		SmartDashboard::PutNumber("Speed Controller 4", RobotMap::speedControllerBR->Get());
		SmartDashboard::PutNumber("Gyro Angle", RobotMap::driveGyro->GetAngle());
		SmartDashboard::PutNumber("Joystick X", CommandBase::oi->getDriverJoystick()->GetX());
		SmartDashboard::PutNumber("Joystick Y", CommandBase::oi->getDriverJoystick()->GetY());
		SmartDashboard::PutNumber("Left Trigger", CommandBase::oi->getDriverJoystick()->GetRawAxis(LEFT_TRIGGER));
		SmartDashboard::PutNumber("Right Trigger", CommandBase::oi->getDriverJoystick()->GetRawAxis(RIGHT_TRIGGER));
		SmartDashboard::PutNumber("upperRampSC", ramp.getUpperRampSC());
		SmartDashboard::PutNumber("lowerRampSC", ramp.getLowerRampSC());
		SmartDashboard::PutNumber("intakeRampSC", ramp.getIntakeRampSC());
	}

START_ROBOT_CLASS(Robot)
