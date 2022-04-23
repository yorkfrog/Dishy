/*
 * CoutLogger.h
 *
 *  Created on: 23 Apr 2022
 *      Author: colin
 */

#ifndef COUTLOGGER_H_
#define COUTLOGGER_H_

#include "Logger.h"
#include <initializer_list>


class CoutLogger: public Logger
{
public:
	CoutLogger() {};
	virtual ~CoutLogger() {};
	virtual void log(string str);
};

#endif /* COUTLOGGER_H_ */
