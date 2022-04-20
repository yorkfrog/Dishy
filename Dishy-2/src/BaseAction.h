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
#include "ActionEvent.h"


class BaseAction: public virtual Action  {
public:
	static int instanceCount;

public:
	//Action();
	BaseAction(ActionEvent* event) ;
	BaseAction::BaseAction(const BaseAction &other) ;

	virtual ~BaseAction() ;
	virtual int run();
	virtual string toString() const ;

	bool isValid() const;

private:
	ActionEvent* _event;
	bool _isValid;

};


#endif /* BASEACTION_H_ */
