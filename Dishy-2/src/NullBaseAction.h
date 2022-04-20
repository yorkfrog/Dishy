/*
 * NullAction.h
 *
 *  Created on: 19 Apr 2022
 *      Author: colin
 */

#ifndef NULLBASEACTION_H_
#define NULLBASEACTION_H_

#include "ActionEvent.h"
#include "BaseAction.h"

class NullAction: public BaseAction {
public:
	NullAction(ActionEvent* event);
	NullAction::NullAction(const NullAction &other);

	virtual ~NullAction();

	virtual int run();
};

#endif /* NULLBASEACTION_H_ */
