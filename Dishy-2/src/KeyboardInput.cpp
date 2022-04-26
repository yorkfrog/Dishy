/*
 *  Created on: Nov 27, 2015
 *      Author: jan
 */
#include "KeyboardInput.h"

#ifdef LOCAL_ENV
//===========================
// Read INPUT on Local system
//===========================
char readInput() {
	char chr;
	char cr;
	printf("Enter a character: ");
//	scanf("%c%c",&chr, &cr);
	string input;
	cin >> input;

//	printf("You entered %c.\n", chr);

	cout << "You entered " << input << endl;
	return input.at(0); //chr;
}

#endif

#ifdef MCU_ENV

#include "Arduino.h"
//===========================
// Read INPUT on MCU
//===========================
char readInput()
{
	char chr;
	Serial.print("Enter a character: ");
	Serial.flush();

	// block waiting on Serial input
	while (Serial.available() == 0)
		;
	chr = Serial.read();
	Serial.printf("Entered >>> [%i][%c]\n", chr, chr);

	return chr;
}

#endif

