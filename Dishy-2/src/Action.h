/*
 * Action.h
 *
 *  Created on: 18 Apr 2022
 *      Author: colin
 */

#ifndef ACTION_H_
#define ACTION_H_

#include <iostream>
using namespace std;

class Action {
public:
  // virtual destructor is required if the object may
  // be deleted through a pointer to Serializable
	virtual ~Action() {}
	virtual Action* clone() const = 0;
	virtual int run() = 0;
	virtual string toString() const = 0;
	virtual int getId() const = 0;
	virtual void setDescription(const string desc) = 0;
	virtual string getDescription() const = 0;


};

#endif /* ACTION_H_ */
