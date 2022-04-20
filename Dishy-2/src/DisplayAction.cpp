/*
 * ButtonPressAction.cpp
 *
 *  Created on: 19 Apr 2022
 *      Author: colin
 */
//#define DEBUG

#include <iostream>
#include <sstream>
using namespace std;

#include "DisplayBaseAction.h"

DisplayAction::DisplayAction(int buttonNum, ActionEvent *event):
		BaseAction(event)

{
#ifdef DEBUG
	cout << "   # DisplayAction contructor (" << this << "), id:"
			<< event->getId() << endl;
#endif
	_buttonNumber = buttonNum;
}

DisplayAction::DisplayAction(const DisplayAction &other) :
		BaseAction(other) {
#ifdef DEBUG
	cout << "   # DisplayAction  COPY contructor, from (" << &other
			<< "), to (" << this << ")" << endl;
#endif
	_buttonNumber = other._buttonNumber;

}

DisplayAction::~DisplayAction() {
#ifdef DEBUG
	cout << "   # DisplayAction destructor on (" << this << ")" << endl;
#endif
}

int DisplayAction::run() {
	cout << "run DisplayAction for " << this->toString() << endl;
	return 0;
}

int DisplayAction::getButtonNumber() const {
	return _buttonNumber;
}

string DisplayAction::toString() const {
	stringstream ss ;
	ss << BaseAction::toString() << "[btn #:" << _buttonNumber << "]";
	return ss.str();
}

