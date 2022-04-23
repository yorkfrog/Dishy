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

//#define INSTANCE_COUNT

class BaseAction: public virtual Action  {

public:
	static int instanceCount;

public:
	//Action();
	BaseAction(int id, InputEvent* event) ;
	BaseAction(const BaseAction &other) ;

	virtual BaseAction& operator=(const BaseAction &other);
	virtual ~BaseAction() ;
	virtual string toString() const ;
	virtual int getId() const;
	virtual void setDescription(const string desc) ;
	virtual string getDescription() const ;

	InputEvent* getEvent() const;
	virtual int run() =0;

private:
	InputEvent* _pEvent;
	string _description;
	int _id;
};


#endif /* BASEACTION_H_ */
