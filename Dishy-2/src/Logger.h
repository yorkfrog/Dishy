/*
 * Logger.h
 *
 *  Created on: 23 Apr 2022
 *      Author: colin
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <iostream>
using namespace std;

class Logger
{
public:
	virtual ~Logger() {};
	virtual void log(string str) = 0;
};

#endif /* LOGGER_H_ */
