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


void doExit();
void assertNoMemoryLeak();
void dispatchEvent(InputEvent *pInputEvent);
bool isValidInput(InputEvent *pInputEvent);

void setup()
{

	pinMode(LED_BUILTIN, OUTPUT);
}


============================

		/*
		 * 1 - add actions to array in ActionGroup
		 * 2 - learn about smart pointers
		 * 3 - convert to smart pointers
		 * Go to NFT's
		 */


void loop()
{

	{ // memory tracking block
		char input = '\0';
		input = readInput();

		InputEvent* pInputEvent = getEventForInput(input);

		if (isValidInput(pInputEvent))
		{
			dispatchEvent(pInputEvent);
		}
		delete pInputEvent;
	}

	assertNoMemoryLeak();

}

bool isValidInput(InputEvent *pInputEvent)
{
	bool result = true;
	if (pInputEvent->getId() == InputEvent::invalidEvent && pInputEvent->getData() == 'x')
	{
		delete pInputEvent;
		doExit();
	}
	else if (pInputEvent->getId() == InputEvent::invalidEvent)
	{
		cout << "Invalid input " << pInputEvent->getData() << endl;
		result = false;
	}
	return result;
}

void dispatchEvent(InputEvent *pInputEvent)
{
	Action *pAction = NULL;

	pAction = getAction(*pInputEvent);

	cout << "------------------" << endl;
	int actionResult = pAction->run();
	delete pAction;
	cout << "Action result:" << actionResult << endl;
	cout << "------------------" << endl;
}

// caller must free Action memory.
Action* getAction(InputEvent &event)
{

	Action *singleAction = NULL;
	ActionGroup *newActionGrp = NULL;
	string group1Desc = "Group1";
	string group2Desc = "Group2";
	string group3Desc = "Group3";
	string testDesc = "TEST_STR";
	int result = 0;

	switch (event.getId()) {
	case InputEvent::btn1pressEvent:
		singleAction = new DisplayAction(-1, 1, &event);
		newActionGrp = new ActionGroup(100, 10, singleAction, "Group1");
		break;
	case InputEvent::btn2pressEvent:
		singleAction = new DisplayAction(-2, 2, &event);
		newActionGrp = new ActionGroup(200, 20, singleAction, group2Desc);
		break;
	case InputEvent::btn3pressEvent:
		singleAction = new DisplayAction(-3, 3, &event);
		newActionGrp = new ActionGroup(300, 30, singleAction, group2Desc);
		break;
	case InputEvent::btn4pressEvent:
		singleAction = new NullAction(1,&event);
		newActionGrp = new ActionGroup(400, 40, singleAction, group2Desc);
		break;
	default:
		singleAction = new NullAction(2,&event);
		newActionGrp = new ActionGroup(-10, -1, singleAction, group2Desc);
		cout << "NEW ACTION:" << newActionGrp->toString();
		break;
	}
	delete singleAction;
	return newActionGrp;
}

// caller must free InputEvent memory.
InputEvent* getEventForInput(char input)
{
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
	return new InputEvent(eventType, input);
}

void assertNoMemoryLeak()
{
	if (ActionGroup::instanceCount > 0)
	{
		cout << "**** MEMORY LEAK - ActionGroup instance count != 0, Actual:[" << ActionGroup::instanceCount << "]" << endl;
	}
	if (BaseAction::instanceCount > 0)
	{
		cout << "**** MEMORY LEAK - BaseAction instance count != 0, Actual:[" << BaseAction::instanceCount << "]" << endl;
	}

	if (InputEvent::instanceCount > 0)
	{
		cout << "**** MEMORY LEAK - InputEvent instance count != 0, Actual:[" << InputEvent::instanceCount << "]" << endl;
	}
	assert(BaseAction::instanceCount == 0);
}

void doExit()
{
	cout << "all done!" << endl;
	assertNoMemoryLeak();
	exit(0);
}

