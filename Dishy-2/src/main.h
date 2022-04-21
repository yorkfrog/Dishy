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
#include "DisplayBaseAction.h"
#include "NullAction.h"
#include "InputEvent.h"

#define INTERVAL 1250 //The blinking interval

void setup() ;
void loop();
InputEvent getEventForInput(char input);

//int doAction( InputEvent &event) ;
//void getAction(Action* actionToAssign, ActionEvent &event) ;

Action*  getAction(InputEvent &event);
//Action getAction(ActionEvent &event) ;


/*
struct inputEvent {
  int id;
  int action;
  string data;
} ;
*/

#endif /* MAIN_H_ */
