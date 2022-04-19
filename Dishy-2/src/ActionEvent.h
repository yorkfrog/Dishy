/*
 * ActionEvent.h
 *
 *  Created on: 18 Apr 2022
 *      Author: colin
 */

#ifndef ACTIONEVENT_H_
#define ACTIONEVENT_H_
#include <cstdint>
#include <iostream>
using namespace std;

class ActionEvent {
public:
	ActionEvent();
	ActionEvent::ActionEvent(const ActionEvent &other);
	ActionEvent(int8_t id, char data);
	virtual ~ActionEvent();
	int getId();
	char getData();
	string toString() const ;

private:
	int _id;
	char _data;
};

#endif /* ACTIONEVENT_H_ */
