#pragma once

#include <Commands/Subsystem.h>
#include <WPILib.h>
#include <Drive/DifferentialDrive.h>
#include <SpeedController.h>
#include <SpeedControllerGroup.h>
#include <Talon.h>
#include <ctre/Phoenix.h>
#include "RobotMap.h"
#include "Subsystems/ITG3200Gyro.h"

//this class controls all the systems for driving. it does not take input from the controller.

class Drive: public Subsystem  {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities

	// initializes speed controllers for Drive to use
	WPI_TalonSRX speedControllerFL{DRIVE_SPEED_CONTROLLER_FL_CHANNEL};
	WPI_TalonSRX speedControllerBL{DRIVE_SPEED_CONTROLLER_BL_CHANNEL};
	frc::SpeedControllerGroup leftSC{speedControllerFL, speedControllerBL};

	WPI_TalonSRX speedControllerFR{DRIVE_SPEED_CONTROLLER_FR_CHANNEL};
	WPI_TalonSRX speedControllerBR{DRIVE_SPEED_CONTROLLER_BR_CHANNEL};
	frc::SpeedControllerGroup rightSC{speedControllerFR, speedControllerBR};

	frc::DifferentialDrive diffDrive{leftSC, rightSC};
	float oldX, oldY, oldLeftSpeed, oldRightSpeed;
	const float MAX_CHANGE = .05;

	//AnalogGyro gyro{GYRO_ANALOG_PORT};
	ADXRS450_Gyro gyro{GYRO_SPI_PORT};

	//ITG3200_Gyro newGyro;

public:
	Drive();
	~Drive();
	void safetyOff(){diffDrive.SetSafetyEnabled(false);}
	void InitDefaultCommand();

	//AnalogGyro* getGyro();
	ADXRS450_Gyro* getGyro();
	float getGyroAngle();
	void resetGyro();

	void setMotorsArcade(float move, float rotate);
	void setMotors(float leftSpeed, float rightSpeed);
	void takeInput();
};
