/*
 * main.cpp
 *
 *  Created on: Nov 27, 2015
 *      Author: jan
 */
#include "environment.h"


#ifdef MCU_ENV
//#include ""
#endif

#include "main.h"
//#include "stdio.h"

#include "ToggleLedAction.h"

// enable NDEBUG to disable assert()
#define NDEBUG
#include <assert.h>     /* assert */

//#include "Arduino.h"

void doExit();
void assertNoMemoryLeak();
void dispatchEvent(unique_ptr<InputEvent> &pInputEvent);
bool isValidInput(unique_ptr<InputEvent> &pInputEvent);


unique_ptr<InputSource> inputSrc;

void setup()
{
#ifdef MCU_ENV
	// open the serial port:
	Serial.begin(9600);
	pinMode(LED_BUILTIN, OUTPUT);
	Serial.println("Welcome!");
#endif

	inputSrc = make_unique<KeyboardInputSource>();

}

//============================

/*
 * TODO 1 - add actions to array in ActionGroup
 * TODO 2 - learn about smart pointers
 * TODO 3 - convert to smart pointers
 * TODO 4 - add local Git repo's to remote.
 * TODO Go to NFT's
 */

void loop()
{

	{ // memory tracking block
		char input = '\0';

		input = inputSrc->readInput();

		unique_ptr<InputEvent> pInputEvent = getEventForInput(input);

		if (isValidInput(pInputEvent))
		{
			dispatchEvent(pInputEvent);
		}
	}

	assertNoMemoryLeak();

}

bool isValidInput(unique_ptr<InputEvent> &pInputEvent)
{
//	LOG_DEBUG_LN("=======>%s<========\n", pInputEvent->toString().c_str());
	bool result = true;
	if (pInputEvent->getId() == InputEvent::invalidEvent && pInputEvent->getData() == 'x')
	{
		//pInputEvent.reset();
		doExit();
	}
	else if (pInputEvent->getId() == InputEvent::invalidEvent)
	{
		LOG_DEBUG_LN("Invalid input <%c>\n", pInputEvent->getData() );
		result = false;
	}
	return result;
}

void dispatchEvent(unique_ptr<InputEvent> &pInputEvent)
{
	Action *pAction = NULL;

	pAction = getAction(pInputEvent);

	LOG_DEBUG_LN("------------------\n");
	int actionResult = pAction->run();
	LOG_DEBUG_LN( "Action result: %i \n", actionResult);
	delete pAction;
	LOG_DEBUG_LN("------------------\n");
}

// caller must free Action memory.
Action* getAction(unique_ptr<InputEvent> &event)
{

	unique_ptr<Action> singleAction = NULL;
	ActionGroup *newActionGrp = NULL;
	string group1Desc = "Group1";
	string group2Desc = "Group2";
	string group3Desc = "Group3";
	string testDesc = "TEST_STR";
	int result = 0;

	switch (event->getId()) {
	case InputEvent::btn1pressEvent:
		singleAction = unique_ptr<Action>(new ToggleLedAction(1, event));
		newActionGrp = new ActionGroup(100, 10, singleAction, "Group1");
		break;
	case InputEvent::btn2pressEvent:
//		singleAction = new NullAction(2,event);
		singleAction = unique_ptr<Action>(new DisplayAction(-2, 2, event));
		newActionGrp = new ActionGroup(200, 20, singleAction, group2Desc);
		break;
	case InputEvent::btn3pressEvent:
//		singleAction = new NullAction(3,event);
		singleAction = unique_ptr<Action>(new DisplayAction(-3, 3, event));
		newActionGrp = new ActionGroup(300, 30, singleAction, group2Desc);
		break;
	case InputEvent::btn4pressEvent:
		singleAction = unique_ptr<Action>(new NullAction(1, event));
		newActionGrp = new ActionGroup(400, 40, singleAction, group2Desc);
		break;
	default:
		singleAction = unique_ptr<Action>(new NullAction(2, event));
		newActionGrp = new ActionGroup(-10, -1, singleAction, group2Desc);
		break;
	}
	singleAction.reset();
	return newActionGrp;
}

// caller must free InputEvent memory.
unique_ptr<InputEvent> getEventForInput(char input)
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
	return make_unique<InputEvent>(eventType, input);
}

void assertNoMemoryLeak()
{
	if (ActionGroup::instanceCount > 0)
	{
		LOG_DEBUG_LN( "**** MEMORY LEAK - ActionGroup instance count != 0, Actual:[%i]\n" ,ActionGroup::instanceCount );
	}
	if (BaseAction::instanceCount > 0)
	{
		LOG_DEBUG_LN( "**** MEMORY LEAK - BaseAction instance count != 0, Actual:[%i]\n" ,BaseAction::instanceCount );
	}

	if (InputEvent::instanceCount > 0)
	{
		LOG_DEBUG_LN( "**** MEMORY LEAK - InputEvent instance count != 0, Actual:[%i]\n" ,InputEvent::instanceCount );
	}
	assert(BaseAction::instanceCount == 0);
}

void doExit()
{
	LOG_DEBUG_LN("all done!\n");
	assertNoMemoryLeak();
	exit(0);
}

