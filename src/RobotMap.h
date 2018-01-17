/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <SpeedControllerGroup.h>
#include <SpeedController.h>

#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
#include "ctre/Phoenix.h" // we get this from the people who make the CAN talons


// this used to be in a file called RobotParameters. We put that information here for simplicity.
#define DRIVE_SPEED_CONTROLLER_FL_CHANNEL 0
#define DRIVE_SPEED_CONTROLLER_FR_CHANNEL 1
#define DRIVE_SPEED_CONTROLLER_BL_CHANNEL 2
#define DRIVE_SPEED_CONTROLLER_BR_CHANNEL 3

#define GYRO_SPI_PORT 							SPI::kOnboardCS0_

#define CAMERA_XRES 640
#define CAMERA_YRES 480

#define RIGHT_TRIGGER 3
#define LEFT_TRIGGER 2

#define Y_ERROR_MARGIN 15 // PIXELS
#define X_ERROR_MARGIN 20
#define AREA_ERROR_MARGIN .15 // PERCENT ERROR

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

class RobotMap {
public:
	static std::shared_ptr<SpeedController> speedControllerFL; // Front Left
	static std::shared_ptr<SpeedController> speedControllerFR; // Front Right
	static std::shared_ptr<SpeedController> speedControllerBL; // Back Left
	static std::shared_ptr<SpeedController> speedControllerBR; // Back Right

	static std::shared_ptr<RobotDrive> driveRobotDrive4; // this is the variable for the drive system as a whole

	static std::shared_ptr<AnalogGyro>driveGyro;

	static void init();
};
#endif// ROBOTMAP_H
