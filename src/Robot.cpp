#include "Robot.h"
#include "RobotMap.h"
#include <Commands/Scheduler.h>
#include "Subsystems/REVDigitBoard.h"
#include <SmartDashboard/SmartDashboard.h>
#include <RobotController.h>
#include "Commands/RampCalibrate.h"

std::unique_ptr<Autonomous> Robot::autonomousCommand;

// This subsystem is here for some reason
// Most of the subsystems are in CommandBase
AutonomousChooser Robot::AutoChooser;

void Robot::RobotInit() { // initializes the main things needed for the robot to run.
	// runs when the robot starts.
	CommandBase::init();
	CommandBase::drive->safetyOff();
	CommandBase::leds->TurnOn(LED_PANEL);
}

void Robot::RobotPeriodic() {}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {
	frc::Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {// runs when the autonomous portion of the game starts.
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

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

void Robot::AddSmartDashboardItems() {
	SmartDashboard::PutNumber("Gyro Angle", CommandBase::drive->getGyroAngle());
	SmartDashboard::PutNumber("Joystick X", CommandBase::oi->getDriverJoystick()->GetX());
	SmartDashboard::PutNumber("Joystick Y", CommandBase::oi->getDriverJoystick()->GetY());
	SmartDashboard::PutNumber("Left Trigger", CommandBase::oi->getDriverJoystick()->GetRawAxis(LEFT_TRIGGER));
	SmartDashboard::PutNumber("Right Trigger", CommandBase::oi->getDriverJoystick()->GetRawAxis(RIGHT_TRIGGER));
	SmartDashboard::PutNumber("upperRampSC", CommandBase::ramp->getUpperRampSC());
	SmartDashboard::PutNumber("lowerRampSC", CommandBase::ramp->getLowerRampSC());
	SmartDashboard::PutNumber("intakeRampSC", CommandBase::ramp->getIntakeRampSC());
	SmartDashboard::PutData("Calibrate ramp", new RampCalibrate());
}

START_ROBOT_CLASS(Robot)
