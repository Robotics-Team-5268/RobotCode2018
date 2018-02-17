#include "AutonomousChooser.h"
#include "Autonomous.h"
#include "Commands/Move.h"
#include "Commands/Rotate.h"
#include "Robot.h"

Autonomous::Autonomous(int selection) : CommandGroup("Autonomous") {
	std::string gameData;
	gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();

	// Move straight away from the wall
	AddSequential(new Move(4, .5));

	switch(selection) {
	case 1: //right

		if(gameData[0] == 'L') { // if left switch plate is ours
			AddSequential(new Rotate(-90));
			AddSequential(new Move(4, .5));
			AddSequential(new Rotate(90));
		}
		break;

	case 2: //center

		if(gameData[0] == 'L') {
			AddSequential(new Rotate(-45));
		} else { // Right
			AddSequential(new Rotate(45));
		}
		break;

	case 3: //left

		if(gameData[0] == 'R') {
			AddSequential(new Rotate(90));
			AddSequential(new Move(4, .5));
			AddSequential(new Rotate(-90));
		}
		break;

	default:
		break;
	}

	// Move forward to the switch plate
	AddSequential(new Move(2, .5));

	// Deploy cube - true changes end behavior
	//AddSequential(new RampUp(true));
}
