/*
 * ButtonPressAction.h
 *
 *  Created on: 19 Apr 2022
 *      Author: colin
 */

#ifndef DISPLAYBASEACTION_H_
#define DISPLAYBASEACTION_H_

#include "BaseAction.h"
#include "InputEvent.h"

class DisplayAction: public virtual Action, public BaseAction
{
private:
	int _buttonNumber;

public:
	DisplayAction(int id, int buttonNum, InputEvent *event);
	DisplayAction::DisplayAction(const DisplayAction &other);

	virtual ~DisplayAction();
	virtual Action* clone() const;

	virtual int run();
	virtual string toString() const;

	int getButtonNumber() const;
};

#endif /* DISPLAYBASEACTION_H_ */
