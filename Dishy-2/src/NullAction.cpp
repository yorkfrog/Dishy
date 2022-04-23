/*
 * NullAction.cpp
 *
 *  Created on: 19 Apr 2022
 *      Author: colin
 */
//#define DEBUG

#include <iostream>
using namespace std;

#include "NullAction.h"

NullAction::NullAction(int id, InputEvent* event): BaseAction(id, event) {
#ifdef DEBUG
	cout << "   # NullAction contructor (" << this << "), id:" << event->getId() << endl;
#endif
}

NullAction::NullAction(const NullAction &other): BaseAction(other)  {
#ifdef DEBUG
	cout << "   # NullAction  COPY contructor, from (" << &other << "), to (" << this << ")" << endl;
#endif

}

NullAction::~NullAction() {
#ifdef DEBUG
	cout << "   # NullAction destructor on (" << this << ")" << endl;
#endif
}

// the caller is responsible for free the memory allocated to this cloned object.
Action* NullAction::clone() const {
	return new NullAction(*this);
}

int NullAction::run() {
	cout << "run NullAction" << "::" << this->toString() << endl;
	return getDescription().length();
}
