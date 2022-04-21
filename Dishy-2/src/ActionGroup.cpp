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

ActionGroup::ActionGroup(int maxActions, string* desc) {
	assert(maxActions > 0);
	_pTheAction = NULL;
	_maxActions = maxActions;
	_pDescription = desc;
#ifdef DEBUG
	cout << "   # DEF ActionGroup contructor (" << this << ")" << endl;
#endif
}

ActionGroup::ActionGroup(int maxActions, Action* action, string* desc) {
	assert(maxActions > 0);
	assert(action != NULL);

	_pTheAction = action;
	_maxActions = maxActions;
	_pDescription = desc;
#ifdef DEBUG
	cout << "   # ActionGroup A contructor (" << this << ")" << endl;
#endif
}

ActionGroup::ActionGroup(const ActionGroup &other) {
	assert(&other != NULL);

	_pTheAction = other._pTheAction;
	_maxActions = other._maxActions;
	_pDescription = other._pDescription;
#ifdef DEBUG
	cout << "   # ActionGroup  COPY constructor, from (" << &other << "), to ("
			<< this << ")" << endl;
#endif

}

ActionGroup::~ActionGroup() {
#ifdef DEBUG
	cout << "   # ActionGroup destructor on (" << this << ")" << endl;
#endif
}

int ActionGroup::getMaxActions() const {
	return _maxActions;
}

void ActionGroup::addAction(Action *action) {
	assert(action != NULL);
	_pTheAction = action;

	// TODO add actions to collection (array) of Action Ptrs AND FREE

}

string ActionGroup::toString() const {
	stringstream ss;
	ss << "ActionGroup[" << _pDescription << "][" << _maxActions << "]";
	return ss.str();
}

int ActionGroup::run() {
	cout << "run " << toString() << " " << _pTheAction->toString() << endl;
	return 0;
}


void ActionGroup::setDescription(const string* desc) {
	_pDescription = desc;
}

string* ActionGroup::getDescription() const {
	return _pDescription;
}

