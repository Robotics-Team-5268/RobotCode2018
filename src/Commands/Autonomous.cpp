
#include "AutonomousChooser.h"
#include "Autonomous.h"
#include "Commands/Move.h"
#include "Commands/Rotate.h"
#include "Commands/RampControl.h"
#include "Robot.h"

/*
 * All of the move values in this file are completely arbitrary
 * and have not been tested
 */
Autonomous::Autonomous(int selection) : CommandGroup("Autonomous") {
	std::string gameData;
	gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();

	// Move straight away from the wall
	AddSequential(new Move(1.25, .5));

	// Move to the side if needed, based on starting position
	// and which switch plate belongs to our team.
	// selection comes from where we positioned the robot to start,
	// and gameData comes from First to say which switch plate is ours.
	switch(selection) {
	case 1: //right

		if(gameData[0] == 'L') { // if left switch plate is ours
			AddSequential(new Rotate(-90));
			AddSequential(new Move(1.75, .5));
			AddSequential(new Rotate(90));
		}
		break;

	case 2: //center

		if (gameData[0] == 'L') {
			AddSequential(new Rotate(-90));
			AddSequential(new Move(.5, .5));
			AddSequential(new Rotate(90));
		} else { // Right
			AddSequential(new Rotate(90));
			AddSequential(new Move(.5, .5));
			AddSequential(new Rotate(-90));
		}
		break;

	case 3: //left
		AddSequential(new Rotate(90));
		if (gameData[0] == 'R') {
			AddSequential(new Move(2, .5));
		} else {
			AddSequential(new Move(.25, .5));
		}
		AddSequential(new Rotate(-90));
		break;

	default:
		break;
	}

	// Move forward to the switch plate
	AddSequential(new Move(1, .5));

	// Deploy cube
	AddSequential(new RampControl(1.0, 1));
}
