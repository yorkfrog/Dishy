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

#include "ActionEvent.h"
#include "BaseAction.h"

class ActionGroup: public BaseAction {
private:
	BaseAction* _pTheAction;


public:
	ActionGroup();
	ActionGroup::ActionGroup(BaseAction* action);

	ActionGroup(ActionEvent* event);
	ActionGroup::ActionGroup(const ActionGroup &other);

	virtual ~ActionGroup();

	virtual int run();
	void addAction(BaseAction* action);

};

#endif /* ACTIONGROUP_H_ */
