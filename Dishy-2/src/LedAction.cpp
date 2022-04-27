/*
 * LedAction.cpp
 *
 *  Created on: 19 Apr 2022
 *      Author: colin
 */
//#define DEBUG

#include "Arduino.h"
#include "LedAction.h"


/*
static unique_ptr<LedAction> LedAction::build()
{
	unique_ptr<InputEvent> event = make_unique<InputEvent>(100, 'z');
	unique_ptr<LedAction> action = make_unique<LedAction>(1000, event);
	return action;
}
*/

LedAction::LedAction(int id, unique_ptr<InputEvent> &event): BaseAction(id, event)
{
#ifdef DEBUG
	LOG_DEBUG_MEM("      # LedAction constructor [%#lx] id:%i\n", this , event->getId() );
#endif
}

LedAction::LedAction(const LedAction &other) : BaseAction(other)
{
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
	digitalWrite(LED_BUILTIN, newState );
	LOG_DEBUG("[%dl] run LedAction - LED %s\n",millis(), (newState==1?"OFF":"ON") );
	return newState ;
}
