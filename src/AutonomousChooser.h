/*
 * AutonomousChooser.h
 *
 *  Created on: Jan 27, 2018
 *      Author: osfalcons
 */

#ifndef SRC_AUTONOMOUSCHOOSER_H_
#define SRC_AUTONOMOUSCHOOSER_H_

#include <atomic>   // For atomic variables.
#include <chrono>   // For millisecond duration type.
#include <cstdint>  // For standard type definitions.
#include <iomanip>  // For hex, setw, and setfill.
#include <thread>   // For thread and sleep_for.

class AutonomousChooser {
public:
    AutonomousChooser();
    virtual ~AutonomousChooser();
    uint32_t GetCount() const;
    void StopThread();
    int AutonomousSelection();
private:
    void ThreadBody();
    // The order I declared these in is important because it is the order the
    // copmiler will initialize them in. We do not want the thread body to
    // start before the variables are initialized.

    //! Atomic variables need to be of limited fixed sizes. They are modified
    //! with special functions that use CPU primitives to update without the
    //! need of operating system locks.
    std::atomic_uint mCounter;

    //! Thread loop control variable. The thread will run while this is true
    //! and exit when it becomes false.
    std::atomic_bool mRun;

    //! Object encapsulating an execution thread.
    std::thread mThread;

    int currentSelection;
};

#endif /* SRC_AUTONOMOUSCHOOSER_H_ */
