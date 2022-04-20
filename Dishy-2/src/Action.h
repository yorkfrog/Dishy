/*
 * Action.h
 *
 *  Created on: 18 Apr 2022
 *      Author: colin
 */

#ifndef ACTION_H_
#define ACTION_H_

#include "ActionEvent.h"


class Action {
public:
  // virtual destructor is required if the object may
  // be deleted through a pointer to Serializable
	virtual ~Action() {}
	virtual int run() = 0;
	virtual string toString() const = 0;
	virtual bool isValid() const = 0;
};

#endif /* ACTION_H_ */
