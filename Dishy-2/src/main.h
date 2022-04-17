/*
 * blink.h
 *
 *  Created on: Nov 27, 2015
 *      Author: jan
 */

#ifndef MAIN_H_
#define MAIN_H_
#include "Arduino.h"

#include "input.h"
#include "action.h"

#define INTERVAL 1250 //The blinking interval

void setup() ;
void loop();

/*
struct inputEvent {
  int id;
  int action;
  string data;
} ;
*/

#endif /* MAIN_H_ */
