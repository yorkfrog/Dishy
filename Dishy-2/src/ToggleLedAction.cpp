/*
 * ToggleLedAction.cpp
 *
 *  Created on: 19 Apr 2022
 *      Author: colin
 */
//#define DEBUG
#include "Arduino.h"
#include "ToggleLedAction.h"
#include "assert.h"

ToggleLedAction::ToggleLedAction(int id, uint8_t ledPin, unique_ptr<InputEvent> &event) : BaseAction(id, event)
{
	assert(ledPin >= 0);
	_ledPin = ledPin;
	LOG_DEBUG_MEM("      # ToggleLedAction constructor [%#lx] id:%i\n", this , event->getId() );
}

ToggleLedAction::ToggleLedAction(const ToggleLedAction &other) : BaseAction(other)
{
	_ledPin = other._ledPin;
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
		newState = !digitalRead(_ledPin);
		digitalWrite(_ledPin, newState);
		LOG_DEBUG("[%dl] run ToggleLedAction[%i] - LED %s\n", millis(), _ledPin, (newState == 1 ? "OFF" : "ON"));
	}
	return newState;
}
