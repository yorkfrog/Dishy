/*
 * ActionGroup.cpp
 *
 *  Created on: 19 Apr 2022
 *      Author: colin
 */
//#define DEBUG

#include <iostream>
using namespace std;

#include "ActionGroup.h"

ActionGroup::ActionGroup() :
		BaseAction(NULL) {
#ifdef DEBUG
	cout << "   # DEF ActionGroup contructor (" << this << ")" << endl;
#endif
	_pTheAction = NULL;
}

ActionGroup::ActionGroup(BaseAction* action) :
		BaseAction(NULL) {
#ifdef DEBUG
	cout << "   # ActionGroup A contructor (" << this << ")" << endl;
#endif
	_pTheAction = action;
}

ActionGroup::ActionGroup(ActionEvent *event) :
		BaseAction(event) {
#ifdef DEBUG
	cout << "   # ActionGroup AE contructor (" << this << ")" << endl;
#endif
	_pTheAction = this;
}

ActionGroup::ActionGroup(const ActionGroup &other) :
		BaseAction(other) {
#ifdef DEBUG
	cout << "   # ActionGroup  COPY contructor, from (" << &other << "), to ("
			<< this << ")" << endl;
#endif
	_pTheAction = this;

}

ActionGroup::~ActionGroup() {
#ifdef DEBUG
	cout << "   # ActionGroup destructor on (" << this << ")" << endl;
#endif
	if (_pTheAction != NULL) {
		delete _pTheAction;
	}
}

void ActionGroup::addAction(BaseAction *action) {
	if (action != NULL) {
		_pTheAction = action;
	}

	// TODO add actions to collection (array) of Action Ptrs AND FREE

}

int ActionGroup::run() {
	cout << "run ActionGroup for " << _pTheAction->toString() << endl;
	return 0;
}
