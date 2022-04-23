/*
 * NullLogger.h
 *
 *  Created on: 23 Apr 2022
 *      Author: colin
 */

#ifndef NULLLOGGER_H_
#define NULLLOGGER_H_

#include "Logger.h"

class NullLogger: public Logger
{
public:
	NullLogger() {};
	virtual ~NullLogger() {};
	virtual void log(string str) {};
};

#endif /* NULLLOGGER_H_ */
