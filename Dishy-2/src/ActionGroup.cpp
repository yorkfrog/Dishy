/*
 * ActionGroup.cpp
 *
 *  Created on: 19 Apr 2022
 *      Author: colin
 */
//#define DEBUG
#include <iostream>
using namespace std;
#include <sstream>

#include "ActionGroup.h"

ActionGroup::ActionGroup(int maxActions) {
	_pTheAction = NULL;
#ifdef DEBUG
	cout << "   # DEF ActionGroup contructor (" << this << ")" << endl;
#endif
}

ActionGroup::ActionGroup(Action *action) {
	_pTheAction = action;
#ifdef DEBUG
	cout << "   # ActionGroup A contructor (" << this << ")" << endl;
#endif
}

ActionGroup::ActionGroup(const ActionGroup &other) {
	_pTheAction = this;
#ifdef DEBUG
	cout << "   # ActionGroup  COPY contructor, from (" << &other << "), to ("
			<< this << ")" << endl;
#endif

}

ActionGroup::~ActionGroup() {
	if (_pTheAction != NULL) {
		delete _pTheAction;
	}
#ifdef DEBUG
	cout << "   # ActionGroup destructor on (" << this << ")" << endl;
#endif
}

void ActionGroup::addAction(Action *action) {
	if (action != NULL) {
		_pTheAction = action;
	}

	// TODO add actions to collection (array) of Action Ptrs AND FREE

}

string ActionGroup::toString() const {
	stringstream ss ;
	ss << "ActionGroup[...]";
	return ss.str();
}

int ActionGroup::run() {
	cout << "run ActionGroup for " << _pTheAction->toString() << endl;
	return 0;
}
