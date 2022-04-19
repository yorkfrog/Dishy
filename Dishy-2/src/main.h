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
#include "ActionEvent.h"
#include "Action.h"
#include "ActionGroup.h"
#include "DisplayAction.h"

#define INTERVAL 1250 //The blinking interval

void setup() ;
void loop();
ActionEvent getEventForInput(char input);
int doAction( ActionEvent &event) ;

//void getAction(Action* actionToAssign, ActionEvent &event) ;
Action*  getAction(ActionEvent &event);
//Action getAction(ActionEvent &event) ;

enum eventId{invalidEvent=-1, btn1pressEvent=1,btn2pressEvent=2,btn3pressEvent=3,btn4pressEvent=4};

/*
struct inputEvent {
  int id;
  int action;
  string data;
} ;
*/

#endif /* MAIN_H_ */
