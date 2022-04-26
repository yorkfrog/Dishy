/*
 *  Created on: Nov 27, 2015
 *      Author: jan
 */

#ifndef KEYBOARDINPUT_H_
#define KEYBOARDINPUT_H_

#include "environment.h"

#ifdef MCU_ENV
#include "Arduino.h"
#endif

#ifdef LOCAL_ENV
#include <iostream>
#include "stdio.h"
using namespace std;
#endif

char readInput();

#endif /* KEYBOARDINPUT_H_ */
