/*
 *  Created on: Nov 27, 2015
 *      Author: jan
 */
#include "KeyboardInputSource.h"

KeyboardInputSource::~KeyboardInputSource()
{
#ifdef DEBUG
	LOG_DEBUG_MEM("      # KeyboardInputSource destructor on [%#lx]\n" , this);
#endif
}

#ifdef LOCAL_ENV
//===========================
// Read INPUT on Local system
//===========================
uint8_t KeyboardInputSource::readInput() {
	printf("Enter a character: ");
	string input;
	cin >> input;

//	printf("You entered %c.\n", chr);

	printf("Entered >>> [%s]\n", input.c_str());
	return input.at(0); //chr;
}

#endif

#ifdef MCU_ENV

#include "Arduino.h"
//===========================
// Read INPUT on MCU
//===========================
uint8_t KeyboardInputSource::readInput()
{
	char chr;
	Serial.print("Enter a character: ");
	Serial.flush();

	// block waiting on Serial input
	while (Serial.available() == 0)
		;
	chr = Serial.read();
	Serial.	printf("Entered >>> %c [%i]\n", chr, chr);

	return chr;
}

#endif

#ifdef TEST_ENV

uint8_t KeyboardInputSource::readInput()
{
	return 'a';
}

#endif
