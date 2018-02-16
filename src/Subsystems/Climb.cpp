#include <Subsystems/Climb.h>

Climb::Climb() : frc::Subsystem("Climb") {}

void Climb::InitDefaultCommand() {}

void Climb::Extend(float speed) {
	climbExtendPipe.Set(speed);
}

void Climb::Retract(float speed) {
	climbRetractRope.Set(speed);
}

void Climb::Off() {
	climbExtendPipe.Set(0.0);
	climbRetractRope.Set(0.0);
}

Climb::~Climb() {}
