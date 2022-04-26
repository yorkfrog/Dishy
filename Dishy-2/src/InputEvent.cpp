/*
 * InputEvent.cpp
 *
 *  Created on: 18 Apr 2022
 *      Author: colin
 */


#include "InputEvent.h"

#include <sstream>


int InputEvent::instanceCount = 0;

InputEvent::InputEvent(int8_t id, char data): _id(id), _data(data) {
	LOG_DEBUG("   # InputEvent contructor (" << this << "), id:" << _id << ",data:" << _data << endl);
	instanceCount++;
}

InputEvent::InputEvent(const InputEvent &other): _id(other._id), _data(other._data) {
	LOG_DEBUG("   # COPY InputEvent contructor from (" << &other << "), to (" << this << "), id:" << _id << endl);
	instanceCount++;
}

InputEvent::~InputEvent() {
	LOG_DEBUG("   # InputEvent destructor on (" << this << "), id:" << _id << endl);
	instanceCount--;
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
