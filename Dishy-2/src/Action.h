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

#include "ActionEvent.h"


class Action {
public:
	static int instanceCount;

public:
	//Action();
	Action(ActionEvent* event) ;
	Action::Action(const Action &other) ;

	virtual ~Action() ;
	virtual int run();
	virtual string toString() const ;

private:
	ActionEvent* _event;
};

/*
class FlashLedAction:public Action
{
	FlashLedAction();
	int run();
};
*/




#endif /* ACTION_H_ */
