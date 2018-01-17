#include "OI.h"
#include "SmartDashboard/SmartDashboard.h"

#include <WPILib.h>

OI::OI() {
	// Process operator interface input here.
	// Process operator interface input here.
	   driverJoystick.reset(new Joystick(0));

	   for(int i = 1; i <= 10; i++){
		   driverBtns.push_back(new JoystickButton(driverJoystick.get(), i));
	   }

}

std::shared_ptr<Joystick> OI::getDriverJoystick() {
	return driverJoystick;
}
bool OI::getDriverButtonPressed(int btnNum){
	return driverBtns[btnNum-1]->Get();
}
