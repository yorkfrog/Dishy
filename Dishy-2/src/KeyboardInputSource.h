/*
 *  Created on: Nov 27, 2015
 *      Author: jan
 */

#ifndef KEYBOARDINPUTSOURCE_H_
#define KEYBOARDINPUTSOURCE_H_

#include "environment.h"

#include "InputSource.h"

#ifdef MCU_ENV
#include "Arduino.h"
#endif

#ifdef LOCAL_ENV
#include <iostream>
#include "stdio.h"
using namespace std;
#endif

class KeyboardInputSource:  public virtual InputSource
{
public:

	uint8_t readInput();
	virtual ~KeyboardInputSource();
};
#endif /* KEYBOARDINPUTSOURCE_H_ */
