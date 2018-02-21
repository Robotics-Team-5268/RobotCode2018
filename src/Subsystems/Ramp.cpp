#include <Commands/RampControl.h>
#include <Subsystems/Ramp.h>
#include "Robot.h"
#include "RobotMap.h"
#include "CommandBase.h"
#include "Commands/Intake.h"
#include "CommandBase.h"

#include <SmartDashboard/SmartDashboard.h>

Ramp::Ramp() : frc::Subsystem("Ramp") {
	rampUL_SC.SetInverted(false);
	rampUR_SC.SetInverted(false);
	rampML_SC.SetInverted(true);
	rampMR_SC.SetInverted(false);
	rampLL_SC.SetInverted(true);
	rampLR_SC.SetInverted(false);
	rampIntakeR_SC.SetInverted(true);
	rampIntakeL_SC.SetInverted(false);
}

void Ramp::InitDefaultCommand() {}


double Ramp::getUpperRampSC() {
	//return upperRampSC.Get();
	return rampUpper.Get();
}

double Ramp::getLowerRampSC() {
	//return lowerRampSC.Get();
	return rampLower.Get();
}

double Ramp::getIntakeRampSC() {
	return rampIntake.Get();
}

void Ramp::UpperOn(float Value) {
	rampUpper.Set(Value);
}

void Ramp::UpperOff() {
	rampUpper.Set(0.0);
}

void Ramp::LowerOn(float Value) {
	rampLower.Set(Value);
}


void Ramp::LowerOff() {
	rampLower.Set(0.0);
}

void Ramp::IntakeOn(float Value) {
	rampIntake.Set(Value);
}

void Ramp::IntakeOff() {
	rampIntake.Set(0.0);
}

Ramp::~Ramp() {
}
