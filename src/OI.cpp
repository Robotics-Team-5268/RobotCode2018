#include <WPILib.h>
#include "OI.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/RampUp.h"
#include "Commands/RampDown.h"
#include "Commands/Intake.h"


OI::OI() {
	// Process operator interface input here.
	// Process operator interface input here.
	   driverJoystick.reset(new Joystick(0));

	   for(int i = 1; i <= 10; i++){
		   driverBtns.push_back(new JoystickButton(driverJoystick.get(), i));
	   }

	   driverBtns[0]->WhenPressed(new RampUp());
	   driverBtns[1]->WhenPressed(new RampDown());
	   driverBtns[2]->WhenPressed(new Intake(Intake::intakeForward));
	   driverBtns[3]->WhenPressed(new Intake(Intake::intakeReverse));
}

std::shared_ptr<Joystick> OI::getDriverJoystick() {
	return driverJoystick;
}
bool OI::getDriverButtonPressed(int btnNum){
	return driverBtns[btnNum-1]->Get();
}
