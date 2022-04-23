

/*
 * GroupActionTest.h
 *
 *  Created on: 21 Apr 2022
 *      Author: colin
 */

#include "ActionGroupTest.h"

	void ActionGroupTest::SetUp() {
		id = 1;
		data = 'c';
		gpInputEvent = new InputEvent(id, data);
		gpNullAction = new NullAction(-1, gpInputEvent);
	}

	void ActionGroupTest::TearDown() {
		delete gpInputEvent;
		delete gpNullAction;
	}



