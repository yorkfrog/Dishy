/*
 * InputSource.h
 *
 *  Created on: 26 Apr 2022
 *      Author: colin
 */

#ifndef INPUTSOURCE_H_
#define INPUTSOURCE_H_

#include "Arduino.h"

class InputSource
{
public:
	virtual uint8_t readInput() = 0;
	virtual void setUp() {};

	virtual bool hasChanged() {return true;};
  // virtual destructor is required if the object may
  // be deleted through a pointer to Serializable
	virtual ~InputSource() {}
};

#endif /* INPUTSOURCE_H_ */
