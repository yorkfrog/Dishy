/*
 * NullAction.h
 *
 *  Created on: 19 Apr 2022
 *      Author: colin
 */

#ifndef NULLACTION_H_
#define NULLACTION_H_

#include "BaseAction.h"
#include "InputEvent.h"

class NullAction: public virtual Action, public BaseAction {
public:
	NullAction(InputEvent* event);
	NullAction::NullAction(const NullAction &other);

	virtual ~NullAction();

	virtual int run();

};

#endif /* NULLACTION_H_ */
