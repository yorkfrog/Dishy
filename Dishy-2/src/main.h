/*
 * blink.h
 *
 *  Created on: Nov 27, 2015
 *      Author: jan
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "environment.h"

#include "Arduino.h"

//#include <cstdint>

#include "actions.h"
#include "ActionGroup.h"
#include "Action.h"
#include "DisplayAction.h"
#include "NullAction.h"
#include "InputEvent.h"
#include "KeyboardInputSource.h"


void setup() ;
void loop();
unique_ptr<InputEvent> getEventForInput(uint8_t input);

unique_ptr<Action>  getAction(unique_ptr<InputEvent> &event);


#endif /* MAIN_H_ */
