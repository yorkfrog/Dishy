/*
 * Action.cpp
 *
 *  Created on: 18 Apr 2022
 *      Author: colin
 */
//#define DEBUG

// define NDEBUG to turn off assert()
//#define NDEBUG

#include "environment.h"
#include <assert.h>

#include "BaseAction.h"


#include "InputEvent.h"

#include <sstream>
using namespace std;


int BaseAction::instanceCount = 0;

BaseAction::BaseAction(int id, unique_ptr<InputEvent> &event) {
	// ensure we always get a non-NULL event ptr.
	assert(event != NULL);
	instanceCount++;
	_id = id;
	_pEvent = make_shared<InputEvent>(*event.get());
	_description = "";

#ifdef DEBUG
	LOG_DEBUG_LN("    # ACTION constructor [%#lx] id:%i\n", this , (int)_pEvent->getId() );
#endif
}

BaseAction::BaseAction(const BaseAction& other) {
	instanceCount++;
	_id = other._id;
	_pEvent = make_shared<InputEvent>(*(other._pEvent.get()) ) ;
//	_pEvent = new InputEvent(*(other._pEvent.get()));
	_description = other._description;

#ifdef DEBUG
	LOG_DEBUG_LN("    # ACTION COPY constructor, from [%#lx] to [%#lx], id:%i\n", &other , this , (int)other._pEvent->getId() );
#endif

}



BaseAction& BaseAction::operator=(const BaseAction &other) {
	LOG_DEBUG_LN("    # BaseAction Oper= from [%#lx] to [%#lx]\n", &other , this);
	if (this != &other) { // protect against invalid self-assignment
		// 1: allocate new memory and copy the elements
		shared_ptr<InputEvent> pNewEvent = make_shared<InputEvent>(*(other._pEvent.get()) ) ;

		// 2: deallocate old memory
		_pEvent.reset();

		// 3: assign the new memory to the object
		_pEvent = pNewEvent;
		_id = other._id;
		_description = other._description;
	}
	// by convention, always return *this
	return *this;
}



BaseAction::~BaseAction() {
	instanceCount--;
	_pEvent.reset();
//	delete _pEvent;
//	_pEvent = NULL;
#ifdef DEBUG
	LOG_DEBUG_LN("    # ACTION destructor on [%#lx], id:%i\n" , this , instanceCount);
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

shared_ptr<InputEvent> BaseAction::getEvent() const {
	return _pEvent;
}

string BaseAction::toString() const {
	stringstream ss ;
	ss << "BaseAction[event id:" << (int)_pEvent->getId() << "]";
	return ss.str();
}



