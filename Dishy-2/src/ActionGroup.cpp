/*
 * ActionGroup.cpp
 *
 *  Created on: 19 Apr 2022
 *      Author: colin
 */
#define DEBUG
// define NDEBUG to turn off assert()
//#define NDEBUG
#include <assert.h>

#include <iostream>
using namespace std;
#include <sstream>

#include "ActionGroup.h"

ActionGroup::ActionGroup(int maxActions, string desc) {
	assert(maxActions > 0);
	_pTheAction = NULL;
	_maxActions = maxActions;
	_description = desc;
#ifdef DEBUG
	cout << "   # DEF ActionGroup constructor (" << this << ")" << endl;
#endif
}

// this object will delete the action object on destruction
ActionGroup::ActionGroup(int maxActions, Action* action, string desc) {
	assert(maxActions > 0);
	assert(action != NULL);

	// FIXME - use copy c'tor for Action - but do we need to know the type of the Action to call it s c'tor?????
	_pTheAction = action->clone();
	_maxActions = maxActions;
	_description = desc;
#ifdef DEBUG
	cout << "   # ActionGroup A constructor (" << this << ")" << endl;
#endif
}

ActionGroup::ActionGroup(const ActionGroup &other) {
	assert(&other != NULL);

	// FIXME : we are copying another object pointer here that ActionGroup is responsible for
	// so it will get deleted twice!!
//	_pTheAction = other._pTheAction;
	// do all class in tree (NullAction->BaseAction->Action) all define the BigTHree???? - do smaller example to prove it.

	// FIXME - use copy c'tor for Action - but do we need to know the type of the Action to call it s c'tor?????
	_pTheAction = other._pTheAction->clone();
	_maxActions = other._maxActions;
	_description = other._description;
/*
#ifdef DEBUG
	cout << "   # ActionGroup  COPY constructor, from (" << &other << "), to ("
			<< this << ")" << endl;
#endif
*/

}

// #FIXME - need operator= too.



ActionGroup::~ActionGroup() {
	delete _pTheAction;
	_pTheAction = NULL;
#ifdef DEBUG
	cout << "   # ActionGroup destructor on (" << this << ")" << endl;
#endif
}

Action* ActionGroup::clone() const {
	// #FIXME need Clone function
//	assert(false);
	return new ActionGroup(*this);
//	return new DisplayAction(*this);
}

int ActionGroup::getMaxActions() const {
	return _maxActions;
}

// this object will delete the action object on destruction
void ActionGroup::addAction(Action *action) {
	assert(action != NULL);
	_pTheAction = action;

	// TODO add actions to collection (array) of Action Ptrs AND FREE

}

string ActionGroup::toString() const {
	stringstream ss;
	ss << "ActionGroup[" << _description << "][" << _maxActions << "]";
	return ss.str();
}

int ActionGroup::run() {
//	cout << "run " << toString() << " " << _pTheAction->toString() << endl;
	// TODO debug
	cout << "run " << toString() << " " << _pTheAction << endl;
	return 0;
}


void ActionGroup::setDescription(const string desc) {
	_description = desc;
}

string ActionGroup::getDescription() const {
	return _description;
}

