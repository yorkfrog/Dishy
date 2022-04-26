/*
 * ActionEvent.h
 *
 *  Created on: 18 Apr 2022
 *      Author: colin
 */

#ifndef INPUTEVENT_H_
#define INPUTEVENT_H_

#include "environment.h"

#include <cstdint>
#include <string>

using namespace std;

class InputEvent {

public:
	static int instanceCount;

public:
	enum eventId{invalidEvent=-1, btn1pressEvent=1,btn2pressEvent=2,btn3pressEvent=3,btn4pressEvent=4};

public:
	InputEvent(const InputEvent &other);
	InputEvent(int8_t id, char data);
	virtual ~InputEvent();
	int getId();
	char getData();
	string toString() const ;

private:
	int _id;
	char _data;
};

#endif /* INPUTEVENT_H_ */
