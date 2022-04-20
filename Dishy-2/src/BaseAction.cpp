/*
 * Action.cpp
 *
 *  Created on: 18 Apr 2022
 *      Author: colin
 */
//#define DEBUG


#include "BaseAction.h"

#include "environment.h"
#include "ActionEvent.h"

#include <iostream>
#include <sstream>
using namespace std;
/*
Action::Action() {
	// TODO Auto-generated constructor stub

}
*/
int BaseAction::instanceCount = 0;

BaseAction::BaseAction(ActionEvent* event) {
	instanceCount++;
	_isValid = (event == NULL)?false:true;
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
	_isValid = other._isValid;

}

BaseAction::~BaseAction() {
	instanceCount--;
#ifdef DEBUG
	cout << "   # ACTION destructor on (" << this << "::[" << instanceCount << "]), id:" << _event->getId() << endl;
#endif
}

string BaseAction::toString() const {
	stringstream ss ;
	if (_isValid) {
		ss << "Action[event id:" << (int)_event->getId() << "]";
	} else {
		ss << "Action[event id:null, isValid:"  << _isValid << "]";
	}
	return ss.str();
}

bool BaseAction::isValid() const {
	return _isValid;
}

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


/*
FlashLedAction::FlashLedAction() {

}

*/
