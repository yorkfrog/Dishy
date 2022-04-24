/*
 * blink.h
 *
 *  Created on: Nov 27, 2015
 *      Author: jan
 */

#ifndef MAIN_H_
#define MAIN_H_

#include "Arduino.h"
#include <cstdint>

#include "actions.h"
#include "input.h"
#include "ActionGroup.h"
#include "Action.h"
#include "DisplayAction.h"
#include "NullAction.h"
#include "InputEvent.h"


void setup() ;
void loop();
unique_ptr<InputEvent> getEventForInput(char input);

Action*  getAction(unique_ptr<InputEvent> &event);


#endif /* MAIN_H_ */
