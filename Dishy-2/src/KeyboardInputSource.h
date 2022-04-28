/*
 *  Created on: Nov 27, 2015
 *      Author: jan
 */

#ifndef KEYBOARDINPUTSOURCE_H_
#define KEYBOARDINPUTSOURCE_H_

#include "environment.h"
#include <string>
#include "InputSource.h"

#ifdef MCU_ENV
#include "Arduino.h"
#endif

#ifdef LOCAL_ENV
#include <iostream>
#include "stdio.h"
#endif
using namespace std;

class KeyboardInputSource:  public virtual InputSource
{
public:

	KeyboardInputSource(string prompt);
	uint8_t readInput();
	virtual ~KeyboardInputSource();

private:
	string _prompt;
};
#endif /* KEYBOARDINPUTSOURCE_H_ */
