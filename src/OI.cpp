#include <Commands/LEDToggle.h>
#include <Commands/RampControl.h>
#include <WPILib.h>
#include "OI.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/Intake.h"
#include "Robot.h"

OI::OI() {
	// Process operator interface input here.
	driverJoystick.reset(new Joystick(0));
	driverJoystick2.reset(new Joystick(1)); // Second Joystick Controller, Exactly same as first Controller, except all methods and objects are appended by 2

	for (int i = 1; i <= 10; i++) {
	   driverBtns.push_back(new JoystickButton(driverJoystick.get(), i));
	}
	for (int i = 1; i <= 10; i++) {
	   driverBtns2.push_back(new JoystickButton(driverJoystick2.get(), i));
	}

	//driverJoystick->SetRumble(GenericHID::kRightRumble, 1);

	//driverBtns[1]->WhenPressed(new LEDToggle(LED_CAMERA));

	driverBtns2[0]->WhileHeld(new RampControl(1.0)); //A - Make ramp go up to launch cube
	driverBtns2[1]->WhileHeld(new RampControl(-.25)); //B - Make ramp go down in case cube is too far up ramp (not for dropping cube off ramp)
	driverBtns2[2]->WhileHeld(new Intake(-1.0)); //X - Make intake go in and get the cube on the ramp
	driverBtns2[3]->WhileHeld(new Intake(1.0)); //Y - Make intake go out

	//driverBtns2[4]->WhileHeld(new ClimbWithButton(ClimbWithButton::climbExtend, 0.25));
	//driverBtns2[5]->WhileHeld(new ClimbWithButton(ClimbWithButton::climbRetract, -1.0));
}

std::shared_ptr<Joystick> OI::getDriverJoystick() {
	return driverJoystick;
}
std::shared_ptr<Joystick> OI::getDriverJoystick2() {
	return driverJoystick2;
}
bool OI::getDriverButtonPressed(int btnNum){
	return driverBtns[btnNum-1]->Get();
}
bool OI::getDriverButtonPressed2(int btnNum){
	return driverBtns2[btnNum-1]->Get();
}
