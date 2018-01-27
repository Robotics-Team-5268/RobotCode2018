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

#include <SmartDashboard/SmartDashboard.h>

Ramp::Ramp() :
	frc::Subsystem("Ramp") {

}

void Ramp::InitDefaultCommand() {}

double Ramp::getUpperRampSC() {
	return upperRampSC.Get();
}

double Ramp::getLowerRampSC() {
	return lowerRampSC.Get();
}

double Ramp::getIntakeRampSC() {
	return intakeRampSC.Get();
}

void Ramp::UpperUp(float Value) {
	upperRampSC.Set(Value);
	SmartDashboard::PutNumber("UpperUp", 1.0);
}

void Ramp::UpperDown(float Value) {
	upperRampSC.Set(Value);
}

void Ramp::UpperStop() {
	upperRampSC.Set(0.0);
}

void Ramp::LowerUp(float Value) {
	lowerRampSC.Set(Value);
}

void Ramp::LowerDown(float Value) {
	lowerRampSC.Set(Value);
}

void Ramp::LowerStop() {
	lowerRampSC.Set(0.0);
}

void Ramp::IntakeOn(float Value) {
	intakeRampSC.Set(Value);
}

void Ramp::IntakeOff() {
	intakeRampSC.Set(0.0);
}

Ramp::~Ramp() {
}
