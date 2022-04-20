/*
 * ButtonPressAction.h
 *
 *  Created on: 19 Apr 2022
 *      Author: colin
 */

#ifndef DISPLAYBASEACTION_H_
#define DISPLAYBASEACTION_H_

#include "ActionEvent.h"
#include "BaseAction.h"

class DisplayAction: public BaseAction {
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

#endif /* DISPLAYBASEACTION_H_ */
