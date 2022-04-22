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
	int _maxActions;
	string* _pDescription;
	string _testStr;

public:
	ActionGroup(int maxActions, string* desc);
	ActionGroup(int maxActions, Action* action, string* desc);
	ActionGroup(int maxActions, Action* action, string* desc, string &testStr);

	ActionGroup(const ActionGroup &other);

	virtual ~ActionGroup();
	virtual Action* clone() const;

	virtual int run();
	virtual string toString() const;
	virtual void setDescription(const string* desc) ;
	virtual string* getDescription() const ;

	int getMaxActions() const ;
	void addAction(Action* action);

	const string& getTestStr() const {
		return _testStr;
	}

	void setTestStr(const string &testStr) {
		_testStr = testStr;
	}
};

#endif /* ACTIONGROUP_H_ */
