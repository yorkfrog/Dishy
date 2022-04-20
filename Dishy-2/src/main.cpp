/*
 * main.cpp
 *
 *  Created on: Nov 27, 2015
 *      Author: jan
 */
#include <iostream>
using namespace std;
#include "main.h"
#include "stdio.h"

#include "Arduino.h"

void setup() {
	pinMode(LED_BUILTIN, OUTPUT);
}

//inputEvent iEvent;
char input = '\0';

void loop() {

	input = readInput();

	// ***
	// doActionOnInput is dependent on all action functions and we can't test the
	// result of the actionFunctions or the result of the doAction... function.
	// Also, likely, action functions will have side effects (hardware...).
	//
	// p0erhaps this is where a Action class could created and an array of Actions could
	// be passed in to the doAction function to operate on.

	ActionEvent inputEvent = getEventForInput(input);

	BaseAction *pAction = NULL;

	if (inputEvent.getId() == invalidEvent && inputEvent.getData() == 'x') {
		cout << "EXIT 1 -- ACTION INSTANCE COUNT == [" << BaseAction::instanceCount
				<< endl;
		if (BaseAction::instanceCount > 0) {
			delete pAction;
		}
		cout << "EXIT 2 -- ACTION INSTANCE COUNT == [" << BaseAction::instanceCount
				<< endl;
		exit(0);

	} else if (inputEvent.getId() == invalidEvent) {
		printf("Invalid input [%c]\n", inputEvent.getData());

	} else {

		pAction = getAction(inputEvent);

		cout << "Action RUN ..." << endl;

		int actionResult = pAction->run();
		delete pAction;

		printf("Action result:[%d]\n", actionResult);

	}

	if (BaseAction::instanceCount > 0) {
		cout << "**** MEMORY LEAK - ACTION INSTANCE COUNT should be Zero, but == [" << BaseAction::instanceCount << endl;
	}

}

/*
 Action getAction(ActionEvent &event) {
 cout << "   *** 021" << endl;
 return Action(&event);
 }

 */

BaseAction* getAction(ActionEvent &event) {

	BaseAction *newAction = NULL;
	BaseAction* singleAction = NULL;
	int result = 0;
	switch (event.getId()) {
	case btn1pressEvent:
		newAction = new DisplayAction(1, &event);
		break;
	case btn2pressEvent:
		singleAction = new DisplayAction(2, &event);
		newAction = new ActionGroup(singleAction);
		break;
	case btn3pressEvent:
		newAction = new DisplayAction(3, &event);
		break;
	case btn4pressEvent:
		newAction = new DisplayAction(4, &event);
		break;
	default:
		newAction = new ActionGroup(&event);
		cout << "NEW ACTION:" << newAction->toString();
		break;
	}
	return newAction;
}

ActionEvent getEventForInput(char input) {
	int eventType = invalidEvent;
	switch (input) {
	case '1':
		eventType = btn1pressEvent;
		break;
	case '2':
		eventType = btn2pressEvent;
		break;
	case '3':
		eventType = btn3pressEvent;
		break;
	case '4':
		eventType = btn4pressEvent;
		break;
	default:
		break;
	}
	return ActionEvent(eventType, input);
}
