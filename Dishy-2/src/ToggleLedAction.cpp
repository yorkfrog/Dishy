/*
 * ToggleLedAction.cpp
 *
 *  Created on: 19 Apr 2022
 *      Author: colin
 */
//#define DEBUG

#include "Arduino.h"
#include "ToggleLedAction.h"

/*
static unique_ptr<ToggleLedAction> ToggleLedAction::build()
{
	unique_ptr<InputEvent> event = make_unique<InputEvent>(100, 'z');
	unique_ptr<ToggleLedAction> action = make_unique<ToggleLedAction>(1000, event);
	return action;
}
*/

ToggleLedAction::ToggleLedAction(int id, unique_ptr<InputEvent> &event): BaseAction(id, event)
{
#ifdef DEBUG
	LOG_DEBUG_LN("      # ToggleLedAction constructor [%#lx] id:%i\n", this , event->getId() );
#endif
}

ToggleLedAction::ToggleLedAction(const ToggleLedAction &other) : BaseAction(other)
{
#ifdef DEBUG
	LOG_DEBUG_LN("      # ToggleLedAction COPY constructor, from [%#lx] to [%#lx]\n", &other , this  );
#endif

}

ToggleLedAction::~ToggleLedAction()
{
#ifdef DEBUG
	LOG_DEBUG_LN("      # ToggleLedAction destructor on [%#lx]\n" , this);
#endif
}

Action* ToggleLedAction::clone() const
{
	return new ToggleLedAction(*this);
}

int ToggleLedAction::run()
{
	LOG_DEBUG_LN("run ToggleLedAction...\n" );
//	LOG_DEBUG_LN("run ToggleLedAction::%s\n", this->toString() );
	int newState = 0;
	newState = !digitalRead(LED_BUILTIN);
	digitalWrite(LED_BUILTIN, newState );
	return newState ;
}
