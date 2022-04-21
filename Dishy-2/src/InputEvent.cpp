/*
 * InputEvent.cpp
 *
 *  Created on: 18 Apr 2022
 *      Author: colin
 */


//#define  DEBUG

#include "InputEvent.h"

#include <iostream>
#include <sstream>
using namespace std;

InputEvent::InputEvent(int8_t id, char data): _id(id), _data(data) {
#ifdef DEBUG
	cout << "   # InputEvent contructor (" << this << "), id:" << _id << ",data:" << _data << endl;
#endif
//	_id = id;
//	_data = data;
}

InputEvent::InputEvent(const InputEvent &other): _id(other._id), _data(other._data) {
#ifdef DEBUG
	cout << "   # COPY InputEvent contructor from (" << &other << "), to (" << this << "), id:" << _id << endl;
#endif
//	_id = id;
//	_data = data;

}

InputEvent::~InputEvent() {
#ifdef DEBUG
	cout << "   # InputEvent destructor on (" << this << "), id:" << _id << endl;
#endif
}

int InputEvent::getId() {
	return _id;
}

char InputEvent::getData() {
	return _data;
}

string InputEvent::toString() const {
	stringstream ss ;
	ss << "InputEvent[id:" << (int)_id << ", data:" << _data << "]";
	return ss.str();
}
