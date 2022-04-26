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

//#define LOCAL_ENV 100
#define MCU_ENV 200
//#define TEST_ENV 300


// define this to allow debug logging in code.
#define DEBUG_OUT

#ifdef LOCAL_ENV
#ifdef DEBUG_OUT
#define LOG_DEBUG(...) cout << __VA_ARGS__
#endif
#endif //LOCAL_ENV

#ifndef LOG_DEBUG
#define LOG_DEBUG(...)
#endif




#endif /* ENVIRONMENT_H_ */
