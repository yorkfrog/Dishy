/*
 * NullAction.cpp
 *
 *  Created on: 19 Apr 2022
 *      Author: colin
 */
//#define DEBUG

#include <iostream>
using namespace std;

#include "NullBaseAction.h"

NullAction::NullAction(ActionEvent* event): BaseAction(event) {
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

int NullAction::run() {
	cout << "run NullAction for " << this->toString() << endl;
	return 0;
}
/*
NullAction::NullAction(const NullAction &other) {
	// TODO Auto-generated constructor stub

}
*/
