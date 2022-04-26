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

#include "environment.h"

#ifndef MCU_ENV
#include <iostream>
#endif
#include <memory>

#include "Action.h"

class ActionGroup: public virtual Action {
private:
	shared_ptr<Action> _pTheAction;
	int _maxActions;
	string _description;
	int _id;

public:
	static int instanceCount;

public:
	ActionGroup(int id, int maxActions, string desc);
	ActionGroup(int id, int maxActions, unique_ptr<Action> &action, string desc);

	ActionGroup(const ActionGroup &other);
	ActionGroup& operator=(const ActionGroup &other) ;

	virtual ~ActionGroup();
	virtual Action* clone() const;

	virtual int getId() const;
	virtual int run();
	virtual string toString() const;
	virtual void setDescription(const string desc) ;
	virtual string getDescription() const ;

	int getMaxActions() const ;
	void addAction(unique_ptr<Action> &action);

};

#endif /* ACTIONGROUP_H_ */
