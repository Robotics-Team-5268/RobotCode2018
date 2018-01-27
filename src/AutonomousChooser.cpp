/*
 * AutonomousChooser.cpp
 *
 *  Created on: Jan 27, 2018
 *      Author: osfalcons
 */

#include <AutonomousChooser.h>
#include "RevRoboticsDigitBoard.h"
#include <string>

AutonomousChooser::AutonomousChooser()
    : mCounter( 0u )
    , mRun( true )
    // Creates a thread that will run the function ThreadBody(). Since that
    // function is a member of ExampleDeviceThread we need to pass the
    // this pointer. All non-static member functions have an implicit first
    // argument of the class type.
    , mThread( &AutonomousChooser::ThreadBody, this )
	, currentSelection( 1 )
{
}

AutonomousChooser::~AutonomousChooser() {
	// Indicate we want the thread to stop.
    StopThread();
    // Wait for the thread to stop. The function joinable() is used to
    // ensure mThread is not the current thread and contains a valid
    // thread. There are cases where std::thread does not represent a
    // valid execution context.
    if( mThread.joinable() )
    {
        mThread.join();
    }
}

uint32_t AutonomousChooser::GetCount() const
{
	return mCounter;
}

void AutonomousChooser::StopThread()
{
    mRun = false;
}

void AutonomousChooser::ThreadBody()
{
	REVDigitBoard RRDB;
	bool OldA = false;



	while( true == mRun )
    {
		if( RRDB.getButtonA() == true && OldA == false){
			currentSelection++;
		}
		if( currentSelection == 4 ){
			currentSelection = 1;
		}
        // This could be anything. But for example purposes I am just
        // incrementing a counter value to demonstrate the thread is
        // running even though main() never increments the counter.
        mCounter += 1;
        OldA= RRDB.getButtonA();
        RRDB.display(std::to_string(currentSelection));
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

}

int AutonomousChooser::AutonomousSelection() {
	return currentSelection;
}
