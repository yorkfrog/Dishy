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

#include "Action.h"
#include "ActionEvent.h"

class ActionGroup: public Action {
private:
	Action* _pTheAction;


public:
	ActionGroup();
	ActionGroup::ActionGroup(Action* action);

	ActionGroup(ActionEvent* event);
	ActionGroup::ActionGroup(const ActionGroup &other);

	virtual ~ActionGroup();

	virtual int run();
	void addAction(Action* action);

};

#endif /* ACTIONGROUP_H_ */
