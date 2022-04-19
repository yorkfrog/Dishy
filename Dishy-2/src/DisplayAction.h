/*
 * ButtonPressAction.h
 *
 *  Created on: 19 Apr 2022
 *      Author: colin
 */

#ifndef DISPLAYACTION_H_
#define DISPLAYACTION_H_

#include "Action.h"
#include "ActionEvent.h"

class DisplayAction: public Action {
private:
	int _buttonNumber;

public:
	DisplayAction(int buttonNum, ActionEvent* event);
	DisplayAction::DisplayAction(const DisplayAction &other);

	virtual ~DisplayAction();

	virtual int run();
	virtual string toString() const ;

	int getButtonNumber() const ;
};

#endif /* DISPLAYACTION_H_ */
