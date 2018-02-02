#include <Subsystems/Drive.h>
#include <Commands/DriveWithJoystick.h>
#include "Robot.h"
#include "Drive.h"
#include "RobotMap.h"
#include "CommandBase.h"

Drive::Drive() : Subsystem("Drive") {
	//robotDrive4 = RobotMap::driveRobotDrive4;
	gyro = RobotMap::driveGyro;
	oldX = 0.0;
	oldY = 0.0;
	oldLeftSpeed = 0.0;
	oldRightSpeed = 0.0;
	speedControllerFL.SetInverted(SCFL_INVERTED);
	speedControllerBL.SetInverted(SCBL_INVERTED);
	speedControllerFR.SetInverted(SCFR_INVERTED);
	speedControllerBR.SetInverted(SCBR_INVERTED);

}
void Drive::InitDefaultCommand() {
	//set the default command
	SetDefaultCommand(new DriveWithJoystick());
}
void Drive::takeInput() { //takes input from controller to drive robot in teleop
	float X = CommandBase::oi->getDriverJoystick()->GetX();
	float Y = CommandBase::oi->getDriverJoystick()->GetY();

	// Limit the acceleration of the robot.
	// This is done to prevent brownouts.
	if (X > oldX + MAX_CHANGE) X = oldX + MAX_CHANGE;
	else if (X < oldX - MAX_CHANGE) X = oldX - MAX_CHANGE;
	if (Y > oldY + MAX_CHANGE) Y = oldY + MAX_CHANGE;
	else if (Y < oldY - MAX_CHANGE) Y = oldY - MAX_CHANGE;

	diffDrive.ArcadeDrive(-Y,X);
	//robotDrive4->ArcadeDrive(X,Y);// works, X and Y are swapped

	// Store these values for next time.
	oldX = X;
	oldY = Y;
}
void Drive::setMotors(float leftSpeed, float rightSpeed){// add acceleration limit to reduce gear box wear and tear
	// Limits acceleration to prevent jerky motion and brownouts
	if (leftSpeed > oldLeftSpeed + MAX_CHANGE) leftSpeed = oldLeftSpeed + MAX_CHANGE;
	else if (leftSpeed < oldLeftSpeed - MAX_CHANGE) leftSpeed = oldLeftSpeed - MAX_CHANGE;
	if (rightSpeed > oldRightSpeed + MAX_CHANGE) rightSpeed = oldRightSpeed + MAX_CHANGE;
	else if (rightSpeed < oldRightSpeed - MAX_CHANGE) rightSpeed = oldRightSpeed - MAX_CHANGE;

	diffDrive.TankDrive(leftSpeed, rightSpeed, false);

	SmartDashboard::PutNumber("Speed Controller 0", speedControllerFL.Get());
	SmartDashboard::PutNumber("Speed Controller 1", speedControllerFR.Get());
	SmartDashboard::PutNumber("Speed Controller 2", speedControllerBL.Get());
	SmartDashboard::PutNumber("Speed Controller 3", speedControllerBR.Get());


	// Store these values for next time.
	oldLeftSpeed = leftSpeed;
	oldRightSpeed = rightSpeed;
}
AnalogGyro* Drive::getGyro() {
	return gyro.get();
	return nullptr;
}
Drive::~Drive() {
	// TODO Auto-generated destructor stub

}

