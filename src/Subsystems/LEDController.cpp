#include "LEDController.h"
#include "../RobotMap.h"

LEDController::LEDController() : Subsystem("LEDController") {}

void LEDController::InitDefaultCommand() {}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void LEDController::TurnOff(int relayNum) {
	if (relayNum == LED_CAMERA) {
		ledCam_state = false;
		ledCamRelay.Set(frc::Relay::kOff);
	}
	else if (relayNum == LED_PANEL) {
		ledPanel_state = false;
		ledPanelRelay.Set(frc::Relay::kOff);
	}
}

void LEDController::TurnOn(int relayNum) {
	if(relayNum == LED_CAMERA) {
		ledCam_state = true;
		ledCamRelay.Set(frc::Relay::kForward);
	}
	else if(relayNum == LED_PANEL) {
		ledPanel_state = true;
		ledPanelRelay.Set(frc::Relay::kForward);
	}
	// DO NOT EVER SET RELAYS TO REVERSE
	// UNLESS THE WIRING GETS CHANGED.
	// This would fry the LED.
}

bool LEDController::IsOn(int relayNum) {
	if (relayNum == LED_CAMERA) {
		return ledCam_state;
	}
	else if (relayNum == LED_PANEL) {
		return ledPanel_state;
	}
	return false; // Invalid LED number (keeps compiler warnings happy)
}
