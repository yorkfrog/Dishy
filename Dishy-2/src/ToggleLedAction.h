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
	ToggleLedAction(int id, unique_ptr<InputEvent> &event);
	ToggleLedAction(const ToggleLedAction &other);

	virtual ~ToggleLedAction();
	virtual Action* clone() const;

	virtual int run();

};

#endif /* TOGGLELEDACTION_H_ */
