/*
 *  Created on: 19 Apr 2022
 *      Author: colin
 */
//#define DEBUG

#include "environment.h"

#include <sstream>
using namespace std;

#include "DisplayAction.h"

DisplayAction::DisplayAction(int id, int buttonNum, unique_ptr<InputEvent> &event) : BaseAction(id, event)

{
#ifdef DEBUG
	LOG_DEBUG_LN("      # DisplayAction constructor [%#lx] id:%i\n", this , event->getId() );
#endif
	_buttonNumber = buttonNum;
}

DisplayAction::DisplayAction(const DisplayAction &other) : BaseAction(other)
{
#ifdef DEBUG
	LOG_DEBUG_LN("      # DisplayAction COPY constructor, from [%#lx] to [%#lx]\n", &other , this  );
#endif
	_buttonNumber = other._buttonNumber;

}

DisplayAction::~DisplayAction()
{
#ifdef DEBUG
	LOG_DEBUG_LN("      # DisplayAction destructor on [%#lx]\n" , this);
#endif
}

// the caller is responsible for free the memory allocated to this cloned object.
Action* DisplayAction::clone() const
{
	return new DisplayAction(*this);
}

int DisplayAction::run()
{
#ifndef MCU_ENV
	LOG_DEBUG_LN("run DisplayAction::%s\n" , this->toString());
#endif

	return 0;
}

int DisplayAction::getButtonNumber() const
{
	return _buttonNumber;
}

string DisplayAction::toString() const
{
	stringstream ss;
	ss << BaseAction::toString() << "[btn #:" << _buttonNumber << "]";
	return ss.str();
}

