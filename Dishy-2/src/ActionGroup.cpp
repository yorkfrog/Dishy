/*
 * ActionGroup.cpp
 *
 *  Created on: 19 Apr 2022
 *      Author: colin
 */
//#define DEBUG

// define NDEBUG to turn off assert()
//#define NDEBUG
#include <assert.h>

#include <iostream>
using namespace std;
#include <sstream>

#include "ActionGroup.h"

int ActionGroup::instanceCount = 0;

ActionGroup::ActionGroup(int maxActions, string desc)
{
	instanceCount++;
	assert(maxActions > 0);
	_pTheAction = NULL;
	_maxActions = maxActions;
	_description = desc;

#ifdef DEBUG
	cout << "   # DEF ActionGroup constructor (" << this << ")" << endl;
#endif
}

// this object will delete the action object on destruction
ActionGroup::ActionGroup(int maxActions, Action *action, string desc)
{
	instanceCount++;
	assert(maxActions > 0);
	assert(action != NULL);

	_pTheAction = action->clone();
	_maxActions = maxActions;
	_description = desc;
#ifdef DEBUG
	cout << "   # ActionGroup A constructor (" << this << ")" << endl;
#endif
}

ActionGroup::ActionGroup(const ActionGroup &other)
{
	assert(&other != NULL);
	instanceCount++;

	_pTheAction = other._pTheAction->clone();
	_maxActions = other._maxActions;
	_description = other._description;
#ifdef DEBUG
	cout << "   # ActionGroup  COPY constructor, from (" << &other << "), to (" << this << ")" << endl;
#endif
}

ActionGroup& ActionGroup::operator=(const ActionGroup &other) {

	cout << "# BaseAction Oper= from [" << &other << "] to [" << this << "]" << endl;
	if (this != &other) { // protect against invalid self-assignment
		// 1: allocate new memory and copy the elements
		Action *pNewAction = other._pTheAction->clone();

		// 2: deallocate old memory
		delete _pTheAction;

		// 3: assign the new memory to the object
		_pTheAction = pNewAction;
		_maxActions = other._maxActions;
		_description = other._description;
	}
	// by convention, always return *this

	return *this;
}


ActionGroup::~ActionGroup()
{
	delete _pTheAction;
	_pTheAction = NULL;
#ifdef DEBUG
	cout << "   # ActionGroup destructor on (" << this << ")" << endl;
#endif
	instanceCount--;
}

// the caller is responsible for free the memory allocated to this cloned object.
Action* ActionGroup::clone() const
{
	return new ActionGroup(*this);
}

int ActionGroup::getMaxActions() const
{
	return _maxActions;
}

// this object will delete the action object on destruction
void ActionGroup::addAction(Action *action)
{
	assert(action != NULL);
	_pTheAction = action;

	// TODO add actions to collection (array) of Action Ptrs AND FREE

}

string ActionGroup::toString() const
{
	stringstream ss;
	ss << "ActionGroup[" << _description << "][" << _maxActions << "]";
	return ss.str();
}

int ActionGroup::run()
{
	cout << "run " << toString() << " " << _pTheAction << endl;
	return _pTheAction->run();
}

void ActionGroup::setDescription(const string desc)
{
	_description = desc;
}

string ActionGroup::getDescription() const
{
	return _description;
}

