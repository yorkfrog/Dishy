/*
 * ActionGroup.h
 *
 * create a group of Actions that can be treated an a single action.
 *
 *  Created on: 19 Apr 2022
 *      Author: colin
 */

#ifndef ACTIONGROUP_H_
#define ACTIONGROUP_H_

#include <iostream>

#include "Action.h"

class ActionGroup: public virtual Action {
private:
	Action* _pTheAction;


public:
	ActionGroup(int maxActions);
	ActionGroup(Action* action);
	ActionGroup(const ActionGroup &other);

	virtual ~ActionGroup();

	virtual int run();
	virtual string toString() const;

	void addAction(Action* action);

};

#endif /* ACTIONGROUP_H_ */
