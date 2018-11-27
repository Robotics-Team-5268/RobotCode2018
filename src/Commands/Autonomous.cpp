
#include "AutonomousChooser.h"
#include "Autonomous.h"
#include "Commands/Move.h"
#include "Commands/Rotate.h"
#include "Commands/RampControl.h"
#include "Commands/MoveEncoder.h"
#include "Robot.h"

/*
 * All of the move values in this file are completely arbitrary
 * and have not been tested
 */
Autonomous::Autonomous(int selection) : CommandGroup("Autonomous") {
	std::string gameData;
	gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
	AddSequential(new Move(2,0));
	// Move straight away from the wall
	AddSequential(new MoveEncoder(4, .5, 115)); // UNCOMMENT ME!! @TODO
	AddSequential(new Move(1.25, .5));
	// Move to the side if needed, based on starting position
	// and which switch plate belongs to our team.
	// selection comes from where we positioned the robot to start,
	// and gameData comes from First to say which switch plate is ours.
	switch(selection) {
	case 1: //right

		if(gameData[0] == 'L') { // if left switch plate is ours\
			/*AddSequential(new Rotate(-90));
			AddSequential(new MoveEncoder(3, .5, 100));
			AddSequential(new Rotate(90));
			AddSequential(new Rotate(-90));
			AddSequential(new Move(1.75, .5));
			AddSequential(new Rotate(90));
		}
		else{ //right
			AddSequential(new Rotate(-90));
			AddSequential(new RampControl(1.0, 1));}
		break;

	case 2: //center
		//this if if we are the center of the 3 robots and in front of the right side of the switch
		if (gameData[0] == 'R') {AddSequential(new RampControl(1.0, 1));}

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

		//AddSequential(new Rotate(90));
		if (gameData[0] == 'R') {
			//AddSequential(new MoveEncoder(2, .5, 100));
		} else {
			//AddSequential(new Move(.25, .5));
			AddSequential(new RampControl(1.0, 1));
		}
		//AddSequential(new Rotate(-90));
		break;
	case 4: //test
		//AddSequential(new Move(3, 0));
		//AddSequential(new MoveEncoder(3, .5, 24));
		AddSequential(new Rotate(80));

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

	//AddSequential(new MoveEncoder(3, .5, 60));

	AddSequential(new Move(1, .5));
	// Deploy cube
	//AddSequential(new RampControl(1.0, 1));
}
