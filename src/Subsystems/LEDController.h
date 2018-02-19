#ifndef LEDController_H
#define LEDController_H

#include "RobotMap.h"
#include "Commands/Subsystem.h"
#include "WPILib.h"
// This turns the LEDs on and off, please do not set them to reverse or you get magic smoke.
// We don't like magic smoke.

class LEDController: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	frc::Relay ledCamRelay{LED_CAMERA}; // relayNum 0
	frc::Relay ledPanelRelay{LED_PANEL}; // relayNum 1

	bool ledCam_state = false;
	bool ledPanel_state = false;
public:
	LEDController();
	void InitDefaultCommand();
	void TurnOn(int relayNum);
	void TurnOff(int relayNum);
	bool IsOn(int relayNum);
};

#endif
