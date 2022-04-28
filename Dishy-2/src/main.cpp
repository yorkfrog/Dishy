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

#include "LedAction.h"
#include "ToggleLedAction.h"
#include "SimpleButtonInputSource.h"

// enable NDEBUG to disable assert()
#define NDEBUG
#include <assert.h>     /* assert */

//#include "Arduino.h"

void doExit();
void assertNoMemoryLeak();
void dispatchEvent(unique_ptr<InputEvent> &pInputEvent);

unique_ptr<InputSource> pInputSrc1;
unique_ptr<InputSource> pInputSrc2;
//unique_ptr<Action> pLedAction1;
//unique_ptr<Action> pLedAction2;

static const uint8_t LED1_PIN = LED_BUILTIN;
static const uint8_t LED2_PIN = D8;

void setup()
{
#ifdef MCU_ENV
	// open the serial port:
	Serial.begin(57600);
	pinMode(LED1_PIN, OUTPUT);
	pinMode(LED2_PIN, OUTPUT);

#endif

#ifdef MCU_ENV
	// add button input src
//	inputSrc = make_unique<KeyboardInputSource>();
	pInputSrc1 = make_unique<SimpleButtonInputSource>(D2, InputEvent::btn1pressEvent, "button1");
	pInputSrc2 = make_unique<SimpleButtonInputSource>(D3, InputEvent::btn2pressEvent, "button2");
	pInputSrc1->setUp();
	pInputSrc2->setUp();

	// TODO can't create up front as take Event as param.
	// perhaps move event to param of run(event) method - then Action becomes longer lived and
	// events becomes transient state of run()
//	pLedAction1 = unique_ptr<Action>(new ToggleLedAction(1, LED1_PIN, event));
//	pLedAction1 = unique_ptr<Action>(new ToggleLedAction(1, LED2_PIN, event));

#else
	pInputSrc1 = make_unique<KeyboardInputSource>("Enter key 1");
	pInputSrc2 = make_unique<KeyboardInputSource>("Enter key 2");
#endif

	delay(500);  // wait for serial to connect;
	Serial.println("Welcome!");

}

//============================

/*
 * - def Button input scr for MCU
 * TODO 1 - add actions to array in ActionGroup
 * TODO 4 - add local Git repo's to remote.
 * TODO Go to NFT's
 */

void loop()
{

	{ // memory tracking block
		uint8_t input1 = pInputSrc1->readInput();
		uint8_t input2 = pInputSrc2->readInput();
		if (pInputSrc1->hasChanged() || pInputSrc2->hasChanged())
		{
			unique_ptr<InputEvent> pInputEvent1 = getEventForInput(input1);
			unique_ptr<InputEvent> pInputEvent2 = getEventForInput(input2);

			if (pInputEvent1->getData() == 'x')
			{
				doExit();
			}

			if ((pInputEvent1->getId() != InputEvent::invalidEvent)
					|| (pInputEvent2->getId() != InputEvent::invalidEvent))
			{
				dispatchEvent(pInputEvent1);
				dispatchEvent(pInputEvent2);
			}
		}
	}
	assertNoMemoryLeak();
}


void dispatchEvent(unique_ptr<InputEvent> &pInputEvent)
{
	unique_ptr<Action> pAction = NULL;

	pAction = getAction(pInputEvent);

	LOG_DEBUG("[%s] ------------------\n", pAction->getDescription().c_str());
	int actionResult = pAction->run();
	LOG_DEBUG("[%s] Action result: %i \n", pAction->getDescription().c_str(), actionResult);
}

// caller must free Action memory.
unique_ptr<Action> getAction(unique_ptr<InputEvent> &event)
{

	unique_ptr<Action> pSingleAction = NULL;
	unique_ptr<Action> pNewActionGrp = NULL;
	string group1Desc = "Group1";
	string group2Desc = "Group2";
	string group3Desc = "Group3";
	string testDesc = "TEST_STR";
	int result = 0;

	switch (event->getId()) {
	case InputEvent::btn1pressEvent:
//		singleAction = unique_ptr<Action>(new LedAction(1, event));
		pSingleAction = unique_ptr<Action>(new ToggleLedAction(1, LED1_PIN, event));
		pNewActionGrp = make_unique<ActionGroup>(100, 10, pSingleAction, group1Desc);
		break;
	case InputEvent::btn2pressEvent:
//		singleAction = new NullAction(2,event);
//		pSingleAction = unique_ptr<Action>(new DisplayAction(-2, 2, event));
		pSingleAction = unique_ptr<Action>(new ToggleLedAction(2, LED2_PIN, event));
		pNewActionGrp = make_unique<ActionGroup>(200, 20, pSingleAction, group2Desc);
		break;
	case InputEvent::btn3pressEvent:
//		singleAction = new NullAction(3,event);
		pSingleAction = unique_ptr<Action>(new DisplayAction(-3, 3, event));
		pNewActionGrp = make_unique<ActionGroup>(300, 30, pSingleAction, group2Desc);
		break;
	case InputEvent::btn4pressEvent:
		pSingleAction = unique_ptr<Action>(new NullAction(1, event));
		pNewActionGrp = make_unique<ActionGroup>(400, 40, pSingleAction, group2Desc);
		break;
	default:
		pSingleAction = unique_ptr<Action>(new NullAction(2, event));
		pNewActionGrp = unique_ptr<Action>(new ActionGroup(-10, 1, pSingleAction, group2Desc));
		break;
	}
	return pNewActionGrp;
}

// caller must free InputEvent memory.
unique_ptr<InputEvent> getEventForInput(uint8_t input)
{
	LOG_DEBUG("E4Input [%i]\n", input);
	int eventType ;
	switch (input) {
	case InputEvent::btn1pressEvent:
		eventType = InputEvent::btn1pressEvent;
		break;
	case InputEvent::btn2pressEvent:
		eventType = InputEvent::btn2pressEvent;
		break;
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
		eventType = InputEvent::invalidEvent;
		break;
	}
	return make_unique<InputEvent>(eventType, input);
}

void assertNoMemoryLeak()
{
	if (ActionGroup::instanceCount > 0)
	{
		LOG_DEBUG_MEM("**** MEMORY LEAK - ActionGroup instance count != 0, Actual:[%i]\n", ActionGroup::instanceCount);
	}
	if (BaseAction::instanceCount > 0)
	{
		LOG_DEBUG_MEM("**** MEMORY LEAK - BaseAction instance count != 0, Actual:[%i]\n", BaseAction::instanceCount);
	}

	if (InputEvent::instanceCount > 0)
	{
		LOG_DEBUG_MEM("**** MEMORY LEAK - InputEvent instance count != 0, Actual:[%i]\n", InputEvent::instanceCount);
	}
	assert(BaseAction::instanceCount == 0);
}

void doExit()
{
	LOG_DEBUG("all done!\n");
	assertNoMemoryLeak();
	exit(0);
}

