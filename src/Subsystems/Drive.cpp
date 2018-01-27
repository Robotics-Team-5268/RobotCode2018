#include <Subsystems/Drive.h>
#include <Commands/DriveWithJoystick.h>
#include "Robot.h"
#include "Drive.h"
#include "RobotMap.h"
#include "CommandBase.h"

Drive::Drive() : Subsystem("Drive") {
	// instantiates objects used in this class
	speedControllerFL = RobotMap::speedControllerFL;
	speedControllerFR = RobotMap::speedControllerFR;
	speedControllerBL = RobotMap::speedControllerBL;
	speedControllerBR = RobotMap::speedControllerBR;
	robotDrive4 = RobotMap::driveRobotDrive4;
	gyro = RobotMap::driveGyro;
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

	robotDrive4->ArcadeDrive(X,Y);// works, X and Y are swapped

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

	// set motor speeds
	speedControllerFL->Set(leftSpeed);
	speedControllerFR->Set(rightSpeed);
	speedControllerBL->Set(leftSpeed);
	speedControllerBR->Set(rightSpeed);

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

