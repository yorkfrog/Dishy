/*
 * NullAction.h
 *
 *  Created on: 19 Apr 2022
 *      Author: colin
 */

#ifndef NULLACTION_H_
#define NULLACTION_H_

#include "Action.h"
#include "ActionEvent.h"

class NullAction: public Action {
public:
	NullAction(ActionEvent* event);
	NullAction::NullAction(const NullAction &other);

	virtual ~NullAction();

	virtual int run();
};

#endif /* NULLACTION_H_ */
