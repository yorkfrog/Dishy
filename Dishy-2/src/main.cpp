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

// enable NDEBUG to disable assert()
#define NDEBUG
#include <assert.h>     /* assert */


#include "Arduino.h"

void doExit(Action* pAction);
void assertNoMemoryLeak();

void setup() {
	pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {

	char input = '\0';
	Action *pAction = NULL;

	input = readInput();

	InputEvent inputEvent = getEventForInput(input);


	if (inputEvent.getId() == InputEvent::invalidEvent && inputEvent.getData() == 'x') {
		doExit(pAction);

	} else if (inputEvent.getId() == InputEvent::invalidEvent) {
		cout << "Invalid input " << inputEvent.getData() << endl;;

	} else {

		pAction = getAction(inputEvent);

		cout << "Action RUN ..." << endl;

		int actionResult = pAction->run();
		delete pAction;

		cout << "Action result:" << actionResult << endl;

	}

	assertNoMemoryLeak();

}


Action* getAction(InputEvent &event) {

	Action* newAction = NULL;
	Action* singleAction = NULL;
	int result = 0;
	switch (event.getId()) {
	case InputEvent::btn1pressEvent:
		singleAction = new DisplayAction(1, &event);
		newAction = new ActionGroup(singleAction);
		break;
	case InputEvent::btn2pressEvent:
		singleAction = new DisplayAction(2, &event);
		newAction = new ActionGroup(singleAction);
		break;
	case InputEvent::btn3pressEvent:
		newAction = new DisplayAction(3, &event);
		break;
	case InputEvent::btn4pressEvent:
		newAction = new NullAction(&event);
		break;
	default:
		newAction = new NullAction(&event);
		cout << "NEW ACTION:" << newAction->toString();
		break;
	}
	return newAction;
}

InputEvent getEventForInput(char input) {
	int eventType = InputEvent::invalidEvent;
	switch (input) {
	case '1':
		eventType = InputEvent::btn1pressEvent;
		break;
	case '2':
		eventType = InputEvent::btn2pressEvent;
		break;
	case '3':
		eventType = InputEvent::btn3pressEvent;
		break;
	case '4':
		eventType = InputEvent::btn4pressEvent;
		break;
	default:
		break;
	}
	return InputEvent(eventType, input);
}

void assertNoMemoryLeak() {
	if (BaseAction::instanceCount > 0) {
		cout << "**** MEMORY LEAK - ACTION INSTANCE COUNT should be Zero, but == [" << BaseAction::instanceCount << "]"<< endl;
	}
	assert(BaseAction::instanceCount == 0);
}


void doExit(Action* pAction) {
	cout << "EXIT 1 -- ACTION INSTANCE COUNT == [" << BaseAction::instanceCount<< "]" << endl;
	if (BaseAction::instanceCount > 0) {
		delete pAction;
	}
	cout << "EXIT 2 -- ACTION INSTANCE COUNT == [" << BaseAction::instanceCount << "]" << endl;
	exit(0);
}
