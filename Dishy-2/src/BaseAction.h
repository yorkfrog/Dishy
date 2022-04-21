/*
 * Action.h
 *
 *  Created on: 18 Apr 2022
 *      Author: colin
 */

#ifndef BASEACTION_H_
#define BASEACTION_H_

#include <iostream>
using namespace std;

#include "Action.h"
#include "InputEvent.h"


class BaseAction: public virtual Action  {
public:
	static int instanceCount;

public:
	//Action();
	BaseAction(InputEvent* event) ;
	BaseAction::BaseAction(const BaseAction &other) ;

	virtual ~BaseAction() ;
	virtual int run() =0;
	virtual string toString() const ;

protected:
	InputEvent* getEvent();

private:
	InputEvent* _event;

};


#endif /* BASEACTION_H_ */
