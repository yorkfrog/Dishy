/*
 *  Created on: 19 Apr 2022
 *      Author: colin
 */
//#define DEBUG

#include "environment.h"

#ifndef MCU_ENV
#include <iostream>
#endif

#include <sstream>
using namespace std;

#include "DisplayAction.h"

DisplayAction::DisplayAction(int id, int buttonNum, unique_ptr<InputEvent> &event) : BaseAction(id, event)

{
#ifdef DEBUG
	cout << "   # DisplayAction contructor (" << this << "), id:"
			<< event->getId() << endl;
#endif
	_buttonNumber = buttonNum;
}

DisplayAction::DisplayAction(const DisplayAction &other) : BaseAction(other)
{
#ifdef DEBUG
	cout << "   # DisplayAction  COPY contructor, from (" << &other
			<< "), to (" << this << ")" << endl;
#endif
	_buttonNumber = other._buttonNumber;

}

DisplayAction::~DisplayAction()
{
#ifdef DEBUG
	cout << "   # DisplayAction destructor on (" << this << ")" << endl;
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
	cout << "run DisplayAction::" << this->toString() << endl;
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

