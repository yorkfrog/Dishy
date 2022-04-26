/*
 * ToggleLedAction.cpp
 *
 *  Created on: 19 Apr 2022
 *      Author: colin
 */
//#define DEBUG
//#include <iostream>
//using namespace std;

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
	cout << "   # ToggleLedAction contructor (" << this << "), id:" << event->getId() << endl;
#endif
}

ToggleLedAction::ToggleLedAction(const ToggleLedAction &other) : BaseAction(other)
{
#ifdef DEBUG
	cout << "   # ToggleLedAction  COPY contructor, from (" << &other << "), to (" << this << ")" << endl;
#endif

}

ToggleLedAction::~ToggleLedAction()
{
#ifdef DEBUG
	cout << "   # ToggleLedAction destructor on (" << this << ")" << endl;
#endif
}

Action* ToggleLedAction::clone() const
{
	return new ToggleLedAction(*this);
}

int ToggleLedAction::run()
{
	LOG_DEBUG("run ToggleLedAction" << "::" << this->toString() << endl);
	int newState = !digitalRead(LED_BUILTIN);
	digitalWrite(LED_BUILTIN, newState );
	return newState ;
}
