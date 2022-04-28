/*
 *  Created on: Nov 27, 2015
 *      Author: jan
 */

#ifndef SIMPLEBUTTONINPUTSOURCE_H_
#define SIMPLEBUTTONINPUTSOURCE_H_

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

static const uint8_t RELEASED = HIGH;
static const uint8_t PRESSED = LOW;

class SimpleButtonInputSource:  public virtual InputSource
{
public:
	SimpleButtonInputSource(uint8_t buttonPin, uint8_t valueWhenPressed, string description);
	uint8_t readInput();
	virtual void setUp();
	virtual bool hasChanged() ;

	virtual ~SimpleButtonInputSource();

private:
	uint8_t _valueWhenPressed = 0;
  bool _stateChanged = false;
  uint8_t _buttonPin = 0;  // D2 on Lolin D1 Mini
  uint8_t _buttonState = HIGH;   // the previous reading from the input pin
  uint8_t _lastButtonState = HIGH;   // the previous reading from the input pin

  // the following variables are unsigned longs because the time, measured in
  // milliseconds, will quickly become a bigger number than can be stored in an int.
  uint32_t _lastDebounceTime = 0;  // the last time the output pin was toggled
  uint32_t _debounceDelay = 50;    // the debounce time; increase if the output flickers

  string _description ;

  uint8_t convertButtonState(uint8_t btnState);

};
#endif /* SIMPLEBUTTONINPUTSOURCE_H_ */
