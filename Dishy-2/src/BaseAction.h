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
	virtual string toString() const ;
	virtual void setDescription(const string* desc) ;
	virtual string* getDescription() const ;

	virtual int run() =0;

protected:
	InputEvent* getEvent();

private:
	InputEvent* _event;
	string* _description;

};


#endif /* BASEACTION_H_ */
