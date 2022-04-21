/*
 * Action.cpp
 *
 *  Created on: 18 Apr 2022
 *      Author: colin
 */
//#define DEBUG

#include <iostream>
#include <sstream>

// define NDEBUG to turn off assert()
//#define NDEBUG
#include <assert.h>

#include "BaseAction.h"

#include "environment.h"

#include "InputEvent.h"
using namespace std;

int BaseAction::instanceCount = 0;

BaseAction::BaseAction(InputEvent* event) {
	// ensure we always get a non-NULL event ptr.
	assert(event != NULL);
	instanceCount++;
	_event = event;

#ifdef DEBUG
	cout << "   # ACTION contructor (" << this << "), id:" << (int)_event->getId() << endl;
#endif
}

BaseAction::BaseAction(const BaseAction& other) {
	instanceCount++;
#ifdef DEBUG
	cout << "   # ACTION COPY contructor, from (" << &other << "), to (" << this << "), id:" << (int)other._event->getId() << endl;
#endif
	_event = other._event;

}

BaseAction::~BaseAction() {
	instanceCount--;
#ifdef DEBUG
	cout << "   # ACTION destructor on (" << this << "::[" << instanceCount << "]), id:" << _event->getId() << endl;
#endif
}

InputEvent* BaseAction::getEvent() {
	return _event;
}

string BaseAction::toString() const {
	stringstream ss ;
	ss << "BaseAction[event id:" << (int)_event->getId() << "]";
	return ss.str();
}


/*
#if defined LOCAL_ENV
int BaseAction::run() {
	cout << "run Action for " << (_isValid?_event->toString():"INVALID") << endl;

	if (! _isValid) {
		// invalid
		return -1;
	}

	// do run()
	return 0;
}

#elif defined MCU_ENV

int BaseAction::run() {
	cout << "run **MCU** Action for " << _event->toString() << endl;

	return 0;
}


#elif defined TEST_ENV

#endif
*/


