/*
 * ToggleToggleLedAction.h
 *
 *  Created on: 19 Apr 2022
 *      Author: colin
 */

#ifndef TOGGLELEDACTION_H_
#define TOGGLELEDACTION_H_

#include "BaseAction.h"


class ToggleLedAction: public virtual Action, public BaseAction
{
/*
public:
	static unique_ptr<ToggleToggleLedAction> build();
*/

public:
	ToggleLedAction(int id, uint8_t ledPin, unique_ptr<InputEvent> &event);
	ToggleLedAction(const ToggleLedAction &other);

	virtual ~ToggleLedAction();
	virtual Action* clone() const;

	virtual int run();

private:
	uint8_t _ledPin;
};

#endif /* TOGGLELEDACTION_H_ */
