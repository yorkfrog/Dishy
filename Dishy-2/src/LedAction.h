/*
 * ToggleLedAction.h
 *
 *  Created on: 19 Apr 2022
 *      Author: colin
 */

#ifndef LEDACTION_H_
#define LEDACTION_H_

#include "BaseAction.h"


class LedAction: public virtual Action, public BaseAction
{
/*
public:
	static unique_ptr<ToggleLedAction> build();
*/

public:
	LedAction(int id, unique_ptr<InputEvent> &event);
	LedAction(const LedAction &other);

	virtual ~LedAction();
	virtual Action* clone() const;

	virtual int run();

};

#endif /* LEDACTION_H_ */
