/*
 * Action.cpp
 *
 *  Created on: 18 Apr 2022
 *      Author: colin
 */
//#define DEBUG


#include "environment.h"
#include "Action.h"
#include "ActionEvent.h"

#include <iostream>
#include <sstream>
using namespace std;
/*
Action::Action() {
	// TODO Auto-generated constructor stub

}
*/
int Action::instanceCount = 0;

Action::Action(ActionEvent* event): _event(event) {
	instanceCount++;
#ifdef DEBUG
	cout << "   # ACTION contructor (" << this << "), id:" << (int)_event->getId() << endl;
#endif
}

Action::Action(const Action& other) {
	instanceCount++;
#ifdef DEBUG
	cout << "   # ACTION COPY contructor, from (" << &other << "), to (" << this << "), id:" << (int)other._event->getId() << endl;
#endif
	_event = other._event;


}

Action::~Action() {
	instanceCount--;
#ifdef DEBUG
	cout << "   # ACTION destructor on (" << this << "::[" << instanceCount << "]), id:" << _event->getId() << endl;
#endif
}

string Action::toString() const {
	stringstream ss ;
	ss << "Action[event id:" << (int)_event->getId() << "]";
	return ss.str();
}


#if defined LOCAL_ENV

int Action::run() {
	cout << "run Action for " << _event->toString() << endl;

	return 0;
}

#elif defined MCU_ENV

int Action::run() {
	cout << "run **MCU** Action for " << _event->toString() << endl;

	return 0;
}


#elif defined TEST_ENV

#endif


/*
FlashLedAction::FlashLedAction() {

}

*/
