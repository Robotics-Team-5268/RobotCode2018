/*
 * RevRoboticsDigitBoard.h
 *
 *  Created on: Jan 20, 2018
 *      Author: Team5268
 */

#ifndef SRC_REVROBOTICSDIGITBOARD_H_
#define SRC_REVROBOTICSDIGITBOARD_H_

#include <I2C.h>
#include <Timer.h>
#include <DigitalInput.h>
#include <AnalogInput.h>
#include <string.h>

class REVDigitBoard {
	typedef unsigned char byte;

	/*
	 * DOCUMENTATION::
	 *
	 * REVDigitBoard() : constructor
	 * void display(String str) : displays the first four characters of the string (only alpha (converted to uppercase), numbers, and spaces)
	 * void display(double batt) : displays a decimal number (like battery voltage) in the form of 12.34 (ten-one-decimal-tenth-hundredth)
	 * void clear() : clears the display
	 * boolean getButtonA() : button A on the board
	 * boolean getButtonB() : button B on the board
	 * double getPot() : potentiometer value
	 */
public:
	REVDigitBoard();
	void clear();
	bool getButtonA();
	bool getButtonB();
    double getPot();
	void display(double batt);
	void display(std::string str);

private:
	void _display( byte charz[4]);

	frc::I2C i2c;
	DigitalInput buttonA, buttonB;
	AnalogInput pot;

	byte charreg[37][2];
	byte charmap[256];
};

#endif /* SRC_REVROBOTICSDIGITBOARD_H_ */
