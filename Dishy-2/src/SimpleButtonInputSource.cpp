/*
 *  Created on: Nov 27, 2015
 *      Author: jan
 */
#include "SimpleButtonInputSource.h"
#include "Arduino.h"

SimpleButtonInputSource::SimpleButtonInputSource(uint8_t buttonPin, uint8_t valueWhenPressed, string description = "button") {
	_buttonPin = buttonPin;
	_valueWhenPressed = valueWhenPressed;
	_description = description;
#ifdef DEBUG
	LOG_DEBUG_MEM("      # SimpleButtonInputSource [%s] C'TOR [%#lx]\n", _description.c_str(), this);
#endif
}
SimpleButtonInputSource::~SimpleButtonInputSource()
{
#ifdef DEBUG
	LOG_DEBUG_MEM("      # SimpleButtonInputSource [%s] D'TOR [%#lx]\n", _description.c_str(), this);
#endif
}

#ifdef LOCAL_ENV
//===========================
// Read INPUT on Local system
//===========================
uint8_t SimpleButtonInputSource::readInput() {
	printf("Enter a character: ");
	string input;
	cin >> input;

//	printf("You entered %c.\n", chr);

	printf("Entered >>> [%s]\n", input.c_str());
	return input.at(0); //chr;
}

#endif

#ifdef MCU_ENV


void SimpleButtonInputSource::setUp()
{
	// setup input pins
	pinMode(_buttonPin, INPUT_PULLUP);

}

//===========================
// Read INPUT on MCU
//===========================

/*
 * Read the de-bouced momentary button state.
 * This function is non-blocking
 * @return:
 *  - valueWhenPressed  : button pressed
 *  - LOW : button released
 *
 *  Call hasChanged() to determine if the button state has changed on the last read.
 */
uint8_t SimpleButtonInputSource::readInput()
{
//	return digitalRead(button1Pin);
//  // read the state of the switch into a local variable:
	uint8_t btnNewState = digitalRead(_buttonPin);
	uint32_t currentMillis = millis();

// check to see if you just pressed the button
// (i.e. the input went from LOW to HIGH), and you've waited long enough
// since the last press to ignore any noise:

	if ((currentMillis - _lastDebounceTime) > _debounceDelay)
	{
		// whatever the reading is at, it's been there for longer than the debounce
		// delay, so take it as the actual current state:
		_lastDebounceTime = currentMillis;

		// if the button state has changed:
		if (btnNewState != _buttonState)
		{
			_lastButtonState = _buttonState;
			_buttonState = btnNewState;
			_stateChanged = true;

		}
//		else
//		{
//			// 	LOG_DEBUG("   >> BB prev[%i] read[%i] d[%b] t[%dl]\n", _lastButtonState, btnNewState, _stateChanged, currentMillis);
//			_stateChanged = false;
//		}
	}

	if (_stateChanged)
	{
		LOG_DEBUG("[%dl]   >> [%s] S change to v[%i] st[%i]\n", currentMillis, _description.c_str(),  _buttonState, _stateChanged);
//		LOG_DEBUG("   >> [%s] debounced input prev[%i] read[%i] t[%dl]\n", _description.c_str(), _lastButtonState, btnNewState, currentMillis);
	}

return convertButtonState(_buttonState) ;
//return _buttonState ;
}

uint8_t SimpleButtonInputSource::convertButtonState(uint8_t btnState) {
	if (PRESSED == btnState) {
		return _valueWhenPressed;
	}
	return LOW;
}

bool SimpleButtonInputSource::hasChanged()
{
	bool oldState = _stateChanged;
	if (_stateChanged) {
//		LOG_DEBUG("   >> [%s] State changed: prev[%i] read[%i] t[%dl]\n", _description.c_str(), _lastButtonState, _buttonState, millis());
		_stateChanged = false;
	}
	return oldState;
}
#endif

#ifdef TEST_ENV

char SimpleButtonInputSource::readInput()
{
	return 'a';
}

#endif
