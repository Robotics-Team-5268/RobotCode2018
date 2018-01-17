#ifndef SRC_SUBSYSTEMS_DRIVE_H_
#define SRC_SUBSYSTEMS_DRIVE_H_
#include "Commands/Subsystem.h"
#include "WPILib.h"

//this class controls all the systems for driving. it does not take input from the controller.

class Drive: public Subsystem  {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities

	// initializes speed controllers for Drive to use
	std::shared_ptr<SpeedController> speedControllerFL;
	std::shared_ptr<SpeedController> speedControllerFR;
	std::shared_ptr<SpeedController> speedControllerBL;
	std::shared_ptr<SpeedController> speedControllerBR;

	float oldX, oldY;
	const float MAX_CHANGE = .05;

	//std::shared_ptr<AnalogGyro> gyro;


public:
	Drive();
	void safetyOff(){robotDrive4->SetSafetyEnabled(false);}
	void InitDefaultCommand();
	AnalogGyro* getGyro();
	void setMotors(float leftSpeed, float rightSpeed);
	void takeInput();
	virtual ~Drive();
	std::shared_ptr<RobotDrive> robotDrive4;
};

#endif /* SRC_SUBSYSTEMS_DRIVE_H_ */
