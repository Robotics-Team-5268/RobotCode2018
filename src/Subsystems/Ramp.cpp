/*
 * Ramp.cpp
 *
 *  Created on: Jan 22, 2018
 *      Author: Team5268
 */

#include <Subsystems/Ramp.h>
#include "Robot.h"
#include "RobotMap.h"
#include "CommandBase.h"
#include "Commands/RampUp.h"
#include "Commands/RampDown.h"
#include "Commands/Intake.h"
#include "CommandBase.h"

#include <SmartDashboard/SmartDashboard.h>

Ramp::Ramp() :
	frc::Subsystem("Ramp") {

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

void Ramp::UpperUp(float Value) {
	rampUpper.Set(Value);
}

void Ramp::UpperDown(float Value) {
	rampUpper.Set(Value);
}

void Ramp::UpperStop() {
	rampUpper.Set(0.0);
}

void Ramp::LowerUp(float Value) {
	rampLower.Set(Value);
}

void Ramp::LowerDown(float Value) {
	rampLower.Set(Value);
}

void Ramp::LowerStop() {
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
