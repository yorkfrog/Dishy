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

BaseAction::BaseAction(int id, InputEvent* event) {
	// ensure we always get a non-NULL event ptr.
	assert(event != NULL);
	instanceCount++;
	_id = id;
	_pEvent = new InputEvent(*event);
	_description = "";

#ifdef DEBUG
	cout << "   # ACTION contructor (" << this << "), id:" << (int)_pEvent->getId() << endl;
#endif
}

BaseAction::BaseAction(const BaseAction& other) {
	instanceCount++;
	_id = other._id;
	_pEvent = new InputEvent(*(other._pEvent));
	_description = other._description;

	#ifdef DEBUG
	cout << "   # ACTION COPY contructor, from (" << &other << "), to (" << this << "), id:" << (int)other._pEvent->getId() << endl;
#endif

}

BaseAction& BaseAction::operator=(const BaseAction &other) {
	cout << "# BaseAction Oper= from [" << &other << "] to [" << this << "]" << endl;
	if (this != &other) { // protect against invalid self-assignment
		cout << "#### 2" << endl;
		// 1: allocate new memory and copy the elements
		InputEvent *pNewEvent = new InputEvent(*(other._pEvent));

		// 2: deallocate old memory
		delete _pEvent;

		// 3: assign the new memory to the object
		_id = other._id;
		_pEvent = pNewEvent;
		_description = other._description;
	}
	// by convention, always return *this
	return *this;
}

BaseAction::~BaseAction() {
	instanceCount--;
	delete _pEvent;
	_pEvent = NULL;
#ifdef DEBUG
	cout << "   # ACTION destructor on (" << this << "::[" << instanceCount << "]), id:" << _pEvent->getId() << endl;
#endif
}

int BaseAction::getId() const {
	return _id;
}

void BaseAction::setDescription(const string desc) {
	_description = desc;
}

string BaseAction::getDescription() const {
	return _description;
}

InputEvent* BaseAction::getEvent() const {
	return _pEvent;
}

string BaseAction::toString() const {
	stringstream ss ;
	ss << "BaseAction[event id:" << (int)_pEvent->getId() << "]";
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

	return 0;ActionGroup
}


#elif defined TEST_ENV

#endif
*/


