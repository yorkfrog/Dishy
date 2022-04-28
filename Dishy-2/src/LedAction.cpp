/*
 * LedAction.cpp
 *
 *  Created on: 19 Apr 2022
 *      Author: colin
 */
//#define DEBUG

#include "Arduino.h"
#include "LedAction.h"
#include <assert.h>

/*
static unique_ptr<LedAction> LedAction::build()
{
	unique_ptr<InputEvent> event = make_unique<InputEvent>(100, 'z');
	unique_ptr<LedAction> action = make_unique<LedAction>(1000, event);
	return action;
}
*/

LedAction::LedAction(int id, uint8_t ledPin, unique_ptr<InputEvent> &event) : BaseAction(id, event)
{
	assert(ledPin >= 0);
	_ledPin = ledPin;
#ifdef DEBUG
	LOG_DEBUG_MEM("      # LedAction constructor [%#lx] id:%i\n", this , event->getId() );
#endif
}

LedAction::LedAction(const LedAction &other) : BaseAction(other)
{
	_ledPin = other._ledPin;
#ifdef DEBUG
	LOG_DEBUG_MEM("      # LedAction COPY constructor, from [%#lx] to [%#lx]\n", &other , this  );
#endif

}

LedAction::~LedAction()
{
#ifdef DEBUG
	LOG_DEBUG_MEM("      # LedAction destructor on [%#lx]\n" , this);
#endif
}

Action* LedAction::clone() const
{
	return new LedAction(*this);
}

/*
 * Set the LED to the value in the InputEvent Data element.
 * LOW (0) = ON
 * HIGH (1) = OFF
 */
int LedAction::run()
{
	LOG_DEBUG("run LedAction::%s, d[%i]\n", this->toString().c_str(), this->getEvent()->getData() );
	int newState = this->getEvent()->getData();
	digitalWrite(_ledPin, newState );
	LOG_DEBUG("[%dl] run LedAction[%i] - LED %s\n",millis(), _ledPin, (newState==1?"OFF":"ON") );
	return newState ;
}
