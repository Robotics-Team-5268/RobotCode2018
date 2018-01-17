#pragma once
#ifndef OI_H
#define OI_H

#include "WPILib.h"
// this class defines the stuff we use to control the robot. OI stands for operator input.
class OI {
private:
	std::shared_ptr<Joystick> driverJoystick;
	std::vector<JoystickButton*> driverBtns;
public:
	OI();

	std::shared_ptr<Joystick> getDriverJoystick();
	bool getDriverButtonPressed(int btnNum);
};
#endif
