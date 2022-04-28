/*
 * InputEvent.cpp
 *
 *  Created on: 18 Apr 2022
 *      Author: colin
 */


#include "InputEvent.h"

#include <sstream>


int InputEvent::instanceCount = 0;

InputEvent::InputEvent(int8_t id, uint8_t data): _id(id), _data(data) {
	LOG_DEBUG_MEM("         # InputEvent constructor [%#lx], id:%i, data:%c\n", this , _id , _data );
	instanceCount++;
}

InputEvent::InputEvent(const InputEvent &other): _id(other._id), _data(other._data) {
	LOG_DEBUG_MEM("         # COPY InputEvent constructor from [%#lx] to [%#lx], id:%i\n", &other , this , _id );
	instanceCount++;
}

InputEvent::~InputEvent() {
	LOG_DEBUG_MEM("         # InputEvent destructor on [%#lx], id:%i\n", this , _id );
	instanceCount--;
}

int InputEvent::getId() {
	return _id;
}

uint8_t InputEvent::getData() {
	return _data;
}

string InputEvent::toString() const {
	stringstream ss ;
	ss << "InputEvent[id:" << _id << ", data:" << _data << "]";
	return ss.str();
}
