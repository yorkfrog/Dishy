/*
 * main.cpp
 *
 *  Created on: Nov 27, 2015
 *      Author: jan
 */

#include "main.h"
#include "stdio.h"

#include "Arduino.h"

void setup() {
	pinMode(LED_BUILTIN, OUTPUT);
}

//inputEvent iEvent;
char input = '\0';
int actionResult = 0;

void loop() {
	input = readInput();

	// ***
	// doActionOnInput is dependent on all action functions and we can't test the
	// result of the actionFunctions or the result of the doAction... function.
	// Also, likely, action functions will have side effects (hardware...).
	//
	// p0erhaps this is where a Action class could created and an array of Actions could
	// be passed in to the doAction function to operate on.

	actionResult = doActionOnInput(input);

	printf("Action result:%d\n", actionResult);

}



/*
//===========================
// Do Actions / OUTPUTS
//===========================
int doActionButton1(char input) {
	printf("\nDoing action ONE on [%c].\n", input);
	return 1;
}
int doActionButton2(char input) {
	printf("\nDoing action TWO on [%c].\n", input);
	return 1;
}
int doActionButton3(char input) {
	printf("\nDoing action THREE on [%c].\n", input);
	return 1;
}
int doActionButton4(char input) {
	printf("\nDoing action FOUR on [%c].\n", input);
	return 1;
}

int doActionDefault(char input) {
	printf("\nNO action for [%c].\n", input);
	return 0;
}

int doActionOnInput(char input) {
	switch (input) {
	case '1':
		result = doActionButton1(input);
		break;
	case '2':
		result = doActionButton2(input);
		break;
	case '3':
		result = doActionButton3(input);
		break;
	case '4':
		result = doActionButton4(input);
		break;
	default:
		result = doActionDefault(input);
		break;
	}
	return result;
}

*/
