/*
 * environment.h
 *
 * Define the environment we are runing in:
 * LOCAL - local PC
 * MCU 	- the microcontroller
 * TEST - unittests
 *
 *This allows us to rewrite/exclude sections of code appropriately for the exec env.
 *
 *To override these from the build options:
 *Proj properties | C/C++ build | settings | Tool Settings | Arduino C++ compiler | expert settings
-- add -D MY_DEFINE_VAR to the cmd line pattern.
 *
 *
 *  Created on: 19 Apr 2022
 *      Author: colin
 */

#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_

//#include "Arduino.h"

/*
 * To set per build config in Sloeber, set in :
 *     Proj properties | Arduino | Compile Options | append to C/C++
 */
//#define LOCAL_ENV 100
//#define MCU_ENV 200
//#define TEST_ENV 300

#define DEBUG

// define this to allow debug logging in code.
#ifdef LOCAL_ENV
#define DEBUG_OUT
#endif

#ifdef DEBUG_OUT
#define LOG_DEBUG_LN(...) printf( __VA_ARGS__ )
#else
#define LOG_DEBUG_LN(...)
#endif




#endif /* ENVIRONMENT_H_ */
