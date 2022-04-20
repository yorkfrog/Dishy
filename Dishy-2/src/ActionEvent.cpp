/*
 * ActionEvent.cpp
 *
 *  Created on: 18 Apr 2022
 *      Author: colin
 */


//#define  DEBUG

#include "ActionEvent.h"

#include <iostream>
#include <sstream>
using namespace std;

ActionEvent::ActionEvent(int8_t id, char data): _id(id), _data(data) {
#ifdef DEBUG
	cout << "   # ActionEvent contructor (" << this << "), id:" << _id << ",data:" << _data << endl;
#endif
//	_id = id;
//	_data = data;
}

ActionEvent::ActionEvent(const ActionEvent &other): _id(other._id), _data(other._data) {
#ifdef DEBUG
	cout << "   # COPY ActionEvent contructor from (" << &other << "), to (" << this << "), id:" << _id << endl;
#endif
//	_id = id;
//	_data = data;

}

ActionEvent::~ActionEvent() {
#ifdef DEBUG
	cout << "   # ActionEvent destructor on (" << this << "), id:" << _id << endl;
#endif
}

int ActionEvent::getId() {
	return _id;
}

char ActionEvent::getData() {
	return _data;
}

string ActionEvent::toString() const {
	stringstream ss ;
	ss << "ActionEvent[id:" << (int)_id << ", data:" << _data << "]";
	return ss.str();
}
