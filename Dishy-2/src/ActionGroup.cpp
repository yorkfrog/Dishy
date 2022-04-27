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

#define DEBUG

#include "environment.h"

#include <sstream>
using namespace std;

#include "ActionGroup.h"

int ActionGroup::instanceCount = 0;

ActionGroup::ActionGroup(int id, int maxActions, string desc)
{
	instanceCount++;
	assert(maxActions > 0);
	_id = id;
	_pTheAction = NULL;
	_maxActions = maxActions;
	_description = desc;

#ifdef DEBUG
	LOG_DEBUG_MEM("  # DEF ActionGroup constructor (%#lx)\n", this );
#endif
}

// this object will delete the action object on destruction
ActionGroup::ActionGroup(int id, int maxActions, unique_ptr<Action> &action, string desc)
{
	instanceCount++;
	assert(maxActions > 0);
	assert(action != NULL);

	_id = id;

	_pTheAction = shared_ptr<Action>((action.get())->clone());
	_maxActions = maxActions;
	_description = desc;
#ifdef DEBUG
	LOG_DEBUG_MEM("  # ActionGroup constructor (%#lx)\n", this );
#endif
}

ActionGroup::ActionGroup(const ActionGroup &other)
{
	assert(&other != NULL);
	instanceCount++;

	_id = other._id;
	_pTheAction = shared_ptr<Action>((other._pTheAction.get())->clone());
	_maxActions = other._maxActions;
	_description = other._description;
#ifdef DEBUG
	LOG_DEBUG_MEM("  # ActionGroup  COPY constructor, from (%#lx) to (%#lx)\n", &other, this );
#endif
}

ActionGroup& ActionGroup::operator=(const ActionGroup &other) {

	LOG_DEBUG_MEM("  # ActionGroup Oper= from [%#lx] to [%#lx]\n", &other, this);
	if (this != &other) { // protect against invalid self-assignment
		// 1: allocate new memory and copy the elements
		shared_ptr<Action> pNewAction = shared_ptr<Action>((other._pTheAction.get())->clone());

		// 2: deallocate old memory
		_pTheAction.reset();

		// 3: assign the new memory to the object
		_pTheAction = pNewAction;
		_maxActions = other._maxActions;
		_id = other._id;
		_description = other._description;
	}
	// by convention, always return *this

	return *this;
}


ActionGroup::~ActionGroup()
{
	_pTheAction.reset();
#ifdef DEBUG
	LOG_DEBUG_MEM("  # ActionGroup destructor on (%#lx)\n", this);
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

int ActionGroup::getId() const
{
	return _id;
}

// this object will delete the action object on destruction
void ActionGroup::addAction(unique_ptr<Action> &action)
{
	_pTheAction = shared_ptr<Action>((action.get())->clone());

	// TODO add actions to collection (array) of Action Ptrs AND FREE

}

string ActionGroup::toString() const
{
	stringstream ss;
	ss << "ActionGroup[" << _id << "][" << _description << "][" << _maxActions << "]";
	return ss.str();
}

int ActionGroup::run()
{
	LOG_DEBUG_MEM("run [%s %#lx]\n", toString().c_str(), _pTheAction );
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

