/*
 * blink.h
 *
 *  Created on: Nov 27, 2015
 *      Author: jan
 */

#ifndef MAIN_H_
#define MAIN_H_
#include "Arduino.h"
#define INTERVAL 1250 //The blinking interval

uint8_t calcLedState(uint32_t currentMillis, uint8_t ledState);
void setup() ;
void loop() ;


#endif /* MAIN_H_ */
