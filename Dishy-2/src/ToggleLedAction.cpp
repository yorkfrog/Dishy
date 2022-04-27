/*
 * ToggleLedAction.cpp
 *
 *  Created on: 19 Apr 2022
 *      Author: colin
 */
//#define DEBUG
#include "Arduino.h"
#include "ToggleLedAction.h"

ToggleLedAction::ToggleLedAction(int id, unique_ptr<InputEvent> &event) : BaseAction(id, event)
{
	LOG_DEBUG_MEM("      # ToggleLedAction constructor [%#lx] id:%i\n", this , event->getId() );
}

ToggleLedAction::ToggleLedAction(const ToggleLedAction &other) : BaseAction(other)
{
	LOG_DEBUG_MEM("      # ToggleLedAction COPY constructor, from [%#lx] to [%#lx]\n", &other , this );
}

ToggleLedAction::~ToggleLedAction()
{
	LOG_DEBUG_MEM("      # ToggleLedAction destructor on [%#lx]\n" , this);
}

Action* ToggleLedAction::clone() const
{
	return new ToggleLedAction(*this);
}

/*
 * Toggle the LED state each time this function is called;
 * LOW (0) = ON
 * HIGH (1) = OFF
 */
int ToggleLedAction::run()
{
	LOG_DEBUG("run ToggleLedAction::%s, d[%i]\n", this->toString().c_str(), this->getEvent()->getData());
	int newState = 0;
	// only trigger when button pressed (not released)
	if (this->getEvent()->getData() != 0)
	{
		newState = !digitalRead(LED_BUILTIN);
		digitalWrite(LED_BUILTIN, newState);
		LOG_DEBUG("[%dl] run ToggleLedAction - LED %s\n", millis(), (newState == 1 ? "OFF" : "ON"));
	}
	return newState;
}
