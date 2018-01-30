/*
 * AutonomousChooser.cpp
 *
 *  Created on: Jan 27, 2018
 *      Author: osfalcons
 */

#include <AutonomousChooser.h>
#include "RevRoboticsDigitBoard.h"
#include "SuspendableThread.h"
#include <string>

AutonomousChooser::AutonomousChooser()
	: currentSelection( 1 )
{
	SetRunDelay(std::chrono::milliseconds(100));
	Run();
}

AutonomousChooser::~AutonomousChooser() {

}


void AutonomousChooser::OnRun()
{

	REVDigitBoard RRDB;
	static bool OldA = false;
	if( RRDB.getButtonA() == true && OldA == false){
		currentSelection++;
	}
	if( currentSelection == 4 ){
		currentSelection = 1;
	}
	// This could be anything. But for example purposes I am just
	// incrementing a counter value to demonstrate the thread is
	// running even though main() never increments the counter.
	OldA = RRDB.getButtonA();
	RRDB.display(std::to_string(currentSelection));


}

int AutonomousChooser::AutonomousSelection() {
	return currentSelection;
}
